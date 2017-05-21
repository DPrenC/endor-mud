/*
Fichero: cebadilla_mantecona.c
Autor: Aulë
Fecha: 09/04/2013
Descripción: el famoso posadero y propietario del Poney Pisador, Cebadilla Mantecona
Comentarios: futuro pnj que dará numerosos miniquest y misiones varias.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("Cebadilla", "humano", 14, GENDER_MALE);
    SetShort("Cebadilla Mantecona");
    SetLong("Beslow es el tabernero de esta famosa posada, aunque en realidad es el "
    "negocio de su padre.\n  Por su apariencia no te cabe duda que abusa de las  buenas "
    "comidas que se sirven en este lugar, puesto que el adjetivo de gordo se lo ha "
    "ganado a conciencia.\n");
    AddId(({"tabernero", "gordo", "posadero", "cebadilla", "mantecona}));
    Set(P_CANT_LURE,1);
    SetNoise("El posadero resopla mientras corre sin pausa de un lado a otro sirviendo "
    "a los clientes y dando órdenes a los demás empleados de la posada");
    SetWeight(96000);
        Set(P_CANT_STEAL, "El posadero te aparta de un manotazo y mientras se aleja "
        "apresurado hacia una de las mesas exclama por encima del hombro:\n"
        	"¡En Bree no queremos ladrones, lárguese o compórtese como una persona decente!\n");
        
    InitChats(2, ({
        }));
    SetSmell("Huele a humo, comida y cerveza.\n");
    SetShrugMsg("Beslow parece que no entiende.\n");
    AddQuestion(({"al", "al el kender", "kender", "Al"}), "Beslow dice: maldito kender,"
        "no para quieto ni un minuto, siempre de aquí para allá sin parar.\n  No me "
        "extrañaría que lo hayan echado de su tierra por su forma de ser.\n De todas "
        "formas ten cuidado con él, es muy amante de lo ajeno.\n", 1);
    AddQuestion("nandor", "Beslow dice: bonito pueblo éste, aunque últimamente tiene "
        "demasiado paso, pero aun así es bastante tranquilo.\n", 1);
    AddQuestion(({"comer", "comida"}), "Beslow te mira con mala cara y te dice: ¿y por "
        "qué me preguntas eso a mi?, no como tanto como te piensas.\n", 1);
    AddQuestion("castillo", "Beslow te dice: ten cuidado por esos parajes, los guardias "
    "del castillo no tienen buen humor.\n", 1);
    AddQuestion(({"boyc", "Boyc", "bardo", "música", "musica", "canciones"}),
    "El tabernero te dice: la verdad es que canta mal el condenado, y toca peor.\n  Lo "
    "tengo ahí porque a los clientes les gusta y se divierten con sus tonterías, pero "
    "de buena gana lo echaría a la calle.\n", 1);
    AddQuestion("padre", "Beslow dice: mi padre ya hace tiempo que está muy cansado y "
    "no puede atander la posada, así que me tengo que encargar yo del negocio familiar.\n", 1);
    AddQuestion(({"taberna", "posada", "negocio"}), "El tabernero dice: esta posada es "
    "el negocio familiar de varias generaciones, tenemos muchos clientes, además que "
    "Nandor últimamente es un sitio de mucho paso.\n", 1);
    SetCitizenship("bree");
}
public void init()
{
    ::init();
    call_out("saludo",1);
}

public void saludo(){
    if (TP->QueryIsPlayer() && !TP->QueryInvis())
    {
        write("El posadero se inclina en una profunda reverencia limpiándose las manos "
        "en el delantal mientras exclama: \n"
        	"¡Buenos días, pequeño señor, ¿en que puedo servirle?\n");
        say("La sirvienta mira con mala cara a "+CAP(TNAME)+" cuando entra en la "
        "habitación, quizá, al igual que tú, tampoco debería de estar aquí.\n", TP);
    }
    return 0;
}
