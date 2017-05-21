/********************
Fichero: /d/simauria/comun/objeto/otro/marhalt/nandor/carta_betky.c
descripción: carta para la mujer de la limpieza, de su hermano, necesaria para obtener el "
    pergamino de lanza de ácido.
Autor: Lug y Yalin.
Fecha: 28/09/2007 21:31:20.
********************/
#include "path.h"
#include <properties.h>
#include <moving.h>
inherit THING;
string pOwner;
public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }

create()
{
    ::create();
    SetShort("una carta");
    SetLong("Es una carta, una hoja de papel sellada. ¿Qué esperabas?\n");
    AddId(({"carta","papel","hoja de papel","carta_betky"}));
    Set(P_CANT_STEAL,1);
    Set(P_NODROP,1);
    Set(P_NOBUY,1);
    Set(P_NOSELL,1);
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(10);
    SetReadMsg("Entre primos, parientes y hermanos, que nadie meta las manos... No seas "
        "cotilla.\n");
}

public varargs int move(mixed dest, int method, mixed extra)
{
    if (method == M_GIVE && !dest->QueryBetky()) return ME_NO_GIVE;
	  if (method == M_GET && QueryOwner() != TP->QueryRealName())
	  {
	      write("Eso no es tuyo, déjalo donde está.\n");
	      return ME_NO_GET;
	  }
	  return ::move(dest, method, extra);
}
    