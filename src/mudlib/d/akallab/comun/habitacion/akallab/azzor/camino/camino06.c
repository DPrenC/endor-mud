/*
DESCRIPCION  : Cruce en el Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino06.c
MODIFICACION :
05-02-99 [Angor] Creacion
16-09-07 [Angor] Partes comunes a includes
*/

#include "path.h"
inherit ROOM;
create() {
  ::create();
   SetIntShort("un cruce en el Camino del Este");
    SetIntLong(
       "Has llegado a un cruce de caminos. De este punto parte un camino de la via "
       "principal, el Camino del Este, que se aleja hacia el pueblo de Gaddaro que se "
       "halla al noroeste del valle. El Camino del Este gira aqui de sur a este tras "
       "atravesar con un puente el río Kuneii. Junto al cruce se halla la fonda del 'Craneo de elfo', "
       "donde el viajero puede encontrar un buen fuego y una comida caliente.\n");
       
    AddDetail(({"fonda"}),"Es el bajo edificio que se halla al oeste de aqui.\n");
    
    AddDetail(({"puente","puente de piedra"}),
       "Un ancho puente piedra permite atravesar el caudaloso río Kuneii. Es un puente "
       "de varios ojos con gruesos pilares firmemente asentados en el cauce del río. "
       "Se haya en buen estado, aunque ya se nota el efecto de la humedad en él.\n");

#include "geografia.ic"
#include "ambiente.ic"

    AddExit("noroeste",AZ_CAMINO("camino07"));
    AddExit("suroeste",AZ_CAMINO("camino05"));
    AddExit("este",AZ_CAMINO("camino20"));
    AddExit("oeste",AZ_CAMINO("fonda"));
    }