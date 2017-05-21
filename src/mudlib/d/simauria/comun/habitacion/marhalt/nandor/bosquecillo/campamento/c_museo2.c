// c_museo2.c

/*
 Segunda habitaci�n del "Museo de las Cosas Imposibles"
 Habr� un artilugio que se podr� sabotear para obtener
 un peque�o engranaje, que es el objeto que pide Pinky.
 Probablemente el objeto a sabotear sea un reloj, aunque
 puede ser cualquier otra cosa...
 En cualquier caso, habr� que incluir un peque�o flag y
 alguna que otra funci�n para modificar la descripci�n
 y esas cosas. Vamos, que esta habitaci�n ser� la leche
 de compleja...
 (c) [n] nemesis@simauria
 Creaci�n:  06-Oct-2002 00:32:26 CEST [n]
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
  W("Te encuentras en un carromato amplio, si bien est� atestado de toda "
    "clase de objetos extra�os, colocados en vitrinas o pedestales. Sobre "
    "cada uno de ellos puedes ver un cartel. El museo contin�a hacia el oeste.\n"));
 SetIndoors(1);
 SetIntBright(60);

// AddDetails: DEBE haber al menos 8-10 'objetos imposibles'
// con sus correspondientes subdetalles si fuera necesario.
// Esto deber�a dar no menos de 15-20 llamadas a AddDetail.
// Uno de ellos ser� el objeto a sabotear para obtener el
// engranaje.
// Adicionalmente habr� "otros" detalles, lo que dar� un
// total de unos 20-25 detalles. No est� nada mal.

 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"vitrinas"}),
 W("Los objetos m�s peque�os est�n situados en vitrinas. Sobre cada "
   "una de ellas hay un cartel.\n"));
 AddDetail(({"pedestales"}),
 W("Los objetos m�s grandes est�n colocados encima de unos pedestales "
   "de madera en los que hay clavado un cartel.\n"));
 AddDetail(({"carteles","cartel"}),
 "Explican la funcionalidad del objeto con una frase alusiva al mismo.\n");
 AddDetail(({"puerta"}),
 "�Puerta? �Qu� puerta? �Ya empiezas a imaginarte cosas?\n");

 AddExit("oeste", "c_museo1");

}
