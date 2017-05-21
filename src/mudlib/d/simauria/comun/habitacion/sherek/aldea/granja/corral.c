/* Archivo        corral.c
   Autor:         Yalin y Lug
   Fecha:         18/05/2006
   Descripción:   corral de la granja (proyecto)
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("un corral en la granja de la aldea de Sloch");
    SetIntLong("Estás dentro de una empalizada que forma el corral de las "
        "aves de la granja. No tiene techo y en su lugar unas cañas "
        "entrecruzadas impiden que los animales puedan huir volando de aquí. "
        "Adosados a las paredes puedes ver pequeños cubículos de madera "
        "donde se resguardan los animales por las noches y cuando hace mal "
        "tiempo. Unas varas de madera cruzan la habitación cerca del suelo.\n "
        "Al norte puedes ver la puerta que permite la salida y la entrada de "
        "este lugar.\n");
    SetIntNoise("Escuchas el cacareo de las aves  que se han revolucionado "
        "con tu entrada aquí.\n");
    SetIntSmell("¡Apesta a aves!\n");
    AddDetail(({"techo"}), "No hay techo, en su lugar unas cañas se "
        "entrecruzan sobre tu cabeza.\n");
    AddDetail(({"paredes", "pared"}), "Es una empalizada de estacas clavadas "
        "al suelo y entre sí. No es muy fuerte, pero sí lo suficiente para "
        "impedir la huída de las aves.\n");
    AddDetail(({"suelo"}), "Está cubierto por toda clase de desperdicios y "
        "restos de la comida de estos repugnantes bichos de los que lo único "
        "bueno que se saca son los huevos y la carne.\n");
    AddDetail(({"varas", "vara"}), "Son largas y rectas ramas de árbol que "
        "están colocadas a unos 30 centímetros del suelo para que las aves "
        "se posen sobre ellas. ¡Están terriblemente sucias!\n");
    AddDetail(({"puerta", "puertas"}), "Son unas puertas de vaivén hechas de "
        "maderas. De este modo dejan entrar y salir a la gente sin peligro de "
        "que las aves se fuguen.\n");
    AddItem(PNJ("sherek/aldea/faisan"),REFRESH_DESTRUCT,2);
    AddItem(PNJ("sherek/aldea/gallina"),REFRESH_DESTRUCT,5+(d3()));
    AddItem(PNJ("sherek/aldea/gallo"),REFRESH_DESTRUCT,1);
    AddExit("norte", SHERALD("granja/granja04"));
    AddItem(PNJ("sherek/aldea/aldeanog"),REFRESH_DESTRUCT,2);
}
