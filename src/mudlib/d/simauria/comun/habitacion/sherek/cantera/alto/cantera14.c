/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/alto/cantera14.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripci�n: Salida de la cantera de Sherek.
****************************************************************************/

#include "path.h"
#include <moving.h>
inherit SHERCAN("alto/cantera");

private int IrSur()
{
    if (!TP || !query_once_interactive(TP)) return 0;
    string msg, msg2;
    // en estas variables guardamos el mensaje que se mandar� al player
    // y el mensaje que se mandar� a la habitaci�n
    object ob; // para el pico

    if (!TP->QueryAttribute("sabeminas"))
    {
        msg = "El guardia te mira con sorna dici�ndote: Bien, "
              "espero que hayas escarmentado.\nPuedes irte, de todos modos "
              "no necesitamos muchos bloques ahora.\n";
        msg2 = "El guardia mira con sorna a " + CAP(TNAME) + ", dici�ndole: Bien, espero "
               "que hayas escarmentado.\nPuedes "
               "irte, de todos modos no necesitamos muchos bloques ahora.\n";
        if (ob = present("PicoQuest", TP))
        // si tiene el pico, se a�ade el mensaje de que se lo quita
        {
            msg += "Por cierto, ya no "
                   "necesitar�s el pico, as� que lo dejaremos aqu�.\nY "
                   "quit�ndote el pico, te empuja hacia fuera.\n";
            msg2 += "Por cierto, ya no "
                   "necesitar�s el pico, as� que lo dejaremos aqu�.\nY acto seguido, le "
                   "empuja hacia fuera.\n";
            ob->remove();
        }
        else
        {
            msg += "Acto seguido, te empuja hacia fuera.\n";
            msg2 += "Acto seguido, le empuja hacia fuera.\n";
        }
        write(msg);
        say(msg2, TP);
        TP->SetFollowers(0);
        TP->move(SHERCAN("alto/entrada"), M_GO);
        return 1;
    }
    say(CAP(TNAME) + " intenta salir de la cantera, pero el "
            "guardia le grita: '�Eh, t�! �D�nde crees que vas? �Vuelve a tu "
            "trabajo.'\nVisto esto, " + CAP(TNAME)+" decide no "
            "insistir.\n", TP);
    return notify_fail("El guardia te mira con mala cara y grita: �Eh, t�! "
                       "�D�nde crees que vas? �Vuelve a tu trabajo!\n");
}

create()
{
    ::create();
    SetSafe("No, no, no. Hay muchos guardias ah� fuera, podr�as quedarte "
        "como esclavo para toda la vida.\n");
    AddItem(PNJ("sherek/aldea/guardian2"),REFRESH_DESTRUCT,1);
    AddExit("nordeste",SHERCAN("alto/cantera23"));
    AddExit("norte",SHERCAN("alto/cantera24"));
    AddExit("sur",SF(IrSur));
    pongo();
}
