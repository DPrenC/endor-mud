
/*****************************************************************************************
 ARCHIVO:       hongo.c
 AUTOR:         Ztico
 FECHA:         13-12-2005
 DESCRIPCIÓN:   Hongo rojo y amarillo.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <properties.h>
#include <herbs.h>

inherit HERB;

public string f_efecto();

create()
{
    if(::create()) return 1;
  SetType(HERB_TYPE_HERB);
    SetShort("un hongo");
    SetLong("Es un pequeño hongo de color amarillo y rojo.\n");
    AddId("hongo");
    AddAdjective(({"pequeño", "pequenyo"}));
    SetSmell("Huele a madera podrida.\n");
    SetWeight(100);
SetClass(HERB_CLASS_TOXIC);
    SetPower(50 + random(100));

      SetValue(QueryPowerNumber());

    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
}

public string f_efecto()
{
	  string sClase;

    switch(d3())
    {
        case 1:
        	      sClase = "magico";
        	      break;
        case 2:
        	      sClase = "saciante";
        	      break;
        case 3:
        	      sClase = "curativo";
        	      break;
        default:
        	      sClase = "curativo";
    }
    return sClase;
}
