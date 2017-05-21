/*****************************************************************************************
 ARCHIVO:       bosque47.c
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

    SetIntShort("la cámara Real");
    SetIntLong("La belleza y majestuosidad de esta sala son indescriptibles, y "
        "amenazan con colapsar tus sentidos. Una brillante neblina de color dorado, "
        "ligera como una telaraña, fluye por toda la habitación, dando a las cosas un "
        "aspecto irreal y a la vez fastuoso. Las paredes parecen ser de cuarzo rosa, "
        "y en ellas ves el brillo de miles de partículas de diamante. Enormes macizos "
        "de flores exóticas cubren los rincones, impregnando toda la sala con su "
        "intenso y exuberante aroma. Al fondo puedes contemplar un delicado trono "
        "hecho de cristal y filigrana de oro en forma de mariposa, flanqueado por dos "
        "hermosos rosales en flor.\n");
    AddDetail("neblina", "Está motivada por la mezcla de aromas, fragancias y "
        "luces.\n");
    AddDetail(({"pared", "paredes"}), "Son de un tono rosado pálido y parece que "
        "tienen luz propia.\n");
    AddDetail(({"partículas", "particulas", "partícula", "particula", "diamantes"}),
        "Son diminutas lágrimas de diamante, incrustadas en las paredes y dotandolas "
        "de una vida que, sin ellas, sería inexistente.\n");
    AddDetail(({"flores", "macizos", "flores exóticas"}), "Liberan una mezcla extraña "
        "y penetrante de olores.\n");
    AddDetail(({"trono", "delicado trono"}), "No es ni opulento ni lujoso, sin embargo "
        "es de una hermosura indescriptible.\n");
    AddDetail(({"rosales", "rosal"}), "Nacen directamente de las paredes. Están "
        "repletos de grandes rosas aterciopeladas y multitud de capullos ansiosos por "
        "expandir la hermosura que contienen.\n");
    AddDetail("suelo", "El suelo esta cubierto por una densa capa de hierba verde "
        "azulada, poblada a su vez por diminutas lorecillas de colores, añil, rojo, "
        "amarillo, celeste y violeta.\n");
    SetIndoors(1);
    SetIntBright(40);

    SetIntSmell("Respiras infinidad de aromas diferentes que te embriagan, un vértigo "
        "sensual se apodera de ti y te hace sentir un ligero mareo.\n");
    SetIntNoise("Una dulce y cristalina música acaricia tus oídos, no sabrías definir "
        "de dónde procede, y en realidad, tampoco te importa.\n");

    AddExit("suroeste", HAB_BOSQUE_HADAS("bosque42.c"));

    AddItem(PNJ_VALMAR("reina_hadas.c"), REFRESH_DESTRUCT, 1);
    AddItem(PNJ_VALMAR("ruergh.c"), REFRESH_DESTRUCT, 1);
    AddItem(PNJ_VALMAR("hada_sirviente.c"), REFRESH_DESTRUCT, 2);
}
