/****************************************************************************
Fichero: reisi.c
Autor: Riberales
Fecha: 15/02/2006
Descripci�n: La responsable de la tienda de mascotas.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("reisi","elfo",([GC_KISALAS:40]),GENDER_FEMALE);
    AddId(({"elfa", "kisala"}));
    SetShort("reisi");
    SetLong("Reisi es la elfa responsable del cuidado de los animales que van "
            "a convertirse en mascotas de las Kisalas. Es una joven de ojos "
            "azules, por donde se escapa una mirada perspicaz y risue�a. Est� "
            "continuamente sonriendo y vigilando a sus criaturas.\n");

    AddId(({"reisi","Reisi","tendera"}));

    InitChats(3,({
              "Reisi sonr�e.\n",
            "Reisi te mira.\n"}));
}
