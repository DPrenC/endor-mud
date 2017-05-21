/***********************************************************/
//	"valley_15"
//	Valle, Ungrim
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el norte del valle");
SetIntLong(W("Est�s en frente de una gran entrada excavada en la roca"
" justo al norte, parece ser una mina abandonada. Ves un carro de transportar "
"mineral volcado al lado del camino y carteles de madera tirados por el suelo "
"que dicen: ��Largate de aqu�!!. El suelo en esta zona del valle ha dejado de ser verdoso "
"y parece m�s sombr�o.\n"));
SetIndoors(0);
SetIntNoise("No se oye nada.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"carro"}),
W("Es un carro de transportar mineral, est� viejo, tiene las ruedas oxidadas "
"y por m�s que buscas no ves ning�n resto de minerales preciosos. L�stima.\n"));
AddDetail(({"carteles"}),
"No son nada alentadores.\n");
AddDetail(({"entrada"}),
"Por aqu� puedes entrar a la mina aunque los carteles no te lo recomienden.\n");
AddExit("oeste",VALLE_AZMODAN("valley_14"));
AddExit("este",VALLE_AZMODAN("valley_16"));
AddExit("norte",VALLE_AZMODAN("entrada_1"));
AddExit("sur",VALLE_AZMODAN("valley_11"));
SetLocate("Ungrim");
AddItem(NPC_AZMODAN("ungrim"),REFRESH_DESTRUCT,1);
}