/**
 * ENDOR-MUD'/std/room.c'
 */

#include <colours.h>
#include <nightday.h>
#include <classes.h>
#define <bandos.h>
inherit "/std/room/restrictions";
inherit "/std/room/description";
inherit "/std/room/exits";         // init()
inherit "/std/room/details";       // id()
inherit "/std/room/items";         // reset()
inherit "/std/room/cleaning";
inherit "/std/base";

//----------------------------------------------------------------------------
private static string pLocate;
private static int pHealRoom;
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
public string QueryLocate()         { return pLocate; }
public string SetLocate(string str) { return pLocate = str; }

public int QueryHealRoom()          { return pHealRoom; }
public int SetHealRoom(int i)       { return pHealRoom = i; }
//----------------------------------------------------------------------------

// Función para registrar la habitacion
private int _register_me() {
    string *donde, dominio;

    if (sizeof(donde=explode(object_name(),"/"))<3) return 0;

    if (donde[1] == "d")
    {
        dominio=donde[2];
        "/obj/lib/register"->Register(TO, "/log/register/dominios/"+dominio+"/habitaciones.o");
        return 1;
    }
    return 0;
}

/* Establece los colores al ver las salidas */
public varargs string Exits(int brief, object pl) {
  string ret, vis, ocu;

  ret = ::Exits(brief, pl);

  if(sscanf(ret,"%s][%s", vis, ocu)==2)
    return TC_EXIT + vis + TC_NORMAL +"]["+ TC_EXIT + ocu + TC_NORMAL;
  return TC_EXIT + ret + TC_NORMAL;
}

public int id (string try_id) {
  return (norm_id(try_id) == C_ROOM) || details::id(try_id);
}

public int class_id (string try_id) {
  return norm_id(try_id) == C_ROOM;
}

public varargs string Long(string what)  {
  mixed rc;

  rc = what && details::GetDetail(what);
  return (pointerp(rc) ? rc[0] : rc) || "";
}

public varargs string ExaLong(string what)  {
  mixed rc;

  rc = what && details::GetDetail(what);
  return pointerp(rc) ? rc[1] : "No ves nada de especial.\n"+rc;
}

public varargs string Noise(string what) {
  return what && details::GetNoise(what) || "";
}

public varargs string Smell(string what) {
  return what && details::GetSmell(what) || "";
}

public varargs string Read(string what) {
  return what && details::GetReadMsg(what) || "";
}

public void create() {
  if (program_name() != __FILE__)
  {
    base::replace_pgm();
  }
  "*"::create();
  seteuid(getuid());
  //_register_me(); // lo desactivo a ver que ocurre.
  if (!find_object(NIGHTDAY)) load_object(NIGHTDAY);
  SetMaxIntSize(1000); // para que quepan más cosas en las habitaciones.

  SetPreContent("Ves:\n");
}
