
/*=======================================================================*
 |                  <<   Gremio de las Amazonas   >>                     |
 *=======================================================================*
 | [w] Woo@simauria                                                      |
 | [a] Avengelyne@simauria                                               |
 |                                                                       |
 | 09-10-98 [w] Creación de este archivo.                                |
 | 10-03-99 [w] Añadida la nueva definición de las habilidades.          |
 | 23-03-99 [w] Ahora es el gremio de las kisalas, cambiadas las         |
 |              definiciones al respecto.                                |
 | 19-11-99 [w] Ahora ya está la parte nueva del gremio.                 |
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

    SetIntShort("el salón de reuniones de las Kisalas");
    SetIntLong("Te encuentras en una habitación enormemente grande y de forma "
               "hexagonal. Justamente en el centro de la misma, puedes ver "
               "grabado el símbolo de las Kisalas. Las paredes están llenas de "
               "retratos y tapices de las Kisalas que contribuyeron al esplendor "
               "de la Orden. En la pared oeste, observas una escalinata "
               "de piedra que conduce a un trono. Encima del mismo hay un "
               "retrato de Shalei Kisala, la fundadora de la Orden. Aquí se "
               "reúnen las Kisalas cuando hay algún tema importante que "
               "tratar, y donde se inician y ascienden de nivel "
               "las que ya forman parte de la orden. En la pared norte se "
               "encuentra la entrada al templo del gremio, mientras que hacia "
               "el sur te diriges al vestíbulo.\n");

    SetIntBright(45);
    AddDetail(({"trono"}), "Ves un trono magnífico hecho de madera y tapizado "
               "en brocado de seda.\n");

    AddDetail(({"escaleras","escalinata","escalera"}),
               "Ves unas escaleras de piedra situadas en forma de media luna, "
               "con una alfombra roja que conducen a la parte principal de la "
               "sala.\n");

    AddDetail(({"shalei","Shalei","kisala","Kisala"}),
               "Ves el retrato  de Shalei Kisala, una mujer maravillosa llena "
               "de fuerza interior y astucia, inteligencia y belleza. Incluso "
               "ahora, y sabiendo que ella está muerta, es tal el poder que "
               "emana del retrato que te sientes sobrecogida.\n");

    AddDetail(({"retratos","relieves","tapices"}),
               "Ves muchos retratos y tapices por toda la habitación, todos "
               "ellos de Kisalas célebres. La inmensa mayoría pertenecen a "
               "elfas, aunque hay algunas humanas, y también de otras razas. "
               "Aunque el que más te llama la atención es el de Shalei Kisala, "
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
