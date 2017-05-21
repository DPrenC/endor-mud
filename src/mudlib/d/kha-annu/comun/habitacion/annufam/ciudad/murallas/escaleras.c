/****************************************************************************
Fichero: escalera.c
Autor: Riberales
		[t] Tagoras
Creación: 6/10/2005
Descripción: Torre a las murallas.
[t] 05/01/2012 Areglo algún type de la descripción.
****************************************************************************/

#include "./path.h"
#include <moving.h>

inherit HAB_MURALLAS_ANNUFAM("escalera_base");

int subir()
{
    write("Comienzas a subir las escaleras.\n");
    say(CAP(TP->QueryName()) + " se va subiendo las escaleras.\n");
    TP->move(HAB_MURALLAS_ANNUFAM("ab_a_descansillo"),M_SILENT,"arriba");
    return 1;
}

public void create()
{
    ::create();
    SetIntShort("la torre hacia las murallas");
    SetIntLong("Te encuentras en la planta baja de la torre que comunica la "
               "ciudad con las murallas. En la pared oeste observas un "
               "emblema, y al sur las escaleras que suben.\n");
    AddExit("este",HAB_AVENIDA_ANNUFAM("avenida_01"));
    AddExit("arriba",SF(subir));
}
