/**
 * SIMAURIA '/std/shop.c'
 */

#define SHOP_DIRECTORY  STDPATH

inherit SCHEDULER_ROOM;
inherit SHOP_DIRECTORY "shop/articles";
inherit SHOP_DIRECTORY "shop/comm";
inherit SHOP_DIRECTORY "shop/trading";

#include <config.h>
#include <properties.h>		// P_NOBUY, P_NOSELL
#include <moving.h>		// move-methods and errors
#include <wizlevels.h>		// IS_LEARNER and such
#include <rooms.h>		// REFRESH
#include <money.h>
#include <messages.h>
#include <scheduler.h>
#include <nightday.h>
// general defines

#define MYFILE	SHOP_DIRECTORY "shop"	// this is me, we need this for tests
#define P_LASTLIST "shoplist"
#define P_SELL_MUTEX (to_string(TO)+":is selling")
#define MAX_PRICE	10000 	// Is used in 'GetMaxPrice', this func
				// can be overloaded by an inherit shop.

#define DYNAMIC_DEFAULT   20	// Speed refers to dynamic.
#define DEFAULT_MIN_CASH 50000	// Minimal cash of a shop. When a shop is lower
				// at cash it will be restored at reset().

/*
* Variables
*/

private static string Pfstore, Psigndescr,Pverb_list,Pverb_appraise,
                      Pverb_identify,Pverb_sell,Pverb_buy,Pverb_show,Pmarket;
private static status Pliving_trade, Pno_shopkeeper;
private static int Psecure;

private void log_compat(string old,string new)
{
  log_file("COMPAT.shop",
           object_name()+" "+old+" -> "+new+"\n");
}

/*
* The following function may be overloaded by a customized shop for your
* own purpose.
*/

public status CheckTrade(object ob)
// Returns 1 if the shop trades with objects like this, else 0.
{
  return 1;
}

#define TIENDA_CODE ("__tienda_" + blueprint())
public int ModifyPrice(object ob, int price, string verb)
// Here you may modify the price of an object depending on its original price.
// The modified value will be returned.
{
  int rebaja;
  object skeeper;
  int diff;

  skeeper = QueryShopkeeper();
  if (skeeper)
    diff = TP->QuerySkillLevel("comerciar") - skeeper->QuerySkillLevel("comerciar");
  else diff = 0;
  rebaja = TP->Query(TIENDA_CODE);
  if (!rebaja) {
  	rebaja = TP->UseSkill("comerciar", diff);
  	TP->Set(TIENDA_CODE, rebaja);
  }
  if (rebaja>75) {
  	rebaja=75;
  }

  if (verb=="comprar" || verb=="identificar" || verb="lista")
    price -= price*rebaja/100;
  else
    price += price*rebaja/100;
  return price;
}

public varargs int GetMaxPrice(object ob)
// Return the maximum possible price.
{
  return MAX_PRICE;
}

protected status CheckLivingTrade(object ob)
// Returns 1 if it is allowed to trade with livings, or the object is no living
// and otherwise it returns 0.
{
  return Pliving_trade || !living(ob);
}

public mixed SetMarket(mixed i)
// If a player wants to sell items in here for a certain amount of money
// which he will get when someone buys his item, then this flag
// should be set to 1. The flag might also be a string which will specify
// the filename where to store the sold items.
{
  if (!i)
    return Pmarket = 0;
  if (intp(i))
    return Pmarket = blueprint();
  return Pmarket = resolve_file(i);
}

public string QueryMarket() { return Pmarket; }

public status SetSecurity(status i)
// If set to 1, no player will be able to enter the store, even if the shop-
// keeper is gone.
{
  return Psecure = i;
}

public status QuerySecurity()
{
  return Psecure;
}

public string SetSignDesc(string str)
// You may give an alternetive description to the sign. Otherwise the
// standard-description is taken, telling the player how to use the
// commands in here.
{
  return Psigndescr = str;
}

public string QuerySignDesc()
{
  return Psigndescr;
}

public string SetList(string verb) { return Pverb_list = verb; }
public string QueryList() { return Pverb_list; }
public void CanList(int can)
{
   if (can == 1) SetList("lista");
   else SetList(0);
}

public string SetIdentify(string verb) { return Pverb_identify = verb; }
public string QueryIdentify() { return Pverb_identify; }
public void CanIdentify(int can)
{
   if (can == 1) SetIdentify("identificar");
   else SetIdentify(0);
}

public string SetAppraise(string verb) { return Pverb_appraise = verb; }
public string QueryAppraise() { return Pverb_appraise; }
public void CanAppraise(int can)
{
   if (can == 1) SetAppraise("valorar");
   else SetAppraise(0);
}

