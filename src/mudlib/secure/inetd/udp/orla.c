/* SIMAURIA '/secure/inetd/udp/orla.c'
   ==================================

*/

#include <udp.h>

void udp_orla(mapping data) {
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: "/lib/web/rorla.c"->Orla()
    ]) );
}


string send_orla(string mudname, string playername)
{
  string msg;
  if (msg = INETD->send_udp(mudname,
    ([ REQUEST: "orla", 
    SENDER: this_player()->QueryRealName(),
    DATA: playername ]), 1))
  {
    return (msg);
  }
  else {
    return("Petición enviada.\n");
  }
}
