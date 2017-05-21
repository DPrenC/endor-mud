/**
 * SIMAURIA '/std/living/restrictions.c'
 */

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <attributes.h>
#include <living.h>
#include <messages.h>

inherit "/std/container/restrictions";

public mixed Query(string prop); // std/base

public string QueryName();                  // std/living/description
public int QueryGhost();                    // std/living/description
public int QueryInvis();                    // std/living/description
public void GetHeart(int user);             // std/living/heart
public varargs int QueryStr(int real);      // std/living/stats
public int QuerySize();			    // std/living/description
public int QueryParalyzed();  // std/living/body

//---------------------------------------------------------------------------

// Esta funcion es para cuando se cambie a stats d20
//¿Rara? Pues si, pero da los resultados que tiene que dar segun d20
/*
#define SINNOMBRE ({ 50000, 57500, 65000, 75000, 87500 })
public int QueryMaxIntWeight()
{
  int str;

  if (QueryGhost()) return 0;

  str = Query(P_STR);
  if (str < 1) return 0;
  if (str <11) return 5000*str; // 5 Kg por punto de fuerza
  str -= 10;
  return SINNOMBRE[str%5]*to_int(pow(2,str/5));
}
*/
public int QueryMaxIntWeight () {
  return 10000 + 600 * STAT_SCALE * QueryStr(1);  // 10..70 kg load
}
public int SetMaxIntWeight(int i) { return QueryMaxIntWeight(); }

public int QueryMaxContent()
{ // Compat
    return QueryMaxIntWeight();
}
public int SetMaxContent(int i)
{ // Compat
    return SetMaxIntWeight(i);
}

public int QueryMaxIntSize()
{
	return 8*(QuerySize()+1);
}
public int SetMaxIntSize(int to)
{
	return QueryMaxIntSize();
}

public int QueryLoad()
{ // Los || 1 son para evitar los division by cero
  return max((100 * QueryIntWeight()) / (QueryMaxIntWeight()||1),
             (100 * QueryIntSize()  ) / (QueryMaxIntSize()  ||1) );
}
public int SetLoad (int i) { return QueryLoad(); }

public varargs int QueryWeight(int flag) {
    return (flag || !QueryGhost()) ? ::QueryWeight(flag)
                                   : QueryIntWeight();// No own body weight
}

public int SetWeight(int new) {
    if (QueryGhost())
    { // No own body weight, 'new' ist just load.
      // => Add the normal bodyweight to it.
        new = new + ::QueryWeight() - QueryIntWeight();
    }
    ::SetWeight(new);
    if (new > QueryMaxIntWeight() >> 1) GetHeart(HEART_HEAL);
    return QueryWeight();
}


public int QueryMaxWeight()
{
  return QueryWeight()-::QueryIntWeight()+QueryMaxIntWeight();
}

public int SetMaxWeight (int i)
{
  return QueryMaxWeight();
}

//---------------------------------------------------------------------------
private int _overload_droppable (object ob)
{
  return    ob->QueryWeight() && !ob->Query(P_NODROP)
         && (ob->QueryMoneyObject() || !ob->Query(P_AUTOOBJECT))
        ;
}

public void DropOverload()
{
  object *inv, *dropped;
  int max, ix;

  inv = filter(all_inventory(), SF(_overload_droppable));

  if (!environment() || !sizeof(inv)) return;
  max = QueryMaxIntWeight();
  dropped = ({});
  while (sizeof(inv) && QueryIntWeight() > max) {
    ix = random(sizeof(inv));
    if (ME_OK == inv[ix]->move(environment(), M_DROP))
      dropped += ({ inv[ix] });
    inv = inv[0..ix-1] + inv[ix+1..];
  }

  if (sizeof(dropped))
  {
    dropped = fold_objlist(dropped);
    tell_object( TO
               , implode_list(dropped, "", " se te cae.\n"));
    if (!QueryInvis())
      tell_room( environment(TO)
               , ({ MSG_SEE
                  , capitalize(implode_list(dropped, " " + QueryName()+" pierde", ".\n"))
                  , "Algunas cosas caen al suelo.\n" })
               , ({ TO }) + dropped
               );
    else
      tell_room( environment(TO)
               , ({ MSG_SEE
                  , capitalize(implode_list(dropped, 0, " están en el suelo.\n"))
                  , "Algunas cosas caen al suelo.\n" })
               , ({ TO }) + dropped
               );
   }
}

//---------------------------------------------------------------------------
public int prevent_leave(mixed dest, int method, mixed extra)
{
  return (method == M_GET) ? ME_NO_LEAVE
                           : ::prevent_leave(dest, method,extra);
}

//---------------------------------------------------------------------------

public int allow_enter(int method, mixed extra)
{
  if (method == M_PUT) return ME_NO_ENTER;
  return ::allow_enter(method, extra);
}

/***************************************************************************/
