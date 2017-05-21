/****************************************************************************
Fichero: margarita.c
Autor: Ratwor
Fecha: 15/08/2007
Descripción: Una margarita temporal hasta que consiga que funcione la que se puede deshojar.
****************************************************************************/

#include <herbs.h>

inherit HERB;

create()
{
    ::create();
    AddId(({"flor", "margarita"}));
    SetShort("una margarita");
    SetLong("Es una hermosa margarita blanca, de gran tamaño. Tiene un tallo largo y"
        " flexible. Su abundancia de pétalos le da apariencia vistosa y radiante.\n");
    AddSubDetail(({"petalos", "pétalos", "petalo", "pétalo", "hoja", "hojas"}),
        "Tiene muchos pétalos blanquitos.\n");
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
    return notify_fail("Hay que ser bruto, siempre rompiéndolo todo.\n");
}
