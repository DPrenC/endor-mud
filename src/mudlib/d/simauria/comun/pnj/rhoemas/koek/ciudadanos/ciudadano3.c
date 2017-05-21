/****************************************************************************
Fichero: ciudadano3.c
Autor: Dharkus
Fecha: 06/06/2010
Descripci�n: Un elegante ciudadano para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    AddId(({"ciudadano","hombre"}));
    SetAds(({"elegante"}));
    SetStandard("un elegante ciudadano","humano",([GC_TORPE:13]),GENDER_MALE);
    SetShort("un elegante ciudadano");
    SetLong("Es un hombre entrado en a�os, pero las canas y el bigote gris�ceo "
    "le dan cierto toque de distinci�n.\n Parece un hombre muy educado y formal, "
    "seguramente trabaja en alg�n sitio importante.\n");
    InitChats(3,({"El ciudadano te sonr�e con amabilidad.\n",
      "El elegante ciudadano te mira.\n",
      "El elegante ciudadano parece repasar mentalmente algo.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/pantalones"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/camisa"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
