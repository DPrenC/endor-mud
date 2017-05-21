/****************************************************************************
Fichero: entrada.c
Autor: Riberales
Fecha: 06/03/2006
Descripción: Entrada del Centro de Annufam.
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();

    SetIntShort("la entrada del centro");
    SetIntLong("Estás en la entrada del Centro de Adiestramiento de Guerreros "
               "Enanos de Annufam. Aquí los reclutas enanos se instruyen en "
               "el arte de la guerra en previsión de posibles ataques orcos o "
               "de cualquier otro enemigo. Te llama la atención una enseña "
               "del dominio de Kha-annu que ves en una de las paredes. Al "
               "norte puedes ver unas escaleras y lo que parece el "
               "principio de un pasillo.\n");

// En teoría faroles no hya. Lo que hay son antorchas.
    AddDetail(({"pared","paredes"}),
                "Las paredes están prácticamente desnudas. Solo una pintura "
                "de la enseña del dominio de Kha-annu y algún farol las "
                "decoran. Sospechas que los enanos no se han tomado muchas "
                "molestias en la decoración de su centro de "
                "entrenamiento.\n");

    AddDetail(({"enseña","ensenya"}),
                "Se trata de la enseña del dominio de Kha-annu. En su parte "
                "superior hay una corona de oro con cinco diamantes, que "
                "representan las cinco ciudades del dominio enano, y en la "
                "parte inferior un escudo con borde plateado y de fondo verde "
                "sobre el que hay un león rampante que muestra sus fauces "
                "desafiante, y que se encuentra flanqueado por dos hachas "
                "enanas de empuñadura marrón.\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo05"));
    AddExit("salir",HAB_CIUDAD_ANNUFAM("plaza"));
}
