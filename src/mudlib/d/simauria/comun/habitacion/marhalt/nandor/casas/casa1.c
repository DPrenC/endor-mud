/**************************************************************************/
/*                                                                        */
/*  [k] Kintups                                                           */
/*                                                                        */
/*  [k] Mon 13 Nov 2000 --- Revisados los textos y a�adidos los W()       */
/*                                                                        */
/**************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("una sucia casa");
    SetIntLong("Nada m�s entrar, eres sofocado por el polvo y la suciedad que est� "
    "flotando en el ambiente. Parece que alguien est� de limpieza general, "
    "y que eso es algo que hace mucho tiempo que necesitaba esta caba�a. "
    "Piensas que debes salir de aqu� lo antes posible, no sea que alguien "
    "te invite a echarle una mano.\n" );
    SetIntBright(30);
    AddExit("sur","../calle1" );
    AddDoor("sur", "la puerta de la calle");
    AddItem(PNJ("marhalt/mujer"),REFRESH_DESTRUCT,1);
}