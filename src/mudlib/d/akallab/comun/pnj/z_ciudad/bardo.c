/*
DESCRIPCION  : Aiumi, un bardo
FICHERO      : /d/akallab/comun/pnj/bardo.c
MODIFICACION : 24-04-98 [Angor@Simauria] Creacion
UPDATE       : 03-03-99 [Angor@Simauria] typos
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Aiumi","medio elfo",15,GENERO_MASCULINO);
    SetName("Aiumi");
    SetShort("Aiumi, el bardo errante");
    SetLong("Aiumi es un medio elfo de mediana estatura y más bien delgado. Bajo una raída "
        "capa de viaje, se adivinan unas ropas de colores que ahora no son mas que un reflejo "
        "de lo que una vez debieron ser. Su gesto es algo melancólico, y sus ojos parecen "
        "haber visto mucho mundo. Utiliza un laúd como instrumento.\n");
    AddId("bardo", "Aiumi", "aiumi","medio elfo");
    SetAlign(50);
    Set(P_NOGET,"Aiumi se revuelve y te pega con el laúd en la cabeza.\n");
    InitChats(7,({"Aiumi toma un sorbo de agua.\n",
        "Aiumi dice: Esta canción es antigua, bueno... es antigua en el lugar del que yo vengo. "
            "Espero que os guste. A continuación comienza a cantar.\n",
        "Aiumi ajusta y afina las cuerdas del laúd.\n",
        "Aiumi comienza a tocar una triste melodía con el laúd.\n",
        "Aiumi toca y canta una de tus canciones favoritas.\n",
        "Aiumi pregunta al público: ¿Alguna petición?\n",
        "Aiumi canta: ...pobre de mí, triste bardo errante,\nque un lejano día dejó su hogar,\n"
            "¿volveré a verte, Leewin hechizante?\nNingún otro lugar podré tanto a amar...'\n",
        "Aiumi toca una bella melodía.\n",
        "Aiumi canta una pícara y lasciva canción.\n",
        "Aiumi dice: ¡Venga, todos juntos!\n"}));
}
