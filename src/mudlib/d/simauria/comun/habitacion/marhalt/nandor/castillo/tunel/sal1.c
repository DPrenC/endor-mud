/**************************************************************************/
/*                                                                        */
/*  [k] Kintups                                                           */
/*                                                                        */
/*  [k] Sun 19 Nov 2000 --- Revisados los textos y a�adidos los W()       */
/*                                                                        */
/**************************************************************************/

#include "./path.h"
#include <moving.h>


#define LOCATE "Algun lugar del norte de Marhalt"
inherit SIM_ROOM;

haz_norte()
{
    tell_room(CASTILLO("camino/camino14"),
    TP->QueryName()+" sale de entre unos matorrales.\n");
    write("Sigilosamente sales a la luz...\n.... Y apareces en medio de un camino!\n");
    TP->move(CASTILLO("camino/camino14"),M_GO,"norte");
    tell_room(MARH("nandor/castillo/tunel/sal1"),
    TP->QueryName()+" sale del t�nel.\n");
    return 1;
}

create()
{
    ::create();
    SetLocate(LOCATE);
    SetIntShort("la salida de un t�nel");
    SetIntLong("Est�s en un oscuro y fr�o t�nel. Sin embargo, ves una luz hacia el "
        "norte, mientras que al oeste te internas nuevamente en la oscuridad.\n");
    SetIntBright(25);
    AddDetail(({"luz","luz al final del tunel","norte","luz al final del t�nel"}),
    "�S�! ���Seguro que lleva hacia la salida!!!\n");
    AddExit("norte",SF(haz_norte));
    AddExit("oeste","./pasadizo28");
}
