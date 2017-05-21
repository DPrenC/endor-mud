/*
  [ Modificado por Nemesis 13-04-2000 ]
  Cambiada la salida al gremio.
*/

#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la avenida Djorn");
  SetLongWrap("La avenida Djorn parece enorme desde aquí. Si quieres "
  "puedes refrescarte un poco en la taverna que hay en el Oeste. En "
  "el Este está una de las sedes del Gremio de Guerreros.");

  SetIndoors(0);
  AddExit("norte","calle3");
  AddExit("sur","calle5");
  AddExit("este","/guilds/guerreros/sedes/glucks/sede_glucksfall");
  AddExit("oeste","pub1");
  SetLocate("Glucksfall");
}
