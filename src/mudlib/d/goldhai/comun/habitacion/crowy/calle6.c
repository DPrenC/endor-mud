/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 27-04-97                |
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
"Un lugar apartado y solitario de la zona comercial. Muy tranquilo si lo\n\
comparamos a lo que te puedes encontrar si vas al Este. Si vas hacia el Norte\n\
llegarás a la armeria de crowy, un lugar poco visitado ya que casi todo el\n\
mundo ya dispone de algun tipo de arma en esta ciudad.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail("armeria",
"Vieja, sucia, asquerosa, puerculenta, desastrosa.. pero quizas encuentres\n\
algo de interés ahí.\n");
 AddExit("este",CROWY("calle4"));
 AddExit("norte",CROWY("armeria"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+1);
 AddItem(PNJ("crowy/kguardia_enano"),REFRESH_DESTRUCT);

 SetLocate("crowy");
}
