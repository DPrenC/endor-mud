/****************************************************************************
Fichero: orilla.c
Autor: Ratwor
Fecha: 25/12/2006
Descripci�n: un archivo base para las orillas del r�o del bosque de Marhalt
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <skills.h>
#include <moving.h>
#include <sounds.h>
#define AO       (this_player()->QueryGender()==GENDER_FEMALE ? "a" : "o")

inherit SIM_ROOM;

private varargs string snd_ambiente(int newstate);
private string last_sound;

create(){
    ::create();
    SetIndoors(0);
    SetLocate("bosque de Marhalt");
    SetIntShort("la orilla del r�o");
    switch(d6()){
        case 1:
            SetIntLong(" Esta es una de las orillas del r�o Kandal, que cruza de este "
            "a oeste la totalidad del bosque de Marhalt.\n  Si quieres cruzarlo "
            "deber�s buscar otra zona del r�o que lo permita, pues aqu� las "
            "caracter�sticas de su cauce te va a dificultar el cruce.\n");
            break;
        case 2:
            SetIntLong("El bosque de Marhalt est� aqu� limitado por el r�o que lo "
            "cruza de este a oeste.\n No es un r�o muy caudaloso ni peligroso, pero "
            "hay zonas donde mejor no meterse por el riesgo de ser arrastrado por la "
            "corriente.\n");
            break;
        case 3:
            SetIntLong("El r�o Kandal cruza el bosque desde el este hasta la costa oeste "
            "de Simauria. Sus aguas transparentes y llenas de buena pesca transcurre "
            "en algunas zonas velozmente y en otras calmadas.\n");
            break;
        case 4:
            SetIntLong("En este punto del bosque te corta el paso el r�o Kandal de aguas"
            " cristalinas, donde deja apreciar los trofeos del noble entretenimiento de "
            "la pesca, los cuales guarda en su interior.\n Para cruzar el r�o necesitar�s "
            "buscar otra parte menos caudalosa.\n");
            break;
        case 5:
            SetIntLong("El r�o Kandal transcurre de este a oeste atravesando parte del "
            "bosque de Marhalt, hasta la costa oeste de Simauria. Sus aguas corren m�s "
            "tranquilas en algunas zonas y m�s raudas en otras, y est�n llenas de peces "
            "que pueden pescarse si se cuenta con los elementos necesarios.\n");
            break;
        case 6:
            SetIntLong("Este r�o de aguas claras corre de este a oeste dividiendo el "
            "bosque de Marhalt. Est� lleno de peces que incluso pueden verse desde fuera.\n"
            " No es muy caudaloso, pero hay ciertas partes por las que corre con m�s "
            "velocidad, por lo que para cruzarlo tendr�s que buscar otra parte menos "
            "peligrosa.\n");
            break;
    }

    switch(d3()){
        case 1:
            SetIntNoise("Escuchas el rumor de aguas en movimiento.\n");
            break;
        case 2:
            SetIntNoise("Te llega el murmullo del r�o.\n");
            break;
        case 3:
            SetIntNoise("La brisa parece sonar de otro modo en las cercan�as de este "
            "caudal de agua.\n");
            break;
    }

    switch(d3()){
        case 1:
            SetIntSmell("Hueles a tierra h�meda y fresca.\n");
            break;
        case 2:
            SetIntSmell("El aroma es aqu� m�s intenso y reconoces el olor de la tierra"
            " mojada.\n");
            break;
        case 3:
            SetIntSmell("La brisa es aqu� m�s h�meda y te trae los olores del r�o.\n");
            break;
    }

    if(d6()==1)
        AddItem(PNJ("marhalt/bicho_orilla"), REFRESH_DESTRUCT, 1);

    AddDetail(({"suelo", "tierra", "arena"}), "Esta parte del suelo es ligeramente "
        "pantanosa, porque recibe la humedad de las aguas del r�o Kandal que se "
        "extiende a tus pies.\n  La vegetaci�n se hace m�s tupida y m�s tipica de "
        "las orillas de los r�os, y el olor a htierra h�meda es m�s penetrante.\n");
    AddDetail(({"rio","r�o","agua","aguas","corriente"}), "La corriente del agua "
        "transcurre de este a oeste, no tiene mucha fuerza, pero en algunos recodos "
        "quiz� sea algo peligroso.\n Algunos pececillos se dejan ver nadando "
        "tranquilamente.\n");
    AddDetail("orilla", QueryIntLong());
    AddDetail(({"peces","pececillos","pez"}), "Curiosos peces nadan tranquilamente por "
        "las aguas del r�o, Quiz� puedas pescar alguno.\n");
    AddRoomCmd("pescar", "cmd_pescar");
    AddRoomCmd("beber", "cmd_beber");
    AddRoomCmd(({"nadar", "ba�arse"}), "cmd_nadar");
    SetSoundEnvironment(SF(snd_ambiente), 35);
}

int cmd_nadar(){
    write("Esta parte del r�o puede ser peligrosa para nadar, busca otra parte m�s "
        "segura donde puedas darte un chapuz�n.\n");
    return 1;
}

int cmd_beber(string str) {
    if (!str || str=="agua"){
        if (TP->QueryDrink() >= TP->QueryMaxDrink()){
            return notify_fail("Ya est�s llen"+AO+" de agua, no puedes beber m�s.\n",
            NOTIFY_NOT_VALID);
        }
        TP->AddDrink(5);
    write("Te agachas en el borde del r�o, coges un poco de agua con las manos y te "
        "la bebes.\n");
        say(TP->QueryName()+" se acerca al borde del r�o y bebe agua cogi�ndola con "
        "las manos.\n");
        return 1;
    }
    return notify_fail("Tienes abundante abua en el r�o para beber, aprov�chala.\n",
    NOTIFY_NOT_VALID);
}

int cmd_pescar(){
    int hab_pescar, pescando;
    object cebo, trucha;
    //La formula para pescar.
    hab_pescar = random(TP->QueryInt()+TP->QueryDex()+TP->QueryLevel());
    switch(hab_pescar){
        case 0..25: pescando=d3(2); break; //As� nunca saldr� un 1.
        case 26..50: pescando=d6(); break;
        case 51..75: pescando=d4(); break;
        case 76..100: pescando=d3(); break;
        default: pescando=d2(); break; // para jugadores de muy alto nivel.
    }

    if (present("ca�a",TP))
    {
        if (cebo=(present("cebo", TP)))
        {
            write("Te pones a pescar con paciencia...\n");
            say(CAP(TP->QueryName())+ " se pone a pescar pacientemente...\n");
            trucha = clone_object(GOBJETO("comida/marhalt/trucha"));

            switch(pescando){
                case 1:
                    write("Y tras excasos segundos notas que alg�n pez ha picado el "
                    "anzuelo, rapidamente sacas la ca�a del r�o con una buena  trucha.\n");
                    say(" Y tras pocos segundos la vuelve a sacar con una buena trucha.\n");
                    //se le va a caer si lleva mucho peso encima.
                    if (trucha->move(TP,M_SILENT)!=ME_OK )
                    {
                        write("Despu�s de haber tenido la trucha en tu poder, se te escurre"
                        " y se vuelve a caer al r�o dando botes.\n  Quiz� llevas demasiadas"
                        " cosas encima para aguantar algo vivo.\n");
                        say("T�rpemente se le vuelve a caer la trucha al r�o, por llevar "
                        "demasiadas cosas encima y no poder sujetar algo vivo.\n");
                    }
                    destruct(cebo);
                    return 1;
                    break;

                case 2:
                    switch(d2()){
                        case 1: //del case 2.
                            write("Y tras unos minutos consigues pescar una trucha "
                            "que sacas rapidamente.\n");
                            say(" Y tras unos minutos consigue sacar una buena trucha.\n");
                            if (trucha->move(TP,M_SILENT)!=ME_OK )
                            {
                                write("Despu�s de haber tenido la trucha en tu poder, "
                                "se te escurre y se vuelve a caer al r�o dando botes.\n"
                                "  Quiz� llevas demasiadas cosas encima para aguantar "
                                "algo vivo.\n");
                              say("T�rpemente se le vuelve a caer la trucha al r�o, "
                              "por llevar demasiadas cosas encima y no poder sujetar "
                              "algo vivo.\n");
                            }
                            destruct(cebo);
                            return 1;
                            break;
                        case 2: //del case 2.
                            write("Pero tras varios minutos sacas la ca�a del r�o y te "
                            "percatas que los peces se han comido el cebo sin picar en "
                            "el anzuelo.\n");
                            say("Pero tras varios minutos mira con sorpresa el anzuelo "
                            "vac�o.\n");
                            destruct(cebo);
                            return 1;
                            break;
                    }

                case 3..4:
                    switch(d3()){
                        case 1: //del case 3 y 4.
                            write("Y tras unos minutos consigues pescar una trucha que "
                            "sacas rapidamente.\n");
                            say(" Y tras unos minutos consigue sacar una buena trucha.\n");
                            if (trucha->move(TP,M_SILENT)!=ME_OK )
                            {
                                write("Despu�s de haber tenido la trucha en tu poder, se"
                                " te escurre y se vuelve a caer al r�o dando botes.\n  "
                                "Quiz� llevas demasiadas cosas encima para aguantar "
                                "algo vivo.\n");
                                say("T�rpemente se le vuelve a caer la trucha al r�o, "
                                "por llevar demasiadas cosas encima y no poder sujetar "
                                "algo vivo.\n");
                            }
                            destruct(cebo);
                            return 1;
                            break;
                        case 2: //del case 3 y 4.
                            write("Pero tras varios minutos sacas la ca�a del r�o y te "
                            "percatas que los peces se han comido el cebo sin picar en "
                            "el anzuelo.\n");
                            say("Pero tras varios minutos mira con cara de asombro "
                            "el anzuelo vac�o.\n");
                            destruct(cebo);
                            return 1;
                            break;
                        case 3: //del case 3 y 4.
                            write("Tras algunos minutos consigues pescar una pieza "
                            "enorme...\n Sacas la ca�a rapidamente del r�o, pero el "
                            "pescado da un fuerte tir�n y consigue soltarse del anzuelo"
                            " volviendo al agua.\n");
                            say(" Tras varios minutos saca rapidamente la ca�a del "
                            "r�o con una gran pieza en el anzuelo, pero el pescado da "
                            "un tir�n y vuelve a caer al agua.\n");
                            destruct(cebo);
                            return 1;
                            break;
                    }

                case 5..6:
                    switch(d2()){
                        case 1: //del case 5 y 6.
                            write("Pero tras varios minutos sacas la ca�a del r�o y "
                            "te percatas que los peces se han comido el cebo sin picar "
                            "en el anzuelo.\n");
                            say("Pero tras varios minutos mira con mala cara que el "
                            "anzuelo est� vac�o.\n");
                            destruct(cebo);
                            return 1;
                            break;
                        case 2: //del case 5 y 6.
                            write("Tras algunos minutos consigues pescar una pieza "
                            "enorme...\n Sacas la ca�a rapidamente del r�o, pero el "
                            "pescado da un fuerte tir�n y consigue soltarse del "
                            "anzuelo volviendo al agua.\n");
                            say(" Tras varios minutos saca rapidamente la ca�a del "
                            "r�o con una gran pieza en el anzuelo, pero el pescado da "
                            "un tir�n y vuelve a caer al agua.\n");
                            destruct(cebo);
                            return 1;
                            break;
                    }
            }
        }else{
            return notify_fail("Los peces no van a picar por amor al arte, necesitar�s"
            " algo de cebo.\n");
        }
    }
    return notify_fail("Para pescar necesitas una ca�a de pescar.\n");
}

public void NotifyDayStateChange(mixed data, int newstate)
{
    ::NotifyDayStateChange(data, newstate);
    snd_ambiente(newstate);
}

private varargs string snd_ambiente(int newstate)
{
    int hora;
    string sonido;

    if (newstate) hora = newstate;
    else hora = QueryServer()->QueryState();
    if(hora==ND_NIGHT || hora==ND_PREDAWN || hora==ND_DAWN || hora==ND_PRENIGHT)
    {
        sonido = SND_AMBIENTES("rio_grillos");
    }
    else
    {
        sonido = SND_AMBIENTES("rio_bosque");
    }
    if (newstate && sonido != last_sound)
    {
        stop_sounds(TO);
        play_sound(TO, sonido, 0, 35, -1);
    }
    last_sound = sonido;
    return sonido;
}



