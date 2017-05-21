/****************************************************************************
Fichero: mesonero_crowy.c
Autor: Buh
Fecha: 06/09/2006
Descripción: el mesonero del mesón Cuervo negro.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <gremios.h>
#include DOM_SYS "crowiano.h"

inherit PNJ_CROWY("crowiano_civil_base");

create()
{
    ::create();
    AddId(({"mesonero", "sirviente", "viejo", "cocinero", "weltha", "Weltha"}));
    SetStandard("Wheltha", "humano", ([GC_TORPE:15]), GENDER_MALE);
    SetShort("weltha el mesonero");
    SetLong("Weltha llegó a Crowy no hace mucho, tras servir multitud de años a "
        "personalidades importantes, llegando a ser un cocinero cotizado y reclamado por "
        "importantes nobles.\n  Decidió montarse su propio negocio, en esta ciudad,"
        " sirviendo sus especialidades a sus clientes, cosa que, ahsta el momento, sólo"
        " unos pocos habían degustado.\n");
    SetEdad(MEDIANA);
    SetAlign(30);
    SetWeight(80000);
    SetSmell("Huele a una mezcla de comidas.\n");
    InitAChats(15, ({"Weltha dice: en cuanto has entrado por la puerta me has dado mal agurio.\n",
        "El cocinero grita: ¡maldita sea tu estampa!.\n"}));
    InitChats(2, ({"El cocinero recoge unas mesas.\n",
        "EL cocinero te dice: ¿has provado ya mi especialidad?.\n",
        "Weltha sirve unas comidas a unos clientes.\n",
        "Weltha entra en la cocina y sale al poco después con más platos para distintas"
        " mesas.\n"}));
    AddQuestion(({"Kribbat", "kribbat", "especialidad", "su especialidad", "especialidades"}),
    "El cocinero te dice: Umm mi especialidad... el Kribbat cocinado de distintas formas,"
        "está delicioso y a los clientes les gusta, vienen desde muy lejos para provarlo "
        "y la mayoría repiten.\n Si quieres saber más sobre mi especialidad mejor que "
        "lo pruebes tú personalmente, básicamente es cerdo, arroz y mi toque personal.\n");
    AddQuestion(({"reyes", "nobles", "terratenientes"}), "weltha te dice: no puedo hablar"
        " de mis antiguos jefes, no sería ético.\n", 1);
}
