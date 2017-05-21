/*
DESCRIPCION : El Negro, duenyo de un meson
FICHERO     : /d/akallab/comun/pnj/akallab/azzor/negro_cocina.c
MODIFICACION:
25-09-07 [Angor] Creacion
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit NPC;

public create()
{
    ::create();

    seteuid(getuid());

    SetStandard("el Negro", "orco",([GC_NINGUNO:30]),GENDER_MALE);
    SetShort("el Negro");
    SetLong("El Negro es un orco muy viejo y delgado con piel curtida y muy oscura. "
    "Dicen que viene del sur, de ahí el color y el mote, y dicen que no envejece por "
    "obra de algún hechizo. Sus ojos están hundidos pero siguen vivos y astutos. Aunque le "
    "falta parte de las orejas, sin duda debido a peleas, en lo que le queda de ellas "
    "lleva varios aros. El Negro regenta un mesón en el puerto que tiene fama de tener "
    "buenos platos de pescado. Huele a tabaco negro y lleva un trapo de cocina sobre el "
    "hombro.\n");

    SetIds(({"negro","tabernero","posadero","orco","Negro"}));

    InitChats(2,({
            "El Negro pega un par de profundas caladas al puro que fuma.\n",
            "El Negro enciende un nuevo puro. El aire huele al fragante tabaco negro del sur...\n"
            "El Negro escupe al suelo.\n"
            "El Negro remueve el contenido de varios calderos con una gran espátula.\n"
            "El Negro te mira, menea la cabeza y sigue a lo suyo.\n"
            "El negro rebusca en sus bolsillo en busca de un nuevo puro.\n"}));
    AddItem(ARMOUR,REFRESH_REMOVE,([
            P_SHORT: "un delantal",
            P_LONG: "Es un delantal de tela muy ordinario bastante sucio.\n",
            P_IDS: ({"delantal"}),
            P_ARMOUR_TYPE: AT_CORAZA,
            P_AC: 2,
            P_MATERIAL: M_TELA,
            P_WEIGHT:170]),
            SF(wearme));

}
