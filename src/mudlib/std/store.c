/*SIMAURIA '/std/store.c'
  =======================
  [w] Woo@simauria
  [t] Theuzifan@simauria
  19-02-97 [t] Traducido al castellano y adaptado a
  	       /secure/sefun_search.ic
  28-04-97 [w] Cambiado el room.c por habitacion.c
  27-10-98 [w] Modificado el lugar de habitacion.c
  04-02-99 [t] Castellanizado.
*/

inherit "/std/container/restrictions";
inherit ROOM;
inherit "/std/thing/moving";

#include <wizlevels.h>
#include <properties.h>
#include <moving.h>
#include <search.h>

#define P_TIMESTAMP "TimeStamp" // Time when item entered the store
#define DESTRUCT_TIME 3*60      // Time when an item shall be destructed
#define MAX_ITEMS 6 // if there are more than 6 items of the same file-
                    // name (not clones of /std) in the store, new items
                    // get destructed
#define DESTROY_CHANCE 	90

private static mapping Pinventory;
// Contains the inventory in the form:
// (["<short without article>#<value>#<size>":({<fitting objects>})])
/*--------------------------------------------------------------------------*/

public int leave_store(string str)
{
  object env;
  if (str
      ||!TP
      ||environment(TP)!=TO) return 0;
  if (!env=environment(TO))
    return TP->move("/std/void",M_GO,"a ningún sitio");
  else
    return TP->move(env,M_GO,"a la tienda");
}

public void create()
{
  "*"::create();
  SetIntShort ("un almacén");
  SetIntLong("Estás dentro de un almacén.\n");
  SetMaxIntSize(100000);

#if 0
  /* Creator is a string, not an object, and if it was a now-destructed
   * clone, the attempt to 'load' it implicitely will fail.
   * What shall it log anyway? I don't understand it... [Mateese]
   */
  log_file("STORES",TO->QueryCreator()+" ha creado un almacén.\n"
    "interactivo: "+(TO->QueryCreator())->QueryCreator()+".\n"
    "Creador: "
    +((TO->QueryCreator())->QueryCreator())->QueryCreator()+".\n\n");
#endif
  SetNoGet(1); // uh oh, don't steal the store!
  AddExit("tienda",SF(leave_store));
}

private int check_timestamp(object ob)
{
  int ts;
  return (ts = ob->Query(P_TIMESTAMP)) && (ts+DESTRUCT_TIME<time());
}

protected void check_idle_out()
{
  map_objects(filter(all_inventory(),SF(check_timestamp)),"remove");
}

public varargs void reset()
{
  if (sizeof(filter(all_inventory(TO),
    lambda(({SYM(ob)}),
      ({SF(&&),
        ({SF(query_once_interactive),
          SYM(ob)
        }),
        ({SF(<),
          ({SF(query_wiz_level),
            SYM(ob)
          }),
          LEARNER_LVL
        })
      })))))
    return;
  check_idle_out();
  // Check for items which are too long in the store
  return (::reset());
}

public string Short()
{
  return "";
}

public string Long()
{
  return "";
}

/*
** The store handles what will be displayed to a player.
** The list returned looks like this:
**   ([<objectp>:<calc_price>])
*/

public object *SearchObjects(string pattern)
{
  mixed l;
  int *idx,i;

  switch(lower_case(pattern||"todo"))
  {
   case "pequeño":
   case "pequenyo":
     l = filter(all_inventory(TO)
                     , lambda(({SYM(o)}), ({SF(==), P_SIZE_SMALL
                                    , ({SF(call_other), SYM(o), "Query", P_SIZE})})
                     ));
     break;
   case "normal":
   case "mediano":
     l = filter(all_inventory(TO)
                     , lambda(({SYM(o)}), ({SF(==), P_SIZE_MEDIUM
                                    , ({SF(call_other), SYM(o), "Query", P_SIZE})})
                     ));
     break;
   case "grande":
     l = filter(all_inventory(TO)
                     , lambda(({SYM(o)}), ({SF(==), P_SIZE_LARGE
                                    , ({SF(call_other), SYM(o), "Query", P_SIZE})})
                     ));
     break;
   case "genérico":
   case "generico":
     l = filter(all_inventory(TO)
                     , lambda(({SYM(o)}), ({SF(==), P_SIZE_GENERIC
                                    , ({SF(call_other), SYM(o), "Query", P_SIZE})})
                     ));
     break;
   default:
     l = Locate(pattern,SM_MULTI|SM_IGNLIGHT);
     break;
  }
  if (mappingp(l))
    return m_values(l);
  return l;
}

