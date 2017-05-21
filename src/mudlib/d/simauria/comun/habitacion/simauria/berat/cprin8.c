/****************************************************************************
Fichero: cprin8.c
Autor: Dharkus
Fecha: 23/04/2010
Descripción: Añadido de la calle principal de Berat
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle principal");
    SetIntLong("Estás en uno de los extremos  de la calle principal de Berat.\n "
    "Al este está la entrada al edificio del cuartel de la guardia, al norte continúa "
    "la calle principal hacia el interior de la ciudad, mientras que al sur te "
    "encuentras con el puerto en pleno bullicio comercial.\n En el oeste tan solo "
    "hay un solar abandonado con abundante maleza.\n"); 
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio típico de los pueblos comerciantes.\n");
    AddDetail(({"solar", "solar abandonado", "maleza"}), "Ahí hay un solar abandonado con "
    "abundante maleza.\n"); 
    AddDetail(({"camino","calle"}),"Es la calle mas grande de Berat "
    " y las piedras que lo forman estan muy desgastadas.\n");
    AddDetail("piedras","Parecen cantos rodados, muy desgastados.\n");
    AddDetail(({"cuartel", "edificio", "cuartel de la guardia"}),
    "Es un edificio de madera algo más grande que el resto de los que hay en Berat, "
    "tiene un par de alturas y se nota algo castigado por el salitre del mar.\n");
    AddDetail("puerto", "Hacia el sur ya se puede divisar algo de mar y algún que otro "
    "barco.\n");
    AddDetail(({"agua", "barco", "barcos"}), "Algo más al sur podrás verlo mejor.\n");
    AddExit ("norte","./cprin7");
    AddExit("este","./cuartel/cuartel");
    AddExit("sur", "./muelle07"); 
    AddExit("oeste", "./cpuerto");
    HideExit("oeste",1);
    AddDoor("este", "Una gran puerta doble",
    "Es la puerta que da acceso al cuartel.\n Consiste en dos grandes alas de roble "
    "oscuro y viejo.\n",({"puerta","puerta doble","puerta este","puerta del este"}));
    AddItem(PNJ("simauria/berat/guardia"),REFRESH_DESTRUCT, ([P_GO_CHANCE:0]));
    AddItem(PNJ("simauria/berat/guardia"),REFRESH_DESTRUCT, ([P_GO_CHANCE:0]));
}
