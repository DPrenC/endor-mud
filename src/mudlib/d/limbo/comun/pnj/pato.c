/*
DESCRIPCION  : pato para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/pato.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit NPC;

create() {
  ::create();
  SetStandard("un pato","pato",([ GC_TORPE: 2]),GENDER_MALE);
  SetShort("un peque�o pato");
  SetLong("Es un peque�o pato de plumaje marr�n y cabeza blanca.\n");
  SetIds(({"pato","pajaro","p�jaro","ave"}));
  SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
  SetInt(1);
  SetHands(({ ({"picotazo",TD_PENETRACION,5}) }));
  SetNoGet(0);
  SetWeight(1000);
}

