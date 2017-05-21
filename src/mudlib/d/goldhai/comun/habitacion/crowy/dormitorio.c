/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 07-10-98                |
 |               Ultima Modificacion.. 07-10-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("el dormitorio de la torre");
 SetIntLong(
"El suelo de viejas planchas de madera cruje ruidosamente a cada paso. Por "
"él se han tendido montones de paja cubiertos con mantas a modo de camastros "
"donde duermen los guardias de esta torre. El olor del humo de las antorchas "
"ha impregnado fuertemente el lugar. Una escalera asoma en un hueco en el "
"suelo y permite descender a la planta inferior de la torre.\n");

  AddDetail(({"cama","camas","camastros","camastros"}),
"Los guardias han hecho montones con la paja y los han cubiertos con mantas. "
"No es la forma mas confortable de dormir, pero es sin duda mucho mejor que "
"hacerlo sobre el suelo de madera.\n");

 AddDetail(({"hueco"}),
"Permite bajar al piso inferior.\n");

 AddDetail(({"paja"}),
"Con ella se han hecho los camastros.\n");

 AddDetail(({"antorchas","antorcha"}),
"Cuelgan de las paredes para iluminar la habitación.\n");

 AddItem(PNJ("crowy/lonny"),REFRESH_DESTRUCT);
 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(30);
 SetIntNoise("Hay un silencio casi sepulcral.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("abajo",CROWY("torre_guardias"));
 SetLocate("Crowy");
}