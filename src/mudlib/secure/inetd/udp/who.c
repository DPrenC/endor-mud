/* SIMAURIA '/secure/inetd/udp/who.c'
   ==================================
   [w] Woo@simauria

   10-09-99 [w] Hace que llame a "/lib/rquien.c" el cual devolverá el
                texto que verán los que nos hagan un who remoto.
*/

#include <udp.h>

void udp_who(mapping data) {
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: "/lib/rquien.c"->Quien()
    ]) );
}
