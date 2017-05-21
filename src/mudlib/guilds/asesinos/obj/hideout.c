/* SIMAURIA '/obj/hideout.c'
   =====================
   [t] Theuzifan

   05-10-99 [t] Este es EL lugar para los escondites.
*/
inherit ROOM;

#include <moving.h>
#include <wizlevels.h>
#include <properties.h>

#define HIDE_FLAG "HideSKPerc"
#define PREV_ROOM "_previous_room"
#define OLD_BRIEF "_old_brief"

#define Me capitalize(TP->QueryName())

#define QR QueryRoom(TP)
//#define USE_SKILL
//#define REMOVE_CASCADE

public QueryRoom(object player)
{
  return (player->Query(PREV_ROOM));
}

public varargs string GetIntDesc(int nolong, mixed excl, object pl)
{
  if (QueryCloned())
    return W("Estás escondido en "+lower_case(QR->QueryIntShort())+".\nRecuerda que puedes salir con 'salir fuera'.\n"+::GetIntDesc(1, excl, pl));
  else
    return ::GetIntDesc(1, excl, pl);
}

int cmd_salir()
{
  int i;
  object *inv;

  TP->move(QR, M_SILENT);

  tell_object(TP, "Sales de tu escondite.\n");

  if (QueryCloned())
  {
    inv=all_inventory();
    for (i=0; i<sizeof(inv); i++)
    {
      if (inv[i]->move(QR, M_SILENT)!=ME_OK)
        inv[i]->remove();
    }
  }
  remove();

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

  if (QueryCloned()) return ME_OK;

#ifdef USE_SKILL
  room=environment(PO);
  modif=-(room->QueryLight()+room->QueryIntLight()-50);
  if (modif<-10) modif=-10;
  if (modif>10) modif=10;
  perc=TP->UseSkill("esconderse", modif);
  if (perc<=0)
  {
    write("No consigues esconderte. No eres lo bastante hábil.\n");
    return ME_NO_ENTER;
  }
  PO->Set(HIDE_FLAG, perc);
#endif

  write("Consigues esconderte.\n");
  return ME_OK;
}


public void notify_enter(mixed from,int method,mixed extra)
{
  object ob;

  if (!QueryCloned())
  {
    ob=clone_object("/obj/hideout");
    PO->move(ob, M_SILENT);
    TP->Set(OLD_BRIEF, TP->QueryBrief());
    TP->SetBrief(1);
    TP->SetHomeTmp(objectp(from)?object_name(from):from);
  }
  TP->Set(PREV_ROOM, from);
}

public varargs void notify_leave(mixed dest, mixed method, mixed extra)
{
  PO->SetBrief(PO->Query(OLD_BRIEF));
  PO->Set(OLD_BRIEF, 0);
  PO->Set(HIDE_FLAG, 0);
  PO->Set(PREV_ROOM, 0);
}

int cmd_mirar(string str)
{
  if (str=="fuera")
  {
#ifdef USE_SKILL
    if (TP->UseSkill("esconderse")<=0)
    {
      write("¡Eres tan torpe que al mirar fuera sales de tu escondite!\n");
      return cmd_salir();
    }
#endif
    write("Asomas la cabeza y miras...\n");
    write(QR->GetIntDesc(0, ({}), TP));
    return 1;
  }
  return 0;
}

#define do_exit ({"matar", "magia", "mostrar", "ponerse", "quitarse",\
	"empuñar", "desempuñar", "empunyar", "desempunyar", "magia",\
	"convocar", "corteza", "calmar", "sangre", "transmutacion",\
        "transmutación","acuchillar","cortar"})

int cmd_all(string str)
{
  string verb;
  int invis;

  verb=query_verb();
  if (verb=="salir" && str=="fuera")
    return cmd_salir();

  if (verb=="m" || verb=="mirar")
    return cmd_mirar(str);

#ifdef USE_SKILL
  if (TP->UseSkill("esconderse")<=0)
  {
    write("¡Eres tan torpe que sales de tu escondite!\n");
    return cmd_salir();
  }
#endif

  if (member(do_exit, verb)!=-1)
  {
    invis=TP->QueryInvis();
    if (!invis) TP->SetInvis(1);
  }

  TP->move(QR, M_SILENT);

//  write("Sales de las sombras para '"+verb+"'.\n");
  command(verb+(str?(" "+str):""), TP);

  if (member(do_exit, verb)!=-1)
  {
    return cmd_salir();
  }

  TP->move(TO, M_SILENT);
  if (invis<10)
    TP->SetInvis(invis);

  return 1;
}


init()
{
  ::init();
  add_action("cmd_all", "", 1);
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
  SetIntLong("");
  SetIntShort("");
}

#ifdef REMOVE_CASCADE
public int remove()
{
  int i;
  object *w;

  if (QueryCloned())
  {
    w=m_indices(who);

    for (i=0; i<sizeof(w); i++)
    {
      write("¡Woops! Tu escondite ha sido destruído.\n");
      w[i]->move(who[w[i], HAB], M_SILENT);
      w[i]->Set(HIDE_FLAG, 0);
    }
    return ::remove();
  }
  else
  {
    //borrado en cascada de todos los objetos hijos...
    w=clones("/obj/hideout");
    for (i=0; i<sizeof(w); i++)
      w[i]->remove();
    return ::remove();
  }
  return ::remove();
}
#endif
