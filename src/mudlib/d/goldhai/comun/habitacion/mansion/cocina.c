#include "./path.h"
#include <magia.h>

inherit GROOM;

create()
{
 ::create();
 SetIntShort("una cocina");
SetIntLong(
"La cocina de la mansión parece bien surtida. Multitud de armarios cuelgan de "
"las paredes donde ves todo tipo de botes, frascos y tarros. En el centro hay "
"un amplio banco de trabajo sobre el que cuelgan de una barra variados "
"instrumentos de cocina. Al fondo junto a la pared, una gran chimenea permite "
"cocinar varios platos a la vez.\n");

AddDetail(({"armarios"}),
"Cuelgan de las paredes y hacen las veces de despensa.\n");

AddDetail(({"banco"}),
"El amplio banco que hay en el centro de la cocina es donde se prepara la "
"comida.\n");

AddDetail(({"chimenea","brasas"}),
"Está al fondo de la cocina. En ella arden brasas lentamente.\n");

AddDetail(({"paredes","pared"}),
"Las paredes estan hechas con enormes bloques de piedra.\n");

 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(50);
 SetIntNoise("No oyes nada especial.\n");
 SetIntSmell("Hmm.. huele a comida.\n");

 SetTPort(TPORT_NO);
 AddExit("este",MANSION("entrada"));
 SetLocate("mansión de Hardester Rankomme");
}