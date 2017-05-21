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

  SetIntShort("la estancia del cieno");
  SetIntLong("Te encuentras en la parte oeste de una estancia bastante "
    "amplia y muy alta (unos 13 metros). El suelo está cubierto de cieno "
    "verdoso mezclado con fragmentos de conchas y carne putrefacta.\n");
  SetIntSmell("Hueles el fetido hedor que desprende la mezcla que forma el "
    "cieno, las conchas y la carne putrefacta.\n");
  SetIntNoise("Escuchas movimiento de agua hacia el oeste.\n");
  AddDetail(({"suelo"}),
    "El suelo esta cubierto por una especie de cieno verdoso, fragmentos de "
    "conchas y carne putrefacta.\n");
  AddDetail(({"cieno","cieno verdoso"}),
    "Es algo verde y pringoso, como babas de caracol en plan salvaje y de "
    "tono verdoso.\n");
  AddDetail(({"conchas","fragmentos","fragmentos de conchas"}),
    "Son fragmentos de conchas como la de los caracoles, pero gigantes.\n");
  AddDetail(({"carne","carne putrefacta"}),
    "Solo sabes que es carne pero es absolutamente imposible saber de que "
    "ser proviene por el estado de putrefacción.\n");
  AddExit("norte",CAOSHAB"cieno_03");
  AddExit("oeste",CAOSHAB"cieno_04");
  AddExit("sur",CAOSHAB"cieno_01");
  AddExit("este",CAOSHAB"cieno_05");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
