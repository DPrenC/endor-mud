/*
DESCRIPCION  : oveja para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/oveja.c
MODIFICACION :

08-08-98 [Angor@Simauria] Creacion
23-03-99 [Angor@Simauria] La oveja era dificil de matar. Rebajada de nivel.
10-04-00 [nemesis@simauria] La oveja seguía siendo chunga de matar... asi que la
                            repaso...  No comprendo por qué tiene AC y 45 puntos
                            de vida! Y tampoco por que ataca con los dientes...
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit NPC;

create() {
    ::create();
    SetStandard("una oveja","oveja",([ GC_TORPE: 3]),GENDER_FEMALE);
    SetShort("una oveja");
    SetLong(
    "Es una simple oveja. Sus grandes ojos tristones te miran asomándose entre\n"
    "gruesos mechones de lana.\n");
    SetSize(P_SIZE_MEDIUM);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
    SetInt(1);
    SetHands(({({"mordisco",TD_PENETRACION,3})}));
    InitChats(20,({"La oveja bala: ¡Baaah!\n",
                   "La oveja te mira y bala: ¡Baaaaaah!\n",
                   "La oveja mordisquea indiferente un poco de hierba.\n"}));
    SetGoChance(20);
}
