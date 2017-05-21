/****************************************************************************
Fichero: cabanya_guardabosques1.c
Autor: Ratwor
Fecha: 03/02/2007
Descripci�n: el exterior de la caba�a del guardabosques.
****************************************************************************/


#include "./path.h"
#include <combat.h>
#include <moving.h>
#include <nightday.h>
#include <sounds.h>
#include <skills.h>
inherit SIM_ROOM;
public void snd_golpe();
private string last_sound;
public string snd_ambiente();

public string f_abajo(){
    object abajo = find_object(MARH("nandor/bosque/zona_guardabosques"));
    if(!abajo)
    return "La verdad es que est� muy alto esto.\n";
    write("Miras hacia abajo siguiendo la cuerda hasta el suelo, y puedes ver una "
        "porci�n de bosque como otras tantas, donde nacen los �rboles, donde est�n las "
        "plantas y donde est� el duro suelo si te cayeras de aqu�.\n" + abajo->Content());
    return "";
}

public int f_bajar(){
    if (TP->QueryIsPlayer()){
        if (TP->UseSkill(HAB_TREPAR) >= -10){
            TP->move(MARH("nandor/bosque/zona_guardabosques"), M_SPECIAL,
            ({"baja �gilmente por la cuerda hasta el suelo sin problema",
            "llega trepando por la cuerda desde arriba �gilmente",
            "bajas por la cuerda hasta el suelo sin problema"}));
            return 1;
        } else {
            TP->move(MARH("nandor/bosque/zona_guardabosques"), M_SPECIAL,
            ({"baja por la cuerda torpemente estamp�ndose contra el suelo",
            "baja por la cuerda desde la caba�a pero se cae dolorosamente estamp�ndose "
            "contra el suelo",
            "te dispones a bajar por la cuerda hasta el suelo, pero se te resvalan las "
            "manos y bajas m�s rapido de lo deseado d�ndote un fuerte golpe contra el "
            "suelo"}));
        TP->Defend(50,TD_APLASTAMIENTO, DEFEND_NOMSG);
        snd_golpe();
            return 1;
        }
    }
    return 0;
}

create()
{
    ::create();
    SetLocate("bosque de Marhalt");
    SetIntShort("lo alto de un gran roble");
    SetIntLong("Te encuentras en las alturas de un robusto roble, sobre una plataforma "
        "de madera solidamente construida, de la cual cuelga una gruesa cuerda hacia "
        "abajo. Tambi�n se encuentra aqu� la construcci�n de una peque�a caba�a"
        ", igualmente construida con madera de roble.\n Desde aq� puedes apreciar toda "
        "la parte noroeste del bosque de Marhalt, las monta�as del oeste, el r�o "
        "Kandal muy al norte, y m�s todav�a al norte la villa de Nandor con su "
        "alto campanario.\n ");
    SetSoundEnvironment(SF(snd_ambiente), 10);
    SetIndoors(0);
    AddDetail(({"construccion", "construcci�n", "caba�a","casa"}),
        "Se trata de una caba�a de madera de roble "
        "s�lidamente construida, que parece estar a prueba de cualquier inclemencia "
        "del tiempo, tan variable por estos bosques.\n  Quiz�s hallar�as algo "
        "interesante si echas un vistazo a su interior.\n");
    AddDetail("plataforma", "Es una superficie de madera donde est� asentada la "
        "caba�a. Hacia abajo cuelga una gruesa cuerda.\n");
    AddDetail("cuerda", "Es una gruesa cuerda fuertemente atada, la cual facilita "
        "el descenso hacia el suelo.\n");
    AddDetail(({"nandor", "villa", "villa de nandor", "campanario"}), "La villa de "
        "Nandor se recorta a lo lejos, destac�ndose su alto campanario sobre cualquier "
        "otra edificaci�n. Desde la altura en que est�s ves la parte superior de "
        "dicho campanario, el cual pertenece  al cementerio de Nandor.\n");
    AddDetail(({"rio", "r�o", "r�o Kandal", "kandal", "Kandal", "rio kandal",
        "r�o kandal"}), "Muy al norte puedes divisar una franja de este a oeste que "
        "debe ser el r�o Kandal, aunque desde esta distancia no se aprecia ning�n otro "
        "detalle al respecto.\n");
    AddDetail(({"monta�a", "monta�as", "picos", "pico de monta�a"}),
        "Desde tu posici�n en la altura del bosque puedes apreciar con mejor detalle "
        "las monta�as del oeste, a cuyos pies transcurre de norte a sur el camino "
        "Nandor-ishtria.\n Seguramente esas monta�as escondan curiosos desfiladeros.\n");
    AddDetail("camino", "Transcurre de norte a sur, desde la villa de Nandor "
        "serpenteando hasta el cruce que va a Gorat, ycontin�a en su direcci�n sur "
        "pasando por tu zona oeste, perdi�ndolo de vista algo m�s al sur.\n");
    AddDetail("suelo", "Si te refieres al suelo de esta plataforma es de madera de "
        "roble, pero si te refieres al del bosque... pues es el mismo que se ve "
        "desde abajo, pero aqu� est� bastante m�s lejos.\n");
    AddDetail("abajo", SF(f_abajo));
    AddDetail(({"reto�o", "reto�os", "arboles jovenes", "�rboles jovenes"}),
        "Son reto�os muy j�venes, en su mayor�a de robles y hayas, que son los "
        "�rboles que pueblan la mayor parte de este bosque.\n  Son plantas de color "
        "verde intenso y de escaso foliaje que no tapa las entradas de luz. Sus "
        "troncos son todav�a muy delgados como para pensar en talarlos.\n");
        AddDetail(({"vegetacion", "vegetaci�n", "plantas", "plantas jovenes"}),
        "Se trata de vegetaci�n de lo m�s variado en especie y colorido. Va desde "
        "hierbas hasta arbustos y malezas. Desprende un aroma silvestre que es "
        "caracter�stico de este bosque.\n Todas las plantas de este bosque son j�venes"
        " y de tama�o mediano. No tienen copas frondosas, pero s� un intenso colorido "
        "que llena de vida cada recodo del bosque.\n");
    AddDetail("troncos", "Son troncos de �rboles j�venes, algunos lo suficientemente "
        "grandes como para que alguien piense en talarlos, pero siempre lo bastante "
        "delgados como para que puedas mirar y hasta a veces avanzar por entre ellos.\n");
    AddDetail(({"follaje", "follajes"}), "Todo el follaje que ves en este bosque es "
        "poco frondoso, porque los �rboles han sido plantados recientemente.\n  Las "
        "ramas dejan lugar para que se filtre la luz, y en muchas de ellas ves "
        "brotes verdes que hacen pensar que en unos a�os, todo esto podr�a estar m�s "
        "tupido.\n");
    AddDetail(({"arbustos", "arbusto"}), "Por todas partes ves arbustos que crecen "
        "muy juntos, aunque no lo bastante espesos como para cerrarte el paso. No "
        "puedes identificar a qu� clase pertenecen porque observas una infinidad de "
        "variedades distintas.  Llama la atenci�n su colorido intenso.\n");
    AddDetail("maleza", "Todav�a se trata de maleza joven, vigorosa pero no invasiva "
        "del terreno, aunque sospechas que si no la cortan, con el tiempo puede "
        "volverse muy tupida. \n Son grupos de malezas de distintas clases que parecen "
        "poblar gran parte del suelo de este bosque.\n");
    AddDetail(({"bosque", "�rboles", "arboles"}), "todo a tu alrededor es bosque, "
        "hayas y robles adornan los alrededores en todas direcciones.\n Es un bosque "
        "joven, lleno de vida y, como no, fauna que podr�a llegar a ser molesta en "
        "seg�n que situaciones.\n");

    AddRoomCmd("gritar", "cmd_gritar");
    SetIntNoise("Escuchas distintos sonidos de bosque.\n");
    SetIntSmell("Hueles a naturaleza.\n");
    AddExit("entrar","./cabanya_guardabosques2");
    AddExit("abajo", SF(f_bajar));
    AddExit("bajar", SF(f_bajar));
    HideExit("bajar",1);
}

