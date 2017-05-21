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

  SetIntShort("la entrada de la caverna");
  SetIntLong("Te encuentras en una habitaci�n aproximadamente circular de "
    "unos 10 metros de di�metro. Las paredes son de color marr�n claro. "
    "El suelo es irregular y est� cubieto de peque�as piedras rojizas. "
    "En la pared hay una inscripci�n y al este una especie de figura bajo "
    "la que corren algunas ratas.\n"
    "La caverna continua al sudeste, y la salida se encuentra al oeste.\n"
    "Ves un gran cartel a tu lado.\n");
  SetIndoors(0);
  SetIntSmell("S�lo hueles el f�tido olor que desprende la basura de la "
    "entrada.\n");
  SetIntNoise("S�lo escuchas el ruido de alguna rata al corretear.\n");
  AddDetail(({"cartel","Cartel","CARTEL","gran cartel"}),
    "En esta caverna viven seres malignos poderosos, se ruega no entrar salvo "
    "ser un aventurero experimentado.\n"
    "\n"
    "Comite para la Seguridad Ciudadana\n");
  AddDetail(({"inscripcion","inscripci�n"}),
    "Puedes leer <<�Fuera! �No te queremos aqu�! �Est�s en peligro! "
    "�M�rchate o morir�s!>>\n");
  AddDetail(({"figura","especie de figura"}),
    "La figura esta m�s al este.\n");
  AddDetail(({"rata","ratas"}),
    "Hay algunas ratas que huyen de tu presencia.\n");
  AddExit("oeste",CAOSHAB"entrada_01");
  AddExit("este",CAOSHAB"entrada_03");
}
