/********************
Fichero: /d/akallab/comun/pnj/z_ciudad/maoli.c
Autor: Yalin.
Fecha: 28/11/2007 23:03
Descripción: Tendera para la sastrería de Zarkam.
********************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;
    
create()
{
    ::create();
    SetStandard("Maoli","orco",12,GENERO_FEMENINO);
    SetName("Maoli");
    SetShort("Maoli la sastre");
    SetLong("Maoli es una orca de mediana edad. Es algo pequeña para los de su raza, pero lo "
        "compensa su forma de ser: es todo nervio. En su sastrería, Maoli hace todo tipo de "
        "ropa. Es una buena artesana y su trabajo es bien conocido y apreciado en toda esta "
        "región.\n");
    AddId(({"maoli","Maoli","sastre","costurera","orco","orca"}));
}