public string SetSell(string verb) { return Pverb_sell = verb; }
public string QuerySell() { return Pverb_sell; }
public void CanSell(int can)
{
   if (can == 1) SetSell("vender");
   else SetSell(0);

}

public string SetBuy(string verb) { return Pverb_buy = verb; }
public string QueryBuy() { return Pverb_buy; }
public void CanBuy(int can)
{
   if (can == 1) SetBuy("comprar");
   else SetBuy(0);
}

public string SetShow(string verb) { return Pverb_show = verb; }
public string QueryShow() { return Pverb_show; }
public void CanShow(int can)
{
   if (can == 1) SetShow("mostrar");
   else SetShow(0);
}

public int SetLivingTrade(int i) { return Pliving_trade = i; }
public int QueryLivingTrade() { return Pliving_trade; }

public int QueryNoShopkeeper() { return Pno_shopkeeper; }
public void ForbidShopkeeper()
{
  Pno_shopkeeper = 1;
  RemoveShopkeeper();
}

public void AllowShopkeeper()
{
  Pno_shopkeeper = 0;
  SetShopkeeper();
}

/*
* Functions of this room
*/

public string detail_shopkeeper()
// If the shopkeeper is just an 'idea' and no thing ...
{

   if (QueryNoShopkeeper())
    return "No hay nadie atendiendo.\n";
  return "El tendero te mira sin demasiado interés...\n";
}

protected varargs string format_sign(string cmd,string desc,string help)
{
  return
    W(STR->ladjust(cmd+" ",27,".")+" "+desc)+"\n"+
    (help?W(STR->mkstr(28)+"Ejemplo: "+help)+"\n":"");
}

public string detail_sign()
// Give a help on what functions you may use in here.
{
  string buy,sell,identify,appraise,list,vshow,result;

  if (buy = QuerySignDesc()) return buy;
  buy = QueryBuy();
  sell = QuerySell();
  identify = QueryIdentify();
  appraise = QueryAppraise();
  list = QueryList();
  vshow = QueryShow();

  if (!(buy||sell||identify||appraise||list||vshow))
    return "El tendero es autista. No esperes demasiado comercio de él...\n";

  result = "";
  if (buy||sell)
    result+="Aquí puedes "+(buy?buy+(sell?" o ":""):"")
                      +(sell||"")+" cosas.\n";
  result+="Puedes comerciar con el tendero, el cual puede:\n";
  result+=list?format_sign(list+" [<objeto>]",
                           "Mostrar articulos de la tienda (todos/objeto).",
                           list+", "+list+" arma"):"";
  result+=identify?format_sign(identify+" <objeto>",
                               "Pedir informacion especial de un objeto "
			       "que posees. Te costará un 10% del valor "
			       "del objeto en cuestión.",identify+" espada"):"";
  result+=vshow?format_sign(vshow+" <objeto>",
                            "Pedir información al tendero sobre un "
			    "objeto del almacen.", vshow+" antorcha"):"";
  result+=appraise?format_sign(appraise+" <objeto>",
                               "Preguntar al tendero sobre el valor de uno "
			       "de tus objetos.",
			       appraise+" amuleto"):"";
  if (!QueryMarket())
    result+=sell?format_sign(sell+" <objeto>",
                             "Vender objetos.",
                             sell+" todo, "+sell+" todas las antorchas"):"";
  else
    result+=sell?format_sign(sell+" <objeto> [por <precio>]",
                                 "Vender objetos. El dinero irá a parar a "
                                 "tu banco tan pronto como alguien lo compre. "
	  	     "si quieres venter el objeto por un precio "
		     "determinado, escríbelo en monedas de cobre. ",
                             sell+" antorchas por 20, "+sell+
                             " antorchas de la bolsa"):"";
  result+=buy?format_sign(buy+" <objeto>",
                          "Comprar objetos de la tienda. 'comprar realmente "
			  " <objeto>' intentara comprar ese objeto aunque "
			  "no dispongas del tipo de moneda necesario, dándole "
			  "al tendero un pequeño incentivo por el cambio de "
			  "moneda.",
			  buy+" gafas, "+buy+" 3, "+buy+" todas las antorchas"):"";
/*
  result+=(TP&&IS_LEARNER(TP))?format_sign("tienda <comando>",
                                           "Comandos especiales para Wizs. "
                                           "Mira 'tienda ayuda' para mas información."):"";
*/
  result += "Los precios que aparecen en las transacciones son puramente orientativos " +
  	"y pueden variar en función de la habilidad del comerciante y la del cliente.\n";

  return STR->smore(result, TP->QueryPageSize());
}

