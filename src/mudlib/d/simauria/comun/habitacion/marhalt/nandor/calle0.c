/*
??-??-?? [??@??] Creacion
05-02-99 [Angor@Simauria] Anyadida la caravana Zarkam-Nandor
17-05-99 [Mirill@Simauria] Anyadidas las caravanas que faltaban
03/06/99 [Mirill@Simauria] Correciones varias
20-09-99 [Woo@Simauria] Cambiadas algunas cosas para que funcione, en
                        especial que no heredaba bien la caravana.
28-10-99 [Angor@Simauria] Arreglada la caravana Zarkam-Nandor
*/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

#define CARAVANA_ZARKAM   "/d/akallab/comun/transporte/caravana/zarkam/caravana"
#define CARAVANA_KHA_ANNU "/d/kha-annu/comun/transporte/caravana/khandor/khandor"
#define CARAVANA_NHALIN   "/d/lad-laurelin/comun/transporte/caravana/nahlin/nahlin"

inherit CARAVAN_STOP;

create() {
    ::create();
   SetLocate("Aldea de Nandor");
    SetIntShort("la calle principal de Nandor");
    SetIndoors(0);
    SetClimateServer(SERVER);
    SetIntLong("Estás en la calle principal de la villa de Nandor. Hacia el este, la "
        "calle continúa en dirección a la plaza, mientras que si vas hacia el oeste "
        "llegarás a la entrada occidental de la aldea.\n  Al norte tienes la posada, un gran "
        "edificio de dos pisos con un gran letrero en la entrada.\n  Al sur puedes ver "
        "la Oficina de la Hermandad de Banqueros.\n  En este lugar tienen su parada "
        "las caravanas que en sus recorridos unen Simauria con otros reinos lejanos.\n"
        "Puedes leer la tabla de información de las distintas caravanas.\n");
    AddDetail(({"letrero", "cartel"}), "Es grande y pone: 'Posada de Nandor'.\n");
    SetIntNoise("El sonido de las voces y risas de la posada es ensordecedor.\n");
    AddExit("este","./calle1");
    //AddExit("oeste","./camino0");
    AddExit("oeste", CAMINOS "/norte_marhalt/camino01");
    AddExit("sur","./tiendas/bancoh");
    AddExit("norte","./tiendas/posada");
    AddDoor("sur", "la puerta del banco", "Es la puerta para entrar en el banco.\n",
    ({"puerta", "puerta del banco", "puerta del sur"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
    AddDoor("norte", "la puerta de la posada",
    "Es la puerta principal de la posada de Nandor.\n",
    ({"puerta", "puerta principal", "puerta de la posada", "puerta del norte",
        "puerta principal de la posada"}));

    AddCaravana(CARAVANA_ZARKAM);
    AddCaravana(CARAVANA_KHA_ANNU);
    AddCaravana(CARAVANA_NHALIN);

}

