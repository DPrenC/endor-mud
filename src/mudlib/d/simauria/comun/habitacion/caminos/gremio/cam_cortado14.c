/****************************************************************************
Fichero: cam_cortado14.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: El camino entre montañas que se dirije a la cueva de los trolls.
****************************************************************************/


#include "./path.h"
#include <sounds.h>
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";
#define AO       (this_player()->QueryGender()== GENDER_FEMALE ? "a" : "o")
create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntShort("un pequeño manantial");
    SetIntLong(" Te encuentras en un abrigado recodo del desfiladero cerrado por "
    "tres lados por altisimas paredes. En la pared del fondo surge borboteando un "
    "diminuto chorro de agua, que fluye alegremente entre los espesos arbustos, "
    "que crecen al abrigo del viento y alimentados por el manantial. Éste podría "
    "parecer un buen lugar para que cualquier tipo de animal, que habitara esta zona,"
    " bebiera y se ocultara, pero no hay ninguna huella ni señal de seres vivos.\n");
    AddDetail(({"arbustos", "arbusto", "vegetacion", "vegetación", "maleza", "helechos",
        "helecho", "plantas", "planta"}),
        " Pequeños arbustos, cubiertos de diminutas florecillas, se aprietan unos "
        "contra otros mezclados con frondosos helechos.\n");
    AddDetail(({"agua", "charco", "charca", "manantial"}),
    "Es un pequeño manantial que se ha formado de forma natural debido al agua que fluye "
    "de la montaña.\n");
    AddRoomCmd("beber", "cmd_beber");
    AddExit("noreste", "./cam_cortado12");
    SetSoundEnvironment(SND_AMBIENTES("manantial"));
}

int cmd_beber(string str) {
    if (!str || str=="agua"){
        if (TP->QueryDrink() >= TP->QueryMaxDrink()){
            return notify_fail("Ya estás llen"+AO+" de agua, no puedes beber más.\n",
            NOTIFY_NOT_VALID);
        }
        TP->AddDrink(5);
    write("Te agachas en el borde del manantial , coges un poco de agua con las manos y te "
        "la bebes.\n");
        say(TP->QueryName()+" se acerca al borde del manantial y bebe agua cogiéndola con "
        "las manos.\n");
        return 1;
    }
    return notify_fail("Tienes abundante agua en el manantial para beber, aprovéchala.\n",
    NOTIFY_NOT_VALID);
}

