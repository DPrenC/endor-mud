/**
 * SIMAURIA '/std/npc.c'
 */


#include <config.h>
#include <properties.h>
#include <colours.h>
#include <wizlevels.h>
#include <combat.h>
#include <classes.h>
#include <living.h>
#include <skills.h>
#include <gremios.h>
#include <actions.h>
#include <stats.h>

//------------------------------------------------------------------------------

/* Comandos heredados */
inherit "/std/base";

inherit "/std/room/items"; // Para poder darle objetos con AddItem

inherit "/std/living/description";
inherit "/std/living/equipment";
inherit "/std/living/perception";
inherit "/std/living/heart";
inherit "/std/living/attributes";
inherit "/std/living/restrictions";
inherit "/std/living/combat";
inherit "/std/living/groups";
inherit "/std/living/commands";
inherit "/std/living/skills";
inherit "/std/living/stats";
inherit "/std/living/body";
inherit "/std/living/cmds";
inherit "/std/living/putget";
inherit "/std/living/view";

inherit "/std/npc/moving";
inherit "/std/npc/chat";

//-----------------------------------------------------------------------------

#define MAX_LEVEL_OVERFLOW 1000

/* Nota importante:
//Para que esto rule mas o menos bien, debido a que es todo una gran chapuza
//debe usarse el setstandard... si no hay que llamar a las funciones en el
//siguiente orden: SetLevel, SetGuild e InitRace, de hacerse en otro orden
//puede quedar la cosa muy malita...
*/

//sobrecargo maxHP y maxSP, los pnj tienen mas por la cara
public int QueryMaxHP()	{ return NPC_POINTS(::QueryMaxHP());}
public int QueryMaxSP() { return NPC_POINTS(::QueryMaxSP());}

//sobrecargo el guild level...
public varargs int QueryGuildLevel(string g) { return QueryTotalLevel(); }

#define NIV_AL_MAXIMO	5 //cuantos niv tarda en tener algo en perfecto
//nota: si no se le da un gremio RESETEA las habilidades...
public varargs int GiveSkills(string g, int l) {
  mapping habmap;
  string *ind;

  if (!l) l=QueryLevel()||1;
  if (!g) {
    g=QueryGuild()||GC_NINGUNO;
    SetSkills(([]));
  }
  if (!(habmap=HAB_MAP[g])) return 0;
  if (!mappingp(habmap) || !sizeof(ind=m_indices(habmap))) return 0;
  foreach (string hab:ind)
    if (l>=habmap[hab,HAB_MAP_NIV])
      AddSkill( hab,
        ((l-habmap[hab,HAB_MAP_NIV])>=NIV_AL_MAXIMO) ?
          habmap[hab,HAB_MAP_MAX] :
          habmap[hab,HAB_MAP_MAX]*(l-habmap[hab,HAB_MAP_NIV])/NIV_AL_MAXIMO, P_DEX);
  AddSkill(HAB_NATURAL, l>10?100:(l*10) );
  return 1;
}

//sobrecargo el setguild
public string SetGuild(string g) {
  string old;
  mapping map;
  int i;

  //se quitan los modificadores antiguos
  if ( (old=QueryGuild())
    && (old!=GC_NINGUNO)
    && (map = STATS_MAP[old])
    && (map = map[STAT_MAX]) ) {
    for (i=sizeof(STATS);i--;) {
      Set(STATS[i],Query(STATS[i])-map[STATS[i]]);
    }
  }
  //se ponen los modificadores nuevos
  if (g && (g!=GC_NINGUNO) && (map = STATS_MAP[g]) && (map = map[STAT_MAX])) {
    for (i=sizeof(STATS);i--;) {
      Set(STATS[i],Query(STATS[i])+map[STATS[i]]);
      if (Query(STATS[i])<1) Set(STATS[i],1);
    }
  }
  GiveSkills(g, QueryGuildLevel());
  return ::SetGuild(g);
}

#define NIV_STAT_MAX_HLP	50 //entre MAX_STAT y este se sube mas lento
//sobrecargo el setlevel
public int SetLevel(int l) {
  int i;
  if (l > MAX_LEVEL_OVERFLOW) {
    log_file("LEVEL_OVERFLOW", sprintf("%s: %O (%d)\n", ctime(), TO, l));
    l = MAX_LEVEL_OVERFLOW;
  }
  SetXP(level2xp(l) + random(level2xp(l+1)-level2xp(l)));

  if (l < MAX_STAT) i=l;
  else if (l < NIV_STAT_MAX_HLP) {
    i = MAX_STAT + (l - MAX_STAT) / (NIV_STAT_MAX_HLP - MAX_STAT);
  }
  else { //l es mayor que 50, stats maximos
    i = HLP_STAT;
  }

  SetStr(i);
  SetDex(i);
  SetInt(i); //dan sp
  SetCon(i); //dan hp
  SetHP(QueryMaxHP());
  SetSP(QueryMaxSP());
  GiveSkills(QueryGuild()||GC_NINGUNO, l);
  SetResistance(TM_INTR,l>100?100:l); //si, macho, un tio de nivel 100 es inmune
  SetAC(l/4);
  return ::SetLevel(l);
}

