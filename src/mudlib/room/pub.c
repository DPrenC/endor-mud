/**
 * SIMAURIA '/room/pub.c'
 */
/*
             AddDrink(string nombre, string articulo,
                      int vida, int alcohol, int sed, int valor,
                      string mensaje);
             AddFood(string nombre, string articulo,
                     int vida, int hambre, int valor,
                     string mensaje);
             AddSpecial(string nombre, string articulo, int vida, int alcohol,
                       int hambre, int sed, int valor, string mensaje)
   (interna) AddMenuItem(string nombre | string *nombre,
                     int vida, int alcohol, int sed, int hambre,
                     int valor, string mensaje);
             SetDiscountFunc(string func_name);	[opcional]
             SetMenuStr(string menu_str);	[opcional]
             Esta función sirve para imprimir una cabecera al menú.

   Si no sabes exactamente que precio ponerle a una bebida o una comida
   pon en 'value' 0 ya que el pub.c dispone de una función que calcula
   el precio por el mismo.
   Para ver los valores de strength, soak, heal y stuff mirate los
   archivos '/std/drink.c' y '/std/food.c' o '/doc/wizards/LPC/std/pub'.
   Puedes comprar algo, comprar algo para alguien, o comprar algo para todos
   siempre y cuando se encuentren en la habitacion.
*/


#include <properties.h>
#include <money.h>
#include <health.h>
#include <keeper.h>
#include <sounds.h>


#define STDPUB		"/std/pub"
#define PUBLIST		"/log/PUBLIST"

inherit SCHEDULER_ROOM;
inherit "obj/lib/string";
inherit MONEY_LIB;
inherit KEEPER;


/* Declaración de funciones */
mixed  _test_menu(string item);
int    _serve_item(mixed *item, object pl);

string change_value;
string menu_str;
mixed *menu_list;
string menu;
static string mincoin;
static int    minvalue;
static int abierto;

void create() {
  ::create();
  abierto = 0;

  SetIntShort("Taberna");
  SetIntLong("Estás en una taberna.\n");
  AddRoomCmd("leer", "_pread");
  AddRoomCmd(({"pedir", "comprar"}), "_porder");
  AddDetail(({"menu","menú","menu colgado","menú colgado"}),
              "Debes leerlo para saber que hay.\n");
  menu_list = ({ });
  menu_str  = "";
  change_value = "_do_pay";
}

QueryIntLong() {
 return ::QueryIntLong()+"Parece un buen lugar para tomar o comer algo.\n";
}

int log_pub(string me) {
  string list, foo1, foo2;

  if (file_size(PUBLIST) > 0) {
    list = read_file(PUBLIST);
    if (!sscanf(list,"%s"+me+"%s", foo1, foo2))
      return write_file(PUBLIST,me+"\n");
  }
  else
    return write_file(PUBLIST,me+"\n");
}

mixed *query_menu() { return(menu_list); }

private int sort_value(string type1, string type2) {
  return MONEY_DEMON->QueryCoinValue(type1) >
    MONEY_DEMON->QueryCoinValue(type2);
}

/* [w] Funcion que usa las variables minvalue y mincoin.
 */
private void min_value_coin() {
 mincoin = sort_array(MONEY_DEMON->QueryStandard(), SF(sort_value ))[0];
 minvalue = MONEY_DEMON->QueryCoinValue(mincoin);
}


/* ---------------- Funciones Públicas ------------------ */

/* [w] Añadidas dos nuevas variables 'articulo' (un,una) y 'tipo'
 *     tipo = 0 si es una bebida
 *     tipo = 1 si es una comida
 *     tipo = 2 si es un especial
 */
varargs mixed AddMenuItem(mixed name, int heal, int strength, int soak,
        int stuff, int value, string msg, string articulo, int tipo)
{
  int    min_value, n, i;
  string s;

  if (!name) return 0;

  min_value = MIN_FOOD_COST(soak,stuff,strength,heal,0);
  if (value < min_value)
    value = min_value;

  if (pointerp(name)) {
    s = name[0];
    n = sizeof(name);
    for (i = 0; i < n; i++)
      name[i] = lower_case(name[i]);
  }
  else if (stringp(name)) {
    s = name;
    name = lower_case(name);
  }
  else
    return 0;

  if(!mincoin) min_value_coin();
  if (!abierto) abierto++;

  value = minvalue*(value+minvalue-1)/minvalue;

  if (!menu_list) {
    menu_list = ({});
  }
  menu_list += ({ ({name, heal, strength, soak, stuff, value, msg, articulo, tipo}) });
  return s;
}

varargs mixed AddDrink(mixed name, string articulo, int heal, int strength,
                       int soak, int value, string drink_msg)
{
  return AddMenuItem(name, heal, strength, soak, 0, value, drink_msg, articulo, 0);
}

