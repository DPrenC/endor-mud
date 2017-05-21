/****************************************************************************
Fichero: pirkn.c
Autor: Dharkus
Fecha: 01/05/2010
Descripción: El capitán de la guardia de Berat.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;
inherit GUARD;

create()
{
    "*"::create();
    SetStandard("Pirkn","humano",([GC_LUCHADOR:55]),GENDER_MALE);
    SetShort("el capitán Pirkn");
    SetLong("Pirkn es el capitán de la guardia de Berat.\n Se trata de un hombre "
    "de mediana edad, con notable corpulencia y larga melena castaña.\n Sus facciones "
    "serias endurecen su apariencia, dándole un aire imponente.\n Sus gruesas manos "
    "están curtidas en mil y un combates.\n");
    AddId(({"Pirkn","capitán","guardia","hombre", "capitan"}));
    SetIVision(0);
    SetCitizenship("berat");
    InitChats(4,({"Pirkn murmura:\n ¡Tanto trabajo en una ciudad tan pequeña!\n",
    "El capitán te mira con dureza.\n", "Pirkn rebusca en sus papeles.\n"}));
    InitAChats(10,({"Pirkn grita:\n ¡Pero cómo te atreves, insensato!\n", 
      "El capitán gruñe.\n", "la melena de Pirkn se agita descontroladamente, fruto "
    "de los lances del combate.\n"}));
    AddItem(RHOEVAR("/koek/comercio/herreria/sable"),REFRESH_REMOVE,SF(wieldme),
    ([P_LONG:"Es una larga espada curva y ligera, con una fina hoja de brillante acero.\n"]));
    AddItem(PROT("berat/peto_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/pantalon_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/botas_roorg"), REFRESH_REMOVE, SF(wearme));  
        AddItem(THING,REFRESH_REMOVE,
    ([P_SHORT:"una gran llave",
      P_LONG:"Una gran llave un poco oxidada.\n",
      P_IDS:({"llave","gran llave","llave_calabozo_berat"}),
      P_GENDER:GENDER_FEMALE,
      P_SIZE:P_SIZE_SMALL,
      P_WEIGHT:50]));
}
  