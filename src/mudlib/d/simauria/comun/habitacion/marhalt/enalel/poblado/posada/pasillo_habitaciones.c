/*

    Nombre      : posadaPasilloHabitacionesEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Pasillo de las habitaciones de la posada.

*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(0);
  SetLocate("Poblado de Enalel");
  SetIntShort("el pasillo de las habitaciones de la posada");
  SetIntLong(W("Estás al comienzo de un estrecho pasillo que comunica las "
  "distintas habitaciones de la posada con el salón comedor. En las paredes, "
  "algunos cuadros y retratos adornan la estancia. La escalera de bajada al "
  "salón se encuentra aquí y el pasillo continúa hacia el oeste.\n"));
  SetIntNoise("Los sonidos del salón de la posada llegan hasta aquí amortiguados.\n");
  SetIntSmell("El aroma de las manzanas y de rica comida flota en el lugar.\n");
  AddDetail(({"cuadro","cuadros","retrato","retratos"}),W("Son los rostros de "
  "los distintos dueños de esta posada durante los últimos siglos. Todos parecen "
  "pertenecer a la familia Silves.\n"));
  AddDetail(({"puerta","puertas","puerta de habitacion","puertas de habitaciones",
  "habitacion","habitaciones"}),W("Son puertas de madera que dan paso a las distintas "
  "habitaciones para huéspedes.\n"));
  AddExit("oeste",ENALHAB"poblado/posada/pasillo_trastero");
  AddExit("abajo",ENALHAB"poblado/posada/posada");
}
