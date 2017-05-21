/*
DESCRIPCION : aguila
FICHERO     : /d/simauria/comun/pnj/simauria/fortaleza/bosque/aguila.c
MODIFICACION: 03-07-00 [m] Maler:Creacion;Mangao del boske de angor
*/

#include "path.h"
#include <properties.h>

inherit NPC;

create()
{
    ::create();
    switch(random(2))
    {
    case 0:
        SetStandard("un águila","aguila",14+random(2),GENDER_MALE);
        SetShort("un joven aguilucho");
        AddId(({"águila","aguila","aguilucho"}));
        AddAdjective("joven");
        SetLong("Es un joven aguilucho con grandes alas enormes y un "
                "precioso plumaje. Tiene un pico robusto y afilado con el "
                "que desgarra trozos de carne de sus presas a las que "
                "atrapa. Por sus movimientos deduces que aun no posee la "
                "habilidad y fuerza de sus mayores.\n");
        break;
    case 1:
        SetStandard("un águila","aguila",16+random(2),GENDER_MALE);
        SetShort("un águila real");
        AddId(({"águila","aguila"}));
        AddAdjective("real");
        SetLong("Se trata de un aguila de coloracion marron oscura, con "
                "reflejos dorados en la nuca. Suelen habitar en los bosques, "
                "aunque anidan en zonas rocosas. Su pico es lo "
                "suficientemente poderoso como para rasgar la carne de sus "
                "presas. Posee la precision necesaria para lanzarse en "
                "picado sobre ti, sacarte los ojos y emprender de nuevo "
                "el vuelo.\n");
       break;
    default:
        SetStandard("un águila","aguila",18+random(2),GENDER_MALE);
        SetShort("un águila imperial");
        AddId(({"águila","aguila"}));
        AddAdjective("imperial");
        SetLong("Es una majestuosa aguila imperial, con unas alas enormes y "
                "un precioso plumaje. Tiene un pico robusto y afilado con el "
                "que desgarra trozos de carne de sus presas a las que "
                "atrapa firmemente con sus poderosas garras.\n");
        break;
    }

    SetNoise("Oyes sus escandalosos chillidos.\n");
    SetWeight(2000);
    AddId(({"aguila"}));

    SetAggressive(random(2));
    SetGoChance(10);

    SetHands(({({"una garra",0,10}), ({"el pico",0,15})}));

    InitChats(3,({
      "El aguila real se posa ante ti desafiante.\n",
      "El aguila remonta el vuelo con una presa entre sus garras.\n",
      "El aguila vuela majestuosamente con sus grandes alas extendidas.\n",
      "Chiiiiii, chiiiiii!\n",
      "El aguila vuela en circulos observandolo todo desde las alturas.\n"
      "El aguila pasa cerca tuya en vuelo rasante.\n",
      "El aguila te observa desde una rama.\n",
      "El aguila busca algun roedor.\n"
    }));

    InitAChats(3,({
      "El aguila pierde algunas plumas en el combate.\n",
      "El aguila se lanza hacia ti.\n",
      "El aguila clava sus ojos en ti.\n"
    }));
    AddWalkZones(ROOMFB(""));
}
