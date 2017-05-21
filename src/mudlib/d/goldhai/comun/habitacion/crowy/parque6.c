#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntLong(
"Has alcanzado la esquina noroeste del muro que rodea a la ciudad. Los "
"matorrales junto a él son tan densos que no puedes acercarte más.\n");

 AddExit("este",CROWY("parque5"));
 AddExit("sur",CROWY("parque4"));
 
#include "./parque.inc"
}


