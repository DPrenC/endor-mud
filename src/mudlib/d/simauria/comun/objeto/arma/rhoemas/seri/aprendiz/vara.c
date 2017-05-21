/***************************************************************************************
 ARCHIVO:	vara.c
 AUTOR:		[z] Zomax
 FECHA:		29-12-2001
 COMENTARIOS:	Una vara de madera
 		Habilidad de lucha con varas parcialmente adaptada del archivo de Nyh?
 		/d/lad-laurelin/std/usahab.c y de la capa de los conjuradores, Woo?
 ***************************************************************************************/

#include <skills.h>
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_VARA,5,P_SIZE_MEDIUM,M_MADERA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"vara","vara de madera"}));
  SetShort("una vara de madera");
  SetLong(W("Es una vara de madera absolutamente recta que todos los aprendices "
  	"llevan para entrenar y defenderse.\n"));
}

private object Owner()
{
	object pnj;
	pnj = environment(TO);
	if (!pnj) return 0;
	if (pnj->IsPlayer()) return 0;
	return pnj;
}

public varargs int UseSkill(string name, int chance, int percentage)
{
	if (!name) return 0;
 	percentage=Owner()->UseSkill(name,chance);
 	if (percentage>0) return 1;
 	else return 0;
 	return 0;
}
