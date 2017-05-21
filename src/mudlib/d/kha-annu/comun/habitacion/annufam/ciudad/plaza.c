/****************************************************************************
Fichero: plaza.c
Autor: Kastwey
Creación: 27/07/2005
Descripción: Plaza de Annufam
****************************************************************************/

#include "./path.h"
#include <ansi.h>


inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("la plaza Belthain");
    SetIntLong(W("Has llegado a la Plaza Belthain, nombre que recibe por el "
                 "rey que fundó esta ciudad. En mitad de la plaza puedes ver "
                 "una gran estatua enana. Al norte observas un edificio "
                 "con unas enormes puertas de entrada. La calle Thualin "
                 "discurre de este a oeste, mientras que al sur te diriges a "
                 "la Avenida Real.\n"));

    AddDetail(({"estatua","estatua enana"}),
              W("Es una estatua que representa a un enano con una gran "
                "hacha en las manos, y bajo él, arrodillado, un orco que "
                "según muestran sus facciones, pide misericordia. En el "
                "pedestal se puede ver una leyenda.\n"));

    AddDetail(({"leyenda","placa"}),
              "Es una leyenda en una placa dorada, quizá deberías "
              "leerla.\n");


    AddReadMsg(({"leyenda","placa"}),
               W("La leyenda reza: " + ANSI_BLUE + "Annufam, Ciudad-Cuartel "
                 "creada por el rey Belthain para un mejor dominio enano. "
                 "Larga vida a Kha-annu.\n" + ANSI_NORMAL));

    AddDetail("puertas",W("Son unas puertas bastante gruesas que dan entrada "
                          "al Centro de Adiestramiento de Guerreros "
                          "Enanos.\n"));

    AddSuelo();
    AddAntorchas();

    AddExit("sur",HAB_AVENIDA_ANNUFAM("avenida_05"));
    AddExit("entrar",HAB_PRIMERA_ANNUFAM("entrada"));
    AddExit("este",HAB_THUALIN_ANNUFAM("thualin_01"));
    AddExit("oeste",HAB_THUALIN_ANNUFAM("thualin_05"));
    AddItem(PNJ_CIUDAD_ANNUFAM("bleni"),REFRESH_DESTRUCT,1);
    AddItem(PNJ_CIUDAD_ANNUFAM("posadera"),REFRESH_DESTRUCT,1);
    AddItem(PNJ_CIUDAD_ANNUFAM("moili"),REFRESH_DESTRUCT,1);
}
