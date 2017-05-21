/*
DESCRIPCION : entrada de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/entrada.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include "./posada.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la entrada de la posada");
  SetIntLong(
     "Te encuentras en la entrada de la "+TIPO+" "+POS_NOM+". Ante ti se "
     "extiende una gran habitacion en cuya zona sur se halla un comedor lleno de "
     "gente. En el rincon nordeste de la habitacion puedes ver unas mesas algo mas "
     "retiradas junto a una gran chimenea donde se reune la gente para charlar.\n");

  AddDetail(({"comedor"}),
     "El comedor que ocupa mas de la mitad de esta amplia habitacion. Esta lleno de "
     "mesas, la mayoria de las cuales estan llenas de clientes.\n");

  AddDetail(({"mesas"}),
     "La "+TIPO+" esta llena de ellas. Donde sino iban a comer los clientes?\n");

  AddDetail(({"chimenea"}),
     "Al fondo del comedor hay una gran chimenea en la que siempre hay un "
     "agradable fuego que mantiene la "+TIPO+" a una confortable temperatura.\n");

  SetIntNoise("Se oye el a la gente del comedor.\n");
  SetIntSmell("Hmm.. huele a comida.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("norte",Z_CIUDAD("plaza_03"));
  AddExit("oeste",Z_CIUDAD("calle_03"));
  AddExit("sur",Z_POSADA("comedor01"));
  AddExit("este",Z_POSADA("rincon"));
}
