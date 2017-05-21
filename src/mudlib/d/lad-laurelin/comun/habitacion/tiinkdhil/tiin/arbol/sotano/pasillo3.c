/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : [Ch] Chantiel.
MODIFICACION :
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("");
SetIntLong(
"El techo lo componen dos gruesas raices que se bifurcan y luego vuelven a\n"
"unirse en la esquina. Es una estancia pequenya. Al sur sigue el pasillo y\n"
"si quieres ir tendras que tener cuidado de no golpearte la cabeza con la\n"
"raiz. Al norte y al este hay celdas. Al oeste el pasillo continua.\n"
);

/*******
[Ch] tendria que haber alguna referencia a la raiz
************/
AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntNoise("");
SetIntSmell("");
SetLocate("");
SetIndoors(1);

AddExit("norte",TASOTANO("celda3"));
AddExit("sur",TASOTANO("pasillo5"));
AddExit("este",TASOTANO("celda5"));
AddExit("oeste",TASOTANO("pasillo2"));

}

/***********************
 [Ch] hay que poner un acction que se llame "sur" y que quite vida por no
 "agacharte" y darte con la gran raiz
***********************/
