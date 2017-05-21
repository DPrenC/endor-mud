/****************************************************************************
Fichero: caniche.c
Autor: Ratwor
Fecha: 04/10/2006
Descripci�n: el caniche de la esposa del noble del castillo de nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <damage.h>
inherit NPC;
public void snd_ladrido();
public void snd_gru�ido();
public int cmd_pisar(string str)
{
    if (!str) return 0;
    if (str=="perro" || str=="a perro" || str=="chuch�n" || str=="a chuch�n" ||
        str=="chuchin" || str=="a chuchin" || str=="chucho" || str=="a chucho"
        || str=="caniche" || str=="a caniche")
    {
        write("Te acercas a chuch�n con malas intenciones y �l parece que lo nota, porque"
        " sale disparado a toda velocidad ladrando horrorizado.\n");
        say(CAP(TP->QueryName())+" se acerca a chuch�n con malas intenciones y, el perro "
        "que es muy listo, lo deduce y se va corriendo alarmado armando gran esc�ndalo "
        "con sus ladridos.\n", TP);
        TO->GoAway();
        return 1;
    }
    return 0;
}

public int cmd_acariciar(string str)
{
    if (!str) return 0;
    if (str=="perro" || str=="a perro" || str=="chuch�n" || str=="a chuch�n" ||
        str=="chuchin" || str=="a chuchin" || str=="chucho" || str=="a chucho"
        || str=="caniche" || str=="a caniche")
    {
        write("Acercas la mano para acariciar al chucho y �l se aparta de t� gru�endo y "
        "ladr�ndote.\n");
        say(CAP(TP->QueryName())+" le acerca la mano al chucho para acariciarle y �ste se"
        " aparta gru�endo y ladrando.\n", TP);
        snd_gru�ido();
        return 1;
    }
    return 0;
}

create()
{
    ::create();

    SetStandard("Chuch�n", "perro", 1, GENDER_MALE);
    AddId(({"perro", "caniche", "chucho", "chuch�n", "chuchin"}));
    SetShort("un caniche");
    SetLong("Es un peque�ito perro de raza caniche enano que pertenece a la esposa del noble"
        " del castillo.\n  Lleva atado del cuello un lazo de seda rosa que, junto con "
        "el blanco de su pelo y su diminuto tama�o de apenas un palmo, hace un animalito "
        "muy gracioso.\n Le gusta husmear a sus anchas por todos los rincones del "
        "castillo oliendo todo lo que se encuentra y ladrando a todo ser estra�o que pase "
        "cerca de �l.\n");
    SetSmell("Huele a perro.\n");
    SetWeight(4500);
    //SetCitizenship("nandor");
    SetAlign(50);
    SetNoise("Emite unos graciosos ladridos a todo el que se encuentra.\n");
    AddSubDetail(({"Lazo", "seda"}), "Un peque�o lazo de seda de color rosa.\n");
    InitChats(4, ({"Chuch�n te olfatea los pies.\n", SF(snd_ladrido),
        "Chuch�n se pone a rascarse las pulgas con la pata trasera.\n",
        "Chuch�n olfatea una esquina.\n",
        "Chuch�n te sigue con la mirada.\n", SF(snd_gru�ido),
        "Chuch�n se acerca a una pared y echa una meadita chiquitina.\n"}));
    SetShrugMsg("Chuch�n mira desconcertado cuando escucha que le preguntan.\n");
    InitAChats(10, ({"Chuch�n lloriquea.\n",
    "chuch�n tiene la mirada triste.\n"}));
    SetGoChance(100);
    AddWalkZones(({CASTILLO("murallas/"), CASTILLO("patio/"), CASTILLO("planta")}));
    SetSize(P_SIZE_SMALL);
    SetNoGet("Chuch�n se revuelve espantado y te ladra m�s fuerte todav�a intentando "
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
        tell_room(ENV(TO), "Chuch�n huye espantado.\n");
    }
    Whimpy();
    return;
}

public void snd_ladrido(){
    tell_room(environment(),"Chuch�n te ladra graciosamente: �guau, guau!\n");
    play_sound(environment(), SND_PNJS("perro_pequeno"),0, 100, 2);
}

public void snd_gru�ido(){
    tell_room(environment(), "Chuch�n gru�e: Grrrr...'\n");
        play_sound(environment(), SND_PNJS("grunido_pequeno"));
    }

public void saludo(){
    if(present(TP, environment())){
        write ("El caniche chuch�n empieza a ladrarte nada m�s verte: �guau, guau!.\n");
        say("El caniche chuch�n ladra a "+CAP(TNAME)+" en cuanto lo ve: �guau, guau!"
        ".\n", TP);
        snd_ladrido();
    }
    return 0;
}

