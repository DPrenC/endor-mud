/*
DESCRIPCION   : Coraza de acero grande
FICHERO       : coraza_acero_g.c
CREACION      : 10-11-01 [Bomber]
MODIFICACION  :
*/


#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>


inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_CORAZA,12,P_SIZE_LARGE,M_ACERO);
  SetIds(({"coraza","coraza de acero"}));
  SetShort("una coraza de acero");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una coraza de acero que cubre el pecho por completo y sujetada con unas\n\
tiras de cuero por la espalda.\n");
  SetWeight(QueryWeight()*2); // Doblo peso
  SetValue(QueryValue()*4); // Cuadruplico Valor

}
