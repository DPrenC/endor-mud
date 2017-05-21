/*SIMAURIA '/std/shop/comm.c'
  ===========================
  19-02-97 Theuzifan, Traducido al castellano, genero femenino/masculino
  	   antes era the shopkeeper (masculino o femenino) y ahora es el
  	   tendero/la tendera... y ello por defecto...

  11-05-99 Theuzifan, QueryShopkeeper() devuelve 0 si el tendero está muerto.
  	   Antes, el tendero muerto 'soltaba un gruñido y te impedía el paso.
  	   Eso sí que da miedo.
  03-03-03 Theuzifan, El dustbin pasa a ser un objeto real.
 */

#include <config.h>
#include <properties.h>
#include <living.h>
#include <rooms.h>
#include <wizlevels.h>
#include <messages.h>

#define SHOPKEEPER_ID "Soy el tendero"
#define DUSTBIN_ID "Soy el cubo de basura habitado"
#define LSF(x) symbol_function(x,TO)
#define ESF(x) symbol_function(x)

public object QueryShopkeeper()
{
  object ob;

  ob=present(SHOPKEEPER_ID, TO);
  if (ob && living(ob)) return ob;
  return 0;
}

public void RemoveShopkeeper()
{
  object ob;
  string fname;

  if (ob = QueryShopkeeper())
    {
      fname = blueprint(ob);
      ob->remove();
      if (ob) destruct(ob);
      TO->RemoveItem(fname);
      TO->SetSchedulerID(0);
    }
}

public varargs void SetShopkeeper(string file,mapping properties)
{
  int gender;

  gender=random(2);
  RemoveShopkeeper();
  if (!properties) properties = ([P_CANT_LURE: 1]);
  else m_add(properties, P_CANT_LURE, 1);
  if (!file)
    TO->AddItem("/std/npc",REFRESH_HOME,
      ({
        ([
          P_NAME:(gender?"El tendero":"La tendera"),
          P_IDS:(gender?({"tendero","vendedor","asistente"}):({"tendera","vendedora","asistenta"})),
          P_SHORT:(gender?"el tendero":"la tendera"),
          P_LONG:(gender?"Éste es el tendero.\n":"Ésta es la tendera.\n"),
          P_GENDER:(gender?MALE:FEMALE),
          P_RACE:"humano",
          P_ALIGN:500+random(300),
          P_LEVEL:17,
          P_DEX:16,
          P_CON:19,
          P_INT:15,
P_IVISION:20,
P_UVISION:100
        ]),
        properties
      })-({0}),
      LSF("shopkeeper_refresh"));
  else
    TO->AddItem(file,REFRESH_HOME,properties,LSF("shopkeeper_refresh"));
  TO->SetSchedulerID(SHOPKEEPER_ID);
}

public object QueryDustbin()
{
  return present(DUSTBIN_ID,TO);
}

public void RemoveDustbin()
{
  object ob;
  string fname;

  if (ob = QueryDustbin())
    {
      fname = blueprint(ob);
      ob->remove();
      if (ob) destruct(ob);
      TO->RemoveItem(fname);
    }
}

public varargs void SetDustbin(string file,mapping properties)
{
  RemoveDustbin();
  if (!file)
  	TO->AddItem("/std/shop/dustbin", REFRESH_HOME, ({}), LSF("dustbin_refresh"));
/*
    TO->AddItem("/std/container",REFRESH_HOME,
      ({
        ([
          P_IDS:({"cubo de basura","cubo"}),
          P_ADS:({"grande","papelera"}),
          P_WEIGHT:0,
          P_SHORT:"un cubo de basura",
          P_LONG:"Un reluciente cubo de basura.\n"
                  "Puedes tirar objetos inutiles en él.\n",
          P_NOGET:"La cosa que habita el cubo suelta un gruñido que te hace cambiar de idea.\n"
        ]),
        properties
      })-({0}),
      LSF("dustbin_refresh"));
*/
  else
    TO->AddItem(file,REFRESH_HOME,properties,LSF("dustbin_refresh"));
}

public varargs string CustomerName(int cap)
// Returns name, shortdescription or whatever of the customer. If
// the customer is an invis wizard, 0 is returned, i. e. there should
// be no message given to its environment.
{
  string message;
  if (!TP) return 0;
  message = TP->QueryName()||TP->QueryShort()||"alguien";
  return message?(cap?capitalize(message):message):0;
}

protected varargs status sk_in_shop(int silent)
{
  if (TO->QueryNoShopkeeper()
      ||QueryShopkeeper())
    return 1;
  if (!silent)
    notify_fail(
      lambda(0,
        ({ESF(","),
          ({LSF("Write"),
            "No hay nadie aquí que puede hacer eso por tí...\n"
          }),
          ({LSF("Say"),
            CustomerName(1)+" mira confundido porque no hay nadie atendiendo...\n",
            quote(({TP}))
          })
        })),
      NOTIFY_NOT_VALID);
  return 0;
}

