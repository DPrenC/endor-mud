// camp_01.c

/*
 Entrada al claro donde est� el campamento.
 (c) [n] nemesis@simauria
 Creaci�n:  14-Oct-2002 00:53:10 CEST [n]
 Modificado:

*/

#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;

create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetIntShort("la entrada a un campamento de titiriteros");
 SetIntLong(
 W("Has llegado a un claro en el bosque. Parece que un grupo de c�micos "
   "ambulantes lo ha elegido para descansar. Uno de ellos se encuentra "
   "aqu� arreglando un viejo carromato. Puedes internarte en el campamento "
   "hacia el sur, o volver al bosque hacia el norte.\n"));
 SetIndoors(0);

 AddDetail(({"carromato","viejo carromato","carromato averiado",
             "carro","viejo carro","carro averiado"}),
   "Es un enorme carro pintado de brillantes colores, aunque se nota "
   "que ya tiene bastantes a�os. Le falta una rueda, que ha sido "
   "sustitu�da temporalmente por una pila de ladrillos.\n");
 AddDetail(({"pila de ladrillos","ladrillos"}),
 "Sostienen temporalmente el carro hasta que la rueda sea reparada.\n");
 AddDetail(({"rueda","rueda averiada"}),
 W("Parece que la rueda se solt� del eje por alguna raz�n. Uno de los "
   "miembros de la compa��a est� aqu� intentando repararla.\n"));
 AddDetail(({"campamento","campamento de titiriteros","carromatos"}),
 W("Puedes ver un grupo de carros al sur, junto a un peque�o arroyo. "
   "Es posible que esta gente est� aqu� detenida mientras reparan el "
   "carro que tienes delante de ti.\n"));
 AddDetail(({"claro","claro en el bosque"}),
 W("Parece que un grupo de artistas ambulantes ha elegido este lugar "
   "para descansar. Puedes ver sus carromatos aparcados un poco m�s "
   "al sur.\n"));
 AddDetail(({"arroyo","peque�o arroyo","pequenyo arroyo"}),
 W("Una peque�a corriente de agua corre en direcci�n norte-sur y pasa "
   "muy cerca del grupo de carros, proporcionando al campamento agua "
   "fresca.\n"));

// AddItem("baskari",REFRESH_REMOVE, 1);

// AddExit("norte", "fuera");
// AddExit("sur", "centro");

}
