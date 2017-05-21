/***
Fichero: arbol_entrada.c
Autor: kastwey@simauria
Descripci�n: Un �rbol para la entrada al bosque m�gico de Faeria.
Creaci�n: 18/12/2004
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
    SetShort("un enorme �rbol");
    SetLong(W("Es un gigantesco �rbol.\n"
    "Tiene un grueso tronco, con infinidad de ramas m�s gruesas que el brazo de un gigante.\n"
    "Miras hacia arriba intentando ver la copa, pero lo m�s que consigues discernir, es que el �rbol contin�a ascendiendo hasta donde tu vista alcanza.\n"));
    AddId("arbol");
    AddId("�rbol");
    SetNoTake("Ni cien como t� podr�a mover este �rbol ni un mil�metro.\n");
    SetSmell("huele a madera.\n");
}
int cmd_trepar(string str)
{
    int hab;
    if (!str || (str != "arbol" && str != "�rbol" && str != "al arbol" && str != "al �rbol")) return 0;
    hab = TP->UseSkill(HAB_TREPAR);
    if (hab < 30)
    {
        write("Comienzas a trepar por las gruesas ramas del �rbol. Sin embargo, tu inexperiencia hace que pierdas pie, y sin poder evitarlo, caigas al suelo.\n");
        say(W(capitalize(TP->QueryName()) + " comienza a trepar por las gruesas ramas del �rbol. Sin embargo, sin poder evitarlo, pierde pie y cae al suelo.\n"),TP);
        TP->Defend(random(5), DT_BLUDGEON, DEFEND_F_NOLIV);
    }
    else
    {
        if (TP->move(HAB_BOSQUE_PUESTO("copa_arbol"),M_SPECIAL,({
        W("comienza a ascender por las gruesas ramas del �rbol.....\n"
        "Milagrosamente, consigue llegar a la copa"),
        "llega trepando desde la base del �rbol",
        W("Comienzas a trepar por las ramas del �rbol.......\n"
        "Tras un rato de arduo ascenso, consigues llegar a la copa")
        })) != ME_OK) return write("Por alguna raz�n, la copa del �rbol es inaccesible. Consulta con un wizard.\n"),1;

    }
    return 1;
}