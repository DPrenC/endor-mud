/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 01-05-97                |
 |               Ultima Modificacion.. 01-05-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;
inherit GRAF;

create()
{
 ::create();
 SetIntShort("el camino en el parque");
 SetIntLong(
"Sigues en el sendero que recorre este parque. Los árboles en esta zona son "
"enormes, especialmente uno que parece tener una inscripción pintada hace "
"ya algun tiempo.\n");

 AddExit("oeste",CROWY("parque3"));
 AddExit("este",CROWY("parque2"));
 AddExit("norte",CROWY("parque7"));

#include "./parque.inc"

 SetGraf("El amor es como una antorcha, cuando la\nenciendes sabes que algún día se apagará, pero siempre te pilla desprevenido.");
 SetGrafPlaces(({"el arbol","arbol","inscripción","inscripcion"}));

}

void init()
{::init();
 add_graf_commands();
}
