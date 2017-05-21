/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/bodega01.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripci�n: Bodega de la aldea, nave de embasado.
****************************************************************************/

#include "path.h"
inherit SHERALD("ceroom");

public int fcoger(string str)
{
    if ((str == "barril") || (str == "barriles") || (str == "tonel") || (str == "toneles"))
    {
        write("�Pretendes romperte la espalda?\n");
         return 1;
    }
    if (str == "tinaja")
    {
        write("Y de paso, �por qu� no te llevas la nave a cuestas?");
        return 1;
    }
    if ((str == "ca�o") || (str == "canyo") || (str == "ca�os") || (str == "canyos") || (str == "canal"))
    {
        write("�No crees que esta gente es ya bastante pobre para que les "
            "destroces lo poco que tienen?");
        return 1;
    }
}

create()
{
    ::create();
    SetIntShort("la nave de recogida, en la bodega");
    SetIntLong("�sta es la parte de la bodega donde se recoge el mosto que "
        "fluye del lagar al pisar la uva.\nEn la pared norte, sale de junto "
        "al techo el canal que transporta el mosto hasta la tinaja, que, "
        "colocada en el centro, ocupa casi todo el espacio de la sala.\nA "
        "todo lo largo de las paredes, rodeando la tinaja, hay toneles "
        "vac�os, esperando el mosto de la pr�xima vendimia.\nAl norte, una "
        "puerta lleva a los almacenes donde se guardan los barriles ya "
        "llenos, para terminar de criar el vino.\nUna escalerilla conduce, "
        "hacia el oeste, a una plataforma desde donde el operario remueve el "
        "vino con un palo, para que no forme hilos.\nHay muy poca iluminaci�n, "
        "porque la luz no es conveniente para la fermentaci�n.\n");
    SetIntBright(20);
    SetIntSmell("Hay un fuerte olor a alcohol et�lico y a aire enrarecido. "
        "No deber�as quedarte aqu� mucho tiempo.\n");
    SetIntNoise("No oyes nada. Al vino no le sientan bien los ruidos.\n");
    AddDetail(("tinaja"), "Es un monstruoso cilindro de unos 6 o 7 metros "
        "de altura, y unos 4 de ancho, algo panzudo hacia su parte media, y "
        "en forma de cono invertido en su parte m�s baja.\nA unos 70 "
        "cent�metros del suelo, salen ca�os de varios puntos, para pasar el "
        "vino ya hecho a los toneles. Esto hace que siempre quede algo de "
        "vino espeso y con posos en la base de la tinaja, que es lo que se "
        "conoce como  la madre del vino, y ayudar� a fermentar la pr�xima "
        "llenada de mosto.\nBajo cada ca�o, una depresi�n circular en el "
        "suelo permite colocar el barril, de forma que quede estable y con "
        "la boca ajustada al grifo.\n");
    AddDetail(({"ca�o","ca�os"}), "Son unos tubos de madera, insertados en "
        "la tinaja, con el otro extremo cerrado, con dos agujeros laterales "
        "y opuestos, donde se introduce un canutillo hueco, con un agujerito "
        "en el lateral, de forma que al girarlo, permite o cierra el paso "
        "del vino, a manera de un primitivo grifo.\n");
    AddDetail(({"canal","canalon","canal�n"}),
        "Es un semicilindro de madera, que va desde la salida del lagar, "
        "arriba al norte, hasta la boca de la tinaja, y sirve para trasegar "
        "el mosto que va soltando la uva al ser pisada.\n");
    AddDetail(({"tonel","toneles","barril","barriles"}), "Los barriles son "
        "cilindros hechos de tablas curvadas, unidas por abrazaderas "
        "met�licas, y con unos c�rculos de madera cerrando sus bases. En una "
        "de ellas, hay un orificio cerrado por un corcho. Sirven para "
        "almacenar el vino.\n");
    AddDetail(("plataforma"), "Es un entarimado de tablas, de unos 60 "
        "cent�metros cuadrados, sostenida por 4 puntales de madera.\n");
    AddDetail(({"puntal","puntales"}), "Son 4 simples troncos, ligeramente "
        "desbastados, que sostienen la plataforma a la altura de la boca "
        "de la tinaja.\n");
    AddDetail(({"escalerilla","listones","travesa�os"}), "Dos listones "
        "verticales unidos por travesa�os horizontales, conducen desde el "
        "suelo a la plataforma.\n");
    AddRoomCmd("coger","fcoger");
    AddExit("arriba", SHERALD("casas/bodega00"));
    AddExit("subir",SHERALD("casas/tablado"));
    AddExit("norte", SHERALD("casas/bodega02"));
}
