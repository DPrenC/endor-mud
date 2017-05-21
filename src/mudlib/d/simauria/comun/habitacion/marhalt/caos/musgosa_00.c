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

  SetIntShort("la estancia musgosa");
  SetIntLong("Estás en una gran estancia cuya superficie está completamente "
    "cubierta de musgo verdoso, un río subterráneo de unos 3 metros de ancho "
    "(por las zonas más estrechas) obliga a saltar para acceder a las partes "
    "norte y oeste de la estancia, pero el salto no implica mucha "
    "dificultad.\n");
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
    "y apenas distingues el fondo.\n");
  AddExit("oeste",CAOSHAB"musgosa_01");
  AddExit("norte",CAOSHAB"musgosa_02");
  AddExit("sur",CAOSHAB"cieno_03");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
