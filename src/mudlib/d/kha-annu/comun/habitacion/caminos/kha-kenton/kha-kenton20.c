#include "./camino.h"

create()
{
    object ob;
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("Est�s al pie de unas monta�as, muy cerca del poblado de Flenton, del que "
        "puedes ver la entrada hacia el oeste. Siguiendo el camino en la direcci�n opuesta "
        "comienza un sendero que asciende la monta�a.\n");
    SetIndoors(0);
    AddExit("este",CAMINO+"kha-kenton19");
    AddExit("oeste","/d/kenton/comun/habitacion/flenton/calles/entrada");
    SetLocate("Camino de Kha-Annu");
    ob=clone_object("/obj/monolito");
    ob->SetRaza("duende");
    ob->move(TO);
}
