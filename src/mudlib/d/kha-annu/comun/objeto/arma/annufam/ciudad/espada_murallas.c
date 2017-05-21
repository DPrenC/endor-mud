/**************************************************************************
fichero: espada_murallas.c
Autor: Riberales
Creaci�n: 9/10/2005
Descripci�n: Una espada para los enanos de la muralla y los del centro
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
    SetLong(W("Es una espada de hoja larga y muy afilada. La empu�adura est� "
              "forjada delicadamente y aparenta la cabeza de un le�n. Parece "
              "ligera, pero seguro que no deja de ser peligrosa.\n"));

}
