/**************************************************************************
fichero: minas23.c
Autor: Riberales
Creación: 2/1/06
Descripción: Room en tercera planta de las minas.
**************************************************************************/



#include "path.h"


inherit HAB_TERCERA_MINAS("tercera_base");

        create()
{
    object ob, carretilla;

    ::create();

    SetIntShort("una encrucijada de galerías");
    SetIntLong("Te encuentras en medio de un cruce de túneles, al lado de una "
               "carretilla abandonada, por lo que no muy lejos habrá buen "
               "mineral que extraer. Observas que las galerías discurren en "
               "dirección noroeste, suroeste y nordeste, donde el túnel se "
               "hace mucho más angosto.\n");

    DetalleParedes();

    AddItem(OTRO_MINAS("carretilla_rota"),REFRESH_DESTRUCT);

    if (carretilla = present("carretilla"))
    {
        ob = clone_object(OTRO_MINAS("mithril_grande"));
        ob->move(carretilla);
    }

    AddExit("noroeste",HAB_TERCERA_MINAS("minas22"));
    AddExit("suroeste",HAB_TERCERA_MINAS("minas20"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas24"));
    AddGuardia();
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}
