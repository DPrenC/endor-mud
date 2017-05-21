  //
  //--------------------------------------------------------------------------------
  //DESCRIPCION : Cubierta de la goleta "Radiante" (ruta Berat-Gorat)
  //FICHERO     : /d/simauria/comun/transportes/barco/radiante/cubierta.c
  //MODIFICACION: 21-01-00 [Chaos@Simauria] Creacion
  //
  //-------------------------------------------------------------------------------_

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("la cubierta de la goleta Radiante");
    SetIntLong("Te encuentras en la cubierta de la goleta Radiante. Es un velero de tres "
        "mástiles, en la meseta permanece un vigía que está siempre atento al horizonte. "
        "En medio de la cubierta ves unas escaleras que llevan a la bodega. "
        "También puedes ver una puerta que lleva a los camarotes. Es un navío "
        "ligero, de poco calado y bordas poco elevadas, lo que hace que sea "
        "bastante rápido. Regularmente realiza el trayecto entre Berat y "
        "Gorat.\n");

    SetIndoors(0);

    //Ambientación

    AddDetail(({"radiante", "Radiante", "goleta", "barco", "cubierta"}), QueryIntLong());
    AddDetail(({"cofa", "cofas"}), "La cofa es una meseta colocada horizontalmente en el "
        "cuello de un palo para afirmar la obencadura de la gavia, facilitar la maniobra "
        "de las velas altas, etc.\n");
    AddDetail("meseta", "Es una especie de descansillo o rellano en el mástil.\n");
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

    AddExit("camarotes", BARCO("radiante/camarote"));
    AddExit("bodega", BARCO("radiante/bodega"));
}
