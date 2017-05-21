/*
DESCRIPCION : Thalan, amante de Malmabeth y poseedor de la palanca ;)
FICHERO     : /d/simauria/comun/pnj/simauria/berat/thalan.c
MODIFICACION: 2-6-00[Maler]creación
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create() {
    ::create();

    SetStandard("Thalan","humano",20,GENDER_MALE);
    SetShort("Thalan");
    SetLong("Ves a un hombre vestido de negro. Su cara refleja una especie de dolor "
    "continuado. Te mira y una expresión de miedo cruza sus ojos.\n");
    AddId(({"hombre","Thalan","humano"}));
    SetCitizenship("berat");
    AddAdjective(({"un"}));
    AddQuestion("palanca",
   "Thalan te dice: Si, tengo la palanca, pero no te la daré, mientras esté en "
    "mi poder, tengo el corazón de Malmabeth en mis manos. Ella ama ese cuchillo por "
    "encima de todas las cosas. Esta noche, cuando el albañil se vaya lo cogeré y "
    "chantajearé a Malmabeth para que se case conmigo.\n");
    AddQuestion(({"Malmabeth","malmabeth"}),
    "Thalan te dice: Oooooh, ella es preciosa, nunca encontraré a nadie parecido "
    "su preciosa piel blanca, sus preciosos ojos castaños.......\n");
    AddItem(QUEST+"/cuchillo/palanca",REFRESH_REMOVE);
}



