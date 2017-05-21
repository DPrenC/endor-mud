/*****************************************************************************************
 ARCHIVO:       barrotes.c
 AUTOR:         Ztico
 FECHA:         14-05-2005
 DESCRIPCI�N:   Unos barrotes para las ventanas de la posada de Faeria.
 COMENTARIOS:   
*****************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit THING;

create()
{
    if(::create()) return 1;
    	
    SetShort("unos barrotes");
    SetLong("Son unos barrotes de metal. Est�n oxidados.\n");
    SetWeight(4000);
    SetValue(600);
    SetIds(({"barrotes", "rejas"}));
    AddAdjective(({"oxidados"}));
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
}