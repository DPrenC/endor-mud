/*
Fichero: pasillo1.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  pasillos de la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";

create()
{
    ::create();
    	SetIntShort("un pasillo");
   SetIntLong("Te encuentras en un largo pasillo iluminado por faroles que tras un "
   "recodo discurre hacia el este y que al sur desemboca en un amplio vest�bulo.\n"
   "Suelo y paredes est�n hechas de s�lida piedra que atestigua la solidez de la "
   "antigua posada y el alto techo est� ligeramente ennegrecido por los a�os.\n"
   "Al este contin�a el pasillo, al sur se llega al recibidor de la posada que da "
   "acceso al exterior y a las dependencias anexas mientras que al norte hay una "
   "puerta que no parece dar acceso a ning�n dormitorio.\n");
   AddDetail("suelo",
   "El suelo est� hecho de losas de piedra muy antigua y pulida por el paso de "
   "innumerables pies.\n");
   AddDetail(({"muros", "paredes"}),
   "Los gruesos muros est�n levantados con pesados bloques de piedra de forma "
   "irregular y superficie toscamente alisada.\n");
   AddDetail(({"sur", "recibidor"}),
   "Del sur procede el fulgor de la cocina y la sala com�n y un coro de voces, "
   "entrechocar de cubiertos y jarras, charlas y risas.\n");
   AddDetail(({"este", "pasillo"}),
   "Al este se extiende el pasillo al final del cual vislumbras una escalera que "
   "asciende al piso superior.\n");
    	    SetIndoors(1);
    SetIntBright(25);
     AddExit("sur", "./recibidor");
     AddExit("norte", "./salita");
     AddExit("este", "./pasillo2");
     AddDoor("norte", "la puerta del norte",
     "Es una puerta de madera pulida y bien cuidada con una manilla de bronce.\n",
     ({"puerta", "n", "norte", "salita"})); 
    }