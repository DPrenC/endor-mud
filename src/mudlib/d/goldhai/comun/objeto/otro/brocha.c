/*=============================================================*
 |           << GOLDHAI.Crowy [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 05-10-98                 |
 |              Ultima Modificacion...05-10-98                 |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>

inherit THING;

int pintar(string str);

create() {
 ::create();

 SetShort("una brocha");
 SetLong("\
Es una extranya brocha para pintar. Esta fabricada con los pelos de algun\n\
animal, mientras que la empunyadura es de madera de nogal.\n");
 SetIds(({"brocha","brocha para pintar","brocha de pintura"}));
 SetValue(70);
 SetWeight(300);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
}

init()
{::init();
 add_action("pintar","pintar");
}

int pintar(string str)
{
 if(!str)
  return notify_fail("Que es lo que quieres pintar?\n"),0;

 if(!present("bote de pintura",TP))
  return notify_fail("Quizas debieras comprar un poco de pintura primero.\n"),0;

 return notify_fail("No creo que este sea el sitio adecuado para pintar algo.\n"),0;
}
