/**************************************************************************
Fichero: Doignus.c
Autor: Riberales
Creaci�n: 27-09-05
Descripci�n: El tabernero del ojo de orco.
***************************************************************************/

#include <properties.h>
inherit NPC;
public void create()
{
    ::create();
    SetStandard("doignus","enano",12,GENDER_MALE);
    AddId(({"Doignus","tabernero"}));
    SetShort("Doignus el tabernero");
    SetLong(W("Se trata del tabernero de Ojo de Orco. Siempre lo ves de aqu� "
               "para all� limpiando el suelo y recogiendo las sobras de las "
               "mesas. No est�s seguro de si interrumpirlo ser�a una buena "
               "idea.\n"));

    InitChats(3,({W("Doignus canturrea: Con mi sopa y mi cerveza, no se resiste "
                    "ning�n intestino, ni garganta ni cabeza.\n"),
                  W("El tabernero silba una melod�a mientras limpia las "
                    "mesas.\n"),
                  W("Doignus te sonr�e mientras te pregunta: �Deseas "
                    "algo?\n")}));
}
