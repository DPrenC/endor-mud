/****************************************************************************
Fichero: ciudadana2.c
Autor: Dharkus
Fecha: 27/05/2010 
Descripci�n: Otra ciudadana para Koek
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
    SetLong("Es una mujer de mediana edad, seguramente un ama de casa que sali� "
    "en busca de alg�n art�culo para su hogar.\n Lleva el pelo recogido en un mo�o, "
    "y una expresi�n alegre y despreocupada.\n");
    InitChats(3,({"La ciudadana te mira.\n",
      "La mujer comenta:\n '�Todav�a me faltan algunas cosas para la casa!'\n",
      "La ciudadana te sonr�e.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/vestido"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
