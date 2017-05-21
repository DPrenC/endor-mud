/**************************************************************************
fichero: Bleni.c
Autor: Riberales
Creación: 03/10/2005
Descripción: La hija del maestro herrero, en la plaza.
**************************************************************************/

#include "path.h"
#include <properties.h>


inherit NPC;
string pregunta();

public void create()
{
    ::create();
    SetStandard("Bleni","enano",16,GENDER_FEMALE);
    SetLong(W("Bleni es una enana relativamente joven, morena y bastante "
              "delgada en relación a su raza. Es la hija del herrero, y "
              "parece que se va a convertir en la soltera de oro, pues todos "
              "los enanos respetan a su padre.\n"));
    SetIds(({"bleni_annufam","bleni","amiga_posadera"}));


    InitChats(3,({W("Bleni murmura: Buf, ahí tanto músculo junto y sudoroso, "
                "y yo condenada a la eterna virginidad.\n"),"Bleni suspira.\n"
               ,SF(pregunta)}));
}






string pregunta()
{
    object posadera;
    if ((posadera = present("posadera_annufam")) && living(posadera))
    {
        return W("Bleni le pregunta a la posadera: ¿Sabes algo más de la "
                "pareja de tu posada?\n");
    }
    return "";
}
