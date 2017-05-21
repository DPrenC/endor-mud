/****************************************************************************
Fichero: gemin.c
Autor: Kastwey
Creación: 22/08/2005
Descripción: Gemin, la tendera de la tienda de ropa de Annufam
****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit NPC;

public void create()
{
    ::create();
    SetStandard("gemin","enano",11,GENDER_FEMALE);
    SetShort("Gemin, la tendera");
    SetLong(W("Teniendo en cuenta que los enanos no son muy agraciados "
              "estéticamente, Gemin es lo más parecido a una persona "
              "atractiva que has encontrado hasta ahora en Annufam. El "
              "cabello le llega hasta las posaderas, y lo lleva recogido en "
              "una graciosa trenza.\n"));

    AddId(({"tendera","enana"}));

}
