/****************************************************************************
Fichero: caniche.c
Autor: Ratwor
Fecha: 04/10/2006
Descripción: el caniche de la esposa del noble del castillo de nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <damage.h>
inherit NPC;
public void snd_ladrido();
public void snd_gruñido();
public int cmd_pisar(string str)
{
    if (!str) return 0;
    if (str=="perro" || str=="a perro" || str=="chuchín" || str=="a chuchín" ||
        str=="chuchin" || str=="a chuchin" || str=="chucho" || str=="a chucho"
        || str=="caniche" || str=="a caniche")
    {
        write("Te acercas a chuchín con malas intenciones y él parece que lo nota, porque"
        " sale disparado a toda velocidad ladrando horrorizado.\n");
        say(CAP(TP->QueryName())+" se acerca a chuchín con malas intenciones y, el perro "
        "que es muy listo, lo deduce y se va corriendo alarmado armando gran escándalo "
        "con sus ladridos.\n", TP);
        TO->GoAway();
        return 1;
    }
    return 0;
}

public int cmd_acariciar(string str)
{
    if (!str) return 0;
    if (str=="perro" || str=="a perro" || str=="chuchín" || str=="a chuchín" ||
        str=="chuchin" || str=="a chuchin" || str=="chucho" || str=="a chucho"
        || str=="caniche" || str=="a caniche")
    {
        write("Acercas la mano para acariciar al chucho y él se aparta de tí gruñendo y "
        "ladrándote.\n");
        say(CAP(TP->QueryName())+" le acerca la mano al chucho para acariciarle y éste se"
        " aparta gruñendo y ladrando.\n", TP);
        snd_gruñido();
        return 1;
    }
    return 0;
}

create()
{
    ::create();

    SetStandard("Chuchín", "perro", 1, GENDER_MALE);
    AddId(({"perro", "caniche", "chucho", "chuchín", "chuchin"}));
    SetShort("un caniche");
    SetLong("Es un pequeñito perro de raza caniche enano que pertenece a la esposa del noble"
        " del castillo.\n  Lleva atado del cuello un lazo de seda rosa que, junto con "
        "el blanco de su pelo y su diminuto tamaño de apenas un palmo, hace un animalito "
        "muy gracioso.\n Le gusta husmear a sus anchas por todos los rincones del "
        "castillo oliendo todo lo que se encuentra y ladrando a todo ser estraño que pase "
        "cerca de él.\n");
    SetSmell("Huele a perro.\n");
    SetWeight(4500);
    //SetCitizenship("nandor");
    SetAlign(50);
    SetNoise("Emite unos graciosos ladridos a todo el que se encuentra.\n");
    AddSubDetail(({"Lazo", "seda"}), "Un pequeño lazo de seda de color rosa.\n");
    InitChats(4, ({"Chuchín te olfatea los pies.\n", SF(snd_ladrido),
        "Chuchín se pone a rascarse las pulgas con la pata trasera.\n",
        "Chuchín olfatea una esquina.\n",
        "Chuchín te sigue con la mirada.\n", SF(snd_gruñido),
        "Chuchín se acerca a una pared y echa una meadita chiquitina.\n"}));
    SetShrugMsg("Chuchín mira desconcertado cuando escucha que le preguntan.\n");
    InitAChats(10, ({"Chuchín lloriquea.\n",
    "chuchín tiene la mirada triste.\n"}));
    SetGoChance(100);
    AddWalkZones(({CASTILLO("murallas/"), CASTILLO("patio/"), CASTILLO("planta")}));
    SetSize(P_SIZE_SMALL);
    SetNoGet("Chuchín se revuelve espantado y te ladra más fuerte todavía intentando "
        "morderte la mano.\n");
    SetHands(({({"un mordisco", TD_CORTE, 2})}));
    SetMsgIn("viene corriendo");
    SetMsgOut("se va corriendo");
}

public void init()
{
    ::init();
    if (TP->QueryRace()!="humano")
        call_out("saludo",1);

    add_action("cmd_pisar", "pisar");
    add_action("cmd_pisar", "patear");
    add_action("cmd_pisar", "chafar");
    add_action("cmd_acariciar", "acariciar");
    add_action("cmd_acariciar", "tocar");
}

DoDamage() // Si le atacan intenta huir
{
    if (ENV(TO))
    {
        tell_room(ENV(TO), "Chuchín huye espantado.\n");
    }
    Whimpy();
    return;
}

public void snd_ladrido(){
    tell_room(environment(),"Chuchín te ladra graciosamente: ¡guau, guau!\n");
    play_sound(environment(), SND_PNJS("perro_pequeno"),0, 100, 2);
}

public void snd_gruñido(){
    tell_room(environment(), "Chuchín gruñe: Grrrr...'\n");
        play_sound(environment(), SND_PNJS("grunido_pequeno"));
    }

public void saludo(){
    if(present(TP, environment())){
        write ("El caniche chuchín empieza a ladrarte nada más verte: ¡guau, guau!.\n");
        say("El caniche chuchín ladra a "+CAP(TNAME)+" en cuanto lo ve: ¡guau, guau!"
        ".\n", TP);
        snd_ladrido();
    }
    return 0;
}

