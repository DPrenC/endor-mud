#include "path.h"
#include <money.h>

inherit DOM_STD+"herreria";

#define NTF(x) notify_fail(x)
/*
int cmd_mostrar(string str)
{
  object *inv, cascara;
  int i, num;

  if (!present("aleet")) return 0;

  if (str!="cascara a aleet" && str!="c�scara a aleet"
    && str!="cascara a Aleet" && str!="c�scara a Aleet")
      return 0;

  inv=all_inventory(TI);
  for (i=0; i<sizeof(inv); i++)
  {
    if (object_name(efun::blueprint(inv[i]))=="/d/lad-laurelin/comun/quest/cascara")
      cascara=inv[i];
  }

  if (!cascara) return 0;

  write(W("Aleet te dice: Vaya, �D�nde has encontrado eso? Es un material "
    "excelente. Si me lo das te puedo crear una armadura fant�stica.\n"));

  return 1;
}


int cmd_dar(string str)
{
  object *inv, cascara, ob;
  int i, num, price;
  string what;

  if (!present("aleet")) return 0;

  if (str!="cascara a aleet" && str!="c�scara a aleet"
    && str!="cascara a Aleet" && str!="c�scara a Aleet")
      return 0;

  inv=all_inventory(TI);
  for (i=0; i<sizeof(inv); i++)
  {
    if (object_name(efun::blueprint(inv[i]))=="/d/lad-laurelin/comun/quest/cascara")
      cascara=inv[i];
  }

  if (!cascara) return 0;

  switch(cascara->Query("from"))
  {
    case "lad laurelin": price=200000;
    			what=QUEST+"coraza-wyvelt";
    			str="la coraza";
    			break;
    case "goldhai":	price=150000;
    			what=QUEST+"perneras-wyvelt";
    			str="las perneras";
    			break;
    case "akallab":	price=100000;
    			what=QUEST+"casco-wyvelt";
    			str="el casco";
    			break;
  }

  if (!price)
  {
    write("La cascara parece rara. Notif�caselo a alg�n wizard.\n");
    return 1;
  }
  ob=clone_object(what);
  if (!ob)
  {
    write("No puedo cargar "+str+". Notif�caselo a alg�n wizard.\n");
    return 1;
  }

  if (MONEY_LIB->QuerySomeonesValue(TP)<price)
  {
    write(W("Aleet te dice: No tienes suficiente dinero para "+str+". Deber�s pagarme "+
  	MONEY_DEMON->QueryValueString(price)+".\n"));
    return 1;
  }

  write(MONEY_LIB->PayValueString(TP, price, 0, "por "+str));
  cascara->remove();
  if (ob->move(TP, M_SILENT)!=ME_OK)
  {
    ob->move(environment(TP), M_SILENT);
    write("No puedes llevar tanto peso y se te cae "+str+".\n");
  }
  return 1;
}
*/
int do_fix(string w)
{
  object ob;

  if (!w) return ::do_fix(w);
  if (!ob=present(w, TP)) return ::do_fix(w);

  if (member(inherit_list(ob), "/std/armour.c")==-1)
    return NTF("Lo siento, s�lo trabajo con armaduras.\n");

  return ::do_fix(w);
}


int do_resize(string w)
{
  object ob;

  if (!w) return ::do_resize(w);
  if (!ob=present(w, TP)) return ::do_resize(w);

  if (member(inherit_list(ob), "/std/armour.c")==-1)
    return NTF("Lo siento, s�lo trabajo con armaduras.\n");

  return ::do_resize(w);
}


create()
{
  ::create();
 seteuid(getuid());
  SetIntLong(W("La tienda est� dividida en dos mitades. Aqu� se pueden "
  	"reparar armaduras y ensancharlas o hacerlas m�s peque�as, seg�n "
  	"sea necesario. Esta parte de la tienda la regenta Aleet, la esposa "
  	"de Ralin.\n"));

  SetIntShort("la tienda de reparaci�n de armaduras");
  SetIntNoise("El murmullo de la ciudad es aqu� un poco m�s tenue.\n");

  SetShopkeeper(PNJ("atbalnin/ciudad/aleet"));
  SetNoShop(1);
  CanSell(1);

  AddExit("tienda", ATB_TI("tienda04"));
  //AddRoomCmd("dar", SF(cmd_dar));
  //AddRoomCmd("mostrar", SF(cmd_mostrar));
  //AddRoomCmd("ense�ar", SF(cmd_mostrar));
  //AddRoomCmd("ensenyar", SF(cmd_mostrar));
}

