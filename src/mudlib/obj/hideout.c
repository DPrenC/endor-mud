/* ENDOR-MUD'/obj/hideout.c'
   =====================
   [t] Theuzifan

   05-10-99 [t] Este es EL lugar para los escondites.
   03-05-02 [t] Muchas modificaciones para que esto rule como debe...
   09-05-02 [t] Quito la invisibilidad al personaje al realizar acciones
*/

#include <colours.h>
#include <moving.h>
#include <wizlevels.h>
#include <properties.h>
#include <skills.h>

inherit ROOM;

#define PREV_ROOM "_previous_room"

#define Me capitalize(TP->QueryName())

#define QR QueryRoom(TP)

#define valid_verb ({"=", "==", "-", "ausente", "alias", "ayuda", \
	"breve", "bug", "canal", "canales", "color", "cquien", "conectados", \
	"empunyar", "empuñar", "desempunyar", "desempuñar", "equipar", \
	"equipo", "escuchar", "estado", "fecha", "ficha", "habilidades", \
	"historico", "hora", "idea", "ignorar", "informar", "inventario", \
	"jgritar", "mensajes", "mirar", "oler", "pagina", "parar", "quien", \
	"reiniciar", "salidas", "salvar", "stty", "suicidar", \
	"telepatia", "textos", "typo", "gquien", \
	"m", "i", "tel"})

nosave private int first_time;

public object QueryRoom(object player)
{
  return (player->Query(PREV_ROOM));
}

int CheckSkill(object room, int first) {
	int ret;

	if (!room) {
		if (first) {
			write("No puedes esconderte aqui.\n");
		}
		else {
			write("Sales de tu escondite.\n");
		}
		return 0;
	}
	if (first || member(room->QueryExits(), query_verb())) {
		ret = TP->TP->UseSkill(HAB_ESCONDERSE);
	}
	else {
		ret = 1;
	}
	if (ret > 0) {
		if (first_time) {
			write("Consigues esconderte.\n");
		}
		return 1;
	}
	if (first_time) {
		write("No consigues esconderte.\n");
	}
	else {
		write("Eres tan torpe que sales de tu escondite.\n");
	}
	return 0;
}

public varargs string GetIntDesc(int nolong, mixed excl, object pl)
{

  if (QueryCloned()) {
    return "Estás " + TC_BOLD + "escondido" + TC_NORMAL +
    	", recuerda que puedes salir con " + TC_BOLD + "salir fuera" +
    	TC_NORMAL + ".\n" + QR->GetIntDesc(nolong, excl, pl);
  }
  else
    return ::GetIntDesc(1, excl, pl);
}

public mixed ExitList() {
	return QR->ExitList();
}

public string QueryIntNoise() {
	string noise;

	noise = ::QueryIntNoise();
	if (!noise) {
		noise = QR->QueryIntNoise();
	}
	return noise;
}

public varargs string Noise(string what) {
	string noise;

	noise = ::Noise(what);
	if (!noise) {
		noise = QR->Noise(what);
	}
	return noise;
}

public string QueryIntSmell() {
	string smell;

	smell = ::QueryIntSmell();
	if (!smell) {
		smell = QR->QueryIntSmell();
	}
	return smell;
}

public varargs string Smell(string what) {
	string smell;

	smell = ::Smell(what);
	if (!smell) {
		smell = QR->Smell(what);
	}
	return smell;
}

int _do_exit()
{
  int i;
  object *inv;

  if (QR) {
  	TP->move(QR, M_SILENT);
  }

  if (QueryCloned())
  {
    inv=all_inventory();
    for (i=0; i<sizeof(inv); i++)
    {
      if (inv[i]->move(QR, M_SILENT)!=ME_OK)
        inv[i]->remove();
    }
    remove();
  }

  return 1;
}

public int allow_enter(int method, mixed extra)
{
  int code, perc;
  int modif;
  object room;

  code=::allow_enter(method, extra);
  if (code!=ME_OK) return code;

  if (PO->Query(PREV_ROOM))
  {
    write("Ya estabas escondido.\n");
    return ME_NO_ENTER;
  }
  if (!CheckSkill(environment(TP), first_time)) {
  	_do_exit();
  	return ME_NO_ENTER;
  }
  return ME_OK;
}


public void notify_enter(mixed from,int method,mixed extra)
{
  object ob;

  first_time = 0;
  if (QueryCloned())
  {
    TP->SetHomeTmp(objectp(from)?object_name(from):from);
    TP->Set(PREV_ROOM, from);
  }
}

public varargs void notify_leave(mixed dest, mixed method, mixed extra)
{
  PO->Set(PREV_ROOM, 0);
}

int ValidAction(object room, string verb, string args) {
	if (member(valid_verb, verb) != -1) {
		return 1;
	}
	return (member(QR->QueryExits(), verb));
}

int cmd_all(string str)
{
  string verb;

  verb=query_verb();
  if (verb=="salir" && str=="fuera") {
    write(TC_BOLD + "Sales de tu escondite.\n" + TC_NORMAL);
    _do_exit();
    return 1;
  }

  if (!CheckSkill(QR, first_time)) {
  	_do_exit();
    	return 1;
  }

  if (ValidAction(QR, verb, str)) {
  	mapping exits;

	exits = QR->QueryPlainExits();
	if (member(exits, verb)) {
		object room;
		int err;

		room = find_object(exits[verb]);
		if (!room) {
			err = catch(room = load_object(exits[verb]));
			if (!err && !room) { // caso especial y muy raro
				call_other(exits[verb], "???");
				room = find_object(exits[verb]);
			}
		}
		if (!room) {
			return notify_fail("No puedes ir en esa dirección, hay un fallo en la habitación destino.\n" +
				"Contacta con un Wizard.\n"),0;
		}
		TP->Set(PREV_ROOM, room);
		tell_object(TP, GetIntDesc(TP->QueryBrief()));
		return 1;
	}
	exits = QR->QueryExitsDest();
	if (member(exits, verb)) {
		if (objectp(exits[verb])) {
			TP->Set(PREV_ROOM, exits[verb]);
			tell_object(TP, GetIntDesc(TP->QueryBrief()));
			return 1;
		}
		return notify_fail("No puedes moverte en esa dirección estando oculto.\n"),0;
	}
	return 0;
  }
  else {
  	write(TC_BOLD + "No puedes hacer eso mientras estés escondido.\n" + TC_NORMAL);
 	return 1;
  }

  return 1;
}

public void create()
{
  ::create();
  SetIntLong("Esta es la habitación hideout maestra.\n");
  SetIntShort("la habitación hideout maestra");
}

public void create_clone()
{
  ::create_clone();
  first_time = 1;
  SetIntLong("");
  SetIntShort("");
}

init()
{
  ::init();
  add_action("cmd_all", "", 1);
}

