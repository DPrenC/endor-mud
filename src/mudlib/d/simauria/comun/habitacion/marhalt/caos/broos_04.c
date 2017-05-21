/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitación base, corrijo mogollón de typos y más
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("el norte de una gran cámara");
  SetIntLong("Estás en una gran cámara ligeramente iluminada por antorchas "
    "mortecinas.\nEl desorden reina por toda la estancia. El suelo está "
    "lleno de restos de animales medio devorados, excrementos, y en general "
    "podredumbre.\n"
    "Un pasillo va en dirección noroeste y la cámara se extiende hacia el "
    "sur, suroeste y oeste.\n");
  SetIntBright(25);
  SetIntSmell("El hedor es tan fuerte que no hay moscas.\n");
  AddDetail(({"antorcha","antorchas","antorchas mortecinas"}),
    "Apenas iluminan la estancia y parece que van a apagarse en cualquier "
    "momento.\n"
    "Cuando miras el soporte ves que las antorchas están clavadas a la "
    "pared, por lo que es imposible llevarselas.\n");
  AddExit("noroeste",CAOSHAB"broos_03");
//AddExit("sur",CAOSHAB"guaribroos");
  AddExit("oeste",CAOSHAB"broos_05");
//AddExit("suroeste",CAOSHAB"oesteguaridadelosbroos");
}
