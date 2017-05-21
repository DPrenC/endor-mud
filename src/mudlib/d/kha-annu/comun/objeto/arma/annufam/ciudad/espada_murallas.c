/**************************************************************************
fichero: espada_murallas.c
Autor: Riberales
Creación: 9/10/2005
Descripción: Una espada para los enanos de la muralla y los del centro
**************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>


inherit WEAPON;

public void create()
{
    ::create();
    SetStandard(WT_ESPADA,9,P_SIZE_NORMAL,M_HIERRO);
    SetShort("una espada");
    SetLong(W("Es una espada de hoja larga y muy afilada. La empuñadura está "
              "forjada delicadamente y aparenta la cabeza de un león. Parece "
              "ligera, pero seguro que no deja de ser peligrosa.\n"));

}
