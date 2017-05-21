/****************************************************************************
Fichero: tabernero_contrabandista.c
Autor: Buh
Fecha: 05/09/2006
Descripci�n: un tabernero para la taberna de contrabandistas de Crowy.
Como buen contrabandista, quiz� le quede bien una daga o similar.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <gremios.h>
#include DOM_SYS "crowiano.h"

inherit PNJ_CROWY("crowiano_civil_base");


create()
{
    ::create();
    AddId(({"contrabandista", "tabernero", "rhams", "Rhams"}));
    SetStandard("Rhams", "humano", ([GC_LUCHADOR:23]), GENDER_MALE);
    SetShort("rhams el tabernero");
    SetLong("Rhams es un viejo humano que durante toda su vida ha servido en esta"
        " taberna.\n  Sus arrugas en la cara y el pelo blanco en cabeza y bigote te "
        "hacen deducir que lleva en esta isla tanto como el que m�s.\n Pero, aparte de "
        "ser un simple sirviente de comidas y bebidas, tambi�n es el enlace de los "
        "contrabandistas en toda la isla de goldhai.\n");
    SetEdad(MEDIANA);
    SetAlign(-30);
    SetWeight(70000);
    SetSmell("Huele a lo t�pico en una taberna.\n");
    AddSubDetail(({"bigote", "pelo"}), "Blanco blanco de verdad.\n");
    InitAChats(30, ({"Rhams grita: �no sabes con quien te est�s metiendo!.\n",
    "Rhams dice: van a ir a por ti todos mis compa�eros y te acordar�s de esto.\n"}));
    InitChats(2, ({"El tabernero te mira con disimulo.\n",
        "Te ha parecido ver como Rhams ocultaba algo en sus bolsillos rapidamente.\n",
        "El tabernero se sirve un vaso de vino.\n",
    "Rhams bebe un poco de vino.\n"}));
    AddQuestion(({"contrabando", "anillo", "frobbon"}), "Rhams te dice: mejor pregunta"
    " a alguno de mis clientes, seguro que algo saben.\n", 1);
    AddQuestion(({"gremio", "gremio de contrabandistas"}), "Rhams te dice: ummm, as� que"
        " buscas el gremio...\n  La sede de los contrabandistas est� en Simauria, m�s "
        "concretamente por la peninsula de nyne.\n  Puedes buscar alg�n  gu�a por alguno "
        "de los pueblos cercanos de por all�.\n", 1);
    AddQuestion(({"pueblo", "pueblos", "nyne", "peninsula de nyne", "guia", "gu�a"}),
        "Rhams te dice: mucho preguntas ya.\n", 1);
}
