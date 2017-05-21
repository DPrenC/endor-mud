/* Archivo: /d/simauria/comun/pnj/abadia/guardian.c
* Descripci�n: Guardi�n de la abad�a para lavigilancia de la aldea y sus aleda�os.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <skills.h>
inherit PNJ("sherek/gbase");

create()
{
    ::create();
    SetStandard("un guardi�n","humano",([ GC_LUCHADOR:40+d10() ]),GENERO_MASCULINO);
    SetShort("un guardi�n");
    SetLong("Es un miembro del servicio privado de guardias de la abad�a de "
        "Sherek.\nSu entrenamiento es duro y continuado, lo que los convierte en "
        "perfectos y seguros vigilantes, por lo que se les dedica a la guardia y "
        "cuidado de los terrenos de la abad�a, as� como a la vigilancia del "
        "orden entre sus gentes, aunque nadie est� seguro de si son protectores "
        "o carceleros. Quiz� sean las dos cosas.\n");
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    SetGoChance(90);
    AddWalkZones(({SHERALD("calles"),SHERALD("campo"),SHERALD("granja"),SHERALD("pastos"),SHERALD("tiendas"),SHERALD("pradera")}));
    AddItem(ARMA("sherek/aldea/espada"),REFRESH_REMOVE,2,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
    InitChats(5,({"El Guardi�n te mira con suspicacia.\n",
        "El guardi�n dice: Aqu� no queremos l�os.\n",
        "El guardi�n dice: �no estar�s buscando problemas, verdad?\n",
        "El guardi�n acaricia la empu�adura de su espada.\n",
        "El guardi�n dice: No se te ocurra ninguna tonter�a.\n"}));
    InitAChats(10,({"El guardi�n grita: �Eso ha sido una estupidez!\n"}));
}

