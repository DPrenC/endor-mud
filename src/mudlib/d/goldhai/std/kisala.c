/*=============================================================*
 |            << GOLDHAI.Gremio [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 16-05-99               |
 |               Ultima Modificacion... 16-05-99               |
 |                                                             |
 *=============================================================*/

#include "../path.h"
#include <wizlevels.h>
#include <spellmonster.h>
#include <properties.h>

inherit SPELLMONSTER;

#define ART(x)   (x->QueryGender()==GENDER_FEMALE?"a":"o")
int cegar();

create()
{
  ::create();
AddSpell("luz cegadora",
  ([
    S_FUN:SF(cegar),
    S_SP:20,
    S_CHANCE:40,
    S_VICTIMS:1,
  ]));
}

int cegar()
{
 object *en,enemigo, bola;
 int i;

 en = QueryEnemies()||({});
 if (!sizeof(en)) return 0;
 enemigo = en[random(sizeof(en))];

 if (!enemigo || !present(enemigo,environment())) return 0;

 if (!enemigo->QueryIsNPC() && !enemigo->QueryIsPet())
 {
  if (bola=present("lightball",enemigo))
   return 0;
  else {
   seteuid(getuid(TO));
   bola=clone_object("/guilds/kisalas/obj/bola_luz");
   bola->Deslumbrar(enemigo->QueryUVision(),enemigo,10+random(10));
  }
 }

 enemigo->SetCombatDelay(10,"Estás deslumbrad"+ART(enemigo)+".\n");

 tell_room(environment(),capitalize(QueryName())+" se concentra y de sus "
 "ojos emana una intensa luz que deslumbra a "+
 enemigo->QueryName()+".\n",({enemigo}));
 tell_object(enemigo,capitalize(QueryName())+" se concentra "
 "y fija su mirada en tus ojos. Una intensa luz aparece de la nada y "
 "consigue deslumbrarte.\n");

 return 0;
}
