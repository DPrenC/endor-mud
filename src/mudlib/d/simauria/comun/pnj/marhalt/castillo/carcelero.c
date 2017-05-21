/****************************************************************************
Fichero: carcelero.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: El carcelero de las mazmorras del castillo.
****************************************************************************/
#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>

inherit NPC;
inherit GUARD;

object arma;

create(){
    "*"::create();
    SetStandard("el carcelero","humano",([GC_LUCHADOR:27]),GENDER_MALE);
    AddId(({"carcelero","car\ncelero", "guardia", "hombre"}));
    SetShort("el carcelero");
    SetLong(
    "Es el carcelero que custodia las mazmorras, un tipo que tiene cara de mala leche.\n");
    SetCitizenship("nandor");
    SetGuardDefendMsg("El carcelero grita:\n ¡Por mi señor Rocher! ¡Por Nandor!\n");
    SetIVision(0);
    Set(P_CANT_LURE,1);
    SetAlign(100);
    InitChats(2,({"El carcelero te dice:\n '¡Qué haces aquí!\n ¡No se puede entrar!\n",
      "El carcelero te mira con mala leche.\n",
        "El carcelero te grita:\n  '¡Fuera!'\n"}));
    InitAChats(10,({"El carcelero grita:\n '¡Vas a morir!\n"}));
    arma=clone_object("/std/weapon");
    arma->SetStandard(WT_MAZA, 8, P_SIZE_MEDIUM, M_HIERRO);
    arma->Set(P_SHORT, "una maza de pinchos");
    arma->Set(P_LONG, "Una maza de madera con algunos pinchos metálicos que sobresalen.\n");
    AddItem(arma,REFRESH_REMOVE,SF(wieldme));
    AddItem(PROTNANDOR("cota_malla"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));

    if(d2()==1)
            AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["cobre":random(10),"plata":d6()])]));   AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));

    AddQuestion(({"ladrón", "ladrones", "chorizos", "chorizo"}),
    "El carcelero dice: Sí claro, de eso tenemos unos cuantos de vez en cuando... "
    "ahora mismo puedes hacerle una visita a un pobre infeliz que intentó robar a "
    "un viajero por el camino del norte, menos mal que cerca andaba uno de los "
    "hombres de armas de nuestro señor. Hay que tener mano dura con esos ladronzuelos "
    "para mantener el orden en Marhalt.\n Aunque de vez en cuando alguno se nos "
    "escapa, como ese de hace unos días que casi nos roba una de las valiosísimas "
    "perchas que hay en las habitaciones de la torre del homenaje, todavía no sabemos "
    "por donde salió.\n");
    AddQuestion(({"mazmorras", "mazmorra", "celda", "celdas"}),
    "El carcelero dice: ahí tenemos unas cuantas habitaciones lujosas para nuestros "
    "visitantes... apuesto a que vas a verlas brevemente...\n");

}

public varargs void Die(mixed silent) {
    TO->RemoveId("car\ncelero");
    ::Die(silent);
}
