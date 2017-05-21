/****************************************************************************
Fichero: suelo_base.c
Autor: Kastwey
Fecha: 03/03/2006
Descripción: El suelo base de la arena, donde se meten los animalitos y eso.
****************************************************************************/


#include "path.h"
#include <rooms.h>
#include <nightday.h>


#define ANIMALES ({"ardilla", "ciervo_grande", "ciervo_peque", "conejo",\
                "gorrion", "lobo", "tucan", "zorro"})

#define D_HIERBAS "/d/limbo/comun/objeto/hierba/"

inherit AM_ARENA("arena_base");



public void AnadeDetalleEdificio(string direccion)
{
    // si hay algún detalle colocado por el AsignaIntLong, lo borramos
    RemoveDetail(({"edificio", "gremio"}));
    AddDetail(({"pared", "edificio", direccion, "gremio"}),
          "Hacia el " + direccion + " puedes ver una de las paredes del gremio, formada "
          "por grandes bloques de piedra unidos con precisión, casi sin dejar "
          "huecos entre ellos.\n");
}


public void AnadeDetalleLago(string direccion)
{
    AddDetail(({direccion,"lago"}), "Hacia el " + direccion + " puedes ver el "
              "lago que rodea esta isla. Sus aguas no son precísamente "
              "cristalinas, ya que tienen un tono verdoso, y aparecen repletas "
              "de algas de aspecto malsano.\n");
}

private void AnadeHierba(int num)
// Útil para entrenar la habilidad identificar plantas
// añade una hierba aleatoria del directorio de limbo.
// Pensaba copiar las hierbas aquí, pero me parece una tontería. Si alguna vez se
// hace un directorio para hierbas ya cambiaré el define en consecuencia.
{
    string *hierbas = get_dir(HERBS("*.c"));
    while (num-- > 0)
    {
        AddItem(HERBS(hierbas[random(sizeof(hierbas))]), REFRESH_REMOVE);
    }
}

private string mirar_grillos()
{
    int state = QueryServer()->QueryState();
    if (state != ND_NIGHT && state != ND_PREDAWN && state != ND_PRENIGHT) return 0;
    return "Aunque escuchas numerosos grillos cantar, por más que miras a tu "
           "alrededor no consigues ver ninguno.\n";
}

int cmd_coger(string str)
{
    int estado;
    if (   ((estado = QueryServer()->QueryState()) != ND_NIGHT && estado != ND_PREDAWN
        && estado != ND_PRENIGHT) || (!str || str != "grillo"))
    {
        return 0;
    }
    say(CAP(TNAME) + " intenta cazar un grillo, pero por más que mira y remueve en la "
        "hierba, finalmente no consigue atrapar ninguno.\n");
    return notify_fail("Te agachas sobre la húmeda hierba y comienzas a intentar "
                       "cazar un grillo. Aunque por el sonido dirías que los tienes "
                       "al alcance de la mano, por más que lo intentas no eres capaz ni "
                       "tan siquiera de ver uno.\n", NOTIFY_NOT_VALID);
}