public int go_store()
// A special exit leading into the store. Wizards can enter the store anytime.
{
  if (!IS_LEARNER(TP))
    {
      if((QueryShopkeeper()&&environment(QueryShopkeeper())==TO)
         ||QueryNoShopkeeper())
        return notify_fail(
          lambda(0,
            ({
              SF(SkEmote),
              quote(
                ({
                   "suelta un gruñido y te cierra el paso.\n",
                   "cierra el paso a "+CustomerName()+" cuando intentaba "
		   "entrar en el almacén.\n"
                }) )
            })),NOTIFY_NOT_VALID),0;
      // Ah, now we may prevent players from entering the store even if the
      // shopkeeper is not there anymore. (s. SetSecurity())
      if (QuerySecurity())
        return notify_fail(
          lambda(0,
            ({CL_PROGN,
              ({SF(Write),
		"Un complicado sistema de seguriadad cierra las puertas"
		"delante de tí.\n"
              }),
              ({SF(Say),
                CustomerName(1)+" intenta entrar en el almacen, pero no puede.\n"
                "Un complicado sistema de seguridad cierra las "
		"puertas delante de "+TP->QueryObjective()+".\n",
                quote(({TP}))
              })
            })),NOTIFY_NOT_VALID),0;
    }
  return PutInStore(TP);
}

/*
** Actions in this room
*/

public object *do_buy(string str)
// This is called when the customer types 'buy'.
{
  int number, force, count, count2;
  string h, msg;
  string *spl, *spl2, *plids;
  object *ret;
  object ob;

  if (msg = CantAttend())
  {
      write(msg);
      return ({});
  }
  ;
  if (str&&sscanf(str,"realmente %s",h))
    {
      str = h;
      force = 1;
    }
  if (!to_int(str))
    Say(CustomerName(1)+" quiere "+(QueryBuy()||"comprar")+" "+
        (str||"algo")+".\n",({TP}),1);
  else
    Say(CustomerName(1)+" quiere "+(QueryBuy()||"comprar")+
        " el artículo num. "+str+".\n",({TP}),1);
  if (!sk_in_shop())
    return 0;	// Check if the shopkeeper is in the shop and
		// if not, give a message to the player.


  if (!QueryBuy())		// you can't buy anything in here
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "No va a vender ningún objeto.\n"
        })),
      NOTIFY_NOT_OBJ),0;

  if (!GetStore())
  return notify_fail(
    lambda(0,
      ({SF(SkSay),
	   "Lo siento pero mi almacen está destrozado. Necesita unos cuantos"
	   "arreglos...\n"})),
    NOTIFY_NOT_VALID),0;

  if (!str || str == "")
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "¿Qué es lo que quieres comprar?\n"
        })),
      NOTIFY_NOT_VALID),0;

  str = norm_id( str ); // norm first
  str += " "; // add blank if someone used ... and
  spl = explode( str, " y ") - ({ "" });
  ret = ({});

  for ( count = 0; count < sizeof( spl ); count++ )
  {
     str = norm_id( spl[count] ); // norm it again
    if ((number = to_int(str)) > 0 && to_string(number) == str)
      ret += buy_number(number,force) || ({});
    else
    {
      spl2 = explode( str, " " );
      if ( ( ( number = to_int( spl2[0] ) ) > 0 ) && to_string(number) == spl2[0])
      {
        if ( ob = present( str, GetStore() ) )
        {
          ob->SetLastAmount(0); // fix for unit-problem
          number = 1;
        }
        else
        {
          str = implode( spl2[1..], " " );
          if (ob=present( str, GetStore()))
          {
            // if it is an unit and not the plural id was given...
            // sort of a hack, may cause buying the wrong item, but as
            // a loop for buying 200 unit-item causes a too long eval
            // due to joining units, better than nothing.

            if ( sizeof(plids = ob->QueryPluralIds()) )
            {
              str = to_string(number)+" "+plids[0];
              number = 1;
              ob->SetLastAmount(0);
            }
          }
          else
          {
            if (str[<1]=='s') str[<1]=' ';
          }
        }
      }
      else
      {
        number = 1;
        if ( ( ob = present( str, GetStore() ) ) && ( ob->QueryAmount() ) )
        {
          if ( sizeof(plids = ob->QueryIds()) )
          {
            str = to_string(number)+" "+plids[0];
            ob->SetLastAmount(0);
          }
        }
      }

      for (count2 = 1; count2 <= number; count2++ )
        ret += buy_string(str,force) || ({});
    }
  }

  if ( sizeof ( ret ) )
    return ret;
  else
    return 0;
}


