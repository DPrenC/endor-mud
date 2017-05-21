/*=============================================================*
 |            << TIINKDHIL>>            |
 *=============================================================*
 |               Creacion.............. 16-05-99               |
 |               Ultima Modificacion... 16-05-99               |
 |                                                             |
 *=============================================================*/

#include <wizlevels.h>
#include <spellmonster.h>
#include <combat.h>

inherit "/obj/monster/spellundead";

#define ART(x)   (x->QueryGenderEndString())
int drenar();

create() {
  ::create();
 AddSpell("mordisco fatal",
  ([
    S_FUN:SF(drenar),
    S_SP:20,
    S_CHANCE:5,
    S_VICTIMS:1,
  ]));
}

drenar(mapping sp, object *vic) {
  object *en,enemigo;
  int i;

  if (!sizeof(en=QueryEnemies()||({}))) return 0;
  if (!(enemigo=en[random(sizeof(en))]) || !present(enemigo,environment())) return 0;

  tell_room(environment(),capitalize(QueryName())+" clava sus colmillos "+
	"el cuello de "+enemigo->QueryName()+".\n",({enemigo}));
  tell_object(enemigo,capitalize(QueryName())+" se abalanza sobre ti "+
	"y clava sus colmillos en tu cuello, directamente a la yugular. "+
	"Notas como empiezas a debilitarte.\n");

  enemigo->Defend(5+random(10),DT_POISON,DEFEND_F_NOMSG);
  vic=({enemigo});
  return sp;
}

