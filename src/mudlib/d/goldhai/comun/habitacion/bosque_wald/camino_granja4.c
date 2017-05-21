/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 27-08-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("un camino de piedras");

 AddDetail(({"río","arroyo","agua"}),
"Te arrimas a la orilla del río y miras hacia abajo. Un terrible olor\n\
proveniente del agua te impide casi respirar, seguramente hara anyos que no\n\
se ha cambiado ese agua estancada. Toda clase de enseres y porqueria flota\n\
en la superficie de ese agua grasienta y de color amarillo.\n");

 AddExit("este",BWALD("camino_granja5"));
 AddExit("oeste",BWALD("camino_granja3"));

 SetLocate("bosque Wald");
}