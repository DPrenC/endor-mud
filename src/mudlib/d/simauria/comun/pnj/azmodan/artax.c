/*********************************************************/
//		"artax"
//	El gran shamán orco líder de los clanes, que invoca
//	espíritus.
//		12-12-01: Kodex-> creación
//		12-12-01: Kodex-> última modificación
//              13-06-03: Nemesis->Retocada la descripción
/*********************************************************/


#include <spellmonster.h>
#include <properties.h>
#include "./path.h"
#include <rooms.h>
#include <moving.h>
#include <colours.h>
#include <gremios.h>

inherit SPELLMONSTER;


public status check_sp();
public int magia();


create()
{
::create();
SetStandard("Artax","uruk",([GC_CLERIGO: 60]),GENERO_MASCULINO);
SetShort("Artax el gran chamán");
SetLong("Artax es un chamán orco, sus ojos son de un color "
"rojo brillante, no tiene pupilas, los poderes de los espíritus "
"le rodean, está vestido con una túnica ceremonial y lleva unos "
"tatuajes místicos en sus brazos. Los colmillos le salen de la "
"mandíbula amenazadoramente. Es un ser tremendamente horrendo.\n");
SetIds(({"orco","chamán","chaman","artax"}));
SetAggressive(1);
SetFriendFunction((:($1->QueryRace() == "orco"):));
SetInt(60);
SetAC(30);
SetMaxHP(380);
SetHP(380);
SetAlign(-300);
SetSpellChance(100);
AddItem(ARMA_AZMODAN("necrofirix"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA_AZMODAN("daga"),REFRESH_REMOVE,SF(wieldme));
AddItem(OBJETO_AZMODAN("colgante"),REFRESH_REMOVE,SF(wearme));
AddSpell("conjuros",
  ([
  S_CHECKFUN:SF(check_sp),
  S_FUN:SF(magia), S_SP:2,
  S_CHANCE:25,
  S_VICTIMS:1,
  ]));

InitChats(4,({"Artax dice: 'Descubriré los secretos de esta mina...'\n"}));
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
tell_room(environment(),W(TC_YELLOW+"El chamán levanta las garras y lanza unos agudos gritos invocando al espíritu de algún "+TC_RED+"combatiente orco"+TC_YELLOW+" caído.\n"+TC_NORMAL));
 for(i=0;i<sizeof(en);i++)
 {
   en[i]->Kill(bicho);
 }
return 0;
}