public int do_sell(string str)
// Called when the customer types 'sell'.
{
  mixed found, tmp;
  object env;
  int i,price;
  string msg, msg2, emsg;

  if (msg = CantAttend()) return notify_fail(msg, NOTIFY_NOT_VALID);
  if (!env = TP)
    return 0;

  Say(CustomerName(1)+" quiere "+(QuerySell()||"vender")+" "+
      (str||"algo")+".\n",({TP}),1);
  if (!sk_in_shop())
    return 0;	// Check if the shopkeeper is in the shop and
		// if not, give a message to the player.
  if (!QuerySell())	// you can't sell anything in here
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "No va a comprar ningún objeto.\n"
        })),
      NOTIFY_NOT_OBJ),0;
  if (!str)
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "¿Qué es lo que quieres vender?\n"
        })),NOTIFY_NOT_VALID),0;

  if (sscanf(str,"%s por %d",str,price)==2
      &&!QueryMarket())
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
	  "No quiero regatear. Véndemelo por su precio justo o vete a "
	  "otra tienda.\n"
          })),NOTIFY_NOT_VALID),0;

  found = searchm(TP,str, SEARCH_INV|SM_CMULTI|SM_REALLY|WizSearch());
  found = sort_findings(found, sort_f_prop(P_NODROP));
  if (sizeof(found[FOUND_IDS])!=0)
  {
    found = searchm(TP,str+(str[<1..<1]=="s"?"":"s"), SEARCH_INV|SM_CMULTI|SM_REALLY|WizSearch());
    found = sort_findings(found, sort_f_prop(P_NODROP));
  }
  msg = found[-FOUND_SINGLE]
        ? "No encuentras tantos objetos como pretendías "+QuerySell()+".\n"
        : "";
  emsg = found[-FOUND_SINGLE]
         ? CustomerName(1)+
           " no encuentra tantos objetos como quería "+QuerySell()+".\n"
         : "";

  if (i = sizeof(tmp = found[FOUND_IDS]))
    {
      if (i == 1)
        msg2 = tmp[0];
      else
        msg2 = implode(tmp[0..<2], ", ")+" o "+tmp[<1];
      emsg += CustomerName(1)+" no encuentra "+msg2+" para "+QuerySell()+".\n";
      msg+= "No encuentras "+msg2+" para "+QuerySell()+".\n";
    }
  if (i = sizeof(tmp = found[FOUND_NOTHANDLE]))
    {
      tmp = fold_objlist(tmp);
      if (i == 1)
        msg2 = tmp[0];
      else
        msg2 = implode(tmp[0..<2], ", ")+" o "+tmp[<1];
      emsg += CustomerName(1)+" intenta "+QuerySell()+" algo sin éxito.\n";//depositar
      msg += "No puedes "+QuerySell()+" eso.\n";//tirar
    }
  if (!(sizeof(found[FOUND_SINGLE])))
    return notify_fail(
      msg
      ?lambda(0,
        ({CL_PROGN,
          ({SF(Say),
            emsg,
            quote(({TP}))
          }),
          ({SF(Write),
            msg,
            1
          })
        }))
      :"No tienes ningún "+str+" para "+QuerySell()+".\n",
      NOTIFY_NOT_VALID),0;

  if (msg != "")
    {
      Write(msg,1);
      Say(emsg,({TP}));
    }
  if (!sell_items(found[FOUND_SINGLE],price))
  // sell all items in the array, give messages
  // and errors like 'I don't buy such items.'
    return 0;

  return 1;
}

public int do_appraise(string str)
// Action called when a player types "appraise".
{
  object ob;
  int price,maxprice;
  string msg;
  
  if (msg = CantAttend()) return notify_fail(msg, NOTIFY_NOT_VALID);
  Say(CustomerName(1)+" pregunta "+(SkShort()||"alguien")+" para "+
      (QueryAppraise()||"apreciar")+" "+(str||"algo")+".\n",({TP}));
  if (!sk_in_shop())
    return 0;	// Check if the shopkeeper is in the shop and
		// if not, give a message to the player.
  if (!QueryAppraise())		// you can't appraise anything in here
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "Lo siento, no soy ningún perista.\n"
        })),
      NOTIFY_NOT_OBJ),0;
  if(!str)
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "¿Que objeto quieres que evalúe?\n"
        })),
      NOTIFY_NOT_VALID),0;
  if(!ob = present(str, TP))
    return notify_fail(
       lambda(0,
         ({SF(SkSay),
         "Lo siento "+CustomerName()+", no tienes ningun objeto llamado '"+str+"'.\n"})),
         NOTIFY_NOT_VALID),0;

  if(blueprint(ob) == "/obj/money")
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "Lo siento "+CustomerName()+", si quieres negociar con dinero\n"
          "debes ir al banco.\n"
        })),NOTIFY_NOT_VALID),0;

  // check if we trade with this item
  if(!CheckTrade(ob) || !CheckLivingTrade(ob))
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "No negocio con "+ob->Short()+".\n"
        })),NOTIFY_NOT_VALID),0;
  price = (price = GetPrice(ob))>(maxprice = GetMaxPrice(ob))
          ?maxprice:price;
  SkSay("Te daré "+MONEY_DEMON->QueryValueString(price,QueryValuta())+
        " por "+ob->Short()+".\n");
  return 1;
}

