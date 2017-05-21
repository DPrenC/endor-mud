/****************************************************************************
Fichero: arena16.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Grandes árboles se alinean frente a ti, impidiéndote el avance "
               "hacia el norte. Puedes continuar en la línea de la costa si sigues "
               "en dirección oeste, o adentrarte más en el bosque si vas hacia el sur.\n");


    AddExit("oeste","arena15");
    AddExit("suroeste","arena13");
    AddExit("sur","arena14");

}


