/*
DESCRIPCION  : Faro del puerto
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/faro.c
MODIFICACION : 16-09-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

public create(){
  ::create();
  SetIntShort("el faro del puerto");
  SetIntLong(
"Te encuentras junto al faro del puerto. El faro es un cilindro de piedra de "
"un par de metros de diametro y otros tantos de alto. En su interior se hace una "
"fogata cuya luz, que atraviesa la gran abertura de la pared, guia a las barcas "
"de pesca por la noche. El faro está cubierto para evitar la lluvia y siempre hay "
"un farero cuya función es la de mentener el fuego toda la noche. Un estrecho "
"sendero desciende entre las rocas hasta el puerto que queda al nordeste.\n");

AddDetail(({"faro"}), QueryIntLong());

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan para poder "
"así vivir en este mundo.\n");

SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
SetIntSmell("Hmm.. huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);


AddExit("nordeste",LIMBO("calle04"));
AddItem(PNJ("farero"), REFRESH_DESTRUCT);
}