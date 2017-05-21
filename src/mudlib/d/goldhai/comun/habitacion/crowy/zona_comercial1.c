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
 SetIntShort("la entrada a la zona comercial");
 SetIntLong(
"Estás en la entrada a la zona más comercial de la ciudad. Un lugar donde por\n\
unas pocas monedas puedes comprar aquello que te hace falta para proseguir\n\
tu viaje o para vivir en esta ciudad. Al Sur esta la tienda del viejo Smart,\n\
el sitio adecuado para encontrar toda clase de objetos y utensilios. Si vas\n\
hacia el Oeste saldrás de aquí, los comercios continuan hacia el Este.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"tienda","tienda de Smart","tienda del viejo Smart"}),
"La tienda del viejo Smart, el sitio ideal para encontrar lo que buscas.\n");
 AddDetail(({"comercio","comercios"}),
"Los hay de todo tipo pero en todos encontrarás cosas de interés.\n");
 AddExit("este",CROWY("zona_comercial2"));
 AddExit("oeste",CROWY("calle12"));
 AddExit("sur",CROWY("tienda_smart"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2));
 AddItem(PNJ("crowy/kguardia_elfo"),REFRESH_DESTRUCT);

 SetLocate("Crowy");
}

void init()
{
 ::init();
}
