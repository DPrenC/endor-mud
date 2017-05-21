/*****************************************************************************************
 ARCHIVO:       runa_1.c
 AUTOR:         Ztico
 FECHA:         14-01-2006
 COMENTARIOS:   Runa de Cernunos
 ****************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit THING;

public string pOwner;

public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }
public string QueryRuna() { return "Cernunos"; }

public void create()
{
    ::create();

    SetShort("la Runa de Cernunos");
    SetLong("Se trata de una roca fría y de color pardo. Tiene forma pentagonal, y no es "
        "muy pesada. En el centro tiene grabadas las formas de una cornamenta de "
        "ciervo, el símbolo del dios Cernunos.\n");
    AddId(({"runa", "runa cernunos", "cernunos", "Cernunos", "Runa de Cernunos",
    	      "roca"}));
    Set(P_CANT_STEAL, 1);
    Set(P_NOSELL, 1);
    Set(P_NODROP, 1);

    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
}
