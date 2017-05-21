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
"Sigues en el sendero que recorre este parque. Los �rboles en esta zona son "
"enormes, especialmente uno que parece tener una inscripci�n pintada hace "
"ya algun tiempo.\n");

 AddExit("oeste",CROWY("parque3"));
 AddExit("este",CROWY("parque2"));
 AddExit("norte",CROWY("parque7"));

#include "./parque.inc"

 SetGraf("El amor es como una antorcha, cuando la\nenciendes sabes que alg�n d�a se apagar�, pero siempre te pilla desprevenido.");
 SetGrafPlaces(({"el arbol","arbol","inscripci�n","inscripcion"}));

}

void init()
{::init();
 add_graf_commands();
}
