/*
DESCRIPCION  : Puerto en el lago Darum
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/puerto.c
MODIFICACION :
21-02-99 [Angor] Creacion.
21-02-99 [Angor] Retoques
*/

#include "path.h"
#include AK_MACRO
#include <moving.h>

inherit ROOM;

int ir_lago(){
  write("Te lanzas al agua del lago. Esta bastante fria...\n");
  say(NOMBRE+" se tira al fria agua del lago Darum.\n",TP);
  tell_room(GADDARO("lago"),NOMBRE+" llega nadando desde el muelle del puerto.\n");
  TP->move(GADDARO("lago"),M_SILENT);
  return 1;
}

create() {
  ::create();
  SetIntShort("el puerto en el lago Darum");
  SetIntLong(
  "Estás sobre el muelle de madera que el pueblo de Gaddaro tiene en el lago Darum. "
  "El muelle es una plataforma de madera apoyada sobre pilares que se adentra en el "
  "lago y a la cual se amarran las barcas de los pescadores.\n");

  AddDetail(({"muelle","puerto"}),QueryIntLong());

  AddDetail(({"barca","barcas"}),
  "Amarradas al muelle del puerto hay varias viejas barcas de pesca. Estan "
    "hechas de madera y son de pequenyo tamaño, de forma que apenas si cabe "
    "en ellas el pescador y los aparejos de pesca.\n");

#include "geografia.ic"
#include "ambiente.ic"

  SetIntNoise("Oyes a las olas chocar suavemente contra el muelle.\n");
  SetIntSmell("Huele a humedad.\n");

  AddExit("este",GADDARO("calle00"));
  //AddExit("barca",SF(enbarcar));
  AddExit("noroeste",SF(ir_lago));
}

