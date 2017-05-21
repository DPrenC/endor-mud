/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS        : [Ch] Chantiel.
MODIFICACION : [Ch] 10-11-97 justificacion del texto.
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("un calabozo del Arbol de la Vida");
SetIntLong(
"Es una celda de tamanyo normal, ni grande ni pequenya. La pared lateral y\n"
"parte del techo estan formados por un trozo de la raiz del arbol. No hay\n" "muebles, solo una manta raida y deshilachada tirada en el suelo. Todo esta\n"
"muy sucio y descuidado, lleno de telaranyas por los rincones y pequenyas\n"
"marcas en las paredes que parecen estar hechas por los dientes de alguna\n"
"clase de roedor. Al sur se encuentra la unica salida de la estancia.\n"
);

AddDetail(({"manta"}),
"Ves una manta de tejido basto y aspero, esta muy sucia y es de color marron\n"
"oscuro, aunque no puedes determinar su color verdadero debido a la antiguedad\n"
"de la misma, a la suciedad y a su mal estado.\n"
);

SetIntBright(10);
SetIntNoise(
"En la lejania te parece oir el ruido de pasos muy regulares, como alguien dando\n"
"paseos continuos.\n"
);

/****************************************************************************

[Ch] Ya esta la funcion foler definida.

SetIntSmell(
"El polvillo que hay en la atmosfera se te mete en la nariz y te hace estornudar.\n"
);

****************************************************************************/

SetLocate("");
SetIndoors(1);

AddExit("sur",TASOTANO("pasillo2"));

}
void init(){
::init();
add_action("foler","oler");
}
int foler(string entrada){
if(!entrada){
write(
"El polvillo que reina en la estancia se te mete en la nariz y te hace estornudar\n"
"AAAAATTTTTCCCHISSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS.\n"
);
say(
TP->QueryName()+"huele el ambiente\n"
"de repente"+TP->QueryName()+"empieza a estornudar como un desesperado.\n"
);
return 1;
}
}