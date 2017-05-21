/* SIMAURIA '/std/room/items.c'
   ============================
   [w] Woo@simauria
   [g] Guybrush@simauria
   [t] Theuzifan

   16-02-97 [w] Comprobada, no hace falta traducir nada mas.
   05/12/98 [g] Quita lock.h y algunas cosillas referentes a ello.
   08-02-99 [t] Log castellanizado.
   23-09-99 [w] Quitada la función aloha y sus llamadas. ¿soluciónará
                el problema de cloneamiento múltiple de PNJs? quien sabe.
*/

#pragma strong_types

#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <money.h>
#include <door.h>

#undef ENV
#define ENV        environment

// Undefine this to expunge REFRESH_NONE items from the P_ITEMS array.
// Saves memory, but makes life (not only debugging) more difficult.
#define KEEP_REFR_NONE

//--- global variables ------------------------------------------------------

private static mixed *Pitems, Pmoney;

//--- Money handling ---------------------------------------------------

public int RefreshMoney ()
{
  int itsvalue;
  mixed rc;

  if (!Pmoney)
    return 0;
  if (intp(Pmoney))
    itsvalue = Pmoney;
  else
    itsvalue = MONEY_DEMON->QueryMoneyValue(Pmoney);
  if (MONEY_LIB->QuerySomeonesValue(TO) >= itsvalue)
    return 0;
  return MONEY_LIB->SetMoney(TO, Pmoney);
}

//--- query and set information ----------------------------------------

public mixed *QueryItems()       { return Pitems; }
public mixed *SetItems(mixed *i) { return Pitems = i; }

public mixed QueryMoney()      { return Pmoney; }
public mixed SetMoney(mixed i) {
  Pmoney = i;
  RefreshMoney();
  return Pmoney;
}

//--- clone/refresh one item ------------------------------------------------

private object clone_item(mixed obj, mixed props, int new) {
  int lstate;

  // If  the file name  of  the object  is an array,  then select  one
  // element out  of it by random.  It  is possible that this does not
  // result immediately in a string but in a closure so 'unclosure' it
  // first.   This way a  function can be  used instead of a file name
  // and this function may either return an object or a file we use to
  // create  a clone. Finally move the  object into the  room, tell it
  // that it has been (re)created and return the object.

  obj = funcall(pointerp(obj) ? obj[random(sizeof(obj))] : obj);
  if (stringp(obj)) obj = clone_object(obj);
  if (objectp(obj))
  {
    if (props)
    {
      if (mappingp(props))
        obj->SetProperties(props);
      else
        for (lstate = 0; lstate < sizeof(props); lstate++)
          obj->SetProperties(props[lstate]);
    }
    if ((    ME_OK != (living(obj) ? (int) obj->move(TO, M_GO)
                                 : (int) obj->move(TO, M_SPECIAL, "aparece"))
          && (int) obj->move(TO, M_NOCHECK) != ME_OK
        ) || ENV(obj) != TO) {
      if (obj) obj->remove();
      if (obj) destruct(obj);
    }
    return obj;
  }
  return 0;
}

private mixed *refresh_item(mixed *item, int new) {
  int s, refr, offset, nobjs, i, j;
  object *away, *objs;
  mixed func, file;
  mixed props;

  if ((refr = item[RITEM_REFRESH]) || new)
  {

    // Extract the  object file  names,  the possible   properties and
    // reset function out of the item array.

    offset = RITEM_OBJECT;
    if (   mappingp(item[RITEM_OBJECT])
        || pointerp(item[RITEM_OBJECT]))
    {
      props = item[offset++];
    }
    if (refr & REFRESH_FUNC) func  = item[offset++];

    nobjs = sizeof(item) - offset;
    objs  = item[offset..] - ({ 0 });

    // If REFRESH_HOME is in  effect then first  bring back the remote
    // objects   before  we might  create   new   ones  for  them with
    // REFRESH_REMOVE.

    away = objs - all_inventory();
    if (refr & REFRESH_MOVE_HOME) {
      filter_objects(away, "move", TO, M_GO);
      away -= all_inventory();
    }

    // If REFRESH_DESTRUCT or REFRESH_REMOVE is active then clone the
    // required amount of objects. Or, if this is the first time then
    // do it anyway. If REFRESH_REMOVE is active then consider all
    // remote objects (for which we have to create new ones) as "missing in
    // action" and exclude them from further refresh actions.

    // But before, check the missing objects if they are alive.
    // We have a problem with walking NPCs which are set to REFRESH_REMOVE
    // instead of REFRESH_DESTRUCT resp. REFRESH_HOME, effectively making
    // the room a NPC generator.
    // This utilizes the yet undocumented property "RefreshRemoveOk" to
    // hide 'certified' livings from the test.

    if (!new && (refr & REFRESH_REMOVE))
      for ( i=sizeof(away); i-- ; )
      {
        if (    living(away[i])
	        && !away[i]->Query("RefreshRemoveOk")
	        && !away[i]->Query(P_IS_PET)
	       )
        {
          log_file("rep/NPCREFRESH", sprintf(ctime()+" %O refresh_remove por %O\n"
                  , away[i], TO));
        }
      }

    if (new || (refr & REFRESH_ALWAYS))
    {
      s = nobjs - sizeof(objs);
    }

    if (refr & REFRESH_REMOVE)
    {
      s += sizeof(away);
      objs -= away;
    }

    if (props)
    {
      if (mappingp(props)) call_other(objs,"SetProperties",props);
      else
        for(i = sizeof(objs); i-- ; )
          for (j = sizeof(props); j-- ; )
            objs[i]->SetProperties(props[j]);
    }

    for (file = item[RITEM_FILE]; s--;)
      objs += ({ clone_item(file, props, new) });
    objs -= ({ 0 });

    if (refr & REFRESH_RESET) filter_objects(objs, "reset");

    if (closurep(func))
      for (s = sizeof(objs); s--;)
	    funcall(func, objs[s], refr, s);
    else if (stringp(func))
      for (s = sizeof(objs); s--;)
	    call_other(TO, func, objs[s], refr, s);

    // Return the new item array that results out of the above refresh
    // actions.   The  amount  of objects will   be  readjusted to the
    // initial amount. Also don't include the properties and the reset
    // function (if given) if they aren't needed any more.

    objs -= ({ 0 });
#ifndef KEEP_REFR_NONE
    if ((refr & REFRESH_ALWAYS) || sizeof(objs)) {
#endif
      item = ({ file, refr });
      if (props && refr & (REFRESH_ALWAYS | REFRESH_PROPS))
        item += ({ props });
      if (func  && refr & (REFRESH_ALWAYS | REFRESH_FUNC))
        item += ({ func });
      item += objs + allocate(nobjs - sizeof(objs));
#ifndef KEEP_REFR_NONE
    }
    else item = 0;
#endif
  }
  return item;
}

