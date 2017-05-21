/*
        SIMAURIA [/guilds/hechiceros/hechiceros.c]
        ========

          [g] Guybrush (email: guybrush@simauria.upv.es)

	26/10/99 [g] Creaci�n.
*/

#include "path.h"
#include <guild.h>
#include <config.h>
#include <skills.h>
inherit "/std/guild";

create() {
   ::create();

   /* --- PARTE DE HABITACI�N --- */

   SetIntShort( "Gremio de Hechiceros" );
   SetIntLong("\
Est�s en el hall del Gremio de Hechiceros. La habitaci�n tiene forma de un\n\
cuarto de circunferencia. No hay muchas cosas interesantes, parece ser que\n\
se encuentra a�n por terminar.\n");
   SetIntBright( 50 );
   SetIndoors( 1 );
   AddExit("este","/guilds/guardabosques/gremio");
   AddExit("nordeste",H_HOME+"rooms/esca0");

   /* --- PARTE DE GREMIO --- */

   // Nombre, clase, creador/es...
   //
   SetGuildclass( GC_HECHICEROS );
   SetGuildname( "Gremio de Hechiceros" );
   SetGuildMaster("Nadie, por ahora");
   SetCreators( ({ "Guybrush","Maler" }) );
   SetGuildobject( H_OBJETO( "cayado" ) );
}
