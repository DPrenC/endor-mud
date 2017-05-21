/*****************************************************************************************
 ARCHIVO:       driada.c
 AUTOR:         Ztico
 FECHA:         02-05-2005
 DESCRIPCI�N:   Dr�ada del Bosque de las Dr�adas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("dr�ada", "driada", ([GC_GUARDABOSQUE: 45]), GENERO_FEMENINO);
    SetShort("una dr�ada");
    SetLong("Es una criatura esbelta de boca rosada, senos peque�os, muslos delgados y "
        "rostro de una inexpresable belleza. Su cabello es casta�o y posee una "
        "pronunciada textura frondosa, del color de las hojas, mientras su piel parece "
        "madera pulida. Al igual que un hada, no tiene vello p�bico; al igual que un "
        "hada, parece hecha de un material menos tosco que la sangre, la carne y el "
        "hueso.\nTiene una mirada salvaje e insondable en sus grandes ojos almendrados, "
        "sin embargo, emana una luz dorada que calma el esp�ritu de quien la ve.\n");
    
    InitChats(2,
        ({"Una dr�ada comienza a cantar dulcemente.\n",
          "Una dr�ada te mira con ojos insondables.\n",
          "Una dr�ada se acaricia la piel con delicados movimientos.\n"}));
}
