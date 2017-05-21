// camp_04.c

/*
 Junto al carro de Lady Morkobva
 (c) [n] nemesis@simauria
 Creaci�n:  03-Nov-2002 00:18:19 CET [n]
 Modificado:

*/

#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;

create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetIntShort("el carro de Lady Morkobva");
 SetIntLong(
 W("Te encuentras junto a un carromato de aspecto poco acogedor. "
   "Cerca de �l, puedes ver otro carro, un carro-jaula de los que "
   "se usan para el transporte de animales. Hacia el norte y el "
   "este hay otros carros, aunque no est�n tan cerca como ese.\n"));
 SetIndoors(0);

 AddDetail(({"carromato-vivienda","carro-vivienda","carromato"}),
 W("Es de color negro salvo por un dibujo en un lateral. Tiene las "
   "ventanas cerradas a cal y canto, como si a su ocupante no le "
   "gustase demasiado la luz del sol.\n"));
 AddDetail(({"ventanas"}),
 "Son bastante peque�as y tienen los postigos cerrados.\n");
 AddDetail(({"dibujo","dibujo en el lateral"}),
 W("Representa unos inquietantes ojos felinos, pintados de manera "
   "que parecen observarte desde la oscuridad. Bajo ellos puedes "
   "adivinar unos blancos y afilados colmillos. Alrededor del dibujo "
   "puedes leer: 'LADY MORKOBVA'.\n"));
 AddDetail(({"carromato-jaula","carro-jaula"}),
 W("Es un carro-jaula como los que se utilizan para transportar "
   "fieras salvajes. Efectivamente, en su interior puedes ver una "
   "pantera negra de aspecto poco amistoso.\n"));
 AddDetail(({"fiera","pantera","pantera negra"}),
 W("Jam�s hab�as visto una pantera de ese tama�o. En sus ojos a�n "
   "no se ha extinguido el fuego de su pasado de libertad en las "
   "junglas, donde era la reina. Al notar que la miras se incorpora "
   "y clava sus ardientes ojos en ti, y en ese momento te das cuenta "
   "de que es una suerte que ella est� ah� dentro y t� aqu� fuera...\n"));
 AddDetail(({"carro del norte","carromato del norte"}),
 "Parece que no es tan l�gubre como �ste, aunque no lo puedes ver bien.\n");
 AddDetail(({"carro del este","carromato del este"}),
 "Parece bastante m�s grande que cualquiera que hayas visto hasta ahora.\n");

// AddItem("morkobva",REFRESH_REMOVE, 1);

// AddExit("norte", "camp_02");
// AddExit("este", "camp_06");

}