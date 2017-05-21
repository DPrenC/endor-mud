/****************************************************************************
Fichero: uniforme_soldados.c
Autor: Kastwey
Creación: 26/08/2005
Descripción: Uniforme para los soldados de Annufam
****************************************************************************/

#include "./path.h"
#include <materials.h>
#include <properties.h>
#include <combat.h>


inherit ARMOUR;

public void create()
{
    ::create();
    SetStandard(AT_TABARDO, 7, P_SIZE_NORMAL, M_TELA);
    SetShort("un uniforme");
    SetLong(W("Es el uniforme de los soldados de menor rango del ejército "
              "enano de Kha-annu. Se trata de una túnica verde y marrón sin "
              "ningún distintivo excepto una cabeza de león bordada en el "
              "pecho.\n"));
    AddId(({"uniforme","uniforme de tela"}));

}
