//#include "path.h"
#include "/guilds/guerreros/wguild.h"
#include <rooms.h>
#include <properties.h>
#include <wizlevels.h>
#include <skills.h>
#include <guild.h>
#include <moving.h>

inherit "/guilds/guerreros/gremio_base";

public void create_ob()
{
  ::create_ob();
  SetIntShort("una subsede del Gremio de Guerreros");
  SetIntLong(
"Est�s en una de las subsedes del Gremio de Guerreros, un lugar donde puedes\n"
"subir tus caracter�sticas si perteneces a este gran gremio. Apenas si hay\n"
"alg�n tipo de decoraci�n pero �qu� m�s quieres? los guerreros no son lo que\n"
"podr�a llamarse unos aficionados al arte. La salida te conducir� de nuevo\n"
"a la avenida Djorn de la ciudad.\n");

  SetGuildMaster("Mensam");
  SetGuildDomain("goldhai");


  SetIndoors(1);
  SetIntBright(50);
  SetIntSmell("No hueles nada especial\n");
  SetIntNoise("No escuchas nada importante\n");
  AddExit("oeste","/d/goldhai/comun/habitacion/glucksfall/calle4");
  AddExit("norte","/guilds/guerreros/sedes/glucks/almacenjbn");
  AddExit("abajo","/guilds/guerreros/sedes/glucks/herreria");

  SetLocate("Glucksfall");
}
