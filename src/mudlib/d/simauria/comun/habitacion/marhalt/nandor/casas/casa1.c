/**************************************************************************/
/*                                                                        */
/*  [k] Kintups                                                           */
/*                                                                        */
/*  [k] Mon 13 Nov 2000 --- Revisados los textos y añadidos los W()       */
/*                                                                        */
/**************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("una sucia casa");
    SetIntLong("Nada más entrar, eres sofocado por el polvo y la suciedad que está "
    "flotando en el ambiente. Parece que alguien está de limpieza general, "
    "y que eso es algo que hace mucho tiempo que necesitaba esta cabaña. "
    "Piensas que debes salir de aquí lo antes posible, no sea que alguien "
    "te invite a echarle una mano.\n" );
    SetIntBright(30);
    AddExit("sur","../calle1" );
    AddDoor("sur", "la puerta de la calle");
    AddItem(PNJ("marhalt/mujer"),REFRESH_DESTRUCT,1);
}