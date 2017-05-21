// camp_06.c

/*
 Junto al carro de el Gran André
 (c) [n] nemesis@simauria
 Creación: 03-Nov-2002 00:49:52 CET [n]
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
   "Parece que éste es el extremo sur del campamento. A tu alrededor "
   "puedes ver toda clase de aparatos de gimnasia, así como enormes "
   "pesas y un enorme saco de boxeo. También hay un enorme carro que "
   "parece ser el hogar de un ser igualmente formidable, sin duda el "
   "dueño de todos estos trastos que ves por aquí.\nHacia el este y "
   "el oeste puedes ver más carros, y al norte puedes "
   "ver el centro del campamento.\n");
 SetIndoors(0);

 AddDetail(({"carromato","carro"}),
 W("Un inmenso carro-vivienda. La enorme puerta parece indicar que el "
   " ocupante del carro es alguien enorme y muy robusto. Junto a ella "
   "puedes ver colgado un enorme saco de boxeo. En los laterales del "
   "carro puedes ver unas toscas letras rojas.\n"));
 AddDetail(({"letras","letrero"}),
   "Unas enormes letras rojas anuncian: 'ANDRÉ EL INVENCIBLE'.\nSupones "
   "que ése es el nombre del ocupante del carro.\n");
 AddDetail(({"puerta","puerta del carro","puerta del carromato"}),
 W("Es una enorme y sólida puerta hecha de madera, como el carro. Debe "
   "medir unos cuatro metros de alto, así que el ser que ocupa el "
   "carro debe ser alguien de tamaño respetable.\n"));
 AddDetail(({"carro del este","carromato del este"}),
 W("Al este puedes ver otro enorme carro del que parecen venir risas "
   "femeninas.\n"));
 AddDetail(({"carro del oeste","carromato del oeste"}),
 W("Al oeste puedes ver no uno, sino dos carros, ambos bastante más "
   "pequeños que éste, aunque los verías mejor si te acercaras.\n"));
 AddDetail(({"aparatos de gimnasia"}),
 W("Puedes ver una cuerda de saltar, un enorme saco de boxeo y montones "
   "de pesas de todos los tamaños imaginables.\n"));
 AddDetail(({"cuerda"}),
 W("Una simple cuerda de saltar. A un boxeador le serviría para practicar "
   "su juego de piernas. Eso sí, ésta en particular es larguísima.\n"));
 AddDetail(({"pesas","pesas de gimnasia"}),
 W("Las hay de todos los tamaños, pero empezando desde 'enorme' hacia "
   "arriba. El que las utilice para sus ejercicios debe ser un coloso.\n"));
 AddDetail(({"saco","saco de boxeo","enorme saco de boxeo"}),
 W("Una oxidada cadena sujeta un enorme y machacado saco de boxeo junto a "
   "la puerta del carro. Por su aspecto, dirías que al ocupante del carro "
   "le gusta golpearlo con gran violencia cada vez que entra o sale del "
   "mismo.\n"));
 AddDetail(({"hoguera","centro","centro del campamento"}),
 "Al norte hay una hoguera que parece ser el centro del campamento.\n");

// AddItem("andre",REFRESH_REMOVE, 1);

// AddExit("norte", "centro");
// AddExit("este", "camp_05");
// AddExit("oeste","camp_04");

}