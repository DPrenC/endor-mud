/****************************************************************************
Fichero: cuerda_encarfiada.c
Autor: Kastwey
Fecha: 13/11/2005
Descripción: Cuerda con un garfio, para escalar las murallas de Annufam.
****************************************************************************/


inherit THING;

public void create()
{
    ::create();
    SetShort("una cuerda engarfiada");
    SetLong("Se trata de una gruesa cuerda de unos veinte metros de longitud. "
            "En uno de sus extremos puedes ver atado un gran garfio.\n");
    SetValue(720);
    SetWeight(2000);

    AddId(({"cuerda","cuerda engarfiada","cuerda_engarfiada"}));
}
