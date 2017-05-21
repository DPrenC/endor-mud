/* Archivo: /d/simauria/comun/habitacion/abadia/granja/molino00.c
* Descripci�n: s�tano del molino de la granja.
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
    SetIntLong("Te encuentras en el s�tano del molino de la aldea de Sloch. "
        "Aqu� es donde van depositados los rodeznos o rodetes que mueven la "
        "maquinaria. hacia el oeste puedes ver un arco, por el este entra el "
        "agua del r�o que es captada aguas arriba con un banzao, y, a la "
        "entrada del agua, hay una reja de metal. En la parte baja puedes "
        "ver un estrechamiento del canal que introduce el agua del molino.\n"
        "Una escalerilla que asciende es la salida de esta estancia.\n");
    SetIntNoise("Escuchas la corriente del agua al pasar y el giro de las "
        "palas del molino.\n");
    SetIntSmell("Huele a humedad y a madera mojada.\n");
    SetIntBright(20);
    AddDetail(({"arco"}), "una especie de arco que es por donde se le da "
        "salida al agua hacia el cauce del r�o tras haber pasado por el "
        "molino.\n");
    AddDetail(({"banzao"}), "Es una especie de viga que desv�a el agua hacia "
        "el canal.\n");
    AddDetail(({"reja","reja de metal"}), "Est� colocada entre el canal y la "
        "entrada del agua en el interior del molino para evitar la entrada "
        "en la maquinaria de hojas, ramas o aquellos elementos que puedan "
        "ocasionar problemas.\n");
    AddDetail(({"estrechamiento","parte baja"}), "Se trata de un sistema de "
        "conducci�n casi vertical, de forma cuadrangular que est� fabricado "
        "en piedra. En la zona demayor estrechamiento puedes ver la paradera.\n");
    AddDetail(({"paradera"}), "sirve para desviar la corriente de agua fuera "
        "del campo de funcionamiento del rodete y as� impulsar o bien que se "
        "pare o que arranque todo el sistema.\n");
    AddDetail(({"rodete","rodezno"}), "Se trata de una rueda que gira al "
        "recibir la presi�n del agua. Es la pieza motriz del molino, formada "
        "por un n�mero de palas, llamadas tambi�n cucharas, unidas a la maza "
        "del �rbol que gira en posici�n horizontal. El mecanismo est� "
        "totalmente fabricado con madera de roble y todo �l descansa sobre "
        "una pieza llamada marrana.\n");
    AddDetail(({"marrana", "viga"}), "Es un madero sobre el que descansa el "
        "rodezno para evitar que �ste se desgaste contra el lecho de piedra "
        "del suelo y as�, en caso de problemas, poder cambiarlo con "
        "facilidad. Puedes ver tambi�n un cable sujeto al mecanismo.\n");
    AddDetail(({"cable"}), "est� enganchado al mecanismo y asciende hacia la "
        "parte superior del molino.\n");
    AddDetail(({"suelo"}), "Es un lecho de roca maciza cruzado por su mitad "
        "por el canal de paso del agua y la hidr�ulica del molino.\n");
    AddDetail(({"pared", "paredes"}), "Est�n formadas aqu� por grandes rocas "
        "que han sido talladas para hacer el s�tano y poder pasar la fuerza "
        "de la corriente por �l. Hay humedad por todos lados haciendo que "
        "las rocas rezumen.\n");
    AddDetail(({"techo"}), "Lo forman los maderos del suelo de la parte "
        "superior. Grandes vigas lo soportan atravesando de pared a pared.\n");
    AddDetail(({"viga", "vigas"}), "Son grandes troncos que soportan el peso "
        "del techo. En sus extremos se hunden en las paredes para descargar "
        "la presi�n en ellas.\n");
    AddExit("arriba", SHERALD("granja/molino00"));
    SetSoundEnvironment(SND_AMBIENTES("molino_a"));
}
