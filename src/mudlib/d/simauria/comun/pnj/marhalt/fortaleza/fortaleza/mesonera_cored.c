/****************************************************************************
Fichero: mesonera_cored.c
Autor: Buh
Fecha: 29/05/2007
Descripción: La mesonera del mesón de la banda de Cored.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("la mesonera", "humano", ([GC_NINGUNO:15]), GENDER_FEMALE);
    SetShort("la mesonera");
    SetLong("Esta mesonera debe cocinar muy bien, pues ciertamente se le nota que está"
        " gorda.\n Con los pelos rizados y castaños, junto con la cara regordeta, su "
        "imagen es toda una estampa. Debe ser la mujer de algún miembro de la banda.\n");
    AddId(({"mesonera", "humana", "gorda", "mujer"}));
    SetWeight(90000);
    Set(P_CANT_LURE,1);
    SetSmell("Podría oler mejor.\n");
}
