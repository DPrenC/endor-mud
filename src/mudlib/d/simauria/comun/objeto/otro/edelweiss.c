/*   edelweiss.c
     Creado por : Nemesis
     Fecha 18-Abr-2001 22:10:44 CEST
     Notas: En principio, s�lo est� para dar m�s colorido al Gremio de
           Psi�nicos, pero en un futuro podr�a formar parte de un quest
	   tipo el de la curandera, pero inter-dominio. De hecho, se me
	   est� ocurriendo uno en este preciso instante...
*/

#include <properties.h>

inherit THING;

create() {
::create();
SetShort("Un edelweiss");
SetLong(
"Una peque�a flor de las cumbres. El borde de sus p�talos parece tener un\n"
"tenue brillo plateado.\n");
SetWeight(7);
SetValue(3);
AddId(({"flor","edelweiss","edel_weiss"}));
}
