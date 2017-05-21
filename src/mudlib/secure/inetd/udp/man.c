#include "/secure/config.h"
#include UDP_HEADER

void udp_man(mapping data) {

    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: "Got man request for: "+data[DATA]+".\nRemote man will soon be implemented in Nightfall!\n"
    ]) );
}


string send_man(string mudname, string manname)
{
  string msg;
  if (msg = INETD->send_udp(mudname,
    ([ REQUEST: "man",
    SENDER: this_player()->QueryRealName(),
    DATA: manname ]), 1))
  {
    return (msg);
  }
  else {
    return("Request sent.\n");
  }
}
