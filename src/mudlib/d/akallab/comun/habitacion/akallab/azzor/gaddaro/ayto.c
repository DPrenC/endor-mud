/*
DESCRIPCION  : Ayuntamiento
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/ayto.c
MODIFICACION : 15-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <door.h>
#include <nightday.h>
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("el ayuntamiento del pueblo de Gaddaro");
    SetIntLong("Te encuentras en la casa del jefe del poblado, que también hace las veces de "
        "ayuntamiento. Es algo mayor que el resto de las casas, y por ello es aquí donde se "
        "reúne el consejo, formado por el jefe y varios habitantes representativos, para tomar "
        "decisiones o impartir justicia. Observas varios trofeos de caza colgados en las "
        "paredes. Un generoso fuego arde en una gran chimenea caldeando el ambiente.\n");
    AddDetail(({"trofeos","paredes"}),
  "En las paredes del ayuntamiento hay colgadas las cabezas disecadas de "
  "algunos grandes animales. Supones que deben ser trofeos de caza del "
  "jefe del poblado.\n");

  AddDetail(({"chimenea"}),
  "La chimenea de piedra esta adosada a la casa. En ella arde un "
  "agradable fuego que calienta el ambiente.\n");

  AddDetail(({"pueblo","villa","Gaddaro"}),
  "Gaddaro es el nombre de este pueblo. Es un pequenyo pueblo situado "
  "en el noroeste del valle de Azzor, en su parte alta. Sus habitantes "
  "se dedican basicamente a la agricultura y a la pesca en el cercano "
  "lago Darum.\n");

 SetIntNoise("Oyes el fuego crepitar en la chimenea.\n");
 SetIntSmell("Hueles el olor que desprende la madera al quemarse.\n");
 SetLocate("pueblo de Gaddaro");
 SetIndoors(1);
 SetIntBright(50);

    SetCloseTime(({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
    SetLastDest(GADDARO("calle02"));
    SetNotifyExits("este");
    AddExit("norte",GADDARO("calle04"));
    AddExit("este",GADDARO("calle02"));
    AddDoor("norte", "la puerta trasera",
        "Es la puerta que da sobre la esquina de la plaza del pueblo.\n",
        ({"puerta", "puerta de la calle", "puerta norte","puerta trasera"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    AddDoor("este", "la puerta principal",
        "Es la puerta que da a la calle principal del pueblo.\n",
        ({"puerta", "puerta de la calle", "puerta este","puerta principal"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
}
