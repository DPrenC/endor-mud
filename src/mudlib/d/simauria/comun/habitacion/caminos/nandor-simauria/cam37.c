
/****************************************************************************
Fichero: cam37.c
Autor: Ratwor
Fecha: 21/01/2007
Descripci�n: camino nandor-ishtria. Cruce con la capital.
****************************************************************************/


#include "./path.h"
inherit CNS("camino");

go_east()
{
    tell_room(TO,"El guardia dice: no se puede ir a Ishtria en este "
        "momento. La �ltima crecida del r�o ha puesto en alerta la ciudad, y ahora est� "
        "declarada como zona de alto riesgo.\n");
    return 1;
}

create() {
    ::create();
    SetIntShort("un cruce de caminos");
    SetIntLong("Has llegado a un cruce, donde en su ramificaci�n hacia el este, "
    "se encuentra un buen n�mero de guardias cortando el paso.\n Todo lo que se "
    "extiende hacia el nordeste es el bosque de Marhalt, y al noroeste ves unas "
    "pocas monta�as que adornan el paisaje.\n Junto al cruce puedes ver un poste "
    "clavado en el suelo.\n");
    AddDetail(({"poste", "letrero"}), "Es un robusto poste de madera, con un letrero "
    "clavado a �l que tiene escritas unas indicaciones.\n");    AddExit("este",SF(go_east));
    AddReadMsg(({"letrero", "cartel"}), " *Norte - Betwa | Marhalt.\n *Este - Ishtria.\n"
    " *Sur - Berat | Rhoemas | Nyne.\n");
    AddExit("suroeste",CAMINOS "/simauria-berat/cam01");
    AddExit("norte","./cam36");
}


