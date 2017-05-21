/*

    Nombre      : granManzanoEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Delante del gran manzano

*/

#include "./path.h"
#include <skills.h>
#include <combat.h>
#include <moving.h>
#include <sounds.h>
inherit SIM_ROOM;

public int cmd_trepar(string str){
    object manzano = find_object(ENALHAB"poblado/manzanal/manzano01");

    if (!str || (str != "arbol" && str != "�rbol" && str != "al arbol" && str != "al �rbol"
        && str!="manzano" && str!="al manzano")) return 0;
    if (TP->QueryTP()<1)
        return notify_fail("Has agotado tus fuerzas, descansa un rato.\n",
        NOTIFY_NOT_VALID);
    if (TP->UseSkill(HAB_TREPAR) < 0){
    	write("Comienzas a trepar por las gruesas ramas del �rbol. Sin embargo, "
  	    "tu inexperiencia hace que pierdas pie, y sin poder evitarlo, caigas al suelo.\n");
        say(CATP+" comienza a trepar por las gruesas ramas del �rbol. Sin embargo, sin "
        "poder evitarlo, pierde pie y cae al suelo.\n");
        tell_room(ENALHAB"poblado/manzanal/manzano01", CAP(TNAME)+
        " intenta subir hasta aqu�, pero cae torpemente.\n");
        TP->AddTP(-d3());
        play_sound(manzano, SND_SUCESOS("caida_fuerte"), 0, 50);
        play_sound(TO, SND_SUCESOS("caida_fuerte"));

        TP->Defend(d12(),TD_APLASTAMIENTO,DEFEND_NOMSG);
        return 1;
    }else {
   	    TP->move(ENALHAB"poblado/manzanal/manzano01",M_SPECIAL,({
        "comienza a ascender por las gruesas ramas del �rbol...\n"
        "Milagrosamente, consigue llegar a la copa",
        "llega trepando desde la base del �rbol",
        "Comienzas a trepar por las ramas del �rbol...\n"
        "Tras un rato de arduo ascenso, consigues llegar a la copa"}));
        TP->AddTP(-d3());
        return 1;
    }
}

create() {
    ::create();

    SetIndoors(0);
    SetLocate("Poblado de Enalel");
    SetIntShort("el manzanal, junto a un gran manzano");
    SetIntLong("Est�s en la parte m�s profunda del manzanal de Fhainfos. Delante "
    "de ti est� el m�s magestuoso y viejo manzano que hayas visto en tu vida. Un "
    "clima de solemnidad te hace reberenciar este �rbol. Al sur se encuentra el "
    "sendero de salida.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail(({"manzano","gran manzano","magestuoso manzano","�rbol","arbol"}),
    "Es un magestuoso manzano de altas ramas.\n");
    AddDetail(({"ramas","rama"}),"Son ramas muy fuertes pero est�n muy alto. "
    "Quiz�s trepando podr�as llegar a la copa.\n");
    AddDetail(({"manzana","manzanas","fruto","frutos","fruta","frutas"}),"Est�n "
    "demasiado altas como para poder observarlas bien pero parecen brillar con luz propia.\n");
    AddRoomCmd("trepar","cmd_trepar");
    AddExit("sur",ENALHAB"poblado/manzanal/manzanal06");
}

init(){
    ::init();
    call_out("merodeador", 1);
}

public void merodeador(){
    tell_room(ENALHAB"poblado/manzanal/manzano01",
    "Ves como "+CAP(TNAME)+" merodea por la base del gran manzano.\n");
}

