/****************************************************************************
Fichero: bosque036.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    switch(d4()){
        case 1:
            SetIntLong(QueryIntLong()+
            "En esta parte el terreno se hace más húmedo, y el aroma de la tierra se "
            "nota algo más intenso, habrá una corriente de agua por aquí cerca.\n");
            break;
        case 2:
            SetIntLong(QueryIntLong()  +
            "Escuchas, a lo lejos, el sonido del agua. La humedad del terreno se hace"
            " ligeramente más intensa, y se siente que te estás acercando a un caudal de"
            " agua que todavía no alcanzas con la vista.\n");
            break;
        case 3:
            SetIntLong(QueryIntLong()  +
            "A lo lejos se aprecia el sonido de agua en movimiento. El terreno se nota un"
            " poco más húmedo, y la vegetación parece incluso más abundante.\n");
            break;
        case 4:
            SetIntLong(QueryIntLong()  +
            "Percibes que estás cerca de un río. Oyes el agua y puedes sentir que "
            "el aroma de la tierra se ha vuelto más fuerte.\n  Comienzas a ver pequeños "
            "arbustos típicos de las orillas de los ríos.\n");
            break;
    }

    AddExit("este","./bosque037");
    AddExit("oeste","./bosque035");
    AddExit("nordeste", "./bosque031");
    AddExit("noroeste", "./bosque030");
}


