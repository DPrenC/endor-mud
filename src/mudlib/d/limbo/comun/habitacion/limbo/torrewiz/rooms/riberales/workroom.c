/****************************************************************************
Fichero: workroom.c
Autor: Riberales
Fecha: 06/05/2006
Descripci�n: Workroom de Riberales.
****************************************************************************/


#include "path.h"


inherit ROOM;

create()
{
    ::create();

    SetIntShort("el picadero de Riberales");
    SetIntLong("Te encuentras en los aposentos personales de la Infanta "
               "Riberales. La habitaci�n est� repleta de diversos cuadros "
               "representando diferentes escenas. En la pared este observas "
               "una mesa donde la draconiana dise�a la ampliaci�n  del mundo, "
               "y justo en frente un retrato a tama�o natural. Al sur hay una "
               "pesada puerta que lleva a la torre de los Wizards.\n");

    AddDetail(({"cuadros","cuadro","pintura","pinturas"}),
                "Son diversas pinturas que representan m�ltiples escenas de "
                "la vida de la Infanta, as� como algunos paisajes.\n");

    AddDetail(({"paisaje","paisajes"}),
                "Son paisajes de bosques id�licos y buc�licos, y apacibles pastos.\n");

    AddDetail("retrato","Es el retrato de Nyh.\n");

    AddDetail(({"Nyh","nyh"}),"�Es Nyh!\n");

    AddDetail(({"puerta","pesada puerta","puerta pesada"}),
                "Es una pesada puerta de madera con cerrojos de acero para "
                "que la integridad f�sica de la Infanta no se vea violada. En "
                "el centro observas clavado un diploma.\n");

    AddDetail(({"mesa"}),
                "Es una mesa donde Riberales se sienta a dise�ar las nuevas "
                "zonas que luego crear� de la nada.\n");

    AddDetail(({"diploma","papel","pergamino"}),
                "Es un diploma hecho con pergamino. Podr�as leerlo.\n");

    AddReadMsg(({"pergamino","papel","diploma"}),
                 "***\n\nDiploma de ascenso a Wizard.\n\nPor la presente, y a "
                 "d�a 6 de mayo del a�o del se�or de 495, la aprendiz "
                 "Riberales es ascendida a wizard por sus m�ritos en la "
                 "creaci�n del mundo de Simauria.\n\n****\n");

    SetIntBright(45);
    SetIntSmell("La habitaci�n huele a marihuana en estado puro.\n");

    AddExit("torre", TORRE("piso1/center"));

}
