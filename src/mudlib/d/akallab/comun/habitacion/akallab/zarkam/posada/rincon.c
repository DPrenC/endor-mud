/*
DESCRIPCION : rincon junto a la chimenea en la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/rincon.c
MODIFICACION: 16-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include "./posada.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("un rincón junto a la chimenea");
 SetIntLong(
   "Te hallas en un rincón apartado del comedor de la "+TIPO+". Aqui hay solo unas "
   "pocas mesas y algunos bancos de madera junto a una gran chimenea de piedra. Un "
   "lento fuego crepita sobre el hogar calentando la estancia. Aqui suele reunirse "
   "la gente para charlar tranquilamente despues de una hornada de trabajo.\n");

  AddDetail(({"comedor"}),
     "El comedor que ocupa mas de la mitad de esta amplia habitacion. Esta lleno de "
     "mesas, la mayoria de las cuales estan llenas de clientes.\n");

  AddDetail(({"mesas"}),
     "La "+TIPO+" esta llena de ellas. Donde sino iban a comer los clientes?\n");

  AddDetail(({"chimenea"}),
     "En la esquina de la habitacion hay una gran chimenea adosada a la pared. En ella "
     "siempre arde un poco de fuego para mantener una estancia tan grande como esta "
     "caliente, mas aun si se tiene en cuenta el frio clima de estas montanyas.\n");

 AddDetail(({"bancos","banco"}),
    "A los lados de la chimenea hay unos largos bancos de madera donde sentarse al "
    "calor del fuego que arde en la chimenea.\n");

SetIntNoise("Las brasas del fuego crepitan lastimeramente.\n");
SetIntSmell("El olor de la madera de pino en el fuego es agradable.\n");
SetLocate("ciudad de Zarkam");
SetIndoors(1);
SetIntBright(50);

AddExit("sur",Z_POSADA("comedor02"));
AddExit("oeste",Z_POSADA("entrada"));
}