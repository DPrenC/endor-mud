/***********************************************************/
//	"mina_3-27"
//	Mina abandonada, habitación Artax
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
SetIntLong(W("Estás en una sala adornada con estandartes cubriendo las sucias"
" rocas. Cada estandarte pertenece a uno de los clanes orcos. Es la habitación "
"del gran shamán que controla a los demás orcos. Hay también una especie de "
"camastro con símbolos de magia negra por todas partes, es la zona más tétrica "
"de toda la mina. Al fondo de la habitación puedes ver un pozo con restos de "
"comida alrededor.\n"));
AddDetail(({"estandartes"}),"Son grandes piezas de cuero con símbolos orcos.\n");
AddDetail(({"pozo"}),"Algo te hace pensar que si bajaras por el no podrías volver a subir.\n");
AddItem(OBJETO_AZMODAN("libro"),REFRESH_REMOVE,1);
AddItem(NPC_AZMODAN("artax"),REFRESH_DESTRUCT,1);
AddExit("sur",MINA_AZMODAN("mina_3-24"));
AddExit("pozo",LABERINTO_AZMODAN(4));
}
