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

  SetIntShort("la forja");
  SetIntLong("Estás en la parte este de una habitación irregular. Sus "
    "paredes y techo son de color marrón oscuro. A tu lado hay una forja, "
    "y al oeste hay un agujero de un metro de diámetro. La estancia esta "
    "repleta de armas y armaduras a medio hacer por el suelo. En las paredes "
    "hay algunos agujeros.\n"
    "En el sur hay lo que parece ser un pico y la pared suroeste parece "
    "haber sido picada para extraer minerales.\n"
    "La salida de la forja esta al Suroeste.\n");
  SetIntSmell("No hueles nada destacable, sólo el olor tipico de las "
    "forjas.\n");
  SetIntNoise("No escuchas nada interesante, salvo el chasquido del fuego "
    "de la forja.\n");
  AddDetail(({"forja"}),
    "La forja esta en perfecto estado y es totalmente operativa, en ella "
    "se puede forjar prácticamente cualquier cosa.\n");
  AddDetail(({"agujero","pozo"}),
    "Está al oeste de la Forja.\n");
  AddDetail(({"arma","armas","escudo","escudos","armadura","armaduras"}),
    "Están a medio hacer, por lo que no merece la pena molestarse en "
    "cogerlas.\n");
  AddDetail(({"pico","pared","pared suroeste"}),
    "Está más al sur.\n");
  AddExit("oeste",CAOSHAB"forja_01");
  AddExit("sur",CAOSHAB"forja_03");
  AddExit("suroeste",CAOSHAB"forja_00");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
