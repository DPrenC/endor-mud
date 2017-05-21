#include "/secure/config.h"
#include UDP_HEADER

#define FOUND		"fnd"
#define USER		"user"
#define VERBOSE		"vbs"

void udp_locate(mapping data) {
    mapping ret;
    object ob;

    ret = ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	USER: data[USER],
	VERBOSE: data[VERBOSE],
    ]);
    if (data[DATA] && (ob = find_object(lower_case(data[DATA]))) &&
    interactive(ob) && ob->Short() && !ob->QueryInvis()) {
	ret[FOUND] = 1;
	ret[DATA] = "locate@" + LOCAL_NAME + ": " + ob->Short() + "\n";
    }
    else
	ret[DATA] = "locate@" + LOCAL_NAME + ": No such player: " +
	data[DATA] + "\n";
    INETD->send_udp(data[NAME], ret);
}
