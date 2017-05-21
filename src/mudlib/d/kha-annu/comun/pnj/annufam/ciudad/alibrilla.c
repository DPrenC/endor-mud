/**************************************************************************
fichero: alibrilla.c
Autor: kastwey
Creaci�n:20/07/2005
Descripci�n: Alibrilla, una tendera
**************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

public void create()
{
    ::create();
    SetStandard("Alibrilla","enano",10,GENDER_FEMALE);
    AddId(({"tendera","tendera_alibrilla","Alibrilla"}));
    SetLong("Es una vieja enana que conserva esta tienda como puede. "
            "La ves con el pelo recogido en un mo�o, y bastante "
            "desarreglada. Aun as�, parece buena gente.\n");
}

