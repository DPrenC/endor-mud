#include "path.h"
#include <properties.h>
#include <colours.h>
#include <moving.h>
#include <lock.h>
#include <search.h>
inherit "/std/room/items";
inherit "/std/container";

public int abrir_(string str)
{
    if (TO->id(str))
    {
        write("No ves "+str+" que abrir.\n");
        return 1;
    }
    return 0;
}

public int cerrar_(string str)
{
    if (TO->id(str))
    {
        write("No ves "+str+" que cerrar.\n");
        return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetIds(({"mesa"}));
    SetAds(({"de"}));
    SetShort("una mesa");
    SetLong("Es una mesa delicadamente tallada en caoba, con las patas "
        "en forma de dragón, sosteniendo una plataforma recubierta por una finísima lámina de "
        "cristal que refleja la luz de la lámpara. Tiene 4 sillas con la misma talla a su "
        "alrededor.\n");
    AddId(({"mesa"}));
    AddAdjective(({"caoba","madera"}));
    AddSubDetail(({"cristal","lamina","lámina","lámina de cristal","lamina de cristal"}),"Es una finísima lámina de "
        "cristal trabajado a mano por el legendario Kheron de Atbalnin. Te preguntas como pudieron traerla hasta aquí de "
        "una pieza.\n");
SetPreContent("Sobre ella puedes ver:\n");
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NOGET,"¿Quieres romperte los riñones?\n");
    Set(P_LOCKSTATE,LOCK_OPEN);
    SetMaxIntWeight(10000);
}
  
init()
{
    ::init();
    add_action("cerrar_","cerrar");
    add_action("abrir_","abrir");
}
        