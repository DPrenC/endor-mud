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
 SetIntShort("el camino que rodea Crowy");
 SetIntLong("\
Est�s en el camino de piedras que rodea Crowy. Un bosque te impide ir hacia\n\
el sur y un r�o no te permite ir al norte pero siempre puedes proseguir en\n\
direcci�n Este u Oeste.\n");

#include INC"d_rio_crowy.inc"

 AddExit("este",BOSCURO("alrededor_crowy3"));
 AddExit("oeste",BOSCURO("alrededor_crowy1"));

 SetLocate("bosque oscuro de Goldhai");
}
