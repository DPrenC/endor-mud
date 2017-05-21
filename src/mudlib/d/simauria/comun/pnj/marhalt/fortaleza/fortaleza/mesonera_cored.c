/****************************************************************************
Fichero: mesonera_cored.c
Autor: Buh
Fecha: 29/05/2007
Descripci�n: La mesonera del mes�n de la banda de Cored.
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
    SetLong("Esta mesonera debe cocinar muy bien, pues ciertamente se le nota que est�"
        " gorda.\n Con los pelos rizados y casta�os, junto con la cara regordeta, su "
        "imagen es toda una estampa. Debe ser la mujer de alg�n miembro de la banda.\n");
    AddId(({"mesonera", "humana", "gorda", "mujer"}));
    SetWeight(90000);
    Set(P_CANT_LURE,1);
    SetSmell("Podr�a oler mejor.\n");
}
