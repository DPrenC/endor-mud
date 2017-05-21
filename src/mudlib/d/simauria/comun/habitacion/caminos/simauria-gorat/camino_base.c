/****************************************************************************
Fichero: camino_base.c
Autor: Ratwor
Fecha: 12/11/2006
Descripción: el nuevo camino base para Gorat.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("camino de Gorat");
    SetIntShort("el camino de Gorat");
    AddDetail(({"montaña","montañas"}), "Son unas escarpadas montañas, pero no demasiado "
        "altas, que acompañan al camino por el norte en todo su trayecto.\n");
    AddDetail(({"camino","suelo"}), " Es un ancho camino de tierra con multitud de "
        "huellas de carros y personas.\n En dirección oeste se dirije a Gorat, mientras"
        " que al este llegará al cruce del camino Nandor_ishtria.\n");
    AddDetail(({"huellas","pisadas","huella"}), "Huellas de todo tipo, de ruedas, "
        "personas y algunos animales, tanto pequeños como grandes.\n");
    switch(d3())
    {
        case 1:
            SetIntLong(
            "Te encuentras en el camino de Gorat que va de este a oeste, desde el cruce "
            "del camino Nandor-Ishtria hasta el pueblo pesquero de Gorat.\n Puedes "
            "ver distintas huellas de carros, lo cual te lleva a pensar que no "
            "todo el mundo viaja andando por aquí y prefieren coger la diligencia."
            "\n Unas escarpadas montañas te acompañan, en todo momento, por el norte.\n");
            break;
        case 2:
            SetIntLong(
            "Te encuentras en la región de Betwa atravesando el camino de Gorat, aunque "
            "podrías haber cogido la diligencia para ahorrarte la caminata, y los "
            "posibles peligros de las extrañas montañas que te acompañan por el norte "
            "en todo momento.\n");
            break;
        case 3:
            SetIntLong(
            "Viajas por un ancho camino de la región de Betwa, es bastante transitado "
            "debido a las distintas huellas que se ven en el suelo, cosa que es "
            "normal porque este camino lleva al importante puerto de Gorat y a la "
            "capital ishtria.\n");
            break;
    }
    if (d3()==1)
    AddItem(PNJ("camino/aveboske"),REFRESH_DESTRUCT,d2());
    SetIndoors(0);
}
