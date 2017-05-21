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
Has llegado a una pequeña intesección del camino, así que piensate bien hacia\n\
donde quieres ir antes de continuar. Hacia el Oeste y Sur te adentrarás en un\n\
bosque con la vegetación bastante espesa, mientras que si vas al Norte o al\n\
Este irás bordeando el río que proteje lo que parece ser una gran ciudad. De\n\
todas formas puedes ver un pequeño cartel que te puede aclarar hacia donde ir.\n");

#include INC"d_rio_crowy.inc"
 AddDetail(({"cartel","indicacion","indicación"}),"Será mejor que leas el cartel primero.\n");

 AddReadMsg("cartel","\
Puedes ver escrito en el cartel:   _\n\
                       ___________| |___________\n\
                      /           | |           \\\n\
                     /  Puerto de | | Ciudad de  \\\n\
                     \\    Goldhai | | Crowy      /\n\
                      \\___________| |___________/\n\
                                  | |\n\
                                  | |\n");
 AddExit("norte",BOSCURO("alrededor_crowy15"));
 AddExit("este",BOSCURO("alrededor_crowy13"));
 AddExit("oeste",BOSCURO("camino_puerto1"));
 AddExit("sur",BOSCURO("bosque18"));

 SetLocate("bosque oscuro de Goldhai");
}
