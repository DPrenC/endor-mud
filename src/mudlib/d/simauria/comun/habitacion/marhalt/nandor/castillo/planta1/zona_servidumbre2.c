/****************************************************************************
Fichero: zona_servidumbre2.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: la zona de servidrumbre
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntBright(25);
    SetIntShort("la zona de servidumbre");
    SetIntLong("Te encuentras en un pasillo de paredes desnudas iluminado por algunas "
    "antorchas situadas aquí y allá sobre soportes de bronce.\n");
    AddDetail("antorchas", "Antorchas de gran tamaño permanentemente encendidas.\n");
    AddDetail("soportes", "Antiguos soportes de bronce con el escudo de los Dhes-Bláin "
    "grabado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes está cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre está hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");

    AddExit("oeste", "./cocina");
    AddExit("este", "./zona_servidumbre1");
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("sirvientes_castillo"), REFRESH_DESTRUCT, d2());
}

