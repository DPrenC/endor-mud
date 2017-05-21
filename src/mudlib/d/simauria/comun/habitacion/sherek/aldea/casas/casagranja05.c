/* Archivo:         casagranja05.c
   Autor:           Yalin y Lug
   Descripción:     cocina en la planta alta de la casa de los administradores en la granja de la aldea de Sloch
   Fecha:           25/05/2006
*/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("la cocina");
    SetIntLong("Estás en una pequeña cocina en la planta alta de la casa de "
        "los administradores de la granja de la aldea de Sloch.\nA tu "
        "alrededor puedes ver los diferentes anaqueles con los instrumentos "
        "de cocina, unas sillas y una mesa donde comer. También hay una "
        "chimenea de piedra con el hogar a media altura.\nHacia el este "
        "vuelves al comedor.\n");
    SetIntSmell("Huele a comida.\n");
    SetIntNoise("Puedes escuchar el sonido amortiguado del resto de la casa "
        "y de la calle.\n");
    AddDetail(({"suelo"}), "Se trata de un suelo de maderas pulidas excepto "
        "en la zona del hogar que está hecho de piedra.\n");
    AddDetail(({"pared", "paredes"}), "Son paredes de mampostería pintadas de "
        "color blanco. En la zona más próxima a la chimenea puedes ver que "
        "están manchadas con el hollín que arrastra el humo al hacer fuego "
        "en el hogar.\n");
    AddDetail(({"techo"}), "El techo es un artesonado de tablas estrechas "
        "encajadas entre sí que separan la estancia del contacto directo con "
        "el tejado.\n");
    AddDetail(({"anaquel", "anaqueles"}), "es el lugar donde se colocan "
        "todos los utensilios de cocina y los envases que contienen los "
        "alimentos almacenados.\n");
    AddExit("este", SHERALD("casas/casagranja04"));
}
