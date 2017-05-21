/*
DESCRIPCION  : Camino del Este.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_14.c
MODIFICACION : 13-02-98 [Angor@Simauria] Creacion
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Este.");
  SetIntLong(
     "Te encuentras al pie de las montanyas Negras. Al este de aqui el paso de Akkbar "
     "permite al camino del Este cruzar las montanyas. Desde aqui ya se observa con "
     "claridad todo el valle de Zarkam que queda al oeste. El paisaje es austero y la "
     "vegetacion escasa. Llegan heladas rachas de viento desde los desfiladeros.\n");

 AddDetail(({"paso","paso del akkbar","paso de Akkbar","Paso","montanyas","montanyas Negras","Akkbar","akkbar"}),
    "El paso de Akkbar es el nombre que recibe el paso a traves de las montanyas "
    "Negras que se encuentran al este del valle. Estas montanyas separan este valle "
    "de los territorios orcos en la costa este de la peninsula de Aguliuk. Pese a ser "
    "un lugar peligroso, el paso de Akkbar es el camino mas corto y por ello mas "
    "usado para cruzar estas montanyas.\n");

  AddDetail(({"camino","camino del este","camino del Este"}),
    "Estas en este camino que cruza el valle de Zarkam de este a oeste.\n");

  SetIntNoise("Oyes al ruido del viento aullar a tu alrededor.\n");
  SetIntSmell("Hmm.. el aire es seco y frio.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("este",Z_CAMINO("ce_15"));
  AddExit("suroeste",Z_CAMINO("ce_13"));
 }
