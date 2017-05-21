/****************************************************************************
Fichero: torre1_01.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("la planta baja de la torre de la Inmolación");
    SetIntLong("Estás en una sala en la planta baja del torreón de la Inmolación, tan "
    "solo iluminada por la luz que se cuela por el pasadizo del sudeste, y las "
    "antorchas colocadas en las paredes, pues los gruesos muros de los cimientos de la "
    "fortificación no dejan pasar ni un solo rayo de sol. Se puede observar la curvatura "
    "del muro que proporciona la forma redondeada al torreón en su parte exterior. Ésta "
    "sala parece tener la mera función de distribuidor para las demás estancias del "
    "edificio, ya que al norte y oeste hay puertas, al noroeste se ve el inicio de una "
    "empinada escalera de caracol ascendente mientras que al sureste un pasadizo "
    "desemboca en el patio de armas. Suelos y paredes están tan bien construidos que "
    "pese a su palpable antigüedad, se mantienen sin mostrar ninguna clase de grieta "
    "o desperfecto.\n");
    AddDetail("suelo", "El suelo está formado por pesadas losas de piedra perfectamente "
    "encajadas entre sí.\n");
    AddDetail(({"paredes", "muros"}), "Se percibe la diferencia entre el muro exterior "
    "del torreón, mas grueso, y construído con bloques mucho mas grandes que los de los "
    "tabiques que lo dividen.\n");
    AddDetail("bloques", "Grandes bloques de piedra que forman los muros.\n");
    AddDetail("antorchas", "Antorchas encajadas en soportes de hierro sujetos a la pared.\n");
    SetIntBright(30);

    AddExit("sudeste", "./pasadizo1");
    AddExit("norte", "./torre1_02");
    AddExit("noroeste", "./escalera1_1");
    AddExit("oeste", "./torre1_04");
    AddDoor("norte", "una puerta de madera",
    "Es una puerta vieja de madera sin ningún dibujo ni relieve, por ahí se sale de "
    "los barracones.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
    AddDoor("oeste", "una puerta vieja de madera",
    "Es una asquerosa puerta de madera, en muy mal estado y horriblemente fea.\n",
    ({"puerta", "puerta de madera", "puerta del oeste", "puerta vieja"}));

    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT);
}

