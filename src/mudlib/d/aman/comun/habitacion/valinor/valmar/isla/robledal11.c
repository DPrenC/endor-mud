/*****************************************************************************************
 ARCHIVO:       robledal11.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:   Hacia el OESTE ventana de la posada04_hab2.c
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el bosque, cerca de la posada");
    SetIntLong("Todo a tu alrededor está cubierto por maleza, abrojos, piornos y "
        "matorrales, que te impiden caminar por otro sitio que no sean los senderos "
        "que, débilmente, están marcados en el suelo.\n");
    AddDetail(({"maleza", "abrojos", "piornos", "matorrales"}), "La abundancia de malas "
        "hierbas delimitan el camino.\n");
    AddDetail("senderos", "Si no conoces la zona, no te conviene salirte de ellos.\n");
    AddDetail("suelo", "Está lleno de plantas y hojas pisoteadas.\n");
    AddDetail(({"troncos", "gruesos troncos"}), "Con tus brazos no serías capaz de "
        "abrazarlos.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal15.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal07.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal08.c"));
}
