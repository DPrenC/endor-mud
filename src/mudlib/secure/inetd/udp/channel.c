#include "/secure/config.h"
#include UDP_HEADER

/* from inetd/examples/channel.h */
#define CHANNEL         "channel"
#define COMMAND         "cmd"
#define CHANNELD	CHANNELMASTER

void udp_channel(mapping data) {
    mapping reply;
    object *list;
    string msg;
    int i;

    /* Compatability with older systems. */
    if (!data[CHANNEL])
	data[CHANNEL] = data["CHANNEL"];
    if (!data[COMMAND])
	data[COMMAND] = data["CMD"];

    reply = ([
	REQUEST: REPLY,
	ID: data[ID]
    ]);
    switch(data[COMMAND]) {
	case "list":
	    reply[RECIPIENT] = data[SENDER];

	    /* Request for a list of people listening to a certain channel. */
	    list = CHANNELD->ListChannelUsers(data[CHANNEL]);
            /* remove invisibles */
            if (sizeof(list))
                list -= filter_objects(list,"QueryInvis");
	    if (i = sizeof(list)) {
		msg = "[" + capitalize(data[CHANNEL]) + "@" +
		LOCAL_NAME + "] Listening:\n";
		while(i--)
		    msg +=
		    "    " + capitalize(list[i]->QueryRealName()) + "\n";
	    }
	    else
		msg = "[" + capitalize(data[CHANNEL]) + "@" +
		LOCAL_NAME + "] Nobody Listening.\n";
            reply[DATA] = msg;
            break;
	default:
	    CHANNELD->send_local_message(data);
	    break;
    }
    INETD->send_udp(data[NAME], reply);
}
