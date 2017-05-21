/* SIMAURIA '/secure/inetd/udp/who.c'
   ==================================
   [w] Woo@simauria

   10-09-99 [w] Hace que llame a "/lib/rquien.c" el cual devolverá el
                texto que verán los que nos hagan un who remoto.
*/

#include <udp.h>

void udp_lista(mapping data) {
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: "/lib/rlista.c"->Quien()
    ]) );
}


string send_lista(string mudname, string playername)
{
  string msg;
  if (msg = INETD->send_udp(mudname,
    ([ REQUEST: "lista", 
    SENDER: this_player()->QueryRealName(),
    DATA: playername ]), 1))
  {
    return (msg);
  }
  else {
    return("Petición enviada.\n");
  }
}
