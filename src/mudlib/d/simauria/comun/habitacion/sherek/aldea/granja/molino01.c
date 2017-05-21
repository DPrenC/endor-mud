/* Archivo: /d/simauria/comun/habitacion/abadia/granja/molino00.c
* Descripción: sótano del molino de la granja.
* Autor: Lug y Yalin.
* Fecha: 17/05/2006
*/

#include "path.h"
#include <sounds.h>
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("la parte inferior del molino");
    SetIntLong("Te encuentras en el sótano del molino de la aldea de Sloch. "
        "Aquí es donde van depositados los rodeznos o rodetes que mueven la "
        "maquinaria. hacia el oeste puedes ver un arco, por el este entra el "
        "agua del río que es captada aguas arriba con un banzao, y, a la "
        "entrada del agua, hay una reja de metal. En la parte baja puedes "
        "ver un estrechamiento del canal que introduce el agua del molino.\n"
        "Una escalerilla que asciende es la salida de esta estancia.\n");
    SetIntNoise("Escuchas la corriente del agua al pasar y el giro de las "
        "palas del molino.\n");
    SetIntSmell("Huele a humedad y a madera mojada.\n");
    SetIntBright(20);
    AddDetail(({"arco"}), "una especie de arco que es por donde se le da "
        "salida al agua hacia el cauce del río tras haber pasado por el "
        "molino.\n");
    AddDetail(({"banzao"}), "Es una especie de viga que desvía el agua hacia "
        "el canal.\n");
    AddDetail(({"reja","reja de metal"}), "Está colocada entre el canal y la "
        "entrada del agua en el interior del molino para evitar la entrada "
        "en la maquinaria de hojas, ramas o aquellos elementos que puedan "
        "ocasionar problemas.\n");
    AddDetail(({"estrechamiento","parte baja"}), "Se trata de un sistema de "
        "conducción casi vertical, de forma cuadrangular que está fabricado "
        "en piedra. En la zona demayor estrechamiento puedes ver la paradera.\n");
    AddDetail(({"paradera"}), "sirve para desviar la corriente de agua fuera "
        "del campo de funcionamiento del rodete y así impulsar o bien que se "
        "pare o que arranque todo el sistema.\n");
    AddDetail(({"rodete","rodezno"}), "Se trata de una rueda que gira al "
        "recibir la presión del agua. Es la pieza motriz del molino, formada "
        "por un número de palas, llamadas también cucharas, unidas a la maza "
        "del árbol que gira en posición horizontal. El mecanismo está "
        "totalmente fabricado con madera de roble y todo él descansa sobre "
        "una pieza llamada marrana.\n");
    AddDetail(({"marrana", "viga"}), "Es un madero sobre el que descansa el "
        "rodezno para evitar que éste se desgaste contra el lecho de piedra "
        "del suelo y así, en caso de problemas, poder cambiarlo con "
        "facilidad. Puedes ver también un cable sujeto al mecanismo.\n");
    AddDetail(({"cable"}), "está enganchado al mecanismo y asciende hacia la "
        "parte superior del molino.\n");
    AddDetail(({"suelo"}), "Es un lecho de roca maciza cruzado por su mitad "
        "por el canal de paso del agua y la hidráulica del molino.\n");
    AddDetail(({"pared", "paredes"}), "Están formadas aquí por grandes rocas "
        "que han sido talladas para hacer el sótano y poder pasar la fuerza "
        "de la corriente por él. Hay humedad por todos lados haciendo que "
        "las rocas rezumen.\n");
    AddDetail(({"techo"}), "Lo forman los maderos del suelo de la parte "
        "superior. Grandes vigas lo soportan atravesando de pared a pared.\n");
    AddDetail(({"viga", "vigas"}), "Son grandes troncos que soportan el peso "
        "del techo. En sus extremos se hunden en las paredes para descargar "
        "la presión en ellas.\n");
    AddExit("arriba", SHERALD("granja/molino00"));
    SetSoundEnvironment(SND_AMBIENTES("molino_a"));
}
