/*****************************************************************************************
 ARCHIVO:       bosque64.c
 AUTOR:         Ztico
 FECHA:         06-04-2005
 DESCRIPCIÓN:   Pequeño embarcadero en el Bosque de las Dríadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <colours.h>

//defino estos grupos de colores
#define C_B       TC_BG_CYAN TC_BLACK            //texto negro y fondo cian
#define N_C_B     TC_NORMAL TC_BG_CYAN TC_BLACK  //normal, texto negro y fondo cian
#define N_B_W     TC_NORMAL TC_BOLD TC_WHITE     //normal, texto blanco resaltado

inherit PORT;

public string f_oler();
public string f_escuchar();
public string cmd_leer(string str);
public string leer_letrero();

create()
{
    if(::create()) return 1;

    SetIntShort("un pequeño embarcadero");
    SetIntLong("En esta zona se abre un claro rodeado por árboles al norte y límitado "
        "por el río Ellidan hacia el sur. Te encuentras en un pequeño embarcadero a "
        "orillas del río. Unas espirales como de vapor flotan entre las cañas del borde. "
        "\nHay un letrero clavado en un poste que quizá puedas leer.\n");
    SetIndoors(0);

    AddDetail(({"letrero", "cartel"}), "Prueba a leerlo.\n");
    AddReadMsg(({"letrero", "cartel"}), SF(leer_letrero));
    AddDetail("claro", "Es un espacio abierto sin árboles.\n");
    AddDetail(({"árboles", "arboles"}), "Montones de sauces y fresnos marcan el contorno "
        "del río.\n");
    AddDetail(({"río", "rio", "ellidan", "rio ellidan"}), "Es un río de aguas pardas y "
        "perezosas bordeado por viejos sauces caídos y moteado por miles de hojas "
        "marchitas.\n");
    AddDetail(({"embarcadero", "muelle", "pequeño embarcadero"}), "Es de madera. Su "
        "pasarela se mantiene en equilibrio gracias a dos troncos que se alzan desde el "
        "río.\n");
    AddDetail("madera", "Está muy húmeda y en algunas zonas comienza a pudrirse, aunque "
        "milagrosamente no cede.\n");
    AddDetail("pasarela", "Se balancea suavemente pero no parece peligrosa.\n");
    AddDetail("troncos", "Alguien fijó la pasarela a los troncos mediante cordeles y "
        "clavos de metal.\n");
    AddDetail(({"orilla", "orillas"}), "Está plagada de cañas y cubierta por una leve "
        "bruma.\n");
    AddDetail(({"espirales", "vapor", "niebla", "bruma", "neblina"}), "Una suave neblina "
        "cubre toda la orilla y asciende por entre las cañas y juncos.\n");
    AddDetail(({"cañas", "canyas", "juncos"}), "Son de un verde intenso, crecen a "
        "trompicones entre los árboles.\n");


    SetIntSmell(SF(f_oler));
    SetIntNoise(SF(f_escuchar));

    AddShip(COMUN+"transporte/barco/barca_faeria/barca_glinnael");

    AddExit("norte", HAB_BOSQUE_DRIADAS("bosque67.c"));
}

public string f_oler()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Este olor tan puro y fresco te repugna.\n";
    return "Canteros de heliotropo perfuman el aire.\n";
}

public string f_escuchar()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Tus oidos no captan nada especial.\n";
    return "Escuchas como la brisa se cuela entre las ramas de los robles.\n";
}

public string leer_letrero()
{
    if(TP->QueryTiflo())
    {
        return "\n   La barca navega río arriba hasta la isla de\n"
               "   los Druidas en el centro del lago Glinnael.\n"
               "   No te atrevas a subir si tu alma no es pura\n"
               "   y limpia.\n\n";
    }
    else
    {
        return "\n\n"
          "   " C_B "***************************************************\n" TC_NORMAL
          "   " C_B "**" TC_NORMAL "                                               " C_B "**" TC_NORMAL "\n"
          "   " C_B "**" N_B_W "  La barca navega río arriba hasta la isla de  " N_C_B "**" TC_NORMAL "\n"
          "   " C_B "**" N_B_W "  los Druidas en el centro del lago Glinnael.  " N_C_B "**" TC_NORMAL "\n"
          "   " C_B "**" TC_NORMAL "                                               " C_B "**" TC_NORMAL "\n"
          "   " C_B "**" N_B_W "  No te atrevas a subir si tu alma no es pura  " N_C_B "**" TC_NORMAL "\n"
          "   " C_B "**" N_B_W "  y limpia.                                    " N_C_B "**" TC_NORMAL "\n"
          "   " C_B "**" TC_NORMAL "                                               " C_B "**" TC_NORMAL "\n"
          "   " C_B "***************************************************" TC_NORMAL "\n\n";
    }
}