public int do_identify(string str)
// Called when the customer types 'identify'.
{
  object ob;
  string s,msg;
  if (msg = CantAttend()) return notify_fail(msg, NOTIFY_NOT_VALID);
  Say(CustomerName(1)+" quiere "+(SkShort()||"a alguien")+" para "+
      (QueryIdentify()||"identificar")+" "+(str||"algo")+".\n",({TP}),1);
  if (!sk_in_shop())
    return 0;	// Check if the shopkeeper is in the shop and
		// if not, give a message to the player.
  if (!QueryIdentify())		// you can't identify anything in here
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "No identifico objetos.\n"
        })),
      NOTIFY_NOT_OBJ),0;
  if(!str)
    return notify_fail(
      lambda(0,
        ({SF(SkSay),"¿Qué quieres que identifique?\n"})),
      NOTIFY_NOT_VALID),0;

  if(!ob = search(TP,str,SEARCH_INV|SM_OBJECT|SM_IGNLIGHT))
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "Lo siento "+CustomerName()+", no tienes ningún objeto llamado '"+str+"'.\n"
        })),NOTIFY_NOT_VALID),0;

  if(!check_money(round_value(GetPrice(ob) / 10)))
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
	  "¡No me hagas perder el tiempo con objetos como éste!\n"
        })),NOTIFY_NOT_VALID),0;

  if (ob->QueryMagic()&&intp(ob->QueryMagic()))
    msg = "Este es un objeto mágico. No se si tiene algo especial o no.\n";
  else
    msg = "No hay nada especial en el objeto.\n";
  if (member(inherit_list(ob),"/std/equipment.c")!=-1)
    switch(ob->QuerySize())
      {
       case P_SIZE_SMALL:
	msg+="Es un objeto bastante pequeño.\n";
	break;
       case P_SIZE_MEDIUM:
	msg+="Es un objeto mediano.\n";
	break;
       case P_SIZE_LARGE:
	msg+="Es un objeto bastante grande.\n";
	break;
       case P_SIZE_GENERIC:
	msg+="Este objeto es de un tamaño genérico.\n";
	break;
       default:
	msg+="Este objeto tiene un tamaño extraño... no se "
             "quien lo creó.\n";
      }
  SkSay(msg);

  return 1;
}

public int do_show(string str)
// Called when the customer types 'show'.
{
  object ob,*obs;
 string s, msg2;
  mixed msg;
  int number;
  mapping list;

  if (msg = CantAttend()) return notify_fail(msg, NOTIFY_NOT_VALID);
  Say(CustomerName(1)+" quiere que "+(SkShort()||"alguien")+"  "+
      (QueryShow()||"le muestre")+" "+(str||"algo")+".\n",({TP}),1);
  if (!sk_in_shop())
    return 0;	// Check if the shopkeeper is in the shop and
		// if not, give a message to the player.
  if (!QueryShow())		// you can't show anything in here
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "No enseño mi género.\n"
        })),
      NOTIFY_NOT_OBJ),0;
  if(!str)
    return notify_fail(
      lambda(0,
        ({SF(SkSay),"¿Qué quieres que te muestre?\n"})),
      NOTIFY_NOT_VALID),0;

  if (!GetStore())
  return notify_fail(
    lambda(0,
      ({SF(SkSay),
        "Lo siento pero mi almacén esta destrozado. Primero necesita ser "
	"reconstruido.\n"
      })),
    NOTIFY_NOT_VALID),0;

  if ((number = to_int(str)) > 0 && to_string(number) == str)
    {
      if (!list = TP->Query(P_LASTLIST))
        return notify_fail(
          lambda(0,
            ({SF(SkSay),"Todavía no te enseñado mi lista.\n"})),
            NOTIFY_NOT_VALID),0;
      if (!member(list,number))
        return notify_fail(
          lambda(0,({SF(SkSay),"No tengo ese objeto en el almacén.\n"})),
          NOTIFY_NOT_VALID),0;
      if (!sizeof(obs = filter(list[number]-({0}),
                  lambda(({SYM(o)}),({SF(==),({SF(environment),SYM(o)}),
                                             GetStore()})))))
        return notify_fail(
          lambda(0,({SF(SkSay),"Ya no me quedan objetos de ese tipo.\n"})),
          NOTIFY_NOT_VALID),0;
      ob = obs[0];
    }
  else if(!ob = search(GetStore(),str,SEARCH_INV|SM_OBJECT|SM_IGNLIGHT))
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "No tengo ningún objeto llamado '"+str+"'.\n"
        })),NOTIFY_NOT_VALID),0;

  msg = ob->QueryLong()||"Este objeto no es nada.\n";
  if (pointerp(msg)) msg = msg[0];
  if (member(inherit_list(ob),"/std/equipment.c")!=-1)
    switch(ob->QuerySize())
      {
       case P_SIZE_SMALL:
	msg+="Es un objeto pequeño.\n";
	break;
       case P_SIZE_MEDIUM:
	msg+="Es un objeto mediano.\n";
	break;
       case P_SIZE_LARGE:
	msg+="Es un objeto grande.\n";
	break;
       case P_SIZE_GENERIC:
	msg+="Este objeto es de tamaño generico.\n";
	break;
       default:
	msg+="Este objeto tiene un tamaño estraño... No sabria decir quien "
             "lo creó.\n";
      }
  Write(SkShort(1)+" te enseña "+ob->Short()+":\n"+ob->Long());
  Say(SkShort(1)+" le enseña "+ob->QueryShort()+" a "+CustomerName()+".\n",({TP}));
  return 1;
}

