/*****************************************************************************************
 ARCHIVO:       bosque37.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("el pasillo invernal");
    SetIntLong("Estás en un amplio pasillo de aspecto algo tétrico, mucho más oscuro y "
        "frío que los anteriores. Inexplicablemente, el suelo de piedra está cubierto "
        "de escarcha, y una gélida brisa acaricia tu cuerpo y empuja contra ti "
        "diminutos copos de nieve. En el suelo, entre la escarcha, pequeños charcos de "
        "agua congelada brillan como joyas.\n");
    AddDetail("suelo", "Está formado por grandes losas de piedra de granito y "
        "totalmente cubierto por una capa de escarcha.\n");
    AddDetail("escarcha", "Cruje delicadamente sobre tus pies.\n");
    AddDetail(({"copos", "copos de nieve"}), "Caen con suavidad sobre tu piel dándote "
        "una agradable sensación de frescor.\n");
    AddDetail(({"charcos", "joyas", "agua"}), "Son pequeños charcos cogelados en los "
        "que aparecen diminutos arcoiris.\n");
    SetIndoors(1);
    SetIntBright(30);

    SetIntSmell("Un olor frío y estéril invade tu olfato, haciéndote pensar en páramos "
        "desolados desiertos de vida.\n");
    SetIntNoise("Oyes el suave soplo del viento y el crujido de tus pisadas en la "
        "nieve.\n");

    AddExit("este", HAB_BOSQUE_HADAS("bosque38.c"));
    AddExit("norte", HAB_BOSQUE_HADAS("bosque40.c"));
}
