/**************************************************************************
fichero: casco_guerrero.c
Autor: kastwey
Creación: 21/07/2005
Descripción: El casco de los guerreros del centro de entrenamiento
**************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;

public void create()
{
    ::create();
    SetStandard(AT_CASCO,3,P_SIZE_NORMAL,M_ACERO);
    SetShort("un casco de acero");
    SetLong(W("Es el casco que utilizan los guerreros del ejército de "
              "Kha-annu. Está forjado en acero y sobre la visera puedes ver "
              "grabada la cabeza de un león. Parece muy resistente.\n"));
    AddSubDetail(({"cabeza","cabeza de leon","cabeza del leon","cabeza de un "
                 "león","cabeza de un leon","leon","león"}),W("Sobre la "
                   "visera del casco puedes ver grabada la cabeza de un "
                   "león.\n"));
}
