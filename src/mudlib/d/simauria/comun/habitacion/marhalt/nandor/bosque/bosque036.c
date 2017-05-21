/****************************************************************************
Fichero: bosque036.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    switch(d4()){
        case 1:
            SetIntLong(QueryIntLong()+
            "En esta parte el terreno se hace m�s h�medo, y el aroma de la tierra se "
            "nota algo m�s intenso, habr� una corriente de agua por aqu� cerca.\n");
            break;
        case 2:
            SetIntLong(QueryIntLong()  +
            "Escuchas, a lo lejos, el sonido del agua. La humedad del terreno se hace"
            " ligeramente m�s intensa, y se siente que te est�s acercando a un caudal de"
            " agua que todav�a no alcanzas con la vista.\n");
            break;
        case 3:
            SetIntLong(QueryIntLong()  +
            "A lo lejos se aprecia el sonido de agua en movimiento. El terreno se nota un"
            " poco m�s h�medo, y la vegetaci�n parece incluso m�s abundante.\n");
            break;
        case 4:
            SetIntLong(QueryIntLong()  +
            "Percibes que est�s cerca de un r�o. Oyes el agua y puedes sentir que "
            "el aroma de la tierra se ha vuelto m�s fuerte.\n  Comienzas a ver peque�os "
            "arbustos t�picos de las orillas de los r�os.\n");
            break;
    }

    AddExit("este","./bosque037");
    AddExit("oeste","./bosque035");
    AddExit("nordeste", "./bosque031");
    AddExit("noroeste", "./bosque030");
}


