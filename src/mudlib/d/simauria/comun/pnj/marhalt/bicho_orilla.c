/****************************************************************************
Fichero: bicho_orilla.c
Autor: Ratwor
Fecha: 11/02/2007
Descripción: Unos bichos típicos de orillas de río.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <guild.h>
#include <combat.h>

inherit NPC;
public void croak();
public void zumbido();

create(){
    ::create();

    switch(d3()){
        case 1:
        SetStandard("un mosquito", "insecto", ([GC_NINGUNO:1]), GENDER_MALE);
        AddId(({"mosquito", "insecto"}));
        SetShort("un mosquito");
        SetLong("Es un mosquito algo más grande de lo normal que vuela a gran "
            "velocidad.\n");
        SetNoise("Escuchas el típico zumbido de los mosquitos.\n");
        InitChats(5, ({"El mosquito te intenta picar.\n", SF(zumbido),
        "El mosquito te pasa cerca de la oreja.\n", "El mosquito se aproxima.\n"}));
        SetHands(({({"su afiliado estilete",TD_PENETRACION,0})}));
        SetGoChance(300);
        SetNoGet("El mosquito vuela a gran velocidad y no va a ser fácil atraparlo.\n");
        SetAggressive(random(2));
        SetMsgIn("viene volando");
        SetMsgOut("se va volando");
        SetWeight(10);
        break;
        case 2:
        AddId(({"rana", "sapo"}));
        SetStandard("una rana","rana",([ GC_TORPE: 2]),GENDER_FEMALE);
        SetShort("una rana");
        SetLong("Es una rana de color verde grisáceo que vive en zonas húmedas.\n");
        SetHands(({({"la boca",TD_APLASTAMIENTO,0})}));
        SetGoChance(50);
        SetMsgIn("viene saltando");
        SetMsgOut("se va saltando");
        SetWeight(200);
        SetNoGet("La rana da un salto y se aleja de ti.\n");
        InitChats(5,({"La rana dice: ¡Croaakkk!\n",
            "La rana da un salto.\n", SF(croak), SF(croak),
            "La rana croa con fuerza: ¡¡Croaakk, crooakkk!\n",
            "La rana atrapa una mosca con su larga y pegajosa lengua.\n"}));
        break;
        case 3:
        AddId(({"libelula", "insecto"}));
        SetStandard("una libelula", "insecto", ([GC_NINGUNO:2]), GENDER_FEMALE);
        SetShort("una libelula");
        SetLong("Es una bonita libelula que habita en los ríos, vuela a gran velocidad "
        "buscando algo para alimentarse, que generalmente son otros insectos más "
        "pequeños.\n");
        SetNoise("Se oye el zumbido de su vuelo.\n");
        SetMsgIn("viene volando");
        SetMsgOut("se va volando");
        SetGoChance(300);
        SetNoGet("La libelula vuela demasiado rápido.\n");
        SetHands(({({"su cuerpo",TD_APLASTAMIENTO,0})}));
        SetWeight(20);
        break;
    }
    AddId("bicho");
    AddWalkZones(({MARH("nandor/bosque/bosque00"), MARH("nandor/bosque/bosque01"),
        MARH("nandor/bosque/bosque02"), MARH("nandor/bosque/bosque03")}));

}

public void croak(){
    play_sound(environment(), SND_PNJS("rana"));
}

public void zumbido(){
    tell_room(environment(), "El mosquito hace un molesto zumbido.\n");
    play_sound(environment(), SND_PNJS("mosquito"));
}

