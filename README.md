# semilimes sdk for microcontrollers



## 💬 The semilimes ecosystem
semilimes is an innovative ecosystem that serves as a messaging app but offers much more than typical messaging platforms. In addition to standard messaging features, semilimes allows users to create multiple subaccounts, each with the same capabilities as the main account, which can be used for specific purposes such as interacting with electronic devices, artificial intelligence, Node-RED, and other tools.

To enable a device to connect to the semilimes server and start interacting, it must receive an authentication key, which establishes a secure connection. This setup allows access to your devices without the need to expose your private network by opening ports on your modem for public network access. With semilimes, your devices will be accessible through the app, ensuring security and peace of mind!

With semilimes, you can interact with devices using standard text messages or through specialized forms and widgets, such as switch buttons, sliders, map pickers, and more. Devices, like other users, can join channels, participate in group chats, engage in peer-to-peer conversations, and can be shared with other users, groups, or even made public. semilimes offers endless possibilities for connecting your devices or software, creating a mixed network of people and devices. semilimes is a social network for both humans and machines.

## ✨ What this sdk is about
The semilimes SDK is a C++ library designed to connect a variety of microcontrollers to the semilimes advanced messaging service. This SDK is optimized for use with the Arduino IDE but, due to its lack of external dependencies, it can also be used in other environments. 

