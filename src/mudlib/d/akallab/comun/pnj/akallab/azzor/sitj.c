/****************************************************************************
Fichero: sitj.c
Autor: Riberales
Creación: 06/12/05
Descripción: Otro orco más pa repoblar Azzor.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

public create()
{
    ::create();

    seteuid(getuid());

    SetStandard("Sitj","orco",([GC_NINGUNO:72+random(5)]),GENDER_MALE);
    SetShort("Sitj");
    SetLong("Sitj es un orco, de media estatura para su raza. No crees que "
            "tenga muy buenos modales, pues parece que siempre está solo. "
            "Cuentan las malas lenguas que Manak lo expulsó de su tripulación "
            "por un problema de disciplina. De todas formas, no crees que"
            "sea buena idea hablar con él, en vista de la cara de orco "
            "amargado que lleva.\n");

    SetIds(({"sitj","Sitj","orco"}));

    AddQuestion(({"manak","Manak"}),
                (:"Sitj dice: Escucha, "+ TP->QueryRace()+ ", ese Manak es "
                  "un farsante. Siempre ha tenido engañada a su tripulación, "
                  "y nadie decía nada.\n":),1);

    AddQuestion(({"tripulacion","tripulación"}),
                  "Sitj dice: La tripulación tenía miedo de perder su "
                  "puesto. Pero yo tenía unos principios, y ese desgraciado "
                  "no me los iba a pisotear.\n",1);

    AddQuestion("principios","Sitj se vuelve hacia ti con mala cara mientras "
                             "te dice: ¿Que cuales son mis principios? Uno "
                             "de ellos es desconfiar de la gente que hace "
                             "demasiadas preguntas, así que mejor lárgate de "
                             "mi vista.\n",1);

    InitChats(3,({
              "Sitj exclama: Maldito Manak, ojalá te pudras en el mar.\n",
            "sitj gruñe mientras murmura algo ininteligible.\n"}));

    InitAChats(2,({"Sitj grita: ¿Quién te ha mandado venir? ¿Manak?\n"}));

}

