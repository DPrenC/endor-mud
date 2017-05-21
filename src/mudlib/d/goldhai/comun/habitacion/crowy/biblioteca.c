/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 21-10-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <moving.h>
inherit "/room/bibl_room";
inherit GROOM;

NoHay()
{
    write("Abres el libro y al leerlo un frio intenso empieza a recorrer tu cuerpo.\n");
    return 1;
}

create()
{
 ::create();
 SetIntShort("la biblioteca");
 SetIntLong("\
Te encuentras dentro de la biblioteca de Crowy. La verdad es que el polvo\n\
abunda bastante en este lugar, quizás no sea el sitio más visitado del lugar.\n");
 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(45);
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("norte",CROWY("zona_comercial2"));

 SetTema("Historias y leyendas");
 AddBook("Nieves","Terror en las nieves",SF(NoHay));
 AddBook("Sueño","País del sueño",TEXTOS+"pais.bib");
 AddBook("Infierno","El infierno nos influye",SF(NoHay));
 AddBook("Reino","Obras e Historia en el Reino de Simauria",TEXTOS+"historia_guennir");
 SetLocate("Crowy");
}

