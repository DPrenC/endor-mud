/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 11-05-99                |
 |	         Cajun................ 11-05-01                |
 *=============================================================*/

#include "./path.h"

inherit GROOM;

create()
{
 ::create();
seteuid(getuid());
 SetIntShort("la torre de los guardianes");
 SetIntLong(
"El interior de esta torre es mas bien austero: paredes de piedra, suelo "
"de tierra batida y una escalera al piso superior. Es aquí donde los "
"guardias de la ciudad pasan las horas cuando no estan vigilando la entrada "
"de la ciudad. La vieja mesa y las sillas que la rodean han debido ver "
"no pocas partidas de cartas y borracheras de los guardias.\n");

 AddDetail(({"escalera"}),
"Es una simple escalera de madera. Permite subir al piso superior de la torre.\n");

 AddDetail(({"mesa","mesas","gran mesa"}),
"Esta en el centro de la habitación rodeada de algunas viejas sillas.\n");

 AddDetail(({"silla","sillas"}),
"Son una simples sillas de madera, no pagarias por ellas....\n");

 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("No oyes nada especial.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("arriba",CROWY("dormitorio"));
 AddExit("este",CROWY("entrada1"));

// Esta bien acompañado Kurts.. ¿eh? ;)
 AddItem(PNJ("crowy/kguardia_gigante"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/kguardia_orco"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/kguardia_elfo"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/kguardia_humano"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/kguardia_enano"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/lider_guardias"),REFRESH_DESTRUCT);

 SetLocate("Crowy");
}
