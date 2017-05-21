/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"La calle es muy estrecha, apenas mide la anchura de un carro. Las casas de\n\
ambos lados parecen haber sido abandonadas de forma repentina y desvalijadas\n\
posteriormente. Una extraña fuerza te induce a seguir al Norte, aunque no\n\
ves nada por la oscuridad. Si prefieres también puedes ir al Sur.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes como un murmullo proveniente del Sur.\n");
 SetIntSmell("No puedes relacionar el olor con nada ya que es bastante extraño.\n");

 AddDetail(({"casa","casas"}),
"El estado de todas ellas es bastante lamentable.\n");

 AddExit("sur",CROWY("calle14"));
 AddExit("norte",CROWY("frobbon"));

 SetLocate("Crowy");
}
