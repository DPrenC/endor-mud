/*
DESCRIPCION  : aranya para la mina de novatos
FICHERO      : /d/limbo/comun/pnj/aranya.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
               11-10-99 [Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
  ::create();
  SetStandard("una ara�a grande","aranya",([ GC_TORPE: 2]),GENDER_FEMALE);
  SetShort("una ara�a grande");
  SetLong(
  "Es una ara�a peluda de color negro con estrias marron en el abdomen. Sus\n"
  "m�ltiples ojos son de un color rojo brillante.\n");
  SetIds(({"aranya","bicho","ara�a"}));
  SetAds(({"una","asquerosa","gran"}));
  SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
  SetStr(QueryStr()-1);
  SetDex(QueryDex()+1);
  SetInt(1);
  SetHands( ({ ({"mordisco",TD_PENETRACION,3}) }) );
  SetNoGet(0);
  SetWeight(500);

  SetDesmembrableEn(({CABEZA,PATA_PEQUENYA,PATA_PEQUENYA,PATA_PEQUENYA,PATA_PEQUENYA,
  PATA_PEQUENYA,PATA_PEQUENYA,PATA_PEQUENYA,PATA_PEQUENYA,}));
}
