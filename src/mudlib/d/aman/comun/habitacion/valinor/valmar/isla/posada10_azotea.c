/*****************************************************************************************
 ARCHIVO:       posada10_azotea.c
 AUTOR:         Ztico
 FECHA:         13-04-2005
 DESCRIPCI�N:   Posada del Unicornio Azul. Azotea.
 COMENTARIOS:   Describir panor�mica, etc.
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
    AddDetail("tejado", "Est� cubierto por tejas de pizarra de color negro azulado.\n");
    AddDetail(({"baranda", "barandilla"}), "De ricos balaustres de alabastro y filigrana "
        "de oro, sin duda debe costar una fortuna.\n");
    AddDetail(({"panor�mica", "panoramica", "paisaje"}), ".\n");
    AddDetail(({"mesa", "mesa circular"}), "Est� hecha de mimbre y ca�as.\n");
    AddDetail(({"silla", "sillas"}), "Est�n bastante deterioradas a causa de la humedad "
        "y de llevar tanto tiempo a la interperie.\n");

    AddExit("abajo", HAB_BOSQUE_ISLA("posada08_salon.c"));
}
