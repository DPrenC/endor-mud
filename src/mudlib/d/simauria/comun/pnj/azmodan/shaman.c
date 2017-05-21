/*********************************************************/
//		"shaman"
//	Shamanes menores que invocan esp�ritus
//		11-12-01: Kodex-> creaci�n
//		11-12-01: Kodex-> �ltima modificaci�n
/*********************************************************/

#include <nightday.h>
#include <spellmonster.h>
#include <properties.h>
#include "./path.h"
#include <rooms.h>
#include <moving.h>
#include <colours.h>
#include <wizlevels.h>
#include <gremios.h>

inherit SPELLMONSTER;


public status check_sp();
public int magia();


create()
{
::create();
SetStandard("un cham�n","orco-comun",([GC_CLERIGO: d4()+24]),GENERO_MASCULINO);
SetShort("un cham�n menor");
SetLong(W("Ves un orco envuelto en unos harapos rasgados, "
"tiene se�ales ensangrentadas y cicatrices que seguramente son fruto "
"de rituales de magia negra, est� encolerizado y sus ojos chispean.\n"));
SetIds(({"orco","cham�n","chaman","chaman menor","cham�n menor"}));
SetAggressive(1);
SetFriendFunction((:($1->QueryRace() == "orco"):));
SetAlign(-400);
SetSpellChance(80);
AddItem(ARMA_AZMODAN("necrofirix"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA_AZMODAN("daga"),REFRESH_REMOVE,SF(wieldme));
InitChats(7,({"El cham�n agita su necrof�rix.\n"}));
AddSpell("conjuros",
  ([
  S_CHECKFUN:SF(check_sp),
  S_FUN:SF(magia), S_SP:2,
  S_CHANCE:25,
  S_VICTIMS:1,
  ]));


}

public status check_sp()
{
return QuerySP()>=60;
}

public int magia()
{
 object *en,ene,bicho;
 int i;
 bicho=TO;
 en=QueryEnemies()||({});
 if(!sizeof(en)) return 0;
 ene=en[random(sizeof(en))];

bicho->AddSP(-60);
bicho = clone_object(NPC_AZMODAN("spirit"));
bicho-> move(environment(TO));
tell_room(environment(),W(TC_YELLOW+"El cham�n levanta las garras y lanza unos agudos gritos invocando el esp�ritu de alg�n "+TC_RED+"combatiente orco"+TC_YELLOW+" ca�do.\n"+TC_NORMAL));
 for(i=0;i<sizeof(en);i++)
 {
   en[i]->Kill(bicho);
 }
return 0;
}
/*
int Noche()
{
	mixed nd;
	nd = (mixed *)NIGHTDAY->QueryState();
        if (nd == ND_NIGHT || nd == ND_PREDAWN || nd == ND_FALL || nd == ND_PRENIGHT)
        	return 1;
        return 0;
}

int EsWiz(object user)
{

	if (IS_LEARNER(user)) return 1;
	return 0;
}

init()
{
 mixed nd;
  ::init();
        nd = (mixed *)NIGHTDAY->QueryState();
        if (Noche() && TP->QueryRace() != "orco"
        && TP->QueryShort() != "un troll de las cavernas"
        && (!EsWiz(TP)) && (!TP->Query(P_HIDDEN)))
         	Kill(TP);
}
*/