/***********************************************************/
//	"mina_3-28"
//	Mina abandonada,habitación Deimos
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
SetIntLong(W("Te encuentras en la habitación de Deimos, un ogro que lidera varios"
" clanes orcos. Las paredes han sido algo pulidas y algunos adornos de madera las "
"recubren para mejorar el aspecto tosco de la mina. Ves unas sillas de madera una "
"mesa y unos cuantos cráneos. En la mesa puedes ver aún la ultima cena de Morglad.\n"));
AddDetail(({"mesa"}),"Es una mesa de madera vieja, no tiene nada especial.\n");
AddDetail(({"adornos"}),
"Los adornos de madera dan un aspecto más acogedor a la sala excavada en la roca.\n");
AddItem(NPC_AZMODAN("deimos"),REFRESH_DESTRUCT,1);
AddExit("suroeste",MINA_AZMODAN("mina_3-24"));
}
