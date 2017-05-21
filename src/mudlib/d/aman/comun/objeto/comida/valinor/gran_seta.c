/*****************************************************************************************
 ARCHIVO:       gran_seta.c
 AUTOR:         Ztico
 FECHA:         22-05-2005
 DESCRIPCIÓN:   Seta enorme. Es propiedad de un Gnomo muy cascarrabias.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit FOOD;

private int pPoseida = 1;

create()
{
    if(::create()) return 1;

    seteuid(getuid());
    SetShort("una seta enorme");
    SetLong("Ves una gran seta porosa, de color rojo cinabrio y anaranjado.\n");
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    AddId(({"seta", "seta enorme", "seta porosa", "gran seta porosa", "gran seta", 
    	      "seta_id"}));
    SetFood(1);
    SetFoodStuff(40);
    SetFoodHeal(10);
    SetWeight(3000);
    SetSmell("Huele a madera vieja.\n");
}
/*
public varargs int move(mixed dest, int method, mixed extra)
{
	  object gnomo;
	  int aux;   
    
    if(aux = ::move(dest, method, extra) != ME_OK) return aux;
    
    if(method == M_GET && !present("dueño_seta", environment()))
    {
        if(pPoseida)
        {
            write("Coges la seta pero de repente aparece un gnomo de detrás de un árbol "
                "que aparenta estar de muy mal humor.\n");
            say(CAP(TNAME) + " coge la seta pero de repente aparece un gnomo de detrás "
                "de un árbol que aparenta estar de muy mal humor.\n");            
            gnomo = clone_object(PNJ_VALMAR("gnomo_seta.c"));
            gnomo->move(ENV(TP));
            pPoseida = 0;
        }
    }
    return aux;
}

public varargs void reset()
{
    pPoseida = 0;
    return;
}
*/