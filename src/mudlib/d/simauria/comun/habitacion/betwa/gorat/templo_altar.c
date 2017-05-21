// 03-06-08 [Angor] Rehecha

#include "./path.h"
inherit GORAT("room_base.c");

create () {
  ::create();
  replace_program();
  SetIntShort("el templo de la diosa Valevissa");
  SetIntLong(
"Al fondo de éste templo se halla el altar de la diosa humana del mar, "
"Valevissa. El altar está tallado en un bloque de piedra caliza y en él "
"apenas si se pueden leer unas viejas runas grabadas hace mucho tiempo. "
"Una lámina de cristal de roca translucido en el pequeño ventanuco que "
"ves el en techo derrama algo de luz lechosa sobre el altar. Hay trozos "
"de vidrio rotos por el suelo.\n");

AddDetail(({"ventanuco", "lamina", "lamina de cristal"}),
"El ventanuco que hay en el techo es de forma circular y no parece que "
"pueda abrirse. Encastrada en él hay una lamina de cristal de roca " 
"translucida. Durante el día tamiza la luz del sol e ilumina el interior "
"de este templo.\n");

AddDetail(({"trozos de vidrio", "trozos", "vidrio"}),
"Supones que los trozos de vidrio son los restos de lo que en su día "
"debió ser el santo cáliz de la diosa. Parece que algún vándalo lo rompió "
"o lo arrancó del altar siendo los trozos lo único que queda.\n");

AddDetail(({"runas","viejas runas"}),
"Están talladas en la piedra del altar y por como están de desgastadas, "
"dirías que llevan allí mucho tiempo. No comprendes lo que dicen y supones "
"que deben ser alguna lengua antigua largo tiempo olvidada.\n");

AddDetail(({"altar"}),
"Es un bloque de roca caliza, probablemente de la zona y tallado por los "
"pescadores en agradecimiento a la diosa que en no pocas ocasiones les ha "
"salvado del cruel amante que es el mar. Representa un barco y en su proa, "
"la imagen de la diosa Valevissa, triste y mirando al horizonte con sus "
"ropajes y largos cabellos ondeando al viento.\n");

AddDetail(({"imagen","diosa","valevissa","Valevissa"}),
"La imagen de la diosa Valevissa está tallada en el altar de pie sobre la "
"proa de un barco. El semblante de la diosa es triste pues sabe que ha "
"de dejar marchar a los marineros a tierra en vez de permanecer con ella "
"por toda la eternidad. Valevissa esta representada como mujer humana de "
"ojos azul mar y largos cabellos rubios que ondean con el viento.\n");

AddItem(GORPNJ("sacerdotisa"));
//AddItem(GORPNJ("mujer"));

//AddExit("sur","../calles/callep4"); //al puerto, claro.
AddExit("sur", GORAT("templo_entrada") );

SetIndoors(1);
SetIntBright(30);

}