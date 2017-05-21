/**
 * Gremio de Guerreros
 */

#include "path.h"
#include "wguild.h"
#include <rooms.h>
#include <properties.h>
#include <wizlevels.h>
#include <skills.h>
#include <guild.h>
#include <moving.h>

inherit "/guilds/guerreros/gremio_base";

public void create()
{
  ::create();
  SetIntShort("Cuartel General del Gremio de Guerreros");
  SetIntLong(
    "Es un edificio espartano. Parece una especie de cuartel general del\n"
    "ej�rcito. Nada muestra ninguna se�al del lujo que podr�a esperarse\n"
    "de la oficina principal de un gremio.\n");
  SetIndoors(1);
  SetIntBright(75);

  AddItem(GMASTER,REFRESH_HOME);

  AddExit("sur", MARH("nandor/calle3") );
  AddExit("oeste","./almacenjbn");
  AddExit("abajo","./herreria");

}


