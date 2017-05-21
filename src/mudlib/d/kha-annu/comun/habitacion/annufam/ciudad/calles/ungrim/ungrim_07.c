/****************************************************************************
Fichero: ungrim_07.c
Autor: Riberales
Creación: 28/09/2005
Descripción: Un tramo de la calle Ungrim.
****************************************************************************/

#include "./path.h"
inherit BASE_CIUDAD_ANNUFAM;



public void create()
{
    ::create();

    SetIntShort("la calle Ungrim");
    SetIntLong(W("Continúas por la calle Ungrim. Al sur oyes voces y gritos. "
                 "Se trata de la taberna Mi Entrañable Cerveza. Al norte por "
                 "lo contrario, hay una chimenea en lo que parece una gran "
                 "herrería, cuya puerta se encuentra más al oeste. Al este "
                 "llegarás al cruce con la avenida Real. Un par de antorchas "
                 "se colocan en cada una de las paredes para alumbrar la zona "
                 "cuando sea menester.\n"));


    AddSuelo();
    AddAntorchas();

    AddDetail(({"norte","pared norte","pared herreria","pared de herreria"}),
              W("Es la pared de la herrería. Arriba tiene una pequeña "
                "chimenea que supones vendrá del horno de fundición.\n"));


    AddDetail(({"sur","pared sur","taberna","pared taberna"}),
              W("Es la conocida taberna Mi Entrañable Cerveza. Según cuentan, "
                "aquí sirven varios tipos de cervezas, y que los reclutas se "
                "reúnen en este local cuando están de permiso.\n"));


    AddDetail(({"chimenea","chimenea de herreria","chimenea de herrería"}),
              W("Es una chimenea convencional que sale de la pared de la "
                "herrería. A través de ella salen los humos producidos por el "
                "fuego de la fundición."));


    AddExit("sur",HAB_TABERNAS_ANNUFAM("entranable"));
    AddExit("este",HAB_UNGRIM_ANNUFAM("ungrim_06"));
    AddExit("oeste",HAB_UNGRIM_ANNUFAM("ungrim_08"));
}
