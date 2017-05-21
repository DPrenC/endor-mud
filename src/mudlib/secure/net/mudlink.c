/*
 * secure/net/mudlink.c
 *
 * (C) Copyright 1993 Nightfall
 *
 * Deepthought, 18-Jan-93
 *
 * This object may be used with or without modifications as long
 * as credit to its origin is given.
 * 
 * This is a special player object for running MUDLINK connections
 * to other muds, and to be used for Dictionary lookup.
 *
 * MUDLINK is a intermud protocol developed originally for TinyMush
 * type muds by howard@pa.itd.com.
 *
 * This LPmud implementation is written for Nightfall, which runs with
 * Amylaar's gamedriver and our own custom mudlib. It is probably 
 * usable with other mudlibs after small changes. The mudlib needs
 * the capability to start this special player object from the
 * login object.
 *
 * /secure/config.h contains general mud parameters.
 * It provides some query-type functions typically present also in
 * 'normal' player objects.
 *
 */
#include "/secure/config.h"

#define NOPROMPT set_prompt("")


/* for debugging purpose */
query_wiz_level() { return 0; }
query_level() { return 0; }
QueryShort() { 
  return "Mudlink the Mud Connector (deaf)"; 
}
QueryName() { return "MUDLINK"; }
QueryRealName() { return "mudlink"; }
QueryPlayer() { return 1; }

query_prevent_shadow() { return 1; }

//move(dahin,wie,wasnoch) { return 0; }

/*
 * This is the function that gets called by /secure/login after name and
 * password is verified and this object is loaded.
 */
start_player() {
    //log_file("MUDLINK","Restarting the MUDLINK player\n");
    set_living_name("mudlink");
    enable_commands();
    NOPROMPT;

    add_action("junk","",1);
    add_action("pemit","@pemit");
    add_action("mudwho","@mudwho");
    add_action("pmud","@pmud");
    add_action("remove","@quit");
    return 1;
}

junk() { NOPROMPT; return 1; }

#define BAD_COMMAND { notify_fail("Huh?\n"); return 0; } 

/* 
 * The @pemit <player>=<message> is used to send a message to a
 * local player by the info-serv. We do this by using tell_object(player).
 */
static pemit(str) { 
    string a, b, a1, a2;
    object ob;

    NOPROMPT;
    if (!str || str=="")
	BAD_COMMAND;
    if (sscanf(str,"%s=%s",a,b) != 2)
	BAD_COMMAND;
    a = (explode(a," "))[0];
    if (ob = find_object(lower_case(a)))
	tell_object(ob,b+"\n");
    return 1;
}


/*
 * where() is a function which returns the physical country from
 * which the player is logged in. The simul-efun country() is
 * used to return a best guess of the country name from the
 * ip name (usually the top level domain is quite descriptive).
 */
where(ob) { return country(lower_case(query_ip_name(ob))); }

/*
 * We are called from the info-serv by the command @mudwho and
 * should return a list of players. Edit /secure/net/RWHO_BANNER
 * for the top lines to be sent before the player list.
 */
mudwho(str) {
    string a, b;
    int i, nu;
    string *lines;
    object *list;

    NOPROMPT;
    if (!str || str == "")
	BAD_COMMAND;
    if (sscanf(str,"%s=%s",a,b) != 2)
	BAD_COMMAND;
    str = a+"@"+b;
    lines = explode(read_file("/secure/net/RWHO_BANNER"),"\n");
    for (i = 0; i < sizeof(lines); i++) {
	write("@inwho "+str+"="+lines[i]+"\n");
    }
    list = users();
    nu = 0;
    for (i = 0; i < sizeof(list); i++) {
	string sh;
	sh = list[i]->QueryShort();
	if (sh) {
	    write("@inwho "+str+"="+capitalize(sh)+" [" +where(list[i])+"]\n");
	    nu++;
	}
    }
    if (nu) 
	write("@inwho "+str+"=*** There are "+nu+" players connected.\n");
    else
	write("@inwho "+str+"=*** There are no players connected.\n");
    return 1;
}
    
/*
 * @pmud is called from the info-serv to make us deliver a 'page',
 * in LP terms called tell, to be delivered to a player.
 */
#define PPOSE "poses:"
pmud(str) {
    string lu, ru, rm, pcmd, what;
    string w1, w2;
    object ob;

    NOPROMPT;
    if (!str || str == "")
	BAD_COMMAND;
    if (sscanf(str,"%s=%s@%s %s %s", lu, ru, rm, pcmd, what) != 5)
	BAD_COMMAND;
    if (ob = find_object(lower_case(lu))) {
	if (pcmd == PPOSE) {
	    sscanf(what, "%s %s", w1, w2);
	    tell_object(ob,ru+"@"+rm+" "+w2+"\n");
	}
	else {
	    tell_object(ob,ru+"@"+rm+" tells you: "+what+"\n");
	}
    } else
    	tell_object(this_object(), "rpage Mudlink@"+ru+"@"+rm+"=Player "+capitalize(lu)+" currently not logged in.\n");
    return 1;
}
    

/* debugging.. */
remove() {
    write("MUDLINK selfdestructing...\n");
    destruct(this_object());
    return 1;
}
