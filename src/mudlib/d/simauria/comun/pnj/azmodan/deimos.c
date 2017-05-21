/*********************************************************/
//		"deimos"
//	El hermano mayor de Phobos un ogro cachas!
//		12-12-01: Kodex-> creación
//		10-01-02: Kodex-> última modificación
//	*Cambiado el nombre Deimos por Morglad.
//
/*********************************************************/

#include <properties.h>
#include "./path.h"
#include <rooms.h>
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
SetStandard("Morglad","ogro",([GC_LUCHADOR: 66]),GENERO_MASCULINO);
SetShort("Morglad el ogro");
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
SetLong("Morglad es un ogro, más grande que un orco,"
" más corpulento, más fuerte e igual de inteligente, sonríe "
"como si estuviera muy seguro de sí mismo.\n tiene pinturas de "
"guerra de color " + color +" por todo el cuerpo.\n");
SetIds(({"ogro","morglad","morglad el ogro"}));
SetAggressive(0);
SetAlign(-200);
AddItem(ARMA_AZMODAN("erizal"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA_AZMODAN("punyo"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMADURA_AZMODAN("cota"),REFRESH_REMOVE,SF(wearme));
InitChats(7,({"Morglad dice: '¡¡¡Soy el líder del clan "+ clan +"!!! No te metas con nosotros.\n","Morglad dice: 'Tengo que cuidar al pequeño Delrek.'\n"}));
UsarClan(n);
}

void init()
{
 ::init();
 if (TP->QueryRace() != "orco")
 	Kill(TP);
 else
 tell_room(environment(), "Deimos dice: Qué haces aquí " + capitalize(TP->QueryRealName()) +
 "!, vete a trabajar con los demás.\n");
}
