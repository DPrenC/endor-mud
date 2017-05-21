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
Est�s en la orilla del lago Zinn, un extra�o lago situado en la parte norte\n\
de Goldhai. En el centro del lago divisas una peque�a isla llena de arboles\n\
y con una extra�a monta�a en medio a la que quiz�s puedas llegar si vas\n\
al embarcadero situado al Norte. El camino que rodea Crowy continua en\n\
direcci�n Sur y Oeste.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy14"));
 AddExit("norte",BNORTE("embarcadero"));
 AddExit("sur",BWALD("alrededor_crowy15"));

 SetLocate("bosque del norte de Goldhai");
}
