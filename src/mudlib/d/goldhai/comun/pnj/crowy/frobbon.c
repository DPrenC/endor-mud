/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-02-99                |
 |               Ultima Modificacion.. 03-03-99                |
 |                                                             |
 | 03-03-99 [w] Ahora Frobbon ya no muere y además desaparece  |
 |              a los 2 minutos.                               |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


inherit NPC;

void desaparece()
{
 tell_room(TO,"Frobbon desaparece de forma instantánea.\n");
 call_out("remove",2);
}

create()
{
  ::create();
 SetStandard("Frobbon","enano",7,GENERO_MASCULINO);
 SetIds(({"frobbon","enano","frobbon el enano","Frobbon","fantasma","fantasma Frobbon"}));
 SetShort("Frobbon");
 SetAlign(100);
 SetWhimpy(0);
 call_out("desaparece",120); // Desaparece a los 2 minutos.
}

public varargs void Die(mixed silent)
{
 TO->SetHP(50);
 return 0;
}
