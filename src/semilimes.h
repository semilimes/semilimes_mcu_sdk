#ifndef _semilimes_h_
#define _semilimes_h_

#include "utility/sme_json.h"
#include "account/header.h"
#include "account/provisioning.h"
#include "account/get_my_account.h"
#include "account/get_account_profile.h"
#include "account/get_account_feed.h"
#include "account/add_account_feed.h"

#include "communication/bucket_like.h"
#include "communication/bucket_open.h"
#include "communication/bucket_unlike.h"
#include "communication/bucket_update.h"
#include "communication/channel_create.h"
#include "communication/channel_get.h"
#include "communication/channel_message_get.h"
#include "communication/channel_message_send.h"
#include "communication/channel_message_update.h"
#include "communication/channel_subscribe.h"
#include "communication/channel_unsubscribe.h"
#include "communication/channels_my_get.h"
#include "communication/groupchat_create.h"
#include "communication/groupchat_invite.h"
#include "communication/groupchat_message_get.h"
#include "communication/groupchat_message_reply.h"
#include "communication/groupchat_message_send.h"
#include "communication/groupchat_message_update.h"
#include "communication/groupchat_reaction_remove.h"
#include "communication/groupchat_reaction_send.h"
#include "communication/groupchats_get.h"
#include "communication/groupchat_signal_typing.h"

#include "communication/p2p_message_get.h"
#include "communication/p2p_message_reply.h"
#include "communication/p2p_message_send.h"
#include "communication/p2p_messagE_update.h"
#include "communication/p2p_reaction_remove.h"
#include "communication/p2p_reaction_send.h"
#include "communication/p2p_signal_typing.h"
#include "communication/p2p.h"
#include "communication/websocket_header.h"

#include "components/dc_simple_text.h"
#include "components/dc_contact.h"
#include "components/dc_html_text.h"
#include "components/dc_file.h"
#include "components/dc_location.h"
#include "components/dc_webview.h"
#include "components/dc_ch_reference.h"
#include "components/dc_tunnel_reference.h"
#include "components/dc_form.h"
#include "components/dc_appointment.h"
#include "components/dc_gauge.h"

#include "components/fc_label.h"
#include "components/fc_text_box.h"
#include "components/fc_switch.h"
#include "components/fc_time_picker.h"
#include "components/fc_slider.h"
#include "components/fc_date_picker.h"
#include "components/fc_location_picker.h"
#include "components/fc_contact_picker.h"
#include "components/fc_hidden_value.h"
#include "components/fc_qr_scanner.h"
#include "components/fc_nfc_reader.h"
#include "components/fc_bucket_picker.h"
#include "components/fc_single_choice.h"
#include "components/fc_multiple_choice.h"
#include "components/fc_button_list.h"
#include "components/fc_event_picker.h"
#include "components/fc_color_picker.h"
#include "components/fc_gauge.h"

#endif;