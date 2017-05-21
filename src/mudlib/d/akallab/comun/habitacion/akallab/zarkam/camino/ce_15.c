/*
DESCRIPCION  : Camino del Este.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/ce_15.c
MODIFICACION : 13-02-98 [Angor@Simauria] Creacion.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Este");
  SetIntLong(
     "En este punto el camino del Este se adentra en las montanyas Negras. Frente a "
     "ti se halla al este el principio del paso de Akkbar que permite cruzarlas. Este "
     "paso transcurre a traves de profundas grietas y peligrosos acantilados entre las "
     "montanyas, siendo la unica forma directa de llegar desde este valle a la costa "
     "este. El fuerte viento aulla al atravesar los desfiladeros.\n");

AddDetail(({"paso","paso del akkbar","paso de Akkbar","Paso","montanyas","montanyas Negras","Akkbar","akkbar"}),
    "El paso de Akkbar es el nombre que recibe el paso a traves de las montanyas "
    "Negras que se encuentran al este del valle. Estas montanyas separan este valle "
    "de los territorios orcos en la costa este de la peninsula de Aguliuk. Pese a ser "
    "un lugar peligroso, el paso de Akkbar es el camino mas corto y por ello mas "
    "usado para cruzar estas montanyas.\n");

 AddDetail(({"camino","camino del este","camino del Este"}),
    "Estas en este camino que cruza el valle de Zarkam de este a oeste.\n");

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("oeste",Z_CAMINO("ce_14"));
 AddExit("este",AKKBAR_CAMINO("akkbar00"));
}
