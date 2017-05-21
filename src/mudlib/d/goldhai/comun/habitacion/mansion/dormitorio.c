#include "./path.h"
#include <magia.h>

inherit GROOM;

create()
{
::create();
SetIntShort("un dormitorio");
SetIntLong(
"El dormitorio de la mansion es una amplia estancia bien iluminada. En su "
"centro se halla una gran cama con cuatro postes que soportan las cortinas "
"que caen perezosamente a los lados. Junto a la cama un comfortable butacón "
"orientado a la ventana y una pila de libros sobre la mesilla de noche hablan "
"claro de los gustos del dueño de la casa. Junto a la pared se alza un "
"inmenso armario ropero de roble.\n");

 AddDetail(({"cama"}),
"Es inmensa y juzgas que hasta cuatro personas podrían dormir comodamente en "
"ella. Los postes adosados a las esquinas mantienen las cortinas que la "
"cubren.\n");

AddDetail(({"butacón","butacon"}),
"Es grande y cubierto de cuero. Parece muy confortable.\n");

AddDetail(({"mesilla"}),
"La mesilla de noche se halla junto al butacón. Sostiene una gran pila de libros.\n");

AddDetail(({"libros"}),
"Dirias que al menos puede haber unos 10 o 12 sobre la mesilla.\n");

AddDetail(({"armario","ropero"}),
"Es un inmenso armario ropero de madera de roble.\n");

 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(50);
 SetIntNoise("No oyes nada especial.\n");
 SetIntSmell("No huele a nada especial.\n");

 SetTPort(TPORT_NO);

 AddItem(QUEST "hardester/hardester",REFRESH_DESTRUCT,1);
 AddExit("abajo",MANSION("entrada"));

 SetLocate("mansión de Hardester Rankomme");
}