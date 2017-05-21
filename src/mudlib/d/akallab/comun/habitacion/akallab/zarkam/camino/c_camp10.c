/*
DESCRIPCION  : Camino al norte de los campos de cultivo
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_camp11.c
MODIFICACION : 11/02/98 Klauss
               15/03/98 [Angor@Simauria] Rehecha
               07-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/
#include "path.h"
#include <moving.h>


inherit ROOM;

//los PNJ no entran
int ir_se()
{
if (TP->QueryIsPlayer()) return TP->move(Z_CAMPOS("c_camp09"),M_GO);
  return 1;
}

create() {
  ::create();
  SetIntShort("la entrada a los campos de cultivo");
  SetIntLong(
     "Te encuentras en la entrada de los campos de cultivo de los orcos. Ves varios "
     "esclavos con aperos de labranza trabajando en los campos de cultivo. Al este, "
     "observas la cabanya de los esclavos y, al nordeste del valle, un denso bosque. "
     "Al norte esta el río Kuneii, y al sudeste atravesando los campos, el Kusaii.\n");

  AddDetail (({"campos","cultivos"}),
     "Son los campos de cultivo pertenecientes a los orcos. Los esclavos son los "
     "encargados de ciudarlos y hacer que produzcan. Observas como en cultivo mas "
     "extendido es el trigo y que cerca del río hay unas pequenyas zonas de huerta.\n");

  AddDetail(({"esclavos"}),
     "Estan aqui para trabajar los campos de cultivo para los orcos. Te fijas en sus "
     "ropas sucias y rotas, y en sus semblantes tristes y sufridos. Trabajan sin "
     "descanso, desde el alba hasta el anochecer. No te gustaria estar en su pellejo!\n");

  AddDetail (({"aperos"}),
     "Son los tipicos aperos de labrador: azadas, palas, picos, rastrillos, etc...\n");

  AddDetail(({"cabanya","gran cabanya","establo"}),
     "Los orcos suelen utilizar esclavos para cultivar sus tierras, por lo que supones "
     "que la construccion que ves al norte de los campos debe ser el lugar donde los "
     "orcos mantienen a estos esclavos cuando no estan trabajando.\n");

  AddDetail(({"río","kuneii","Kuneii","kusaii","Kusaii","afluente"}),
     "El río Kusaii atraviesa los campos de cultivo viniendo desde el sur, para unirse "
     "mas trade al nordeste de aqui con su afluente el Kuneii.\n");

  SetIntNoise("Oyes el ruido de los esforzados esclavos trabajando la tierra.\n");
  SetIntSmell("Hmm.. te huele a tierra fresca, recien cavada.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("noroeste",Z_CAMINO("c_camp11"));
  AddExit("sudeste",SF(ir_se));
}

