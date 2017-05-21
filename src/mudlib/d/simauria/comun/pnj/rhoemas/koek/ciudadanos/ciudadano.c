/****************************************************************************
Fichero: ciudadano.c
Autor: Dharkus
Fecha: 02/06/2010 
Descripci�n: Un ciudadano para Koek
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
    SetLong("Es un hombre bastante joven, de cabello muy negro y ojos color caf�.\n "
    "Va caminando distra�do, casi sin prestar atenci�n a nada de lo que le rodea.\n "
    "Lleva un peque�o tatuaje en el brazo izquierdo.\n");
    AddSubDetail("tatuaje","Es un rect�ngulo dibujado en la piel, con unos s�mbolos o "
    "dibujos que no consigues entender.\n");
    InitChats(3,({"El joven parece distra�do.\n",
      "El joven te muestra el brazo izquierdo y comenta:\n '�Te gusta?\n �No "
      "pongas esa cara! Son s�mbolos familiares que aunque quieras, no podr�as "
      "entender, ni yo puedo explicarte.'\n",
    "El joven echa a andar y tropieza contigo.\n"}));
    AddItem(RHOEARM("koek/ciudadanos/pantalones"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/camisa"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