protected void list_done(string str)
{
  mapping list;
  int *idx,i,diff,len,j,yahoo, k, l;
  string *linelist,*res,short, *pstr1, pstr2;
  object ob;
  if (!TP)
    return 0;
  list = TP->Query(P_LASTLIST);
  if (!list||!sizeof(list))
    {
      SkSay(str?"Lo siento "+CustomerName()+
            ", no vendo articulos de ese estilo en mi tienda.\n"
            :"Lo siento "+CustomerName()+", el almacen está completamente vacío.\n");
      return;
    }

  Say(SkShort(1)+" enseña una lista a "+CustomerName()+".\n",({TP}));
  // devide the list in two parts and if the number of the lines is odd,
  // then show more lines on the left side.
  res = ({});
  k=4;
  k+=sizeof(m_indices(list));

  for (l=0; l<k; l++)
    res+=({""});

  k=0;
  if (TP->CanSee())
    {

      idx = sort_array(m_indices(list),SF(>));
      //first create all lines (including wrapping)

      res[k++]=SkShort(1)+" te enseña una lista:";
      res[k++]="Los precios de los artículos están expresados en cobre.";
      k++;
      res[k++]="   Num        Precio    Artículo";
       yahoo=0;
       for (i=0;i<sizeof(idx);i++)
	{
          ob = list[idx[i]][0];
          if (!ob || !objectp(ob))
            continue;

          res[k]+=STR->radjust(to_string(idx[i]),5);
	  for (j=0;j<13-strlen(to_string(convert_value(GetPrice(ob))));j++)
	     res[k]+=".";
	  res[k]+=" ";
	  res[k]+=STR->ladjust(to_string(convert_value(GetPrice(ob))),1);
	  res[k]+=" .. .. ";
	  res[k++]+=STR->radjust(ob->QueryShort(),strlen(ob->QueryShort())>22?22:strlen(ob->QueryShort())) + ".";
	  yahoo=0;
	}
 }
  else
    res = ({SkShort(1)+" hace algo."});
  STR->smore(res,TP->QueryPageSize());
}

public int do_list(string str)
// Called whenever a customer types 'list' in here.
{
  string msg = CantAttend();
  if (msg) return notify_fail(msg, NOTIFY_NOT_VALID);
  Say(CustomerName(1)+" pregunta a "+(SkShort()||"alguien")+
      " por la lista de precios.\n",({TP}),1);

  if (!sk_in_shop())
    return 0;	// Check if the shopkeeper is in the shop and
		// if not, give a message to the player.

  if (!QueryList())	// you can't call for a list in here
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          "No tengo ninguna lista disponible...\n"
        })),
          NOTIFY_NOT_VALID),0;

  if (!GetStore())
  return notify_fail(
    lambda(0,
      ({SF(SkSay),
        "Lo siento pero el almacen está destrozado.\n"
      })),
    NOTIFY_NOT_VALID),0;

  if (str=="todo"||str=="todos los"||str=="todas las")
    str = 0;
    //[t] Quito esto:
//  SkSay("Espera un momento, voy al almacen....\n");

  get_list(str);
  return 1;
}
/*
public int test_put(string str) {
	string *s;
	if (!str) {
		return 0;
	}
	s = lower_case(str);
	s = explode(str, " ");
	if (sizeof(s) < 2) {
		return 0;
	}

	if (member(s, "cubo")!= -1) {
		write("Para desechar algo usa el comando \"desechar\"\n");
*/

