/***************************************************
The channel_websocket firmware is designed to demonstrate the implementation 
of the semilimes SDK and establish communication with a server via https. 

This example firmware, once connected to a Wi-Fi network and thereby to the 
internet, establishes an https connection to a server. 

Upon establishing the connection, the firmware creates a new channel in the 
subaccount associated with the provided API key. 
Once the channel is successfully created, it sends a form containing two form 
components: a label and a button list. 

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

#include <Arduino.h>
#include <ArduinoJson.h>
#include <semilimes.h>
    
bool WiFiConnected = false;

Header header;

WiFiMulti WiFiMulti;
const uint32_t connectTimeoutMs = 5000;
HTTPClient http;

char channelId[37];
bool msgReceivedChId = false;
void JSON_decode(String payload)
{
  //Serial.println(payload);  
  JsonDocument doc;
  deserializeJson(doc, payload);
  //check if is the "createdChannel" response 
  if(doc["data"]["createdChannel"]["channelId"])
  {
    msgReceivedChId = true;
    strcpy(channelId,doc["data"]["createdChannel"]["channelId"]);
  }
}

void setup()
{
    Serial.begin(115200);
    while (!Serial);
    delay(200);
      
    //devWiFiConnected = wifiProvisioning(rebootPin, led);  
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
    }
        
    //create a new channel
    ChannelCreate channelcreate; //create a new "CreateChannel" 
    channelcreate.set("New Channel from https","",false,true); //name="New Channel", avatar="", visible=false, locked=true
    http.begin(channelcreate.getEPurl());
    http.addHeader("accept",header.getAccept());
    http.addHeader("Content-Type",header.getContentType());
    http.addHeader("Authorization",header.getAuthorization());
    http.POST(channelcreate.get());  
    String response = http.getString();
    //Serial.print(response);
    JSON_decode(response);
    Serial.print("channelID: ");
    Serial.println(channelId);
    http.end();
    
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
          
      http.begin(channelmessagesend.getEPurl());
      http.addHeader("accept",header.getAccept());
      http.addHeader("Content-Type",header.getContentType());
      http.addHeader("Authorization",header.getAuthorization());
      http.POST(channelmessagesend.get());  
      Serial.println(http.getString()); 
      http.end();
    }
}

void loop() 
{
}
