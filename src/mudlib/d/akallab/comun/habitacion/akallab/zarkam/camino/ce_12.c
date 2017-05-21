/*
DESCRIPCION  : Camino del Este.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_12.c
MODIFICACION : 27-05-97 [Grake] Creacion.
               13-02-98 [Angor@Simauria] Habitacion rehecha.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Este");
  SetIntLong(
     "La ascension del camino se hace mas pronunciada a medida que se acerca al paso "
     "Akkbar en las montanyas del este del valle. Observas que un poco mas adelante "
     "hacia el oeste hay un cruce en el camino. De el parte un sendero hacia el norte, "
     "probablemente hacia los campos de cultivo que se encuentran el fondo del valle. "
     "El frio de esas alturas se te cala en los huesos.\n");

 AddDetail(({"paso","paso del akkbar","paso de Akkbar","Paso","montanyas","montanyas Negras","Akkbar","akkbar"}),
    "El paso de Akkbar es el nombre que recibe el paso a traves de las montanyas "
    "Negras que se encuentran al este del valle. Estas montanyas separan este valle "
    "de los territorios orcos en la costa este de la peninsula de Aguliuk. Pese a ser "
    "un lugar peligroso, el paso de Akkbar es el camino mas corto y por ello mas "
    "usado para cruzar estas montanyas.\n");

  AddDetail(({"camino","camino del este","camino del Este"}),
    "Estas en este camino que cruza el valle de Zarkam de este a oeste.\n");

  AddDetail(({"tierras de cultivo","cultivos"}),
    "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
    "no significa que los orcos sean malos agricultores, simplemente ocurre que "
    "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
    "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
    "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
    "comun que los mantiene como esclavos.\n");

  SetIntNoise("Oyes al ruido del viento aullar a tu alrededor.\n");
  SetIntSmell("Hmm.. el aire es seco y frio.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("oeste",Z_CAMINO("ce_11"));
  AddExit("este",Z_CAMINO("ce_13"));
 }
