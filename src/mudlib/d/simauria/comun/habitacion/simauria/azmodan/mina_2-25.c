/***********************************************************/
//	"mina_2-25"
//	Mina abandonada
//	14-12-01 : Creaci�n -> Kodex
//	14-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la segunda planta de la mina");
SetIntLong(W("Es una habitaci�n excavada en la roca al sur ves un "
"gran agujero en la roca que te permite adentrarte en el segundo nivel "
"de la mina. Hacia arriba por las escaleras llegar�s al primer nivel. "
"Las escaleras son viejas pero la piedra resistir� a�n por muchos a�os.\n"));
AddExit("sur",MINA_AZMODAN("mina_2-23"));
AddExit("arriba",MINA_AZMODAN("mina_1-25"));
}
