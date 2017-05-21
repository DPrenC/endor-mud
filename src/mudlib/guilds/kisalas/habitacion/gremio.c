
/*=======================================================================*
 |                  <<   Gremio de las Amazonas   >>                     |
 *=======================================================================*
 | [w] Woo@simauria                                                      |
 | [a] Avengelyne@simauria                                               |
 |                                                                       |
 | 09-10-98 [w] Creaci�n de este archivo.                                |
 | 10-03-99 [w] A�adida la nueva definici�n de las habilidades.          |
 | 23-03-99 [w] Ahora es el gremio de las kisalas, cambiadas las         |
 |              definiciones al respecto.                                |
 | 19-11-99 [w] Ahora ya est� la parte nueva del gremio.                 |
 *=======================================================================*/

#include "path.h"
#include <guild.h>
#include <skills.h>
#include <rooms.h>

inherit "/std/guild";

int cmd_join(string str)
{
    if (TP->QueryGender()!=2)
    {
        return notify_fail("Solo las mujeres pueden entrar a formar parte del "
                           "gremio de Kisalas!\n",NOTIFY_NOT_VALID);
    }
    return ::cmd_join(str);
}


public void create_ob()
{
    ::create_ob();

    SetIntShort("el sal�n de reuniones de las Kisalas");
    SetIntLong("Te encuentras en una habitaci�n enormemente grande y de forma "
               "hexagonal. Justamente en el centro de la misma, puedes ver "
               "grabado el s�mbolo de las Kisalas. Las paredes est�n llenas de "
               "retratos y tapices de las Kisalas que contribuyeron al esplendor "
               "de la Orden. En la pared oeste, observas una escalinata "
               "de piedra que conduce a un trono. Encima del mismo hay un "
               "retrato de Shalei Kisala, la fundadora de la Orden. Aqu� se "
               "re�nen las Kisalas cuando hay alg�n tema importante que "
               "tratar, y donde se inician y ascienden de nivel "
               "las que ya forman parte de la orden. En la pared norte se "
               "encuentra la entrada al templo del gremio, mientras que hacia "
               "el sur te diriges al vest�bulo.\n");

    SetIntBright(45);
    AddDetail(({"trono"}), "Ves un trono magn�fico hecho de madera y tapizado "
               "en brocado de seda.\n");

    AddDetail(({"escaleras","escalinata","escalera"}),
               "Ves unas escaleras de piedra situadas en forma de media luna, "
               "con una alfombra roja que conducen a la parte principal de la "
               "sala.\n");

    AddDetail(({"shalei","Shalei","kisala","Kisala"}),
               "Ves el retrato  de Shalei Kisala, una mujer maravillosa llena "
               "de fuerza interior y astucia, inteligencia y belleza. Incluso "
               "ahora, y sabiendo que ella est� muerta, es tal el poder que "
               "emana del retrato que te sientes sobrecogida.\n");

    AddDetail(({"retratos","relieves","tapices"}),
               "Ves muchos retratos y tapices por toda la habitaci�n, todos "
               "ellos de Kisalas c�lebres. La inmensa mayor�a pertenecen a "
               "elfas, aunque hay algunas humanas, y tambi�n de otras razas. "
               "Aunque el que m�s te llama la atenci�n es el de Shalei Kisala, "
               "situado encima del trono.\n");


    SetGuildclass(GC_KISALAS);
    SetGuildname("Gremio de las kisalas");
    SetGuildMaster("La Gran Kisala");
    SetGuildDomain("goldhai");

    SetCreators( ({"Woo","Avengelyne"}));
    SetGuildobject(AM_OBJETO("brazalete"));

    ForbidAllMagic();
    AddItem(AM_PNJ("shilda"), REFRESH_DESTRUCT, 1);
    AddRoomCmd("unirse", "cmd_join");

    AddExit("norte",AM_VARIOS("templo"));
    AddExit("sur",AM_VESTIBULO("vest4"));
}
