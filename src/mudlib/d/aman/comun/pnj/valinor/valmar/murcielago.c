/*****************************************************************************************
 ARCHIVO:       murcielago.c
 AUTOR:         Ztico
 FECHA:         20-01-2006
 DESCRIPCI�N:   Un murci�lago malo maloso...
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un murci�lago", "murcielago", ([GC_TORPE: 10]), GENERO_MASCULINO);
    AddId(({"murci�lago", "murcielago_faeria"}));
    SetShort("un murci�lago");
    SetLong("Es un murcielago. Te recuerda a una pequenya rata, solo que con alas y unas "
        "grandes orejas. Es de color oscuro, casi negro, y parece bastante enfadado.\n");
        
    InitChats(1, ({"Un murci�lago revolotea a tu alrededor.\n"}));
    
    SetAggressive(2);
}
