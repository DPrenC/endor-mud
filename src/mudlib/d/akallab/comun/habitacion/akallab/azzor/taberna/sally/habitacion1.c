 /*
DESCRIPCION : habitación en la taberna de Sally la gorda
FICHERO     : /d/akallab/comun/habitación/akallab/
              azzor/taberna/sally/habitacion1.c
MODIFICACION: 10-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("la habitación de Sally la gorda");
    SetIntLong("Te encuentras en una habitación de mediano tamaño que debe ser la de Sally, la "
        "propietaria de la taberna. El lugar está razonablemente limpio y la decoración es "
        "austera. Los muebles son prácticos y, aunque se ven envejecidos, no parece que Sally "
        "tenga intención de cambiarlos. Conociendo a Sally, piensas que es seguro que se habrá "
        "corrido aquí más de una juerga con algún amigo. A través de la ventana se ve la bahía "
        "del puerto.\n");
    AddDetail(({"muebles"}),"Los muebles son prácticos y están envejecidos y la cama está un "
        "poco desvencijada.\n");
    AddDetail(({"cama"}),"La cama de Sally. Mejor no quieras saber que ha pasado por ahí.\n");
    AddDetail(({"ventana"}),"La ventana se encuentra en la pared Este de la habitación. A "
        "través de ella puedes ver la bahía del puerto y los barcos en ella fondeados.\n");
    AddDetail(({"bahia","bahía","barcos"}),"En la bahía que forma el puerto se pueden observar "
        "multitud de barcos fondeados. Algunos de ellos están en medio de la bahía, mientras "
        "que otros se hallan atracados junto al muelle.\n");
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Huele a madera humeda.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que están a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Sally aparece viniendo de la cocina, te coge de un brazo y dice: ¿Qué "
        "demonios haces en mi habitación? Mañana hablaremos de ello, ahora fuera, que voy a "
        "dormir.\nY sin demasiadas ceremonias, te planta de un empujón en la cocina, donde por "
        "tu mala suerte, te encuentras a Nytjar que venía..., seguramente a dar las buenas "
        "noches a Sally, te coge del brazo sin demasiados miramientos, y con un '¡Fuera de "
        "aquí, impertinente!', te arrastra prácticamente a la calle.\n");
    SetNoSchedulerObject(1);
    AddExit("sur","cocina");
    AddDoor("sur","la puerta del dormitorio","Es la puerta del dormitorio de Sally, más "
        "testimonial que efectiva, ya que no es más que una plancha de madera no muy gruesa, "
        "ligeramente barnizada y decorada.\n",
        ({"puerta","puerta de dormitorio","puerta del dormitorio","puerta dormitorio"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
    //AddItem(MUEBLE("mesita_noche"),REFRESH_DESTRUCT,1);
    AddItem(MUEBLE("cofre_ropa"),REFRESH_DESTRUCT,1);
    AddItem(MUEBLE("armario_ropa"),REFRESH_DESTRUCT,1);
    //AddItem(MUEBLE("cama"),REFRESH_DESTRUCT,1);
}
