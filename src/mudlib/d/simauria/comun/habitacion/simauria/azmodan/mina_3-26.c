/***********************************************************/
//	"mina_3-26"
//	Mina abandonada, habitación Phobos
//	15-12-01 : Creación -> Kodex
//	15-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("el tercer nivel de la mina");
SetIntLong(W("En esta sala ves un camastro viejo al fondo de la habitación"
", aquí vive Phobos un ogro líder de varios clanes orcos. La habitación "
"tiene un par de estandartes a los lados con símbolos de clanes orcos y "
"algunas inscripciones que parecen contar el número de rivales caídos que "
"lleva el dueño de la habitación.\n"));
AddItem(NPC_AZMODAN("phobos"),REFRESH_DESTRUCT,1);
AddExit("sudeste",MINA_AZMODAN("mina_3-24"));
}
