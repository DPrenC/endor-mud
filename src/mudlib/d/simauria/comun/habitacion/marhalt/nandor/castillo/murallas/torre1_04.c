/****************************************************************************
Fichero: torre1_03.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>
inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("unas letrinas");
    SetIntLong("Indudablemente estás en las letrinas del castillo, pues solo hace falta "
    "hechar un vistazo a las toscas aberturas practicadas en el suelo junto al muro mas "
    "alejado y la pila de paja sucia y ennegrecida por un enjambre de moscas gordas "
    "de zumbar perezoso.\n");
    AddDetail("paja", "Un montón de paja sucia, pues al parecer alguien ha olvidado "
    "arrojarla por las aberturas del suelo tras usar un puñado.\n");
    AddDetail("aberturas", "Unos orificios redondos abiertos en el suelo que desembocan "
    "en el foso.\n");
    SetIntSmell("Demostrando una gran audacia, una soberana estupidez o unos gustos "
    "realmente depravados, aspiras profundamente el espeso aire que te hace lagrimear, "
    "para doblarte a continuación estremeciéndote por las arcadas.\n");
    AddDetail("aspilleras", "Estrechas aberturas situadas en la zona alta del muro "
    "exterior, cuyo grosor solo permite colarse una leve luminosidad.\n");
    AddDetail("suelo", "El suelo está formado por pesadas losas de piedra perfectamente "
    "encajadas entre sí.\n");
    AddDetail(({"paredes", "muros"}), "Se percibe la diferencia entre el muro exterior "
    "del torreón, mas grueso, y construído con bloques mucho mas grandes que los de los "
    "tabiques que lo dividen.\n");
    AddDetail("bloques", "Grandes bloques de piedra que forman los muros.\n");
    AddDetail("antorchas", "Antorchas encajadas en soportes de hierro sujetos a la pared.\n");

    SetIntBright(21);

    AddExit("este", "./torre1_01");
    AddDoor("este", "una puerta vieja de madera",
    "Es una asquerosa puerta de madera, en muy mal estado y horriblemente fea.\n",
    ({"puerta", "puerta de madera", "puerta del este", "puerta vieja"}));

    SetLocate("el castillo de Nandor");
    AddRoomCmd("cagar", "cmd_cagar");
}

public int cmd_cagar(){
    object mierda=clone_object("/std/food");
    mierda->SetShort("un montoncito de escrementos");
    mierda->SetLong("Es una pequeña pila de heces aparentemente recién excretadas.\n "
    "Tienen la textura y el color marronáceo típico de esta repugnante materia.\n");
    mierda->AddId(({"mierda", "escremento", "cagarruta", "ece", "eces", 
      "montoncito de eces", "escrementos"}));
    mierda->SetGender(GENDER_FEMALE);
    mierda->SetSize(P_SIZE_SMALL);
    mierda->SetWeight(200);
    mierda->SetSmell("Olfateas la pila de heces y su olor acre impregna por entero "
    "tus fosas nasales. Un gusto a excrementos inunda tu boca.\n");
    mierda->SetFoodMsgs(({"Te metes en la boca los excrementos a puñados hasta que no "
      "caben más...\n Mascas la pastosa y cálida materia tragando con dificultad "
      "por el carácter  biscoso de las heces.\n",
    "se llena la boca de puñados de heces hasta que sus carrillos quedan hinchados  "
    "por la gran cantidad de excrementos... con un sonido  húmedo y chapoteante "
    "mastica con fruición y traga ruidosamente.\n"}));
    mierda->SetFoodStuff(-10);
    mierda->SetFoodHeal(-10);

    if (TP->QueryFood() > TP->QueryMaxFood()/2){
        mierda->move(TO, M_SILENT);
        write("Te agachas sobre el inmundo agujero practicado en el suelo y dececas "
        "un montoncito de excrementos pero al mirar atrás te das cuenta de que han "
        "caído junto al agujero en vez de en su interior.\n Finges no haberte dado "
        "cuenta y hechas mano de un puñado de paja sucia y lleno de moscas para "
        "limpiarte el trasero.\n");
        say(CAP(TNAME)+ " se acuclilla sobre el agujero del piso y dececa una pila de "
        "excrementos que caen sobre el suelo con un sonido blando... A continuación "
        "coge un puñado de paja sucia y se limpia cuidadosamente el trasero.\n");
        TP->AddFood(-55);
        return 1;
    }else{
    write("Ahora no tienes ganas.\n");
    return 1;
    }
}

