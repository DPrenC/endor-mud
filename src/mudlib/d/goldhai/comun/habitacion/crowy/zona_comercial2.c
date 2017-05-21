/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 07-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("la zona comercial");
 SetIntLong(
"La gente entra y sale de los comercios a velocidades vertiginosas. Te sientes\n\
mareado por el agobio que este lugar produce. Miras a tu alrededor y ves lo\n\
que parece ser un puesto de verduras al Norte, mientras que al Sur, un cartel\n\
colgado de la puerta de una vieja casa te indica que se trata de la biblioteca\n\
de la ciudad. La calle continua de Este a Oeste.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"edificio","casa","cabaña","biblioteca","vieja casa"}),
"Ves una casa muy vieja, casi derruida por el paso del tiempo. La verdad es\n\
que la cultura en esta ciudad no esta muy arraigada y esta biblioteca es más\n\
bien un monumento decorativo.\n");
 AddDetail(({"comercio","comercios"}),
"Hay muchos y la verdad es que cuesta decidirse a cual entrar.\n");
 AddDetail(({"puesto","puesto verduras","puesto de verduras"}),
"Un puesto de venta normal y corriente donde venden verduras y hortalizas.\n");
 AddDetail("gente","Entran, compran, salen, andan.. están demasiado atareados.\n");
 AddExit("este",CROWY("zona_comercial3"));
 AddExit("oeste",CROWY("zona_comercial1"));
 AddExit("sur",CROWY("biblioteca"));
 AddExit("norte",CROWY("verduleria"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+1);
 AddItem(PNJ("crowy/guardia_orco"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/guardia_gigante"),REFRESH_DESTRUCT);

 SetLocate("Crowy");
}
