/****************************************************************************
Fichero: porhalt.c
Autor: Ratwor
Fecha: 30/03/2008
Descripci�n: El conductor de la diligencia Porhalt.
****************************************************************************/
#include <properties.h>
inherit NPC;

create(){
    ::create();
    SetStandard("Brand", "humano", 20, GENDER_MALE);
    SetShort("el conductor de la Norte�a");
    SetLong("Brand es un humano de mediana edad que se ha pasado buena parte de "
    "su vida a conducir 'La Norte�a', atrav�s de los caminos del norte de la regi�n de "
    "Marhalt.\n");
    SetAlign(100);
    AddId(({"hombre", "conductor"}));
}
