/***************************************************************************************
 ARCHIVO:	daga.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	Una daga
 		Habilidad de lucha con daga parcialmente adaptada del archivo de Nyh?
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
  SetStandard(WT_CUCHILLO,3,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"daga","daga curva"}));
  SetShort("una daga curva");
  SetLong(W("Es una daga curva de acero perfectamente forjada y con un "
  	"escudo de Seri-Solderteg en la empuñadura. Es la daga oficial "
  	"de los discípulos.\n"));
  AddSubDetail(({"empuñadura","empunyadura"}),"Es una bonita empuñadura de marfil.\n");
  AddSubDetail(({"escudo"}),W("Es el escudo de Seri-Solderteg, señal de que esta "
  	"daga pertenece a un discípulo.\n"));
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
