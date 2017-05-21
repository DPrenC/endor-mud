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
"Est�s en la calle justo en frente de un mes�n situado en el Sur, quiz�s sea\n\
un buen momento de saciar tu apetito. La calle continua en direcci�n Este y\n\
Oeste mientras que los muros de la ciudad no te permiten ir al norte.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("este",CROWY("calle18"));
 AddExit("oeste",CROWY("calle16"));
 AddExit("sur",CROWY("meson"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+1);
 AddItem(PNJ("crowy/kguardia_gigante"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/guardia_orco"),REFRESH_DESTRUCT);

 SetLocate("Crowy");
}

void init()
{
 ::init();
}