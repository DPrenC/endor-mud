/*

    Nombre      : cuartelEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : cuartel de la guardia de Enalel

*/

#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("el cuartel de la guardia de Enalel");
    SetIntLong("Estás en el cuartel de la guardia de Enalel.\n"
    "Se respira un ambiente de ajetreo y alerta.\n"
    "Una escalera te permite bajar hasta la sala de la guardia.\n"
    "Puedes salir hacia la calle de la empalizada al norte y hacia la calle del comercio al sur.\n");
    SetIntBright(35);
    SetIntNoise("Las conversaciones y el ajetreo forman los sonidos del lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddExit("norte",ENALHAB"poblado/calles/calle10");
    AddExit("sur",ENALHAB"poblado/calles/calle05");
    AddDoor("sur", "la puerta principal",
    "Es la puerta principal que da salida a la calle del comercio.\n",
    ({"puerta", "puerta principal", "puerta del sur"}));
    AddDoor("norte", "la puerta trasera",
    "Esta puerta, más pequeña que la principal, da salida a la calle de la empalizada.\n",
    ({"puerta", "puerta trasera", "puerta del norte"}));
    AddExit("abajo",ENALHAB"poblado/varios/sala_guardia");
     AddItem(ENALPNJ"guardias/enalel",REFRESH_DESTRUCT,d4());
    AddItem(ENALPNJ"guardias/sargento",REFRESH_DESTRUCT,1);
}
