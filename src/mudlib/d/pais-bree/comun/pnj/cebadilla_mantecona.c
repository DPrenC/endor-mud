/*
Fichero: cebadilla_mantecona.c
Autor: Aul�
Fecha: 09/04/2013
Descripci�n: el famoso posadero y propietario del Poney Pisador, Cebadilla Mantecona
Comentarios: futuro pnj que dar� numerosos miniquest y misiones varias.
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
    "a los clientes y dando �rdenes a los dem�s empleados de la posada");
    SetWeight(96000);
        Set(P_CANT_STEAL, "El posadero te aparta de un manotazo y mientras se aleja "
        "apresurado hacia una de las mesas exclama por encima del hombro:\n"
        	"�En Bree no queremos ladrones, l�rguese o comp�rtese como una persona decente!\n");
        
    InitChats(2, ({
        }));
    SetSmell("Huele a humo, comida y cerveza.\n");
    SetShrugMsg("Beslow parece que no entiende.\n");
    AddQuestion(({"al", "al el kender", "kender", "Al"}), "Beslow dice: maldito kender,"
        "no para quieto ni un minuto, siempre de aqu� para all� sin parar.\n  No me "
        "extra�ar�a que lo hayan echado de su tierra por su forma de ser.\n De todas "
        "formas ten cuidado con �l, es muy amante de lo ajeno.\n", 1);
    AddQuestion("nandor", "Beslow dice: bonito pueblo �ste, aunque �ltimamente tiene "
        "demasiado paso, pero aun as� es bastante tranquilo.\n", 1);
    AddQuestion(({"comer", "comida"}), "Beslow te mira con mala cara y te dice: �y por "
        "qu� me preguntas eso a mi?, no como tanto como te piensas.\n", 1);
    AddQuestion("castillo", "Beslow te dice: ten cuidado por esos parajes, los guardias "
    "del castillo no tienen buen humor.\n", 1);
    AddQuestion(({"boyc", "Boyc", "bardo", "m�sica", "musica", "canciones"}),
    "El tabernero te dice: la verdad es que canta mal el condenado, y toca peor.\n  Lo "
    "tengo ah� porque a los clientes les gusta y se divierten con sus tonter�as, pero "
    "de buena gana lo echar�a a la calle.\n", 1);
    AddQuestion("padre", "Beslow dice: mi padre ya hace tiempo que est� muy cansado y "
    "no puede atander la posada, as� que me tengo que encargar yo del negocio familiar.\n", 1);
    AddQuestion(({"taberna", "posada", "negocio"}), "El tabernero dice: esta posada es "
    "el negocio familiar de varias generaciones, tenemos muchos clientes, adem�s que "
    "Nandor �ltimamente es un sitio de mucho paso.\n", 1);
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
        write("El posadero se inclina en una profunda reverencia limpi�ndose las manos "
        "en el delantal mientras exclama: \n"
        	"�Buenos d�as, peque�o se�or, �en que puedo servirle?\n");
        say("La sirvienta mira con mala cara a "+CAP(TNAME)+" cuando entra en la "
        "habitaci�n, quiz�, al igual que t�, tampoco deber�a de estar aqu�.\n", TP);
    }
    return 0;
}
