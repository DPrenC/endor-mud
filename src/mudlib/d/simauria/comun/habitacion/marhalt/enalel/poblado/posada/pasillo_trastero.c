/*

    Nombre      : posadaPasilloTrasteroEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Zona del pasillo de la posada que comunica con el trastero.
                  Hace falta la llaveque tiene el posadero para abrir la puerta del trastero.

*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Poblado de Enalel");
  SetIntShort("el pasillo de las habitaciones de la posada");
  SetIntLong(W("Estás al final de un estrecho pasillo que comunica las "
  "distintas habitaciones de la posada con el salón comedor. En las paredes, "
  "algunos cuadros y retratos adornan la estancia. Una vieja puerta de madera "
  "comunica con el trastero de la posada. El pasillo empieza hacia el este, "
  "donde está la escalera de bajada.\n"));
  SetIntNoise("Los sonidos del salón de la posada llegan hasta aquí amortiguados.\n");
  SetIntSmell("El aroma de las manzanas y de rica comida flota en el lugar.\n");
  AddDetail(({"cuadro","cuadros","retrato","retratos"}),W("Son los rostros de "
  "los distintos dueños de esta posada durante los últimos siglos. Todos parecen "
  "pertenecer a la familia Silves.\n"));
  AddDetail(({"puerta","puerta del trastero","puerta trastero"}),W("Es una puerta "
  "de madera cerrada con llave que comunica con el trastero.\n"));
  AddExit("este",ENALHAB"poblado/posada/pasillo_habitaciones");
}
