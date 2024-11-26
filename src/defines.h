#ifndef _include_h_
#define _include_h_

#include "utility/SME_JSON.h"
//#include <Arduino.h>

#define sme_accept "application/json"
#define sme_contentType "application/json"
#define sme_authType "Bearer "

#define sme_wsEP "/service/ws"
#define sme_wsClientEP "/wsclient"
#define sme_wsHost "api.semilimes.net"
#define sme_wsPort 443

#define sme_httpsUrl "https://api.semilimes.net"
#define sme_registerDevice "/registerDevice"
#define sme_deviceClaimStatus "/deviceClaimStatus"
#define sme_resetDevice "/resetDevice"
#define sme_communication_channel_my "/communication/channel/my"
#define sme_communication_channel "/communication/channel"
#define sme_communication_channel_create "/communication/channel/create"
#define sme_communication_channel_message "/communication/channel/message"
#define sme_communication_channel_message_send "/communication/channel/message/send"
#define sme_communication_channel_update "/communication/channel/message/update"
#define sme_communication_channel_subscribe "/communication/channel/subscribe"
#define sme_communication_channel_unsubscribe "/communication/channel/unsubscribe"
#define sme_communication_bucket "/communication/bucket"
#define sme_communication_bucket_update "/communication/bucket/update"
#define sme_communication_bucket_like "/communication/bucket/like"
#define sme_communication_bucket_unlike "/communication/bucket/unlike"
#define sme_communication_p2p "/communication/p2p"
#define sme_communication_p2p_message "/communication/p2p/message"
#define sme_communication_p2p_message_send "/communication/p2p/message/send"
#define sme_communication_p2p_message_update "/communication/p2p/message/update"
#define sme_communication_p2p_message_reaction_send "/communication/p2p/message/reaction/send"
#define sme_communication_p2p_message_reaction_remove "/communication/p2p/message/reaction/remove"
#define sme_communication_p2p_message_reply "/communication/p2p/message/reply"
#define sme_communication_p2p_signal_typing "/communication/p2p/signal/typing"
#define sme_communication_groupchat "/communication/groupchat"
#define sme_communication_groupchat_create "/communication/groupchat/create"
#define sme_communication_groupchat_message "/communication/groupchat/message"
#define sme_communication_groupchat_invite "/communication/groupchat/invite"
#define sme_communication_groupchat_message_send "/communication/groupchat/message/send"
#define sme_communication_groupchat_message_update "/communication/groupchat/message/update"
#define sme_communication_groupchat_message_reaction_send "/communication/groupchat/message/reaction/send"
#define sme_communication_groupchat_message_reaction_remove "/communication/groupchat/message/reaction/remove"
#define sme_communication_groupchat_message_reply "/communication/groupchat/message/reply"
#define sme_communication_groupchat_signal_typing "/communication/groupchat/signal/typing"

#endif;