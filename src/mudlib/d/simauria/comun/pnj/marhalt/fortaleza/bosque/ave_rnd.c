/*
DESCRIPCION : pajarraco aleatorio
FICHERO     : /d/simauria/comun/pnj/simauria/fortaleza/bosque/ave_rnd.c
MODIFICACION: 04-07-00 [m] Maler:Creacion
*/

#include "path.h"
#include <properties.h>

inherit NPC;

create() {
    ::create();
    switch(random(3))
    {
    case 0:
        SetShort("un cuco");
        SetStandard("un cuco","pajaro",2+random(2),GENDER_MALE);
        SetGender(GENDER_MALE);
        SetLong("Se trata de un pequeño cuco que anida en el tronco de un árbol. "
                "ahora mismo esta picoteando algo sobre una rama, mientras "
                "te deleita con su tan típico canto.\n");
        SetIds(({"pajaro","cuco"}));
        SetAds(({"pequeño"}));
        break;
    case 1:
        SetShort("un colorín");
        SetStandard("un colorín","pajaro",4+random(4)+2,GENDER_MALE);
        SetLong("Es un pájaro multicolor, comúnmente conocido como colorín. Es "
                "de color azul, rojo y amarillo, realmente vistoso, te choca "
                "que un pájaro que se camufla tan mal en su entorno haya sobrevivido "
                   "al proceso de evolución.\n");
        SetIds(({"pajaro","colorín","pájaro","colorin"}));
        break;
    default:
        SetShort("un halcón");
        SetStandard("un halcón","pajaro",8+random(4)+4,GENDER_MALE);
        SetLong("Es un majestuoso halcón. Su plumaje pardo esta totalmente liso, y su "
                "mirada destella con el brillo de la inteligencia. Sus ojos se posan "
                "en tí, mientras emprende el vuelo.\n");
        SetIds(({"pájaro","halcón","pajaro","halcon"}));
        break;
    }

    SetNoise("Oyes sus escandalosos chillidos.\n");
    SetWeight(2000);
    SetAggressive(0);
    SetGoChance(10);

    SetHands(({({"el pico",0,2})}));

    AddWalkZones(ROOMFB(""));
}

