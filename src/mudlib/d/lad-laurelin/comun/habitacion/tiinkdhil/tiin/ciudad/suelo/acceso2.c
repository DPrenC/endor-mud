/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION : sandalin
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("la calle El Viajero");
  SetIntLong(
"Al norte ves como se abre ante ti un verdadero bosque, frondoso y hermoso.\n"
"Sientes que hay vida en el. Miras hacia arriba y ves enormes ramas que se\n"
"entrelazan unas con otras en las alturas.\n"
"Tratas de alcanzar su final con tu vista pero finalmente desistes. Ves\n"
"elaborados puentes que unen arbol con arbol. Ves lianas y elevadores que te\n""permitiran ir ascendiendo por el arbol. Estas maravillado. Miras al suelo\n"
"para recapacitar sobre lo que estas viendo y reparas en que a tus pies\n"
"da comienzo una sendero flanqueado por maleza.Vuelves la vista, y, al sur\n"
"observas un cruze que enlaza con dos robustos arboles. Agudizas tu vista y\n""ves un hueco en cada uno de ellos. Notas como tu curiosidad se despierta...\n");

AddDetail (({"elevador","elevadores","liana","lianas"}),
"Consta de una silla sujeta por cuerdas en las que hay un sistema de poleas\n"
" circulares que posibilitan el ascceso a las viviendas superiores.\n ");

SetIntNoise(
"Oyes a los chiquillos gritar y reir mientras juegan.Sus madres los llaman a\n"
"viva voz. Es la hora de comer.\n ");
SetIntSmell("");
SetLocate("Tiink");
SetIndoors (0); /* 0 exterior; 1 interior */

AddExit("norte",TCSUELO("fanan4"));
AddExit("sur",TCSUELO("salida4"));
}
