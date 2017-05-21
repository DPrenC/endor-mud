/*****************************************************************************************
 ARCHIVO:       robledal07.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Sendero a través del robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un sendero a través de los árboles");
    SetIntLong("Un sendero se abre paso entre robles y rocas. A ambos lados y a través "
        "de la niebla, las ramas de los árboles, arbustos y matorrales adquieren formas "
        "humanoides y de animales. Desde los agujeros de los troncos varias lucecitas "
        "resplandecen y te observan.\n");
    AddDetail(({"árboles", "arboles", "robles"}), "Son altos, de corteza rugosa y casi "
        "blanca.\n");
    AddDetail("rocas", "Están oscurecidas, en la parte superior están llenas de pequeñas "
        "cavidades llenas de agua.\n");
    AddDetail("cavidades", "El agua se ha ido acumulando en su interior, ya sea por las "
        "lluvias o por el rocío.\n");
    AddDetail("niebla", "Todo está envuelto en una neblina casi permanente, es "
        "especialmente espesa a ras de suelo.\n");
    AddDetail(({"ramas", "arbustos", "matorrales"}), "Crecen entre los árboles y cambian "
        "de forma al compás del movimiento de la niebla.\n");
    AddDetail("agujeros", "Algunos troncos tienen agujeros de diversos tamaños.\n");
    AddDetail(({"lucecitas", "luces"}), "Destacan sobre la negrura de los agujeros, "
        "parecen pequeños ojos.\n");
    AddDetail("troncos", "Los más gruesos tienen nudos deformes y cavidades negras como "
        "el azabache.\n");
    AddDetail("suelo", "No ves el suelo a causa de la niebla.\n");

    SetIntSmell("El ambiente está húmedo y huele a madera picada.\n");
    SetIntNoise("Escuchas el crujir de los árboles y gruñidos procedentes de algún lugar "
        "cercano.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal11.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal06.c"));
}
