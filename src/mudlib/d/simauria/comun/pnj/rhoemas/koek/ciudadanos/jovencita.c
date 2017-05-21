/****************************************************************************
Fichero: jovencita.c
Autor: Dharkus
Fecha: 22/05/2010
Descripción: Una chica adolescente para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();

    SetStandard("una adolescente","humano",([GC_TORPE:11]),GENDER_FEMALE);
    SetIds(({"humana", "jovencita","chica","adolescente"}));
    SetShort("una adolescente");
    SetLong("Es una hermosa jovencita de cara amable y una mirada dulce y serena.\n"
    "Su cabello largo y rizado, se agita suavemente con la brisa.\n Pasea despreocupada "
    "y tranquilamente mientras tararea alguna que otra canción típica de la zona.\n");
    InitChats(5,({"La chica canturrea tranquilamente.\n",
      "La jovencita se retoca el pelo con la mano.\n",
      "La adolescente sonríe.\n",
      "La chica te mira tímidamente.\n"}));
    AddQuestion(({"canción","cancion","canto"}),
    "La chica sonríe y dice:\n 'Es una vieja canción que me enseñaron mis abuelos "
    "cuando yo era más pequeña.\n ¿Te gusta?'\n");
    AddItem(RHOEARM("koek/ciudadanos/vestido"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
