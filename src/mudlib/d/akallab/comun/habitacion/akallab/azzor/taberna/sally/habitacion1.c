 /*
DESCRIPCION : habitaci�n en la taberna de Sally la gorda
FICHERO     : /d/akallab/comun/habitaci�n/akallab/
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
    SetIntShort("la habitaci�n de Sally la gorda");
    SetIntLong("Te encuentras en una habitaci�n de mediano tama�o que debe ser la de Sally, la "
        "propietaria de la taberna. El lugar est� razonablemente limpio y la decoraci�n es "
        "austera. Los muebles son pr�cticos y, aunque se ven envejecidos, no parece que Sally "
        "tenga intenci�n de cambiarlos. Conociendo a Sally, piensas que es seguro que se habr� "
        "corrido aqu� m�s de una juerga con alg�n amigo. A trav�s de la ventana se ve la bah�a "
        "del puerto.\n");
    AddDetail(({"muebles"}),"Los muebles son pr�cticos y est�n envejecidos y la cama est� un "
        "poco desvencijada.\n");
    AddDetail(({"cama"}),"La cama de Sally. Mejor no quieras saber que ha pasado por ah�.\n");
    AddDetail(({"ventana"}),"La ventana se encuentra en la pared Este de la habitaci�n. A "
        "trav�s de ella puedes ver la bah�a del puerto y los barcos en ella fondeados.\n");
    AddDetail(({"bahia","bah�a","barcos"}),"En la bah�a que forma el puerto se pueden observar "
        "multitud de barcos fondeados. Algunos de ellos est�n en medio de la bah�a, mientras "
        "que otros se hallan atracados junto al muelle.\n");
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Huele a madera humeda.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que est�n a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Sally aparece viniendo de la cocina, te coge de un brazo y dice: �Qu� "
        "demonios haces en mi habitaci�n? Ma�ana hablaremos de ello, ahora fuera, que voy a "
        "dormir.\nY sin demasiadas ceremonias, te planta de un empuj�n en la cocina, donde por "
        "tu mala suerte, te encuentras a Nytjar que ven�a..., seguramente a dar las buenas "
        "noches a Sally, te coge del brazo sin demasiados miramientos, y con un '�Fuera de "
        "aqu�, impertinente!', te arrastra pr�cticamente a la calle.\n");
    SetNoSchedulerObject(1);
    AddExit("sur","cocina");
    AddDoor("sur","la puerta del dormitorio","Es la puerta del dormitorio de Sally, m�s "
        "testimonial que efectiva, ya que no es m�s que una plancha de madera no muy gruesa, "
        "ligeramente barnizada y decorada.\n",
        ({"puerta","puerta de dormitorio","puerta del dormitorio","puerta dormitorio"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
    //AddItem(MUEBLE("mesita_noche"),REFRESH_DESTRUCT,1);
    AddItem(MUEBLE("cofre_ropa"),REFRESH_DESTRUCT,1);
    AddItem(MUEBLE("armario_ropa"),REFRESH_DESTRUCT,1);
    //AddItem(MUEBLE("cama"),REFRESH_DESTRUCT,1);
}
