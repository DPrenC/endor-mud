/****************************************************************************
Fichero: patio09.c
Autor: Ratwor
Fecha: 28/12/2007
Descripci�n: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntShort("el patio de armas, zona de entrenamiento");
    SetIntLong("�sta zona del patio est� recubierta de una fina capa de arena sobre "
    "tierra apisonada. Es aqu� donde los nobles de los Dhes-Bl�in se ejercitan en el "
    "combate a caballo entre s� o contra el estafermo situado mas al este.\n"
    "Hacia el oeste hay un bajo cobertizo que hace las veces de taller y forja.\n");
    AddDetail("muro", "Enormes bloques rectangulares de piedra gris forman la parte "
    "baja del muro de la torre del homenaje.\n");
    AddDetail("arena", "Una capa de arena algo apelmazada mezclada con excrementos equinos.\n");
    AddDetail(({"taller", "cobertizo", "herrer�a"}), "Apoyado en la muralla occidental "
    "hay un achaparrado cobertizo de techo de pizarra con un agujero a modo de "
    "chimenea que alberga la herrer�a donde se fabrica y repara la impedimenta de la "
    "guarnici�n.\n");
    AddExit("este", "./patio10");
    AddExit("oeste",  "./taller");
    AddExit("norte", "./patio03");
    AddExit("nordeste", "./patio04");
    AddDoor("oeste", "la puerta del taller",
    "Es la puerta del taller de herrer�a.\n", ({"puerta", "puerta de madera",
    "puerta del taller", "puerta del taller de herrer�a", "puerta del taller de herreria",
    "puerta del oeste"}));
}


