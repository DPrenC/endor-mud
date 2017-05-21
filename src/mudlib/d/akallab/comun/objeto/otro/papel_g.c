/********************
Fichero: /d/akallab/comun/objeto/otro/papel_g.c
Autor: lug y Yalin.
Descripción: poción del curandero para Gadline.
Fecha: 23/09/2007 1:18:22.
********************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit THING;
string pOwner;
public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }

create()
{
    ::create();
    SetShort("un trozo de papel");
    SetLong("Es un trozo de papel mal recortado, donde se han escrito unos símbolos que "
        "eres incapaz de comprender.\n");
    AddId(({"papel","trozo de papel","papel_gadline"}));
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL, 1);
    Set(P_NODROP,1);
    Set(P_NOBUY,1);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(10);
    SetReadMsg("No eres capaz de descifrar estos signos. Jamás los habías visto antes.\n");
}

public varargs int move(mixed dest, int method, mixed extra)
{
    if (method == M_GIVE && !dest->QueryKoubba()) return ME_NO_GIVE;
	  if (method == M_GET && QueryOwner() != TP->QueryRealName())
	  {
	      write("Eso no es tuyo, déjalo donde está.\n");
	      return ME_NO_GET;
	  }
	  return ::move(dest, method, extra);
}
    