public int do_toss(string str)
// This function is called when a player 'toss'es something into the
// dustbin.
{
  object ob, *obs;
  mixed *m;
  mixed error;
  string *s;
  int i;

  Say(CustomerName(1)+" quiere destruir "+(str||"algo")+" en el "
      "cubo de la basura.\n",({TP}));

  if (!QueryDustbin())
    return notify_fail(
      lambda(0,
        ({CL_PROGN,
          ({SF(Write),
            "¡Aquí no hay ningun cubo de basura!\n"
          }),
          ({SF(Say),
            CustomerName(1)+" busca desesperadamente un cubo de basura, pero"
	       "no lo encuentra...\n",
            quote(({TP}))
          })
        })),NOTIFY_NOT_VALID),0;

  if (!str)
    return notify_fail(
      lambda(0,
        ({CL_PROGN,
          ({SF(Write),
            "¿Qué quieres tirar al cubo de la basura?\n"
          }),
          ({SF(Say),
            CustomerName(1)+" mira al cubo de la basura como si quisiera tirar "
	       "algo...\n",
            quote(({TP}))
          })
        })),NOTIFY_NOT_VALID),0;

  m = searchm(TP, str, SEARCH_INV|SM_MULTI) || ({});
  obs = m[FOUND_SINGLE] || ({});
  if (sizeof(m[FOUND_CLASS]))
  {
    for (i = 0; i < sizeof(m[FOUND_CLASS]); i++)
      if (sizeof(m[FOUND_CLASS][i]))
      {
        obs -= m[FOUND_CLASS][i][0..0];
        obs += m[FOUND_CLASS][i][0..0];
      }
  }
  if (sizeof(m[FOUND_MULTI]))
  {
    for (i = 0; i < sizeof(m[FOUND_MULTI]); i++)
    {
      if (sizeof(m[FOUND_MULTI][i]) < 2)
	continue;
      error = m[FOUND_MULTI][i][0];
      if (!error)
        error = sizeof(m[FOUND_MULTI][i])-1;
      obs -= m[FOUND_MULTI][i][1..error];
      obs += m[FOUND_MULTI][i][1..error];
    }
  }

  if(!sizeof(obs))
    {
      if (TP->CantSee())
        return notify_fail(
          lambda(0,
            ({CL_PROGN,
              ({SF(Write),""
              }),
              ({SF(Say),
                ({CustomerName(1)+" parece tener problemas con "+
                  TP->QueryPossessive()+" ojos.\n",""}),
                quote(({TP}))
              })
            })),NOTIFY_NOT_VALID),0;
      return notify_fail(
        lambda(0,
          ({CL_PROGN,
            ({SF(Write),
              "No puedes encontrar eso en tu inventario.\n"
            }),
            ({SF(Say),
              CustomerName(1)+" no puede encontrar "+str+" en "+TP->QueryPossessive()+
              " mochila.\n",
               quote(({TP}))
            })
          })),NOTIFY_NOT_VALID),0;
    }

  if(sizeof(filter(obs, SF(query_once_interactive))))
    return notify_fail(
      lambda(0,
        ({SF(Say),
          "No puedes ir por la vida tirando jugadores a la basura..."
	  "¡por muy molestos que sean!\n"
        })),NOTIFY_NOT_VALID),0;

  s = ({ });
  for (i = 0; i < sizeof(obs); i++)
  {
    error = obs[i]->Query(P_NODROP);
    if (!error)
      error = (ME_OK != (int)obs[i]->move(QueryDustbin(), M_SILENT));
    if (error)
    {
      Write(stringp(error) ? error
                           : ("No puedes tirar "+obs[i]->Short()+".\n"));
      obs[i] = 0;
    }
    else
      s += ({ obs[i]->Short() });
  }

  obs -= ({ 0 });
  s -= ({ 0, "" });
  if (!sizeof(obs))
  {
    notify_fail("No tiras nada.\n", NOTIFY_NOT_VALID);
    return 0;
  }

  if (sizeof(s))
  {
    Write(implode_list(s, "Tiras ", " a la basura.\n"));
    Say(implode_list(s, CustomerName(1)+" tira "," a la basura.\n"),({TP}));
  }
  map_objects(obs, "remove");
  map(obs - ({ 0 }), SF(destruct));
  Write(
"Una especie de masa verde y viscosa empieza a comerse (si es que a \"eso\" se\n"
"le puede llamar comer) lo que acabas de tirar... no contenta con sus actos,\n"
"regurgita lo que era tu estimado objeto y lo vuelve a engullir... Aunque\n"
"no tiene ojos, tienes la sensacion de ser observado con MUCHA hambre y\n"
"decides mirar hacia otro sitio...\n");

   return 1;
}


