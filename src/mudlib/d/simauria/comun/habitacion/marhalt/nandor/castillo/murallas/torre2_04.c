/****************************************************************************
Fichero: torre2_03.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: la torre nordeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("la planta baja del torreón de Cónor");
    SetIntLong("Estás en una sala en la planta baja del torreón de Cónor, tan "
    "solo iluminada por la luz que se cuela por el pasadizo del suroeste, y las "
    "antorchas colocadas en las paredes, pues los gruesos muros de los cimientos de la "
    "fortificación no dejan pasar ni un solo rayo de sol. Se puede observar la curvatura "
    "del muro que proporciona la forma redondeada al torreón en su parte exterior. Ésta "
    "sala parece tener la mera función de distribuidor para las demás estancias del "
    "edificio, ya que al norte y este hay puertas, al nordeste se ve el inicio de una "
    "empinada escalera de caracol ascendente mientras que al suroeste un pasadizo "
    "desemboca en el patio de armas.\n Suelos y paredes están tan bien construidos que "
    "pese a su palpable antigüedad, se mantienen sin mostrar ninguna clase de grieta "
    "o desperfecto.\n");
    AddDetail("suelo", "El suelo está formado por pesadas losas de piedra perfectamente "
    "encajadas entre sí.\n");
    AddDetail(({"paredes", "muros"}), "Se percibe la diferencia entre el muro exterior "
    "del torreón, mas grueso, y construído con bloques mucho mas grandes que los de los "
    "tabiques que lo dividen.\n");
    AddDetail("bloques", "Grandes bloques de piedra que forman los muros. Uno de ellos "
    "tiene unas marcas casi imperceptibles.\n");
    AddDetail("antorchas", "Antorchas encajadas en soportes de hierro sujetos a la pared.\n");
    AddDetail("marcas", "Te agachas junto al muro y recorres con tus dedos las marcas "
    "de uno de los bloques que parecen trazar la forma de un ave que recuerda "
    "vagamente a un águila, aunque las incisiones en la piedra están tan desgastadas "
    "que no se puede asegurar nada, tal vez sea un simple defecto natural de la piedra.\n");
    SetIntSmell("Hueles un persistente hedor que parece proceder de la puerta del este.\n");
    SetIntBright(30);

    AddExit("este", "./torre2_01");
    AddExit("nordeste", "./escalera2_1");
    AddExit("norte", "./torre2_03");
    AddExit("suroeste", "./pasadizo2");
    AddDoor("este", "una puerta vieja de madera",
    "Es una asquerosa puerta de madera, en muy mal estado y horriblemente fea.\n",
    ({"puerta", "puerta de madera", "puerta del este", "puerta vieja",
        "puerta vieja de madera"}));
    AddDoor("norte", "una puerta de madera",
    "Es una puerta vieja de madera sin ningún dibujo ni relieve.\n",
    ({"puerta", "puerta del norte", "puerta de madera"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT);
}

