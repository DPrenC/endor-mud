/*
DESCRIPCION : destileria del pueblo de Narad
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/narad/destil01.c
MODIFICACION: 17-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include AK_MACRO
inherit ROOM;

create(){
  ::create();
 SetIntShort("la destilería del pueblo de Narad");
  SetIntLong(
  "En esta parte de la destileria es donde se fabrica la bebida. A tu alrededor "
    "puedes observar montones de maquinas y utensilios que se emplean en el "
    "proceso, desde prensas para la uva hasta alambiques donde destilar el "
    "alcohol. La entrada a la destileria se encuentra al este de aqui.\n");

  AddDetail(({"maquinas","utensilios"}),QueryIntLong());

  AddDetail(({"prensa","prensas"}),
  "Las prensas para la uva son una especie de inmensos cilindros de madera. "
    "Las uvas se echan en su interior donde se pisa para asi extraerle el zumo "
    "que se filtra por una serie de agujeros en su parte inferior y se conduce "
    "hasta otro recipiente.\n");

  AddDetail(({"alambique"}),"");

  SetIntNoise("Oyes el ruido del alambique operando.\n");
  SetIntSmell("Huele a vino y cerveza... Podrias vivir aqui.\n");
  SetLocate("villa de Narad");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("este",NARAD("destil00"));
}

