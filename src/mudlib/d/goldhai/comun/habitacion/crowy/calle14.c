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
 SetIntShort("una calle");
 SetIntLong(
"Esta zona de Crowy parece mucho menos concurrida, la gente pasa deprisa sin\n\
pararse ante ningun extraño. Al Norte la calle se estrecha y se hace más\n\
oscura. Puedes continuar también hacia el Sur y el Este.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("este",CROWY("calle16"));
 AddExit("norte",CROWY("calle15"));
 AddExit("sur",CROWY("calle13"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(1)+1);
 AddItem(PNJ("crowy/guardia_orco"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/guardia_enano"),REFRESH_DESTRUCT,2);

 SetLocate("Crowy");
}

void init()
{
 ::init();
}