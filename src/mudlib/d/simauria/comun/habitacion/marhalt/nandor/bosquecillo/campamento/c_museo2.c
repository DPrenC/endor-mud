// c_museo2.c

/*
 Segunda habitación del "Museo de las Cosas Imposibles"
 Habrá un artilugio que se podrá sabotear para obtener
 un pequeño engranaje, que es el objeto que pide Pinky.
 Probablemente el objeto a sabotear sea un reloj, aunque
 puede ser cualquier otra cosa...
 En cualquier caso, habrá que incluir un pequeño flag y
 alguna que otra función para modificar la descripción
 y esas cosas. Vamos, que esta habitación será la leche
 de compleja...
 (c) [n] nemesis@simauria
 Creación:  06-Oct-2002 00:32:26 CEST [n]
 Modificado:

*/

#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;

int saboteado; // Reloj saboteado?

// private int empujar_reloj()

create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetIntShort("el 'Museo de las Cosas Imposibles'");
 SetIntLong(
  W("Te encuentras en un carromato amplio, si bien está atestado de toda "
    "clase de objetos extraños, colocados en vitrinas o pedestales. Sobre "
    "cada uno de ellos puedes ver un cartel. El museo continúa hacia el oeste.\n"));
 SetIndoors(1);
 SetIntBright(60);

// AddDetails: DEBE haber al menos 8-10 'objetos imposibles'
// con sus correspondientes subdetalles si fuera necesario.
// Esto debería dar no menos de 15-20 llamadas a AddDetail.
// Uno de ellos será el objeto a sabotear para obtener el
// engranaje.
// Adicionalmente habrá "otros" detalles, lo que dará un
// total de unos 20-25 detalles. No está nada mal.

 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"vitrinas"}),
 W("Los objetos más pequeños están situados en vitrinas. Sobre cada "
   "una de ellas hay un cartel.\n"));
 AddDetail(({"pedestales"}),
 W("Los objetos más grandes están colocados encima de unos pedestales "
   "de madera en los que hay clavado un cartel.\n"));
 AddDetail(({"carteles","cartel"}),
 "Explican la funcionalidad del objeto con una frase alusiva al mismo.\n");
 AddDetail(({"puerta"}),
 "¿Puerta? ¿Qué puerta? ¿Ya empiezas a imaginarte cosas?\n");

 AddExit("oeste", "c_museo1");

}
