/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 24-04-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

int do_entrar();

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"La calle se estrecha bastante. La gente que quiere ir hacia la parte Norte\n\
o la parte Sur de la ciudad tiene que pasar por aquí. En el Oeste hay una gran\n\
casa a la que quizás algún dia tengas que entrar.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");
 AddDetail("casa",
"Es una casa enorme construida en piedra hace ya algun tiempo. Su fachada es\n\
de color blanco, un blanco limpio como si no hiciera mucho que fue pintado.\n\
Un pórtico de madera incita a entrar aunque no sepas lo que hay al otro lado.\n");
 AddExit("sur",CROWY("calle7"));
 AddExit("norte",CROWY("calle3"));
 AddExit("entrar",SF(do_entrar));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+1);
 AddItem(PNJ("crowy/kguardia_elfo"),REFRESH_DESTRUCT);
}

do_entrar()
{
 return notify_fail("La puerta no se abre, quizas si lo intentases con una llave.\n"),0;
}