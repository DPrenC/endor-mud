/*********************************************************/
//		"goblin"
//
//	Los goblins son como los orcos en cuanto a los clanes
//	nada más nacer toman un clan y esto les cambia los
//	atributos y alguna cosilla más
//
//		09-12-01: Kodex-> creación
//		11-12-01: Kodex-> última modificación
/*********************************************************/

#include "./path.h"
#include <properties.h>
#include <colours.h>
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
SetStandard("un goblin","trasgo",([GC_LUCHADOR: d6()+12]),GENERO_MASCULINO);
AddWalkZones(VALLE_AZMODAN(""));
SetShort("un goblin");
n = random(7);
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
	default: break;
	}
SetLong(W("Ves un pequeño goblin. Es una criatura parecida a un "
"orco pero de mucho menor tamaño. Viven esclavizados por ellos y, "
"siempre que hay un goblin... habrá orcos cerca. Lleva el símbolo "
"de su clan tatuado en la frente, y los brazos tatuados en color " + color +".\n"));
SetIds(({"goblin"}));
RemoveId(({"orco"}));
SetAggressive(random(2));
SetFriendFunction((:($1->QueryRace() == "orco"):));
SetAlign(-300);
SetWhimpy(55);
AddItem(ARMA_AZMODAN("espada_corta"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMADURA_AZMODAN("esc_mad"),REFRESH_REMOVE,SF(wearme));
InitChats(4,({"Un goblin dice: '¡¡Sirvo al clan "+ clan +"!!'\n"}));
SetGoChance(35);
AddWalkZones("MINA_AZMODAN");
UsarClan(n);
}

int Es_Goblin (object npc)
	{
	if (npc->QueryShort() == "un goblin" && npc != TO)
	return 1;
	else
	return 0;
	}

DoDamage(int dmg)
	{
		//si atacas a un goblin, los demás goblins
		//de la habitación le ayudarán
        int i;
        object *gobs;
        gobs = filter(deep_inventory(environment(TO)),"Es_Goblin");

        if(sizeof(gobs))
          for(i=0;i<sizeof(gobs);i++)
          {
            gobs[i]->Kill(TP || PO);
            if (!combat)
            	{
            		say(TC_GREEN+"un goblin grita: '¡¡¡Ayuda!!! ¡¡¡Ayuda!!!'\n"+TC_NORMAL);
            		combat++;
            	}
          }
        return ::DoDamage(dmg);
       }
