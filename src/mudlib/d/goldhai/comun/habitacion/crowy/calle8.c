/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-06-97                |
 |               Ultima Modificacion.. 23-09-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"Este lugar de la ciudad rebosa cultura por todos lados. Escritores, autores,\n\
pintores y musicos se reunen en torno a la tienda del viejo Josue, una leyenda\n\
viviente en la ciudad. Un cartel encima de la entrada de su tienda te invita a\n\
entrar, cosa que puedes hacer si vas hacia el Sur. Seria interesante que le\n\
preguntases al viejo Josue sobre su vida, ya verás como te fascina. En el Oeste\n\
puedes escuchar golpes de martillo sobre metal, seguro que es una herreria.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Escuchas a los músicos tocando sus melodias en frente de la tienda de Josue.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"gente","gentes"}),
"Ves de todo. Gente grande, pequeña, con cara de buena fe, con cara de cruel y\n\
malvado, hombres, mujeres, niños.. o sea, de todo.\n");
 AddDetail(({"musico","musicos","músico","músicos"}),
"Una gran variedad de musicos rodea la tienda del viejo Josue. Sus canciones\n\
son alegres y rebosan felicidad, cantan por la cultura en esta extraña ciudad.\n");
 AddDetail(({"escritores","escritor"}),
"Sus estilos son de lo más diversos, hacen de todo incluido versos. Prosas\n\
escuetas, sonetos sinceros, novelas festibas y poesias con sonrisas.\n");
 AddDetail("calle",
"Está hecha de baldosas prominentes y si no vas con cuidado te puedes caer.\n");
 AddDetail("cartel",
"Si en tu mente aún queda un poco de lucidez, no te lo pienses deja que la\n\
cultura te desborde (Josue).\n");
 AddExit("este",CROWY("calle7"));
 AddExit("oeste",CROWY("herreria"));
 AddExit("sur",CROWY("tienda_josue"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+2);

 SetLocate("crowy");
}