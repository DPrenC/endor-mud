/**************************************************************************
fichero: hacha_guerreros.c
Autor: kastwey
Creaci�n: 21/07/2005
Descripci�n: Un hacha para los guerreros del centro de entrenamiento de Annufam
**************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>


inherit WEAPON;

public void create()
{
    ::create();
    SetStandard(WT_HACHA,11,P_SIZE_NORMAL,M_HIERRO);
    SetShort("un hacha");
    SetLong(W("Se trata de la t�pica hacha enana: ligera, muy afilada "
              "y extremadamente peligrosa en unas manos expertas. En la "
              "empu�adura puedes ver grabada la cabeza de un le�n.\n"));
    AddId("hacha_soldados_annufam");
}

