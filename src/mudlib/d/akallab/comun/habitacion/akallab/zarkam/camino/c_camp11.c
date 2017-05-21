/*
DESCRIPCION  : Camino al norte de los campos de cultivo
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_camp11.c
MODIFICACION : 11/02/98 Klauss
               15/03/98 [Angor@Simauria] Rehecha
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino a los campos de cultivo");
  SetIntLong(
     "Estas en un estrecho camino de tierra que conduce al norte de los campos de "
     "cultivo que los orcos tienen en este del valle de Zarkam. Al noroeste de aqui un "
     "bajo puente de madera permite curzar el río Kuneii y llegar al camino que va del "
     "denso bosque del nordeste al Sendero de los Cráneos, al noroeste. Desde aqui "
     "observas una cabanya de madera en medio de los campos de cultivo.\n");

  AddDetail (({"camino","sendero"}),
      "Es un estrecho sendero de tierra que desciende hacia los campos de cultivo que "
      "los orcos tienen al este del valle.\n");

  AddDetail(({"cabanya","gran cabanya","establo"}),
     "Los orcos suelen utilizar esclavos para cultivar sus tierras, por lo que supones "
     "que la construccion que ves al norte de los campos debe ser el lugar donde los "
     "orcos mantienen a estos esclavos cuando no estan trabajando.\n");

  AddDetail(({"río","Kuneii","kuneii","cauce"}),
     "El río continua su curso hacia el este suavemente. A ambos lados de la orilla "
     "crece una escasa vegetacion que alegra algo el paisaje.\n");

  AddDetail(({"puente"}),
     "Al noroeste de aqui un bajo puente de madera permite curzar el río Kuneii. "
     "Aunque algo desgastado, este bajo y macizo puente cumple aun bien su funcion.\n");

  AddDetail(({"bosque"}),"Al nordeste ves una denso y enorme bosque.\n");

  AddDetail(({"tierras de cultivo","campos","cultivos","campos de cultivo"}),
     "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
     "no significa que los orcos sean malos agricultores, simplemente ocurre que "
     "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
     "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
     "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
     "comun que los mantiene como esclavos.\n");

  SetIntNoise("Oyes el cercano susurro del correr del agua del río.\n");
  SetIntSmell("Cough.. solo consigues oler el polvo que levantas a tu paso.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("noroeste",Z_CAMINO("c_camp12"));
  AddExit("sudeste",Z_CAMINO("c_camp10"));
}
