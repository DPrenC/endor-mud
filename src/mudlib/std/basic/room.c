/* SIMAURIA '/std/basic/room.c'
   ============================
   [t] Theuzifan

   21-11-01 [t] Creación.
*/

#include <classes.h>
#include <nightday.h>

inherit "/std/basic/room/restrictions";
inherit "/std/basic/room/details";
inherit "/std/basic/room/exits";
inherit "/std/room/items";
inherit "/std/room/cleaning";
inherit "/std/thing/description";
inherit "/std/base";

private static mapping funcs;
private static string locate;
private static int pHealRoom;

public int _do_cmd(string str) {
	mixed func;

	func = funcs[query_verb()];
	if (stringp(func)) {
		return call_other(TO, func, str);
	}
	else if (closurep(func)) {
		return funcall(func, str);
	}
	return 0;
}


public string QueryLocate() { return locate; }
public string SetLocate(string Locate) { return locate = Locate; }
public int QueryHealRoom() { return pHealRoom;}
public int SetHealRoom(int i) { return pHealRoom=i;}

public void RemoveRoomCmd(mixed cmd) {
	if (!cmd) {
		return;
	}
	else if (pointerp(cmd)) {
		int i;

		for (i=0; i<sizeof(cmd); i++) {
			m_delete(funcs, cmd[i]);
			remove_action(cmd[i]);
		}
	}
	else if (stringp(cmd)) {
		m_delete(funcs, cmd);
		remove_action(cmd);
	}
}

public void AddRoomCmd(mixed cmd, mixed func) {
	if (!cmd) {
		return;
	}
	else if (pointerp(cmd)) {
		int i;

		for (i=0; i<sizeof(cmd); i++) {
			funcs += ([cmd[i]: func]);
		}
	}
	else if (stringp(cmd)) {
		funcs += ([cmd: func]);
	}
}

public init() {
	mixed *idx;
	int i;

	idx = m_indices(funcs);
	for (i=0; i<sizeof(idx); i++) {
		add_action("_do_cmd", idx[i]);
	}

	exits::init();
}


public void create() {
	if (object_name()[0..14] != "/std/basic/room") {
		base::replace_pgm();
	}
	base::create();
	restrictions::create();
	details::create();
	seteuid(getuid());

	funcs = ([]);
	locate = "algún sitio";
	if (!find_object(NIGHTDAY)) {
		load_object(NIGHTDAY);
	}
}

public int id(string try_id) {
	return (norm_id(try_id) == C_ROOM) || details::id(try_id);
}

public int class_id(string try_id) {
	return norm_id(try_id) == C_ROOM;
}

