/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 16-02-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("la zona comercial");
 SetIntLong(
"Estás en la calle de una de las zonas comerciales de Crowy. La calle es\n\
estrecha y con una pendiente pronunciada. Al Norte hay un cartel pegado de la\n\
puerta de una tienda, quizás encuentres algo de interés en ella. Si vas al\n\
Este sales de la zona comercial, pero si vas al Oeste podras ver más tiendas.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"tienda","tiendas"}),
"Te destaca la tienda de articulos de broma, con su espectacular colorido.\n");
 AddDetail("cartel","Quizás seria mejor que lo leyeses.\n");
 AddExit("este",CROWY("calle3"));
 AddExit("oeste",CROWY("calle6"));
 AddExit("norte",CROWY("broma_shop"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(1)+2);

 AddReadMsg("cartel",
"Puedes leer:\n\
                    ARTICULOS DE BROMA 'JENFY'\n\
              No te mueras sin reirte del prójimo\n");
 SetLocate("crowy");
}