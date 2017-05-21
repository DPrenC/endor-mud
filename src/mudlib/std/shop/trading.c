/**
 * SIMAURIA '/std/shop/trading.c'
 */

#include <money.h>      // MONEY_DEMON, MONEY_LIB and such
#include <config.h>     // NOTIFY_...
#include <moving.h>
#include <properties.h>
#include <stdrooms.h>
#include <search.h>

inherit MONEY_LIB;  // money-functions

#define MIN_BUY_FACTOR   25

// shops with endless money
#define SSHOPS ({SHUTSHOP, SHOP})

#define TS_NOMONEY -1  // TestSell - Return-Values
#define TS_NOBUY   -2
#define TS_NOTRADE -3
#define TS_NOMOVE  -4
#define CALC_FEE(x) (x/3)||1

// general defines
#define INSURANCE(x) (x*4/5)
#define P_PRICE "shopprice" // the price a player wants for an item
#define P_OWNER "shopowner" // the player who sold this item
// P_PRICE and P_OWNER are just used for markets
#define P_LASTLIST "shoplist"

#define P_SELL_MUTEX (to_string(TO)+":is selling")

public mapping Powner_list;
// ([<uid of owner of items in the market>:<amount to pay to bank>])

private static int Pcash;
private static int Pbuy_factor, Pdynamic, Pmin_cash;
private static object *Pcurrentobjects;

/*
** Prototypes
** ==========
**
** /std/shop.c
*/

public status CheckTrade(object ob);
public int ModifyPrice(object ob, int price, string verb);
public varargs int GetMaxPrice(object ob);
protected status CheckLivingTrade(object ob);
public int QueryNoShopkeeper();
public string QueryBuy();
public string QueryList();
public string QueryAppraise();
public string QueryIdentify();
public string QuerySell();
public string QueryMarket();
protected void list_done(string str);

/*
** /std/shop/comm.c
*/

public object QueryShopkeeper();
public varargs string CustomerName(int cap);
public varargs string SkShort(int cap);
public int SkSay(string str);
public int SkEmote(mixed str);
public varargs void Write(mixed str,status ignlight);
public varargs void Say(mixed str,object *exclude,status ignlight);

/*
** /std/shop/articles.c
*/

public object GetStore();
public int PutInStore(object ob);

/*
** Prototypes End
** ==============
*/

public varargs string *QueryFValuta(int force)
{
  if (!force)
    return (QueryValuta());
  else
    return m_indices(MONEY_DEMON->QueryCoinTypes()||([]));
}

protected string ValueString(int x)
{
  return MONEY_DEMON->QueryValueString(x,QueryValuta());
}

protected string get_min_coin()
// Eval-time: 0
// Return the minimal coin (as string) to be used e. g. in the 'list'.
{
  object mdemon;
  int *vals,minval,i;
  string *mincoins;
  mdemon = load_object(MONEY_DEMON);
  vals = map(QueryValuta()||({}),
                   symbol_function("QueryCoinValue",mdemon));
  minval = NMB->min(vals);
  mincoins = ({});
  for (i=0;i<sizeof(vals);i++)
    if (vals[i]==minval)
      mincoins+=({QueryValuta()[i]});
  if (member(mincoins,"cobre")!=-1
      ||!sizeof(mincoins))
    return "cobre";
  return mincoins[0];
}

protected int convert_value(int copper)
// Convert the value (in copper) of an object to a value with the
// minimal coin (i. e. lowest value).
{
  int c,new;
  c = MONEY_DEMON->QueryCoinValue("cobre");
  if (!new = MONEY_DEMON->QueryCoinValue(get_min_coin()))
    return 0;
  return ((copper*c)/new+(copper*c%new!=0))||1;
}

protected int round_value(int copper)
// Return the value in copper coins, rounded so that it fits into
// the minimal coin.
{
  int c,new;
  c = MONEY_DEMON->QueryCoinValue("cobre");
  if (!new = MONEY_DEMON->QueryCoinValue(get_min_coin()))
    return 0;
  return ((copper*c)/new+(copper*c%new!=0))*new;
}

