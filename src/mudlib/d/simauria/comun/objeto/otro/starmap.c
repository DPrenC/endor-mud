/*   starmap.c
     Creado por : Nemesis
     Fecha 19-Abr-2001 19:09:33 CEST
     Notas: Un mapa de las estrellas. Puede ser �til en el quest de las
           Geias para satisfacer a la de la Astronom�a.
	   De momento, no obstante, s�lo sirve para venderlo en una tienda
	   y sacar pasta (no mucha, claro est� :)
	   Tambi�n quedar�a mol�n poner un mapa del cielo en ASCII...
*/

#include <properties.h>

inherit THING;

create() {
::create();
SetShort("Un viejo pergamino");
SetLong(
"Parece un viejo mapa del cielo donde est�n representadas las constelaciones. "
"Debe ser muy antiguo.\n");
SetWeight(70);
SetValue(25);
AddId(({"mapa","pergamino","viejo pergamino","mapa de las constelaciones","star_map"}));
}