public int cmd_gritar(string str){
    tell_room(MARH("nandor/bosque/bosque117"), "Escuchas que alguien grita desde las "
        "alturas hacia el sudeste.\n");
    tell_room(MARH("nandor/bosque/bosque118"), "Escuchas que alguien grita desde las "
        "alturas hacia el suroeste.\n");
    tell_room(MARH("nandor/bosque/bosque123"), "Escuchas que alguien grita desde las "
        "alturas hacia el oeste.\n");
    tell_room(MARH("nandor/bosque/bosque127"), "Escuchas que alguien grita desde las "
        "alturas hacia el nordeste.\n");
    tell_room(MARH("nandor/bosque/bosque128"), "Escuchas que alguien grita desde las "
        "alturas hacia el norte.\n");
    tell_room(MARH("nandor/bosque/bosque129"), "Escuchas que alguien grita desde las "
        "alturas hacia el noroeste.\n");
    tell_room(MARH("nandor/bosque/cabanya_guardabosques2"), "Escuchas que fuera de la "
        "caba�a gritan:\n '"+str+"'.\n");
    if (!str){
        tell_room(MARH("nandor/bosque/zona_guardabosques"),"Escuchas que "+CAP(TNAME)+
        " grita desde arriba.\n");
        return 0;
    }else{
        tell_room(MARH("nandor/bosque/zona_guardabosques"), "Escuchas que "+CAP(TNAME)+
        " grita desde arriba:\n '"+str+"'.\n");
        return 0;
    }
    return 0;
}

public void snd_golpe(){
    object abajo = find_object(MARH("nandor/bosque/zona_guardabosques"));
    play_sound(TO, SND_SUCESOS("caida_fuerte"), 0, 30);
    play_sound(abajo, SND_SUCESOS("caida_fuerte"));
}

public varargs string snd_ambiente(int newstate){
    int hora;
    string sonido;
    if (newstate)
    // si la funci�n se llama con un estado nuevo, es que ha sido llamada por NotifyDayStateChange.
    // Si no, ha sido llamada por el SoundEnvironment
    {
        hora = newstate;
    }
    else
    {
        hora = QueryServer()->QueryState();
    }

    if(hora==ND_NIGHT || hora==ND_PREDAWN || hora==ND_DAWN || hora==ND_PRENIGHT){
        sonido = SND_AMBIENTES("noche_grillos");
    }else{
        sonido = SND_AMBIENTES("bosque1");
    }
    if (newstate && sonido != last_sound)
    // Si se ha llamado desde el NotifyDayStateChange y el sonido ha cambiado con respecto al
    // �ltimo, se hace stop_sound y PlaySound
    // pues si no los que est�n dentro no se enterar�an del cambio.
    // Si el sonido es el mismo no hacemos nada, ya que no tiene sentido pararlo y volverlo a iniciar
    // si va a seguir sonando el mismo
    {
        stop_sounds(TO);
        play_sound(TO, sonido, 0, 10, -1);
    }
    last_sound = sonido;
    return sonido;
}

public void NotifyDayStateChange(mixed data, int newstate)
{
    ::NotifyDayStateChange(data, newstate);
    snd_ambiente(newstate);
}

