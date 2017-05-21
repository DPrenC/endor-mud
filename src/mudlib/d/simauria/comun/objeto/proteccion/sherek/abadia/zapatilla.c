/****************************************************************************
Fichero: /d/simauria/comun/objeto/proteccion/sherek/abadia/zapatilla.c
Autor: Lug y Yalin
Fecha: 18/09/2006
Descripción: Zapatillas para los monjes
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <materials.h>
#include <combat.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_BOTAS, 2,P_SIZE_MEDIUM,M_TELA);
    SetShort("unas zapatillas de piel");
    SetLong("Son unas zapatillas de piel de conejo, sobriamente curtidas, "
        "sin suela y cosidas con el pelo hacia dentro, lo que las hace "
        "silenciosas y calientes, por lo que son el calzado habitual de los "
        "monjes de la abadía.\nLlevan el emblema de Sherek bordado en plata "
        "sobre el empeine.\n");
    AddSubDetail(({"emblema"}),"Es la imagen de la diosa Sherek, una mujer "
        "con una serpiente enroscada en su brazo derecho, a la que decapita "
        "con una daga que sostiene en su mano izquierda.\n");
    SetIds(({"zapatillas","zapatillas de piel","zapatillas de conejo"}));
    Set(P_NUMBER,NUMERO_PLURAL);
        SetResetQuality(100);
}
