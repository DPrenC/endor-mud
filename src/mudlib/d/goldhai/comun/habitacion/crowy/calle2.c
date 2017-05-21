/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 15-02-97                |
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
"Estás en la calle. Si vas hacia el Norte llegarás a unas enormes murallas\n\
que intentan proteger la ciudad. Pero si necesitas dinero o por el contrario\n\
llevas mucho encima, es aconsejable que vayas al banco de Crowy, solo tendrías\n\
que ir al Este. Y si lo que deseas es dirigirte a la zona comercial, tienes\n\
que proseguir tu camino en dirección Sur.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail("banco",
"Es el banco principal de la ciudad y el único sitio donde puedes dejar tu\n\
dinero de una forma segura.\n");
 AddExit("norte",CROWY("calle1"));
 AddExit("este",CROWY("banco"));
 AddExit("sur",CROWY("calle3"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(3)+1);

 SetLocate("crowy");
}

void init()
{
 ::init();
}