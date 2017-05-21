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

  SetIntShort("el norte de la estancia musgosa");
  SetIntLong("Estás en la parte norte de una gran estancia completamente "
    "cubierta de musgo verdoso. Un río subterráneo de unos 3 metros de ancho "
    "obliga a saltar para acceder a la parte este, pero el salto no implica "
    "mucha dificultad.\n");
  SetIntNoise("Escuchas el rumor del agua del río subterraneo que atraviesa "
    "la estancia.\n");
  AddDetail(({"musgo","musgo verdoso"}),
    "Es sólo musgo verdoso que cubre la totalidad de la estancia gracias a "
    "la humedad.\n");
  AddDetail(({"río","río subterraneo","agua","río","río subterráneo"}),
    "El río subterraneo es de aguas limpias y cristalinas y atraviesa por "
    "completo la estancia.\n"
    "Puedes ver muchos pequeños peces de colores nadando aquí y allá en las "
    "aguas del río, sin embargo la corriente del río es extraordinariamente "
    "fuerte, y apenas distingues el fondo.\n");
  AddExit("oeste",CAOSHAB"grieta_04");
  AddExit("este",CAOSHAB"musgosa_00");
  AddExit("nordeste",CAOSHAB"musgosa_02");
}
