/*
DESCRIPCION   : Coraza de hierro pequeña
FICHERO       : coraza_hierro_p.c
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
  SetStandard(AT_CORAZA,9,P_SIZE_SMALL,M_HIERRO);
  SetValue(QueryValue()*4); // Cuadruplico Valor

  SetIds(({"coraza","coraza de hierro"}));
  SetShort("una coraza de hierro");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una coraza toda hecha de hierro y que debe pesar una barbaridad.\n");
}
