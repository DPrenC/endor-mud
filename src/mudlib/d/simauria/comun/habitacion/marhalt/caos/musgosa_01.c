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

  SetIntShort("el norte de la estancia musgosa");
  SetIntLong("Est�s en la parte norte de una gran estancia completamente "
    "cubierta de musgo verdoso. Un r�o subterr�neo de unos 3 metros de ancho "
    "obliga a saltar para acceder a la parte este, pero el salto no implica "
    "mucha dificultad.\n");
  SetIntNoise("Escuchas el rumor del agua del r�o subterraneo que atraviesa "
    "la estancia.\n");
  AddDetail(({"musgo","musgo verdoso"}),
    "Es s�lo musgo verdoso que cubre la totalidad de la estancia gracias a "
    "la humedad.\n");
  AddDetail(({"r�o","r�o subterraneo","agua","r�o","r�o subterr�neo"}),
    "El r�o subterraneo es de aguas limpias y cristalinas y atraviesa por "
    "completo la estancia.\n"
    "Puedes ver muchos peque�os peces de colores nadando aqu� y all� en las "
    "aguas del r�o, sin embargo la corriente del r�o es extraordinariamente "
    "fuerte, y apenas distingues el fondo.\n");
  AddExit("oeste",CAOSHAB"grieta_04");
  AddExit("este",CAOSHAB"musgosa_00");
  AddExit("nordeste",CAOSHAB"musgosa_02");
}
