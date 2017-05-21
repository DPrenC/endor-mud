/*
hall3.c
Archivo de: Gorthem, El forjador
Email: jorcama@euibbs.upv.es
Basado en --------.c
Creacion: 11.12.98
Modificacion: 11.12.98
		16-01-05 [Gw] Quito la puerta porque peta y me da miedo
			      ponerme a ver el codigo de las puertas
*/

#include "./path.h"
#include <door.h>
#include <properties.h>
#include <materials.h>
inherit KHA_ROOM;
create() {
 ::create();

 SetIntShort("el hall de Kha-annu");
 SetIntLong("Estas frente a un barracon de guardias enanos, en una garita.\n"
 "Aqui es donde un guardia vigila la entrada a Kha-annu.\n"
 "Los guardias descansan en el interior del barracon.\n"
 "Al sur hay una calle, al oeste la puerta principal.\n");

 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oyes conversaciones de guardias por ahi.\n");
 SetIntSmell("Huele a comida, algo deben estar preparando ahi dentro.\n");

 AddDetail(({"calles","calle"}),
 "Esta calle alumbrada por falores deciende hacia las profundidades "
 "de la montanya.\n");

 AddDetail(({"garita"}),
 "Es un garita con una gran puerta de metal, de vez en cuando entra "
 "y sale un enano del barracon.\n");

  AddItem(MONS+"guardia2",REFRESH_DESTRUCT,1);

    AddExit("sur",("hall6"));
    AddExit("oeste",("hall1"));
    AddExit("suroeste",("hall5"));
    AddExit("este","./barracon");
    AddDoor("este","la puerta de la garita",
        "Es una puerta de hierro, que comunica el hall con la garita de vigilancia.\n",
        ({"puerta","puerta de garita","puerta de hierro"}),GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_STATE:DOOR_CLOSED]));
    }

