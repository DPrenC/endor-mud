/*****************************************************************************************
 ARCHIVO:       posada10_azotea.c
 AUTOR:         Ztico
 FECHA:         13-04-2005
 DESCRIPCIÓN:   Posada del Unicornio Azul. Azotea.
 COMENTARIOS:   Describir panorámica, etc.
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("la azotea");
    SetIntLong("Has llegado a una terraza vertiginosamente elevada sobre el tejado de "
        "la posada. Una baranda te separan del abismo. Hay cinco sillas de mimbre "
        "rodeando a una mesa circular.\n");
    AddDetail("tejado", "Está cubierto por tejas de pizarra de color negro azulado.\n");
    AddDetail(({"baranda", "barandilla"}), "De ricos balaustres de alabastro y filigrana "
        "de oro, sin duda debe costar una fortuna.\n");
    AddDetail(({"panorámica", "panoramica", "paisaje"}), ".\n");
    AddDetail(({"mesa", "mesa circular"}), "Está hecha de mimbre y cañas.\n");
    AddDetail(({"silla", "sillas"}), "Están bastante deterioradas a causa de la humedad "
        "y de llevar tanto tiempo a la interperie.\n");

    AddExit("abajo", HAB_BOSQUE_ISLA("posada08_salon.c"));
}
