/* /std/room/basicexits.c
   ======================
   [t] Theuzifan

   16-01-01 [t] Creación.
*/


#include <moving.h>
#include <colours.h>
#include <messages.h>

mapping exits = ([]);

#define EXIT_DEST	0
#define EXIT_OBJ	1
#define EXIT_DOOR	2
#define EXIT_HIDDEN	3
#define EXIT_CHECK	4
#define EXIT_DEF	({ "norte", "noroeste", "oeste", "suroeste", "sur", "sureste", "este", "noreste", "arriba", "abajo","entrar", "salir" })
#define DOOR_NAME	0
#define DOOR_OPENED	1
#define DOOR_DESC	2
#define DOOR_KEY	3

public varargs void AddDetail(mixed det, mixed desc, string exa);
public void RemoveDetail(mixed det);

public mapping QueryExits() {
	return exits;
}

public mapping SetExits(mapping p) {
	return exits = p;
}

static void _correct_status(mixed *door, string dest) {
	object other_room;
	int error;

	error = catch(other_room = load_object(dest));
	if (error) {
		return;
	}
	if (other_room) {
		mapping other_exits;
		mixed *paths;
		int i;

		other_exits = other_room->QueryExits();
		paths = m_indices(other_exits);
		for (i=0; i<sizeof(paths); i++) {
			string fname;

			fname = other_exits[paths[i]];
			if (fname[<2..] == ".c") {
				fname = fname[..<3];
			}
			if (fname == object_name()) {
				if (other_exits[paths[i], EXIT_DOOR]) {
					other_exits[paths[i], EXIT_DOOR][DOOR_OPENED] = door[DOOR_OPENED];
					tell_room(other_room, ({ MSG_SEE, "Ves una puerta abrirse. Tienes un nuevo camino para explorar.\n" }));
				}
				break;
			}
		}
	}
}

static int _opendoor(string name, mixed *door, string dest) {
	if (door[DOOR_OPENED]) {
		write("Ya está abierta.\n");
		return 1;
	}
	if (door[DOOR_KEY]) {
		object key;

		key = present(door[DOOR_KEY], TP);
		if (key) {
			write("Abres la puerta usando " + key->QueryShort() + ".\n");
			door[DOOR_OPENED] = 1;
		}
		else {
			write("No tienes la llave adecuada para la cerradura.\n");
			return 1;
		}
	}
	else {
		door[DOOR_OPENED] = 1;
		write("Abres la puerta.\n");
	}

	_correct_status(door, dest);

	return 1;
}

static int _closedoor(string name, mixed *door, string dest) {
	if (!door[DOOR_OPENED]) {
		write("Ya está cerrada.\n");
		return 1;
	}
	door[DOOR_OPENED] = 0;
	write("Cierras la puerta.\n");

	_correct_status(door, dest);

	return 1;
}

int cmd_door(string arg) {
	mixed *idx;
	mixed *door;
	int i;

	if (!arg) {
		write("¿" + capitalize(query_verb()) + " qué puerta?\n");
		return 1;
	}
	idx = m_indices(exits);

	for (i=0; i<sizeof(idx); i++) {
		door = exits[idx[i], EXIT_DOOR];
		if (!door) {
			continue;
		}
		if (exits[idx[i], EXIT_HIDDEN]) {
			continue;
		}
		if (pointerp(door[DOOR_NAME])) {
			int j;
			string *names;

			names = door[DOOR_NAME];
			for (j=0; j<sizeof(names); j++) {
				if (names[j] == arg || arg == idx[i]) {
					if (query_verb() == "abrir") {
						return _opendoor(arg, door, exits[idx[i], EXIT_DEST]);
					}
					return _closedoor(arg, door, exits[idx[i], EXIT_DEST]);
				}
			}
		}
		else {
			if (door[DOOR_NAME] == arg || arg == idx[i]) {
				if (query_verb() == "abrir") {
					return _opendoor(arg, door, exits[idx[i], EXIT_DEST]);
				}
				return _closedoor(arg, door, exits[idx[i], EXIT_DEST]);
			}
		}
	}
	write("No encuentras " + arg + " para " + query_verb() + ".\n");
	return 1;
}

public varargs int AddDoor(string dir, mixed name, string desc, string key) {
	if (!dir) {
		return 0;
	}
	if (!member(exits, dir)) {
		return 0;
	}
	if (!name) name = "puerta";
	if (!desc) desc = "Es una simple puerta de madera";
	exits[dir, EXIT_DOOR] = ({name, 0, desc, key});
	AddDetail(name, desc + ".\n");

	return 1;
}

public int UseExit(string verb, string arg, int method) {
	mixed dest;
	mixed *door;

	if (!member(exits, query_verb())) {
		if (member(EXIT_DEF, query_verb())) {
			write("No puedes ir allí.\n" );
			return 1;
		}
		return 0;
	}
	dest = exits[verb];
	door = exits[verb, EXIT_DOOR];
	if (door) {
		if (!door[DOOR_OPENED]) {
			write("No puedes ir allí.\n" );
			return 1;
		}
	}
	if (exits[verb, EXIT_HIDDEN]) {
		write("No puedes ir allí.\n" );
	}
	else if (stringp(dest)) {
		if (TP->move(dest, method, verb) != ME_OK) {
			write("No puedes ir allí.\n" );
		}
	}
	else if (closurep(dest)) {
		return ( int )funcall( dest, arg );
	}
	return 1;
}

