#include "/secure/config.h"
#include UDP_HEADER

void udp_finger(mapping data) {
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: "/bin/cmds/_finger"->get_finger_string(data[DATA])
	/*DATA: "/bin/std/player"->Finger(data[DATA])*/
    ]) );
}
