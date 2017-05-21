#include <udp.h>

#ifdef ZEBEDEE
#include <defs.h>
#endif

#ifndef DATE
#define DATE	ctime(time())[4..15]
#endif

void udp_reply(mapping data) {
    string err;
    object ob;

    if (INETD->check_system_field(data, TIME_OUT)) {
	if (data[SENDER]) {
	    if (stringp(data[SENDER]) && (ob = find_object(lower_case(data[SENDER]))))
	        efun::tell_object(ob, "\ninetd: " + capitalize(data[REQUEST]) +
		" request to " + (data[RECIPIENT] ?
		capitalize(data[RECIPIENT]) + "@" + data[NAME] :
		data[NAME]) + " timed out.\n");
	    else if (objectp(ob = data[SENDER]) ||
	    (ob = find_object(data[SENDER])))
		ob->udp_reply(data);
	}
	return;
    }
    if (data[RECIPIENT]) {
	/* If recipient is a player name, pass the message to them. */
	if (stringp(data[RECIPIENT]) &&
           (ob = find_object(lower_case(data[RECIPIENT]))))
	    efun::tell_object(ob, "\n" + data[DATA]);
	/* Otherwise send it to udp_reply() in the recipient. */
	else if (objectp(ob) || (ob = find_object(data[RECIPIENT])))
	    ob->udp_reply(data);
	return;
    }
    /* Ignore replies with no recipient. */
    return;
#if 0
    switch(data[REQUEST]) {
	case "ping":
	    /* Ignore system ping replies. */
	    return;
	default:
	    /* Log replies to the system. (ie. No RECIPIENT) */
	    if (data[DATA])
		log_file(INETD_LOG_FILE, DATE + ": Reply from " + data[NAME] +
		"\n" + data[DATA] + "\n");
	    return;
    }
#endif
}
