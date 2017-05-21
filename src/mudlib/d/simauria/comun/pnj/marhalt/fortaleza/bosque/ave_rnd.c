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
        SetLong("Se trata de un peque�o cuco que anida en el tronco de un �rbol. "
                "ahora mismo esta picoteando algo sobre una rama, mientras "
                "te deleita con su tan t�pico canto.\n");
        SetIds(({"pajaro","cuco"}));
        SetAds(({"peque�o"}));
        break;
    case 1:
        SetShort("un color�n");
        SetStandard("un color�n","pajaro",4+random(4)+2,GENDER_MALE);
        SetLong("Es un p�jaro multicolor, com�nmente conocido como color�n. Es "
                "de color azul, rojo y amarillo, realmente vistoso, te choca "
                "que un p�jaro que se camufla tan mal en su entorno haya sobrevivido "
                   "al proceso de evoluci�n.\n");
        SetIds(({"pajaro","color�n","p�jaro","colorin"}));
        break;
    default:
        SetShort("un halc�n");
        SetStandard("un halc�n","pajaro",8+random(4)+4,GENDER_MALE);
        SetLong("Es un majestuoso halc�n. Su plumaje pardo esta totalmente liso, y su "
                "mirada destella con el brillo de la inteligencia. Sus ojos se posan "
                "en t�, mientras emprende el vuelo.\n");
        SetIds(({"p�jaro","halc�n","pajaro","halcon"}));
        break;
    }

    SetNoise("Oyes sus escandalosos chillidos.\n");
    SetWeight(2000);
    SetAggressive(0);
    SetGoChance(10);

    SetHands(({({"el pico",0,2})}));

    AddWalkZones(ROOMFB(""));
}

