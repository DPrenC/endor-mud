/**************************************************************************
fichero: hacha_guerreros.c
Autor: kastwey
Creación: 21/07/2005
Descripción: Un hacha para los guerreros del centro de entrenamiento de Annufam
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
    SetLong(W("Se trata de la típica hacha enana: ligera, muy afilada "
              "y extremadamente peligrosa en unas manos expertas. En la "
              "empuñadura puedes ver grabada la cabeza de un león.\n"));
    AddId("hacha_soldados_annufam");
}

