/*
DESCRIPCION : tendero
FICHERO     : tend1.c
MODIFICACION: 16-7-00 [Maler] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <money.h>
#include <combat.h>
#include <properties.h>
#include <rooms.h>

inherit NPC;
create() {
  ::create();
SetName("romalef");
AddAdjective("viejo");
SetIds(({"tendero","romalef","tendero romalef"}));
SetNoGet(1);
SetShort("Romalef");
SetLong(W("Es Romalef, el tendero, es un humano ya anciano. Te preguntas cual "
 "puede ser la función de una persona de esta edad dentro de la banda.\n"));
SetRace("humano");
SetWeight(100000);
SetLevel(15);
SetStr(15);
SetDex(15);
SetAggressive(0); //0 no, 1 si.
SetGender(1);// 1 masculino, 2 femenino
SetAlign(0);
SetMaxHP(80);
SetHP(80);
}
