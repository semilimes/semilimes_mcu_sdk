/***************************************************
The channel_websocket firmware is designed to demonstrate the implementation 
of the semilimes SDK and establish communication with a server via WebSocket. 

This example firmware, once connected to a Wi-Fi network and thereby to the 
internet, establishes a WebSocket connection to a server, utilizing callback functions. 

Upon establishing the connection, the firmware creates a new channel in the 
subaccount associated with the provided API key. 
Once the channel is successfully created, it sends a form containing two form components:
a label and a button list. 

Through the use of callbacks, it is possible to print messages sent to the channel 
via the app, including those related to interactions with the newly created form, 
directly to the serial output.

Unlike the example firmware called "provisioning," where the API key is sent from the 
server after scanning a QR code, in the channel_websocket firmware, the API key is
directly embedded in the firmware. You can request an API key from the following 
page: https://my.semilimes.net/apikeys.
The advantage of using provisioning is that it allows you to create devices intended 
for third-party use without the need to share the API key. During the provisioning 
process, ownership of the device is established, ensuring that the API key remains 
secure and the device is correctly assigned to the user or account during the 
provisioning phase.

This project is licensed under the MIT License.
 ****************************************************/
#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <WebSocketsClient.h>

#include <Arduino.h>
#include <ArduinoJson.h>
#include <semilimes.h>
    
bool singletone = false;
bool wsConnected = false;
bool WiFiConnected = false;

Header header;

WiFiMulti WiFiMulti;
const uint32_t connectTimeoutMs = 5000;
HTTPClient http;
WebSocketsClient webSocket;
#define _WEBSOCKETS_LOGLEVEL_     2

void setup()
{
    Serial.begin(115200);
    while (!Serial);
    delay(200);
      
    WiFi.mode(WIFI_STA);   
    WiFiMulti.addAP("ssid", "password");
    if (WiFiMulti.run(connectTimeoutMs) == WL_CONNECTED) 
    {
      WiFiConnected = true;
      Serial.print("WiFi connected: ");
      Serial.print(WiFi.SSID());
      Serial.print(" ");
      Serial.println(WiFi.localIP());
    } else 
    {
      Serial.println("WiFi not connected!");
    }  

    if(WiFiConnected==true)
    {      
      header.setAuthorization("********** ApiKey **********");
      webSocket.beginSSL(header.getWsHost(),header.getWsPort(),header.getWsEP()); //init the websocket
      webSocket.setExtraHeaders(header.getWsHeader());  //feed the ws_client with the authorization header, needed to connect to the semilimes server 
      webSocket.onEvent(webSocketEvent);  //initialize the websocket client callback event manager
    }  
}

char channelId[37];
bool msgReceivedChId = false;
void JSON_decode(char* payload)
{
  //Serial.println(payload);  
  JsonDocument doc;
  deserializeJson(doc, payload);
  
  //check if is the "createdChannel" response 
  if(doc["eventBody"]["data"]["createdChannel"]["channelId"])
  {
    msgReceivedChId = true;
    strcpy(channelId,doc["eventBody"]["data"]["createdChannel"]["channelId"]);
  }
}

void webSocketEvent(const WStype_t& type, uint8_t * payload, const size_t& length)
{
  switch (type)
  {
    case WStype_DISCONNECTED:
      Serial.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED:
      Serial.printf("[WSc] Connected to url: %s\n", payload);
      wsConnected = true;
      break;
    case WStype_TEXT:
      Serial.printf("[WSc] message received: %s\n", payload);
      JSON_decode((char*)payload);
      break;
    case WStype_BIN:
      break;
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
      break;
    default:
      break;
  }
}

void loop() 
{
  JsonDocument doc;
  String response;
  WebsocketHeader websocketheader;  //create a new "WebsocketHeader" object and feed it with the pointer to the char-array that will contain the json

  webSocket.loop();
  if(wsConnected==true && WiFiConnected==true)
  {
    if(singletone==false)
    {
      singletone=true;
      //**********************************************
      //create a new channel
      //**********************************************
      
      ChannelCreate channelcreate; //create a new "CreateChannel" object and feed it with the pointers to the char-arrays that will contain the json
      channelcreate.set("New Channel","",false,true); //name="New Channel", avatar="", visible=false, locked=true
      webSocket.sendTXT(websocketheader.getRequest("reqId_1", communication_channel_create, channelcreate.get())); //embeds the "channelCreate" json into the "websocketheader" and send the message to the sme server (request id: "reqId_1")
    }

    //check if the channel as been created and the new ChannelId received
    if(msgReceivedChId==true)
    {
      msgReceivedChId = false;
      Serial.print("New Channel Id: ");
      Serial.println(channelId);

      //**********************************************
      //send a message to the newly created channel
      //**********************************************
      
      //create a new Form    
      DcForm form; //create a new "DcForm" object and feed it with the pointers to the char-arrays that will contain the json 
      form.set(channelId,form.featureType[2],false,false,"","refname"); //(channelId, featureType="channel",submitEnabled=false, retainStatus=false, "", refName)
      
      //create Label Form Component
      FcLabel fclabel; //create a new "FcLabel" object and feed it with the pointers to the char-arrays that will contain the json
      fclabel.set("Label","Example Form on a newly created Channel"); //(refname,title)
      //Serial.println(fclabel.get());
      form.addFormComponents(fclabel.get()); //add the "fclabel" to the FormComponents of "form"
      
      //create a button list Form Component
      FcButtonList fcbuttonlist; //create a new "FcButtonList" object and feed it with the pointers to the char-arrays that will contain the json
      fcbuttonlist.set("myButtonList","Button List",false,"buttonName",true); //(refname, title, required selection, value, vertList)
      fcbuttonlist.addOptions("button1","choice1"); //add the first button (name, value)  
      fcbuttonlist.addOptions("button2","choice2"); //add the second button (name, value)
      fcbuttonlist.appendOptions(); //append the buttons to the "fcbuttonlist"
      //Serial.println(fcbuttonlist.get());
      form.addFormComponents(fcbuttonlist.get()); //add the "fcbuttonlist" to the FormComponents of "form"
      
      form.appendFormComponents(); //append the "added" Form Components (fclabel and fcbuttonlist) to the "form"
      //Serial.println(form.get());
      
      //send message to channel
      ChannelMessageSend channelmessagesend; //create a new "ChannelMessageSend" object and feed it with the pointers to the char-array that will contain the json
      channelmessagesend.set(channelId,form.get()); //(channelId, dataComponent)
      //Serial.println(channelmessagesend.get());
      //Serial.println(channelmessagesend.getEPurl());
      
      webSocket.sendTXT(websocketheader.getRequest("reqId_2", communication_channel_message_send, channelmessagesend.get())); //embeds the "channelmessagesend" json into the "websocketheader" and send the message to the sme server (request id: "reqId_2")      
    }
  }
}
