/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 21-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("la entrada dentro de Crowy");
 SetIntLong(
"Te encuentras dentro de la ciudad de Crowy justo al lado de su entrada.\n\
Notas como la gente pasa de largo indiferente de tu presencia. Te sientes\n\
uno más dentro de todo el barullo de personas que van de aquí para alla.\n\
Puedes ver una enorme puerta si miras en dirección Sur. En el Oeste puedes\n\
ver una torre de piedra donde al parecer residen los guardianes de la ciudad,\n\
aunque por tu bien yo no entraria ahí, puede resultar algo bastante peligroso.\n\
Las calles continuan en direccion Norte y Este.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise(
"Oyes el murmullo de la gente y a unos guardias que charlan a las puertas\n\
de su torre. Hay un leve sonido de agua proveniente del Norte.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"puerta","puertas","portones","porton","entrada"}),
"Se trata de una enorme puerta de madera de un grosor de más de un brazo.\n\
Su altura es considerable lo cual hace que sea practicamente imposible poder\n\
entrar a la ciudad cuando se encuentran cerradas, lo cual ocurre algunas\n\
noches para impedir que el pueblo pueda ser atacado aprovechando la oscuridad.\n");
 AddDetail(({"torre","torre de guardias","residencia guardias","torre guardianes"}),
"Una torre hecha de piedra donde residen los guardianes de la ciudad. Yo de\n\
ti no entraria, ya que se pueden molestar si les interrumpes el descanso.\n");
 AddExit("este",CROWY("calle11"));
 AddExit("norte",CROWY("calle9"));
 AddExit("sur",CROWY("entrada"));
 AddExit("oeste",CROWY("torre_guardias"));

 AddItem(PNJ("crowy/fuft"),REFRESH_DESTRUCT);

 SetLocate("crowy");
}
