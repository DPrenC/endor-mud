/*
Por [F] Fran@simauria
       15 oct 1999 : aqui quiero meter un quest en un tiempo
*/

#include "path.h"
inherit KHA_ROOM;

create() {
::create();

SetIntShort("una c�mara.");
  SetIntLong(
    "Est�s en una c�mara muy amplia con aspecto de antigua,\n"
    "hay l�mparas en las paredes, pero son de un tipo que no habias visto.\n"
    "El suelo de esta c�mara es de una especie de marmol blanco y negro en\n"
    "en cual parece haber una figura.\n"
    );

SetIntBright(40);
AddExit("norte",MPISO2+"bifsur2so2");

AddDetail(({"lampara","lamparas","l�mpara","l�mparas"}),
"En todas las paredes hay l�mparas de color dorado y plateado,con "
" un simbolo junto al gancho que las fija a la pared.\n");

AddDetail(({"simbolo"}),
"Es un martillo con una inscripcion: 'Clan del Martillo del Trueno'.\n");

AddDetail(({"suelo","figura"}),
"Mir�ndolo mas detenidamente te das cuenta de que es un GRAN martillo con "
" un intrincado dibujo en todo el mango y una especie de rayos saliendo "
" de la parte superior, es impresionante.\n");
SetIntSmell("Hueles a cerrado en esta c�mara.\n");
}