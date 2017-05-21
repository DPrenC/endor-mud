/* Archivo        corral.c
   Autor:         Yalin y Lug
   Fecha:         18/05/2006
   Descripci�n:   corral de la granja (proyecto)
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("un corral en la granja de la aldea de Sloch");
    SetIntLong("Est�s dentro de una empalizada que forma el corral de las "
        "aves de la granja. No tiene techo y en su lugar unas ca�as "
        "entrecruzadas impiden que los animales puedan huir volando de aqu�. "
        "Adosados a las paredes puedes ver peque�os cub�culos de madera "
        "donde se resguardan los animales por las noches y cuando hace mal "
        "tiempo. Unas varas de madera cruzan la habitaci�n cerca del suelo.\n "
        "Al norte puedes ver la puerta que permite la salida y la entrada de "
        "este lugar.\n");
    SetIntNoise("Escuchas el cacareo de las aves  que se han revolucionado "
        "con tu entrada aqu�.\n");
    SetIntSmell("�Apesta a aves!\n");
    AddDetail(({"techo"}), "No hay techo, en su lugar unas ca�as se "
        "entrecruzan sobre tu cabeza.\n");
    AddDetail(({"paredes", "pared"}), "Es una empalizada de estacas clavadas "
        "al suelo y entre s�. No es muy fuerte, pero s� lo suficiente para "
        "impedir la hu�da de las aves.\n");
    AddDetail(({"suelo"}), "Est� cubierto por toda clase de desperdicios y "
        "restos de la comida de estos repugnantes bichos de los que lo �nico "
        "bueno que se saca son los huevos y la carne.\n");
    AddDetail(({"varas", "vara"}), "Son largas y rectas ramas de �rbol que "
        "est�n colocadas a unos 30 cent�metros del suelo para que las aves "
        "se posen sobre ellas. �Est�n terriblemente sucias!\n");
    AddDetail(({"puerta", "puertas"}), "Son unas puertas de vaiv�n hechas de "
        "maderas. De este modo dejan entrar y salir a la gente sin peligro de "
        "que las aves se fuguen.\n");
    AddItem(PNJ("sherek/aldea/faisan"),REFRESH_DESTRUCT,2);
    AddItem(PNJ("sherek/aldea/gallina"),REFRESH_DESTRUCT,5+(d3()));
    AddItem(PNJ("sherek/aldea/gallo"),REFRESH_DESTRUCT,1);
    AddExit("norte", SHERALD("granja/granja04"));
    AddItem(PNJ("sherek/aldea/aldeanog"),REFRESH_DESTRUCT,2);
}
