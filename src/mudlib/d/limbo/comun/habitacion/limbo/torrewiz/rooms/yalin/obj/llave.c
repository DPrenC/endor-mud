#include "path.h"
#include <properties.h>
#include <moving.h>
inherit THING;

create()
{
    ::create();
    SetIds(({"llave"}));
    SetAds(({"de"}));
    SetShort("una llave de oro");
    SetLong("Es una peque�a llave de oro.\nEn uno de los lados de su cabeza, puedes ver el emblema "
        "de la Reina de las hadas, mientras que en el otro, puedes ver una R.\nA lo largo del "
        "tubo, puede verse la inscripci�n 'YALIN'.\n");
    AddId(({"yalin_key","llave"}));
    AddAdjective(({"yalin","Yalin","oro","dorada","peque�a"}));
    Set(P_MATERIAL,M_ORO);
    SetNoDrop("Si no la quer�as, �para qu� la has cogido?\n");
    SetWeight(10);
}

init()
{
    ::init();
    object lugar = environment(TO);
    if (query_once_interactive(lugar) && lugar != YALIN)
    {
        tell_object(lugar,"T� no deber�as tener esa llave, no eres su propietari"+lugar->QueryGenderEndString()+".\n");
        call_out("remove");
    }
}

    public varargs int move(mixed dest, int method, mixed extra)
{
	  if (method == M_GET && TP != YALIN)
	  {
        write("No eres su propietari"+TP->QueryGenderEndString()+", no lleva tu nombre. Mejor la dejas donde est�, por si su "
            "due�a la busca.\n");
        return ME_NO_GET;
    }
	  return ::move(dest, method, extra);
}
