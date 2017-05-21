/********************
Fichero: /d/akallab/comun/objeto/otro/pocion_g.c
Autor: lug y Yalin.
Descripción: poción del curandero para Gadline.
Fecha: 23/09/2007 11:50:48.
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
    SetShort("una extraña poción");
    SetLong("Ves un tubito de fino cristal, cerrado por ambos extremos, lleno de un extraño "
        "líquido de un color morado intenso. No tienes ni idea de sus efectos, pero te han "
        "dicho que es lo que se necesita, y por el momento, con eso te basta.\n");
    AddId(({"vial","tubito","pocion","poción","extraña poción","extraña pocion","pocion_gadline"}));
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL, 1);
    Set(P_NODROP,1);
    Set(P_NOBUY,1);
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(40);
}

public varargs int move(mixed dest, int method, mixed extra)
{
    if (method == M_GIVE && !dest->QueryGadline()) return ME_NO_GIVE;
	  if (method == M_GET && QueryOwner() != TP->QueryRealName())
	  {
	      write("Eso no es tuyo, déjalo donde está.\n");
	      return ME_NO_GET;
	  }
	  return ::move(dest, method, extra);
}
    