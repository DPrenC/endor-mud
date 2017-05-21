/***************************************************************************************
 ARCHIVO:	roca.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Una roca afilada del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create () {
 ::create();
 SetShort("una roca muy afilada");
 SetLong("Es una fría roca gris del tamaño de un puño con los bordes muy afilados...\n");
 AddSubDetail(({"borde","bordes"}),"Tiene los bordes muy afilados.\n");
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(5000);
 SetValue(0);
 SetWC(2);
 SetNumberHands(1);
 SetWeaponType(WT_CUCHILLO);
 SetIds(({"roca"}));
 SetMaterial(M_PIEDRA);
}
