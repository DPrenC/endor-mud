/****************************************************************************
Fichero: templo.c
Autor: Riberales
Fecha: 15/02/2006
Descripción: El templo de las Kisalas, remodelado.
****************************************************************************/


#include "path.h"

inherit INTERIOR_BASE;

create()
{
    ::create();
    SetIntShort("el templo del Gremio de las Kisalas");
    SetIntLong("Te encuentras en el Templo de las Kisalas. Es una estancia "
                 "muy grande y de forma hexagonal. "
                 "Hay un altar en uno de sus extremos, en el que puedes "
                 "observar una mesa dedicada a los sacrificios. "
                 "Puedes ver numerosos relieves tallados en las paredes, y "
                 "espirales fosforescentes alumbrando el Templo. En el suelo "
                 "hay un sello con el símbolo de las Kisalas. La única "
                 "salida está al sur y conduce al salón de reuniones.\n");



    AddDetail(({"mesa","altar"}),
                "Es un altar de mármol y una pequeña pero decorada mesa, "
                "donde se efectúan los rituales de las Kisalas.\n");



    SetIntNoise("Escuchas unos extraños cánticos que dicen lo siguiente:\n"//
                  "	Él está llenando mi vacio y soledad\n"                 //
                  "	es mi fuerza y mi astucia\n"                           //
                  "	mi ayuda en mis pasos cansados\n"                      //
                  "	mi alegría y mi consuelo\n"                            //
                  "	el único hombre al que amo.\n");

    /*de Avengelyne a Chantiel, para aclarar posibles dudas ;) */


    AddExit("sur",AM_ROOM("gremio"));
}
