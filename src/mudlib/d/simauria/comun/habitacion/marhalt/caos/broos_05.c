/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitaci�n base, corrijo mogoll�n de typos y m�s
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("el noroeste de una gran c�mara");
  SetIntLong("Est�s en la parte noroeste de una gran c�mara ligeramente "
    "iluminada por antorchas mortecinas.\n"
    "El desorden reina por toda la estancia. El suelo est� lleno de restos "
    "de animales medio devorados, excrementos, y en general podredumbre.\n"
    "La c�mara se extiende hacia el este, Sudeste y sur.\n");
  SetIntBright(25);
  AddDetail(({"antorcha","antorchas","antorchas mortecinas"}),
    "Apenas iluminan la estancia y parece que van a apagarse en cualquier "
    "momento.\n"
    "Cuando miras el soporte ves que las antorchas est�n clavadas a la "
    "pared, por lo que es imposible llevarselas.\n");
//AddExit("sur",CAOSHAB"oesteguaridadelosbroos");
  AddExit("este",CAOSHAB"broos_04");
//AddExit("sudeste",CAOSHAB"guaridadelosbroos");
}