protected int modify_on_amount(object ob,int price)
// If we already have too much of these items, we'll buy them for much
// less money only.
{
  int i;
  if (!i = sizeof(GetStore()->GetEqual(ob)))
    return price;
  if (i>6) i = 6;   // put a limit to the decrease of value
  if (!price = price/(((i*i)/4)+1))
    price = 1;
  return price;
}

/* protected */ varargs int GetPrice(object ob,int price,status force)
// Returns the price for an object depending on the command. Modifications are
// done in here (e. g. ModifyPrice is called).
{
  string verb;

  if (!ob) return 0;

  verb = query_verb();

  if ( ( ob->QueryAmount() ) && ( verb==(QueryList()||"lista") ) )
    price = price||(int)ob->QueryValuePerUnit();
  else
    price = price||(int)ob->QueryValue();
/*
  if (  verb==(QuerySell()||"vender")
      ||verb==(QueryAppraise()||"valuar")
      ||force)
    verb = "vender";
  else if (  verb==(QueryBuy()||"comprar")
           ||verb==(QueryList()||"lista"))
    verb = "comprar";
  else
    verb = "ninguno";
*/
  if (!QueryMarket()||force)
    {
/*      price = ModifyPrice(ob, price, verb);	*/
      if (verb=="vender")   // only modify if the customer sells this item
        price = modify_on_amount(ob,price);
      // modify the price refering to the stack
      // of this item in the store
      if (verb=="comprar" || verb=="lista") {
      	price = ModifyPrice(ob, (price * Pbuy_factor) / 100, verb);
      }
    }
  else
    if (verb=="comprar" || verb=="lista")
      price = ob->Query(P_PRICE);
  if (price <= 0)
    price = 1;  // security
  else
    price = round_value(price)||1;
  return price;
}

public mapping SetOwnerList(mapping o)
{
  Powner_list = o;
  save_object(QueryMarket());
  return Powner_list;
}

public mapping QueryOwnerList()
{
  if (file_size(QueryMarket()+".o")>0)
    restore_object(QueryMarket());
  return Powner_list;
}

public mapping AddInsurance(object ob)
{
  string owner;
  if (!Powner_list)
    Powner_list = ([]);
  owner = ob->Query(P_OWNER);
  Powner_list[owner] = Powner_list[owner]+INSURANCE(GetPrice(ob,0,1));
  if (Powner_list[owner]<1)
    m_delete(Powner_list,owner);
  save_object(QueryMarket());
  return Powner_list;
}

public mapping RemoveInsurance(object ob)
{
  string owner;
  int price;
  if (!owner = ob->Query(P_OWNER))
    return Powner_list;
  BANKOBJECT->AddAccount(owner,ob->Query(P_PRICE));
  if (!Powner_list)
    Powner_list = ([]);
  Powner_list[owner] = Powner_list[owner]-INSURANCE(GetPrice(ob,0,1));
  if (Powner_list[owner]<1)
    m_delete(Powner_list,owner);
  save_object(QueryMarket());
  return Powner_list;
}

public void PayInsurances()
{
  mapping list;
  string *owner;
  int i;
  if (list = QueryOwnerList())
    {
      for (i = sizeof(owner = m_indices(list));--i>-1;)
        BANKOBJECT->AddAccount(owner[i],list[owner[i]]);
      rm(QueryMarket()+".o");
    }
}

/*
** SELLING ITEMS
** ============
*/

protected int TestSell(object ob,int price)
// Returns either:
// TS_NOMONEY: The shopkeeper ran out of money
// TS_NOBUY:   The shopkeeper won't buy such items
// TS_NOTRADE: The shopkeeper doesn't trade with this items
// or the calculated value, the player will get for this item
{
  int init_price,   // the price of ob defined by SetValue
      float_price;  // the price of ob after modifications depending on
            // the verb and ModifyPrice

  if (Pcash < 1 && member(SSHOPS, object_name(TO)) < 0)
    return TS_NOMONEY;

  //[a] bug? Su utilizaba P_NOBUY en lugar del P_NOSELL
  if (ob->Query(P_NOSELL))
    return TS_NOBUY;

  if (!CheckTrade(ob) || !CheckLivingTrade(ob))
    return TS_NOTRADE;

  if (ob->QueryNoDrop()||ob->QueryNoGive())
    return TS_NOMOVE;

  if (ob->Query(P_AUTOOBJECT))
    return TS_NOBUY;

  float_price = GetPrice(ob,price); // calculate the price the customer
                    // would get
  if (float_price < 1
      ||(!QueryMarket()
         &&ob->QueryValue()<MONEY_DEMON->QueryCoinValue(get_min_coin())))
                // don't buy worthless things
    return 0;

  return float_price > GetMaxPrice(ob)?GetMaxPrice(ob):float_price;
}

