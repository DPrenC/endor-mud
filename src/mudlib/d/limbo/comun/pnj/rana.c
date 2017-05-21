/*
DESCRIPCION  : rana para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/rana.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
               23-03-99 [Angor@Simauria] Quitado un ataque
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
 ::create();
 SetStandard("una rana","rana",([ GC_TORPE: 1]),GENDER_FEMALE);
 SetShort("una rana");
 SetLong(
 "Es una rana corriente de color verde-grisaceo. Debe vivir en alguna charca de\n"
 "los alrededores.\n");
 AddAdjective("corriente");
 SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
 SetInt(1);
 SetHands(({({"mordisco",TD_PENETRACION,1})}));
 SetWeight(500);
 SetGoChance(30);
 SetNoGet("La rana da un salto y se aleja de ti.\n");
 InitChats(3,({"La rana dice: ¡Croaakkk!\n",
                "La rana da un salto.\n",
                "La rana croa con fuerza: ¡¡Croaakk, crooakkk!\n",
                "La rana atrapa una mosca con su larga y pegajosa lengua.\n"}));
}
