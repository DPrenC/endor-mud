//[Maler]

#include "path.h"

inherit SIM_ROOM;
create() {
::create();
SetLocate("Berat");
SetIntShort("el puente de Berat");
SetIntLong(W("Estás en el puente de entrada a Berat, es el puente "
"más antiguo del pueblo. Es muy ancho y robusto , perfecto para  "
"resistir el paso de carretas y caballos. Es uno de los más "
"transitados de todo el dominio humano, y uno de los más seguros. "
"Une la ciudad de Berat al sur con el camino hacia Ishtria al norte.\n"));
SetIndoors(0);
SetIntNoise("Escuchas el murmullo del río.\n");
SetIntSmell("Huele a hierba fresca.\n");
AddDetail(({"puente"}),W("Este puente permite cruzar uno de los riachuelos del"
" delta que bordean la ciudad de Berat.\n"));
AddDetail(({"río","riachuelo"}),W("Es un riachuelo, poco caudaloso, tipico"
" de un delta.\n"));
AddExit("norte","/d/simauria/comun/habitacion/simauria/berat/camino1");
AddExit("sur","/d/simauria/comun/habitacion/simauria/berat/camino2");
}