protected varargs int check_sell(object ob,int price)
{
  int res;
  res = TestSell(ob,price);
  if (res>0) return 1;
  if (res==TS_NOMONEY)
    notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "¡Lo siento "+CustomerName()+", no me queda más dinero!\n"
        }) ),
        NOTIFY_NOT_VALID);
  if (res==TS_NOBUY)
    notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No compro objetos de ese tipo.\n"
        }) ),
      NOTIFY_NOT_VALID);
  if (res==TS_NOTRADE)
    notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No compro objetos de ese tipo.\n"
        }) ),
      NOTIFY_NOT_VALID);
  if (res==TS_NOMOVE)
    notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "Lo siento "+CustomerName()+", este objeto no se va a mover.\n"
        }) ),
    NOTIFY_NOT_VALID);
  if (!res)
    notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No lo querría ni aunque me lo regalaran...\n"
        }) ),
      NOTIFY_NOT_VALID);
  return 0;
}

int is_greater(mixed *a, mixed *b)
{
 int i, j;
 for (i=0;i<10;i++)
   if (a[i]==" ") break;
 for (j=0;j<10;j++)
   if (b[j]==" ") break;
 return a[i]>b[j];
}

public string print_list(mixed *l)
{
  object *obs;
  string *strs2,str,*strs,*yahoo;
  int i, j, repeated;

  yahoo=({});
  j=0;
  repeated=0;
  obs = filter(l,SF(objectp));
  strs = filter(l-obs,SF(stringp));
  strs += map_objects(obs,"Short")-({0});
  if (!sizeof(strs)) return "";
  strs=sort_array(strs,SF(>));

  repeated=0;
  for (i=0;i<sizeof(strs)-1;i++)
  {
    if (strs[i]!=strs[i+1])
    {
      if (!repeated) yahoo+=({strs[i]});
      else
      {
        yahoo+=({strs[i]+"["+(repeated+1)+"]"});
        repeated=0;
      }
    }
    else repeated++;
  }
  if (repeated)
  {
    yahoo+=({strs[i]+"["+(repeated+1)+"]"});
    repeated=0;
  }
  else yahoo+=({strs[i]});

  //return implode(yahoo,", ");
  return implode(yahoo[0..<2],", ")+(sizeof(yahoo[0..<2])?" y ":"")+yahoo[<1];
//    return strs[<2]+(sizeof(strs[0..<2])?to_string(sizeof(strs[0..<2])):"");
}

public object* QueryCurrentObjects()
{
  return Pcurrentobjects||({});
}

public object* SetCurrentObjects(object *co)
{
  return Pcurrentobjects = co;
}

