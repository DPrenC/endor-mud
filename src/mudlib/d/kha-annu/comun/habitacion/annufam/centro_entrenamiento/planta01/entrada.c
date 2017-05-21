/****************************************************************************
Fichero: entrada.c
Autor: Riberales
Fecha: 06/03/2006
Descripci�n: Entrada del Centro de Annufam.
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();

    SetIntShort("la entrada del centro");
    SetIntLong("Est�s en la entrada del Centro de Adiestramiento de Guerreros "
               "Enanos de Annufam. Aqu� los reclutas enanos se instruyen en "
               "el arte de la guerra en previsi�n de posibles ataques orcos o "
               "de cualquier otro enemigo. Te llama la atenci�n una ense�a "
               "del dominio de Kha-annu que ves en una de las paredes. Al "
               "norte puedes ver unas escaleras y lo que parece el "
               "principio de un pasillo.\n");

// En teor�a faroles no hya. Lo que hay son antorchas.
    AddDetail(({"pared","paredes"}),
                "Las paredes est�n pr�cticamente desnudas. Solo una pintura "
                "de la ense�a del dominio de Kha-annu y alg�n farol las "
                "decoran. Sospechas que los enanos no se han tomado muchas "
                "molestias en la decoraci�n de su centro de "
                "entrenamiento.\n");

    AddDetail(({"ense�a","ensenya"}),
                "Se trata de la ense�a del dominio de Kha-annu. En su parte "
                "superior hay una corona de oro con cinco diamantes, que "
                "representan las cinco ciudades del dominio enano, y en la "
                "parte inferior un escudo con borde plateado y de fondo verde "
                "sobre el que hay un le�n rampante que muestra sus fauces "
                "desafiante, y que se encuentra flanqueado por dos hachas "
                "enanas de empu�adura marr�n.\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo05"));
    AddExit("salir",HAB_CIUDAD_ANNUFAM("plaza"));
}