public varargs void Say(mixed str,object *exclude,status ignlight)
{
  if (stringp(str))
    str = ({str,0});
  if (TP&&TP->QueryInvis()&&IS_LEARNER(TP)&&member(exclude||({}),TP)==-1)
    tell_object(TP,str[0]);
  if (!ignlight)
    tell_room(TO,
      ({MSG_SEE,
        W(str[0]),
        W(str[1]?str[1]:"Algo pasa.\n")
  }),exclude || ({}));
  else
    if (exclude) tell_room(TO,str[0],exclude);
    else tell_room(TO, str[0]);
}

public varargs void Write(mixed str,status ignlight)
{
  if (stringp(str))
    str = ({str,0});
  if (!ignlight)
    tell_object(TP,
      ({MSG_SEE,
        W(str[0]),
        W(str[1]?str[1]:"Está demasiado "+(TP->CantSee()<0?"oscuro":"claro")+".\n")
      }));
  else
    tell_object(TP,W(str[0]));
}

public varargs string SkShort(int cap)
// Returns the shortdescription of the shopkeeper. If argument is
// given, the name will be returned capitalized.
{
  object ob;
  if (cap)
    if (TO->QueryNoShopkeeper())
      return "El tendero";
    else
      return (ob=QueryShopkeeper())
             ?capitalize(ob->QueryShort()||"Alguien"):0;
  if (TO->QueryNoShopkeeper()) return "el tendero";
  return (ob=QueryShopkeeper())?ob->QueryShort()||"alguien":0;
}

public varargs int SkSay(string str)
// Let the shopkeeper say 'str' and return 1. Return 0 for failure.
{
  if (sk_in_shop(1))
    {
      if (TP&&TP->QueryInvis()&&IS_LEARNER(TP))
        tell_object(TP,W(SkShort(1)+" te dice: "+str));
      else
        tell_room(TO,W(SkShort(1)+" dice: "+str));
      return 1;
    }
  return 0;
}

public int SkWrite(string str)
// Let the shopkeeper say 'str' only to the customer and return 1.
// Return 0 for failure.
{
  if (sk_in_shop(1))
    return (int)write (W(SkShort(1)+" te dice: "+str))||1;
  return 0;
}

public int SkEmote(mixed str)
{
  if (sk_in_shop(1))
    {
      if (stringp(str))
        tell_object(TP,W(SkShort(1)+" "+str));
      else
	if (pointerp(str)&&sizeof(str)==2)
	  {
	    tell_object(TP,W(SkShort(1)+" "+str[0]));
	    tell_room(TO,W(SkShort(1)+" "+str[1]),({TP}));
	  }
      return 1;
    }
  return 0;
}

public void shopkeeper_refresh(object ob)
{
  ob->AddId(SHOPKEEPER_ID);
}

public void dustbin_refresh(object ob)
{
  object *inv;
  int a;

  ob->SetMaxIntWeight(1<<29);
  ob->AddId(DUSTBIN_ID);
  if (time()-ob->QueryCreationTime()<10)
    tell_room(TO,
      ({ MSG_SEE,
        SkShort(1)+" rebusca por ahí y coloca un cubo de basura en una esquina\n"
	"de la tienda.\n",
	"Algo pasa.\n"
      }) );
  inv = all_inventory(ob);
  a = sizeof(inv);
  inv = inv - filter(inv, SF(query_once_interactive));
  if (a)
  {
    tell_room(TO, "Se escapan varios sonidos desagradables del cubo de basura y te"
	          "sientes feliz de que sólo sean los sonidos los que se escapen...\n");
    map_objects(inv, "remove");
    inv = inv - ({ 0 });
    if (sizeof(inv))
    {
      map(inv, SF(destruct));
      inv = inv - ({ 0 });
    }
  }
}
public string CantAttend()
{
    object sk;
    string skname;
    int skgender;
    if (!TP || (!TO->QueryNoShopkeeper() && !(sk = QueryShopkeeper())))
    {
        return "No hay nadie aquí para atenderte.\n";
    }
    if (sk)
    {
        skname = sk->QueryName();
        skgender = sk->QueryGender();
    }
    else
    {
        skname = "el tendero";
        skgender = GENDER_MALE;
    }
    if (sk && !sk->CanSeeObject(TP))
    {
        return CAP(skname) + " no puede verte.\n";
    }
    if (sk && sk->Fighting())
    {
        return "Parece que " + CAP(skname) + " está bastante ocupad" +
               (skgender == GENDER_FEMALE ? "a" : "o") + " en "
               "este momento como para atenderte.\n";
    }
    return 0;
}

