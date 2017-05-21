/**************************************************************************
fichero: casco_guerrero.c
Autor: kastwey
Creaci�n: 21/07/2005
Descripci�n: El casco de los guerreros del centro de entrenamiento
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
    SetLong(W("Es el casco que utilizan los guerreros del ej�rcito de "
              "Kha-annu. Est� forjado en acero y sobre la visera puedes ver "
              "grabada la cabeza de un le�n. Parece muy resistente.\n"));
    AddSubDetail(({"cabeza","cabeza de leon","cabeza del leon","cabeza de un "
                 "le�n","cabeza de un leon","leon","le�n"}),W("Sobre la "
                   "visera del casco puedes ver grabada la cabeza de un "
                   "le�n.\n"));
}
