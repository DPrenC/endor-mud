/*
DESCRIPCION   : grebas de acero peque�os
FICHERO       : grebas_acero_p.c
CREACION      : 10-11-01 [Bomber]
MODIFICACION  :
*/

inherit ARMOUR;

#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(AT_GREBAS, 2, P_SIZE_SMALL, M_ACERO);
  SetAds(({"unas", "brillantes"}));
  AddId(({"armadura","grebas"}));
  SetShort("unas grebas");
  SetLong("Son unas grebas de acero dise�adas para proteger las piernas.\n");
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER, NUMBER_PLURAL);
  SetValue(QueryValue()*4); // Cuadruplico Valor

  }