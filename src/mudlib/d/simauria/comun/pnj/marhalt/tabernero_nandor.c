/****************************************************************************
Fichero: tabernero_nandor.c
Autor: Ratwor
Fecha: 03/08/2006
Descripción: un tabernero para la posada de Nandor
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("beslow", "humano", 15, GENDER_MALE);
    SetShort("el gordo tabernero");
    SetLong("Beslow es el tabernero de esta famosa posada, aunque en realidad es el "
    "negocio de su padre.\n  Por su apariencia no te cabe duda que abusa de las  buenas "
    "comidas que se sirven en este lugar, puesto que el adjetivo de gordo se lo ha "
    "ganado a conciencia.\n");
    AddId(({"tabernero", "gordo"}));
    Set(P_CANT_LURE,1);
    SetWeight(105000);
    InitChats(2, ({
        "Beslow se pone un trapo en el hombro que se le había caído.\n",
        "Beslow le da un buen mordisco a una pieza de pollo asado.\n",
        "Oyes que alguien grita desde el fondo: ¡tabernero más cerveza, pero esta vez "
        "de la buena!.\n",
        "Oyes crujir la madera cuando un cliente de la taberna pasa por tu lado.\n"}));
    InitAChats(10, ({"Beslow grita: te voy a aplastar.\n",
        "El gordo grita eufóricamente: ¡criminaaaal!\n"}));
    SetSmell("Huele a grasa de las comidas.\n");
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
    SetCitizenship("nandor");
}
