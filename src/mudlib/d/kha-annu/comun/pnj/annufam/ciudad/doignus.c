/**************************************************************************
Fichero: Doignus.c
Autor: Riberales
Creación: 27-09-05
Descripción: El tabernero del ojo de orco.
***************************************************************************/

#include <properties.h>
inherit NPC;
public void create()
{
    ::create();
    SetStandard("doignus","enano",12,GENDER_MALE);
    AddId(({"Doignus","tabernero"}));
    SetShort("Doignus el tabernero");
    SetLong(W("Se trata del tabernero de Ojo de Orco. Siempre lo ves de aquí "
               "para allá limpiando el suelo y recogiendo las sobras de las "
               "mesas. No estás seguro de si interrumpirlo sería una buena "
               "idea.\n"));

    InitChats(3,({W("Doignus canturrea: Con mi sopa y mi cerveza, no se resiste "
                    "ningún intestino, ni garganta ni cabeza.\n"),
                  W("El tabernero silba una melodía mientras limpia las "
                    "mesas.\n"),
                  W("Doignus te sonríe mientras te pregunta: ¿Deseas "
                    "algo?\n")}));
}
