#include "path.h"
inherit KHA_ROOM;

create() {
   ::create();
SetIntShort("un puesto de vigilancia");

SetIntLong(
"Este es el puesto de vigilancia del castillo. Pasando este lugar hacia el sur "
"puedes ir a las mazmorras del Castillo Kha-annu, a la cocina o al basurero "
"donde permanece la basura hasta que es arrojada al exterior del palacio.\n");

SetIntBright(90);

AddExit("sur", PISO1+"bajada");
AddExit("nordeste", PISO1+"patio8");
AddExit("noroeste", PISO1+"patio5");

AddDetail(({"puesto","puesto de vigilancia","vigilancia","puesto vigilancia"}),
"El puesto de vigilancia no tiene nada en especial.\n");
AddDetail(({"mazmorra",",mazmorras"}),
"Hacia el sur hay unas sucias escaleras que bajan a las mazmorras del castillo.\n");
AddDetail(({"escalera","escaleras"}),
"Solo son las sucias escaleras que bajan a las mazmorras.\n");
SetIntSmell(
"Un olor a podredumbre viene del sur... Parece ser del basurero del castillo...\n");
}