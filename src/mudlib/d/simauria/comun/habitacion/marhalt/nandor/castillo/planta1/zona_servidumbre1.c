/****************************************************************************
Fichero: zona_servidumbre1.c
Autor: Ratwor
Fecha: 01/01/2008
Descripci�n: pasillo para acceder a la zona de servidumbre
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntBright(25);
    SetIntShort("un pasillo de piedra");
    SetIntLong("Te encuentras en un pasillo de paredes desnudas iluminado por algunas "
    "antorchas situadas aqu� y all� sobre soportes de bronce.\n"
    "Al norte est� el gran vest�bulo, al sur la despensa del castillo  y hacia el "
    "oeste contin�a el pasillo.\n");
    AddDetail("antorchas", "Antorchas de gran tama�o permanentemente encendidas.\n");
    AddDetail("soportes", "Antiguos soportes de bronce con el escudo de los Dhes-Bl�in "
    "grabado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes est� cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre est� hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddExit("sur", "./despensa");
    AddExit("oeste", "./zona_servidumbre2");
    AddExit("norte", "./vestibulo");
    AddDoor("norte", "la puerta del vest�bulo",
    "Una simple puerta, pero bien cuidada, para salir de la zona de servidumbre al "
    "vest�bulo del castillo.\n",
    ({"puerta", "puerta del vest�bulo", "puerta del vestibulo", "puerta de madera",
        "puerta simple", "puerta del norte"}));
    SetLocate("el castillo de Nandor");
}

