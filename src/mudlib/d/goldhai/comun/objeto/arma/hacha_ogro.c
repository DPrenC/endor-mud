/****************************************************************************
Fichero: hacha_ogro.c
Autor: Ratwor
Fecha: 06/04/2008
Descripción: el hacha del ogro de Shafil
****************************************************************************/

#include <combat.h>
#include <properties.h>
#include "./path.h"

inherit WEAPON;

create()
{
    if (!clonep(TO)) return;
    ::create();
    SetStandard(WT_HACHA,13,P_SIZE_LARGE,M_HIERRO);
    SetWeight(15000);
    SetShort("una pesada hacha");
    AddId(({"hacha","pesada hacha", "hacha pesada"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(2);
    SetLong("Es una pesada hacha a dos manos dotada de una enorme hoja mellada "
                "de oscuro hierro toscamente forjado.\n  Al igual que la temible  "
                "hoja, el mango presenta toda clase de arañazos y marcas producto "
                "de antiguos combates.\n El hecho de que el filo se encuentre   "
                "burdamente afilado y lleno de muescas se ve compensado por el gran "
                "peso del arma que solo en las manos de una criatura con una  fuerza "
                "tremenda podría causar grandes destrozos.\n");
}
