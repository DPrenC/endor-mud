/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("un cruce");
 SetIntLong(
"Estás situado en el cruce principal de Crowy. Desde aquí puedes ir a casi\n\
todos los lugares de la ciudad. Las calles continuan Este, Oeste, Norte y Sur\n\
permitiendote llegar de forma sencilla a donde desees. El bullicio de la gente\n\
es terrible.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("sur",CROWY("calle11"));
 AddExit("oeste",CROWY("calle9"));
 AddExit("este",CROWY("calle12"));
 AddExit("norte",CROWY("calle13"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+1);
 AddItem(PNJ("crowy/guardia_orco"),REFRESH_DESTRUCT);

 SetLocate("crowy");
}