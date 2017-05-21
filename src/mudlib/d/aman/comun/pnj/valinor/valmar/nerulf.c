/***************************************************************************************
 ARCHIVO:       Nerulf.c
 AUTOR:         Ztico
 FECHA:         19-04-2005
 COMENTARIOS:   Nerulf, cocinero del Unicornio Azul.
 ***************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>
#include <colours.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("nerulf", "humano", ([GC_NINGUNO: 20 + d6()]), GENERO_MASCULINO);
    SetShort("nerulf, el cocinero");
    SetLong("Nerulf es el cocinero del Unicornio Azul. Se trata de un humano no muy "
        "alto pero sí fornido y membrudo, de rostro afilado y nariz abultada. Su cabello "
        "negro y ralo parece demasiado hirsuto para ser peinado. Tiene los ojos pequeños, "
        "muy juntos y hundidos pero su mirada aviesa denota inteligencia y percibes en "
        "ella un matiz inquietante que te impulsa a permanecer alerta, preguntándote si "
        "no estarás delante de uno de esos cocineros que sirven el vino aguado y gato por "
        "liebre a fin de embolsarse unas ganancias adicionales...\n");
    AddId("cocinero");
    InitChats(4, ({TC_TEL_WHO "Nerulf dice:" TC_TEL_MSG " ¿Qué demonios es un logath?\n" 
    	             TC_NORMAL,
    	             TC_TEL_WHO "Nerulf dice:" TC_TEL_MSG " ¿Te apetece tomar algo?\n" 
    	             TC_NORMAL}));
}
