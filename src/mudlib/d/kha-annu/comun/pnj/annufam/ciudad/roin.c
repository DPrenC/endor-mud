/****************************************************************************
Fichero: roin.c
Autor: Kastwey
Creación: 01/08/2005
Descripción: Roin, el posadero de Annufam
****************************************************************************/

#include "./path.h"
#include <properties.h>


inherit NPC;

public void create()
{
    ::create();
    SetStandard("Roin","enano",12,GENDER_MALE);
    SetShort("Roin, el posadero");
    SetLong(W("Es el posadero de la ciudad. un enano ya entrado en años, con "
              "una espesa barba pelirroja y con las manos llenas de "
              "callos.\n"));
    AddId("posadero");
}



public varargs void Die(int silent)
{
    if (object_name(environment()) == HAB_POSADA_ANNUFAM("entrada_posada"))
    {
        environment()->SetEmpleado(0); // el empleado ha sido asesinado
    }
    ::Die(silent);
}
