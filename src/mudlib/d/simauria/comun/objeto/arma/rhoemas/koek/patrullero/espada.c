/***************************************************************************************
 ARCHIVO:	espada.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Espada de los patrulleros de Koek
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_ESPADA,5,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"espada","espada corta"}));
  SetShort("una espada corta");
  SetLong(W("Es una preciosa espada corta con grabados por todo el filo. Tiene una "
  	"empu�adura de plata muy bien forjada con el escudo de Koek grabado en ella.\n"));
  AddSubDetail(({"grabado","grabados","filo"}),W("El filo de la espada est� lleno de "
  	"grabados decorativos que hacen inconfundible esta espada.\n"));
  AddSubDetail(({"empu�adura","empunyadura","escudo"}),W("En la empu�adura de plata "
  	"hay grabado un escudo, parece el de Koek. Debe ser la espada de alg�n miembro "
  	"de seguridad de all�.\n"));
}