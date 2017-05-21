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
 SetIntShort("un cruce del camino");
 SetIntLong("\
Te encuentras en un pequeño cruce. En el Oeste existe una senda bastante\n\
amplia que te lleva a lo que parece ser una gran casa en medio del bosque.\n\
Si decides seguir rodeando la ciudad puedes seguir el camino en dirección\n\
Norte y Sur junto al río.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BOSCURO("alrededor_crowy11"));
 AddExit("oeste",BOSCURO("frente_mansion"));
 AddExit("sur",BOSCURO("alrededor_crowy9"));

 SetLocate("bosque oscuro de Goldhai");
}