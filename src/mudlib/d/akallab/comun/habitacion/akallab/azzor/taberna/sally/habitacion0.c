 /*
DESCRIPCION : habitación en la taberna de Sally la gorda
FICHERO     : /d/akallab/comun/habitación/akallab/
              azzor/taberna/sally/habitacion0.c
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
    SetIntShort("la habitación de Nytjar");
    SetIntLong("Te encuentras en una habitación de mediano tamaño y no muy limpia. En ella hay "
        "únicamente una cama y una pequeña mesilla. La ventana de la pared Norte da a la callejuela "
        "que hay entre este edificio y el de la taberna del Tuerto.\n");
    AddDetail(({"cama"}), "Una cama bastante vieja y desvencijada.\n");
    AddDetail(({"mesilla"}), "Tres tablas de madera mal clavadas simulan lo que "
        "parece una mesilla.\n");
    AddDetail(({"ventana"}),"La ventana que se halla en el muro Norte de la habitación te "
        "permite ver la estrecha callejuela que hay entre este edificio y el de la taberna del "
        "Tuerto, que está en frente.\n");
    AddDetail(({"callejuela"}),"La callejuela avanza entre este edificio y el de en frente "
        "desde el puerto adentrándose en la ciudad.\n");
    AddDetail(({"edificio"}),"El edificio de en frente es la taberna del Tuerto.\n");
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Huele a madera húmeda.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que están a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Nytjar aparece de repente, te mira un momento, y lanzando un desagradable "
        "bufido, te coge del brazo diciendo: ¿Puede saberse qué demonios se te ha perdido en "
        "mi habitación, alimaña?\nY con toda la distinción de que es capaz, que no es mucha, "
        "te acompaña cortésmente hasta la puerta de la calle..., a puntapiés.\n");
    AddExit("sur","pasillo");
    AddDoor("sur","la puerta de la habitación","Es la puerta de la habitación de Nytjar, más "
        "testimonial que efectiva, ya que no es más que una plancha de madera no muy gruesa, "
        "ligeramente barnizada y decorada.\n",
        ({"puerta","puerta habitación","puerta de habitación","puerta de la habitación",
            "puerta habitacion","puerta de habitacion","puerta de la habitacion"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
    AddItem(MUEBLE("cofre_ropa"),REFRESH_DESTRUCT,1);
    AddItem(MUEBLE("armario_ropa"),REFRESH_DESTRUCT,1);
//AddItem(MUEBLE("cama"),REFRESH_DESTRUCT,1);
}
