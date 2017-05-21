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
  SetLong(W("Ralin es un apacible herrero. Es una leyenda viva ya que logr� "
  	"salir con vida cuando una avanzadilla de una incursi�n orca le "
  	"captur� hace ya much�simo tiempo.\n"));

  InitChats(1,({
  	"Ralin se pone a ordenar un poco los art�culos.\n",
  	"",
  	"Oyes el clinc-clinc de la habitaci�n cont�gua.\n",
  	"",
  	"Ralin masculla algo sobre unas plumas...\n"}));

  AddQuestion(({"pluma", "plumas"}),
    W("Ralin te dice: Quiz�s puedas ayudarme. Estoy buscando regalo muy "
    "especial para mi esposa, pero para eso necesito tres plumas de Wyvelt. "
    "No tengo ni tiempo ni idea de d�nde encontrarlas, y estoy seguro que "
    "ser� peligroso. Si deseas ayudarme, podr�as ir a la biblioteca central, "
    "donde seguramente encontrar�s alg�n libro sobre el tema. He o�do hablar "
    "adem�s que hay una curandera por la zona de Goldhai. Aparte de curandera "
    "tambi�n se comenta que es adivina y que puede encontrar cosas, pero eso si, "
    "su precio es elevado.\n"));

}
