/****************************************************************************
Fichero: ogro.c
Autor: Ratwor
Fecha: 18/08/2007
Descripci�n: Un ogro de las cabernas de Caos.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    switch(d2()){
        case 1:
            SetStandard("un ogro","ogro",([ GC_LUCHADOR:60+d8()]),GENERO_MASCULINO);
            SetShort("un ogro de las cavernas");
            switch(d2()){
                case 1:
                    SetLong("Es una criatura de aspecto humanoide, de unos 3 metros de"
                    " altura, cuyo rostro se encuentra cubierto casi por completo por "
                    "una espesa mara�a de pelo negro, por entre la que asoman sus "
                    "ojos siempre abiertos y en busca de una posible v�ctima.\n"
                    " Sus manos y pies, provistos de grandes garras que h�bilmente "
                    "utiliza como arma, hacen a�n mas amenazante su apariencia.\n");
                    break;
                case 2:
                    SetLong("Un horrible ogro, el doble del tama�o de un humano, tanto "
                    "de alto como de ancho.\n  En su espesa barba, as� como en las "
                    "garras de sus manos y pies puedes ver manchas de sangre, resto "
                    "de alguna cacer�a reciente.\n Aunque en apariencia es una criatura "
                    "torpe, se deduce que su falta de agilidad es sustituida por una "
                    "extraordinaria fuerza.\n");
                    break;
            }
            break;
        case 2:
            SetStandard("una ogra","ogro",([ GC_LUCHADOR:55+d8()]),GENERO_FEMENINO);
            SetShort("una ogra de las cavernas");
            AddId("ogra");
            switch(d2()){
                case 1:
                    SetLong("Tiene un tama�o algo menor a sus cong�neres masculinos,"
                    " pero la misma mirada voraz y sedienta de sangre que �stos.\n  Su "
                    "pelaje es de un color gris�ceo y su cuello est� adornado por "
                    "peque�os collares de huesos, seguramente de sus v�ctimas m�s "
                    "peque�as.\n");
                    break;
                case 2:
                    SetLong("Es una hembra de ogro, de un tama�o algo menor que los "
                    "machos.\n  Tiene una estructura similar a un humano, aunque "
                    "su cabeza es desproporcionadamente grande. Su rostro muestra una "
                    "sonrisa mal�fica y burlona, y sus garras, que constantemente "
                    "afila en las piedras de su caverna, siempre parecen listas para "
                    "un nuevo combate.\n");
                    break;
            }
            break;
    }
    SetGoChance(100);
    AddWalkZones(POMARHAB);
}

