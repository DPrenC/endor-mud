/*
DESCRIPCION  : Camino del Este.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_13.c
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
    "A medida que el camino del Este se acerca al paso de Akkbar en las montanyas "
    "Negras, se vuelve cada vez mas escarpado. El paisaje que aparece a estas alturas "
    "esta cada vez mas despejado de vegetacion debido al frio y a la altitud. Hacia "
    "el este el camino asciende serpentenado por entre las rocas.\n");

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
  AddExit("oeste",Z_CAMINO("ce_12"));
  AddExit("nordeste",Z_CAMINO("ce_14"));
  AddItem(HERBS("hierba_curativa"), REFRESH_REMOVE);
 }
