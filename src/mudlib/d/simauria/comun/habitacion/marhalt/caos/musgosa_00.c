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

  SetIntShort("la estancia musgosa");
  SetIntLong("Est�s en una gran estancia cuya superficie est� completamente "
    "cubierta de musgo verdoso, un r�o subterr�neo de unos 3 metros de ancho "
    "(por las zonas m�s estrechas) obliga a saltar para acceder a las partes "
    "norte y oeste de la estancia, pero el salto no implica mucha "
    "dificultad.\n");
  SetIntNoise("Escuchas el rumor del agua del r�o subterr�neo que atraviesa "
    "la estancia.\n");
  AddDetail(({"musgo","musgo verdoso"}),
    "Es s�lo musgo verdoso que cubre la totalidad de la estancia gracias a "
    "la humedad.\n");
  AddDetail(({"r�o","r�o subterraneo","agua","r�o","r�o subterraneo"}),
    "El r�o subterr�neo es de aguas limpias y cristalinas que atraviesa por "
    "completo la estancia.\n"
    "Puedes ver muchos peque�os peces de colores nadando aqu� y all� en sus "
    "aguas, sin embargo la corriente del r�o es extraordinariamente fuerte, "
    "y apenas distingues el fondo.\n");
  AddExit("oeste",CAOSHAB"musgosa_01");
  AddExit("norte",CAOSHAB"musgosa_02");
  AddExit("sur",CAOSHAB"cieno_03");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
