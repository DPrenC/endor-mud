/*****************************************************************************************
 ARCHIVO:       bosque37.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCI�N:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("el pasillo invernal");
    SetIntLong("Est�s en un amplio pasillo de aspecto algo t�trico, mucho m�s oscuro y "
        "fr�o que los anteriores. Inexplicablemente, el suelo de piedra est� cubierto "
        "de escarcha, y una g�lida brisa acaricia tu cuerpo y empuja contra ti "
        "diminutos copos de nieve. En el suelo, entre la escarcha, peque�os charcos de "
        "agua congelada brillan como joyas.\n");
    AddDetail("suelo", "Est� formado por grandes losas de piedra de granito y "
        "totalmente cubierto por una capa de escarcha.\n");
    AddDetail("escarcha", "Cruje delicadamente sobre tus pies.\n");
    AddDetail(({"copos", "copos de nieve"}), "Caen con suavidad sobre tu piel d�ndote "
        "una agradable sensaci�n de frescor.\n");
    AddDetail(({"charcos", "joyas", "agua"}), "Son peque�os charcos cogelados en los "
        "que aparecen diminutos arcoiris.\n");
    SetIndoors(1);
    SetIntBright(30);

    SetIntSmell("Un olor fr�o y est�ril invade tu olfato, haci�ndote pensar en p�ramos "
        "desolados desiertos de vida.\n");
    SetIntNoise("Oyes el suave soplo del viento y el crujido de tus pisadas en la "
        "nieve.\n");

    AddExit("este", HAB_BOSQUE_HADAS("bosque38.c"));
    AddExit("norte", HAB_BOSQUE_HADAS("bosque40.c"));
}
