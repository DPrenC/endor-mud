/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/casas/tablado.c
Autor: Lug y Yalin
Fecha: 20/05/2007
Descripción: plataforma para entrenamiento de salto en la bodega de Sloch.
****************************************************************************/
#include "path.h"
#include <properties.h>
#include <moving.h>
#include <skills.h>
#include <sounds.h>
inherit SHERALD("ceroom");
#define AO  (TP->QueryGenderEndString())

public int salto()
{
    if (TP->QueryStatus() == STATUS_SLEEPING) return 0;
    if (TP->QueryTP() < 5) return notify_fail("Estás muy cansad"+AO+" para saltar.\n",
        NOTIFY_NOT_VALID);
    int salta = TP->UseSkill(HAB_SALTAR,TP->QueryDex());
    if (salta >= 0)
    {
        int azar;
        switch(salta)
        {
            case 0..19: azar=d20();break;
            case 20..49: azar=d10();break;
            default: azar=d4();break;
        }
        if (azar ==1 || salta>=80)
        {
            // salta bien, consigue el objetivo.
            TP->AddTP(-5);
            say(CAP(TP->QueryName())+" da un magnífico salto, y consigue llegar a "
                "tocar el canalón sin mayores problemas.\n",TP);
            return notify_fail("Saltas con gran maestría, y aterrizas "
                "impecablemente sobre la plataforma tras golpear el canalón.\n",
                NOTIFY_NOT_VALID);
        }
        else if (salta >=19)
        {
            //Sabe saltar, pero no demasiado bien.
            TP->AddTP(-5);
            TP->AddHP(-5);
            say(CAP(TP->QueryName())+" salta hacia el canalón, intentando golpearlo "
                "con los dedos, pero no consigue la altura suficiente, y cae sobre "
                "la plataforma haciéndose algo de daño.\n",TP);
            return notify_fail("Saltas hacia el canalón y estiras el brazo en un "
                "intento de tocarlo, pero tu salto no ha sido muy bueno, y no llegas "
                "a tu objetivo.\n",NOTIFY_NOT_VALID);
        }
        // Salta fatal, y se golpea contra la tinaja, pierde mucha vida.
        TP->AddTP(-5);
        TP->AddHP(-15);
        say(CAP(TP->QueryName())+" intenta saltar hacia el canalón, pero es "
            "demasiado torpe, y se golpea cayendo al piso de la habitación. "
            "Esperemos que siga viv"+AO+".\n",TP);
        write("Saltas hacia el canalón, pero tu poca experiencia hace que "
            "pierdas el equilibrio, y, golpeándote con la tinaja, caes al "
            "piso de la bodega, haciéndote bastante daño.\n");
        tell_room(SHERALD("casas/bodega01"),CAP(TP->QueryName())+" cae "
            "estrepitosamente desde la plataforma superior... ¡Qué tortazo...!\n");
            TP->move(SHERALD("casas/bodega01"),M_SILENT);
        play_sound(find_object(SHERALD("casas/bodega01")),SND_SUCESOS("caida_fuerte"));
        TP->LookAfterMove();
        return 1;
    }
    //menos de 0. Ni siquiera sabe saltar.
    say(CAP(TNAME)+" da un pequeño saltito.\n",TP);
    return notify_fail("Das un temeroso saltito... ¡Pero si no sabes saltar!\n",
        NOTIFY_NOT_VALID);
}

create()
{
    ::create();
    SetPreIntShort("sobre");
    SetIntShort("una plataforma elevada en la bodega");
    SetIntLong("Estás sobre una plataforma de madera, justo frente a la gran "
        "tinaja que recoge el vino.\nA un par de metros sobre tu cabeza, "
        "pasa el canalón que transporta el vino del pisadero a la tinaja, y "
        "que baja del piso superior hasta la boca de la tinaja.\n En los "
        "días de la cosecha, los mozos de la aldea suelen probar a golpear el "
        "canalón con la mano saltando desde aquí. Quizá te gustaría "
        "probar tú...\n");
    SetIntBright(20);
    SetIntSmell("Hay un fuerte olor a alcohol etílico y a aire enrarecido. "
        "No deberías quedarte aquí mucho tiempo.\n");
    SetIntNoise("No oyes nada. Al vino no le sientan bien los ruidos.\n");
    AddDetail(("tinaja"), "Es un monstruoso cilindro de unos 6 o 7 metros "
        "de altura, y unos 4 de ancho, algo panzudo hacia su parte media, y "
        "en forma de cono invertido en su parte más baja.\nA unos 70 "
        "centímetros del suelo, salen caños de varios puntos, para pasar el "
        "vino ya hecho a los toneles. Esto hace que siempre quede algo de "
        "vino espeso y con posos en la base de la tinaja, que es lo que se "
        "conoce como  la madre del vino, y ayudará a fermentar la próxima "
        "llenada de mosto.\nBajo cada caño, una depresión circular en el "
        "suelo permite colocar el barril, de forma que quede estable y con "
        "la boca ajustada al grifo.\n");
    AddDetail(({"caño","caños","canyo","canyos","grifo","grifos"}),
        "Desde aquí no puedes verlos.\n");
    AddDetail(({"canal","canalon","canalón"}), "Es un semicilindro de madera, "
        "que va desde la salida del lagar, arriba al norte, hasta la boca de "
        "la tinaja, y sirve para trasegar el mosto que va soltando la uva al "
        "ser pisada.\nLos jóvenes de la aldea gustan de probar a golpearlo "
        "con la mano saltando. ¿Quieres probar tú?\n");
    AddRoomCmd("probar","salto");
    AddRoomCmd("saltar","salto");
    AddExit("bajar",SHERALD("casas/bodega01"));
}

