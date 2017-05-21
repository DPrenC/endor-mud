/*
DESCRIPCION: Celda situada en el sotano del Arbol de la Vida, bastante pequenya
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTA: Es muy oscura y a no ser que se disponga de vision nocturna se
precisara de una antorcha para poder ver.
MODIFICADO POR : Avengelyne
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("el calabozo del Arbol de la Vida");
SetIntLong(
"Cuando por fin tus ojos se acostumbran a la oscuridad que reina en la\n"
"estancia observas una habitacion de dimensiones reducidas, parece una celda\n"
"Lo que mas te llama la atencion es el techo, esta convado, de forma que no\n"
"puedes ir al fondo de la estancia sin agacharte. Parece la raiz de un arbol\n"
"milenario. Un camastro es el unico mobiliario que posee la celda.\n"
);

AddDetail(({"camastro","catre","cama"}),
"Ves un catre desvencijado, el somier esta formado por madera, pero las patas\n"
"estan astilladas y llenas de agujeros pequenyitos, seguramente producidos\n"
"por la carcoma. El colchon esta estropeado, roto por numerosos sitios\n"
"y deja entrever el material del que esta relleno, lana. Ademas esta convado.\n"
"Numerosas telas de aranya ocupan las patas y el colchon.\n"
);

SetIntBright(10);
SetIntNoise(
"Oyes pasos lejanos aunque no puedes concretar de donde.\n"
);
SetIntSmell(
"Hueles a humedad, unido al olor de la madera mojada, parece que ha llovido\n"
"hace poco.\n"
);
SetLocate("");
SetIndoors(1);

AddExit("sur",TASOTANO("pasillo3"));

}