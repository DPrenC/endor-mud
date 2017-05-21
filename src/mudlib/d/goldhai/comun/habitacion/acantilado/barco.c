
#include "./path.h"
#include <magia.h>

inherit GROOM;

create()
{
::create();
SetIndoors(0);
SetIntShort("la cubierta del barco");
SetIntLong(
"La cubierta del barco sobre la que te encuentras esta ligeramente inclinada "
"y todo lo que en ella había ha debido rodar y caer por la borda. El mastil "
"está roto y caido sobre el mar, las velas hechas jirones luchan con las "
"olas. Las viejas tablas de la cubierta crujen bajo tus pies y parecen a "
"punto de quebrarse en cualquier momento. El puente está destrozado pero aun "
"se puede ir al camarote de popa que queda al norte de aquí. La bodega parece "
"inundada pero podrías intentar bajar a ella.\n");

 SetTPort(TPORT_NO);
 ForbidAllMagic();

 AddExit("norte",ACANTILADO("camarote"));
 AddExit("abajo",ACANTILADO("bodega"));
 AddExit("este",ACANTILADO("playa_barco"));

 SetLocate("acantilado del suroeste de Goldhai");
}