/* Archivo: /d/simauria/comun/habitacion/abadia/granja/molino00.c
* Descripción: Planta del molino de la granja.
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
    SetIntLong("Estás en una sala cuadrada destinada a la zona de molienda. "
        "Puedes ver aquí la maquinaria dedicada a convertir el grano  del "
        "cereal en harina lista para su consumo tanto por los humanos como "
        "por las bestias.\n Tienes al noroeste la salida del recinto y una "
        "escalera desciende a la parte baja.\nEn dos hileras, a ambos lados, se apilan los "
        "sacos de trigo y harina.\n");
    SetIntNoise("Escuchas el traqueteo de la maquinaria y de las piedras al "
        "moler. Bajo tus pies oyes el paso del agua a presión.\n");
    SetIntSmell("Huele a cereal y a harina.\n");
    SetIntBright(30);
    AddDetail(({"suelo"}), "Está formado por grandes y robustos tableros de "
        "madera. Por el centro salen las muelas y los dispositivos de "
        "trabajo del molino. Puedes ver también una manivela con un cable "
        "enroscado y un hueco en una de las esquinas por donde se desciende "
        "a la parte baja del molino.\n");
    AddDetail(({"manivela","cable"}),"forma parte del dispositivo que "
        "regula la separación entre las muelas para que la harina salga más "
        "o menos gruesa.\n");
    AddDetail(({"escalera","escaleras","escalerilla"}),"Ves una empinada "
        "escalerilla de madera que desciende hasta el sótano del molino "
        "donde se encuentra la hidráulica.\n");
    AddDetail(({"pared", "paredes"}), "Están construidas con mampostería no "
        "demasiado bien hecha pero lo suficientemente robusta como para "
        "aguantar muchos años.\n");
    AddDetail(({"techo"}), "Está compuesto de maderas sin desbastar que "
        "forman una especie de artesonado rústico.\n");
    AddDetail(({"maquinaria"}), "Está compuesta por un depósito para el "
        "grano, una canaleta de bajada y las muelas.\n");
    AddDetail(({"deposito","depósito","moxega"}), "Es un recipiente de forma "
        "de tronco piramidal invertido que sirve para depositar el grano que "
        "va a ser molido. Presenta un orificio en la parte inferior que "
        "permite que el grano pase lentamente a la canaleta y caiga hacia "
        "las muelas poco a poco entre las ruedas del molino.\n");
    AddDetail(({"canaleta"}), "Es un canal de madera que lleva el grano "
        "hacia las muelas.\n");
    AddDetail(({"muela","muelas","piedra","piedras"}), "son dos piedras "
        "cilíndricas embutidas en un tambor. La inferior,  o fragón, está "
        "fija, la superior, o volandera, se mueve y tritura el grano.\n");
    AddDetail(({"tambor"}), "Es un armazón cilíndrico de madera que sirve "
        "para cubrir las dos muelas. Su función es impedir que el grano "
        "roturado y convertido en harina caiga por los laterales. Presenta "
        "una abertura por donde sale la harina al cajón.\n");
    AddDetail(({"cajon", "cajón"}), "Es una amplia caja de madera donde "
        "va a parar la harina después que los granos de cereal sean molidos.\n");
    AddDetail(({"saco","sacos"}),"Son bolsas de tosca arpillera, llenos de trigo los unos, y "
        "los otros de harina. Cuando el molinero vierte un saco en el depósito, coloca el saco "
        "vacío junto al cajón, para llenarlo con la harina que se va produciendo.\n");
    AddExit("abajo", SHERALD("granja/molino01"));
    AddExit("noroeste", SHERALD("granja/granja03"));
    SetSoundEnvironment(SND_AMBIENTES("molino_m"));
}