protected varargs void continue_sell(object *items,object env,int price)
{
  object *ok,*too_heavy,*not_empty,*too_big,*too_many,
         *too_expensive,*not_take,*not_trade,
         *to_destruct,*no_value;

  int amount,rc,i,repeated;
  object pl;
  mixed m_array;

  repeated=0;
  if (!TP || environment(TP) != TO) return;

  ok = ({});
  too_heavy = ({});
  too_big = ({});
  too_many = ({});
  not_empty = ({});
  too_expensive = ({});
  not_take = ({});
  not_trade = ({});
  to_destruct = ({});
  no_value = ({});
  amount = 0;
  items-=({0});
  if (!env->QueryIsPlayer())
    items+=({env});

  i = sizeof(items);
  while(i--)
    {
      if (sizeof(all_inventory(items[i])||({}))
          &&items[i]!=env)
        {
          not_empty+=({items[i]});
          continue;
        }
        if (!GetStore()->MayAddIntWeight(items[i]->QueryWeight()))
        {
            too_heavy+=({items[i]});
            continue;
        }
        if (!GetStore()->MayAddItem())
        {
            too_many+=({items[i]});
            continue;
        }
        if (!GetStore()->MayAddSize(items[i]->QuerySize()))
        {
            too_big+=({items[i]});
            continue;
        }

      switch(rc = TestSell(items[i],price))
    {
     case TS_NOMONEY:
      too_expensive+=({items[i]});
      break;
         case TS_NOBUY:
     case TS_NOTRADE:
      //[t] No comercio con dinero... mmm... mejor quito el mensaje
      if (member(inherit_list(items[i]), "/obj/money.c")==-1)
        not_trade+=({items[i]});
      break;
     case TS_NOMOVE:
      not_take+=({items[i]});
      break;
     case 0:
      no_value+=({items[i]});
      break;
     default:
      if (!QueryMarket())
        {
          amount+=rc;
              if (member(SSHOPS,object_name(TO))==-1)
                Pcash -= rc;
        }
      else if (TP)
        {
          items[i]->Set(P_PRICE,rc);
              items[i]->Set(P_OWNER,getuid(TP));
              AddInsurance(items[i]);
        }
      if (items[i]->Query(P_NOSELL)
              ||!QueryBuy())
        to_destruct+=({items[i]});
      rc = PutInStore(items[i]);
      if (rc != ME_OK) {
      	log_file("SHOP", sprintf("%s (%O): No se pudo mover el objeto %O: codigo: %d\n", ctime(), TP, items[i], rc));
      }
      switch (rc) {
      case ME_OK:
      	ok+=({items[i]});
      	break;
      case ME_TOO_HEAVY:
      	too_heavy += ({ items[i] });
      	break;
      case ME_TOO_MANY:
        too_many += ({ items[i] });
      	break;
      case ME_TOO_BIG:
        too_big += ({ items[i] });
      	break;
      default:
      	not_take += ({ items[i] });
      	break;
      }
    }
  }

  if (!QueryMarket())
    {
      if (sizeof(ok))
        {
          Pcurrentobjects = ok;
          AdjustMoney(TP,m_array = (mixed *)MONEY_DEMON->CreateMoney(amount,
                                                           QueryValuta()),0);
          Pcurrentobjects = 0;
          Write(
            SkShort(1)+" te coge "+print_list(ok)+
            " y te da "+MONEY_DEMON->QueryMoneyString(m_array)+
            ".\n",1);
          Say(
            ({SkShort(1)+" coge "+print_list(ok)+
              " de "+CustomerName()+" y da "+
              MONEY_DEMON->QueryMoneyString(m_array,10)+" a "+
              TP->QueryObjective()+".\n",
              "Algo pasa.\n"
            }),({TP}));
    }
    }
  else
    {

      Write(
        SkShort(1)+" te coge "+print_list(ok)+".\n",1);
      Say(
        ({SkShort(1)+" coge "+print_list(ok)+" de "+CustomerName()+".\n",
          "Algo pasa.\n"
        }),({TP}));
    }

  if (sizeof(too_heavy))
    SkSay(CustomerName()+". "+
      capitalize(print_list(too_heavy))+" "+
      (sizeof(too_heavy)>1?"no caben":"no cabe")+" en el almacén.\n");
  if (sizeof(too_many))
    SkSay(CustomerName()+". "+
      capitalize(print_list(too_many))+" "+
      (sizeof(too_many)>1?"no caben":"no cabe")+" en el almacén.\n");
  if (sizeof(too_big))
    SkSay(CustomerName()+". "+
      capitalize(print_list(too_big))+" "+
      (sizeof(too_big)>1?"no caben":"no cabe")+" en el almacén.\n");
  if (sizeof(too_expensive))
    SkSay("No tengo suficiente dinero para pagar "+print_list(too_expensive)+
              ", "+CustomerName()+".\n");
  if (sizeof(not_trade))
    SkSay("No comercio con "+print_list(not_trade)+", "+
              CustomerName()+".\n");
  if (sizeof(not_take))
    SkSay("No puedo cogerte "+print_list(not_take)+", "+
              CustomerName()+".\n");
  if (sizeof(no_value))
    SkSay(capitalize(print_list(no_value))+" "+
      (sizeof(no_value)>1?"no tienen":"no tiene")+" ningún valor, "+
      CustomerName()+".\n");
  if (i = sizeof(to_destruct))
    while(i--)
      {
    to_destruct[i]->remove();
    if (to_destruct[i]) destruct(to_destruct[i]);
      }

  rc = 0;
  if (i = sizeof(not_empty))
    {
      SkSay("Oh, "+CustomerName()+". "+
        capitalize(print_list(not_empty))+" "+
        (i>1?"no están vacíos":"no está vacío")+". Déjame ver si puedo comprar algo"
        "de lo que está dentro.\n");
      while(i--)
      {
        call_out(SF(continue_sell),i+1,all_inventory(not_empty[i]),
                 not_empty[i],price);
    rc = 1;
      }
    }
  TP->Set(P_SELL_MUTEX, rc);
}

