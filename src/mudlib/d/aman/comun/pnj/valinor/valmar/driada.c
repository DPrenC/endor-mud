/*****************************************************************************************
 ARCHIVO:       driada.c
 AUTOR:         Ztico
 FECHA:         02-05-2005
 DESCRIPCIÓN:   Dríada del Bosque de las Dríadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("dríada", "driada", ([GC_GUARDABOSQUE: 45]), GENERO_FEMENINO);
    SetShort("una dríada");
    SetLong("Es una criatura esbelta de boca rosada, senos pequeños, muslos delgados y "
        "rostro de una inexpresable belleza. Su cabello es castaño y posee una "
        "pronunciada textura frondosa, del color de las hojas, mientras su piel parece "
        "madera pulida. Al igual que un hada, no tiene vello púbico; al igual que un "
        "hada, parece hecha de un material menos tosco que la sangre, la carne y el "
        "hueso.\nTiene una mirada salvaje e insondable en sus grandes ojos almendrados, "
        "sin embargo, emana una luz dorada que calma el espíritu de quien la ve.\n");
    
    InitChats(2,
        ({"Una dríada comienza a cantar dulcemente.\n",
          "Una dríada te mira con ojos insondables.\n",
          "Una dríada se acaricia la piel con delicados movimientos.\n"}));
}
