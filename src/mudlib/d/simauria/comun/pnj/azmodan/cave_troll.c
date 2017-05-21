/*********************************************************/
//		"cave_troll"
//	La Bestia del laberinto, un troll muy poderoso
//		15-12-02: Kodex-> creación
//		15-02-02: Kodex-> última modificación
//
/*********************************************************/


#include <properties.h>
#include <moving.h>
#include "./path.h"
#include <rooms.h>
#include <colours.h>
#include <gremios.h>

inherit NPC;

object arma1,arma2;


UsarClan(int clan) {
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
SetStandard("un troll","troll",([GC_LUCHADOR: 60]),GENERO_MASCULINO);
SetShort("un troll de las cavernas");
n = random(8);
switch (n)
	{
	case 0: color = "gris plateado"; clan = "Nzel-Orak"; break;
	case 1: color = "marrón cuero"; clan = "Karash"; break;
	case 2: color = "negro azabache"; clan = "Gnarsht"; break;
	case 3: color = "blanco luminoso"; clan = "Korgul"; break;
	case 4: color = "azul marino"; clan = "Tanglor"; break;
	case 5: color = "amarillo llameante"; clan = "Gruniac"; break;
	case 6: color = "azul brillante"; clan = "Jhanzur"; break;
	case 7: color = "rojo sangre"; clan = "Kniel-Zahg"; break;
	default:  break;
	}
SetLong(W("Es un Troll de las cavernas. Es muy grande y debe tener "
"una fuerza descomunal, por sus marcas de color "+color+" parece "
"haber sido adiestrado por el clan "+clan+". Es una criatura horrible "
"salida de una de tus peores pesadillas.\n"));
SetIds(({"troll","troll de las cavernas"}));
SetAlign(-350);
SetGoChance(100);
SetAggressive(1);
InitChats(7,({"¡El troll de las cavernas brama con fuerza!.\n"}));
UsarClan(n);
arma1=clone_object(ARMA_AZMODAN("punyo"));
arma1->SetSize(3);
arma2=clone_object(ARMA_AZMODAN("erizal"));
arma2->SetSize(3);

AddItem(arma1,REFRESH_REMOVE,SF(wieldme));
AddItem(arma2,REFRESH_REMOVE,SF(wieldme));


}

public int QueryRegHP() { return 20;}

move(dest,method,stuff) {
		//nunca sale del laberinto
	if (method==M_GO && dest->QueryLocate()!="Laberinto")
           return ME_NO_ENTER;
	return ::move(dest,method,stuff);
	}
/* tb lo quito
mixed SetCombatDelay(int time , string s)
{
	switch (random(5))
		{
		case 0..3:
			if (!QueryCombatDelay())
			tell_room(environment(TO),TC_PURPLE+"¡¡El troll resiste la parálisis!!\n"+TC_NORMAL);
			return 1;
			break;
		case 4:
                        return delaybeats=time;
			break;
		default:break;
		}
}
*/
public varargs void Die(mixed silent) {
  arma1->SetHitObj(0);
	arma2->SetHitObj(0);
	tell_room(environment(TO),"El troll grita de dolor y cae al suelo provocando un gran temblor.\n");
	::Die(silent);
}

StopAttack() {
  SetCombatDelay(3+random(4));
  tell_room(environment(TO),TC_BOLD+TC_RED+"¡¡¡El troll ruge de furia!!!\n");
  AddHP(50);
}
