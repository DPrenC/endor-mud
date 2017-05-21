/* SIMAURIA '/secure/inetd/udp/webwho.c'
   ==================================
   [w] Woo@simauria
   [m] Mirill@Simauria
   10-09-99 [w] Hace que llame a "/lib/rquien.c" el cual devolverá el
                texto que verán los que nos hagan un who remoto.
   16-06-99 [m] Basandose en el "/who.c" comienzo la implementacion de los
   		comandos que permitiran al mud comunicarse con la Web a
   		a traves de UDP.

*/

#include <udp.h>

void udp_webwho(mapping data) {
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: "/lib/web/rwebwho.c"->Quien()
    ]) );
}


string send_webwho(string mudname, string playername)
{
  string msg;
  if (msg = INETD->send_udp(mudname,
    ([ REQUEST: "webwho", 
    SENDER: this_player()->QueryRealName(),
    DATA: playername ]), 1))
  {
    return (msg);
  }
  else {
    return("Petición enviada.\n");
  }
}
