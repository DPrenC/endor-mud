/****************************************************************************
Fichero: anciana2.c
Autor: Dharkus
Fecha: 27/05/2010
Descripción: Otra viejecita para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    SetStandard("una anciana","humano",([GC_TORPE:9]),GENDER_FEMALE);
    SetIds(({"anciana", "humana", "vieja", "mujer", "ciudadana"}));
    SetShort("una anciana");
    SetLong("Es una anciana de grises cabellos y el rostro muy marcado por el paso "
    "del tiempo.\n Se nota un dejo de tristeza en su mirada.\n Posiblemente en "
    "su juventud fue una mujer muy hermosa.\n");
    InitChats(3,({"La anciana te mira.\n",
      "La anciana dice:\n '¡Todo son achaques, todo son dolores!'\n",
      "La anciana suspira.\n",
      "La anciana te mira y comenta:\n '¡Qué juventud la tuya!\n Tendrías que haberme "
      "visto de joven.'\n"}));
    AddItem(RHOEARM("koek/ciudadanos/vestido"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
}
