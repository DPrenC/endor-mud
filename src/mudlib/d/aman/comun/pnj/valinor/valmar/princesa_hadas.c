/*****************************************************************************************
 ARCHIVO:       princesa_hadas.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCI�N:   Princesa, hija de Twyligh.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("biab", "duende", ([GC_CONJURADOR: 50]), GENERO_FEMENINO);
    AddId(({"princesa", "hada", "la princesa de las hadas"}));
    SetShort("biab, la princesa");
    SetLong("Esta adorable hada, es la princesa de las hadas, es delgada y fr�gil como "
        "una rama de sauce, es peque�a y su piel, blanca, tiene un ligero tono rosado. "
        "El cabello, liso y del color del oro, lo lleva peinado en una trenza que le "
        "rodea la cabeza como una corona, lo que le confiere un aire majestuoso, en "
        "consecuencia con su porte erguido. La mirada de sus ojos grises es franca y "
        "sincera. Los suaves y sonrientes labios, aunque est�n f�namente dibujados, son "
        "fuertes, y hay algo en la forma rotunda de la mand�bula que delata cierta "
        "obstinaci�n.\n");
    InitChats(3,
          ({"La princesa canturrea una mel�dica cancioncilla.\n",
            "La joven princesita se entretiene trenzando coronas y collares con todos "
            "los tipos de flores que se encuentran por el bosque.\n"}));
}
