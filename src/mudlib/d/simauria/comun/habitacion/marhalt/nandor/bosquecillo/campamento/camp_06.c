// camp_06.c

/*
 Junto al carro de el Gran Andr�
 (c) [n] nemesis@simauria
 Creaci�n: 03-Nov-2002 00:49:52 CET [n]
 Modificado:

*/

#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;

create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetPreIntShort("junto a");
 SetIntShort("el carro de los gemelos Trassi");
 SetIntLong(
   "Parece que �ste es el extremo sur del campamento. A tu alrededor "
   "puedes ver toda clase de aparatos de gimnasia, as� como enormes "
   "pesas y un enorme saco de boxeo. Tambi�n hay un enorme carro que "
   "parece ser el hogar de un ser igualmente formidable, sin duda el "
   "due�o de todos estos trastos que ves por aqu�.\nHacia el este y "
   "el oeste puedes ver m�s carros, y al norte puedes "
   "ver el centro del campamento.\n");
 SetIndoors(0);

 AddDetail(({"carromato","carro"}),
 W("Un inmenso carro-vivienda. La enorme puerta parece indicar que el "
   " ocupante del carro es alguien enorme y muy robusto. Junto a ella "
   "puedes ver colgado un enorme saco de boxeo. En los laterales del "
   "carro puedes ver unas toscas letras rojas.\n"));
 AddDetail(({"letras","letrero"}),
   "Unas enormes letras rojas anuncian: 'ANDR� EL INVENCIBLE'.\nSupones "
   "que �se es el nombre del ocupante del carro.\n");
 AddDetail(({"puerta","puerta del carro","puerta del carromato"}),
 W("Es una enorme y s�lida puerta hecha de madera, como el carro. Debe "
   "medir unos cuatro metros de alto, as� que el ser que ocupa el "
   "carro debe ser alguien de tama�o respetable.\n"));
 AddDetail(({"carro del este","carromato del este"}),
 W("Al este puedes ver otro enorme carro del que parecen venir risas "
   "femeninas.\n"));
 AddDetail(({"carro del oeste","carromato del oeste"}),
 W("Al oeste puedes ver no uno, sino dos carros, ambos bastante m�s "
   "peque�os que �ste, aunque los ver�as mejor si te acercaras.\n"));
 AddDetail(({"aparatos de gimnasia"}),
 W("Puedes ver una cuerda de saltar, un enorme saco de boxeo y montones "
   "de pesas de todos los tama�os imaginables.\n"));
 AddDetail(({"cuerda"}),
 W("Una simple cuerda de saltar. A un boxeador le servir�a para practicar "
   "su juego de piernas. Eso s�, �sta en particular es largu�sima.\n"));
 AddDetail(({"pesas","pesas de gimnasia"}),
 W("Las hay de todos los tama�os, pero empezando desde 'enorme' hacia "
   "arriba. El que las utilice para sus ejercicios debe ser un coloso.\n"));
 AddDetail(({"saco","saco de boxeo","enorme saco de boxeo"}),
 W("Una oxidada cadena sujeta un enorme y machacado saco de boxeo junto a "
   "la puerta del carro. Por su aspecto, dir�as que al ocupante del carro "
   "le gusta golpearlo con gran violencia cada vez que entra o sale del "
   "mismo.\n"));
 AddDetail(({"hoguera","centro","centro del campamento"}),
 "Al norte hay una hoguera que parece ser el centro del campamento.\n");

// AddItem("andre",REFRESH_REMOVE, 1);

// AddExit("norte", "centro");
// AddExit("este", "camp_05");
// AddExit("oeste","camp_04");

}