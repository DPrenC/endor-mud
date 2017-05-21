/*
DESCRIPCION  : bosque de Morak
FICHERO      : bosque27.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <moving.h>
inherit ROOM;

int ir_norte()
{
    if (TP->QuerySize()==P_SIZE_SMALL)
    {
        write("Entras por el agujero.\n");
        say(capitalize(TP->QueryName())+" entra por el agujero.\n",TP);
        TP->SetFollowers(0);
        return TP->move(BOSQUE_MORAK("galeria"),M_GO);
    }
    else
    {
        say(capitalize(TP->QueryName())+" intenta entrar en el agujero pero "
            "no cabe.\n",TP);
        return notify_fail("Eres demasiado grande para entrar en el "
            "agujero.\n",NOTIFY_NOT_VALID);
    }
}

create()
{
    ::create();
    SetPreIntShort("junto a");
    SetIntShort("un arroyo en el bosque de Morak");
    SetIntLong("Est�s en un peque�o claro junto a la orilla de un arroyo. El "
    "arroyo es una corriente de agua r�pida que, a trav�s de su irregular "
        "cauce, cruza este bosque. La tierra en esta zona apartada del "
        "bosque es h�meda y la hierba crece abundantemente. Frente a ti, al "
        "norte, unas grandes pe�as marcan el principio de las monta�as. Unas "
        "altas hierbas ocultan de manera algo tosca un extra�o agujero entre "
        "las rocas y la tierra bajo ellas.\n");
    AddDetail(({"hierbas"}),"�sta es una zona h�meda, hay hierba por todas "
        "partes!\n");
    AddDetail(({"penyas","pe�as","rocas"}),"Frente a ti se halla un grupo "
        "de grandes pe�as, posiblemente desprendidas de las monta�as que "
        "comienzan al norte de aqu�. Junto a la parte baja de una de las "
        "rocas, toscamente oculto por unas altas hierbas, puedes observar un "
        "peque�o agujero.\n");
    AddDetail(({"agujero"}),"Junto a la parte baja de una de las rocas, "
        "toscamente oculto por unas altas hierbas, se encuentra excavado en "
        "la tierra un extra�o agujero. El agujero tiene una altura de unos "
        "30 o 40 cent�metros y conduce a lo que parece ser una galer�a "
        "subterr�nea. Tienes la extra�a impresi�n de que esta demasiado bien "
        "hecho como para ser obra de un zorro o un conejo.\n");
#include "arroyo.h"
    SetLocate("bosque de Morak");
    SetIndoors(0);
    AddExit("oeste",BOSQUE_MORAK("bosque28"));
    AddExit("sudeste",BOSQUE_MORAK("bosque25"));
    AddExit("sur",BOSQUE_MORAK("bosque26"));
    AddExit("norte",SF(ir_norte));
}
