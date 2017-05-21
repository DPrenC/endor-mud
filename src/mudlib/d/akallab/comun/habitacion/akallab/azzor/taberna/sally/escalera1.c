/*
DESCRIPCION : en la taberna de Sally la gorda el puerto de Azzor
FICHERO     : /d/akallab/comun/habitaci�n/akallab/
              azzor/taberna/sally/escalera1.c
MODIFICACION: 10-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <door.h>
#include <properties.h>
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("el rellano de la taberna de Sally la gorda");
    SetIntLong("Est�s junto a una abertura en el suelo en el extremo de un pasillo que permite "
        "acceder a varias habitaciones. A trav�s de esa abertura y por medio de una escalera de "
        "gruesos pelda�os de madera se puede bajar a la planta inferior del edificio.\n");
    AddDetail(({"pasillo"}),"Est�s en �l.\n");
    AddDetail(({"abertura","escalera"}),"Hay una abertura en el suelo en el extremo del "
        "pasillo. A trav�s de ella llega la escalera que permite bajar a la planta inferior de "
        "este edificio.\n");
    SetIntNoise("Oyes lejano el ambiente de la taberna.\n");
    SetIntSmell("Huele a madera h�meda.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que est�n a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Sally aparece viniendo del piso de abajo, te mira un momento y te dice: �Y "
        "bien? �Piensas quedarte a dormir conmigo? Me encantar�a, pero hoy no es mi d�a, as� "
        "que ya te est�s largando.\nViendo la expresi�n de su cara, decides no hac�rtelo "
        "repetir, y a toda prisa, bajas la escalera y abandonas el local.\n");
    AddExit("norte","trastero");
    AddExit("este","pasillo");
    AddExit("abajo","escalera0");
    AddDoor("norte","la puerta del trastero",
        "Apenas un tabl�n de madera, viejo y desvencijado.\n",
        ({"puerta","puerta trastero","puerta de trastero","puerta del trastero"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
}