protected void clean_room()
// Check for items, which don't belong to the shop and remove them
// through an exit (best to the outside) or if they are of any
// value, put them into the store.
{
  object *inv;
  int i,j;
  status moved;
  string *idx,exit;
  mapping exits;

  i = sizeof(inv = all_inventory());
  // Don't do anything, if a player is in here. It might be one of
  // her/his items.
  if (sizeof(filter(inv,SF(interactive))))
    return;
  while(i--)
    if (inv[i]->QueryCreator()!=object_name(TO)
        &&(!query_once_interactive(inv[i])&&!inv[i]->QueryIsPlayer()))
      {
	if (living(inv[i])
            ||!inv[i]->QueryValue()
            ||!CheckTrade(inv[i]))
	  {
	    j = sizeof(idx = m_indices(exits = QueryExitsDest()));
            // search an exit where to throw out useless items
	    while(j--)
	      {
		if (stringp(exits[idx[j]]))
		  if (!exit
                      ||!exits[idx[j]]->QueryIndoors())
		    exit = exits[idx[j]];
		if (exit&&!exit->QueryIndoors())
		  break;
	      }
	    if (!exit&&!living(inv[i])&&!query_once_interactive(inv[i]))
	      {
		inv[i]->remove();
		if (inv[i]) destruct(inv[i]);
	      }
	    else
	      {
                moved = 1;
		inv[i]->move(exit,M_SILENT);
	      }
	  }
	else
	  PutInStore(inv[i]);
      }
  if (moved&&exit)
    tell_room(exit, ({ MSG_SEE, W(SkShort(1)+
              " llega con un delantal y una escoba y empieza a barrer... "
              "levanta una raída alfombra (con muchos bultos) y empieza a"
	      "conducir (no sin cierta destreza) lo que ha barrido debajo de "
	    "la susodicha alfombra.\n") }));
}


/*
* Overriding functions of /std/room
*/

public string QueryIntLong (string arg)
{
  if (arg) return (::QueryIntLong(arg));
  return ((::QueryIntLong())||"Estás en una tienda.\n")+
         "Ves una nota en la pared.\n";
}

/*
* reset, create, init, notify_enter
*/

public void reset()
{
  object st;
  if (object_name(TO)==MYFILE) return;
  if (st = GetStore()) st->GoOutPeople();
  //room
  ::reset();
  reset_cash();
  clean_room();
  if (st)
    st->reset();
}

public void create()
{
  ::create();
  if (object_name(TO)==MYFILE) return;

  CanList(1);
  CanIdentify(1);
  CanAppraise(1);
  CanBuy(1);
  CanSell(1);
  CanShow(1);

  AddDetail("nota",SF(detail_sign));
  //AddDetail("tendero",SF(detail_shopkeeper)); <- bug!!!

  Pno_shopkeeper = 0;

  SetIndoors(1);
  SetIntBright(MAX_SUNBRIGHT/5);
  AddExit ("almacen",SF(go_store));
  AddReadMsg("nota",SF(detail_sign));

  SetBuyFactor(300);
  SetDynamic(DYNAMIC_DEFAULT);
  SetMinCash(DEFAULT_MIN_CASH);
  SetCash(DEFAULT_MIN_CASH);
  SetStore();
  SetShopkeeper();
  SetDustbin();
  SetCloseTime(S_CLOSED_AT_NIGHT);

  Psigndescr = 0;

  call_out(SF(PayInsurances),1);
  // As we may be defined as market later on, try to pay the
  // insurances if we are.
  "/obj/lib/register"->Register(TO, "SHOP");
}

public void init()
{
  (::init());
  TP->Set(P_SELL_MUTEX, 0);
  if (QueryIdentify()) add_action("do_identify","identificar");
  if (QueryDustbin()) {
  	add_action("do_toss","desechar");
//  	add_action("test_put", "poner");
  }
  if (QueryList()) add_action("do_list", "lista");
  if (QuerySell()) add_action("do_sell", "vender");
  if (QueryAppraise()) add_action("do_appraise", "valorar");
  if (QueryBuy()) add_action("do_buy", "comprar");
  if (QueryShow()) add_action("do_show", "mostrar");
}

// prevent that someone enters the /std/shop

public int allow_enter(int method,mixed extra)
{
  if (object_name(TO) == MYFILE) return ME_NO_ENTER;
  return (::allow_enter(method,extra));
}

public void notify_leave(mixed to, int method, mixed extra)
{
  if (query_once_interactive(PO))
    PO->Set(P_LASTLIST,0);
  return (::notify_leave(to,method,extra));
}
