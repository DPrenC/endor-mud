 /*
DESCRIPCION : en la taberna de Sally la gorda el puerto de Azzor
FICHERO     : /d/akallab/comun/habitación/akallab/
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
        "se da sobre él.\n");
    AddDetail(({"pasillo"}),"Estás en él.\n");
    AddDetail(({"suelo"}),"La madera del suelo está ya tan vieja, que cruje con cada paso que "
        "dás.\n");
    AddDetail(({"abertura","escalera"}),"Hay una abertura en el suelo en el extremo del "
        "pasillo. A través de ella llega la escalera que permite bajar a la planta inferior de "
        "este edificio.\n");
    SetIntNoise("Oyes lejano el ambiente de la taberna.\n");
    SetIntSmell("Huele a madera humeda.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que están a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Sally aparece viniendo desde la escalera, te mira un momento y te dice: ¿Y "
        "bien? ¿Piensas quedarte a dormir conmigo? Me encantaría, pero hoy no es mi día, así "
        "que ya te estás largando.\nViendo la expresión de su cara, decides no hacértelo "
        "repetir, y a toda prisa, bajas la escalera y abandonas el local.\n");
    AddExit("norte","habitacion0");
    AddExit("este","cocina");
    AddExit("oeste","escalera1");
    AddDoor("norte","la puerta de la habitación","Es la puerta de la habitación, más "
        "testimonial que efectiva, ya que no es más que una plancha de madera no muy gruesa, "
        "ligeramente barnizada y decorada.\n",
        ({"puerta","puerta habitación","puerta de habitación","puerta de la habitación",
            "puerta habitacion","puerta de habitacion","puerta de la habitacion"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
}
