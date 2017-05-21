/*          templo3o.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-01
	    [Nemesis]
	    [Jessy] Castellanizaci�n del fichero y cambio de las descripciones
	            del templo que antes era una ermita
            [n] A�adido un puntito de exploraci�n por la paridilla del concesionario :)
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

string parida()
{
    TP->SetExplored();
    return "Es un confesionario, ��CONFESIONARIO, animal!!\n";
}

create()
{
    ::create();
    SetLocate("Cementerio de Nandor");
    SetPreIntShort("frente a");
    SetIntShort("un confesionario");
    SetIntLong("Ves el confesionario donde la gente se arrepiente de sus pecados.\nHacia el "
        "este ves los bancos para que la gente se siente, y el altar hacia el nordeste.\n");
    SetIndoors(1);
    SetIntBright(20);
    AddDetail("confesionario","Est� vac�o. No hay nadie confes�ndose ni confesando.\n");
    AddDetail(({"concesionario"}),SF(parida));
    AddDetail("altar","Es un altar. Tiene algunos s�mbolos grabados.\n");
    AddDetail("bancos","Son de madera, est�n vac�os y sirven para sentarse...\n");
    AddDetail("signos","No los entiendes. El tiempo los ha vuelto irreconocibles.\n");
    AddExit("este","templo3");
}

