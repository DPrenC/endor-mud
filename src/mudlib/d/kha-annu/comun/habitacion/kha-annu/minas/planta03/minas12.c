/**************************************************************************
fichero: minas12.c
Autor: Riberales
Creación: 26/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("el corazón de las minas enanas");
    SetIntLong("Permaneces en lo más recóndito de estas minas enanas, y el "
               "aire cada vez está más viciado, unido a una fuerte humedad. "
               "Te parece escuchar un extraño murmullo a tus pies, aunque "
               "quizá sea ya producto de tu estancia en estas oscuras "
               "galerías.\n");

    DetalleParedes();

    SetIntNoise("Reconoces lo que parece um murmullo de agua justo a tus "
                "pies.\n");

    AddExit("norte",HAB_TERCERA_MINAS("minas11"));
    AddExit("sudeste",HAB_TERCERA_MINAS("minas13"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}

