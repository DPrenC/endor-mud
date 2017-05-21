/****************************************************************************
Fichero: anciana.c
Autor: Dharkus
Fecha: 27/05/2010
Descripci�n: Una ciudadana anciana para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    SetStandard("una anciana","humano",([GC_TORPE:10]),GENDER_FEMALE);
      SetIds(({"anciana", "vieja", "mujer", "ciudadana", "humana"}));
    SetShort("una anciana");
    SetLong("Es una mujer madura, con el rostro un tanto p�lido y una mirada "
    "penetrante.\n Tiene el cabello cubierto de abundantes canas.\n Sus gestos "
    "y movimientos transmiten la imagen de una persona segura de s� misma.\n");
    InitChats(3,({"La anciana te sonr�e amablemente.\n",
      "La anciana dice:\n '�Cc�mo ha cambiado Koek desde que vine a vivir aqu�!'\n",
      "La anciana suspira.\n",
      "La anciana canturrea en voz baja.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/falda"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/blusa"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
}
