/**************************************************************************
fichero: tercera_base.c
Autor: Riberales
Creaci�n: 9/12/05
Descripci�n: Room base en el tercer piso.
**************************************************************************/


#include "path.h"

inherit BASE_MINAS;
string escuchar();
string oler();



create()
{
    ::create();
    planta = "tercera";
    SetIntSmell(oler());
    SetIntNoise(escuchar());

}

public void AddGuardia()
{
    if (d3() == 1) AddItem(PNJ_MINAS("guardia_mithril"),REFRESH_DESTRUCT);
}


string oler()
{
    string msg;
    if (p_antorchas)
    {
        return "Hueles el combustible quemado proveniente de las antorchas.\n";
    }

    switch (d4())
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
        case 4:
            msg="Percibes un fuerte ambiente de humedad y presientes que "
                   "habr� alg�n r�o subterr�neo cerca.";
            break;
    }
    return msg;
}

string escuchar()
{
    string msg;
    if (p_antorchas)
    {
        return "Escuchas el crepitar del fuego que hay en las antorchas.\n";
    }
    switch (d6())
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
            msg="Escuchas pasos lejanos por estas minas, y en "
                   "ocasiones, alg�n pico estamp�ndose contra la roca.\n";
            break;
        case 4:
            msg="Oyes ocasionalmente alguna gota cayendo al suelo.\n";
            break;
        case 5:
        case 6:
            msg="Oyes un tenue murmullo de agua, proveniente de alg�n r�o "
                   "subterr�neo.\n";
            break;
    }
    return msg;
}
