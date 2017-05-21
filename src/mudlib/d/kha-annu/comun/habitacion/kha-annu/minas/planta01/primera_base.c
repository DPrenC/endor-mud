/**************************************************************************
fichero: primera_base.c
Autor: Riberales
Creaci�n: 18/10/05
Descripci�n: Room base en el primer piso.
**************************************************************************/


#include "path.h"

inherit BASE_MINAS;
string escuchar();
string oler();



create()
{
    ::create();
    planta = "primera";

    SetIntSmell(oler());
    SetIntNoise(escuchar());

}

public void AddGuardia()
{
    if (d3() == 1) AddItem(PNJ_MINAS("guardia_hierro"),REFRESH_DESTRUCT);
}


string oler()
{
    if (p_antorchas)
    {
        return "Hueles el combustible quemado proveniente de las antorchas.\n";
    }
    string msg;
    switch (d3())
    {
        case 1:
            msg="No diferencias ning�n olor fuera de lo normal.\n";
            break;
        case 2:
            msg="Percibes un olor a lugar cerrado, por otra parte l�gico "
                   "estando en el interior de unas minas.\n";
            break;
        case 3:
            msg="Hueles el olor lejano del combustible de alguna "
                   "antorcha.\n";
            break;
    }
    return msg;
}

string escuchar()
{
    if (p_antorchas)
    {
        return "Escuchas el crepitar del fuego que hay en las antorchas.\n";
    }
    string msg;
    switch (d3())
    {
        case 1:
            msg="Escuchas de vez en cuando alg�n pico contra las paredes "
                   "de las minas.\n";
            break;
        case 2:
            msg="Escuchas el crepitar del fuego de alguna antorcha "
                   "lejana.\n";
            break;
        case 3:
            msg="Escuchas algunos pasos perdidos por estas minas, y en "
                   "ocasiones, alg�n pico estamp�ndose contra la roca.\n";
            break;
    }
    return msg;
}