protected varargs int sell_items(object *items,int price)
// Sell all items given in the array and do the checks if we may
// buy the items or not.
{
  int i;
  if (!items || (sizeof(items) < 1))
    return notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No tienes nada de eso.\n"
        }) ),
      NOTIFY_NOT_VALID);

  if (!i = sizeof(filter(items,SF(check_sell),price)))
    return 0;

  if (TP->Query(P_SELL_MUTEX))
  {
    notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "Espera, "+CustomerName()+", estoy en medio de una transacción...\n"
        }) ),
      NOTIFY_NOT_VALID);
    return 0;
  }
  TP->Set(P_SELL_MUTEX, 1);
  call_out(SF(continue_sell),1,items,TP,price);
  // to prevent Too long evaluation
  return 1;
}

/*
** BUYING ITEMS
** ============
*/

/* protected */ varargs int check_money(int amount, status no_action,status force)
// Checks the player for the amount of money and reduces the money of enough
// is present. Otherwise the player will get an error message.
// If 'force' is !=0, the player accepted to pay a fee, if (s)he hasn't the
// correct money.
{
  mixed paying;
  int fee;

  if (!TP || (!QueryShopkeeper()&&!QueryNoShopkeeper())) return 0;
    // Program error

  if (force) amount+=CALC_FEE(amount);
  if (QuerySomeonesValue(TP) < amount)
    return notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No tienes suficiente dinero.\n"
        })),NOTIFY_NOT_VALID);

  if (QuerySomeonesValue(TP,QueryFValuta(force)) < amount)
    return notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No comercio con ese tipo de moneda.\n"
          "Si de todas maneras quieres "+QueryBuy()+"lo y estas dispuesto\n"
          "a pagar una pequeña cantidad por las molestias, escribe:\n"+
          QueryBuy()+" realmente 'objeto a "+QueryBuy()+"'.\n"
        })),NOTIFY_NOT_VALID);

  if (no_action) return 1;

  if (member(SSHOPS,object_name(TO))==-1)
    Pcash += amount;
  paying = PayValue2(TP, amount,QueryFValuta(force));
  if (paying == MONEY_CANT_PAY)
    return notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No tienes suficiente dinero.\n"
        })),NOTIFY_NOT_VALID);
  if (paying == MONEY_NEGATIVE)
    return notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "Lo siento "+CustomerName()+", tu dinero no parece tener buena pinta...\n"
        })),NOTIFY_NOT_VALID);

  if (amount)
    {
      Write("Pagas "+paying[0] +
         (paying[1] ? " y recibes "+paying[1] : "")+
         ".\n",1);
      Say(SkShort(1)+" coje algo de dinero que "+CustomerName()+" le ofrece.\n",({TP}));
    }
  else
    Write("No pagas nada.\n");
  return 1;
}

