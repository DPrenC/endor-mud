#include "/secure/config.h"
#include UDP_HEADER

#ifdef ZEBEDEE
inherit "/sys/format";
#endif

#define FROM	"frm"

void udp_tell(mapping data) {
    object ob;
    int rc; /* 1: Ok, 0: ignore, -1: Silent ignore */
    string away;

    /* Compat with old-style SENDER handling. */
    if (data[SENDER])
	data[FROM] = data[SENDER];
    else
        data[FROM] = "?";
    if (data[RECIPIENT] && (ob = find_object(lower_case(data[RECIPIENT]))) &&
    interactive(ob) ) {
	if (!INETD->check_system_field(data, REPEAT)) {
            rc = ob->check_ignore("tell", lower_case(data[FROM])+"@"+lower_case(data[NAME]));
            if (rc > 0) {
	        tell_object(ob, "\n" + sprintf("%-80=s",
	        capitalize(data[FROM]) + "@" + data[NAME] + " te dice: " +
	        data[DATA]) + "\n");
	        /* data[SENDER] included for compat with old-style SENDER handling. */
                if (ob->QueryInvis()) 
                    INETD->send_udp(data[NAME], ([
                        REQUEST: REPLY,
                        RECIPIENT: data[SENDER],
                        ID: data[ID],
                        DATA: sprintf("%-80=s", "Root@" + LOCAL_NAME +
                        ": No such player: " + capitalize(data[RECIPIENT]||"?")) + "\n"
                   ]) );
                else
                    INETD->send_udp(data[NAME], ([
                        REQUEST: REPLY,
                        RECIPIENT: data[SENDER],
                        ID: data[ID],
                        DATA: sprintf("%-80=s", "You tell " +
                        capitalize(data[RECIPIENT]) + "@" + LOCAL_NAME + ": " +
                        data[DATA]) + "\n"
                     ]) );
                if (!ob->QueryInvis() && (away = ob->QueryAway())) {
	             /* data[SENDER] included for compat with old-style SENDER handling. */
	             INETD->send_udp(data[NAME], ([
	                 REQUEST: REPLY,
	                 RECIPIENT: data[SENDER],
	                 ID: data[ID],
	                 DATA: sprintf("%-80=s", "Root@" + LOCAL_NAME +
	                 ": "+ capitalize(data[RECIPIENT]) + "@"+LOCAL_NAME+
		         " is away, "+away+".")+"\n"
	             ]) );
		 }
            }
            else if (!ob->QueryInvis() && (rc == 0)) {
	         /* data[SENDER] included for compat with old-style SENDER handling. */
	         INETD->send_udp(data[NAME], ([
	             REQUEST: REPLY,
	             RECIPIENT: data[SENDER],
	             ID: data[ID],
	             DATA: sprintf("%-80=s", "Root@" + LOCAL_NAME +
	             ": "+ capitalize(data[RECIPIENT]) + "@"+LOCAL_NAME+
		     " ignores you.")+"\n"
	         ]) );
	    }
	}
    }
    else
	/* data[SENDER] included for compat with old-style SENDER handling. */
	INETD->send_udp(data[NAME], ([
	    REQUEST: REPLY,
	    RECIPIENT: data[SENDER],
	    ID: data[ID],
	    DATA: sprintf("%-80=s", "Root@" + LOCAL_NAME +
	    ": No such player: " + capitalize(data[RECIPIENT]||"?")) + "\n"
	]) );
}
