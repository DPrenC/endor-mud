/*****************************************************************************************
 ARCHIVO:       murcielago.c
 AUTOR:         Ztico
 FECHA:         20-01-2006
 DESCRIPCIÓN:   Un murciélago malo maloso...
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un murciélago", "murcielago", ([GC_TORPE: 10]), GENERO_MASCULINO);
    AddId(({"murciélago", "murcielago_faeria"}));
    SetShort("un murciélago");
    SetLong("Es un murcielago. Te recuerda a una pequenya rata, solo que con alas y unas "
        "grandes orejas. Es de color oscuro, casi negro, y parece bastante enfadado.\n");
        
    InitChats(1, ({"Un murciélago revolotea a tu alrededor.\n"}));
    
    SetAggressive(2);
}
