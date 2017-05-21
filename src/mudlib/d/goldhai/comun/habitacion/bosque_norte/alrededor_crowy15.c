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
Estás en la orilla del lago Zinn, un extraño lago situado en la parte norte\n\
de Goldhai. En el centro del lago divisas una pequeña isla llena de arboles\n\
y con una extraña montaña en medio a la que quizás puedas llegar si vas\n\
al embarcadero situado al Norte. El camino que rodea Crowy continua en\n\
dirección Sur y Oeste.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy14"));
 AddExit("norte",BNORTE("embarcadero"));
 AddExit("sur",BWALD("alrededor_crowy15"));

 SetLocate("bosque del norte de Goldhai");
}
