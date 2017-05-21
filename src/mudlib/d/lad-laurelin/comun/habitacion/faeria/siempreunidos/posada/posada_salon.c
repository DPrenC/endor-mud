/***
Fichero: salon_posada.c
Autor: kastwey@simauria
Descripci�n: Sal�n de descanso de la posada.
***/

#include "path.h"
#include <nightday.h>

inherit STD_FAERIA("posada_base_faeria");


public string QueryIntLong();
string mirar_bosque();
string mirar_chimenea();

create()
{
    ::create();
    SetIntShort("el sal�n de descanso de la posada");
    SetIntLong(W("Te encuentras en el sal�n de descanso de la posada de Siempreunidos.\n"
    "Es un sal�n muy confortable, con una larga mesa rodeada de sillas, y un sof� al fondo de la sala.\n"
    "En una de las paredes, hay una gran chimenea que en las estaciones fr�as debe proporcionar un calor muy agradable.\n"
    "En la pared de enfrente a la chimenea, puedes ver un trofeo enmarcado.\n"
    "Aqu� es donde se suelen reunir    los habitantes del pueblo o los hu�spedes de la posada a charlar un rato. Hacia el oeste puedes ver el vest�bulo, y hacia el norte se abre un gran ventanal.\n"));
    SetOficina(HAB_PUESTO("posada/posada"));
    SetIndoors(1);
    SetIntBright(25);
    AddItem(PNJ_PUESTO("soldado"), REFRESH_HOME, random(3));
    AddDetail(({"ventana", "ventanal", "norte", "bosque"}), SF(mirar_bosque));
    AddDetail(({"chimenea", "fuego", "hogar"}), SF(mirar_chimenea));
    AddDetail(({"mesa", "mesa larga", "mesa alargada"}), W("Se trata de una gran mesa situada en el centro de la estancia.\n"
    "A su alrededor puedes ver multitud de sillas.\n"));
    AddDetail(({"silla", "sillas"}), "Son unas sillas que parecen muy c�modas. Est�n situadas alrededor de una gran mesa colocada en el centro de la estancia.\n");
    AddDetail(({"trofeo", "cuadro", "placa"}), W("Es una placa enmarcada en un marco que parece de plata.\n"
    "Te acercas y en ella puedes leer:\n"
    "Engelbergt Gyliam. Ganador del torneo de tiro con arco del " + to_int(CHRONOS->QueryYear() - 10) + ".\n"));
    AddDetail(({"sof�", "sofa", "sillon", "sill�n"}), "Es un sof� enorme, con multitud de cojines que tienen pinta de ser muy mullidos.\n");
    AddExit("oeste", HAB_PUESTO("posada/posada"));
}

public string QueryIntLong()
{
    if (CHRONOS->QueryEstacion() == 1 || CHRONOS->QueryEstacion() == 4)
    // estaciones fr�as
    {
        return W("Te encuentras en el sal�n de descanso de la posada de Siempreunidos.\n"
        "Es un sal�n muy confortable, con una larga mesa rodeada de sillas, y un sof� al fondo de la estancia.\n"
        "En una de las paredes, hay una gran chimenea que ilumina la estancia con un resplandor rojizo, adem�s de proporcionar un agradabil�simo calor.\n"
        "En la pared de enfrente a la chimenea, puedes ver un trofeo enmarcado.\n"
        "Aqu� es donde se reunen los hu�spedes de la posada a charlar un rato. Hacia el oeste puedes ver el vest�bulo, y hacia el norte se abre un gran ventanal.\n");
    }
    else
        return ::QueryIntLong();
}




string mirar_bosque()
{
    if (NIGHTDAY->QueryState() == ND_NIGHT) return W("Te asomas a la ventana, pero con la oscuridad de la noche no puedes ver casi nada.\n"
    "Solo crees poder atisbar el contorno de lo que te parece puede ser un bosque.\n");
    switch(CHRONOS->QueryEstacion())
    {
        case 1: // algo as� como invierno
            return W("Desde la ventana ves la magn�fica vista de un gran bosque nevado.\n"
            "Observas a lo lejos los contrastes entre los troncos de las con�feras, que destacan ennegrecidos sobre el fondo blanco de la nieve que cubre gran parte del lugar.\n");
            break;
        case 2: // estaci�n templada:
            return W("Desde la ventana observas unas maravillosas vistas de un bosque.\n"
            "La nieve que lo cubr�a se ha derretido por completo, y los �rboles comienzan de nuevo a producir frutos.\n");
            break;
        case 3: // algo as� como el verano. Estaci�n calurosa.
            return "desde la ventana puedes divisar un bosque de pinos, cedros y abetos cuyas copas desaf�an a las nubes desde su altura imponente.\n";
            break;
        case 4: // algo as� como el oto�o... estaci�n templada tendiendo a fr�a.
            return W("Desde la ventana divisas un bosque, en el que comienzan a sentirse los efectos del fr�o.\n"
            "No te cuesta imaginarte como ser� este bosque dentro de poco, con la nieve cubri�ndolo todo como si de una manta blanca se tratase.\n");
            break;
    }
    return "";
}





string mirar_chimenea()
{
    if (CHRONOS->QueryEstacion() == 1 || CHRONOS->QueryEstacion() == 4) // la chimenea est� encendida
        return W("En la chimenea arde un gran fuego, alimentado por multitud de ramas secas.\n"
        "Al acercartes, notas el agradable calor que desprende.\n");
    else
    // estaci�n calurosa o templada... no hace falta chimenea.
        return W("Es una gran chimenea que ahora permanece apagada.\n"
        "No obstante, por las paredes ennegrecidas y el olor que desprende, es obvio que suele encenderse con frecuencia.\n");
}


 