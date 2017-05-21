/*
DESCRIPCION: Celda situada en el sotano del Arbol de la Vida, bastante pequenya
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTA: Es muy oscura y a no ser que se disponga de vision nocturna se
precisara de una antorcha para poder ver.
[Ch] Chantiel.
     Deberia de ponerse una funcion que permita llegar hasta el fondo de la
habitacion para posibles resoluciones de quest. Sugiero "agacharse".
MODIFICADO POR : Avengelyne
                 [Ch]
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("un calabozo del Arbol de la Vida");
SetIntLong(
"Cuando por fin tus ojos se acostumbran a la oscuridad que reina en la estancia\n"
"observas una habitacion de dimensiones reducidas, parece una celda. Lo que mas\n"
"te llama la atencion es el techo, esta convado, de forma que no puedes ir al\n"
"fondo de la estancia sin agacharte. Parece la raiz de un arbol milenario. Un\n"
"camastro es el unico mobiliario que posee la celda. La salida mas cercana esta\n"
"al sur de la estancia.\n"
);

AddDetail(({"camastro","catre","cama"}),
"Ves un catre desvencijado, el somier esta formado por madera, pero las patas\n"
"estan astilladas y llenas de agujeros pequenyitos, seguramente producidos por la\n"
"carcoma. El colchon esta estropeado, roto por numerosos sitios y deja entrever\n"
"el material del que esta relleno, lana. Ademas esta convado.\n"
"Numerosas telas de aranya ocupan las patas y el colchon.\n"
);

SetIntBright(10);
SetIntNoise(
"Oyes pasos lejanos aunque no puedes concretar de donde.\n"
);
SetIntSmell(
"Hueles a humedad, unido al olor de la madera mojada. Al parecer ha llovido hace\n"
"poco tiempo.\n"
);
SetLocate("");
SetIndoors(1);

AddExit("sur",TASOTANO("pasillo3"));

}