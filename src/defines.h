#ifndef _include_h_
#define _include_h_

#include "utility/SME_JSON.h"

#define accept "application/json"
#define contentType "application/json"
#define authType "Bearer "

#define wsEP "/service/ws"
#define wsClientEP "/wsclient"
#define wsHost "api.semilimes.net"
#define wsPort 443

#define httpsUrl "https://api.semilimes.net"
#define registerDevice "/registerDevice"
#define deviceClaimStatus "/deviceClaimStatus"
#define communication_channel_my "/communication/channel/my"
#define communication_channel "/communication/channel"
#define communication_channel_create "/communication/channel/create"
#define communication_channel_message "/communication/channel/message"
#define communication_channel_message_send "/communication/channel/message/send"
#define communication_channel_update "/communication/channel/message/update"
#define communication_channel_subscribe "/communication/channel/subscribe"
#define communication_channel_unsubscribe "/communication/channel/unsubscribe"
#define communication_bucket "/communication/bucket"
#define communication_bucket_update "/communication/bucket/update"
#define communication_bucket_like "/communication/bucket/like"
#define communication_bucket_unlike "/communication/bucket/unlike"
#define communication_p2p "/communication/p2p"
#define communication_p2p_message "/communication/p2p/message"
#define communication_p2p_message_send "/communication/p2p/message/send"
#define communication_p2p_message_update "/communication/p2p/message/update"
#define communication_p2p_message_reaction_send "/communication/p2p/message/reaction/send"
#define communication_p2p_message_reaction_remove "/communication/p2p/message/reaction/remove"
#define communication_p2p_message_reply "/communication/p2p/message/reply"
#define communication_groupchat "/communication/groupchat"
#define communication_groupchat_create "/communication/groupchat/create"
#define communication_groupchat_message "/communication/groupchat/message"
#define communication_groupchat_invite "/communication/groupchat/invite"
#define communication_groupchat_message_send "/communication/groupchat/message/send"
#define communication_groupchat_message_update "/communication/groupchat/message/update"
#define communication_groupchat_message_reaction_send "/communication/groupchat/message/reaction/send"
#define communication_groupchat_message_reaction_remove "/communication/groupchat/message/reaction/remove"
#define communication_groupchat_message_reply "/communication/groupchat/message/reply"

#endif;