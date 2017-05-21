/****************************************************************************
Fichero: ciudadano.c
Autor: Dharkus
Fecha: 02/06/2010 
Descripción: Un ciudadano para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    AddId(({"ciudadano", "hombre", "joven"}));
    SetStandard("un joven","humano",([GC_TORPE:10+d4()]),GENDER_MALE);
    SetShort("un joven ciudadano");
    SetLong("Es un hombre bastante joven, de cabello muy negro y ojos color café.\n "
    "Va caminando distraído, casi sin prestar atención a nada de lo que le rodea.\n "
    "Lleva un pequeño tatuaje en el brazo izquierdo.\n");
    AddSubDetail("tatuaje","Es un rectángulo dibujado en la piel, con unos símbolos o "
    "dibujos que no consigues entender.\n");
    InitChats(3,({"El joven parece distraído.\n",
      "El joven te muestra el brazo izquierdo y comenta:\n '¿Te gusta?\n ¡No "
      "pongas esa cara! Son símbolos familiares que aunque quieras, no podrías "
      "entender, ni yo puedo explicarte.'\n",
    "El joven echa a andar y tropieza contigo.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/pantalones"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/camisa"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
