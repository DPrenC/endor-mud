/* SIMAURIA '/std/room/cleaning.c'
   ===============================
   [w] Woo@simauria
   [h] Nyh@simauria

   ??-??-?? [w] Revisado.
   03-11-04 [h] Añado el log para ver por que no limpia correctamente.
*/

#include <properties.h>
#include <rooms.h>

#undef ENV
#define ENV	   environment

//[Nyh] Con define y todo
// #define LOG_CLEAN_UP

//---------------------------------------------------------------------------
// Cleanup handling:
//
// ref < 0: El environment nos pide que nos limpiemos, o algo asi...
// ref = 0: we are a clone, or a blueprint with replaced program.
// ref = 1: we are a swapped and/or unreferenced blueprint.
// ref > 1: we are a non-swapped blueprint in use.
//
// If the room has an environment() and is a cloned room, it will return 0
// and thus never clean up.
// The room won't selfdestruct if there are items which need the room
// for refresh (like REFRESH_HOME). Items which can be recreated by the
// room are ignored.


public int clean_up(int ref) {
  mixed *items, rc;
  object *alien, *objs, item, *own;
  int s, i, refr;
  mapping list_exits_door;


  //[Nyh] Añado el log
#ifdef LOG_CLEAN_UP
  log_file("/CLEAN_UP", sprintf("--------------------------------------------------------------------------------\n"
				"\n"
				"--------------------------------------------------------------------------------\n"
				"[%O] Llamada a %O -> clean_up ( ref = %O )\n",ctime(time()),TO,ref) );
#endif

#ifdef LOG_CLEAN_UP
  log_file("/CLEAN_UP", sprintf("\t( (call_resolved(&rc, TO, \"Query\", P_CLEAN_UP) = %O) && (!rc = %O) ) = %O\n",call_resolved(&rc, TO, "Query", P_CLEAN_UP),!rc,call_resolved(&rc, TO, "Query", P_CLEAN_UP) && !rc) );
#endif
  // If the object doesn't want to be cleaned up, don't do it.
  if (call_resolved(&rc, TO, "Query", P_CLEAN_UP) && !rc)
    return 1;

#ifdef LOG_CLEAN_UP
  log_file("/CLEAN_UP", sprintf("\t( (ENV() = %O) && (clonep() = %O) ) = %O\n",ENV(),clonep(),ENV() && clonep()) );
#endif
  // Objects with environment do not clean up on their own.
  if (ENV() && clonep())
    return 0;

  // Check if there are room items which need the room to exist.

  own = ({});
  items = (mixed *) TO->QueryItems();
#ifdef LOG_CLEAN_UP
  log_file("/CLEAN_UP", sprintf("\t items = %O\n",items) );
#endif
  for (s = sizeof(items); s--; ) {
    refr = items[s][RITEM_REFRESH];
    i = RITEM_OBJECT;
    if (mappingp(items[s][i]) || pointerp(items[s][i])) i++;
    if (refr & REFRESH_FUNC) i++;
    objs = items[s][i..] - ({ 0 });
    for (i = sizeof(objs); i--; ) {
      // Moving other items might have destructed this one.
      if (!(item = objs[i])) continue;

      if (!objectp(item)) raise_error(sprintf("Item is no object: %O\n", item));

      // If the item exists somewhere else and needs noticeable actions
      // upon reset, don't clean up for now.
      // One might discuss if REFRESH_DESTRUCT counts for this, too.
      if ( (refr & ( REFRESH_DESTRUCT|REFRESH_RESET|REFRESH_PROPS ))
	   && (ENV(item) != TO)
	 )
	return 1;

      // If the item exits somewhere else, and demands home-moving on
      // reset, simulate it. If the move fails, it fails - mostly for
      // bug reasons.
      if ( (refr & REFRESH_MOVE_HOME) && (ENV(item) != TO) ) item->move(TO);

      // The item belongs to this room and is here - note that.
      if ( item && (ENV(item) == TO) ) own += ({ item });
    }
  }

  i = sizeof(alien = all_inventory() - own);

#ifdef LOG_CLEAN_UP
  log_file("/CLEAN_UP", sprintf("\t own = %O\n",own) );
#endif
#ifdef LOG_CLEAN_UP
  log_file("/CLEAN_UP", sprintf("\t alien = %O\n",alien) );
#endif

  // Compute the inventory which can't be reconstructed by the room
  for (;i--;) alien[i]->clean_up(-1);

#ifdef LOG_CLEAN_UP
  log_file("/CLEAN_UP", sprintf("\t alien cleaned = %O\n",alien) );
#endif

  // If there aren't any alien objects left and we have come so
  // far, then destruct all our items and selfdestruct, because
  // the items will be recreated when we are.
  if (!sizeof(alien - ({ 0 }))) {
    call_other(own, "remove");
    TO->remove();
  }

#ifdef LOG_CLEAN_UP
  log_file("/CLEAN_UP", sprintf("\t TO && 1 = %O\n",TO && 1) );
#endif

  return TO && 1;
}

// Dummy-remove for the blueprint
public varargs int remove(int arg) {
  object *inv;
  int i, rc;
  mixed tmp;
  mapping list_exits_door;

  if (!TO)
    return 0;
  if (!environment(TO) && arg == -1)
  {
    inv = all_inventory(TO);
    for (i = 0; i < sizeof(inv); i++)
    {
      if (query_once_interactive(inv[i]))
	continue;
      catch(rc = call_resolved(&tmp, inv[i], "remove", -1));
      if (inv[i] && rc)
	return 0;
    }
  }


  // comprobamos si hay puertas asociadas a alguna salida, y en caso de que la habitación destino
  // tampoco exista, borramos el objeto
  // así mismo, traspasamos las posibles propiedades closures de este lado que se va a borrar, al otro lado, si existe
  if ((list_exits_door = TO->ListExitsDoor()) && mappingp(list_exits_door))
  {
    foreach(string salida, mixed dest, object door : list_exits_door)
    {
      mapping p_closures;
      if (!find_object(dest)) door->remove();
      else if (   door && (p_closures = door->QueryDoorClosures(door->QueryDoorOtherSide(TO)))
               && sizeof(p_closures))
      {
          door->SetProperties(p_closures);
      }
    }
  }
#ifdef LOG_CLEAN_UP
  else log_file("CLEAN_UP" , ctime() + ". " + object_name(TO) + " --> ListExitsDoor vale 0.\n");
#endif


destruct(TO);
  return 1;
}
