/***************************************************************************************
 ARCHIVO:	espada.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Espada de la Guardia de Koek
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_ESPADA,6,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"espada","espada larga"}));
  SetShort("una espada larga");
  SetLong(W("Es una preciosa espada larga con grabados por todo el filo. Tiene una "
  	"empuñadura de oro muy bien forjada con el escudo de Koek grabado en ella.\n"));
  AddSubDetail(({"grabado","grabados","filo"}),W("El filo de la espada está lleno de "
  	"grabados decorativos que hacen inconfundible esta espada.\n"));
  AddSubDetail(({"empuñadura","empunyadura","escudo"}),W("En la empuñadura de oro "
  	"hay grabado un escudo, parece el de Koek. Debe ser la espada de algún miembro "
  	"de seguridad de allí.\n"));
}