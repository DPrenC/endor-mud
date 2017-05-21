/* Archivo: /d/simauria/comun/habitacion/abadia/granja/molino00.c
* Descripci�n: Planta del molino de la granja.
* Autor: Lug y Yalin.
* Fecha: 17/05/2006
*/

#include "path.h"
#include <sounds.h>
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el molino de la aldea de Sloch");
    SetIntLong("Est�s en una sala cuadrada destinada a la zona de molienda. "
        "Puedes ver aqu� la maquinaria dedicada a convertir el grano  del "
        "cereal en harina lista para su consumo tanto por los humanos como "
        "por las bestias.\n Tienes al noroeste la salida del recinto y una "
        "escalera desciende a la parte baja.\nEn dos hileras, a ambos lados, se apilan los "
        "sacos de trigo y harina.\n");
    SetIntNoise("Escuchas el traqueteo de la maquinaria y de las piedras al "
        "moler. Bajo tus pies oyes el paso del agua a presi�n.\n");
    SetIntSmell("Huele a cereal y a harina.\n");
    SetIntBright(30);
    AddDetail(({"suelo"}), "Est� formado por grandes y robustos tableros de "
        "madera. Por el centro salen las muelas y los dispositivos de "
        "trabajo del molino. Puedes ver tambi�n una manivela con un cable "
        "enroscado y un hueco en una de las esquinas por donde se desciende "
        "a la parte baja del molino.\n");
    AddDetail(({"manivela","cable"}),"forma parte del dispositivo que "
        "regula la separaci�n entre las muelas para que la harina salga m�s "
        "o menos gruesa.\n");
    AddDetail(({"escalera","escaleras","escalerilla"}),"Ves una empinada "
        "escalerilla de madera que desciende hasta el s�tano del molino "
        "donde se encuentra la hidr�ulica.\n");
    AddDetail(({"pared", "paredes"}), "Est�n construidas con mamposter�a no "
        "demasiado bien hecha pero lo suficientemente robusta como para "
        "aguantar muchos a�os.\n");
    AddDetail(({"techo"}), "Est� compuesto de maderas sin desbastar que "
        "forman una especie de artesonado r�stico.\n");
    AddDetail(({"maquinaria"}), "Est� compuesta por un dep�sito para el "
        "grano, una canaleta de bajada y las muelas.\n");
    AddDetail(({"deposito","dep�sito","moxega"}), "Es un recipiente de forma "
        "de tronco piramidal invertido que sirve para depositar el grano que "
        "va a ser molido. Presenta un orificio en la parte inferior que "
        "permite que el grano pase lentamente a la canaleta y caiga hacia "
        "las muelas poco a poco entre las ruedas del molino.\n");
    AddDetail(({"canaleta"}), "Es un canal de madera que lleva el grano "
        "hacia las muelas.\n");
    AddDetail(({"muela","muelas","piedra","piedras"}), "son dos piedras "
        "cil�ndricas embutidas en un tambor. La inferior,  o frag�n, est� "
        "fija, la superior, o volandera, se mueve y tritura el grano.\n");
    AddDetail(({"tambor"}), "Es un armaz�n cil�ndrico de madera que sirve "
        "para cubrir las dos muelas. Su funci�n es impedir que el grano "
        "roturado y convertido en harina caiga por los laterales. Presenta "
        "una abertura por donde sale la harina al caj�n.\n");
    AddDetail(({"cajon", "caj�n"}), "Es una amplia caja de madera donde "
        "va a parar la harina despu�s que los granos de cereal sean molidos.\n");
    AddDetail(({"saco","sacos"}),"Son bolsas de tosca arpillera, llenos de trigo los unos, y "
        "los otros de harina. Cuando el molinero vierte un saco en el dep�sito, coloca el saco "
        "vac�o junto al caj�n, para llenarlo con la harina que se va produciendo.\n");
    AddExit("abajo", SHERALD("granja/molino01"));
    AddExit("noroeste", SHERALD("granja/granja03"));
    SetSoundEnvironment(SND_AMBIENTES("molino_m"));
}
