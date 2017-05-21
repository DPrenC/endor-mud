/*   starmap.c
     Creado por : Nemesis
     Fecha 19-Abr-2001 19:09:33 CEST
     Notas: Un mapa de las estrellas. Puede ser útil en el quest de las
           Geias para satisfacer a la de la Astronomía.
	   De momento, no obstante, sólo sirve para venderlo en una tienda
	   y sacar pasta (no mucha, claro está :)
	   También quedaría molón poner un mapa del cielo en ASCII...
*/

#include <properties.h>

inherit THING;

create() {
::create();
SetShort("Un viejo pergamino");
SetLong(
"Parece un viejo mapa del cielo donde están representadas las constelaciones. "
"Debe ser muy antiguo.\n");
SetWeight(70);
SetValue(25);
AddId(({"mapa","pergamino","viejo pergamino","mapa de las constelaciones","star_map"}));
}
