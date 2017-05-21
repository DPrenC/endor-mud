/**************************************************************************
fichero: minas01.c
Autor: Riberales
Creación: 19/10/05
Descripción: Room en primera planta de las minas.
**************************************************************************/


#include <moving.h>
#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");




create()
{
    ::create();

    SetIntShort("el inicio de las minas de Kha-annu");
    SetIntLong("Te encuentras en el primer tramo de las minas de Kha-annu. el "
               "camino sigue descendiendo conforme te internas en las mismas. "
               "en dirección este sales a la entrada de las minas, mientras "
               "que al oeste sigues entrando en las oscuras galerías.\n");
    DetalleParedes();

    AddExit("oeste",HAB_PRIMERA_MINAS("minas02"));
    AddExit("este",HAB_MINAS("entrada_minas"));
    AddGuardia();

}

public void notify_leave(mixed to,int method, mixed extra)
{
    if (!PO || method != M_GO || extra != "este") return ::notify_leave(to,method,extra);


    tell_object(PO,"Comienzas a subir una pronunciada pendiente que llega "
          "hasta la entrada de las minas.\n");

    return ::notify_leave(to,method,extra);
}
