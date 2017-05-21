/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 13-05-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetPreIntShort("frente a");
 SetIntShort("el puente de Crowy");
 SetIntLong("\
Estás en el camino que bordea Crowy. Al Norte puedes ver un puente que te\n\
conduce a la entrada de la ciudad mientras tanto el camino continua en\n\
dirección Este y Oeste. Hay un cartel de señalización sobre una piedra.\n");

#include INC"d_rio_crowy.inc"

 AddDetail(({"puente","pasarela"}),
"Un enorme puente de piedra que te permite cruzar el río que rodea Crowy.\n");
 AddDetail("piedra","Una enorme piedra sobre la que puedes ver un cartel.\n");
 AddDetail(({"cartel","senyal","señal"}),"Ves un cartel de madera. Quizás debieras leerlo.\n");
 AddReadMsg("cartel","\
Puedes ver escrito en el cartel:   _\n\
                       ___________| |___________\n\
                      /           | |           \\\n\
                     /  Puerto de | | Ciudad de  \\\n\
                     \\    Goldhai | | Glucksfall /\n\
                      \\___________| |___________/\n\
                                  | |\n\
                                  | |\n");


 AddExit("norte",CROWY("puente"));
 AddExit("este",BOSCURO("alrededor_crowy2"));
 AddExit("oeste",BOSCURO("alrededor_crowy4"));

 SetLocate("bosque oscuro de Goldhai");
}