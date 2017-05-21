/*****************************************************************************************
 ARCHIVO:       bosq_driadas_base.c
 AUTOR:         Ztico
 FECHA:         15-03-2005
 DESCRIPCIÓN:   Habitación estándar para el bosque de las Dríadas.
 COMENTARIOS:   details...
*****************************************************************************************/

#include "./path.h"

inherit HAB_VALMAR("hab_bosque");

public string f_escuchar();
public string f_oler();

create()
{
    if(::create()) return 1;

    SetLocate("Bosques de Valmar");
    SetIntShort("el bosque de las Dríadas");
    SetIndoors(0);
    
    switch(random(100))
    {
        case 0..9:
            SetIntLong("A tu alrededor, trazando sinuosos laberintos, entrelazándose en "
                "sus copas y firmemente anclados en el antiguo suelo, ancianos robles se "
                "alzan majestuosos como gigantes adorando el cielo.\n");
            AddDetail("laberintos", "\n");
            AddDetail("copas", ".\n");
            AddDetail("suelo", ".\n");
            AddDetail(({"robles", "ancianos robles"}), ".\n");
            break;
        case 10..19:
            SetIntLong("");
            AddDetail("riachuelo", "Un riachuelo de aguas cristalinas serpentea "
                "alegremente entre los árboles y, más que discurrir, danza haciendo "
                "cabriolas como si de un ágil animalillo se tratase.\n");
            break;
        case 20..29:
            SetIntLong("Ves aquí exuberantes macizos de flores adornando ambos lados de "
                "este senderillo. Su fragante aroma te envuelve y el brillo de los "
                "pétalos dorados, azules, jaspeados, rojos y blancos acarician tu "
                "mirada.\n");
            AddDetail(({"macizos", "exuberantes macizos", "flores"}), ".\n");
            AddDetail(({"petalos", "pétalos"}), ".\n");
            AddDetail("senderillo", ".\n");            
            break;
        case 30..39:
            SetIntLong("\n");
            break;
        case 40..49:
            SetIntLong("\n");
            break;
        case 50..59:
            SetIntLong(".\n");
            break;
        case 60..69:
        	  SetIntLong("\n");
        	  break;
        case 70..79:
        	  SetIntLong("\n");
        	  break;
        case 80..89:
        	  SetIntLong("\n");
        	  break;
        case 90..99:
        	  SetIntLong("\n");
        	  break;
    }

    SetIntSmell(SF(f_oler));
    SetIntNoise(SF(f_escuchar));
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
