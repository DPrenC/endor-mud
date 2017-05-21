/*
DESCRIPCION : mapa del valle de Zarkam
FICHERO     : /d/akallab/comun/objeto/mapa/valle_zarkam.c
MODIFICACION: 17-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit THING;

create() {
  ::create();
 SetShort("mapa del valle de Zarkam");
  SetLong(
"   _   _  _       _  _     _  _    _  _  _        MAPA DEL VALLE DE ZARKAM\n"       //
" _/ \\_/ \\/ \\ (1) / \\/ \\(2)/ \\/ \\  / \\/ \\/_\\    1. Desfiladero de Kuntz\n" //
"/ \\_/ \\         \\            :(f)    *   /_\\   2. Cordillera de Kova\n"         //
" _/ \\ río Kuneii |(b)         : río *   _/ \\   3. Paso de Akkbar\n"               //
"/_\\        ****** \\      __,-- 'Zarmaii/_\\     4. Montanyas Negras\n"            //
"/_\\  (9)-*-,___  */--,-'****     '..*../_\\     5. Desfiladero de Sharg\n"         //
"/_\\    *       `--|** '--,__*****  *   / \\(a)  6. Diente de Sharg\n"              //
"/ \\_              |    .'  *\\ '. *******}}}    7. Cordillera de Sharg\n"          //
"  /_\\           Zarkam : (e) | :      / \\  **  8. Montanyas de Shojuna\n"         //
"  / \\             |     '*..|.'  ___(3)_       9. Minas\n"                         //
" (8)_         (b)/     _*__/----'(c) _/ \\      a. Cataratas de Nurr\n"             //
"   /_\\          |----'  * río       /_\\        b. Sendero de los Craneos\n"       //
"  _/ \\         /_(6)    * Kusaii    (4)        c. Camino del Este\n"               //
" / \\_  _  _   |/ \\_  _   * _   _  _/ \\         e. Campos de cultivo\n"           //
"   / \\/ \\/ \\ (5) / \\/ \\(7)/ \\ / \\/ \\           f. Bosque\n");

  SetValue(200);
  SetWeight(200);
  SetIds(({"mapa","mapa de Zarkam","mapa de zarkam"}));
}

init(){
  ::init();

  add_action("fleer","leer");
}

public int fleer(string str)
{
	if(str && id(str))
	{
		write("   Zarkam se encuentra situado justo en el centro de un valle del que ha "
		"tomado su nombre. Para entrar al valle existen tres caminos: el desfiladero de "
		"Kuntz, al norte, el de Sharg, al sur, y el paso de Akkbar, al este. Los desfiladeros "
		"están unidos entre si por el sendero de los cráneos, un cuya mitad más o menos se "
		"encuentra el pueblo de Zarkam.\n\n   Siguiendo el sendero de los cráneos hacia el norte "
		"al salir de Zarkam encuentras un monolito. En ese punto un camino se bifurca hacia "
		"las minas, al oeste, mientras que el sendero sigue al norte. Siguiendo al norte, "
		"cuando el sendero cruza el río Kuneii, un pequeño camino vuelve a separarse de él "
		"en sentido este y lleva hacia el bosque que hay al nordeste de Zarkam. Justo al norte "
		"de este bosque está la cordillera de Kova.\n\n   Otra vez en Zarkam si en lugar de tomar el "
		"camino norte del sendero lo hacemos por el sur tarde o temprano encuentras un camino "
		"que se separará por el este del sendero, llevándote a los campos de cultivo y al paso "
		"de Akkbar, en el extremo este del valle.\n");
		return 1;
	}
}
