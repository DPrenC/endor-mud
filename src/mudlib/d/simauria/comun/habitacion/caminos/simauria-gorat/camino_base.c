/****************************************************************************
Fichero: camino_base.c
Autor: Ratwor
Fecha: 12/11/2006
Descripci�n: el nuevo camino base para Gorat.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("camino de Gorat");
    SetIntShort("el camino de Gorat");
    AddDetail(({"monta�a","monta�as"}), "Son unas escarpadas monta�as, pero no demasiado "
        "altas, que acompa�an al camino por el norte en todo su trayecto.\n");
    AddDetail(({"camino","suelo"}), " Es un ancho camino de tierra con multitud de "
        "huellas de carros y personas.\n En direcci�n oeste se dirije a Gorat, mientras"
        " que al este llegar� al cruce del camino Nandor_ishtria.\n");
    AddDetail(({"huellas","pisadas","huella"}), "Huellas de todo tipo, de ruedas, "
        "personas y algunos animales, tanto peque�os como grandes.\n");
    switch(d3())
    {
        case 1:
            SetIntLong(
            "Te encuentras en el camino de Gorat que va de este a oeste, desde el cruce "
            "del camino Nandor-Ishtria hasta el pueblo pesquero de Gorat.\n Puedes "
            "ver distintas huellas de carros, lo cual te lleva a pensar que no "
            "todo el mundo viaja andando por aqu� y prefieren coger la diligencia."
            "\n Unas escarpadas monta�as te acompa�an, en todo momento, por el norte.\n");
            break;
        case 2:
            SetIntLong(
            "Te encuentras en la regi�n de Betwa atravesando el camino de Gorat, aunque "
            "podr�as haber cogido la diligencia para ahorrarte la caminata, y los "
            "posibles peligros de las extra�as monta�as que te acompa�an por el norte "
            "en todo momento.\n");
            break;
        case 3:
            SetIntLong(
            "Viajas por un ancho camino de la regi�n de Betwa, es bastante transitado "
            "debido a las distintas huellas que se ven en el suelo, cosa que es "
            "normal porque este camino lleva al importante puerto de Gorat y a la "
            "capital ishtria.\n");
            break;
    }
    if (d3()==1)
    AddItem(PNJ("camino/aveboske"),REFRESH_DESTRUCT,d2());
    SetIndoors(0);
}
