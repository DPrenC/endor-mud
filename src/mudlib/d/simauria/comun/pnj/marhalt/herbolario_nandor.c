/****************************************************************************
Fichero: HERBOLARIO_nandor.C
Autor: Ratwor
Fecha: 05/11/2006
Descripción: el HERBOLARIO de la HERBORISTERÍA de nandor.
****************************************************************************/


#include <properties.h>
#include <gremios.h>
#include "./path.h"

inherit NPC;
create()
{
    ::create();
    AddId(({"herbolario", "tendero", "narpac", "Narpac"}));
    SetStandard("Narpac", "humano",([GC_TORPE:15]), GENDER_MALE);
    SetShort("Narpac el herbolario");
    SetLong("Narpac es un adulto de mediana edad que siente gran amor por todo tipo de "
        "vegetales. Trata las hierbas como si fueran de su familia, suele salir mucho "
        "al bosque a recogerlas para luego mimarlas.\n Ahora se dedica a venderlas para "
        "poder sobrevivir, pero hubo una época que las tenía en su casa como animales de "
        "compañía.\n");
    SetWeight(65000);
    SetSmell("Huele a hierbas, parece obsesión lo del hombre este.\n");
    InitAChats(6,({"El herbolario grita.\n", "Narpac grita: ¡maldita sea tu estampa!\n"}));
    InitChats(3,({"Narpac huele unas flores.\n", "El herbolario se toca la nariz.\n",
        "El herbolario te mira.\n", "El herbolario te dice: ¿buscas alguna cosa.\n",
        "Narpac ordena unas hierbas extrañas.\n"}));
    AddQuestion(({"hierba", "hierbas", "flor", "flores"}),"Narpac  suspira y te dice:"
        " ¿Verdad que la naturaleza es sabia?\n");
    SetCitizenship("nandor");
}
