/*
DESCRIPCION  : zorro para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/zorro.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
  ::create();

  SetStandard("un zorro","zorro",([ GC_TORPE: 3]),GENDER_MALE);
  SetShort("un zorro");
  SetLong(
  "Es un pequeño zorro de pelaje rojizo y cola blanca. Sus dientes son muy\n"
  "afilados y sus ojos brillan con un gesto poco amistoso.\n");
  SetIds(({"zorro","bicho"}));
  SetAds(({"pequeño","un","pequenyo"}));
  SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
  SetInt(1);
  SetHands( ({ ({"mordisco",TD_PENETRACION,3}) }) );
  InitChats(8,({
   "El zorro da vueltas a tu alrededor.\n",
   "El zorro intenta pegarte una dentellada en los tobillos.\n",
   "El zorro te mira con gesto poco amistoso.\n",
   "El zorro husmea el aire en busca del olor de alguna posible presa.\n",
   "El zorro te enseña sus dientes amarillos.\n",
  }));
}
