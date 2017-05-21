/***********************************************************
*    Nombre: cueva13.c			                   *
*    Localizacion: Cueva de los Trolls                     *
*    Realizada por : Cajun, el ejecutor                    *
*    Creado : 20-12-99                                     *
*    Modificado:                                           *
************************************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");

create () {
    ::create();
    SetIntShort("una guarida troll");
    SetIntLong("Al final del pasillo llegas a una sala mediana donde han habilitado "
    "pésimamente un almacén de comida. Las paredes y suelo están aquí con grandes "
    "manchas de sangre antigua.\n Entre la carne se puede diferenciar algunos animaless"
    " pero gran parte de esta carne no debe estar en buen estado.\n");
    SetIntSmell("Huele a carne no muy decente, pero no estas seguro si se trata de "
        "de carne animal o humana.\n");

    AddExit("este", "./cueva12");
    AddItem(PNJ("marhalt/cueva/troll"),REFRESH_DESTRUCT,d3());
}
