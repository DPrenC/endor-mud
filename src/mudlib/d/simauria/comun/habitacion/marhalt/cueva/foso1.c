/*******************************************************************
*    Nombre: foso1.c			                           *
*    Localizacion: Cueva de los Trolls                             *
*    Realizada por : Cajun, el ejecutor                            *
*    Creado : 29-11-99                                             *
*    Modificado: 10-12-99 -> Insertar 2 habitaciones para el fondo *
********************************************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");

create () {
    ::create();
    SetLocate("cueva de los trolls");
    SetIntShort("un foso con pinchos");
    SetIntLong("Te encuentras en un agujero con pinchos de piedra, parece a todas "
    "luces una trampa foso, solo vas a poder salir trepando por alguna de las paredes,"
    " afortunadamente no es demasiado profundo y podrás salir sin gran esfuerzo.\n");
    SetIntSmell("Un olor pestilente llega a tus narices.\n");
    AddExit("arriba", "./cueva07");
  AddExit("noroeste","./foso2");
}
