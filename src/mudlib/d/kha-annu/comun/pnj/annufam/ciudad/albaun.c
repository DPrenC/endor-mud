/**************************************************************************
fichero: Albaun
Autor:Kastwey
Creación:20/07/2005
Descripción: El banquero de Annufam
**************************************************************************/

#include "./path.h"
#include <properties.h>


inherit NPC;

public void create()
{
    ::create();
    SetStandard("Albaun","enano",10,GENDER_MALE);
    SetShort("Albaun, el banquero");
    SetLong(W("Albaun es el banquero de la ciudad. Es un enano con una "
              "blanca barba y unos ojos pequeños como garbanzos.\n"));
    AddId("banquero");
}



