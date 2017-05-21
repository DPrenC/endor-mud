/**
 * SIMAURIA '/guilds/conjuradores/gremio.c'
 */

#include "./path.h"
#include <guild.h>
#include <config.h>
#include <skills.h>
#include <rooms.h>
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>
#include <sounds.h>

inherit "/std/guild";

public void create_ob() {
  ::create_ob();
  SetIntShort("el gremio de los conjuradores");
  SetIntLong("\
Te encuentras en el interior del Gremio de los Conjuradores. Las paredes\n\
apenas si tienen adornos y el suelo es de madera nueva. Hacia el este se encuentra la "
"salida del gremio, mientras que al oeste se accede a la tienda de Firoldil.\n");
  SetIntBright(50);
  SetIndoors(1);
  SetGuildclass(GC_CONJURADORES);
  SetGuildname("Gremio de los conjuradores");
  SetGuildMaster("Valdemar, el maestro");
  SetGuildDomain("akallab");
  SetCreators( ({"Woo"}) );
  AddItem("pnj/valdemar",REFRESH_DESTRUCT);

  SetGuildobject(OBJETO("capa"));

  AddExit("este","/d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_12");
  AddExit("oeste",GCONJURADORES+"/room/tienda1");
  AddDoor("oeste", "la puerta de la tienda",
        "Se trata de una puerta de madera sencilla, que comunica esta estancia "
        "con la tienda del gremio.\n",
        ({"puerta", "puerta de madera", "puerta de la tienda"}), GENDER_FEMALE,
        ([P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT,
P_DOOR_OPEN_SOUND : SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND : SND_SUCESOS("abrir_puerta_campanillas")]));
}
