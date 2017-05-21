/*
DESCRIPCION : Cubierta de la goleta "Tempestad" (ruta Azzor-Goldhai)
FICHERO     : /d/akallab/comun/objeto/barco/tempestad/cubierta.c
MODIFICACION: 18-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("la cubierta de la goleta 'Tempestad'");
    SetIntLong("Estás en la cubierta de la goleta 'Tempestad'. Este es un velero de tres "
        "palos con cofas y vergas en todos ellos. Es un navío ligero, de poco calado y "
        "bordas poco elevadas, lo que hace que sea bastante rápido. Regularmente realiza "
        "el trayecto entre Azzor y Goldhai.\n");

    SetIndoors(0);

    //Ambientación

    AddDetail(({"audaz", "Audaz", "goleta", "barco", "cubierta"}), QueryIntLong());
    AddDetail(({"cofa", "cofas"}), "La cofa es una meseta colocada horizontalmente en el "
        "cuello de un palo para afirmar la obencadura de la gavia, facilitar la maniobra "
        "de las velas altas, etc.\n");
    AddDetail("meseta", "Es una especie de descansillo o rellano en el mastil.\n");
    AddDetail("obencadura", "Es el conjunto de los obenques.\n");
    AddDetail(({"obenque", "obenques"}), "Un obenque es un cabo grueso que sujeta la "
        "cabeza de un palo o de un mastelero a los costados del buque o a la cofa "
        "correspondiente.\n");
    AddDetail(({"mastelero", "masteleros"}), "Un mastelero es un palo menor que se "
        "coloca horizontalmente en las embarcaciones sobre cada uno de los mayores.\n");
    AddDetail("gavia", "Una gavia es una de las velas del aparejo que se coloca en los "
        "masteleros.\n");
    AddDetail("aparejo", "El aparejo es el conjunto de palos, vergas, jarcias y velas de "
        "un buque.\n");
    AddDetail(({"verga", "vergas"}), "Una verga es una especie de percha a la cual se "
        "asegura el gratil de una vela.\n");
    AddDetail(({"jarcia", "jarcias"}), "La jarcia es el conjunto de aparejos y cabos de "
        "un buque.\n");
    AddDetail("gratil", "Extremidad de la vela por donde se une al palo o a la verga.\n");
}
