/*
** Gremio de Guerreros.
** Autor: Nemesis, basado en el Gremio de Guerreros de NF.
** Creación: Ago'99
** Modificado: [18-Ago-99] En teoría, esto ya está...
**             [21-Ago-99] Movidos HAB_IDENTIFICAR y HAB_VARA a InformJoin.
**             [25-Ago-99] Los niveles máximos requerían una revisión. Hecha.
**             [08-Sep-99] Quitados los títulos, que no servían para nada.
**             [12-Nov-99] Quitado el skill de vendaje. Hasta que las vendas
**                         no funcionen, de poco sirve. (A ver si Woo me echa
**                         una garra...)
**             [30-Nov-99] Reactivado el skill de vendaje.
*/

#include "path.h"
#include "../../wguild.h"
#include <rooms.h>
#include <properties.h>
#include <wizlevels.h>
#include <skills.h>
#include <guild.h>
#include <moving.h>

inherit "/guilds/guerreros/gremio_base";

public void create_ob()
{
  if (clonep()) return;
  ::create_ob();
  SetIntShort("el cuartel General del Gremio de Guerreros");
  SetIntLong(
    "Es un edificio espartano. Parece una especie de cuartel general del\n"
    "ejército. Nada muestra ninguna señal del lujo que podría esperarse\n"
    "de la oficina principal de un gremio.\n");
  SetIndoors(1);
  SetIntBright(25);


  AddItem(GMASTER,REFRESH_HOME);
  SetGuildDomain("simauria");


  AddExit("sur", MARH("nandor/calle3") );
  AddExit("oeste","./almacenjbn");
  AddExit("abajo","./herreria");

}


