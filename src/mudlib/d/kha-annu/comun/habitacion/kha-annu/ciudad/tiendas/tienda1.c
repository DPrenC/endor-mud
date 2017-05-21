/* Tienda de Armas personalizada de Kha-annu.
Fichero: tienda1.c
Autor: [I] Izet@Simauria.
Creacion: 28 Enero 1998.
Ultima modificacion: 28 Enero 1998.
                     Izet@Simauria 18 Febrero 1998.
                     Nemesis@Simauria Octubre'99 Desactivadas las hachas hasta que la paseis por SetStandard
                     Woo@Simauria 11 Abril 2000, Si lo desactivais quitad el
                         comando porque si no peta.
                     Izet@Simauria, arreglado lo del SetStandard.
*/

#include "./path.h"
#include <properties.h>
#include <moving.h>
#include <combat.h>

inherit SHOP;

private static int linea;
private static string *mensaje;
object ob;

create() {
  ::create();
  SetIntShort("la Forja del Buen Guerrero");
  SetIndoors(1);
  SetIntBright(70);
  SetIntLong(
"Al entrar en la tienda percibes todo su esplendor. Grandes hachas y elegantes "
"armaduras cuelgan expuestas por todas las paredes.\n\Ves un cartel sobre el mostrador.\n");
  AddDetail( ({"tienda","forja","herreria","forja del guerrero",
              "forja del buen guerrero"}),SF(IntLong));
  AddDetail( ({"hachas","armadura","armaduras","pared"}),
"Son adornos creados por Zanul para decorar su maravillosa tienda.\n");
  AddDetail( ({"cartel"}),"Es un cartel de madera. Tiene algo escrito.\n");
  AddReadMsg( ({"cartel"}),
"El cartel pone:\n"
"Puedes 'encargar' tu hacha a medida en esta herreria. Despues de hacer tu "
"encargo podras poner tu propia descripcion al objeto que compres.\n"
);
  AddArticle(ARMA("axe"),REFRESH_REMOVE,5);
  AddExit("norte",CIUDAD+"antha1");
  AddExit ("oeste",CIUDAD+"rurik9");
  AddExit("este",CIUDAD+"tiendas/trasera");
  AddRoomCmd("encargar","Comprar");
  RemoveDustbin();
}

cancelar() {
  write("Has cancelado tu encargo.\n");
}
ayuda() {
  write("\
~c :	cancela el encargo "
"~a :	muestra esta ayuda "
"~b :	borra la ultima linea "
"~m :	muestra lo que has escrito\n "
"Usa ** o . para terminar tu edicion.\n");
}
borrar() {
  if (!linea) {return;}
  linea--;
  mensaje = mensaje[0..linea-1];
}
private mostrar_texto()
{
  int i;
  for (i=0;i<sizeof(mensaje);i++)
  {
    write(to_string(i+1)+". "+mensaje[i]+"\n");
  }
}
finalizar()
{
 string larga, *pagar;
 int longitud;
 write("Le das la descripcion a de tu hacha a Zanul y la apunta en una hoja.\n");
 larga = implode(mensaje-({0}),"\n") + "\n";
 ob->SetLong(larga);
 longitud = strlen(implode(explode(larga,"\n"),"")) * 10 +6000;
 ob->SetValue(longitud);
 if (QuerySomeonesValue(TP) < longitud)
 {
    write("No tienes dinero suficiente!\n");
    ob->remove();
    return 1;
  }
 pagar = PayValue2 (TP, longitud);
 if (longitud)
  write("Pagas "+pagar[0] +
        (pagar[1] ? " y recibes "+pagar[1] : "")+".\n");
 else write("No has pagado nada.\n");
 if ((ob->move(TP,M_GET)) != ME_OK)
 {
   write(
"El hacha pesa demasiado para ti. Zanul la pone sobre el mostrador.\n");
   ob->move(TO,M_DROP);
 }
}
edicion(string str)
{
  int seguir;
  seguir = 1;
  if (str[0]=='~')
  {
    switch(str[1])
    {
      case 'c': return cancelar(); break;
      case 'a': ayuda(); seguir = 0; break;
      case 'b': borrar(); seguir = 0; break;
      case 'm': mostrar_texto(); seguir = 0; break;
    }
  }
  if (str=="."||str=="**") return finalizar();
  if (seguir)
  {
    mensaje+=({str});
    linea+=1;
  }
  write(to_string(linea+1)+"]");
  input_to("edicion");
}
introduce()
{
  linea = 0;
  mensaje = ({});
  write(to_string(linea+1)+"]");
  input_to("edicion");
}
hachashort(string str)
{
  if ((str) && (str!="")) ob->SetShort(str);
  write("Zanul te pide una descripcion detallada de tu hacha.\n");
  write("Debes editar la descripcion detallada de tu hacha de guerra.\n\
Usa '.' or '**' para terminar o '~h' para mostrar la ayuda:\n");
  introduce();
}
mixed Comprar(string str)
{
  if (!TP) return;
  if (!str) return notify_fail("Encargar QUE?\n");

  if ((str != "hacha") && (str == "hachas")) return notify_fail("Encargar QUE?\n");

  if (!QueryShopkeeper()) return notify_fail("Encargar QUE?\n");
  else
  {
    say(TP->QueryName()+" hace un encargo a Zanul.\n");
    ob = clone_object("/std/weapon");
    ob->SetStandard(WT_HACHA, 12, P_SIZE_GENERIC);
    ob->SetValue(700);
    ob->SetResetQuality(100);
    ob->SetDecay(500);
    ob->SetNumberHands(2);
    ob->SetMagic(1);
    ob->SetDamageType(DT_FIRE);
    ob->SetShort("el hacha de guerra de "+TP->QueryName());
    ob->SetLong(
"Este hacha esta hecha con los metales mas ligeros de Kha-annu y disenyada por "
"sus ingenieros con todo lujo de detalles.\n");
    ob->SetWeight(5000);
    ob->SetIds( ({"hacha","hacha de guerra","hachas"}) );
    ob->SetAds( ({"un","muy","especial","cara","lujosa"}) );
    write(
"Zanul te pide la descripcion simple de tu hacha.\n");
    write("Simple: ");
    input_to("hachashort");
    return 1;
  }
}
