/* Coded by Yandros to Aurora MUD.
   Modificado por [i] Izet@Simauria, para implementar a Nightfall(tm).
   Ultima modificacion: 10 Oct, 1997.
   Nyh se carga el geiser por que ha petado los call_outs del mud.
 */
#include "path.h"
#include <door.h>
#include <properties.h>
#include <materials.h>


inherit KHA_ROOM;
//#include "geyser.h"

create()
{
  ::create();
  SetIntShort("el baño.");
  SetIntLong(
"Has entrado en los banyos del castillo. En medio de la habitacion hay una gran "
"piscina llena de agua. Los habitantes del castillo toman aqui los banyos "
"calientes y charlan entre ellos sobre sus luchas y filosofias entre otras "
"cosas. Una nube de vapor sale de la piscina, lo cual hace ver que el agua debe "
"estar bastante caliente, o quiza sea el frio que de por si hace en este lugar.\n\
De en medio de la piscina sobresale una pequenya montanyita que parece ser un "
"geyser.\n"
    );
  SetIntBright(100);
  SetIndoors(1);

    AddExit("este",PISO1+"patio5");
    AddDoor("este","la puerta del patio",
        "Es una destartalada puerta de madera que conduce al patio del castillo",
    ({"puerta","puerta de patio","puerta del patio"}), GENDER_FEMALE,
    ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_DEFAULT_IN_RESET:1]));

  AddDetail(({"geyser","montanya","montanyita"}),
"El geyser sobresale solo unos centimetros de la superficie del agua de la "
"piscina. Parece que es lo que alimenta de agua este lugar tan acogedor.\n"
    );
  AddDetail("piscina",
"La piscina esta llena de agua, y la gente viene a darse los banyos termales "
"a cualquier hora del dia o de la noche. No obstante esta es la zona que "
"parece mas calida en todo el castillo.\n"
    );
  AddDetail(({"vapor","nube","nube vapor","nube de vapor"}),
"La nube de vapor es permanente aqui. El frio del ambiente y el calor en esta "
"estancia hacen del vapor aqui un fenomeno inmortal.\n"
    );
}
