# semilimes sdk for microcontrollers



## 💬 The semilimes ecosystem
semilimes is an innovative ecosystem that serves as a messaging app but offers much more than typical messaging platforms. In addition to standard messaging features, semilimes allows users to create multiple subaccounts. Those subaccounts can be controlled via the semilimes API, and they can be used for specific purposes, such as interacting with electronic devices, artificial intelligence, Node-RED, and other tools.

To enable a device to connect to the semilimes server and start interacting, it must receive an authentication key, which establishes a secure connection. This setup allows access to your devices without the need to expose your private network by opening ports on your modem for public network access. With semilimes, your devices will be accessible through the app, ensuring security and peace of mind!

With semilimes, you can interact with devices using standard text messages or through specialized forms and widgets, such as switches, buttons, sliders, map pickers, and more. Devices, as well as other users, can join channels, participate in group chats, engage in peer-to-peer conversations, and can be shared with other users, groups, or even made public. semilimes offers endless possibilities for connecting your devices or software, creating a mixed network of people and devices. semilimes is a social network for both humans and machines.

## ✨ What this sdk is about
The semilimes SDK is a C++ library designed to connect a variety of microcontrollers to the semilimes advanced messaging service. This SDK is optimized for use with the Arduino IDE but, due to its lack of external dependencies, it can also be used in other environments. The SDK is particularly notable for not utilizing dynamic memory allocation, which means character arrays must be predefined by the user, and the SDK accesses them through pointers.

The SDK allows developers to create JSON messages that comply with the OpenAPI structure used by semilimes APIs. 
All relevant information about the semilimes APIs can be found at the following link​ : https://www.semilimes.com/developers/

