/****************************************************************************
Fichero: jovencito.c
Autor: Dharkus
Fecha: 02/06/2010
Descripci�n: Un chico adolescente para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    AddId(({"jovencito","chico","adolescente"}));
    SetStandard("un adolescente","humano",([GC_TORPE:12]),GENDER_MALE);
    SetShort("un adolescente");
    SetLong("Es un adolescente de cabello rubio, y con abundante acn� en el rostro.\n"
    "Lleva una gran expresi�n de alegr�a que parece contagiarse.\n Va caminando "
    "en�rgico pero observando atentamente cada detalle de su entorno.\n");
    InitChats(5,({"El chico silva tranquilamente.\n",
      "El jovencito se retoca el peinado con la mano.\n",
      "el adolescente sonr�e.\n",
      "El chico te mira.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/camisa"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/pantalones"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(40);
    AddWalkZones(RHOEHAB("koek"));
}
