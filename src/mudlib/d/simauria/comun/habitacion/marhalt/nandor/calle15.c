/****************************************************************************
Fichero: calle15.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  La calle Narwhald.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle Narwhald");
    SetIntLong("Te encuentras en uno de los extremos de la calle Narwhald, que continúa "
        "al nordeste, aunque esta parte parece más amplia que el resto.\n  Si a lo largo de "
        "la calle hay guijarros y maceteros, con plantas que la adornan, aquí además"
        " hay un pequeño jardincito de un par de metros cuadrados, presidido por un pequeño"
        " arbolito, del que se espera que algún día cubra con su sombra al solitario "
        "banco de piedra que tiene a su lado.\n  Una típica casa de pueblo tiene la "
        "entrada al norte, mientras que al suroeste se encuentra la puerta trasera de "
        "la posada de Nandor.\n");
    SetIntSmell("Como en el resto de la calle, las plantas invaden con sus olores el "
        "ambiente.\n");
    SetIntNoise("Un fuerte sonido a gentío sale de la posada.\n");
    SetIndoors(0);
    AddDetail("posada", "Es un edificio de 2 plantas y esta es la entrada trasera.\n");
    AddDetail(({"guijarros","suelo"}), "Unos redondeados y brillantes guijarros cubren el"
        " suelo de la calle.\n");
    AddDetail(({"plantas","maceteros", "flores"}),
        "La calle está llena de plantas y maceteros.\n"
        " Puedes ver hierba buena, jazmines y unas pocas plantas de menta.\n");
    AddDetail(({"menta","hierba buena", "jazmines", "jazmín", "jazmin"}), "Forma parte de"
        " la vegetación de esta zona de la calle Narwhald.\n");
    AddDetail(({"árbol", "arbol", "arbolito", "nogal"}), "Parece que es un joven nogal.\n");
    AddDetail(({"nueces", "nuez"}), "Ahora no hay.\n");
    AddDetail(({"jardin", "jardín", "jardincito"}), "Está en medio de la calle, tiene "
        "un banco de piedra en su interior y un arbolito lo preside.\n");
    AddDetail(({"banco", "banco de piedra"}), "Pues es de piedra, y sirve para que te "
        "sientes si te apetece.\n");
    AddDetail(({"casa", "norte", "casa del norte", "típica casa"}), "Una típica casa de "
        "la villa.\n");
    AddExit("suroeste","./tiendas/posada");
    AddExit("nordeste","./calle14");
    AddDoor("suroeste", "la puerta trasera de la posada",
    "Es la puerta que da acceso a la posada, aunque no es la puerta principal.\n",
    ({"puerta", "puerta trasera", "puerta trasera de la posada", "puerta del suroeste"}));
}
