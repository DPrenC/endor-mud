/*
DESCRIPCION  : Mikrun, el secretario del ayuntamiento
FICHERO      : /d/simauria/comun/pnj/nyne/krigor/secretario.c
MODIFICACION : 26-11-01 [Chaos@Simauria]Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create() {
    ::create();
    SetStandard("Mikrun","humano",19,GENDER_MALE);
    SetShort("Mikrun, el secretario");
  SetLong("Es un peque�o humano que se refugia tras el mostrador del ayuntamiento, "
  "para desempe�ar su labor con gran dignidad. Tiene el pelo corto y moreno, la "
  "cara redondeada y una sonrisa un tanto estra�a.\n");

    SetIds(({"Mikrun","Mikrun","secretario","humano"}));

    InitChats(4,({
  "Mikrun exclama: '�Papeles, papeles y mas papeles!'\n",
  "Mikrun saca punta a un l�piz y contin�a repasando papeles.\n",
  "Mikrun se va al archivador y guarda all� varias carpetas.\n"
}) );

}
