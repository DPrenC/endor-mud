 /*
DESCRIPCION : habitaci�n en la taberna de Sally la gorda
FICHERO     : /d/akallab/comun/habitaci�n/akallab/
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
    SetIntShort("la habitaci�n de Nytjar");
    SetIntLong("Te encuentras en una habitaci�n de mediano tama�o y no muy limpia. En ella hay "
        "�nicamente una cama y una peque�a mesilla. La ventana de la pared Norte da a la callejuela "
        "que hay entre este edificio y el de la taberna del Tuerto.\n");
    AddDetail(({"cama"}), "Una cama bastante vieja y desvencijada.\n");
    AddDetail(({"mesilla"}), "Tres tablas de madera mal clavadas simulan lo que "
        "parece una mesilla.\n");
    AddDetail(({"ventana"}),"La ventana que se halla en el muro Norte de la habitaci�n te "
        "permite ver la estrecha callejuela que hay entre este edificio y el de la taberna del "
        "Tuerto, que est� en frente.\n");
    AddDetail(({"callejuela"}),"La callejuela avanza entre este edificio y el de en frente "
        "desde el puerto adentr�ndose en la ciudad.\n");
    AddDetail(({"edificio"}),"El edificio de en frente es la taberna del Tuerto.\n");
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Huele a madera h�meda.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que est�n a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Nytjar aparece de repente, te mira un momento, y lanzando un desagradable "
        "bufido, te coge del brazo diciendo: �Puede saberse qu� demonios se te ha perdido en "
        "mi habitaci�n, alima�a?\nY con toda la distinci�n de que es capaz, que no es mucha, "
        "te acompa�a cort�smente hasta la puerta de la calle..., a puntapi�s.\n");
    AddExit("sur","pasillo");
    AddDoor("sur","la puerta de la habitaci�n","Es la puerta de la habitaci�n de Nytjar, m�s "
        "testimonial que efectiva, ya que no es m�s que una plancha de madera no muy gruesa, "
        "ligeramente barnizada y decorada.\n",
        ({"puerta","puerta habitaci�n","puerta de habitaci�n","puerta de la habitaci�n",
            "puerta habitacion","puerta de habitacion","puerta de la habitacion"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
    AddItem(MUEBLE("cofre_ropa"),REFRESH_DESTRUCT,1);
    AddItem(MUEBLE("armario_ropa"),REFRESH_DESTRUCT,1);
//AddItem(MUEBLE("cama"),REFRESH_DESTRUCT,1);
}
