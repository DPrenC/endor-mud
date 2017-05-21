/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/cantera/demonio.c
Autor: Lug y Yalin
Fecha: 08/01/2007
Descripción: Demonio aleatorio para el último nivel del laberinto
****************************************************************************/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <moving.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    switch (d4())
    {
        case 1:
            SetStandard("un niño demonio","demonio",([ GC_LUCHADOR:24+d6() ]),GENERO_MASCULINO);
            SetShort("un niño demonio");
            SetLong("Es un pequeño demonio. Su cuerpo brilla con un color "
                "rojo oscuro incandescente. La cola larga con garras que "
                "nace de su espalda se agita en el aire amenazadoramente.\n"
                "Aunque es aún un niño, no te fíes de su tamaño. Los "
                "demonios son muy agresivos.\n");
            AddId(({"niño","ninyo","ninyo demonio","niño demonio","demonio"}));
            SetAlign(-300);
            SetWhimpy(30); // es un niño, se resiste a morir
            AddItem(ARMA("sherek/cantera/barra"),REFRESH_REMOVE,1,SF(wieldme));
            InitAChats(10,({"El niño demonio te clava los dientes.\n",
                "El niño demonio ruge: ¡Quiero tu hígado! Hace mucho que no "
                    "como buena carne.\n"}));
        break;
        case 2:
            SetStandard("una niña demonia","demonio",([ GC_LUCHADOR:24+d6() ]),GENERO_FEMENINO);
            SetShort("una niña demonia");
            SetLong("Es una pequeña demonia. Su cuerpo brilla con un color "
                "rojo oscuro incandescente. La cola larga con garras que "
                "nace de su espalda se agita en el aire amenazadoramente.\n"
                "Aunque es aún una niña, no te fíes de su tamaño. Los "
                "demonios son muy agresivos.\n");
            AddId(({"demonia","niña","niña demonia","ninya","ninya demonia"}));
            SetAlign(-200);
            SetWhimpy(30); // es una niña, se resiste a morir
            AddItem(ARMA("sherek/cantera/cadena"),REFRESH_REMOVE,1,SF(wieldme));
            InitAChats(10,({"La niña demonia te clava los dientes.\n",
                "La niña demonia ruge: ¡Quiero tu corazón! Hace mucho que no "
                    "como buena carne.\n"}));
        break;
        case 3:
            SetStandard("un demonio","demonio",([ GC_LUCHADOR:44+d6() ]),GENERO_MASCULINO);
            SetShort("un demonio");
            SetLong("Naturalmente, es un demonio. Su cuerpo brilla con un "
                "color rojo oscuro incandescente. La cola larga con garras "
                "que nace de su espalda se agita en el aire amenazadoramente.\n\n");
            SetAlign(-500);
            AddItem(ARMA("sherek/cantera/cuchilla"),REFRESH_REMOVE,1,SF(wieldme));
            InitAChats(10,({"El demonio ruge: ¡Vas a morir! ¡Nunca saldrás de aquí!",
                "El demonio grita: ¿Cómo te atreves a entrar en nuestras cuevas?\n"}));
        break;
        case 4:
            SetStandard("una demonia","demonio",([ GC_LUCHADOR:44+d6() ]),GENERO_FEMENINO);
            SetShort("una demonia");
            SetLong("Es una demonia sucia y furiosa. Su cuerpo brilla con un "
                "color rojo oscuro incandescente. La cola larga con garras "
                "que nace de su espalda se agita en el aire amenazadoramente.\n\n");
            SetAlign(-400);
            AddId("demonia");
            AddItem(ARMA("sherek/cantera/hacha"),REFRESH_REMOVE,1,SF(wieldme));
            InitAChats(10,({"La demonia ruge: ¡Vamos a destriparte para cenar! ¡Nunca saldrás de aquí!",
                "La demonia grita: ¡Ésta es mi casa! ¡Lárgate o muere!\n"}));
        break;
    }
    SetHP(QueryMaxHP());
    SetAggressive(1);
    SetGoChance(90);
    AddWalkZones(SHERCAN("fondo"));
}
