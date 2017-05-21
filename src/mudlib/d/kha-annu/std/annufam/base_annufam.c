/****************************************************************************
Fichero: base_annufam.c
Autor: Kastwey
Creaci�n: 25/07/2005
Descripci�n: Habitaci�n base para la zona de annufam
****************************************************************************/

#include "./path.h"
//#define SERVER_CLIMAS DOM_STD "annufam/server_climas"

inherit KHA_ROOM;

public varargs string enumerar(string *arr, int simplificar)
// pasado un array de cosas, devuelve la concatenaci�n de ellas, en el
// formato a, b, c y d.
// si se le pasa 1 en el segundo par�metro, adem�s de concatenarlos,
// ordena los elementos iguales del modo:
// a [3], b [4] y c.
{
    string *arr2 = ({}), ob;
    int num = sizeof(arr), num_ob;

    if (simplificar)
    {
        while (num)
        {
            ob = arr[0];
            arr -= ({ob});
            num_ob = num - (num = sizeof(arr));
            arr2 += ({ob + (num_ob > 1 ? " [" + num_ob + "]" : "")});
        }
        arr = arr2;
    }
    return implode(arr[0..<2],", ")+(sizeof(arr[0..<2])?" y ":"")+arr[<1];
}

public varargs int AddEstandarte(int tipo)
// a�ade un detalle con los diversos tipos de estandartes que existen en
// el dominio kha-annu
{
    string msg;
    switch(tipo)
    {
        case EST_NORMAL:
        // estandarte t�pico
            msg = W("Se trata de la ense�a del dominio de Kha-annu. En su parte "
                    "superior hay una corona de oro con cinco diamantes, que "
                    "representan las cinco ciudades del dominio enano, y en "
                    "la parte inferior un escudo con borde plateado y de fondo "
                    "verde sobre el que hay un le�n rampante que muestra sus "
                    "fauces desafiante, y que se encuentra flanqueado por "
                    "dos hachas enanas de empu�adura marr�n.\n");
            break;
        case EST_SALA:
        // estandarte para las salas
            msg = W("Ves colgadas algunas reproducciones de la ense�a oficial "
                    "del dominio de Kha-annu.\n");
            break;
        case EST_DESPACHO:
        // estandartes para el despacho del maestro
        // no se si lo tendr�n puesto een alg�n otro sitio
            msg = W("No te llama la atenci�n su forma sino los materiales con "
                    "los que est� fabricada. Todas las ense�as que has visto "
                    "hasta ahora han sido pinturas, tapices o grabados, pero "
                    "esta es una reproducci�n del escudo en oro, diamantes y "
                    "mithril... quien sabe si no ser� el escudo original de "
                    "Kha-annu.\n");
            break;
    }
    if (!msg) return 0;
    AddDetail(({"ense�a","estandarte","escudo","emblema"}),msg);
    return 1;
}

public void create()
{
    ::create();
    //SetServer(SERVER_CLIMAS);
    SetLocate("Annufam");
}
//public int AddNotification()
//{
    //return SERVER_ANNUFAM->AddNotification(object_name(TO));
//}

//public int RemoveNotification() { return SERVER_CLIMAS->RemoveNotification(TO); }


