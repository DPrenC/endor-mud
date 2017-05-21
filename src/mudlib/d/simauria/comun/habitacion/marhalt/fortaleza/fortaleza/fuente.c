/*
DESCRIPCION  : plaza con fuente
FICHERO      : fuente.c
MODIFICACION : 14-07-00 [Maler] Creacion
04/05/2007. [Y] (Yalin): suprimo funci�n haz_beber, e incluyo fuente seg�n
    el nuevo standard.
*/

#include "./path.h"
#include <sounds.h>
inherit ROOMFF("fortalez");

create () {
  ::create();

  SetIntShort("una plaza");
  SetIntLong(W("Est�s en una inmensa plazoleta central, dentro del castillo. "
  "Al no haberse cuidado, la vegetaci�n que antes adornaba este lugar ha crecido "
  "descontrolada, dificultando el paso e invadiendo el camino. En el centro hay una "
  "gran fuente.\n"));
  AddExit("norte",ROOMFF("plaza04"));
  AddExit("sur",ROOMFF("plaza01"));
  AddExit("este",ROOMFF("plaza03"));
  AddExit("oeste",ROOMFF("plaza02"));
  AddItem(OTRO("marhalt/fortaleza/fuente"));
  AnyadirPnjs();
AddDetail("vegetacion","La espesa vegetacion colapsa esta zona.\n");
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}
