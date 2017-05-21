/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 27-11-97                |
 |               Ultima Modificacion.. 12-05-99                |
 |                                                             |
 *=============================================================*/

#include "../sys/goldhai.h"
inherit GROOM;
inherit "/lib/money";
#include <money.h>
#include <rooms.h>
#include <moving.h>

mixed *productos;
string tendero;

create() {
  ::create();
  SetIntShort("Puesto de venta");
  SetIntLong(
 "Estás en un puesto donde puedes comprar cosas.\n");
  tendero="el tendero";
  AddRoomCmd("comprar","comprar");
  AddRoomCmd("lista","productos");
}

AddTendero(str)
{
 if(!str) return;
 tendero=str;
 return 1;
}

AddProducto(nombre,precio,objeto) {
  object ob;
  ob=clone_object(objeto);
  if (!ob) return;
  if (precio < ob->QueryValue()*2) precio=ob->QueryValue()*2;
  ob->remove();
  if (!productos)
   productos=({({nombre+" ["+precio+"]"}),({objeto})});
  else
   productos=insert_alist(nombre+" ["+precio+"]",objeto,productos);
  productos=order_alist(productos);
  return 1;
}

productos() {
  int i;

  for (i=0; i<sizeof(productos[0]); i++) {
      write(i+1+". "+productos[0][i]+"\n");
  }
  return 1;
}

comprar(str) {
  int s,i,precio,dinero_jugador;
  object ob;
  string a;

  if (!str) return notify_fail("Que quieres comprar?\n"),0;
  s=sizeof(productos[0]);
  if (sscanf(str,"%d",i)<1) { write("Dime el numero de lo que quieres comprar.\n"); return 1; }
  i-=1;
  if (i>s-1) { write(capitalize(tendero)+" te dice: No tengo eso que me pides!!\n"); return 1; }
  precio=0;
  if (sscanf(productos[0][i],"%s[%d]",a,s)>1) precio=s;
  say(TP->QueryName()+" pide "+a+".\n");
  dinero_jugador=QuerySomeonesValue(TP);
  if (dinero_jugador<precio) {
    write(capitalize(tendero)+" te dice: No tienes suficiente dinero.\n"); return 1; }
  ob=clone_object(productos[1][i]);
  if (!ob) { tell_room(TO,capitalize(tendero)+" te dice: Lo siento, no nos queda nada que vender.\n"); return 1; }
  ob->move(TP,M_SILENT);
  dinero_jugador=PayValue(TP,precio);
  write(capitalize(tendero)+" te da "+a+"a cambio de "+precio+" monedas.\n");
  return 1;
}
