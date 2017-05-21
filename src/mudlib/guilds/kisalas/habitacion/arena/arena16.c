/****************************************************************************
Fichero: arena16.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Grandes �rboles se alinean frente a ti, impidi�ndote el avance "
               "hacia el norte. Puedes continuar en la l�nea de la costa si sigues "
               "en direcci�n oeste, o adentrarte m�s en el bosque si vas hacia el sur.\n");


    AddExit("oeste","arena15");
    AddExit("suroeste","arena13");
    AddExit("sur","arena14");

}


