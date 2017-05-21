/*
DESCRIPCION  : un cofre (base de objetos contenedores con cerradura)
               Es un simple cofre en el que se pueden meter y sacar cosas,
			   se puede abrir, cerrar, con o sin llave, etc...
FICHERO      : /obj/chest.c
MODIFICACION :
  05-10-92 [m] Mateese lo crea.
  11-12-96 [g] Guybrush traduce las frases que los jugadores veran y hace
               algunas anotaciones.
  11-03-00 [a] comentadas las llamadas a strip_article()

POR HACER:
  - Encontrar donde esta la funcion strip_article() para poder modificarla
  - Establecer un nuevo control de cerrado/a y abierto/a para las cosas por
    su genero
*/

#include <properties.h>
#include <lock.h>
#include <moving.h>
#include <search.h>

inherit "/std/room/items"; // reset() is here
inherit "/std/lock";
inherit "/std/container";

/*-------------------------------------------------------------------------*/

public string InvShort (string what) {
  return ModifyInvShort(container::InvShort(what));
}

public string Long (string what) {
  return ModifyLong(container::Long(what));
}

public string IntLong (string what) {
  return ModifyLong(container::IntLong(what));
}

/*-------------------------------------------------------------------------
** Inicializanos.
-------------------------------------------------------------------------*/

create () {
  container::create();
  SetShort("un cofre");
  SetIntShort("dentro de un cofre");
  SetLong("Esto es un cofre ordinario.\n");
  SetIntLong("Estas en el interior de un cofre ordinario.\n");
  SetPreContent("Contiene:\n");
  SetValue(200);
  SetWeight(8000);
  SetMaxIntWeight(16000);
  AddId("cofre");
  SetLockState(LOCK_CLOSED);
}

/*-------------------------------------------------------------------------
** Si el cofre esta cerrado, coger cosas del interior no es posible.
** En ese caso, devuelve ME_NO_LEAVE, si no ME_NO_PREVENT.
-------------------------------------------------------------------------*/

public int prevent_leave (mixed dest, int method, mixed extra) {
  if (!TP || TP != PO || LSTATE_GHOST != TP->Query(P_LSTATE)) {
    if (QueryLockState() != LOCK_OPEN) {
      if (TP || TI)
        if(TO->QueryGender()==2)
		  write ("La "+strip_article(QueryShort())+" esta cerrada.\n");
        else
		  write ("El "+strip_article(QueryShort())+" esta cerrado.\n");
      return ME_NO_LEAVE;
    }
  }
  return container::prevent_leave(dest, method, extra);
}

/*-------------------------------------------------------------------------
** Si el cofre esta cerrado, poner cosas dentro es imposible.
** En ese caso, devuelve ME_NO_ENTER.
** Si esta abierto, puede estar lleno. Pregunta /std/container para eso
-------------------------------------------------------------------------*/

public int allow_enter (int method, mixed extra) {
  if (!TP || TP != PO || LSTATE_GHOST != TP->Query(P_LSTATE)) {
    if (QueryLockState() != LOCK_OPEN) {
      if (TP || TI)
        if(TO->QueryGender()==2)
		  write ("La "+strip_article(QueryShort())+" esta cerrada.\n");
        else
		  write ("El "+strip_article(QueryShort())+" esta cerrado.\n");
      return ME_NO_ENTER;
    }
  }
  return container::allow_enter (method, extra);
}

/*-------------------------------------------------------------------------
** Si esta cerrado, el jugador no puede encontrar o ver nada a traves de
** su material (a menos de que sea un fantasma o el cofre sea transparente).
--------------------------------------------------------------------------*/

public varargs object *Locate (mixed item, int mode) {
  if (QueryLockState() != LOCK_OPEN
  &&  member(deep_inventory(TO), TP) == -1
  &&  LSTATE_GHOST != TP->Query(P_LSTATE)
     )
    return (mode & SEARCH_OBJECT) ? 0 : ({});
  return container::Locate (item, mode);
}

/*-------------------------------------------------------------------------
** El contenido es siempre visible al interior, pero no al exterior... ya
** sabes, a menos que no este cerrado o sea transparente
-------------------------------------------------------------------------*/

public varargs string Content (string what, mixed exclude) {
  if (member(deep_inventory(TO), TP) == -1
   && LSTATE_GHOST != TP->Query(P_LSTATE)
   && QueryLockState() != LOCK_OPEN
     )
    return "";
  return container::Content(what, exclude);
}

/*************************************************************************/
