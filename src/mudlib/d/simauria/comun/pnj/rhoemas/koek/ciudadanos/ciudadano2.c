/****************************************************************************
Fichero: ciudadano2.c
Autor: Dharkus
Fecha: 02/06/2010 
Descripción: Otro ciudadano para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    SetStandard("un ciudadano","humano",([GC_TORPE:10+d4()]),GENDER_MALE);
    AddId(({"hombre", "ciudadano"}));
    SetShort("un ciudadano");
    SetLong("Es un hombre de mediana edad, bajito y regordete.\n Tiene una expresión "
    "alegre en el rostro.\n Parece estar esperando a alguien.\n");
    InitChats(3,({"El ciudadano te mira.\n",
      "El hombre comenta:\n '¡Todavía no ha llegado\n Parece que se retrasa!'\n",
      "El ciudadano mira a todos lados.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/pantalones"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/camisa"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
}
