/****************************************************************************
Fichero: destornillador.c
Autor: Tagoras
Fecha: 20/03/2009
Descripci�n: Destornillador para salir del foso de Annufam
****************************************************************************/

inherit THING;

#include <materials.h>

public void create()
{
    ::create();
    SetShort("un destornillador");
    SetLong("Se trata de un destornillador de hierro que debieron usar los operarios que instalaron las rejillas en el foso. Est� algo oxidado pero crees que a�n se le puede dar uso.\n");
	SetMaterial(M_HIERRO);
    SetValue(50);
    SetWeight(750);
    AddId(({"destornillador"}));
}
