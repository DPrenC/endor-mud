/****************************************************************************
Fichero: workroom.c
Autor: Riberales
Fecha: 06/05/2006
Descripción: Workroom de Riberales.
****************************************************************************/


#include "path.h"


inherit ROOM;

create()
{
    ::create();

    SetIntShort("el picadero de Riberales");
    SetIntLong("Te encuentras en los aposentos personales de la Infanta "
               "Riberales. La habitación está repleta de diversos cuadros "
               "representando diferentes escenas. En la pared este observas "
               "una mesa donde la draconiana diseña la ampliación  del mundo, "
               "y justo en frente un retrato a tamaño natural. Al sur hay una "
               "pesada puerta que lleva a la torre de los Wizards.\n");

    AddDetail(({"cuadros","cuadro","pintura","pinturas"}),
                "Son diversas pinturas que representan múltiples escenas de "
                "la vida de la Infanta, así como algunos paisajes.\n");

    AddDetail(({"paisaje","paisajes"}),
                "Son paisajes de bosques idílicos y bucólicos, y apacibles pastos.\n");

    AddDetail("retrato","Es el retrato de Nyh.\n");

    AddDetail(({"Nyh","nyh"}),"¡Es Nyh!\n");

    AddDetail(({"puerta","pesada puerta","puerta pesada"}),
                "Es una pesada puerta de madera con cerrojos de acero para "
                "que la integridad física de la Infanta no se vea violada. En "
                "el centro observas clavado un diploma.\n");

    AddDetail(({"mesa"}),
                "Es una mesa donde Riberales se sienta a diseñar las nuevas "
                "zonas que luego creará de la nada.\n");

    AddDetail(({"diploma","papel","pergamino"}),
                "Es un diploma hecho con pergamino. Podrías leerlo.\n");

    AddReadMsg(({"pergamino","papel","diploma"}),
                 "***\n\nDiploma de ascenso a Wizard.\n\nPor la presente, y a "
                 "día 6 de mayo del año del señor de 495, la aprendiz "
                 "Riberales es ascendida a wizard por sus méritos en la "
                 "creación del mundo de Simauria.\n\n****\n");

    SetIntBright(45);
    SetIntSmell("La habitación huele a marihuana en estado puro.\n");

    AddExit("torre", TORRE("piso1/center"));

}
