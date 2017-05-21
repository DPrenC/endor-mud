/* SIMAURIA '/secure/inetd/udp/finger.c'
   =====================================
   [w] Woo@simauria
   
   26-10-99 [w] Actualizado para que funcione con el finger nuestro.
   01-12-99 [w] Pues nada, que no queria ejecutar el lib/finger.
*/

#include "/secure/config.h"
#include UDP_HEADER

void udp_finger(mapping data) {
    seteuid(getuid());
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: "/lib/finger"->Finger(data[DATA], (["remote":1]))
    ]) );
}

string send_finger(string mudname, string playername)
{
  string msg;
  if (msg = INETD->send_udp(mudname,
    ([ REQUEST: "finger", 
    SENDER: this_player()->QueryRealName(),
    DATA: playername ]), 1))
  {
    return (msg);
  }
  else {
    return("Petición enviada.\n");
  }
}
