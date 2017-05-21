/**************************************************************************
fichero: Fagan.c
Autor: Riberales
Creación: 30/08/2005
Descripción: El enano de las armaduras en Annufam.s
**************************************************************************/
#include <combat.h>
#include "path.h"
#include <properties.h>


inherit NPC;
string herrero();
string chats();
string elearca_viva();

public void create()
{
    ::create();
    SetStandard("Fagan","enano",13,GENDER_MALE);
    SetLong(W("Fagan es un enano bastante rechoncho y con una gran sonrisa en "
              "la cara. Aún así, no dudas de su tenacidad y profesionalidad. "
              "Siempre está de un lado a otro apuntando cosas en su "
              "mostrador.\n"));


    SetIds(({"fagan","tendero"}));

    InitChats(2,SF(chats));
}


string chats()
{
    if(environment()->QueryHerreria_03())
    {
        switch(random(2))
        {
            case 0:
                object elearca;
                if ((elearca = present("elearca",to_object(HAB_HERRERIA_ANNUFAM
                    ("herreria_02")))) && living(elearca))
                {
                    return "Fagan grita: Yeeee, Elearca, alegra esa cara, mujer.\n";
                }
                break;

            case 1:
                return "Fagan hace algunas anotaciones en los papeles del mostrador.\n";
                break;
        }
    }
	return "Fagan silba: fiuuuu.\n";
}
