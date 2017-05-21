/*
DESCRIPCION  : una vulgar maza de madera
FICHERO      : maza_madera.c
BASADO       : maza_madera.c de Goldhai
MODIFICACION : 06-03-00 [Angor@Simauria] Creacion
*/

#include <combat.h>
#include <properties.h>
#include <materials.h>
#include "path.h"

inherit WEAPON;
//inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_MAZA,2,P_SIZE_LARGE,M_MADERA);
 SetWeight(3000);
 SetShort("una maza de madera");
 SetIds(({"maza","maza de madera"}));
 SetValue(2500);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Una tosca maza de madera. Hay armas mejores, pero en manos expertas puede\n\
bastante peligrosa.\n");
}

