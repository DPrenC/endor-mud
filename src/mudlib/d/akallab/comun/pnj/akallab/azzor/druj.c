/****************************************************************************
Fichero: druj.c
Autor: Kastwey
Fecha: 06/12/2005
Descripción: Un orco pendenciero en Azzor.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
#include <materials.h>

inherit NPC;

create()
{
    ::create();
    seteuid(getuid());
    SetStandard("Druj","orco",([GC_LUCHADOR:50]),GENDER_MALE);
    AddId("pendenciero");
    SetShort("Druj el pendenciero");
    SetLong("Druj es un viejo orco que lleva muchos combates a sus espaldas. Ahora se pasa el "
        "día en las tabernas pero aún así, el fulgor de sus malignos ojos refleja sus ansias de "
        "riña y pelea. Tiene un colmillo partido y su pelaje oscuro rezuma mal olor. Está casi "
        "siempre borracho.\n");
    SetSmell("Parece que hace tiempo que no se lava.\n");
    SetAlcohol(120);
    AddItem(ARMOUR,REFRESH_REMOVE,
            ([P_SHORT:"una coraza de hierro",
              P_LONG:"Es una coraza muy aboyada pero que parece "
                     "extraordinariamente resistente.\n",
              P_IDS:({"coraza","coraza de hierro","coraza aboyada"}),
              P_ARMOUR_TYPE:AT_CORAZA,
              P_AC:11,
              P_MATERIAL:M_HIERRO,
              P_WEIGHT:8000,
              P_VALUE:1300,
              P_QUALITY:70,
              P_RESET_QUALITY:90,
              P_GENDER:GENDER_FEMALE,
              P_NUMBER:NUMERO_SINGULAR]),SF(wearme));

    AddItem("/obj/armas/espada_ancha",REFRESH_REMOVE,
            ([P_SHORT:"una espada",
            P_LONG:"Es una espada llena de muescas en el filo pero lejos de "
                   "deteriorar el arma parecen hacerla más peligrosa.\n",
            P_IDS:({"espada","espada con muescas"})]),SF(wieldme));

    AddItem("/obj/money",REFRESH_REMOVE,
            ([P_MONEY:(["oro":1 + random(10),"plata": 1 + random(20),
                        "cobre":random(15)])]));

    InitChats(4,({"Druj rezonga: Esta sally nos engaña a todos con su cerveza aguada.\n",
        "Druj grita: ¡Por mis colmillos! ¡Juro que haré trizas al primero que se me ponga por "
            "delante!\n",
        "Druj grita: ¡Eh, fea! ¿Quieres que me muera de sed?\n"}));

    InitAChats(10,({"¡Druj grita: Maldito enjendro! ¡Te partiré en dos con "
                    "mi espada!\n",
                    "Druj dice: ¡Sally servirá tu sangre en lugar de vino!\n",
                    "Druj chilla: ¡Nadie vive tras enfrentarse con druj!\n"}));
}
