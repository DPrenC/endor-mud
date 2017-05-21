/****************************************************************************
Fichero: calle10.c
Autor: Ratwor
Fecha: 01/11/2006
Descripci�n:  la calle Narwhald
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle Narwhald");
    SetIntLong(" Est�s al principio de la calle Narwhald, paralela a la calle principal "
        "de Nandor.\n A pesar de que es una calle secundaria de la villa, est� adornada con "
        "unos bonitos guijarros redondeados en el suelo y maceteros con alegres plantas "
        "por todo lo largo de la calle, hasta el final que termina en la posada.\n"
        " Al norte est� la entrada de una tienda, con su cartel en la puerta, que parece"
        " una herborister�a, mientras que en el este se encuentra la entrada de una casa "
        "que parece grande. La calle contin�a hacia el oeste.\n");
    SetIntNoise("No se oye silencio, pero s� mucha tranquilidad.\n");
    SetIntSmell(" El olor que proviene de la tienda del norte te confirma que es una"
        " herborister�a, pues notas una fuerte mezcla de olores de distintas hierbas e "
        "infusiones.\n");
    SetIndoors(0);
    AddDetail(({"guijarros","suelo"}), "Unos redondeados y brillantes guijarros cubren el"
        " suelo de la calle.\n");
    AddDetail(({"letrero","cartel"}), "Es el letrero de la tienda.\n");

    AddReadMsg(({"letrero","cartel"}), "Herborister�a Flor del norte.\n");
    AddDetail(({"plantas","maceteros", "flores"}),
        "Distintas plantas, en sus maceteros, adornan la calle dej�ndola realmente bonita.\n"
        " Puedes distinguir  algunos rosales, ger�neos, claveles y un sin fin de plantas variadas.\n");
    AddDetail(({"rosales", "rosas","ger�neos", "claveles"}), "El colorido de los p�talos "
        "de sus flores animan la calle.\n");
    AddDetail(({"tienda", "herboristeria", "herborister�a", "norte"}), "Parece una "
        "herborister�a bastante surtida.\n");
    AddDetail(({"casa","este", "casa del este"}), "La casa del este parece bastante "
        "grande y lujosa, no sabes de quien ser�.\n");
    AddExit("este",(:write("La casa est� cerrada y tampoco es cuesti�n de ir entrando "
        "en todas partes.\n"),1:));
    AddExit("norte","./tiendas/herboristeria");
    AddExit("oeste","./calle11");
    AddExit("sur","./calle9");
    AddDoor("norte", "la puerta de la herborister�a",
    "Es la puerta que da entrada a la herborister�a.\n", ({"puerta", "puerta del norte",
        "puerta de la herborister�a", "puerta de la herboristeria"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,2);
}
