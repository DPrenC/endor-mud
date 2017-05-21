/****************************************************************************
Fichero: r_almacen.c
Autor: Riberales
Fecha: 21/02/2006
Descripci�n: almac�n del centro.
[t] 2009/03/04: A�adido un armario, pero mejor hacerlo objeto como en /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/habitacion01.c
****************************************************************************/



#include "path.h"
#include <moving.h>

inherit HAB_PRIMERA_ANNUFAM("r_base");

int cmd_abrir(string str);

create()
{
    ::create();

    tipo_arma = ({"arma","armas"});

    SetIntShort("el almac�n de armas");
    SetIntLong("Has entrado en lo que tiene toda la pinta de ser un almac�n "
               "de armas. Aqu� es donde los reclutas guardan su equipamiento "
               "despu�s de su jornada de entrenamiento. De hecho ves alguna "
               "que otra arma colgada y tambi�n grandes armarios apoyados en "
               "las paredes.\n");

/*
    AddDetail(({"armario","armarios"}),
                "Son unos armarios en los que sospechas que se guardan las "
                "mejores armas del Centro. Parece que est�n fabricados con "
                "madera de muy buena calidad, as� es que no ser� f�cil "
                "abrirlos a las bravas.\n");
*/

    AddDetail(({"pared","paredes"}),
                "Ves colgadas varias de las armas que utilizan los enanos "
                "para entrenarse en el Centro, y tambi�n algunos armarios que "
                "parecen destinados a guardar parte del equipo de los "
                "guerreros.\n");


    AddDetail(({"arma","armas","armadura","armaduras"}),
                "Son las armas y armaduras que se utilizan para entrenar. "
                "Algunas est�n en buen estado, y otras est�n aqu� para "
                "ser reparadas en la herrer�a de Annufam.\n");

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
        write("Tripanain te grita: �Pero bueno! �Qu� pretendes hacer abriendo ese armario?\n");
        say("Tripanain le grita a "+ CAP(TNAME)+ ".\n");
        guardian->Kill(TP);
        return 1;
    }

	return 0;
}
*/
