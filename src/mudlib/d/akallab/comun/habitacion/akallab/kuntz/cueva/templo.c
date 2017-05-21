/*
DESCRIPCION  : Templo de la gran caverna troll
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cuevas/templo.c
MODIFICACION : 18-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("el templo de la Gran Caverna troll");
  SetIntLong(
  "Estas en una amplia y silenciosa cueva. En el centro de la misma se "
    "halla una extranya piedra semitranslucida de color rojizo oscuro. Por "
	"alguna extranya razon surge una misteriosa y mortecina luz rojiza del interior "
	"de la roca inundando la cueva. Alrededor de la roca se encuentran todo "
	"tipo de amuletos, piedras talladas y otros objetos de culto depositados "
	"aqui por los troll. Este parece ser un lugar sagrado para ellos. En las "
	"paredes puedes observar algunas pinturas.\n");

  AddDetail(({"piedra"}),
  "La extranya piedra se encuetra en el centro de la cueva. Es bastante "
    "grante y probablemente igual de pesada. A traves de su semitranslucido "
	"color rojizo oscuro, una extranya y mortecina luz emana de su interior.\n");

  AddDetail(({"luz"}),
  "La luz que emana a traves de las paredes de la extranya piedra es de "
    "un color rojizo y parece fluctuar por momentos. Esta mortecina luz "
	"apenas si ilumina el interior de la cueva.\n");

  AddDetail(({"amuletos","piedras","objetos","objetos de culto"}),
  "Son ofrendas de los troll a la piedra o al espiritu que esta represente. "
    "Carecen de mas valor que el de la fe del que aqui los ha depositado.\n");

  AddDetail(({"pinturas","frescos"}),
    "En alguna de las paredes de la cueva se observan pequenyos frescos "
	  "de color ocre. Algunas de estas pinturas parecen representar "
	  "toscamente animales, pero otras muchas no sabrias decir que son. "
	  "Supones que tal vez espiritus a los que esta gente venere o tema.\n");

 SetIntNoise("El silencio impera en este lugar.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(20);

 AddExit("suroeste",K_CUEVA("caverna23"));
 //AddItem(PNJ("k_cueva/guardia"), REFRESH_DESTRUCT);
}