protected varargs int buy_routine(object ob,int force)
// In this function the player will receive the object he wanted to buy, if he
// can afford it, and if he can carry it.
{
  if (!CheckTrade(ob) || !CheckLivingTrade(ob))
    return notify_fail(
      lambda(0,
        ({CL_PROGN,
          ({
            CL_PROGN,
            ({
              SF(SkSay),
              "¡Oh, no comercio con "+ob->QueryShort()+"!\n"
            }),
            ({
              SF(Say),
              SkShort(1)+"quita "+ob->QueryShort()+" del almacen.\n"
            })
          }),
          ({
            SF(destruct),
            ob
          })
      })),NOTIFY_NOT_VALID);

  // Test coins of customer.
  if (!check_money(GetPrice(ob), 1,force))
    return 0;

  // Check if player can carry the item.
//  dtell("nyh",sprintf("%O->allow_enter(%O) = %O\n",TP, ob, TP->allow_enter(ob)));

  if (   !TP->MayAddIntWeight(ob->QueryWeight())
      || !TP->MayAddItem()
      || !TP->MayAddSize(ob->QuerySize())
     )
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          CustomerName()+", no podrás arrastrar eso.\n"
        })),NOTIFY_NOT_VALID);

  // Get coins from customer.
  Pcurrentobjects = ({ob});
  if(!check_money(GetPrice(ob),0,force))
    return 0;
  Pcurrentobjects = 0;

  // Handle item.
  if (QueryMarket())
    {
      RemoveInsurance(ob);
      ob->Set(P_PRICE,0);
      ob->Set(P_OWNER,0);
    }

  if (ob->move(TP, M_GIVE) == ME_OK) {
    Write(SkShort(1)+" te da "+ob->Short()+".\n",1);
    Say(SkShort(1)+" da "+ob->Short()+" a "+CustomerName()+".\n",({TP}));
  }
  else if (ob->move(environment(TP), M_SILENT) == ME_OK) {
    Write(SkShort(1) + " deja tu mochila en el suelo.\n");
    Say(SkShort(1)+" deja "+ob->Short()+" para "+CustomerName()+" en el suelo.\n", ({TP}));
  }
  else { // Esto seguro que trae problemas.
    ob->move(environment(TP), M_NOCHECK);
    Say(SkShort(1)+" deja "+ob->Short()+" para "+CustomerName()+" en el suelo.\n");
  }
  return 1;
}

protected varargs object *buy_string(string str, int force)
// Buy an item refering to its id.
{
  object *sold;
  int number, i;
  mixed found, tmp;
  string msg, msg2;
  number = 0;
  found = searchm(GetStore(), str,
                  SM_LOCATE|SM_CMULTI|WizSearch(),
                  symbol_function("CheckList",GetStore()));
  found = sort_findings(found, sort_f_prop());

  msg = found[-FOUND_SINGLE]
        ? "no tengo tantos objetos en el almacen."
        : "";

  if (i = sizeof(tmp = found[FOUND_IDS]))
    {
      if (i == 1)
        msg2 = tmp[0];
      else
        msg2 = implode(tmp[0..<2], ", ")+" or "+tmp[<1];
      msg += "No tengo ningun "+msg2+" para vender.\n";
    }

  if (!(sizeof(found[FOUND_SINGLE])))
    return notify_fail(
      lambda(0,
        ({SF(SkSay),
          msg
        })),NOTIFY_NOT_VALID),0;

  if (msg != "")
    SkSay(msg);

  if (!sizeof(sold = filter(found[FOUND_SINGLE], SF(buy_routine),force))) return 0;
  return sold;
}

protected varargs object *buy_number(int number,int force)
// Buy item <number> from store. But take care if someone already buyed an item
// in the meantime, to ensure, that our customer really gets what he wants to
// have and not something completely different.
{
  string *idx;
  int position;
  mapping last_list;
  // ([<number>:({<objectp>})])
  object *items,ob;
  int i;

  if (!TP) return 0;
  if (!last_list = TP->Query(P_LASTLIST))
    return notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No te he mostrado mi lista de objetos..\n"
        })),NOTIFY_NOT_VALID),0;

  if (!member(last_list,number))
    return notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          CustomerName(1)+", ese objeto ("+to_string(number)+
          ") no aparecía en la lista que te he mostrado.\n"
        })),NOTIFY_NOT_VALID),0;

  i = sizeof(items = last_list[number]);

