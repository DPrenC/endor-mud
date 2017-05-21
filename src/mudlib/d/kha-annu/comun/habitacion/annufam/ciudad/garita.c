/****************************************************************************
Fichero: garita.c
Autor: Kastwey
Creaci�n: 24/07/2005
Descripci�n: Garita del guardia de Annufam
****************************************************************************/

#include "./path.h"
#include <moving.h>


inherit BASE_CIUDAD_ANNUFAM;

int cmd_mover(string str);

public void create()
{
    ::create();
    SetIntShort("una garita");
    SetIntLong(W("Has accedido a la garita del guardia en la entrada de "
                 "Annufam. Aqu� es donde se encuentra el mecanismo para "
                 "subir o bajar el puente, una especie de rueda que recoge "
                 "o suelta unas cadenas que supones ir�n enganchadas a la "
                 "puerta. El resto de la habitaci�n est� casi vac�a, con una "
                 "ventana en la pared oeste y un emblema que ves colgado "
                 "en una de las paredes.\n"));
    SetIndoors(1);
    SetIntBright(50);

    AddDetail(({"ventana","ventanuco"}),
              (:W("Es una peque�a ventana de lo m�s sencilla, que utiliza el "
                  "guardia para controlar la puerta cuando la est� subiendo "
                  "o bajando.\n"
                  "Te asomas, y observas que el port�n est� " +
                  (QueryExits()["oeste"]->QueryPortonAbierto() ?
                   "abierto" : "cerrado") + ".\n"):));

    AddDetail(({"rueda","mecanismo"}),
              W("Es una gran rueda de al menos dos metros de "
                "di�metro, que recoge o suelta las cadenas que se enganchan al "
                "puente. En un punto de la misma, distal al eje, puedes ver "
                "una barra de hierro.\n"));

    AddDetail(({"barra","barra de hierro"}),
              W("Es una barra de hierro perpendicular a la rueda, de donde "
                "se coge para girar la misma y as� recoger o soltar las "
                "cadenas y abrir o cerrar el puente.\n"));

    AddDetail("cadenas",W("Son unas cadenas de anchos eslabones que han de "
                          "soportar el peso del port�n de entrada. Se "
                          "recogen en la gran rueda, y ah� descansan cuando "
                          "el port�n est� cerrado.\n"));

    AddEstandarte(EST_NORMAL);
    AddExit("oeste",HAB_AVENIDA_ANNUFAM("avenida_01"));
    AddRoomCmd(({"mover","girar"}),"cmd_mover");
}




int cmd_mover(string str)
// mueve la rueda y abre o cierra el port�n.
{
    int abierto;
    object hab;
    if (!str || str != "rueda")
    {
        return notify_fail("�Mover qu�?\n",NOTIFY_NOT_VALID);
    }
    abierto = (hab = QueryExits()["oeste"])->QueryPortonAbierto();
    if (abierto)
    // el port�n est� abierto
    // si mueves la rueda, hay que cerrarlo
    {
        if (TP->QueryStr() < 20)
        {
            write(W("Intentas girar la rueda para hacer subir el port�n.\n"
                     "Sin embargo, parece que no eres lo suficientemente "
                     "fuerte para conseguirlo. Tras varios intentos, te das "
                     "por vencid " + AO + ".\n"));
            say(W(CAP(TNAME) + " intenta girar la rueda, pero no consigue "
                  "moverla.\n"));
            return 1;
        }
        // lo abres
        write(W("Con todas tus fuerzas, comienzas a mover la rueda.\n"
                "Observas como las cadenas se tensan, y tiran de la puerta "
                "hacia arriba.\n"
                "Tras un rato de arduo trabajo, consigues elevar el port�n.\n"));
        say(W(CAP(TNAME) + " comienza a girar la rueda... Observas como las "
              "cadenas se tensan y tiran del port�n hacia arriba.\n"));
        hab->SetPortonAbierto(0);
        return 1;
    }
    // el port�n est� cerrado.
    write(W("Comienzas a girar la rueda. Escuchas como las cadenas comienzan a "
            "a ceder y el puente empieza a descender.\n"
            "Tras un rato, consigues bajar el port�n.\n"));
    say(W(CAP(TNAME) + " comienza a girar la rueda.\n"
          "Escuchas como las cadenas se van soltando y el puente levadizo "
          "empieza a bajar.\n"
          "Tras un rato, el puente levadizo queda totalmente bajado.\n"));
    hab->SetPortonAbierto(1);
    return 1;
}
