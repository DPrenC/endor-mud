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

  SetIntShort("la entrada de la caverna");
  SetIntLong("Te encuentras en una habitación aproximadamente circular de "
    "unos 10 metros de diámetro. Las paredes son de color marrón claro. "
    "El suelo es irregular y está cubieto de pequeñas piedras rojizas. "
    "En la pared hay una inscripción y al este una especie de figura bajo "
    "la que corren algunas ratas.\n"
    "La caverna continua al sudeste, y la salida se encuentra al oeste.\n"
    "Ves un gran cartel a tu lado.\n");
  SetIndoors(0);
  SetIntSmell("Sólo hueles el fétido olor que desprende la basura de la "
    "entrada.\n");
  SetIntNoise("Sólo escuchas el ruido de alguna rata al corretear.\n");
  AddDetail(({"cartel","Cartel","CARTEL","gran cartel"}),
    "En esta caverna viven seres malignos poderosos, se ruega no entrar salvo "
    "ser un aventurero experimentado.\n"
    "\n"
    "Comite para la Seguridad Ciudadana\n");
  AddDetail(({"inscripcion","inscripción"}),
    "Puedes leer <<¡Fuera! ¡No te queremos aquí! ¡Estás en peligro! "
    "¡Márchate o morirás!>>\n");
  AddDetail(({"figura","especie de figura"}),
    "La figura esta más al este.\n");
  AddDetail(({"rata","ratas"}),
    "Hay algunas ratas que huyen de tu presencia.\n");
  AddExit("oeste",CAOSHAB"entrada_01");
  AddExit("este",CAOSHAB"entrada_03");
}
