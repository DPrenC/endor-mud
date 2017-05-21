/*
DESCRIPCION  : Salon de reuniones en el ayuntamiento
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/salon_ayto.c
MODIFICACION : 26-07-98 [Angor@Simauria] Creacion.
               24-10-98 [Angor@Simauria] Separado el salon del gremio
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>

inherit ROOM;

#define A_      (TP->QueryGender()==GENDER_FEMALE?"a":"")
#define AO      (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define NOMBRE  (capitalize(TP->QueryName()))

static int dormido;

create() {
  ::create();
  SetIntShort("el sal�n del ayuntamiento");
  SetIntLong(
     "Est�s en una amplia sala de reuniones en el ayuntamiento. Aqu� se reune la gente "
     "del pueblo cuando se debe discutir alg�n tema de inter�s com�n o por el mero "
     "hecho de charlar un rato. Al fondo hay una chimenea y varios c�modos butacones "
     "donde descansar y charlar al calor del fuego. La paredes est�n adornadas con "
     "varios trofeos colgados en ellas.\n");

  AddDetail(({"chimenea","brasas"}),
     "Es una chimenea baja y ancha de piedra en la que arden lentamente las brasas de "
     "un fuego, proporcionando una agradable temperatura al ambiente.\n");

  AddDetail(({"butacones","butacas"}),
     "Junto a la chimenea y formando un peque�o corro hay unos cuantos butacones que "
     "sin duda conocieron tiempos mejores. Son una especie de sofas individuales "
     "forrados con una descolorida tela de color azulado.\n");

  AddDetail(({"trofeos"}),
     "A lo largo de las paredes del sal�n hay colgados varios trofeos obtenidos por "
     "algunos de los ciudadanos del pueblo. Puedes observar varias cabezas disecadas "
     "de animales salvajes, una vieja y oxidada espada e incluso una red para cazar "
     "cangrejos, premio del ultimo concurso de pesca celebrado aqui en la isla.\n");

  AddDetail(({"cabezas","cabezas disecadas"}),"Seguro que sus due�os ya no las echan de menos.\n");

  AddDetail(({"red","cazacangrejos","red cazacangrejos"}),
     "Es una red en forma de bolsa para atrapar cangrejos. Est� fijada a una plancha "
     "de madera en la que figura la siguiente inscripci�n: 'Primer premio del LXXV "
     "concurso anual de pesca del cangrejo colorado conseguido por Vernao'.\n");

SetIntNoise("El brasas del fuego crepitan ocasionalmente.\n");
SetIntSmell("Huele un poco a humo.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);


AddExit("sur",LIMBO("ayuntamiento"));
AddItem(PNJ("taramu"));
}