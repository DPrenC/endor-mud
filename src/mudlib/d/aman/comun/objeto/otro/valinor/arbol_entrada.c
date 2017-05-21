/***
Fichero: arbol_entrada.c
Autor: kastwey@simauria
Descripción: Un árbol para la entrada al bosque mágico de Faeria.
Creación: 18/12/2004
***/

#include "path.h"
#include <skills.h>
#include <combat.h>
#include <moving.h>

inherit THING;

int cmd_trepar(string str);

init()
{
    ::init();
    add_action("cmd_trepar","trepar");
}

create()
{
    ::create();
    SetShort("un enorme árbol");
    SetLong(W("Es un gigantesco árbol.\n"
    "Tiene un grueso tronco, con infinidad de ramas más gruesas que el brazo de un gigante.\n"
    "Miras hacia arriba intentando ver la copa, pero lo más que consigues discernir, es que el árbol continúa ascendiendo hasta donde tu vista alcanza.\n"));
    AddId("arbol");
    AddId("árbol");
    SetNoTake("Ni cien como tú podría mover este árbol ni un milímetro.\n");
    SetSmell("huele a madera.\n");
}
int cmd_trepar(string str)
{
    int hab;
    if (!str || (str != "arbol" && str != "árbol" && str != "al arbol" && str != "al árbol")) return 0;
    hab = TP->UseSkill(HAB_TREPAR);
    if (hab < 30)
    {
        write("Comienzas a trepar por las gruesas ramas del árbol. Sin embargo, tu inexperiencia hace que pierdas pie, y sin poder evitarlo, caigas al suelo.\n");
        say(W(capitalize(TP->QueryName()) + " comienza a trepar por las gruesas ramas del árbol. Sin embargo, sin poder evitarlo, pierde pie y cae al suelo.\n"),TP);
        TP->Defend(random(5), DT_BLUDGEON, DEFEND_F_NOLIV);
    }
    else
    {
        if (TP->move(HAB_BOSQUE_PUESTO("copa_arbol"),M_SPECIAL,({
        W("comienza a ascender por las gruesas ramas del árbol.....\n"
        "Milagrosamente, consigue llegar a la copa"),
        "llega trepando desde la base del árbol",
        W("Comienzas a trepar por las ramas del árbol.......\n"
        "Tras un rato de arduo ascenso, consigues llegar a la copa")
        })) != ME_OK) return write("Por alguna razón, la copa del árbol es inaccesible. Consulta con un wizard.\n"),1;

    }
    return 1;
}