/****************************************************************************
Fichero: flor.c
Autor: Ratwor
Fecha: 31/03/2007
Descripci�n: Una flor aleatoria para la herborister�a de Nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <herbs.h>

inherit HERB;

create() {
    ::create();
    AddId(({"flor","flores"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(50);
    switch(d10()){
        case 1:
            SetShort("una amapola");
            SetLong("Es una flor acampanada de color escarlata, con finos p�talos que "
            "le dan una forma esf�rica.\n");
            AddId("amapola");
            SetClass(HERB_CLASS_NARCOTIC);
            SetSmell("Sientes un perfume dulz�n y silvestre, silvestre como la flor "
            "misma.\n");
            break;
        case 2:
            SetShort("una rosa amarilla");
            SetLong("Es una flor de color amarillo claro, no muy grande y todav�a no del"
            " todo abierta, a cuyo tallo alguien se ha tomado el trabajo de quitar las"
            " espinas.\n");
            SetSmell("Percibes la suave fragancia que es t�pica en esta flor.\n");
            AddId(({"rosa", "rosa amarilla"}));
            SetClass("saciante");
            break;
        case 3:
            SetShort("un tulip�n azul");
            SetLong("Se trata de una vistosa flor azul cuyos p�talos presentan una forma "
            "de coraz�n. �sta est� abierta y en todo su esplendor.\n");
            AddId(({"tulipan", "tulip�n","tulip�n azul", "tulipan azul"}));
            SetClass("saciante");
            SetSmell("Sientes un aroma suave y fresco que se evapora enseguida.\n");
            Set(P_GENDER,GENERO_MASCULINO);
            break;
        case 4:
            SetShort("un jazm�n");
            SetLong("Es una gran flor blanca de c�liz apenas visible a causa de sus "
            "muchos p�talos.\n");
            AddId(({"jazmin", "jazm�n"}));
            SetSmell("Percibes un aroma penetrante a flor silvestre.\n");
            SetClass("saciante");
            Set(P_GENDER,GENERO_MASCULINO);
            break;
        case 5:
            SetShort("un lirio");
            SetLong("Es una vistosa flor de color rojo intenso con un elegante jaspeado.\n");
            AddId("lirio");
            SetSmell("Esta flor tiene un aroma suave y delicado, que sin embargo posee a "
            "su vez ese algo indefinido que caracteriza a los olores de la naturaleza en el"
            " campo.\n");
            SetClass("saciante");
            Set(P_GENDER,GENERO_MASCULINO);
            break;
        case 6:
            SetShort("un jacinto");
            SetLong("Se trata de un ramillete de flores peque�as de color blanco. Son muy "
            "carnosas y crecen arracimadas y unidas entre s�.\n");
            SetSmell("Percibes el perfume intenso y persistente que es caracter�stico "
            "de esta flor.\n");
            AddId("jacinto");
            Set(P_GENDER,GENERO_MASCULINO);
            SetClass("saciante");
            break;
        case 7:
            SetShort("una camelia");
            SetLong("Es una flor de buen tama�o, de color rosa y blanco, con grandes "
            "p�talos que forman varias corolas superpuestas.\n");
            AddId("camelia");
            SetSmell("Esta flor casi no tiene aroma, aunque si hueles con cuidado puedes "
            "percibir el perfume suave que exhalan sus p�talos.\n");
            SetClass("saciante");
            break;
        case 8:
            SetShort("una orqu�dea");
            SetLong("Es una flor sumamente delicada y muy vistosa, con finos p�talos que "
            "le dan una forma extra�a e indefinida. �sta est� abriendo.\n");
            AddId(({"orquidea", "orqu�dea"}));
            SetClass("venenoso");
            Set(P_GENDER,GENERO_MASCULINO);
            SetSmell("Percibes el fuerte aroma que es propio de estas flores cuando est�n"
            " abri�ndose.\n");
            break;
        case 9:
            SetShort("una hortensia");
            SetLong("Ves una flor azul cuyo principal rasgo parece ser los cuatro grandes "
            "p�talos que conforman su corola y ocultan su c�liz.\n");
            AddId("hortensia");
            SetSmell("Percibes un aroma silvestre y penetrante.\n");
            SetClass("saciante");
            break;
        case 10:
            SetShort("una azalea");
            SetLong("Ves un ramillete de flores que al parecer crecen juntas. Tienen "
            "un aspecto silvestre pero de alg�n modo delicado.\n");
            AddId("azalea");
            SetClass("saciante");
            SetSmell("Sientes un aroma dulce e indefinible, distinto a todo lo que "
            "conoces.\n");
            break;
    }

    SetPower(20+random(150));
}

