/****************************************************************************
Fichero: margarita.c
Autor: Ratwor
Fecha: 15/08/2007
Descripci�n: Una margarita temporal hasta que consiga que funcione la que se puede deshojar.
****************************************************************************/

#include <herbs.h>

inherit HERB;

create()
{
    ::create();
    AddId(({"flor", "margarita"}));
    SetShort("una margarita");
    SetLong("Es una hermosa margarita blanca, de gran tama�o. Tiene un tallo largo y"
        " flexible. Su abundancia de p�talos le da apariencia vistosa y radiante.\n");
    AddSubDetail(({"petalos", "p�talos", "petalo", "p�talo", "hoja", "hojas"}),
        "Tiene muchos p�talos blanquitos.\n");
    AddSubDetail(({"tayo", "tallo"}), "Es bastante largo.\n");
    SetSmell("Huele como todas las margaritas.\n");
    SetWeight(70);
    SetClass("saciante");
    SetPower(d6(6));
}

public void init()
{
    ::init();
    add_action("cmd_arrancar", "arrancar");
    add_action("cmd_arrancar", "quitar");
}

public int cmd_arrancar(string str){
    return notify_fail("Hay que ser bruto, siempre rompi�ndolo todo.\n");
}