// [Nyh] items es un array de objetos iguales, aqui busca si hay alguno en el
//       almacen y si lo encuentra lo guarda en ob y es el que nos va a dar.
  while(i--&&!ob)
    if ( items[i] && environment(items[i])==GetStore()) ob = items[i];
//
  if (!ob)
    return notify_fail(
      lambda(0,
        ({
          SF(SkSay),
          "No me queda ningun artículo de ese tipo en el almacén.\n"
        })),NOTIFY_NOT_VALID),0;


  if ( ob->QueryAmount() )
  {
    idx = ob->QueryIds();
    if ( sizeof( idx ) )
      ob->id(idx[0]);
    ob->SetLastAmount(1);
  }

  return buy_routine(ob,force)?({ob}):0;
}

// [Nyh] Aqui se supone que me llega en items un array de objetos
//	 Y str es la string que metio el tio al lista string
protected void list_evaluated(object *items,string str)
{
  object store;
  mapping list,inv;
  int i;

  // list: ([<number>:({<objectp>})])
  /*([
	6:({[/std/thing#14105],[/std/thing#14106],[/std/thing#14107]}),
	2:({[+simauria/comun/objeto/arma/arma_rnd#14096]}),
	5:({[+simauria/comun/objeto/arma/daga#14098]}),
	1:({[/std/thing#14108],[/std/thing#14109]}),
	4:({[+simauria/comun/objeto/proteccion/amd_cutre#14099]}),
	3:({[+simauria/comun/objeto/arma/claymore#14097]})
  ])*/

  // inv:  (["<short>#<value>#<size>":({<objectp>})])
  string *shorts;

  store = GetStore();
  inv = store->GroupInventory(items);
//  if (find_object("nyh")) dtell("nyh",sprintf("inv = %O\n",inv));
  shorts = sort_array(m_indices(inv),SF(>));
  list = ([]);
  for (i=1;i<sizeof(shorts)+1;i++)
    list[i]=inv[shorts[i-1]];
  if (TP)
    TP->Set(P_LASTLIST,list);
  list_done(str);
}

// [Nyh] esta funcion se llama directamente cuando un living escribe 'listar'
// aqui se hace todo lo del listar (menos los chekeos de si se puede o no, que ya estan hechos)
// tb se le pasa el texto al player y todo...
// si str = 0 es un listar todo, si no... pues solo lista str.
protected void get_list(string str)
{
  object *items,store;
  mixed *storeinv;
  if (!TP) return;
  store = GetStore();
  // esta linea que viene es la que recoge los objetos que hay en el almacen pa vender
  //con lo cual es lo que tengo q cambiar.
  //Actualmente SearchObjects suele acabar devolviendo
  // Locate(pattern,SM_MULTI|SM_IGNLIGHT), o si es un mapping solo los indices.
  storeinv = store->SearchObjects(str)||({});
  if (sizeof(storeinv) && pointerp(storeinv[0]))
    storeinv = storeinv[0];
  list_evaluated(storeinv,str);
}

public int SetBuyFactor(int factor)
// Percentage how much more you have to pay for an item you sold in here.
{
  if (factor < MIN_BUY_FACTOR)
    return Pbuy_factor = MIN_BUY_FACTOR;
  else
    return Pbuy_factor = factor;
}

public int QueryBuyFactor()
{
  return Pbuy_factor;
}

public int SetDynamic(int dy)
// This handles how fast the cash will be restored for the shop.
{
  if (dy < 0 || dy > 100)
    return Pdynamic;
  else
    return Pdynamic = dy;
}

public int QueryDynamic()
{
  return Pdynamic;
}

public int SetMinCash(int c)
// Minimum amount of cash for the shop.
{
  return Pmin_cash = c;
}

public int QueryMinCash()
{
  return Pmin_cash;
}

public int SetCash(int i)
{
  return Pcash = i;
}

public int QueryCash()
{
  return Pcash;
}

public void reset_cash()
{
  int add_cash;

  if (member(SSHOPS,object_name(TO))==-1)
    if (Pcash < Pmin_cash)
      {
        add_cash = Pmin_cash * Pdynamic / 100;
        Pcash += add_cash;
      }
}
