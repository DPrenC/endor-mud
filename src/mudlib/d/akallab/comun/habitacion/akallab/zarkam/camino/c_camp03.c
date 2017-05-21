/*
DESCRIPCION  : Camino a los Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/c_camp03.c
MODIFICACION : 24-11-97 [Grake] Creacion.
               14-02-98 [Angor@Simauria] Habitacion rehecha.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit ROOM;

//los PNJ no entran
int ir_no()
{
if (TP->QueryIsPlayer()) return TP->move(Z_CAMPOS("c_camp04"),M_GO);
  return 1;
}

create() {
  ::create();
  SetIntShort("el camino a los campos de cultivo");
  SetIntLong(
    "Te encuentras a la entrada de los campos de cultivo. El camino se adentra en "
    "ellos y los cruza en direccion noroeste. Por lo que ves, el cultivo predominante "
    "en el trigo, aunque en las zonas mas proximas al río y por tanto mas humedas "
    "parece haber zonas de huerta. Al norte de los campos observas una gran cabanya. "
    "El viento forma una especie de olas al avanzar sobre los campos de trigo.\n");

  AddDetail(({"cabanya","gran cabanya","establo"}),
     "Los orcos suelen utilizar esclavos para cultivar sus tierras, por lo que supones "
     "que la construccion que ves al norte de los campos debe ser el lugar donde los "
     "orcos mantienen a estos esclavos cuando no estan trabajando.\n");

  AddDetail(({"río","río Kusaii","río kusaii","Kusaii","kusaii"}),
    "El río Kusaii nace en las montanyas de Sharg, al sur del valle de Zarkam. Desde "
    "alli baja encajonado entre desfiladeros hasta el centro del valle donde se une "
    "con su afluente el Kuneii que viene del oeste, para despues dirigirse hacia el "
    "este hacia la costa. Este río no es navegable, pues al atravesar las montanyas "
    "Negras, que quedan al este de aqui, las cataratas de Nurr lo impiden.\n");

 AddDetail(({"tierras de cultivo","cultivos","campos de cultivo"}),
    "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
    "no significa que los orcos sean malos agricultores, simplemente ocurre que "
    "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
    "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
    "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
    "comun que los mantiene como esclavos.\n");

  SetIntNoise("Oyes al ruido del viento a tu alrededor.\n");
  SetIntSmell("Notas un olor a tierra humeda removida.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("suroeste",Z_CAMINO("c_camp02"));
  AddExit("noroeste",SF(ir_no));
}