//si nivel es int: nivel de gremio ninguno
// y si no es maping de la forma ([ GC_XXX: nivel, ...])
public varargs int SetStandard(string nombre, string raza, mixed nivel, int genero) {
  int i;
  mixed *manos;

//if (find_object("nyh")) dtell("nyh",sprintf("%O->SetStandard(%s,%s,%O,%i)\n",TO,nombre,raza,nivel,genero));

  SetName(nombre||QueryName()||"nadie");
  SetGender(genero||GENERO_MASCULINO);
  SetRace(raza||QueryRace()||"humano");

  if (intp(nivel)) nivel = ([ GC_NINGUNO: nivel ]);
  if (mappingp(nivel)) {
    string *gremios;
    gremios=m_indices(nivel);
    if (i=sizeof(gremios)) { //tengo que elegir 1
      string gremio=GC_NINGUNO;
      int max = 0;
      for (;i--;) if (nivel[gremios[i]]>max) {max=nivel[gremios[i]]; gremio=gremios[i];}
      if (max > MAX_LEVEL_OVERFLOW) max = MAX_LEVEL_OVERFLOW;
      SetLevel(max||1);
//atencion, es muy importante q el initrace este despues del setlevel y antes del hands y del SetGuild
      RACEMASTER->InitRace(TO,QueryRace()/*raza||QueryRace()||"humano"*/);
      SetGuild(VALIDA_GREMIO(gremio)||GC_NINGUNO);
    }
    else {
      SetLevel(1);
//atencion, es muy importante q el initrace este despues del setlevel y antes del hands y del SetGuild
      RACEMASTER->InitRace(TO,QueryRace()/*raza||QueryRace()||"humano"*/);
      SetGuild(GC_NINGUNO);
    }
  }
  else {
    SetLevel(1);
    SetGuild(GC_NINGUNO);
  }
  // GiveSkills(); // comentado porque ya se dan en el setlevel
/* [Nyh] atencion, lo sigueinte sobra siempre y cuando el initrace venga despues del setlevel
pues lo que se hace aqui ya se hace a traves del AddHand cuando es llamado desde el initrace
//atencion, es muy importante q el initrace este despues del setlevel y antes del hands y del SetGuild
  manos = QueryHands();
  SetHands(({ }));
//  if (find_object("nyh")) dtell("nyh",sprintf("--------------------EL DEL SETSTANDARD:%O\n",QueryLevel()*2/5));
  for (i=sizeof(manos)+1;--i;) AddHand(manos[<i][HAND_SHORT],manos[<i][HAND_WEAPON],QueryLevel()*2/5);
*/
  SetHP(QueryMaxHP());
  SetSP(QueryMaxSP());

  if (QueryIVision()==QueryUVision()) { SetIVision(0); SetUVision(200); }
  return QueryLevel();
}

//SetHands(h) { return hands = h; }
/* [Nyh]
El wc minimo que puede tener una mano es la mitad del nivel, si es inferior
le pongo el estandar que es 2/3 del nivel
*/
public void AddHand(string short, mixed type, int wc) {
//  if (find_object("nyh")) dtell("nyh",sprintf("AddHand(short=%O, type=%O, wc=%O)\n",short,type,wc));
  if (wc=0 || wc>(QueryLevel()/4)) return ::AddHand(short, type, wc);
  else return ::AddHand(short, type, (QueryLevel()*2/5)||1);
}

SetHands(h) {
  int i;
  ::SetHands(({ }));
  if (i=sizeof(h)) for (i; i--; ) AddHand(h[i][0],h[i][1],h[i][2]);
}

create() {
//    dtell("nyh",sprintf("------------------------------------------\n"));
//    dtell("nyh",sprintf("ob = %O\ngetuid() = %O\ngeteuid() = %O\n",TO, getuid(), geteuid()));
  seteuid(getuid());
//    dtell("nyh",sprintf("seteuid(%O)= %O\n", getuid(), geteuid()));
//    dtell("nyh",sprintf("------------------------------------------\n"));

  base::create();

  SetIds(({}));

    /* No hacer cosas con el blueprint */
  if (!clonep()) return;

  "*"::create();

  AddClassId(C_LIVING);

  SetName("Nadie");
  SetRace("humano");
  SetLong(0);
  SetGender(0);
  SetWeight(75000);
  SetMaxWeight(50000);
  SetMaxFood(100);
  SetMaxDrink(100);
  SetMaxAlcohol(100);
  SetDrink(QueryMaxDrink());
  SetFood(QueryMaxFood());
  SetAlcohol(0);
  Set(P_NOGET, 1);
  ::SetHands(({
    ({"mano derecha",0,WEAPON_CLASS_OF_HANDS}),
    ({"mano izquierda",0,WEAPON_CLASS_OF_HANDS}) }) );
  SetAC(1);
  enable_commands();
  add_putget_cmds();
  add_view_cmds();
  add_living_cmds();
  add_groups_cmds();

  CheckHBfun("/std/npc");

  /* Para estadisticas */
  catch("/obj/npcstat"->Add(TO));
}

reset() {
  "*"::reset();
}

heart_beat() {
  ResetCmdDataStack(); // clean up stack
  "*"::heart_beat();
}

init() {
  "*"::init();
}
