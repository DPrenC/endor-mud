/* Por Izet@Simauria.
   Creacion:  3 Marzo, 1997
   U. Modificacion: 3 Mar, 1997
   [Woo] Modificada
*/

#include "./path.h"
#include <properties.h>


inherit THING;

create() {
   ::create();
   SetIds( ({"estatua"}) );
   SetAds( ({"la","gran","enorme","inmensa","una"}) );
   SetShort("la estatua de una mujer");
   SetLong(
"Ante ti ves la estatua de una bella mujer de complexión perfecta y de "
"cabellos negros. Va vestida con una falda muy corta, y de su cinturón "
"cualga una vaina en la que se enfunda una espada de hoja ancha. Lleva un "
"peto de malla, que la cubre desde su estrecha cintura hasta el cuello.\n\
Su cabeza está protegida por un casco, del que sobresalen sus hermosos cabellos "
"recogidos en una laboriosa trenza. Su mirada es fría, y muy calculadora.\n\
Al pie de la estatua ves una placa que podrias leer.\n");
   SetWeight(999999);
   Set(P_NOGET,
"Haciendo un terrible esfuerzo intentas coger la estatua, pero es imposible.\n");
}

init() {
   ::init();
   add_action("Leer","leer");
}

Leer(string str) {
    if (str == "placa" || str == "pie") {
       write("Lees la placa:\n"
"\tA la Heroina de la Justicia, Kassandra,\n"
"\tdefensora de nuestra querida tierra, durante las\n"
"\tguerras contra el Caos.\n");
       say(TP->QueryName()+" lee una placa al pie de la estatua.\n");
       return 1;
     }
     else {
       write("¿Leer qué?\n");
       return 1;
     }
}

