/****************************************************************************
Fichero: ciudadana2.c
Autor: Dharkus
Fecha: 27/05/2010 
Descripción: Otra ciudadana para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    SetStandard("una ciudadana","humano",([GC_TORPE:10+d2()]),GENDER_FEMALE);
    SetIds(({"mujer", "ciudadana", "humana"}));
    SetShort("una ciudadana");
    SetLong("Es una mujer de mediana edad, seguramente un ama de casa que salió "
    "en busca de algún artículo para su hogar.\n Lleva el pelo recogido en un moño, "
    "y una expresión alegre y despreocupada.\n");
    InitChats(3,({"La ciudadana te mira.\n",
      "La mujer comenta:\n '¡Todavía me faltan algunas cosas para la casa!'\n",
      "La ciudadana te sonríe.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/vestido"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
