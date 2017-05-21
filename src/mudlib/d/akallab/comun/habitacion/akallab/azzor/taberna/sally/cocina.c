 /*
DESCRIPCION : en el salon cocina de la taberna de Sally la gorda
FICHERO     : /d/akallab/comun/habitación/akallab/
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
    SetIntShort("el salón-cocina de la taberna de Sally la gorda");
    SetIntLong("El ambiente es agradable en este salón-cocina en el que te encuentras. En la "
        "pared Sur de la habitación hay una pequeña chimenea en la que arde lentamente un "
        "fuego cuyo calor caldea el ambiente y hace hervir el contenido de una olla. Adosado a "
        "la pared Este de la habitación se halla un largo banco de madera, y frente a él una "
        "mesa redonda.\nA través de la ventana puedes ver la bahía del puerto.\n");
    AddDetail(({"ventana"}),"La ventana se encuentra en la pared Este de la habitación. A "
        "través de ella puedes ver la bahía del puerto y los barcos en ella fondeados.\n");
    AddDetail(({"bahia","bahía","barcos"}),"En la bahía que forma el puerto se pueden observar "
        "multitud de barcos fondeados. Algunos de ellos están en medio de la bahía, mientras "
        "que otros se hallan atracados junto al muelle.\n");
    AddDetail(({"mesa"}),"Junto al banco y frente a la chimenea se halla una mesa circular de "
        "mediano tamaño.\n");
    AddDetail(({"banco"}),"Es un largo banco de madera donde sentarse. Está colocado junto a "
        "la chimenea, al agradable calor del fuego.\n");
    AddDetail(({"chimenea"}),"La chimenea de piedra está adosada a la pared Sur de la "
        "habitación. En ella arde lentamente un agradable fuego que calienta el ambiente y la "
        "olla que hay sobre él.\n");
    AddDetail(({"olla","hervido"}),"¡Parece que Sally prepara la comida! Una olla de metal de "
        "mediano tamaño cuelga sobre el fuego de la chimenea. En este momento se está cociendo "
        "en ella lo que parece un hervido a fuego lento.\n");
    AddDetail(({"pasillo"}),"Queda al Oeste de aquí.\n");
    SetIntNoise("Oyes el borboteo del hervido en la olla.\n");
    SetIntSmell("Huele a grasa y a ahumado.\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que están a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Sally aparece viniendo desde el pasillo, te mira un momento y te dice: ¿Y "
        "bien? ¿Piensas quedarte a dormir conmigo? Me encantaría, pero hoy no es mi día, así "
        "que ya te estás largando.\nViendo la expresión de su cara, decides no hacértelo "
        "repetir, y a toda prisa, bajas la escalera y abandonas el local.\n");
    AddExit("norte","habitacion1");
    AddExit("oeste","pasillo");
    AddDoor("norte","la puerta del dormitorio","Es la puerta del dormitorio de Sally, más "
        "testimonial que efectiva, ya que no es más que una plancha de madera no muy gruesa, "
        "ligeramente barnizada y decorada.\n",
        ({"puerta","puerta de dormitorio","puerta del dormitorio","puerta dormitorio"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
    SetSoundEnvironment(SND_AMBIENTES("chimenea"),90);
}
