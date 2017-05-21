/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera214.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
#include <moving.h>
inherit SHERCAN("fondo/cantera2");

public int mevoy()
{
    object ob = present("PicoQuest",TP);
    if (!ob) return notify_fail("No tienes el pico apropiado para picar aquí.\n",
        NOTIFY_NOT_VALID);
    if (ob->QueryEquipped() != TP) return notify_fail("Tendrás que empuñar el "
        "pico para poder picar.\n",NOTIFY_NOT_VALID);
    if (TP->QueryTP() <=5) return notify_fail("Estás exausto. Tendrás que "
        "descansar para seguir trabajando.\n",NOTIFY_NOT_VALID);
    if (TP->Fighting()) return notify_fail("Estás luchando, no puedes picar.\n",
        NOTIFY_NOT_VALID);
    TP->AddTP(-5);
    switch (d10())
    {
        case 1..3:
            say(CAP(TP->QueryName())+" se pone a cavar en el suelo... "
                "Parece que avanza algo en su labor.\n",TP);
            return notify_fail("Cavas con el pico... ¡Qué cansancio!\nParece "
                "que consigues apartar algunos guijarros...\n",NOTIFY_NOT_VALID);
        break;
        case 4..6:
            say(CAP(TP->QueryName())+" pica con insistencia. Las rocas van "
                "cediendo poco a poco.\n",TP);
            return notify_fail("Picas y picas... ¡No puedes con tu alma!\nEl "
                "suelo empieza a ceder.\n",NOTIFY_NOT_VALID);
        break;
        case 7..9:
            say(CAP(TP->QueryName())+" se empeña en picar a pesar de que no "
                "es su oficio...\nSin embargo, parece que consigue despejar "
                "el suelo...\n",TP);
            return notify_fail("Esto de picar no es lo tuyo... ¡Qué duro es "
                "trabajar!\nVes como el suelo se va hundiendo ante ti.\n",
                NOTIFY_NOT_VALID);
        break;
        case 10:
            ob->remove();
            if (ob) destruct(ob);
            write("Das un fuerte golpe con el pico... ¡Aaaaahhhhh!\nEl suelo "
                "se abre a tus pies, y te precipitas entre trozos de roca.\n"
                "El pico se te escapa de las manos, y se hunde en el río.\n");
            say(CAP(TP->QueryName())+" da un fuerte golpe con el pico. Oyes "
                "crujir siniestramente el suelo, y ves como "+CAP(TP->QueryName())+
                " desaparece de tu vista.\n",TP);
            tell_room(SHERCAN("fondo/salida"),CAP(TP->QueryName())+" cae "
                "desde lo alto, envuelto en polvo y guijarros.\n");
            TP->SetFollowers(0);
            return TP->move(SHERCAN("fondo/salida"),M_GO);
        break;
    }
    return 0;
}

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"El suelo presenta aquí una zona diferente, "
        "como si tiempo atrás se hubiera sepultado algo. Está cubierto por "
        "una capa de guijarros que parecen comprimidos a golpes.\n");
    AddDetail(({"suelo","guijarros","guijarros comprimidos","capa de guijarros"}),
        "Son fragmentos de roca desmenuzada, acumulados aquí. Tienes la "
        "impresión de que no es natural, como si alguien hubiera "
        "ocultado algo bajo ellos.\n");
    AddRoomCmd("picar","mevoy");
    AddRoomCmd("cavar","mevoy");
    AddRoomCmd("excavar","mevoy");
    AddExit("nordeste",SHERCAN("fondo/cantera223"));
    AddExit("norte",SHERCAN("fondo/cantera224"));
    pongo();
}
