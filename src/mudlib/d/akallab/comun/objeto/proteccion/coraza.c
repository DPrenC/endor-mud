/*
DESCRIPCION  : coraza ligera de acero
FICHERO      : coraza.c
MODIFICACION : 02-03-98 [Angor@Simauria] Creacion.
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_CORAZA,6,P_SIZE_MEDIUM,M_ACERO);
  SetIds(({"coraza","coraza de acero"}));
  SetShort("una coraza ligera de acero");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una coraza ligera de acero que cubre el pecho por completo y sujetada con unas\n\
tiras de cuero por la espalda.\n");
}


