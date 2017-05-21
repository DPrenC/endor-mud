/*
DESCRIPCION  : Sendero de los Cráneos al sur de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/cc_04.c
MODIFICACION : 15-08-97 [Angor@Simauria] Creacion
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit ROOM;

//los PNJ no entran a la ciudad
int ir_n()
{
if (TP->QueryIsPlayer()) return TP->move(Z_CIUDAD("puerta_s"),M_GO);
  return 1;
}

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al sur de Zarkam");
  SetIntLong(
     "Te encuentras en el Sendero de los Cráneos, justo al sur de la ciudad de Zarkam. "
     "El camino continua ascendiendo lentamente hacia la loma en la que se halla esta "
     "ciudad fortificada. Observas como la puerta esta custodiada por varios guardias "
     "que controlan a la gente que entra y sale. Los guardias van armados hasta los "
     "dientes y no parecen muy amistosos. El viento sopla con fuerza desde el sudeste.\n");

  AddDetail(({"puerta"}),"La puerta sur de la ciudad de Zarkam queda al norte de aqui.\n");

  AddDetail(({"guardia","guardias","soldados"}),
     "Desde aqui puedes observar la entrada sur de la ciudad. En ella una guarnicion "
     "de guardias y soldados que controlan a la gente a la hora de entrar o salir de "
     "la ciudad. Aunque aun estas un poco lejos, se puede apreciar que van fuertemente "
     "armados y parecen peligrosos. No parece muy conveniente un enfrentamiento.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

  SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);

  AddExit("norte",SF(ir_n));
  AddExit("sur",Z_CAMINO("cc_02"));
}