The documentation for the microcontroller semilimes SDKs has been generated using Doxygen and is accessible at: [semilimes sdk documentation](https://semilimes.github.io/semilimes_mcu_sdk/)

These messages can be sent via HTTPS or WebSocket, although the necessary libraries for these connections are not included in the SDK and must be implemented by the user. semilimes provides example applications to help developers get started, but selecting the most suitable libraries for server connections is the developer's responsibility.

## 🔎 What do you get

- Arduino IDE Compatibility: The library is designed to work seamlessly with the Arduino IDE.
- No External Dependencies: Can be used with other microcontrollers not compatible with the Arduino IDE due to its lack of external dependencies.
- Low Memory Usage: The library has a small footprint in both flash memory and RAM.
- Static Memory Allocation: Utilizes static memory allocation, which is referenced by the user's code, enhancing performance and predictability.
- Dynamic JSON Configuration: Supports the dynamic configuration and combination of JSON scripts, providing flexibility.
- Compatibility with HTTPS and WebSocket: Compatible with synchronous HTTPS calls and asynchronous WebSocket connections.
- Device Provisioning: Enables a secure device provisioning procedure on the Semilimes platform without requiring public API keys to be defined in the firmware.
- Guaranteed Cybersecurity: Robust security features ensure your network and data remain protected.
- Access via Advanced App: Seamlessly manage devices and services through the highly versatile semilimes mobile app.
- Cross-Platform Access: Connect and interact with devices through native iOS, android, Windows, Linux, MacOS applications, or by using the cross-platform Web app in a Web browser.
- Node-RED Integration: Easily integrate your IoT network with Node-RED instances that can be deployed either locally on your Edge computer, or in the Cloud.
- AI LLM Model Integration: Incorporate AI models into your setup, whether hosted locally, or in the Cloud.
- Transparent and Low Costs: Enjoy clear, usage-based pricing with very affordable rates, all available at 
[semilimes pricing](https://www.semilimes.com/pricing)

## 📽️ How does it work

To use the semilimes APIs, your device must first be connected to the Internet. This is essential because, without an Internet connection, the device cannot communicate with the semilimes platform. You'll need to include code in your project that handles this connection, typically through Wi-Fi or another protocol suitable for your hardware.

Once the device is online, the next critical step is called provisioning. Provisioning is the process by which your device is associated with a semilimes subprofile assigned to your user account. This subprofile acts as a unique identifier, allowing the semilimes platform to recognize and manage your device.

After the provisioning process is complete, your device can start communicating with semilimes using the provided APIs. This involves sending and receiving JSON messages structured according to the OpenAPI specifications used by semilimes. Through these steps, your microcontroller-based device becomes fully integrated into the semilimes platform, capable of utilizing its advanced messaging and data exchange features.

## ⚙️ Provisioning

To perform provisioning on the semilimes platform, it’s important to understand that each device has a unique identifier known as a "Device ID", which is tied to the hardware. This "Device ID" is essential for associating the device with a user profile on Semilimes.

To begin the provisioning process, you need to request the "Device Id" and a pair of keys from the semilimes Services portal: a "Provisioning Key" and a "Claim Key". The "Device ID" and "Provisioning Key" are embedded into the microcontroller, while the "Claim Key" is provided to the user in the form of a QR code.

In the first phase, the device sends a special message to the semilimes server containing the "Device ID" and "Provisioning Key". However, the device will only be fully activated and associated with the user’s subaccount after the QR code, containing the "Claim Key", is scanned by the user. Once the QR code is scanned, the server sends an "API-Key" to the device, which should be stored in non-volatile memory for future connections.

This secure process ensures that the device is correctly linked to the user’s account and can reliably interact with the semilimes platform. The keys required for provisioning can be easily requested through your semilimes Services portal: https://my.semilimes.net/apikeys

## 💡 Description of the JSON Structure for a semilimes API Call

Messages for interacting with the semilimes APIs must be formatted in JSON. These APIs allow you to connect a device to the semilimes server and interact by sending and receiving various types of messages.

There are several ways to send a message, such as to a channel, in a peer-to-peer chat, or in a group chat. The endpoints that define how each message is delivered are identified as "communication."

The content of the message (whether being sent or received) is nested within the "communication" and is referred to as the "Data Component". There are various types of "Data Components," each defining a different type of message. One specific type is the "Data Component Form," which represents a container for objects known as "Form Components" Each form can contain one or more form components, and these are nested within the "Data Component Form"

To ensure that messages are structured correctly, and are compatible with the semilimes OpenAPI, Software Development Kits (SDKs) are available. These SDKs provide the necessary tools and functions to compose messages in a way that adheres to the expected structure of the semilimes OpenAPI. This helps developers avoid errors and ensures seamless integration with the semilimes platform.

It is therefore important to note that to perform an API call, you need to know:

- Which endpoint to call.
- Which data component to use.
- Optionally, which form components to include.

For endpoints related to accounts, they are located at the first level, like "communication" endpoints, and require only the parameters defined in the API documentation.

Account Endpoints:

    header
    provisioning
    get_my_account
    get_account_profile
    get_account_feed
    add_account_feed

Communication Endpoints:

    get_my_channels
    get_channel
    get_channel_message
    channel_create
    send_channel_message
    update_channel_message
    channel_subscribe
    channel_unsubscribe
    bucket_open
    bucket_update
    bucket_like
    bucket_unlike
    p2p
    get_p2p_message
    send_p2p_message
    update_p2p_message
    send_p2p_reaction
    remove_p2p_reaction
    reply_p2p_message
    get_groupchats
    create_groupchat
    get_groupchat_message
    groupchat_invite
    send_groupchat_message
    send_groupchat_reaction
    remove_groupchat_reaction
    reply_groupchat_message
    websocket_header

Data Components:

    dc_simple_text
    dc_contact
    dc_html_text
    dc_file
    dc_location
    dc_webview
    dc_ch_reference
    dc_tunnel_reference
    dc_form

Form Components:

    button
    fc_label
    fc_text_box
    fc_switch
    fc_time_picker
    fc_slider
    fc_date_picker
    fc_location_picker
    fc_contact_picker
    fc_hidden_value
    fc_qr_scanner
    fc_nfc_reader
    fc_bucket_picker
    fc_single_choice
    fc_multiple_choice
    fc_button_list

To interact with the semilimes API, the JSON message structure must be carefully crafted to match the API's expectations. This involves selecting the appropriate endpoint, data component, and any nested form components, especially when dealing with complex forms. Understanding the structure of these components is crucial for successfully executing API calls. Utilizing the provided SDKs ensures that messages are composed correctly and remain compatible with the semilimes OpenAPI, facilitating smoother integration and communication with the semilimes platform.
