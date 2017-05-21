/********************
Fichero: /d/akallab/comun/pnj/z_ciudad/nentab.c
Autor: Yalin.
Fecha: 31/10/2007 20:31:00
Descripción: Tendera para la tienda de Zarkam.
********************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;
    
create()
{
    ::create();
    SetStandard("Nentab","orco",10,GENERO_FEMENINO);
    SetName("Nentab");
    SetShort("Nentab, la tendera");
    SetLong("Nentab es una orca corpulenta de carácter abierto y extrovertido. Suele pasarse "
        "el día bromeando con los clientes que acuden a su tienda. Viste con ropas de colores "
        "brillantes y luce varios pendientes en forma de aro en cada oreja.\n");
    AddId(({"nentab","Nentab","tendera","orca"}));
    Set(P_CANT_LURE,1);
}
