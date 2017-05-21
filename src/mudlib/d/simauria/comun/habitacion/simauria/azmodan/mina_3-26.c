/***********************************************************/
//	"mina_3-26"
//	Mina abandonada, habitaci�n Phobos
//	15-12-01 : Creaci�n -> Kodex
//	15-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("el tercer nivel de la mina");
SetIntLong(W("En esta sala ves un camastro viejo al fondo de la habitaci�n"
", aqu� vive Phobos un ogro l�der de varios clanes orcos. La habitaci�n "
"tiene un par de estandartes a los lados con s�mbolos de clanes orcos y "
"algunas inscripciones que parecen contar el n�mero de rivales ca�dos que "
"lleva el due�o de la habitaci�n.\n"));
AddItem(NPC_AZMODAN("phobos"),REFRESH_DESTRUCT,1);
AddExit("sudeste",MINA_AZMODAN("mina_3-24"));
}
