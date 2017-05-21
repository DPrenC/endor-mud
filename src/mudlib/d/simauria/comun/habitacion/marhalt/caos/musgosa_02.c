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
    "cubierta de musgo verdoso, un río subterráneo de unos 3 metros de ancho "
    "obliga a saltar para acceder a la parte sur, pero el salto no implica "
    "mucha dificultad.\n");
  SetIntNoise("Escuchas el rumor del agua del río subterráneo que atraviesa "
    "la estancia.\n");
  AddDetail(({"musgo","musgo verdoso"}),
    "Es sólo musgo verdoso que cubre la totalidad de la estancia gracias a "
    "la humedad.\n");
  AddDetail(({"río","río subterraneo","agua","río","río subterraneo"}),
    "El río subterráneo es de aguas limpias y cristalinas que atraviesa por "
    "completo la estancia.\n"
    "Puedes ver muchos pequeños peces de colores nadando aquí y allá en sus "
    "aguas, sin embargo la corriente del río es extraordinariamente fuerte, "
    "y apenas distingues el fondo del río.\n");
  AddExit("sur",CAOSHAB"musgosa_00");
  AddExit("oeste",CAOSHAB"pozo_oes_00");
  AddExit("suroeste",CAOSHAB"musgosa_01");
}
