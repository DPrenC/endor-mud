/****************************************************************************
Fichero: bosque034.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+ " Notas la presencia de un r�o cercano y puedes ver que "
    "hacia el noroeste se abre un claro en el bosque.\n");
    AddExit("norte","./bosque029");
    AddExit("sur","./bosque040");
    AddExit("este","./bosque035");
    AddExit("nordeste", "./bosque030");
    AddExit("noroeste", "./bosque028");
}


