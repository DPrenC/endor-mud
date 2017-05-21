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
"Te encuentras en una de las numerosas calles de la ciudad. Los enormes muros\n\
de Crowy te impiden ir más hacia el Norte pero puedes ir hacia el Este u Oeste.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("este",CROWY("calle17"));
 AddExit("oeste",CROWY("calle14"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2));

 SetLocate("Crowy");
}

void init()
{
 ::init();
}