public int exitfunc(string arg) {
	return UseExit(query_verb(), arg, M_GO);
}

public void AddExit(mixed to, mixed dest) {
	if (!to || !dest) {
		return;
	}
	/* expando el 'to' para quitarle luego complejidad a las funciones de busqueda */
	if (pointerp(to)) {
		int i;
		for (i=0; i<sizeof(to); i++) {
			exits += ([to[i]:dest;0;0;0;0]);
		}
	}
	else {
		exits += ([to:dest;0;0;0;0]);
	}
}

public int HideExit(mixed to, int state) {
	if (pointerp(to)) {
		int i;

		for (i=0; i<sizeof(to); i++) {
			if (member(exits, to[i])) {
				exits[to[i], EXIT_HIDDEN] = state;
			}
		}
	}
	else if (stringp(to)) {
		if (!member(exits, to)) {
			return 0;
		}
		exits[to, EXIT_HIDDEN] = state;
	}
	return state;
}

public void RemoveExit(mixed to) {
	if (pointerp(to)) {
		int i;

		for (i=0; i<sizeof(to); i++) {
			m_delete(exits, to[i]);
		}
	}
	else {
		m_delete(exits, to);
	}
}

public void RemoveDoor(string to) {
	if (!member(exits, to)) {
		return;
	}
	RemoveDetail(exits[to, EXIT_DOOR][DOOR_NAME]);
	exits[to, EXIT_DOOR] = 0;

}

static int _can_view(string exit, mixed data) {
	if (data[EXIT_HIDDEN]) return 0;
	if (data[EXIT_DOOR]) {
		return data[EXIT_DOOR][DOOR_OPENED];
	}
	return 1;
}

static mixed *_get_doors(int code) {
	mixed *doors = ({});
	mixed *idx;
	int i;

	idx = m_indices(exits);
	for (i=0; i<sizeof(idx); i++) {
		if (exits[idx[i], EXIT_HIDDEN]) {
			continue;
		}
		if (exits[idx[i], EXIT_DOOR]) {
				mixed *door = exits[idx[i], EXIT_DOOR];
				if (code != door[DOOR_OPENED]) {
					continue;
				}
				if (pointerp(door[DOOR_NAME])) {
				doors += ({door[DOOR_NAME][0]});
			}
			else {
				doors += ({door[DOOR_NAME]});
			}
		}
	}
	return doors;
}

static string _itoa(int num) {
	if (num == 1) {
		return "una";
	}
	return itoa(num);
}

public varargs string Exits(int brief, object player) {
	int num, opendnum;
	mixed *idx;
	string str;
	string cstart, cend, cbold;
	int total;

	idx = m_indices(filter(exits, SF(_can_view)));

	num = sizeof(idx);
	total = num;

	if (exits == 0 || exits == ([])) {
		return "No hay salidas obvias.\n";
	}

	str = "";
	switch (player->QueryTTY()) {
		case "ansi": 	cstart = TC_BOLD + player->RetColor(player->QueryColor("salidas"));
				cend = TC_NORMAL + TC_CNORMAL;
				cbold = TC_BOLD;
				break;
		case "vt100":	cbold = TC_BOLD;
				cstart = cbold;
				cend = TC_NORMAL;
				break;
		default: 	cbold = "";
				cstart = "";
				cend = "";
	}
	if (brief) {

		str += cstart + implode(idx[0..<2], cend + "," + cstart) + idx[<1] + cend;
	}
	else {
		if (num > 0) {
			str = "Hay " + cbold + _itoa(num) + cend + " salida" + (num>1?"s":"") + ": ";
			str += cstart + implode(idx[0..<2],cend + ", " + cstart) + (sizeof(idx[0..<2])?(cend + " y " + cstart):"") + idx[<1] + cend + ".\n";
		}
		idx = _get_doors(1);
		num = sizeof(idx);
		total += num;
		if (num > 0) {
			str += "Hay " + cbold + _itoa(num) + cend + " puerta" + (num>1?"s":"") + " abierta" + (num>1?"s":"") + ": ";
			str += cstart + implode(idx[0..<2], cend + ", " + cstart) + (sizeof(idx[0..<2])?(cend + " y " + cstart):"") + idx[<1] + cend + ".\n";
		}
		idx = _get_doors(0);
		num = sizeof(idx);
		total += num;
		if (num > 0) {
			str += "Hay " + cbold + _itoa(num) + cend + " puerta" + (num>1?"s":"") + " cerrada" + (num>1?"s":"") + ": ";
			str += cstart + implode(idx[0..<2],cend + ", " + cstart) + (sizeof(idx[0..<2])?(cend + " y " + cstart):"") + idx[<1] + cend + ".\n";
		}
	}
	if (!total) {
		return "No hay salidas obvias.\n";
	}
	return str;
}

init() {
	int i;
	mixed *idx;

	for (i=0; i<sizeof(EXIT_DEF); i++) {
		add_action("exitfunc", EXIT_DEF[i]);
	}
	idx = m_indices(exits);
	for (i=0; i<sizeof(idx); i++) {
		add_action("exitfunc", idx[i]);
	}
	add_action("cmd_door", "abrir");
	add_action("cmd_door", "cerrar");
}
