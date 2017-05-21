/****************************************************************************
Fichero: sandalias_soldados.c
Autor: Kastwey
Creación: 26/08/2005
Descripción: Unas sandalias para los soldados del centro de entrenamiento
****************************************************************************/

#include "./path.h"
#include <materials.h>
#include <properties.h>
#include <combat.h>
inherit ARMOUR;


public void create()
{
    ::create();
    SetStandard(AT_BOTAS,3,P_SIZE_NORMAL,M_CUERO);
    SetShort("unas sandalias de cuero");
    SetLong(W("Son unas simples sandalias de cuero.\n"));
    AddId(({"sandalias","sandalias de cuero"}));
    Set(P_NUMBER,NUMBER_PLURAL);

}
