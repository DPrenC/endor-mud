/***************************************************************************************
 ARCHIVO:	rama.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Rama del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create () {
 ::create();

 SetShort("una rama caída");
 SetLong("Una rama caída del bosque Cylin, con varios nudos y sin ninguna hoja.\n");
 AddSubDetail(({"nudo","nudos"}),W("La rama tiene unos cuantos nudos de viejos brotes "
 	"ya desaparecidos.\n"));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(2000);
 SetValue(0);
 SetWC(4);
 SetNumberHands(2);
 SetWeaponType(WT_VARA);
 SetIds(({"rama","rama caída"}));
 SetMaterial(M_MADERA);
}
