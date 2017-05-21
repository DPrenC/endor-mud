/****************************************************************************
Fichero: r_almacen.c
Autor: Riberales
Fecha: 21/02/2006
Descripción: almacén del centro.
[t] 2009/03/04: Añadido un armario, pero mejor hacerlo objeto como en /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/habitacion01.c
****************************************************************************/



#include "path.h"
#include <moving.h>

inherit HAB_PRIMERA_ANNUFAM("r_base");

int cmd_abrir(string str);

create()
{
    ::create();

    tipo_arma = ({"arma","armas"});

    SetIntShort("el almacén de armas");
    SetIntLong("Has entrado en lo que tiene toda la pinta de ser un almacén "
               "de armas. Aquí es donde los reclutas guardan su equipamiento "
               "después de su jornada de entrenamiento. De hecho ves alguna "
               "que otra arma colgada y también grandes armarios apoyados en "
               "las paredes.\n");

/*
    AddDetail(({"armario","armarios"}),
                "Son unos armarios en los que sospechas que se guardan las "
                "mejores armas del Centro. Parece que están fabricados con "
                "madera de muy buena calidad, así es que no será fácil "
                "abrirlos a las bravas.\n");
*/

    AddDetail(({"pared","paredes"}),
                "Ves colgadas varias de las armas que utilizan los enanos "
                "para entrenarse en el Centro, y también algunos armarios que "
                "parecen destinados a guardar parte del equipo de los "
                "guerreros.\n");


    AddDetail(({"arma","armas","armadura","armaduras"}),
                "Son las armas y armaduras que se utilizan para entrenar. "
                "Algunas están en buen estado, y otras están aquí para "
                "ser reparadas en la herrería de Annufam.\n");

    AddVentanaN();

    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo02"));
	AddItem(OTRO_ANNUFAM("armario"), REFRESH_REMOVE);
	AddItem(PNJ_CENTRO_ANNUFAM("tripanain"), REFRESH_DESTRUCT);

    //AddRoomCmd("abrir", "cmd_abrir");
}

/*
// Ya lo hace el armario
int cmd_abrir(string str)
{
    object guardian;

    if (!str || str != "armario") return 0;

    if ((guardian = present("tripanain")) && living(guardian))
    {
        write("Tripanain te grita: ¡Pero bueno! ¿Qué pretendes hacer abriendo ese armario?\n");
        say("Tripanain le grita a "+ CAP(TNAME)+ ".\n");
        guardian->Kill(TP);
        return 1;
    }

	return 0;
}
*/
