/*********************************************************/
//		"phobos"
//	        El pequeño ogro de nivel 58!
//		12-12-01: Kodex-> creación
//		10-01-02: Kodex-> última modificación
//		*Cambiado el nombre de phobos por Delrek
//
/*********************************************************/

inherit NPC;
#include <properties.h>
#include "./path.h"
#include <rooms.h>
#include <gremios.h>


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
SetStandard("Delrek","ogro",([GC_LUCHADOR: 58]),GENERO_MASCULINO);
SetShort("Delrek el ogro");
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
	default: break;
	}
SetLong("Delrek es un ogro, más grande que un orco, más corpulento"
", más fuerte e igual de inteligente, su mirada te inspira temor y "
"tiene una gran cicatriz que le cruza la cara. Tiene pinturas de "
"guerra de color " + color +" por todo el cuerpo.\n");
SetIds(({"ogro","delrek","delrek el ogro"}));
SetAggressive(0);
SetAlign(-200);
AddItem(ARMA_AZMODAN("erizal"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA_AZMODAN("punyo"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMADURA_AZMODAN("cota"),REFRESH_REMOVE,SF(wearme));
InitChats(7,({"Delrek dice: '¡¡¡Soy el líder del clan "+ clan +"!!! "
"Mi hermano Morglad y yo te haremos papilla.'\n"}));
UsarClan(n);
}

void init()
{
 ::init();
 if (TP->QueryRace() != "orco")
 	Kill(TP);
 else
 tell_room(environment(), "Phobos dice: Qué haces aquí " + capitalize(TP->QueryRealName()) +
 "!, vete a trabajar con los demás.\n");
}
