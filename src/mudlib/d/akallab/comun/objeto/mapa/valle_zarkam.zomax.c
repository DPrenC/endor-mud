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


