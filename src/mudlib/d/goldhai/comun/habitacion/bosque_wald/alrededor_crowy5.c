/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 13-05-99            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("el camino que rodea Crowy");
 SetIntLong("\
Has llegado a un pequeño cruce. Puedes continuar bordeando la ciudad en\n\
dirección Norte y Oeste, o bien puedes adentrarte en el bosque si vas hacia\n\
el Este.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BWALD("alrededor_crowy4"));
 AddExit("norte",BWALD("alrededor_crowy6"));
 AddExit("este",BWALD("bosque1"));

 SetLocate("bosque Wald");
}
