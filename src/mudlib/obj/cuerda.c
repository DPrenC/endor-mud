/* /obj/cuerda.c
**
** [c] Cheto@simauria
** [n] Nemesis@simauria
** [w] Woo@simauria
**
** Cuerda de Esparto
**
**  3-06-97  [c] Adaptada y traducida por cheto de la rope de Nightfall.
**  Mar'99   [n] Castellanizado y corregido, que de Cheto no me fio...
**  06-10-99 [w] Ahora los Notify_Fail devuelven guay.
**
*/

#include <config.h>
#include <rope.h>
#include <properties.h>
#include <moving.h>
#include <search.h>
#include <messages.h>

inherit THING;

/*-------------------------------------------------------------------------*/

private static object tied_here;   // Objects the rope is tied to
private static object tied_there;
private static int pAllowTie2;     // Flag if two objects may bound together.
private static int sema;           // Prevents recursion in follow()
private static object storeenv;    // Room the rope is fixed in, if any.
private static mapping allowTOb;  // Allowed Details to tie the rope to
private static string whTOb;      // Detail rope is tied to

/*-------------------------------------------------------------------------*/

create() {
  ::create();
  AddId("cuerda");
  SetShort("una cuerda");
  SetLong("Es una simple cuerda de esparto, no ves nada especial en ella.\n");
  SetValue(15);
  SetWeight(1000);
  tied_here = tied_there = pAllowTie2 = 0;
}

/*-------------------------------------------------------------------------*/

public int QueryAllowTie2 ()    { return pAllowTie2; }
public int SetAllowTie2 (int i) { return pAllowTie2 = i; }

/*-------------------------------------------------------------------------*/
public object * QueryTied()
{
   if (!QueryAllowTie2())
      return ({ tied_here, 0 });
   return ({ tied_here, tied_there });
}

public object *SetTied (mixed ob)
{
  if (!QueryAllowTie2()) {
    if (pointerp(ob))
      tied_here = ob[0];
    else
      tied_here = ob;
    return ({ tied_here, 0 });
  }
  if (pointerp(ob)) {
    tied_here = ob[0];
    tied_there = ob[1];
  }
  else if (tied_here)
    tied_there = ob;
  else
    tied_here = ob;
  return ({ tied_here, tied_there });
}

object * SetUntied(object ob)
{
  if (ob == tied_here) {
    tied_here = tied_there;
    tied_there = 0;
  }
  else
    tied_here = 0;
  return QueryTied();
}

/*-------------------------------------------------------------------------*/
public string MyShort()
{
   string ret;

   ret = "";
   if (tied_here && tied_here != TO)
       ret = (string) tied_here->QueryName() || (string)tied_here->Short()
             || (string)tied_here->Query("Fastening")[whTOb];

   if (tied_here && tied_there && tied_here != TO && tied_there != TO)
     ret += " and to "+(  (string) tied_there->QueryName()
                        ||(string)tied_there->Short()
                       || (string)tied_there->Query("Fastening")[whTOb] );
   return ret;
}

public string Short (string what)
{
  string rc;
  return ::Short(what)+((tied_here || tied_there) ? (" atado a "+MyShort()) : "");
}

public string Long (string what)
{
  return  ::Long(what)
         +((tied_here || tied_there) ? (" Esto está atado a "+MyShort())+".\n" : "")
  ;
}

public string CheckNoMove() {
  if (   (tied_here || tied_there)
      && !(    (tied_here  && living(tied_here))
           || (tied_there && living(tied_there))
         )
     )
    return "La cuerda todavía está atada a "+MyShort()+".\n";
  return 0;
}

public mixed QueryNoGet()  { return ::QueryNoGet() || CheckNoMove(); }
public mixed QueryNoGive() { return ::QueryNoGive() || CheckNoMove(); }
public mixed QueryNoDrop() { return ::QueryNoDrop() || CheckNoMove(); }

public mapping AddFastening(mixed id, string descr)
{
  mapping objdet; // Details you can tie a rope to
  int i;

  if (!id) return objdet;
  if (stringp(id)) id = ({id});
  i = sizeof(id);
  if (!objdet=environment(TP)->Query("Fastening")) objdet = ([]);
  while (i--) {
    objdet[id[i]] = descr;
  }
  environment(TP)->Set("Fastening",objdet);
  return objdet;
}

/*-------------------------------------------------------------------------*/
public void follow(mixed from, mixed dest, int method, mixed extra)
// Prevent a player leaving the room if he is tied to an object in the room.
// follow another player if he is tied to it.
{
  if (sema) return;
  sema = 1;

  if (tied_here && tied_there)
  {
    if (living(tied_here) && living(tied_there))
    {
       if (tied_here == TP)
          tied_there->move(dest,method,extra);
       else
          tied_here->move(dest,method,extra);
    }
    else if ((   (living(tied_here) && tied_there)
            || (living(tied_there) && tied_here))
           && dest != storeenv && dest != storeenv->Query("VisibleRoom")
          )
    {
      TP->move(storeenv,M_SILENT);
      write("No te puedes ir de esta habitación mientras estés atado.\n");
      tell_room(environment(TP), ({ MSG_SEE, TP->QueryName()+" Falla al intentar irse de esta habitación estando atado.\n"}), ({ TP }));
      sema=0;
      return;
    }
  }
  if (dest == storeenv->Query("VisibleRoom")) {
    /* Change the tied object from source to destination room */
    if (storeenv == tied_here) tied_here = find_object(storeenv->Query("VisibleRoom"));
    else if (storeenv == tied_there) tied_there = find_object(storeenv->Query("VisibleRoom"));
    storeenv=find_object(storeenv->Query("VisibleRoom"));
  }

  TO->move(dest,M_SILENT,extra); /* move the rope :-) */
  sema = 0;
}

