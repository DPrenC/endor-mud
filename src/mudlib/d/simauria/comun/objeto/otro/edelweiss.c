/*   edelweiss.c
     Creado por : Nemesis
     Fecha 18-Abr-2001 22:10:44 CEST
     Notas: En principio, sólo está para dar más colorido al Gremio de
           Psiónicos, pero en un futuro podría formar parte de un quest
	   tipo el de la curandera, pero inter-dominio. De hecho, se me
	   está ocurriendo uno en este preciso instante...
*/

#include <properties.h>

inherit THING;

create() {
::create();
SetShort("Un edelweiss");
SetLong(
"Una pequeña flor de las cumbres. El borde de sus pétalos parece tener un\n"
"tenue brillo plateado.\n");
SetWeight(7);
SetValue(3);
AddId(({"flor","edelweiss","edel_weiss"}));
}
