/****************************************************************************
Fichero: ungrim_07.c
Autor: Riberales
Creaci�n: 28/09/2005
Descripci�n: Un tramo de la calle Ungrim.
****************************************************************************/

#include "./path.h"
inherit BASE_CIUDAD_ANNUFAM;



public void create()
{
    ::create();

    SetIntShort("la calle Ungrim");
    SetIntLong(W("Contin�as por la calle Ungrim. Al sur oyes voces y gritos. "
                 "Se trata de la taberna Mi Entra�able Cerveza. Al norte por "
                 "lo contrario, hay una chimenea en lo que parece una gran "
                 "herrer�a, cuya puerta se encuentra m�s al oeste. Al este "
                 "llegar�s al cruce con la avenida Real. Un par de antorchas "
                 "se colocan en cada una de las paredes para alumbrar la zona "
                 "cuando sea menester.\n"));


    AddSuelo();
    AddAntorchas();

    AddDetail(({"norte","pared norte","pared herreria","pared de herreria"}),
              W("Es la pared de la herrer�a. Arriba tiene una peque�a "
                "chimenea que supones vendr� del horno de fundici�n.\n"));


    AddDetail(({"sur","pared sur","taberna","pared taberna"}),
              W("Es la conocida taberna Mi Entra�able Cerveza. Seg�n cuentan, "
                "aqu� sirven varios tipos de cervezas, y que los reclutas se "
                "re�nen en este local cuando est�n de permiso.\n"));


    AddDetail(({"chimenea","chimenea de herreria","chimenea de herrer�a"}),
              W("Es una chimenea convencional que sale de la pared de la "
                "herrer�a. A trav�s de ella salen los humos producidos por el "
                "fuego de la fundici�n."));


    AddExit("sur",HAB_TABERNAS_ANNUFAM("entranable"));
    AddExit("este",HAB_UNGRIM_ANNUFAM("ungrim_06"));
    AddExit("oeste",HAB_UNGRIM_ANNUFAM("ungrim_08"));
}
