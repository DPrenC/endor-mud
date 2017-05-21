#include "./path.h"
#include <colours.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("la avenida Grimly");
    SetIntLong("Paseando por la Avenida Grimly llegas a un cruce. La posada del Dragón Azul "
        "invita a pasar unas horas de merecido descanso a los viajeros que llegan desde "
        "tierras lejanas.\nJunto a la puerta puedes ver un letrero pendiente de una varilla.\n");
    SetIntBright(80);
    SetIndoors(1);
    AddDetail(({"posada","posada del dragon azul"}),"Siempre con las puertas abiertas a todo "
        "aquél que desee descansar.\n");
    AddDetail(({"letrero"}),"De madera y bien tallado. tiene algo escrito.\n");
    AddExit("norte",CIUDAD+"kilok3");
    AddExit("sur",POSADAS+"dazul/posada");
    AddExit("este",CIUDAD+"grimly12");
    AddExit("oeste",CIUDAD+"grimly10");
    AddDoor("sur","la puerta de la posada",
        "Es una puerta de madera, sencilla pero robusta.\n",
        ({"puerta","puerta de madera","puerta de posada","puerta de la posada"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
        SetLocate("Kha-annu");
    AddReadMsg(({"letrero","cartel"}),TC_RED"\t        Posada del Dragon Azul\n"TC_NORMAL
        TC_PURPLE"\t         Abierta las 24 horas\n"TC_NORMAL);
}
