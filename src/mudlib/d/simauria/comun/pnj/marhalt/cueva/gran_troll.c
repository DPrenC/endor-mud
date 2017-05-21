/****************************************************************************
Fichero: gran_troll.c
Autor: Ratwor
Fecha: 28/06/2008
Descripci�n: el sustituto del shad, un gran troll que se comi� al shad y ahora domina al
resto de trolls de la cueva.
****************************************************************************/

#include <properties.h>
#include "./path.h"
#include <gremios.h>
inherit NPC;

create() {
    ::create();
    SetStandard("un enorme troll", "troll",([ GC_LUCHADOR: 60+d8()]),GENDER_MALE);
    SetShort("un gran troll de las cavernas");
    SetLong("Una de las criaturas mas peligrosas de las profundidades de la tierra, este "
    "gran troll de las cavernas es un monstruoso humanoide de unos cuatro metros de "
    "altura.\n El grueso corpach�n est� revestido por una piel gris�cea cubierta "
    "por multitud de costurones y cicatrices mal curadas, producto de salvajes reyertas "
    "con quien sabe que odiosa criatura de la oscuridad subterr�nea.\n Posee brazos muy "
    "largos y desgarbados, delgados en comparaci�n al tronco pero a�n as�, tres "
    "veces mas gruesos que los de un humano, que terminan en manos garrudas de dedos "
    "largos y nudosos.\n La enorme cabeza calva, est� encajada entre los hombros "
    "ligeramente inclinada hacia adelante, de forma que la mand�bula inferior, "
    "cuadrada y desproporcionadamente grande se apoya casi sobre el pecho.\n La "
    "criatura carece de orejas, aunque bajo una frente abombada y huesuda los ojos "
    "blancuzcos miran con fr�a malignidad.\n El troll se apoya sobre una nudosas piernas "
    "arqueadas terminadas en pies anchos y deformes, sobre cuya oscura piel, crece "
    "alguna clase de musgo infecto.\n");
    SetAggressive(1);
    SetSmell("Huele horriblemente mal.\n");
    InitAChats(5, ({
    "El troll toma aire rugiendo de forma ensordecedora.\n",
    "La garra del troll desplaza con un zumbido el aire junto a tu cabeza cuando este "
    "hierra su ataque.\n",
    "Las heridas del troll exudan pus amarillento cuando �ste se defiende.\n",
    "El troll abre desmesuradamente su cavernosa boca mostrando los toscos colmillos.\n",
    "Los ojos del troll se motean de rojo cuando la furia lo domina.\n"}));

}
