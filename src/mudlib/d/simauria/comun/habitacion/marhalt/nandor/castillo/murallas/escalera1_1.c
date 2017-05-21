/****************************************************************************
Fichero: escalera1_1.c
Autor: Ratwor
Fecha: 30/03/2008
Descripci�n: la escalera de los torreones.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("una escalera de caracol");
    SetIntLong("Est�s en una empinada y angosta escalera de caracol que asciende por el "
    "coraz�n del torre�n. Los muros de piedra se cierran sobre ti, y tan solo alguna "
    "antorcha colocada en la pared ilumina los pelda�os desiguales. Es un lugar "
    "f�cilmente defendible, pues los atacantes solo podr�an avanzar de uno en uno, y la "
    "forma y angostura de la escalera har�an dif�cil cualquier combate.\n"
    "Al sudeste, atravesando un arco de piedra, se llega a una amplia sala.\n");
    AddDetail("bloques", "Grandes bloques de piedra que forman los muros.\n");
    AddDetail("antorchas", "Antorchas encajadas en soportes de hierro sujetos a la pared.\n");
    AddDetail("muros", "A derecha e izquierda, y uniendose en forma de b�veda sobre tu "
    "cabeza, los muros de piedra rodean la escalera.\n");
    AddExit("sudeste", "./torre1_01");
    AddExit("arriba", "./escalera1_2");
    }
