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

  SetIntShort("el lago interior");
  SetIntLong("Te encuentras pr�cticamente dentro del lago, el agua es "
    "cristalina. En el agua ves un extra�o reflejo. En el suelo hay algunas "
    "conchas de caracol m�s.\n"
    "Al norte esta la entrada a esta c�mara, y al oeste se encuentra un "
    "puente.\n");
  AddDetail(({"reflejo", "extra�o reflejo", "lago", "agua", "agua cristalina",
    "extranyo reflejo"}),
    "Cuando miras el extra�o reflejo te percatas de la existencia de un "
    "pliegue rocoso que sugiere la existencia de una abertura vertical que "
    "conduce al este. Tambi�n observas una extra�a mancha negra en el fondo "
    "del lago.\n");
  AddDetail(({"mancha","mancha negra","fondo","fondo del lago"}),
    "Al fijarte m�s detenidamente descubres que la mancha oscura no es sino "
    "un t�nel subacu�tico en el lago.\n");
  AddExit("norte",CAOSHAB"lago_00");
  AddExit("nordeste",CAOSHAB"lago_01");
  AddExit("oeste",CAOSHAB"lago_04");
  AddExit("este",CAOSHAB"grieta_00");
  HideExit("este",1);
  AddExit("abajo",CAOSHAB"tunel_sub_00");
  HideExit("abajo",1);
  AddItem(CAOSPNJ"tortuga",REFRESH_DESTRUCT);
}
