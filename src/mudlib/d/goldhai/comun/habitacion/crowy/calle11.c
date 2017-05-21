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
 SetIntLong("La parte sur de la ciudad. No ves nada especial en este lugar que te haga "
            "quedarte. En el Oeste están las puertas de entrada y en el Este "
            "puedes ver un local que parece cerrado.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"este","local","local este"}),
           "Es un local sin ningún distintivo en la fachada. Quizás abran "
           "algo ahí próximamente.\n");
 AddExit("oeste",CROWY("entrada1"));
 AddExit("norte",CROWY("calle10"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2));

 SetLocate("crowy");
}