public int CheckList(object ob)
{
  return strlen(ob->QueryShort()||"")
         && !ob->Query(P_NOSELL)
         &&!(int)ob->QueryIsPlayer();
}

public int CheckId(object ob, string pattern)
// Called in filter to get all items which identify themself to the given
// id.
{
  int i;
  if (!CheckList(ob)) return 0;
  switch(lower_case(pattern))
  {
     case "pequeño":
     case "pequenyo":
      return ob->QuerySize()==P_SIZE_SMALL;
     case "normal":
     case "mediano":
      return ob->QuerySize()==P_SIZE_MEDIUM;
     case "grande":
      return ob->QuerySize()==P_SIZE_LARGE;
     case "genérico":
     case "generico":
      return ob->QuerySize()==P_SIZE_GENERIC;
     default:
  }
  return member(SearchObjects(pattern)||({}),ob)!=-1;
}

protected string build_short(object ob)
{
  if (environment()&&environment()->QueryMarket())
    return ob->Short()+"#"+
           ob->Query("shopprice")+"#"+
           ob->QuerySize();
  return ob->Short()+"#"+
         ob->QueryValue()+"#"+
         ob->QuerySize();
}

protected mapping AddInventory(object ob)
{
  string short;
  if (!CheckList(ob)) return Pinventory;
  if (!Pinventory) Pinventory = ([]);
  if (!member(Pinventory,short = build_short(ob))) Pinventory[short] = ({ob});
  else Pinventory[short]+= ({ob});
  return Pinventory;
}

protected mapping RemoveInventory(object ob)
{
  string short;
  if (!Pinventory) return 0;
  if (!member(Pinventory,short = build_short(ob))) return Pinventory;
  Pinventory[short]-=({ob});
  if (!sizeof(Pinventory[short])) m_delete(Pinventory,short);
  return Pinventory;
}

public mapping QueryInventory()
{
  return Pinventory;
}

public mapping GroupInventory(object *obs)
{
  int i,value,size;
  mapping res;
  string *shorts;

  i = sizeof(shorts = map(obs,SF(build_short)));
  res = ([]);
  while(i--)
    if (member(Pinventory||([]),shorts[i]))
      res[shorts[i]] = Pinventory[shorts[i]];
  return res;
}

public object *GetEqual(object ob)
// Returns all objects in the store, which have the same
// shortdescription and the same value as <ob> in an array.
{
  return (Pinventory||([]))[build_short(ob)]||({});
}

public void notify_enter(mixed from,int method,mixed extra)
{
  int i,des;
  object *inv,po;
  po = PO;
  if (query_once_interactive(po)
      && !IS_LEARNER(po))
    {
      for(inv = all_inventory(TO), i = 0; i < sizeof(inv); i++)
        if (!living(inv[i]) && random(100) < DESTROY_CHANCE)
          call_out(symbol_function("remove",inv[i]),1);
      write(
        "Parece que alguien quitó rápidamente bastantes objetos del almacén\n"
	"cuando el vendedor fué asesinado.\n");
    }
  if (po->QueryCreator()!=object_name(TO)
      &&!query_once_interactive(po))
  // Don't destruct own articles or items
    {
      po->Set(P_TIMESTAMP,time());
      if (sizeof(GetEqual(po))>MAX_ITEMS)
	des = 1;
    }
  if ((!po->Short() || "" == po->Short()) && !query_once_interactive(po))
    des = 1;
  if (des)
    call_out(symbol_function("remove",po),1);
  else
    AddInventory(po);
  return (::notify_enter(from,method,extra));
}

public void notify_leave(mixed to,int method,mixed extra)
{
  RemoveInventory(PO);
  return (::notify_leave(to,method,extra));
}

public status id_store()
{
  return 1;
}

public int id(string str)
{
  if (IS_LEARNER(TP))
    return ((lower_case(str)=="almacen") || lower_case(str)=="almacén")||(::id(str));
  return (::id(str));
}

public void GoOutPeople()
{
    object tienda = environment();
    
    foreach(object ob: all_inventory()) {
      if (query_once_interactive(ob)) {
        tell_object(ob, "Escuchas voces en la tienda. Disimuladamente, abandonas el almacén, "
                         "no sea que te pillen.\n");
        ob->move(tienda, M_NOCHECK);
        ob->LookAfterMove();
      }
    }
}

public void NotifyDayStateChange(mixed data, int newstate)
{
    ::NotifyDayStateChange(data, newstate);
    object tienda = environment();
    if (tienda && tienda->IsCloseTime(newstate))
    {
        GoOutPeople();
        tienda->CheckState(newstate, 0);
    }
}
