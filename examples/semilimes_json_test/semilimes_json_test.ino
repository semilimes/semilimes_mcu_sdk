/***************************************************
The semilimes SDK connects microcontrollers to the semilimes server, enabling
secure instant messaging with forms and widgets. It supports interaction in
peer-to-peer chats, channels, and group chats, all while ensuring maximum
cybersecurity through the semilimes platform.

This project was designed to test the creation of all JSON scripts required by
the SDKs to enable the use of semilimes APIs. The scripts are printed via
serial output, and the example does not include a connection to the server.
The primary goal was to ensure that the generated scripts are correctly
formatted and ready for future integration with the semilimes platform.

This project is licensed under the MIT License.
 ****************************************************/

#include <Arduino.h>
#include <semilimes.h>
      
void setup()
{
    Serial.begin(115200);
    while (!Serial);
    
    char json[1000], json_array[400], json_array2[500], json_form_component[500], json_data_component[1000];
      
    //*************************** ACCOUNT ***************************
    //create the header
    /*char authorization[200], json_header[200], ws_header[200];
    Header header(authorization, json_header, ws_header);
    header.setAuthorization("*** ApiKey ***");
    Serial.println(header.getHttpsUrl());
    Serial.println(header.getWsEP());
    Serial.println(header.getWsClientEP());
    Serial.println(header.getWsHost());
    Serial.println(header.getWsPort()); 
    Serial.println(header.getWsHeader()); 
    Serial.println(header.getContentType());  
    Serial.println(header.getAuthorization());   
    Serial.println(header.getAccept());*/   

    //provisioning
    /*Provisioning provisioning(json);
    provisioning.setObj("*** Device ID ***","*** Provisioning Key ***");
    Serial.println(provisioning.getRegisterDeviceURL());
    Serial.println(provisioning.getDeviceClaimStatusURL());
    Serial.println(json);*/

    //get my Account data
    /*GetMyAccount getmyaccount(json);
    getmyaccount.setObj(true,false,true,false);
    Serial.println(json);*/

    //get account profile data
    /*GetAccountProfile getaccountprofile(json);
    getaccountprofile.setObj("*** Account ID ***");
    Serial.println(json);*/

    //get account feeds
    /*GetAccountFeed getaccountfeed(json);
    getaccountfeed.setObj("*** Account ID ***",5,2,10);
    Serial.println(json);*/
    
    //add account feed
    //create a simpleText Data Component
    /*DcSimpleText dcsimpletxt1(json_data_component);
    dcsimpletxt1.setObj("hello from semilimes sdk!!!");
    AddAccountFeed addAccountFeed(json,json_array);
    addAccountFeed.setObj("feed title","feed descriprion","avatar_fileId",false,true,false);
    addAccountFeed.addDataComponents(json_data_component);
    addAccountFeed.addDataComponents(json_data_component);
    addAccountFeed.appendDataComponents();
    Serial.println(json);*/
    
    //*********************************************************************
    
    //*************************** FC COMPONENTS ***************************
      
    //create Label Form Component
    /*FcLabel fclabel(json_form_component);
    fclabel.setObj("Label","Label Title");
    Serial.println(json_form_component);*/
        
    //create switch Form Component
    /*FcSwitch fcswitch(json_form_component);
    fcswitch.setObj("switchRef","switch Title",1);
    Serial.println(json_form_component);
    fcswitch.setObj("switchRef","switch Title",0);
    Serial.println(json_form_component);*/
    
    //create TextBox Form Components
    /*FcTextBox textbox2(json_form_component);
    textbox2.setObj("textbox2","TB Title","content of the textbox2!!",true);
    Serial.println(json_form_component);
    textbox2.setObj("textbox2","TB Title","content of the textbox2!!");
    Serial.println(json_form_component);*/

    //create date picker Form Component
    /*FcTimePicker fctimepicker(json_form_component);
    fctimepicker.setObj("mytimePicker","time picker Title",false,"","Select time");
    Serial.println(json_form_component);*/
    
    //create slider Form Component
    /*FcSlider fcslider(json_form_component);
    fcslider.setObj("slider","slider Title",true,20,0,100,5);
    Serial.println(json_form_component);*/

    //create Location picker Form Component
    /*FcLocationPicker fclocationpicker(json_form_component);
    fclocationpicker.setObj("mylocationPicker","location picker Title",false,"","Select Location",false);
    Serial.println(json_form_component);*/

    //create date picker Form Component
    /*FcDatePicker fcdatepicker(json_form_component);
    fcdatepicker.setObj("mydatePicker","date picker Title",false,"","Select Date");
    Serial.println(json_form_component);*/

    //create contact picker Form Component
    /*FcContactPicker fccontactpicker(json);
    fccontactpicker.setObj("mycontactPicker","contact picker Title",false,"","Select Contact",true);
    Serial.println(json);*/
    
    //create hidden value Form Component
    /*FcHiddenValue fchiddenvalue(json_form_component);
    fchiddenvalue.setObj("hidden value","hidden");
    Serial.println(json_form_component);*/
    
    //create qr scaner Form Component
    /*FcQrScanner fcqrscanner(json_form_component);
    fcqrscanner.setObj("myQrScanner","qr scanner Title",false,"","Scan QR Code");
    Serial.println(json_form_component);*/

    //create NFC reader Form Component
    /*FcNfcReader nfcreader(json_form_component);    
    nfcreader.setObj("myNFCreader","nfc reader Title",false,"","Read NFC");
    Serial.println(json_form_component);*/
    
    //create bucket picker Form Component
    /*FcBucketPicker fcbucketpicker(json_form_component,json_array);
    fcbucketpicker.setObj("myBucketPicker","bucket picker Title",false,"","Select Bucket",true);
    fcbucketpicker.addValue(fcbucketpicker.featureTypes[0]);
    fcbucketpicker.appendValue();
    Serial.println(json_form_component);
    fcbucketpicker.setObj("myBucketPicker2","bucket picker Title",true,"","Select Bucket",false);
    fcbucketpicker.addValue(fcbucketpicker.featureTypes[0]);
    fcbucketpicker.addValue(fcbucketpicker.featureTypes[2]);
    fcbucketpicker.appendValue();
    Serial.println(json_form_component);*/

    //create single choice Form Component
    /*FcSingleChoice fcsinglechoice(json_form_component,json_array);
    fcsinglechoice.setObj("single choice1 ref name","single choice title",true,"choice1value");
    fcsinglechoice.addOptions("button1","choice1"); 
    fcsinglechoice.addOptions("button2","choice2");
    fcsinglechoice.appendOptions();
    Serial.println(json_form_component);
    fcsinglechoice.setObj("single choice1 ref name","single choice title",true,"choice1value");
    fcsinglechoice.addOptions("button3","choice3");
    fcsinglechoice.appendOptions();
    Serial.println(json_form_component);*/

    //create multiple choice Form Component
    /*FcMultipleChoice fcmultiplechoice(json_form_component,json_array,json_array2);
    fcmultiplechoice.setObj("multi choice1 ref name","multi choice title",true);
    fcmultiplechoice.addValues("choice1");
    fcmultiplechoice.addValues("choice2");
    fcmultiplechoice.appendValues();    
    fcmultiplechoice.addOptions("button1","choice1");   
    fcmultiplechoice.addOptions("button2","choice2");
    fcmultiplechoice.appendOptions();
    Serial.println(json_form_component);
    fcmultiplechoice.setObj("multi choice1 ref name","multi choice title",false);
    fcmultiplechoice.addValues("choice3");
    fcmultiplechoice.appendValues();    
    fcmultiplechoice.addOptions("button3","choice3");
    fcmultiplechoice.appendOptions();
    Serial.println(json_form_component);*/

    //create a button list Form Component
    /*FcButtonList fcbuttonlist(json_form_component,json_array);
    fcbuttonlist.setObj("myButtonList","Button List",false,"buttonName",true);
    fcbuttonlist.addOptions("button1","choice1");   
    fcbuttonlist.addOptions("button2","choice2");
    fcbuttonlist.appendOptions();
    Serial.println(json_form_component);
    fcbuttonlist.setObj("myButtonList2","Button List2",false,"buttonName2",true);
    fcbuttonlist.addOptions("button3","choice3");
    fcbuttonlist.appendOptions();
    Serial.println(json_form_component);*/
    
    //*********************************************************************
    
    
    //*************************** DC COMPONENTS ***************************
    //create a simpleText Data Component
    /*DcSimpleText dcsimpletxt1(json_data_component);
    dcsimpletxt1.setObj("hello 1 from c++ sme lib!!!");
    Serial.println(json_data_component);*/

    //create a contact Data Component
    /*DcContact dccontact(json_data_component,json_array);
    dccontact.addContactIds("contact id number1");
    dccontact.addContactIds("contact id number2");
    dccontact.addContactIds("contact id number3");
    dccontact.addContactIds("contact id number4");
    dccontact.appendDataContactIds();
    Serial.println(json_data_component);
    dccontact.setObj();
    dccontact.addContactIds("contact id number5");
    dccontact.appendDataContactIds();
    Serial.println(json_data_component);*/

    //create a htmlText Data Component
    /*DcHtmlText dchtmltext(json_data_component);
    dchtmltext.setObj("<p> html text </p>");
    Serial.println(json_data_component);*/
    
    //create a File Data Component
    /*DcFile dcfile(json_data_component,json_array);
    dcfile.addFileIds("id number1");
    dcfile.addFileIds("id number2");
    dcfile.addFileIds("id number3");
    dcfile.addFileIds("id number4");
    dcfile.appendFileIds();
    Serial.println(json_data_component);*/

    //create a location Data Component
    /*DcLocation dclocation(json_data_component);
    dclocation.setObj("Genova", 44.405650, 8.946256);
    Serial.println(json_data_component);*/
    
    //create a Webview Data Component
    /*DcWebview dcwebview(json_data_component);
    dcwebview.setObj("http://www.google.it",true,dcwebview.viewSizeTypes[1]);
    Serial.println(json_data_component);*/

    //create a channel reference Data Component
    /*DcChReference dcchreference(json_data_component);
    dcchreference.setObj("myChannelId");
    Serial.println(json_data_component);*/
    
    //create a tunnel reference Data Component
    /*DcTunnelReference dctunnelreference(json_data_component);
    dctunnelreference.setObj("myTunnelId");
    Serial.println(json_data_component);*/
    
    //create a new Form    
    /*DcForm form(json_data_component,json_array);  
    form.setObj(true,true,"submit text","refname");
    form.addReceiver("*** receiverID ***",form.featureType[2]);
    form.addFormComponents(json_form_component);
    form.appendFormComponents();
    Serial.println(json_data_component);*/

    //*********************************************************************
    
    
    //*************************** COMMUNICATION ***************************  

    
    //******* BUCKET *******
    
    //bucket open
    /*BucketOpen bucketopen(json);
    bucketopen.setObj("*** bucketId ***");
    Serial.println(json);
    Serial.println(bucketopen.getEPurl());*/
    
    //bucket update
    /*BucketUpdate bucketupdate(json, json_array);
    bucketupdate.setObj("*** bucketId ***","bucket Title","description","*** avatarId ***",true,false,true);
    bucketupdate.addDataComponents(json_data_component);
    bucketupdate.appendDataComponents();
    Serial.println(json);
    Serial.println(bucketupdate.getEPurl());*/
    
    //bucket like
    /*BucketLike bucketlike(json);
    bucketlike.setObj("*** bucketId ***");
    Serial.println(json);
    Serial.println(bucketlike.getEPurl());*/
    
    //bucket unlike
    /*BucketUnlike bucketunlike(json);
    bucketunlike.setObj("*** bucketId ***");
    Serial.println(json);
    Serial.println(bucketunlike.getEPurl());*/

     
    //******* CHANNEL *******
    
    //get my Channels
    /*ChannelsMyGet channelsmyget(json);
    channelsmyget.setObj(true,false,true);
    Serial.println(json);
    Serial.println(channelsmyget.getEPurl());*/
    
    //get Channel
    /*ChannelGet channelget(json);
    channelget.setObj("*** ownerId ***","*** editorId ***","*** channelId ***","title");
    Serial.println(json);
    Serial.println(channelget.getEPurl());*/
    
    //get Channel msgs
    /*ChannelMessageGet channelmessageget(json);
    channelmessageget.setObj("*** channelId ***","*** messageId ***",4);
    Serial.println(json);
    Serial.println(channelmessageget.getEPurl());*/
    
    //create channel
    /*ChannelCreate channelcreate(json,json_array);
    channelcreate.setObj("*** chTitle ***","*** avatarId ***",false,true);
    channelcreate.addEditorsIds("*** editorId_1 ***");
    channelcreate.addEditorsIds("*** editorId_2 ***");
    channelcreate.appendEditorsIds();
    Serial.println(json);
    Serial.println(channelcreate.getEPurl());*/
    
    //send message to channel
    /*ChannelMessageSend channelmessagesend(json);
    channelmessagesend.setObj("*** channelId ***",json_data_component);
    Serial.println(json);
    Serial.println(channelmessagesend.getEPurl());*/
    
    //channel subscribe
    /*ChannelSubscribe channelsubscribe(json);
    channelsubscribe.setObj("*** channelId ***");
    Serial.println(json);
    Serial.println(channelsubscribe.getEPurl());*/
    
    //channel unsubscribe
    /*ChannelUnsubscribe channelunsubscribe(json);
    channelunsubscribe.setObj("*** channelId ***");
    Serial.println(json);
    Serial.println(channelunsubscribe.getEPurl());*/

    
    //******* GROUPCHAT *******
    
    //create groupchat
    /*GroupchatCreate groupchatcreate(json,json_array);
    groupchatcreate.setObj("*** groupchat Title ***");
    groupchatcreate.addRecipientId("*** editorId_1 ***");
    groupchatcreate.addRecipientId("*** editorId_2 ***");
    groupchatcreate.appendRecipientIds();
    Serial.println(json);
    Serial.println(groupchatcreate.getEPurl());*/
   
    //get groupchats
    /*GroupchatsGet groupchatsget(json,json_array);
    groupchatsget.setObj();
    Serial.println(json);
    Serial.println(groupchatsget.getEPurl());*/
    
    //get groupchat msgs
    /*GroupchatMessageGet groupchatmessageget(json);
    groupchatmessageget.setObj("*** groupchatlId ***","*** messageId ***",4);
    Serial.println(json);
    Serial.println(groupchatmessageget.getEPurl());*/

    //groupchat invite
    /*GroupchatInvite groupchatinvite(json,json_array);
    groupchatinvite.setObj("*** groupchatId ***");
    Serial.println(json);
    Serial.println(groupchatinvite.getEPurl());*/
    
    //send message to groupchat
    /*GroupchatMessageSend groupchatmessagesend(json);
    groupchatmessagesend.setObj("*** groupChatId ***",json_data_component);
    Serial.println(json);
    Serial.println(groupchatmessagesend.getEPurl());*/
    
    //send groupchat reaction
    /*GroupchatReactionSend groupchatreactionsend(json);
    groupchatreactionsend.setObj("*** messageId ***","*** reaction ***");
    Serial.println(json);
    Serial.println(groupchatreactionsend.getEPurl());*/
    
    //remove groupchat reaction
    /*GroupchatReactionRemove groupchatreactionremove(json);
    groupchatreactionremove.setObj("*** messageId ***","*** reaction ***");
    Serial.println(json);
    Serial.println(groupchatreactionremove.getEPurl());*/
    
    //reply groupchat message
    /*GroupchatMessageReply groupchatmessagereply(json);
    groupchatmessagereply.setObj("*** messageId ***",json_data_component);
    Serial.println(json);
    Serial.println(groupchatmessagereply.getEPurl());*/
    
    //update groupchat message
    /*GroupchatMessageUpdate groupchatmessageupdate(json);
    groupchatmessageupdate.setObj("*** messageId ***",json_data_component);
    Serial.println(json);
    Serial.println(groupchatmessageupdate.getEPurl());*/
    

    //******* PEER TO PEER *******
    
    //get p2p message
    /*P2pMessageGet p2pmessageget(json);
    p2pmessageget.setObj("*** recipientId ***","*** messageId ***",4);
    Serial.println(json);
    Serial.println(p2pmessageget.getEPurl());*/
    
    //reply p2p message
    /*P2pMessageReply p2pmessagereply(json);
    p2pmessagereply.setObj("*** messageId ***",json_data_component);
    Serial.println(json);
    Serial.println(p2pmessagereply.getEPurl());*/
    
    //send p2p message
    /*P2pMessageSend p2pmessagesend(json);
    p2pmessagesend.setObj("*** recipientId ***",json_data_component);
    Serial.println(json);
    Serial.println(p2pmessagesend.getEPurl());*/
    
    //update p2p message
    /*P2pMessageUpdate p2pmessageupdate(json);
    p2pmessageupdate.setObj("*** messageId ***",json_data_component);
    Serial.println(json);
    Serial.println(p2pmessageupdate.getEPurl());*/
    
    //remove p2p reaction
    /*P2pReactionRemove p2preactionremove(json);
    p2preactionremove.setObj("*** messageId ***","*** reaction ***");
    Serial.println(json);
    Serial.println(p2preactionremove.getEPurl());*/
    
    //send p2p reaction
    /*P2pReactionSend p2preactionsend(json);
    p2preactionsend.setObj("*** messageId ***","*** reaction ***");
    Serial.println(json);
    Serial.println(p2preactionsend.getEPurl());*/
    
    //p2p chat retrieves
    /*P2p p2p;
    Serial.println(p2p.getEPurl());*/
    
    //p2p chat retrieves
    /*WebsocketHeader websocketheader(json);
    Serial.println(websocketheader.getRequest("*** requestId ***", "*** requestType ***", "*** body ***"));*/

    
    //********************************************************************* 
    
    //******************************* DEVICE ******************************  

    //create a new device
    /*char jdevice[500],jpins[500],jfunctions[500];
    Device device(jdevice,jpins,jfunctions);
    device.setObj("deviceN1");
    device.addGPIO("pinA1", device.pinTypes[0], "portA", 14, 0);
    device.addGPIO("pinB1", device.pinTypes[1], "portB", 1, 0);
    device.addGPIO("pinB2", device.pinTypes[1], "portB", 2, 0);
    device.appendGPIOs();
    device.addFunction("KitchenTemp", "AcqD0()");
    device.appendFunctions();
    Serial.println(jdevice);*/
    
    //*********************************************************************     
    
}

void loop() 
{
}