varargs mixed AddFood(mixed name, string articulo, int heal, int stuff,
              int value, string eat_msg)
{
  return AddMenuItem(name, heal, 0, 0, stuff, value, eat_msg, articulo, 1);
}

varargs mixed AddSpecial(mixed name, string articulo, int heal, int strength,
                       int stuff, int soak, int value, string special_msg)
{
  return AddMenuItem(name, heal, strength, soak, stuff, value, special_msg, articulo, 2);
}

string SetDiscountFunc(string funcname) { return change_value = funcname; }
string QueryDiscountFunc(string funcname) { return change_value; }

string SetMenuStr(string str) { return menu_str = str; }
string QueryMenuStr(string str) { return menu_str; }

/* [w] Añadida una comprobación de que en el caso de que no hubiera
 *     nada que servir de un mensaje y no un '0'.
 *     Cambiado totalmente para que ahora te separe entre bebidas y
 *     comidas.
 *     Añadido aquí lo de minvalue que se encontraba en AddMenuItem.
 *     Primero visualiza Bebidas, luego Comidas y luego Especiales.
 */


int _pread(string str)
{
  int bebidas, comidas, especiales;
  int i;

  if (str != "menu" && str!= "menú" &&
      str != "el menu" && str!= "el menú" &&
      str != "menú colgado" && str!= "menu colgado") return 0;
  if(!abierto)
   return write("En este momento no podemos servir nada.\n"),1;

  if (menu_str)
    write(menu_str);

  menu ="";
  for (i=0;i<sizeof(menu_list);i++) // Bebidas
  {
   if(menu_list[i][8]==0)
   {
    if(!bebidas) {menu+="BEBIDAS\n"; bebidas++;}
    menu += ladjcut("  "+capitalize(menu_list[i][0])+" ",43,".")
    + radjcut(" "+menu_list[i][5]/minvalue,8,".") +" "
    + MONEY_DEMON->QueryMoneyString(([mincoin:2]))[2..] +"\n";
   }
  }

  for (i=0;i<sizeof(menu_list);i++) // Comidas
  {
   if(menu_list[i][8]==1)
   {
    if(!comidas) {menu+="COMIDAS\n"; comidas++;}
    menu += ladjcut("  "+capitalize(menu_list[i][0])+" ",43,".")
    + radjcut(" "+menu_list[i][5]/minvalue,8,".") +" "
    + MONEY_DEMON->QueryMoneyString(([mincoin:2]))[2..] + "\n";
   }
  }

  for (i=0;i<sizeof(menu_list);i++) // Especiales
  {
   if(menu_list[i][8]==2)
   {
    if(!especiales) {menu+="ESPECIALES\n"; especiales++;}
    menu += ladjcut("  "+capitalize(menu_list[i][0])+" ",43,".")
    + radjcut(" "+menu_list[i][5]/minvalue,8,".") +" "
    + MONEY_DEMON->QueryMoneyString(([mincoin:2]))[2..] + "\n";
   }
  }
  menu+="\nPuedes pedirte algo o invitar a alguien que se encuentre aquí.\n";
  write(menu);

  return 1;
}

int _porder(string str)
{
  object ob;
  string stuff, name;
  mixed  *item;

  if (CantAttend(K_NOTIFY)) return 0;
  if (!str) {
    notify_fail("¿pedir qué?\n");
    return 0;
  }
  if (sscanf(str,"%s para %s",stuff,name) != 2) {
    stuff = str;
    name  = (string)(TP->QueryName());
  }
  stuff = lower_case(stuff);
  name  = lower_case(name);

  if (item = (mixed *)_test_menu(stuff)) {
    if (name == "todos") {
      ob = first_inventory(TO);
      while (ob) {
    if (living(ob) && TP->CanSeeObject(ob))
      _serve_item(item,ob);
    ob = next_inventory(ob);
      }
    }
    else {
      ob = present(name);
      name = capitalize(name);
      if (!ob)
    return notify_fail("¡"+name + " no está presente para que lo invites.\n"),0;
      else if (living(ob))
    _serve_item(item,ob);
      else
    return notify_fail("No puedes invitar a "+name+".\n"),0;
    }
    return 1;
  }

  notify_fail("No disponemos de eso en este establecimiento, vete a pedirlo a otro sitio.\n");
  return 0;
}

/* ---------------- Funciones Internas ------------------ */

int _do_pay(int amount) { return amount; }

mixed _test_menu(string item)
{
  int i, n, found;

  item  = lower_case(item);
  found = -1;
  n = sizeof(menu_list);
  i = 0;
  while (i < n && found < 0) {
    if (pointerp(menu_list[i][0]))
      found = member(menu_list[i][0], item);
    else if (item == menu_list[i][0])
      found = 0;
    i++;
  }
  i--;

  if (found >= 0)
    return menu_list[i];
  else
    return 0;
}

