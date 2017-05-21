/****************************************************************************
Fichero: mesonero_crowy.c
Autor: Buh
Fecha: 06/09/2006
Descripci�n: el mesonero del mes�n Cuervo negro.
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
    SetLong("Weltha lleg� a Crowy no hace mucho, tras servir multitud de a�os a "
        "personalidades importantes, llegando a ser un cocinero cotizado y reclamado por "
        "importantes nobles.\n  Decidi� montarse su propio negocio, en esta ciudad,"
        " sirviendo sus especialidades a sus clientes, cosa que, ahsta el momento, s�lo"
        " unos pocos hab�an degustado.\n");
    SetEdad(MEDIANA);
    SetAlign(30);
    SetWeight(80000);
    SetSmell("Huele a una mezcla de comidas.\n");
    InitAChats(15, ({"Weltha dice: en cuanto has entrado por la puerta me has dado mal agurio.\n",
        "El cocinero grita: �maldita sea tu estampa!.\n"}));
    InitChats(2, ({"El cocinero recoge unas mesas.\n",
        "EL cocinero te dice: �has provado ya mi especialidad?.\n",
        "Weltha sirve unas comidas a unos clientes.\n",
        "Weltha entra en la cocina y sale al poco despu�s con m�s platos para distintas"
        " mesas.\n"}));
    AddQuestion(({"Kribbat", "kribbat", "especialidad", "su especialidad", "especialidades"}),
    "El cocinero te dice: Umm mi especialidad... el Kribbat cocinado de distintas formas,"
        "est� delicioso y a los clientes les gusta, vienen desde muy lejos para provarlo "
        "y la mayor�a repiten.\n Si quieres saber m�s sobre mi especialidad mejor que "
        "lo pruebes t� personalmente, b�sicamente es cerdo, arroz y mi toque personal.\n");
    AddQuestion(({"reyes", "nobles", "terratenientes"}), "weltha te dice: no puedo hablar"
        " de mis antiguos jefes, no ser�a �tico.\n", 1);
}