private string AsignaIntLong()
// descripciones aleatorias
{
    string long;
    switch (d10())
    {
        case 1:
             long = "Te hallas en el bosque del gremio de las Kisalas. Grandes "
                    "árboles brotan por doquier, haciendo que el suelo aparezca "
                    "cubierto de sobresalientes raíces, con las que, de no andarte "
                    "con ojo, es muy posible que acabes tropezando.\n";
             break;
        case 2:
             long = "Te encuentras en un tupido bosque, en la isla del gremio "
                    "de las Kisalas. Los grandes árboles, muy próximos entre "
                    "sí, se yerguen esbeltos y majestuosos a tu alrededor, "
                    "entrelazándose sus ramas muy por encima de tu cabeza.\n";
             break;
        case 3:
             long = "Estás en el interior del bosque que rodea al gremio de "
                    "las Kisalas. Este es el lugar en el que las amazonas "
                    "más inexpertas del gremio se adentran para practicar "
                    "las diversas habilidades del mismo y enfrentarse a los "
                    "muchos animales que campan por este paraje.\n";
             break;
        case 4:
             long = "Te encuentras en el interior de un bosque, en la isla "
                    "del gremio de las Kisalas. A tu alrededor, se alternan "
                    "grandes árboles con pequeños retoños, producto de la "
                    "tala y repoblación que las amazonas deben realizar, a fin de  "
                    "conseguir la madera necesaria para la fabricación de "
                    "lanzas, arcos y flechas.\n";
             break;
        case 5:
             long = "Te hallas en el bosque que bordea el edificio del gremio "
                    "de las Kisalas. Por doquier puedes ver huellas, pequeñas "
                    "y grandes, causadas sin duda por la diversidad de animales "
                    "que campan por esta zona.\n";
             AddDetail("huellas", "Son huellas de diversas formas y tamaños, que se "
                                  "entrecruzan por el suelo en todas direcciones. "
                                  "Parece que este bosque está repleto de todo tipo de "
                                  "animales.\n");
             break;
        case 6:
             long = "Estás en un tupido bosque, en la isla del gremio de las "
                    "Kisalas. Los árboles, grandes y pequeños, se apiñan a tu "
                    "alrededor, entrecruzando raíces y ramas en intrincadas "
                    "y extrañas formas.\n";
             break;
        case 7:
             long = "Te encuentras en un pequeño bosque, en la isla del lago "
                    "Zinn. Puedes ver numerosos árboles a tu alrededor, "
                    "haciéndote difícil el avance en algunas ocasiones.\n";
             break;
        case 8:
             long = "Estás en el interior del bosque de entrenamiento de las "
                    "Kisalas. Aquí podrás encontrar gran cantidad de animales "
                    "con los que enfrentarte para ganar experiencia, así como "
                    "diversas construcciones para mejorar alguna de las "
                    "habilidades que el gremio te ofrece.\n";
             break;
        case 9:
             long = "Te hallas en un tupido bosque, en la isla del gremio de las "
                    "Kisalas. Miras a tu alrededor y no ves más que árboles, "
                    "árboles y más árboles, además de multitud de huellas de a saber "
                    "qué peligrosos animales.\n";
             AddDetail ("huellas", "Puedes ver varias huellas de un tamaño más que "
                                   "considerable. Quizás debas andarte con cuidado, "
                                   "por si te tropiezas con la clase de animal que "
                                   "ha podido causarlas.\n");
             break;
        case 10:
             long = "Te encuentras en el interior del bosque de la isla del lago "
                    "Zinn, en Goldhai. A tu alrededor, observas multitud de árboles, "
                    "así como una alfombra de hierbas y raíces que cubren la "
                    "totalidad del suelo.\n";
             break;


    }
    return long;
}

public mixed SetIntLong(mixed s)
{
    return ::SetIntLong(AsignaIntLong() + s);
}


create()
{
    int i;
    ::create();

    AddDetail(({"edificio","gremio"}), "En mitad del bosque, puedes ver el "
                "gran edificio que sirve como sede para el gremio de las Kisalas.\n");

    AddDetail(({"árboles", "arboles"}),
              "Por doquier ves árboles de todos los tamaños. En algunos lugares, "
              "su ramaje se entrecruza por encima de tu cabeza, creando intrincadas y "
              "extrañas sombras a tu alrededor.\n");

    AddDetail(({"grillo","grillos"}), SF(mirar_grillos));

    AddDetail(({"hierba","hierbas"}), "Por todos lados ves altas hierbas, que tapizan "
              "el suelo de este bosque.\n");

    AddDetail("suelo", "El suelo aparece alfombrado de todo tipo de hierbas, que "
              "en algunos lugares alcanzan más de medio metro de altura.\n");

    SetIntSmell("El olor de la tierra, la hierba y los árboles, se mezclan "
                "en tu nariz en una sinfonía de suaves aromas. Sin embargo, el fétido "
                "efluvio que emana el lago que rodea esta isla, arruina un tanto "
                "la sensación de pureza y serenidad del lugar.\n");


    for (i=0;i<random(4);i++)
    {
        AddItem(AM_PNJ_ARENA(ANIMALES[random(sizeof(ANIMALES))]),
                REFRESH_DESTRUCT, 1);
    }
    // tiramos un dado de seis caras. Si sale 3, añadimos x hierbas, donde x es
    // el resultado de tirar un dado de dos caras: una o dos hierbas.
    if (d6() == 3) AnadeHierba(d2());

    AddRoomCmd("coger","cmd_coger");
}