int _serve_item(mixed *item, object pl)
{
  string name, *coins, articulo;
  int    heal, strength, soak, stuff, value, intox, psoak, pstuff, tipo;
  object ob;

  if (pointerp(item[0])) name = item[0][0];
  else name = item[0];

  heal     = item[1];
  strength = item[2];
  soak     = item[3];
  stuff    = item[4];
  value    = item[5];
  articulo = item[7];
  tipo     = item[8];

  if (change_value)
    value = (int)call_other(TO,change_value,value);
  if (QuerySomeonesValue(TP) < value) {
    if (QuerySomeonesValue(TP) >= 2*value) {
      value *= 2;
      coins = 0;
   }
   else {
    write("Necesitas más dinero para pagarte eso. Aquí no fiamos a nadie!\n");
    return 1;
   }
  }

  intox  = (int)pl->Query(P_ALCOHOL);
  psoak  = (int)pl->Query(P_DRINK);
  pstuff = (int)pl->Query(P_FOOD);
  if (pl != TP)
    tell_object(pl,""+capitalize(TP->QueryName()) +
        " echa mano a su bolsa y te invita a " + articulo + " " + name + ".\n");
  if ((intox + strength <= (int)pl->Query(P_MAX_ALCOHOL)) &&
      (soak + psoak <= (int)pl->Query(P_MAX_DRINK)) &&
      (stuff + pstuff <= (int)pl->Query(P_MAX_FOOD))) {
    pl->AddAlcohol(strength);
    pl->AddDrink(soak);
    pl->AddFood(stuff);
    pl->Heal(heal);
    ob = first_inventory(TO);
    while (ob) {
      if (ob == pl) {
    if (item[6])
      tell_object(pl,item[6]+"\n");
    else
    {
      if (tipo==0)
      {
          play_sound(TP, SND_SUCESOS("beber"));
          tell_object(ob,"Empinas el codo tomándote " + articulo + " " + name + " a grandes tragos.\n");
      }
      if (tipo==1)
      {
          play_sound(TP, SND_SUCESOS("comer"));
          tell_object(ob,"Atacas con buen apetito " + articulo + " " + name + " y te lo terminas todo.\n");
      }

      if (tipo!=0&&tipo!=1)
       tell_object(ob,"Te pides " + articulo + " " + name + ".\n");
    }
      }
      else
      {
        if (tipo==0)
     tell_object(ob,capitalize(pl->QueryName())+" empina el codo, tomándose "+articulo+" "+name+" a grandes sorbos.\n");
        if (tipo==1)
     tell_object(ob,capitalize(pl->QueryName())+" ataca con buen apetito "+articulo+" "+name+" y se lo termina todo con cara de satisfacción.\n");
        if (tipo!=0&&tipo!=1)
     tell_object(ob,capitalize(pl->QueryName())+" se pide "+articulo+" "+name+".\n");
      }

      ob = next_inventory(ob);
    }
    write(PayValueString(TP, value,coins||
                         (QueryMoneyObject(TP)?
                          m_indices(QueryMoneyObject(TP)->
                                    QueryMoney()) +
                          QueryValuta():0))||
          "Te ha sido imposible pagar.\n");
  }

  else {
    if (intox + strength > (int)pl->Query(P_MAX_ALCOHOL))
      tell_object(pl,"Te tambaleas, la cabeza te da vueltas y de lo único de lo que "
      "tienes la seguridad es que eres incapaz de ingerir una sola gota más de alcohol.\n");
    if (soak + psoak > (int)pl->Query(P_MAX_DRINK))
      tell_object(pl,"No tienes sed y no puedes beber nada más.\n");
    if (stuff + pstuff > (int)pl->Query(P_MAX_FOOD))
      tell_object(pl,
      "Tu hambre ha sido plenamente saciada y en tu estómago no cabe ni un solo bocado más.\n");
    ob = first_inventory(TO);
    while (ob) {
      if (ob != pl)
      {
        if (tipo==0)
         tell_object(ob,capitalize(pl->QueryName())+" echa mano de "+articulo+" "+name+" pero finalmente decide no beber nada más.\n");
        if (tipo==1)
         tell_object(ob,capitalize(pl->QueryName())+", pese a su evidente hartazgo, pide  "+articulo+" "+name+" se da cuenta de que no tiene hambre y dice que se lo lleven todo de vuelta a la cocina.\n");
        if (tipo!=0&&tipo!=1)
         tell_object(ob,capitalize(pl->QueryName())+" pide "+articulo+" "+name+" cambia de idea y decide no pedírselo.\n");
      }
      ob = next_inventory(ob);
    }
  }
  return 1;
}