// Set P_ITEMS and clone all items in one step.

public mixed *SetItemsRefresh(mixed *items) {
  if (sizeof(Pitems)) {
    int i, j;
    object obj;
    for (i = sizeof(Pitems); i--;)
      for (j = sizeof(Pitems[i]); j--; )
        if (   objectp(obj = Pitems[i][j])
            && present(obj, TO) == obj)
          obj->remove();
  }
  if (sizeof(Pitems = items))
     Pitems = map(Pitems, SF(refresh_item), 1) - ({ 0 });
  return Pitems;
}


//--- querying and modify the items alist -----------------------------------

public varargs object *AddItem(mixed file, int refr,
			       mixed xarg1, mixed xarg2, mixed xarg3) {
  mixed *item, func;
  mapping props;
  int n, i;

  // Find  out what the  extra arguments to  AddItem() stand for. This
  // may look ugly but makes calling of AddItem() very flexible.

  n     = (intp(xarg1) && xarg1 ||
	   intp(xarg2) && xarg2 ||
	   intp(xarg3) && xarg3);
  props = ((mappingp(xarg1) || pointerp(xarg1)) && xarg1 ||
	   (mappingp(xarg2) || pointerp(xarg2)) && xarg2 ||
	   (mappingp(xarg3) || pointerp(xarg3)) && xarg3);
  func  = ((stringp(xarg1) || closurep(xarg1)) && xarg1 ||
	   (stringp(xarg2) || closurep(xarg2)) && xarg2 ||
	   (stringp(xarg3) || closurep(xarg3)) && xarg3);

  // Create  the item array and force  initial  cloning

  if (pointerp(file)) {
    for (i = sizeof(file); i--; )
      if (stringp(file[i]))
        file[i] = resolve_file(file[i]) || file[i];
  }
  else if (stringp(file))
    file = resolve_file(file) || file;

  item = ({ file, refr });
  if (props)
    item += ({ props });
  if (func) {
    item += ({ func });
    item[RITEM_REFRESH] |= REFRESH_FUNC;
  }
  if (item = refresh_item(item + allocate(n < 1 || n), 1)) {
    if (!Pitems)
      Pitems = ({});
    Pitems += ({ item });
  }
  return item;
}

public void RemoveItem(mixed what) {
  mixed file;
  int s;

  if (intp(what))
    Pitems[what] = 0;
  if (stringp(what)) {
    for (s = sizeof(Pitems); s--;)
      if (Pitems[s][RITEM_FILE] == what)
	Pitems[s] = 0;
  } else if (pointerp(what)) {
    for (s = sizeof(Pitems); s--;) {
      file = Pitems[s][RITEM_FILE];
      if (!pointerp(file))
	file = ({ file });
      if (!sizeof(file - what))
	Pitems[s] = 0;
    }
  }
  if (!sizeof(Pitems -= ({ 0 })))
    Pitems = 0;
}

//--- do the reset ---------------------------------------------------------

public varargs void reset() {
  int i;
  object *doors;

  if (sizeof(Pitems)) Pitems = map(Pitems, SF(refresh_item)) - ({ 0 });
  RefreshMoney();
  // buscamos las puertas de la habitación, y reseteamos su estado si es necesario
  if (doors = TO->ListExitsDoor())
  {
    foreach(string salida, mixed dest, object door:doors)
    {
      if ((!door->QueryDoorCloseTime() || !sizeof(door->QueryDoorCloseTime())) && door->QueryDoorDefaultInReset())
      // las puertas scheduler no se actualizan en el reset
      {
        door->SetDoorState(door->QueryDoorDefaultState());
        door->SetDoorLockState(door->QueryDoorDefaultLockState());
      }
    }
  }
}


//---------------------------------------------------------------------------

