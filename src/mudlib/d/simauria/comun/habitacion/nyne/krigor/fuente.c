/*
DESCRIPCION  : Manantial del norte de Krigor.
FICHERO      : KRIGOR("fuente")
MODIFICACION : 08-11-02 [Chaos@Simauria] Creacion.

--------------------------------------------------------------------------------
*/

#include "path.h"
#include <sounds.h>
inherit SIM_ROOM;

create()
{
    ::create();
	SetIntShort("la fuente del pueblo de Krigor");
	SetIntLong(W("Te encuentras al lado de un pequeña fuentecilla de agua cristalina. "+
		"Debajo ves un pequeño estanque donde cae el agua, del cual sale un fino "+
		"chorro de agua que se filtra por entre las piedrecillas del suelo. Ves "+
	 	"unas altas montañas que rodean el valle. Hacia el noroeste ves la casa "+
		"de algun ganadero de la zona.\n"));
	//Algun ke otro detalle
	AddDetail(({"agua"}),
	        W("El agua es fría y transparente, te dan ganas de bebértela. "+
		  "Seguro que te refresca y apaga tu sed.\n"));
	AddDetail(({"chorro"}),
	        "Es un fino hilillo de agua que cae en un estanque.\n");
	AddDetail(({"piedras","piedrecillas"}),
	        W("Son unas piedrecillas blancas que han sido alisadas por "+
		  "el paso del agua durante años.\n"));
	AddDetail(({"montaña","montanya","montañas","montanyas"}),
	        W("Son unas escarpadas montañas que rodean todo el valle del "
 		  "pueblo de Krigor.\n"));
	AddDetail(({"krigor","Krigor"}),
	        W("Es el típico pueblo de montaña, con diversas casas por los "
		  "alrededores y una plaza donde se encuentran los edificios "
		  "más significativos.\n"));
	AddDetail(({"casa"}),
	        "Es una casa de madera con el tejado de pizarra.\n");
	AddDetail(({"tejado","tejado de pizarra"}),
		W("Sin duda está hecho así para que la nieve no se acumule "
		  "sobre él en invierno y lo hunda.\n"));
	AddDetail(({"estanque"}),
	        W("Es un estanque de piedra pulida. Es un poco tosco, "+
   		  "pero cumple su función perfectamente y tiene un pequeño "
		  "agujero por el cual sale el agua que se derrama. Las vacas "
		  "suelen beber del estanque.\n"));
   	// Añadir adddetail flores
	// Añadir adddetail pájaros

	SetIntNoise("Se oye el trinar de los pájaros y el murmullo del agua "
	            "de la fuente.\n");
	SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
	SetLocate("Krigor");
	SetIndoors(0);
	AddItem(OTRO("nyne/fuente"));
	AddExit("oeste",KRIGOR("prado10"));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}