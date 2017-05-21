/****************************************************************************
Fichero: porhalt.c
Autor: Ratwor
Fecha: 30/03/2008
Descripción: El conductor de la diligencia Porhalt.
****************************************************************************/
#include <properties.h>
inherit NPC;

create(){
    ::create();
    SetStandard("Brand", "humano", 20, GENDER_MALE);
    SetShort("el conductor de la Norteña");
    SetLong("Brand es un humano de mediana edad que se ha pasado buena parte de "
    "su vida a conducir 'La Norteña', através de los caminos del norte de la región de "
    "Marhalt.\n");
    SetAlign(100);
    AddId(({"hombre", "conductor"}));
}
