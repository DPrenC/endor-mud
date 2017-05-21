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

  SetIntShort("el este de la estancia del cieno");
  SetIntLong("Te encuestras en la parte este de una estancia amplia y alta. "
    "El suelo esta cubierto de cieno verdoso mezclado con fragmentos de "
    "conchas y carne putrefacta.\n");
  SetIntSmell("Hueles el f�tido hedor que desprende la mezcla que forma el "
    "cieno, las conchas y la carne putrefacta.\n");
  AddDetail(({"suelo"}),
    "El suelo est� cubierto por una especie de cieno verdoso, fragmentos de "
    "conchas y carne putrefacta.\n");
  AddDetail(({"cieno","cieno verdoso"}),
    "Es algo verde y pringoso, como babas de caracol en plan salvaje y de "
    "tono verdoso.\n");
  AddDetail(({"conchas","framentos","fragmentos de conchas"}),
    "Son fragmentos de conchas como la de los caracoles, pero gigantes.\n");
  AddDetail(({"carne","carne putrefacta"}),
    "S�lo sabes que es carne pero es absolutamente imposible saber de que "
    "ser proviene por el estado de putrefacci�n.\n");
  AddExit("suroeste",CAOSHAB"cieno_01");
  AddExit("nordeste",CAOSHAB"pozo_est_00");
  AddExit("oeste",CAOSHAB"cieno_02");
}
