/* Archivo        granero00.c
   Autor:         Yalin y Lug
   Fecha:         07/05/2006
   Descripción:   granero de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("ceroom");

create ()
{
    ::create();
    SetIntShort("un granero en la aldea de Sloch");
    SetIntLong("Estás en el interior de un pequeño granero donde los "
        "aldeanos guardan parte del cereal y de las cosechas que se les dan "
        "como pago por su trabajo en la granja y en las tierras que "
        "pertenecen a la abadía. Por todas partes puedes ver sacos de grano, "
        "de legumbres y demás alimentos almacenables en este tipo de sitios.\n");
    SetIntNoise("Escuchas como los roedores intentan entrar a toda costa aquí.\n");
    SetIntSmell("Huele intensamente a cereales almacenados.\n");
    AddDetail(({"techo"}), "Está construido de cañas y maderas entretejidas.\n");
    AddDetail(({"paredes", "pared"}), "Son de gruesos maderos con hoquedades "
        "para que el aire pueda entrar y, de este modo, secar los cereales y "
        "legumbres que hay aquí.\n");
    AddDetail(({"suelo"}), "Es de piedra y está elevado sobre el nivel del "
        "suelo de la calle, para tratar de que las ratas y demás bichejos "
        "del campo no entren a darse un festín con lo que se guarda aquí "
        "dentro.\n");
    AddDetail(({"sacos", "grano", "legumbres"}), "Son una buena cantidad de "
        "productos amontonados para ser consumidos durante las épocas "
        "invernales.\n");
    AddExit("norte", SHERALD("calles/callejuela00"));
}
