/*****************************************************************************************
 ARCHIVO:       robledal07.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Sendero a trav�s del robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un sendero a trav�s de los �rboles");
    SetIntLong("Un sendero se abre paso entre robles y rocas. A ambos lados y a trav�s "
        "de la niebla, las ramas de los �rboles, arbustos y matorrales adquieren formas "
        "humanoides y de animales. Desde los agujeros de los troncos varias lucecitas "
        "resplandecen y te observan.\n");
    AddDetail(({"�rboles", "arboles", "robles"}), "Son altos, de corteza rugosa y casi "
        "blanca.\n");
    AddDetail("rocas", "Est�n oscurecidas, en la parte superior est�n llenas de peque�as "
        "cavidades llenas de agua.\n");
    AddDetail("cavidades", "El agua se ha ido acumulando en su interior, ya sea por las "
        "lluvias o por el roc�o.\n");
    AddDetail("niebla", "Todo est� envuelto en una neblina casi permanente, es "
        "especialmente espesa a ras de suelo.\n");
    AddDetail(({"ramas", "arbustos", "matorrales"}), "Crecen entre los �rboles y cambian "
        "de forma al comp�s del movimiento de la niebla.\n");
    AddDetail("agujeros", "Algunos troncos tienen agujeros de diversos tama�os.\n");
    AddDetail(({"lucecitas", "luces"}), "Destacan sobre la negrura de los agujeros, "
        "parecen peque�os ojos.\n");
    AddDetail("troncos", "Los m�s gruesos tienen nudos deformes y cavidades negras como "
        "el azabache.\n");
    AddDetail("suelo", "No ves el suelo a causa de la niebla.\n");

    SetIntSmell("El ambiente est� h�medo y huele a madera picada.\n");
    SetIntNoise("Escuchas el crujir de los �rboles y gru�idos procedentes de alg�n lugar "
        "cercano.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal11.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal06.c"));
}
