 /*
DESCRIPCION : en la taberna de Sally la gorda el puerto de Azzor
FICHERO     : /d/akallab/comun/habitaci�n/akallab/
              azzor/taberna/sally/pasillo.c
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
    SetIntShort("el pasillo de la taberna de Sally la gorda");
    SetIntLong("Te hallas en medio de un pasillo que permite acceder a varias habitaciones. En "
        "el extremo del pasillo, al Oeste, una escalera permite bajar al piso inferior. El "
        "suelo de madera del pasillo, aunque aparentemente resistente, cruje a cada paso que "
        "se da sobre �l.\n");
    AddDetail(({"pasillo"}),"Est�s en �l.\n");
    AddDetail(({"suelo"}),"La madera del suelo est� ya tan vieja, que cruje con cada paso que "
        "d�s.\n");
    AddDetail(({"abertura","escalera"}),"Hay una abertura en el suelo en el extremo del "
        "pasillo. A trav�s de ella llega la escalera que permite bajar a la planta inferior de "
        "este edificio.\n");
    SetIntNoise("Oyes lejano el ambiente de la taberna.\n");
    SetIntSmell("Huele a madera humeda.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que est�n a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Sally aparece viniendo desde la escalera, te mira un momento y te dice: �Y "
        "bien? �Piensas quedarte a dormir conmigo? Me encantar�a, pero hoy no es mi d�a, as� "
        "que ya te est�s largando.\nViendo la expresi�n de su cara, decides no hac�rtelo "
        "repetir, y a toda prisa, bajas la escalera y abandonas el local.\n");
    AddExit("norte","habitacion0");
    AddExit("este","cocina");
    AddExit("oeste","escalera1");
    AddDoor("norte","la puerta de la habitaci�n","Es la puerta de la habitaci�n, m�s "
        "testimonial que efectiva, ya que no es m�s que una plancha de madera no muy gruesa, "
        "ligeramente barnizada y decorada.\n",
        ({"puerta","puerta habitaci�n","puerta de habitaci�n","puerta de la habitaci�n",
            "puerta habitacion","puerta de habitacion","puerta de la habitacion"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
}
