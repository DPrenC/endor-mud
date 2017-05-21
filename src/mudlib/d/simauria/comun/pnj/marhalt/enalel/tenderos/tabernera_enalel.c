/****************************************************************************
Fichero: tabernera_enalel.c
Autor: Ratwor
Fecha: 20/11/2007
Descripción: Una tabernera para la posada de Enalel.
****************************************************************************/
#include "./path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
    ::create();
    SetStandard("Dilara", "humano", 11, GENDER_FEMALE);
    SetShort("Dilara la tabernera");
    SetLong("Dilara es una humana con lijeros rasgos élficos.\n Es la hija del "
    "posadero y, a nada mejor que hacer, se pasa buena parte del día atendiendo a "
    "los pueblerinos de Enalel en la posada, sirviendo las delicias que cocina su "
    "madre.\n De cabellos rubios y cara redondeada, donde llama la atención una bonita "
    "nariz, es una de las jóvenes del poblado más bellas.\n");
    SetSmell("Umm, huele bien.\n");
    AddId(({"joven", "humana", "dilara", "tabernera", "hija"}));
    InitChats(3, ({"Dilara te mira interrogante.\n",
        "Dilara limpia una jarra.\n", "Dilara habla en voz baja.\n",
    "Dilara pregunta: ¿a ver quién quiere otra ronda de sidra?\n"}));
}
