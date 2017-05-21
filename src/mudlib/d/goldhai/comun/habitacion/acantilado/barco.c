
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
"y todo lo que en ella hab�a ha debido rodar y caer por la borda. El mastil "
"est� roto y caido sobre el mar, las velas hechas jirones luchan con las "
"olas. Las viejas tablas de la cubierta crujen bajo tus pies y parecen a "
"punto de quebrarse en cualquier momento. El puente est� destrozado pero aun "
"se puede ir al camarote de popa que queda al norte de aqu�. La bodega parece "
"inundada pero podr�as intentar bajar a ella.\n");

 SetTPort(TPORT_NO);
 ForbidAllMagic();

 AddExit("norte",ACANTILADO("camarote"));
 AddExit("abajo",ACANTILADO("bodega"));
 AddExit("este",ACANTILADO("playa_barco"));

 SetLocate("acantilado del suroeste de Goldhai");
}