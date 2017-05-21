/* Archivo: /d/simauria/comun/pnj/abadia/mathin.c
* Descripción: Herrero de la granja.
* Autor Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <combat.h>
inherit PNJ("sherek/aldea/base");
object ob;

create()
{
    ::create();
    SetStandard("mathin","humano",30,GENERO_MASCULINO);
    SetName("Mathin");
    SetShort("mathin, el herrero");
    SetLong("Mathin es un humano de talla mediana, pero de gran envergadura y "
        "musculatura bien marcada.\nTrabaja incansablemente durante todo el día, "
        "atendiendo a los clientes en sus compras, y reparando los útiles de "
        "labranza y de la granja que le traen los aldeanos.\n");
    SetIds(({"mathin","Mathin","humano","herrero"}));
    Set(P_CANT_LURE,1);
    SetHP(QueryMaxHP());
    InitChats(5,({"Mathin se limpia el hollín de la cara.\n",
        "Mathin refunfuña: siempre lo mismo, reparar y volver a reparar. Ni una "
            "herramienta vendida.\n",
        "Mathin saca una pieza del fuego y la golpea duramente.\n",
        "Mathin te mira y gruñe: ¿quieres comprar algo?\n"}));
    InitAChats(5,({"Sólo faltaba eso, me mato a trabajar para que vengas tú a "
        "crearme problemas.\n"}));
    ob=clone_object("/std/weapon");
    ob->SetStandard(WT_MAZA, 12,M_ACERO);
    ob->Set(P_SHORT, "un martillo pesado");
    ob->Set(P_LONG, "Un enorme martillo de acero, fuerte y eficaz.\n");
    ob->SetIds(({"martillo","martillo pesado"}));
    ob->SetSize(P_SIZE_MEDIUM);
    AddItem(ob, REFRESH_REMOVE,1, SF(wieldme));
}
