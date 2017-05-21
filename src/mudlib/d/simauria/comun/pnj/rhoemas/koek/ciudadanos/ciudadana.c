/****************************************************************************
Fichero: ciudadana.c
Autor: Dharkus
Fecha: 27/05/2010 
Descripci�n: Una ciudadana para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    SetStandard("una ciudadana","humano",([GC_TORPE:10+d2()]),GENDER_FEMALE);
    SetIds(({"mujer", "humana", "ciudadana"}));
    SetShort("una ciudadana");
    SetLong("Es una corpulenta mujer bastante joven, de cabello casta�o largo hasta "
    "los hombros.\n Tiene un gran lunar sobre la mejilla izquierda y cierto dejo "
    "de preocupaci�n en la mirada.\n");
    AddSubDetail("lunar","Se trata de una marca dejada posiblemente por alg�n tipo "
    "de enfermedad pasada en la piel.\n");
    InitChats(2,({"La ciudadana suspira hondo.\n",
      "La ciudadana murmura: '�C�mo disimular este lunar?'\n",
    "La ciudadana advierte tu presencia y esconde la cara entre las manos.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/vestido"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
