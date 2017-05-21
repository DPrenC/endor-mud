/****************************************************************************
Fichero: uniforme_soldados.c
Autor: Kastwey
Creaci�n: 26/08/2005
Descripci�n: Uniforme para los soldados de Annufam
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
    SetLong(W("Es el uniforme de los soldados de menor rango del ej�rcito "
              "enano de Kha-annu. Se trata de una t�nica verde y marr�n sin "
              "ning�n distintivo excepto una cabeza de le�n bordada en el "
              "pecho.\n"));
    AddId(({"uniforme","uniforme de tela"}));

}
