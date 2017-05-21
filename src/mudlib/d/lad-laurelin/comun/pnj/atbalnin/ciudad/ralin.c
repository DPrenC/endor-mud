/*
	Ralin el tendero
	Theuzifan, 29-03-99
*/

#include "path.h"
#include <properties.h>
inherit NPC;

varargs int allow_enter(int method, mixed extra)
{
  if (object_name(efun::blueprint(PO))!="/d/lad-laurelin/comun/quest/pluma")
  {
    write("Ralin te dice: No, gracias, no quiero eso...\n");
    return 0;
  }
  return ::allow_enter(method,extra);
}

create()
{
  ::create();

  SetStandard("ralin", "elfo", 7, GENDER_MALE);
  SetShort("Ralin el tendero");
  SetLong(W("Ralin es un apacible herrero. Es una leyenda viva ya que logró "
  	"salir con vida cuando una avanzadilla de una incursión orca le "
  	"capturó hace ya muchísimo tiempo.\n"));

  InitChats(1,({
  	"Ralin se pone a ordenar un poco los artículos.\n",
  	"",
  	"Oyes el clinc-clinc de la habitación contígua.\n",
  	"",
  	"Ralin masculla algo sobre unas plumas...\n"}));

  AddQuestion(({"pluma", "plumas"}),
    W("Ralin te dice: Quizás puedas ayudarme. Estoy buscando regalo muy "
    "especial para mi esposa, pero para eso necesito tres plumas de Wyvelt. "
    "No tengo ni tiempo ni idea de dónde encontrarlas, y estoy seguro que "
    "será peligroso. Si deseas ayudarme, podrías ir a la biblioteca central, "
    "donde seguramente encontrarás algún libro sobre el tema. He oído hablar "
    "además que hay una curandera por la zona de Goldhai. Aparte de curandera "
    "también se comenta que es adivina y que puede encontrar cosas, pero eso si, "
    "su precio es elevado.\n"));

}
