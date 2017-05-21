/****************************************************************************
Fichero: ardilla.c
Autor: Kastwey
Fecha: 01/03/2006
Descripción: Una ardilla para la arena de las Kisalas
****************************************************************************/


#include <properties.h>
#include <gremios.h>
#include "./path.h"

inherit ANIMAL_BASE;


create()
{
   ::create();
   SetStandard("una ardilla","ardilla",([ GC_TORPE: 2]),GENDER_FEMALE);
   SetShort("una ardilla");
   SetLong("Es una simpática y temerosa ardilla. Su pelaje es de un color ocre "
           "claro con estrías pardas. Es un animalillo nervioso que no para de "
           "mirar continuamente a todos lados como si presintiera algún peligro.\n");
   SetIds(({"ardilla","bicho"}));
   AddAdjective(({"simpatica", "simpática", "temerosa"}));
   SetSize(P_SIZE_SMALL);
   SetGoChance(50);
    SetNoGet("La ardilla pega un brinco y se aleja de ti.\n");
   InitChats(3,({"La ardilla mira nerviosa a todos lados.\n",
                 "La ardilla coge una bellota y la guarda en sus carrillos.\n",
                  "La ardilla va de aquí para allá.\n",
                 "La ardilla te mira curiosa.\n"}));
}
