 /*
DESCRIPCION : en el salon cocina de la taberna de Sally la gorda
FICHERO     : /d/akallab/comun/habitaci�n/akallab/
              azzor/taberna/sally/cocina.c
MODIFICACION: 10-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <sounds.h>
#include <door.h>
#include <properties.h>

inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("el sal�n-cocina de la taberna de Sally la gorda");
    SetIntLong("El ambiente es agradable en este sal�n-cocina en el que te encuentras. En la "
        "pared Sur de la habitaci�n hay una peque�a chimenea en la que arde lentamente un "
        "fuego cuyo calor caldea el ambiente y hace hervir el contenido de una olla. Adosado a "
        "la pared Este de la habitaci�n se halla un largo banco de madera, y frente a �l una "
        "mesa redonda.\nA trav�s de la ventana puedes ver la bah�a del puerto.\n");
    AddDetail(({"ventana"}),"La ventana se encuentra en la pared Este de la habitaci�n. A "
        "trav�s de ella puedes ver la bah�a del puerto y los barcos en ella fondeados.\n");
    AddDetail(({"bahia","bah�a","barcos"}),"En la bah�a que forma el puerto se pueden observar "
        "multitud de barcos fondeados. Algunos de ellos est�n en medio de la bah�a, mientras "
        "que otros se hallan atracados junto al muelle.\n");
    AddDetail(({"mesa"}),"Junto al banco y frente a la chimenea se halla una mesa circular de "
        "mediano tama�o.\n");
    AddDetail(({"banco"}),"Es un largo banco de madera donde sentarse. Est� colocado junto a "
        "la chimenea, al agradable calor del fuego.\n");
    AddDetail(({"chimenea"}),"La chimenea de piedra est� adosada a la pared Sur de la "
        "habitaci�n. En ella arde lentamente un agradable fuego que calienta el ambiente y la "
        "olla que hay sobre �l.\n");
    AddDetail(({"olla","hervido"}),"�Parece que Sally prepara la comida! Una olla de metal de "
        "mediano tama�o cuelga sobre el fuego de la chimenea. En este momento se est� cociendo "
        "en ella lo que parece un hervido a fuego lento.\n");
    AddDetail(({"pasillo"}),"Queda al Oeste de aqu�.\n");
    SetIntNoise("Oyes el borboteo del hervido en la olla.\n");
    SetIntSmell("Huele a grasa y a ahumado.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que est�n a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Sally aparece viniendo desde el pasillo, te mira un momento y te dice: �Y "
        "bien? �Piensas quedarte a dormir conmigo? Me encantar�a, pero hoy no es mi d�a, as� "
        "que ya te est�s largando.\nViendo la expresi�n de su cara, decides no hac�rtelo "
        "repetir, y a toda prisa, bajas la escalera y abandonas el local.\n");
    AddExit("norte","habitacion1");
    AddExit("oeste","pasillo");
    AddDoor("norte","la puerta del dormitorio","Es la puerta del dormitorio de Sally, m�s "
        "testimonial que efectiva, ya que no es m�s que una plancha de madera no muy gruesa, "
        "ligeramente barnizada y decorada.\n",
        ({"puerta","puerta de dormitorio","puerta del dormitorio","puerta dormitorio"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
    SetSoundEnvironment(SND_AMBIENTES("chimenea"),90);
}
