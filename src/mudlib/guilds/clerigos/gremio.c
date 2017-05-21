/**
 *SIMAURIA '/guilds/clerigos/gremio.c'
 */

#include "./path.h"
#include <guild.h>
#include <config.h>
#include <skills.h>
#include <rooms.h>
inherit "/std/guild";

create() {
  ::create();
  SetIntShort("Gremio de los clerigos");
  SetIntLong("\
Te encuentras en el interior del Gremio de los Clerigos. Las paredes\n\
apenas si tienen adornos y el suelo es de madera nueva. Puedes salir del\n\
Gremio si vas hacia el Este.\n");
  SetIntBright(50);
  SetIndoors(1);
  SetGuildclass(GC_CLERIGOS);
  SetGuildname("Gremio de los clerigos");
  SetGuildMaster("Dhoigner, el alto prior");
  SetCreators( ({"Nyh"}) );

  SetGuildobject(OBJETO("medallon"));
/*
  AddMinStat(P_INT, 3); AddMaxStat(P_INT, 35); AddMaxHLPStat(P_INT, 45);
  AddMinStat(P_DEX, 3); AddMaxStat(P_DEX, 30); AddMaxHLPStat(P_DEX, 40);
  AddMinStat(P_CON, 1); AddMaxStat(P_CON, 27); AddMaxHLPStat(P_CON, 37);
  AddMinStat(P_STR, 2); AddMaxStat(P_STR, 28); AddMaxHLPStat(P_STR, 38);

  AddGuildSkill(HAB_VARA, 1, 100, 0, 1);
  AddGuildSkill(HAB_MEMORIZAR, 1, 100, 0, 1);
  AddGuildSkill(HAB_MAZA, 1, 100, 0, 5);
*/

//  AddExit("este","/d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_12");
}
