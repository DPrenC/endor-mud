/****************************************************************************
Fichero: tabernera_crowy.c
Autor: Buh
Fecha: 07/09/2006
Descripci�n: la tabernera de la taberna de guerreros de crowy
****************************************************************************/



#include "path.h"
#include <properties.h>
#include <gremios.h>
#include DOM_SYS "crowiano.h"

inherit PNJ_CROWY("crowiano_civil_base");

create()
{
    ::create();
    AddId(({"tabernera", "gigante", "giganta", "guerrera", "maril", "Maril"}));
    SetStandard("Maril", "gigante", ([GC_GUERREROS:26]), GENDER_FEMALE);
    SetShort("maril la tabernera guerrera");
    SetLong("Maril es una guerrera gigante que, algo m�s inteligente que el resto de los "
        "de su raza, se le ocurri� montar esta taberna para que sus kolegas de gremio "
        "tuvieran un punto de reuni�n y contarse sus aventuras.\n  A�n dedic�ndose a "
        "servir cervezas a sus amigos los guerreros, no ha perdido las ganas de lucha y"
        " es de las primeras en apuntarse a cualquier aventura que le propongan.\n");
    SetEdad(MEDIANA);
    SetAlign(50);
    SetWeight(120000);
    SetSmell("Huele a lo t�pico en una taberna.\n");
    InitChats(2, ({"Maril sirve unas cervezas a unos guerreros.\n",
        "Maril te mira estudi�ndote.\n",
        "Maril limpia unos vasos.\n"}));
    InitAChats(25, ({"La gigante intenta aplastarte con su cuerpo.\n",
        "Maril grita euf�ricametne.\n",
        "Maril grita: �qu� poco me gustas!.\n"}));

}
