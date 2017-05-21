/****************************************************************************
Fichero: llave_maestra_posada.c
Autor: Kastwey
Creación: 19/08/2005
Descripción: llave maestra de las habitaciones de Annufam
****************************************************************************/

#include "./path.h"
#include <ansi.h>



inherit THING;

public void create()
{
    ::create();
    SetShort("una llave maestra");
    SetLong(W("Se trata de una gran llave plateada. Sujeto por una corta "
              "cadenita, puedes ver un llavero en el que aparece la "
              "siguiente inscripción:\n\n" + ANSI_BLUE + "APERTURA DE TODAS "
              "LAS HABITACIONES DE LA POSADA" + ANSI_NORMAL + "\n\n"));
    AddId(({"llave","llave plateada","llave_maestra_posada_annufam"}));
    SetValue(0);
    SetWeight(85);
}

