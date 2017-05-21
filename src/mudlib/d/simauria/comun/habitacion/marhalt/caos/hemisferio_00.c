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

  SetIntShort("el hemisferio");
  SetIntLong("Te encuentras en una cueva con forma hemisf�rica de seis "
    "metros de di�metro. Las paredes est�n cuidadosamente pulidas. Las "
    "cuatro estatuas que se encuentran aqu� est�n en perfecto estado "
    "de conservaci�n; las estatuas est�n esculpidas con el mismo tipo de "
    "roca amarilla que forma las paredes de la estancia, y representan "
    "cuatro mujeres desnudas, pr�cticamente identicas, en actitud de rezar.\n");
  AddDetail(({"estatuas","estatua"}),
    "Al acercarte a mirar una de las estatuas, te das cuenta que algo "
    "refleja en las mismas desde el techo.\n");
  AddDetail(({"techo"}),
    "Cuando miras al techo ves que en el centro geom�trico de la sala "
    "hay un cristal que brilla tenuemente.\n");
  AddDetail(({"cristal"}),
    "Ves un cristal del que emana una suave luz azulada. Notas como de "
    "�l emana poder m�gico.\n");
  AddExit("oeste",CAOSHAB"banyos_01");
  AddExit("este",CAOSHAB"hemisferio_01");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