/*-------------------------------------------------------------------------*/

public void init()
{
  ::init();
  add_action("ftie"  , "atar");
  add_action("funtie", "desatar");
}

/*-------------------------------------------------------------------------*/
public int TieTo (object ob)
{
  mixed rc;
  int allowTie2;
  string obd;

  allowTie2 = QueryAllowTie2();
  if (tied_here && (!allowTie2 || tied_there))
  {
    notify_fail("está atado a  "+MyShort()+".\n", NOTIFY_NOT_VALID);
    return 1;
  }

  obd = (string)ob->QueryName() || (string)ob->Short()
        || (string)ob->Query("Fastening")[whTOb];

  if ((rc = ob->Query(P_NO_TIE))) {
    notify_fail(stringp(rc) ? rc
                            : "No puedes atar"+::Short()+" a "+obd+".\n"
               , NOTIFY_NOT_VALID);
    return 2;
  }
  // Carried ropes get dropped
  if (environment() == TP)
    TO->move(environment(TP),M_SILENT);

  storeenv = environment();
  ob->AddFollower(TO);
  if (tied_here)
    tied_there = ob;
  else {
    tied_here = ob;
    SetNoGet(1);
  }
  return 0;
}

/*-------------------------------------------------------------------------*/
public int UntieFrom (object ob)

{
  string obd;
  mixed  rc;

  obd = (string)ob->QueryName() || (string)ob->Short()
        || (string)ob->Query("Fastening")[whTOb];

  if (ob != tied_here && ob != tied_there) {
    notify_fail(::Short()+" no está atado a "+obd+".\n"
               , NOTIFY_NOT_VALID);
    return 1;
  }

  if ((rc = ob->Query(P_NO_UNTIE))) {
    notify_fail(stringp(rc) ? rc
                          : "No puedes desatar "+::Short()+" de "+obd+".\n"
               , NOTIFY_NOT_VALID);
    return 2;
  }

  ob->RemoveFollower(TO);
  if (tied_here == ob) {
    tied_here = tied_there;
    tied_there = 0;
    if (!tied_here) {
       SetNoGet(0);
       storeenv=0;
    }
  }
  else
    tied_there = 0;
  return 0;
}

/*-------------------------------------------------------------------------*/
public string dtie(string arg)
{
    allowTOb=environment(TP)->Query("Fastening");
    if  (allowTOb==([]) || !allowTOb || !member(allowTOb,arg)) return 0;
    return arg;
}

/*-------------------------------------------------------------------------*/
public int ftie (string arg)
{
  object ob;
  string t1, t2;

  if (   !arg
      || 2 != sscanf(arg, "%s to %s", t1, t2)
      || TO != TP->WSearchEnvInv(t1)
     )
  {
    notify_fail("¿Qué quieres atar?\n");
    return 0;
  }

  if (!(ob = TP->WSearchEnvInv(t2)) && !(whTOb=dtie(t2)))
  {
    notify_fail("¿A qué lo quieres atar?\n");
    return 0;
  }

  if (!ob && whTOb) ob=environment(TP);

  if (TieTo(ob))
    return 0;

  t1 = (string)ob->QueryName() || (string) ob->Short();
  if (t1="nobody") t1=0;
  if (!t1 && sizeof(ob->Query("Fastening")))
    t1 = ob->Query("Fastening")[whTOb];
  else if (!t1 && !sizeof(ob->Query("Fastening")))
    t1 = "something";

  write("Atas "+::Short()+" a "+t1+".\n");
  tell_room(environment(TP), ({ MSG_SEE, TP->QueryName()+" atat "+::Short()+" a "+t1+".\n"}), ({ TP }));

  return 1;
}

/*-------------------------------------------------------------------------*/
public int funtie (string arg)
{
  object ob;
  string t1, t2;

  if (   !arg
      || 2 != sscanf(arg, "%s from %s", t1, t2)
      || TO != TP->WSearchEnvInv(t1)
     )
  {
    notify_fail("¿Qué quieres desatar?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  if (!(ob = TP->WSearchEnvInv(t2)) && !(whTOb=dtie(t2)))
  {
    notify_fail("¿De dónde lo quieres desatar?\n", NOTIFY_NOT_VALID);
    return 0;
  }

  if (!ob && whTOb) { write(whTOb+"\n"); ob=environment(TP); }

  if (UntieFrom(ob))
    return 0;

  write("desatas"+::Short()+" de "+(ob->Short()||ob->Query("Fastening")[whTOb])+".\n");
  tell_room(environment(TP), ({ MSG_SEE, TP->QueryName()+" desata "+::Short()+" de "+(ob->Short()||ob->Query("Fastening")[whTOb])+".\n"}), ({ TP }));

  whTOb=0;
  return 1;
}

/*************************************************************************/

