/*

    Nombre      : posadaPasilloHabitacionesEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Pasillo de las habitaciones de la posada.

*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(0);
  SetLocate("Poblado de Enalel");
  SetIntShort("el pasillo de las habitaciones de la posada");
  SetIntLong(W("Est�s al comienzo de un estrecho pasillo que comunica las "
  "distintas habitaciones de la posada con el sal�n comedor. En las paredes, "
  "algunos cuadros y retratos adornan la estancia. La escalera de bajada al "
  "sal�n se encuentra aqu� y el pasillo contin�a hacia el oeste.\n"));
  SetIntNoise("Los sonidos del sal�n de la posada llegan hasta aqu� amortiguados.\n");
  SetIntSmell("El aroma de las manzanas y de rica comida flota en el lugar.\n");
  AddDetail(({"cuadro","cuadros","retrato","retratos"}),W("Son los rostros de "
  "los distintos due�os de esta posada durante los �ltimos siglos. Todos parecen "
  "pertenecer a la familia Silves.\n"));
  AddDetail(({"puerta","puertas","puerta de habitacion","puertas de habitaciones",
  "habitacion","habitaciones"}),W("Son puertas de madera que dan paso a las distintas "
  "habitaciones para hu�spedes.\n"));
  AddExit("oeste",ENALHAB"poblado/posada/pasillo_trastero");
  AddExit("abajo",ENALHAB"poblado/posada/posada");
}
