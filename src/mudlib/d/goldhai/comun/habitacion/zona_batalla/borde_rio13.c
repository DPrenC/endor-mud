/*=============================================================*
 |          << GOLDHAI.Zona Batalla[w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 28-10-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBATALLA;

int beber(string str);

create()
{
 ::create();
 SetIntShort("el borde del río");
 SetIntLong("\
.\n");
 AddDetail(({"río","arroyo","agua","río cashigan","cashigan"}),
"Es el río Cashigan que recorre la isla Goldhai de norte a sur. Su caudal\n\
de agua es bastante grande y dada la distancia que hay entre ambas orillas\n\
te resulta practicamente imposible atravesarlo. Este parece ser un buen\n\
sitio para calmar tu sed si bebes un poco del agua clara del Cashigan.\n");

 AddRoomCmd("beber",SF(beber));
 AddExit("oeste",BATALLA("borde_rio4"));
 AddExit("suroeste",BATALLA("borde_rio3"));
 AddExit("sur",BATALLA("zona_combate25"));

 SetLocate("llanura de Orkath");
}

int beber(string str)
{
 if (!str)
  return notify_fail("Que es lo que quieres beber?\n"),0;
 if (str != "agua" && str != "agua del río" &&
     str != "agua del cashigan" && str != "agua río" &&
     str != "río" && str != "cashigan")
  return notify_fail("No creo que puedas beber eso.\n"),0;

 TP->SetDrink(TP->QueryDrink()-5);
 write("Te agachas en la orilla y bebes un poco de agua del río.\n");
 write("Arrrgghhhhh... el agua esta salada y te esta entrando mas sed.\n");
 say(CAP(TNREAL)+" se agacha y bebe un poco de agua del río Cashigan.\n");
 return 1;
}
