/***********************************************************/
//	"mina_3-27"
//	Mina abandonada, habitaci�n Artax
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
SetIntLong(W("Est�s en una sala adornada con estandartes cubriendo las sucias"
" rocas. Cada estandarte pertenece a uno de los clanes orcos. Es la habitaci�n "
"del gran sham�n que controla a los dem�s orcos. Hay tambi�n una especie de "
"camastro con s�mbolos de magia negra por todas partes, es la zona m�s t�trica "
"de toda la mina. Al fondo de la habitaci�n puedes ver un pozo con restos de "
"comida alrededor.\n"));
AddDetail(({"estandartes"}),"Son grandes piezas de cuero con s�mbolos orcos.\n");
AddDetail(({"pozo"}),"Algo te hace pensar que si bajaras por el no podr�as volver a subir.\n");
AddItem(OBJETO_AZMODAN("libro"),REFRESH_REMOVE,1);
AddItem(NPC_AZMODAN("artax"),REFRESH_DESTRUCT,1);
AddExit("sur",MINA_AZMODAN("mina_3-24"));
AddExit("pozo",LABERINTO_AZMODAN(4));
}
