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

  SetIntShort("el hemisferio");
  SetIntLong("Te encuentras en una cueva con forma hemisférica de seis "
    "metros de diámetro. Las paredes están cuidadosamente pulidas. Las "
    "cuatro estatuas que se encuentran aquí están en perfecto estado "
    "de conservación; las estatuas están esculpidas con el mismo tipo de "
    "roca amarilla que forma las paredes de la estancia, y representan "
    "cuatro mujeres desnudas, prácticamente identicas, en actitud de rezar.\n");
  AddDetail(({"estatuas","estatua"}),
    "Al acercarte a mirar una de las estatuas, te das cuenta que algo "
    "refleja en las mismas desde el techo.\n");
  AddDetail(({"techo"}),
    "Cuando miras al techo ves que en el centro geométrico de la sala "
    "hay un cristal que brilla tenuemente.\n");
  AddDetail(({"cristal"}),
    "Ves un cristal del que emana una suave luz azulada. Notas como de "
    "él emana poder mágico.\n");
  AddExit("oeste",CAOSHAB"banyos_01");
  AddExit("este",CAOSHAB"hemisferio_01");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