The SDK allows developers to create JSON messages that conform to the OpenAPI structure used by semilimes APIs. 
All relevant information about the semilimes APIs can be found at the following link​ : [semilimes Developers page](https://www.semilimes.com/developers/)

The documentation for the semilimes SDKs has been generated using Doxygen and is accessible at the following page: [semilimes sdk documentation](https://semilimes.github.io/semilimes_mcu_sdk/)

These messages can be sent via HTTPS or WebSocket, although the necessary libraries for these connections are not included in the SDK and must be implemented by the user. semilimes provides example applications to help developers get started, but selecting the most suitable libraries for server connections is the developer's responsibility.

## 🔎 What do you get

- Arduino IDE Compatibility: The library is designed to work seamlessly with the Arduino IDE.
- No External Dependencies: Can be used with other microcontrollers not compatible with the Arduino IDE due to its lack of external dependencies.
- Low Memory Usage: The library has a small footprint in both flash memory and RAM.
- Dynamic JSON Configuration: Supports the dynamic configuration and combination of JSON scripts, providing flexibility.
- Compatibility with HTTPS and WebSocket: Compatible with synchronous HTTPS calls and asynchronous WebSocket connections.
- Device Provisioning: Enables a secure device provisioning procedure on the semilimes platform without requiring public API keys to be defined in the firmware.
- Guaranteed Cybersecurity: Robust security features ensure your network and data remain protected.
- Access via Advanced App: Seamlessly manage devices and services through a highly advanced mobile app.
- Cross-Platform Access: Connect and interact with devices through Windows, Linux, or web-based applications.
- Node-RED Integration: Easily integrate your sensor network with Node-RED instances, either locally or in the cloud.
- AI LLM Model Integration: Incorporate AI models into your setup, whether hosted locally or in the cloud.
- Transparent and Low Costs: Enjoy clear, usage-based pricing with affordable rates, all available on the website [semilimes](www.semilimes.com).

## 📽️ How does it work

To use the semilimes APIs, your device must first be connected to the internet. This is essential because, without an internet connection, the device cannot communicate with the semilimes platform. You'll need to include code in your project that handles this connection, typically through Wi-Fi or another protocol suitable for your hardware.

Once the device is online, the next critical step is called provisioning. Provisioning is the process by which your device is associated with a semilimes subprofile assigned to your user account. This subprofile acts as a unique identifier, allowing the semilimes platform to recognize and manage your device.

After the provisioning process is complete, your device can start communicating with semilimes using the provided APIs. This involves sending and receiving JSON messages structured according to the OpenAPI specifications used by semilimes. Through these steps, your microcontroller-based device becomes fully integrated into the semilimes platform, capable of utilizing its advanced messaging and data exchange features.

## ⚙️ Provisioning

To perform provisioning on the semilimes platform, it’s important to understand that each device has a unique identifier known as a "Device ID", which is tied to the hardware. This "Device ID" is essential for associating the device with a user profile on semilimes.

To begin the provisioning process, you need to request the "Device Id" and a pair of keys from the semilimes Services portal: a "Provisioning Key" and a "Claim Key". The "Device ID" and "Provisioning Key" are embedded into the microcontroller, while the "Claim Key" is provided to the user in the form of a QR code.

In the first phase, the device sends a special message to the semilimes server containing the "Device ID" and "Provisioning Key". However, the device will only be fully activated and associated with the user’s subaccount after the QR code, containing the "Claim Key", is scanned by the user. Once the QR code is scanned, the server sends an "API-Key" to the device, which should be stored in non-volatile memory for future connections.

This secure process ensures that the device is correctly linked to the user’s account and can reliably interact with the semilimes platform. The keys required for provisioning can be easily requested through your semilimes Services portal: [semilimes Portal - Apikeys](https://my.semilimes.net/apikeys)

## 💡 Description of the JSON Structure for a semilimes API Call

Messages for interacting with the semilimes APIs must be formatted in JSON. These APIs allow you to connect a device to the semilimes server and interact by sending and receiving various types of messages.

There are several ways to send a message, such as to a channel, in a peer-to-peer chat, or in a group chat. The endpoints that define how each message is delivered are identified as "communication."

The content of the message (whether being sent or received) is nested within the "communication" and is referred to as the "Data Component". There are various types of "Data Components," each defining a different type of message. One specific type is the "Data Component Form," which represents a container for objects known as "Form Components" Each form can contain one or more form components, and these are nested within the "Data Component Form"

To ensure that messages are structured correctly and are compatible with the semilimes OpenAPI, Software Development Kits (SDKs) are available. These SDKs provide the necessary tools and functions to compose messages in a way that adheres to the expected structure of the semilimes OpenAPI. This helps developers avoid errors and ensures seamless integration with the semilimes platform.

It is therefore important to note that to perform an API call, you need to know:

- Which endpoint to call.
- Which data component to use.
- Optionally, which form components to include.

For endpoints related to accounts, they are located at the first level, like "communication" endpoints, and require only the parameters defined in the API documentation.

Account Endpoints:

    add_account_feed
    get_account_feed
    get_account_profile
    get_my_account
    header
    provisioning

Communication Endpoints:

    bucket_like
    bucket_open
    bucket_unlike
    bucket_update
    channel_create
    channel_get
    channel_message_get
    channel_message_send
    channel_message_update
    channel_subscribe
    channel_unsubscribe
    channels_my_get
    groupchat_create
    groupchat_invite
    groupchat_message_get
    groupchat_message_reply
    groupchat_message_send
    groupchat_message_update
    groupchat_reaction_remove
    groupchat_reaction_send
    groupchat_signal_typing
    groupchats_get
    p2p_message_get
    p2p_message_reply
    p2p_message_send
    p2p_message_update
    p2p_reaction_remove
    p2p_reaction_send
    p2p_signal_typing
    p2p
    websocket_header

Data Components:

    dc_appointment
    dc_ch_reference
    dc_contact
    dc_file
    dc_form
    dc_gauge
    dc_html_text
    dc_location
    dc_simple_text
    dc_tile_view
    dc_tunnel_reference
    dc_webview

Form Components:

    fc_bucket_picker
    fc_button_list
    fc_color_picker
    fc_contact_picker
    fc_date_picker
    fc_event_picker
    fc_gauge
    fc_hidden_value
    fc_label
    fc_location_picker
    fc_multiple_choice
    fc_nfc_reader
    fc_qr_scanner
    fc_single_choice
    fc_slider
    fc_switch
    fc_text_box
    fc_time_picker

To interact with the semilimes API, the JSON message structure must be carefully crafted to match the API's expectations. This involves selecting the appropriate endpoint, data component, and any nested form components, especially when dealing with complex forms. Understanding the structure of these components is crucial for successfully executing API calls. Utilizing the provided SDKs ensures that messages are composed correctly and remain compatible with the semilimes OpenAPI, facilitating smoother integration and communication with the semilimes platform.
