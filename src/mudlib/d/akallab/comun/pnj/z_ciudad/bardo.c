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
    SetLong("Aiumi es un medio elfo de mediana estatura y m�s bien delgado. Bajo una ra�da "
        "capa de viaje, se adivinan unas ropas de colores que ahora no son mas que un reflejo "
        "de lo que una vez debieron ser. Su gesto es algo melanc�lico, y sus ojos parecen "
        "haber visto mucho mundo. Utiliza un la�d como instrumento.\n");
    AddId("bardo", "Aiumi", "aiumi","medio elfo");
    SetAlign(50);
    Set(P_NOGET,"Aiumi se revuelve y te pega con el la�d en la cabeza.\n");
    InitChats(7,({"Aiumi toma un sorbo de agua.\n",
        "Aiumi dice: Esta canci�n es antigua, bueno... es antigua en el lugar del que yo vengo. "
            "Espero que os guste. A continuaci�n comienza a cantar.\n",
        "Aiumi ajusta y afina las cuerdas del la�d.\n",
        "Aiumi comienza a tocar una triste melod�a con el la�d.\n",
        "Aiumi toca y canta una de tus canciones favoritas.\n",
        "Aiumi pregunta al p�blico: �Alguna petici�n?\n",
        "Aiumi canta: ...pobre de m�, triste bardo errante,\nque un lejano d�a dej� su hogar,\n"
            "�volver� a verte, Leewin hechizante?\nNing�n otro lugar podr� tanto a amar...'\n",
        "Aiumi toca una bella melod�a.\n",
        "Aiumi canta una p�cara y lasciva canci�n.\n",
        "Aiumi dice: �Venga, todos juntos!\n"}));
}
