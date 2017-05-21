/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 29-10-98                |
 |               Ultima Modificacion.. 13-05-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("el camino que rodea Crowy");
 SetIntLong("\
Hay un pequeño agujero en la orilla del campo de trigo, quizás se trate\n\
de un escondite de ratas. Puedes continuar caminando si vas hacia el\n\
Este o el Oeste.\n");

#include INC"d_rio_crowy.inc"

 AddDetail(({"agujero","madriguera","escondite"}),
"Es un pequeño agujero que se adentra en los campos de trigo.\n");

 AddExit("oeste",BNORTE("alrededor_crowy8"));
 AddExit("este",BNORTE("alrededor_crowy10"));

 SetLocate("bosque del norte de Goldhai");
}
