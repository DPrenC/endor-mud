/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 01-05-97                |
 |               Ultima Modificacion.. 01-05-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("el camino en el parque");
 SetIntLong(
"Estás en lo que parece ser uno de los limites del parque. Multitud de\n\
árboles y matorrales te impiden que sigas hacia el este o el sur, y en el\n\
norte esta el muro que delimita la ciudad. Ves unos restos de palos y rocas.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Todo es tranquilo y silencioso.\n");
 SetIntSmell("Hueles a naturaleza, árboles y plantas.\n");
 AddDetail("parque","No es muy grande pero parece cómodo y confortable.\n");
 AddDetail("muro",
"Es enorme e imposible de saltar.\n");
 AddDetail(({"restos","rocas","palos","restos de palos y rocas"}),
"Observas que hay lo que parece ser una entrada a una caverna oculta.\n");
 AddExit("oeste",CROWY("parque5"));
 AddItem(PNJ("parque/ardilla"), REFRESH_DESTRUCT,2);
 AddItem(PNJ("parque/osezno"), REFRESH_DESTRUCT,6);
 SetLocate("crowy");
 
 
#include "./parque.inc"
}


