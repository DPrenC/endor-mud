/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 25-11-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("el centro religioso");
 SetIntLong(
"Este sitio no esta dedicado a ninguna religion en especial. Es un lugar de\n\
culto y devocion hacia los dioses de cada uno. Cientos de velas iluminan este\n\
sitio y te produce un cierto sentido abstracto de la realidad. Se dice que\n\
cuando un ser abandona el cuerpo para pasar a otro plano y viene aquí a rendir\n\
sus plegarias, vuelve a recuperar su cuerpo.\n");
 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("Distintos canticos se escuchan con eco.\n");
 SetIntSmell("Hay un fuerte olor a incienso.\n");

 AddDetail(({"iglesia","centro religioso","templo"}),
"Se trata de un lugar bastante tenebroso. Las paredes son de piedra tallada y\n\
las ventanas son de madera de roble. Hay un gran altar en frente de ti más\n\
iluminado de lo que está el resto, seguramente será el sitio donde la gente\n\
invoca a sus dioses.\n");
 AddDetail("altar","Ves un altar de madera.\n");
 AddDetail(({"velas","vela"}),
"Iluminan el templo y a su vez le dotan de un aire mas mortal.\n");

 AddExit("norte",CROWY("zona_comercial3"));

 SetLocate("Crowy");
}

void init()
{
 ::init();
}