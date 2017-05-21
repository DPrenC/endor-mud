/*********************************************************/
//		"artax"
//	El gran sham�n orco l�der de los clanes, que invoca
//	esp�ritus.
//		12-12-01: Kodex-> creaci�n
//		12-12-01: Kodex-> �ltima modificaci�n
//              13-06-03: Nemesis->Retocada la descripci�n
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
SetShort("Artax el gran cham�n");
SetLong("Artax es un cham�n orco, sus ojos son de un color "
"rojo brillante, no tiene pupilas, los poderes de los esp�ritus "
"le rodean, est� vestido con una t�nica ceremonial y lleva unos "
"tatuajes m�sticos en sus brazos. Los colmillos le salen de la "
"mand�bula amenazadoramente. Es un ser tremendamente horrendo.\n");
SetIds(({"orco","cham�n","chaman","artax"}));
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

InitChats(4,({"Artax dice: 'Descubrir� los secretos de esta mina...'\n"}));
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
tell_room(environment(),W(TC_YELLOW+"El cham�n levanta las garras y lanza unos agudos gritos invocando al esp�ritu de alg�n "+TC_RED+"combatiente orco"+TC_YELLOW+" ca�do.\n"+TC_NORMAL));
 for(i=0;i<sizeof(en);i++)
 {
   en[i]->Kill(bicho);
 }
return 0;
}