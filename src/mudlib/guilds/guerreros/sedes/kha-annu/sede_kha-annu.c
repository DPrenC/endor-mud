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
**             [14-Dic-00] Fusilado por Gorthem para Kha-annu  (por fin)
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
  ::create_ob();
  SetIntShort("el gremio de Guerreros de Kha-annu");
  SetIntLong(
    "Estas en un gran salon de techos altos y paredes de piedra. Armas de todo\n"
    "tipo cuelgan de las paredes intercaladas con los mejores tapices que jamas\n"
    "hayas visto, representando escenas de batallas.\n"
    "Al oeste hay una abertura por la que desaparece un pasillo y empieza una\n"
    "escalera.\n");

  SetIndoors(1);
  SetIntBright(25);

  AddItem("./thualin",REFRESH_HOME);
  SetGuildMaster("Thualin");
  SetGuildDomain("kha-annu");

  AddExit("norte","/d/kha-annu/comun/habitacion/kha-annu/ciudad/grimly4");
  AddExit("sur","/d/kha-annu/comun/habitacion/kha-annu/ciudad/baldur4");
  AddExit("oeste","./almacenjbn");
  AddExit("abajo","./herreria");

}


