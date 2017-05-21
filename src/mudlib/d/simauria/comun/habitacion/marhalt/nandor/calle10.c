/****************************************************************************
Fichero: calle10.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  la calle Narwhald
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
    SetIntLong(" Estás al principio de la calle Narwhald, paralela a la calle principal "
        "de Nandor.\n A pesar de que es una calle secundaria de la villa, está adornada con "
        "unos bonitos guijarros redondeados en el suelo y maceteros con alegres plantas "
        "por todo lo largo de la calle, hasta el final que termina en la posada.\n"
        " Al norte está la entrada de una tienda, con su cartel en la puerta, que parece"
        " una herboristería, mientras que en el este se encuentra la entrada de una casa "
        "que parece grande. La calle continúa hacia el oeste.\n");
    SetIntNoise("No se oye silencio, pero sí mucha tranquilidad.\n");
    SetIntSmell(" El olor que proviene de la tienda del norte te confirma que es una"
        " herboristería, pues notas una fuerte mezcla de olores de distintas hierbas e "
        "infusiones.\n");
    SetIndoors(0);
    AddDetail(({"guijarros","suelo"}), "Unos redondeados y brillantes guijarros cubren el"
        " suelo de la calle.\n");
    AddDetail(({"letrero","cartel"}), "Es el letrero de la tienda.\n");

    AddReadMsg(({"letrero","cartel"}), "Herboristería Flor del norte.\n");
    AddDetail(({"plantas","maceteros", "flores"}),
        "Distintas plantas, en sus maceteros, adornan la calle dejándola realmente bonita.\n"
        " Puedes distinguir  algunos rosales, geráneos, claveles y un sin fin de plantas variadas.\n");
    AddDetail(({"rosales", "rosas","geráneos", "claveles"}), "El colorido de los pétalos "
        "de sus flores animan la calle.\n");
    AddDetail(({"tienda", "herboristeria", "herboristería", "norte"}), "Parece una "
        "herboristería bastante surtida.\n");
    AddDetail(({"casa","este", "casa del este"}), "La casa del este parece bastante "
        "grande y lujosa, no sabes de quien será.\n");
    AddExit("este",(:write("La casa está cerrada y tampoco es cuestión de ir entrando "
        "en todas partes.\n"),1:));
    AddExit("norte","./tiendas/herboristeria");
    AddExit("oeste","./calle11");
    AddExit("sur","./calle9");
    AddDoor("norte", "la puerta de la herboristería",
    "Es la puerta que da entrada a la herboristería.\n", ({"puerta", "puerta del norte",
        "puerta de la herboristería", "puerta de la herboristeria"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,2);
}
