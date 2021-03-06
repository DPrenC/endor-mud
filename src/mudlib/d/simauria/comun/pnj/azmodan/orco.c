/*********************************************************/
//		"orco"
//	El t�pico orco perteneciente a un clan n�mada.
//	toma su clan al nacer y sus atributos se ajustan a
//	su clan. El armamento varia de cimitarra + escudo
//	a 2 cimitarras.
//
//		09-12-01: Kodex-> creaci�n
//		11-12-01: Kodex-> �ltima modificaci�n
/*********************************************************/

#include <nightday.h>
#include <properties.h>
#include "./path.h"
#include <rooms.h>
#include <wizlevels.h>
#include <gremios.h>

inherit NPC;

int combat = 0;


UsarClan(int clan)
{
    switch (clan)
	{
	case 0: SetDex(QueryDex()+4); SetDex(QueryStr()+1); break;
	case 1: SetDex(QueryDex()+5); break;
	case 2: SetMaxHP(QueryHP()+45); SetHP(QueryMaxHP()); break;
	case 3: SetDex(QueryDex()+2); SetDex(QueryStr()+3); break;
	case 4: SetStr(QueryStr()+5); break;
	case 5: SetDex(QueryDex()+3); SetMaxHP(QueryHP()+20); SetHP(QueryMaxHP()); break;
	case 6: SetStr(QueryStr()+3); SetMaxHP(QueryHP()+20); SetHP(QueryMaxHP()); break;
	case 7: SetAC(QueryAC()+3); break;
	default: break;
	}
}


create()
{
string color,clan;
int n;
::create();
SetStandard("un orco","orco-co	mun",([GC_LUCHADOR: d4()+29]),GENERO_MASCULINO);
SetShort("un orco");
n = random(8);
switch (n)
	{
	case 0: color = "gris plateado"; clan = "Nzel-Orak"; break;
	case 1: color = "marr�n cuero"; clan = "Karash"; break;
	case 2: color = "negro azabache"; clan = "Gnarsht"; break;
	case 3: color = "blanco luminoso"; clan = "Korgul"; break;
	case 4: color = "azul marino"; clan = "Tanglor"; break;
	case 5: color = "amarillo llameante"; clan = "Gruniac"; break;
	case 6: color = "azul brillante"; clan = "Jhanzur"; break;
	case 7: color = "rojo sangre"; clan = "Kniel-Zahg"; break;
	default: break;
	}
SetLong(W("Ves un orco. Su pelaje es como terciopelo negro con "
"tintes verdosos. Un par de largos colmillos adornan su gran mand�bula."
" Lleva el s�mbolo de su clan tatuado en la frente, y los brazos tatuados"
" en color " + color +".\n"));
SetIds(({"orco"}));
SetAggressive(1);
SetFriendFunction((:($1->QueryRace() == "orco"):));
SetAlign(-350);
switch (random(2))
	{
	case 0:	AddItem(ARMA_AZMODAN("cimit"),REFRESH_REMOVE,SF(wieldme));
		AddItem(ARMADURA_AZMODAN("esc_mad"),REFRESH_REMOVE,SF(wearme));
		break;
	case 1: AddItem(ARMA_AZMODAN("cimit"),REFRESH_REMOVE,SF(wieldme));
		AddItem(ARMA_AZMODAN("cimit"),REFRESH_REMOVE,SF(wieldme));
		break;
	default:break;
	}
AddItem(ARMADURA_AZMODAN("cuero"),REFRESH_REMOVE,SF(wearme));
InitChats(7,({"Un orco grita: '��Por la fuerza del clan "+ clan +"!!'\n"}));
UsarClan(n);
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
        && TP->QueryShort() != "un troll de las cavernas" &&
        (!EsWiz(TP)) && (!TP->Query(P_HIDDEN)))
         	Kill(TP);

// if (TP->QueryRace() == "orco")
 //say("un orco dice: Saludos " + capitalize(TP->QueryRealName()) +", bienvenid"+ (TP->QueryGenderEndString()) + " a la vieja mina.\n");
 }
 */