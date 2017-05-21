/****************************************************************************
Fichero: destornillador.c
Autor: Tagoras
Fecha: 20/03/2009
Descripción: Destornillador para salir del foso de Annufam
****************************************************************************/

inherit THING;

#include <materials.h>

public void create()
{
    ::create();
    SetShort("un destornillador");
    SetLong("Se trata de un destornillador de hierro que debieron usar los operarios que instalaron las rejillas en el foso. Está algo oxidado pero crees que aún se le puede dar uso.\n");
	SetMaterial(M_HIERRO);
    SetValue(50);
    SetWeight(750);
    AddId(({"destornillador"}));
}
