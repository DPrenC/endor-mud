/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"Estás en una de las calles de la zona nordeste de la ciudad. En el Este hay\n\
una taberna bastante sucia y roñosa. Si quieres comprar o vender algo de\n\
contrabando ese es el mejor sitio. La calle continua en direccion Oeste.\n");

 AddDetail(({"taberna","pub"}),
"Supongo que no estaras pensando entrar ahi, verdad?\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes bastante murmullo proveniente del interior de la taberna.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("este",CROWY("contrabandistas"));
 AddExit("oeste",CROWY("calle17"));

 SetLocate("crowy");
}