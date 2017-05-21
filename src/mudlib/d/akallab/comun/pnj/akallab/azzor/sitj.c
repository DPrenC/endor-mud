/****************************************************************************
Fichero: sitj.c
Autor: Riberales
Creaci�n: 06/12/05
Descripci�n: Otro orco m�s pa repoblar Azzor.
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
            "tenga muy buenos modales, pues parece que siempre est� solo. "
            "Cuentan las malas lenguas que Manak lo expuls� de su tripulaci�n "
            "por un problema de disciplina. De todas formas, no crees que"
            "sea buena idea hablar con �l, en vista de la cara de orco "
            "amargado que lleva.\n");

    SetIds(({"sitj","Sitj","orco"}));

    AddQuestion(({"manak","Manak"}),
                (:"Sitj dice: Escucha, "+ TP->QueryRace()+ ", ese Manak es "
                  "un farsante. Siempre ha tenido enga�ada a su tripulaci�n, "
                  "y nadie dec�a nada.\n":),1);

    AddQuestion(({"tripulacion","tripulaci�n"}),
                  "Sitj dice: La tripulaci�n ten�a miedo de perder su "
                  "puesto. Pero yo ten�a unos principios, y ese desgraciado "
                  "no me los iba a pisotear.\n",1);

    AddQuestion("principios","Sitj se vuelve hacia ti con mala cara mientras "
                             "te dice: �Que cuales son mis principios? Uno "
                             "de ellos es desconfiar de la gente que hace "
                             "demasiadas preguntas, as� que mejor l�rgate de "
                             "mi vista.\n",1);

    InitChats(3,({
              "Sitj exclama: Maldito Manak, ojal� te pudras en el mar.\n",
            "sitj gru�e mientras murmura algo ininteligible.\n"}));

    InitAChats(2,({"Sitj grita: �Qui�n te ha mandado venir? �Manak?\n"}));

}

