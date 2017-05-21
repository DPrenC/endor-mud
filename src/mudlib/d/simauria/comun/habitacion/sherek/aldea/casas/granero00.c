/* Archivo        granero00.c
   Autor:         Yalin y Lug
   Fecha:         07/05/2006
   Descripci�n:   granero de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("ceroom");

create ()
{
    ::create();
    SetIntShort("un granero en la aldea de Sloch");
    SetIntLong("Est�s en el interior de un peque�o granero donde los "
        "aldeanos guardan parte del cereal y de las cosechas que se les dan "
        "como pago por su trabajo en la granja y en las tierras que "
        "pertenecen a la abad�a. Por todas partes puedes ver sacos de grano, "
        "de legumbres y dem�s alimentos almacenables en este tipo de sitios.\n");
    SetIntNoise("Escuchas como los roedores intentan entrar a toda costa aqu�.\n");
    SetIntSmell("Huele intensamente a cereales almacenados.\n");
    AddDetail(({"techo"}), "Est� construido de ca�as y maderas entretejidas.\n");
    AddDetail(({"paredes", "pared"}), "Son de gruesos maderos con hoquedades "
        "para que el aire pueda entrar y, de este modo, secar los cereales y "
        "legumbres que hay aqu�.\n");
    AddDetail(({"suelo"}), "Es de piedra y est� elevado sobre el nivel del "
        "suelo de la calle, para tratar de que las ratas y dem�s bichejos "
        "del campo no entren a darse un fest�n con lo que se guarda aqu� "
        "dentro.\n");
    AddDetail(({"sacos", "grano", "legumbres"}), "Son una buena cantidad de "
        "productos amontonados para ser consumidos durante las �pocas "
        "invernales.\n");
    AddExit("norte", SHERALD("calles/callejuela00"));
}
