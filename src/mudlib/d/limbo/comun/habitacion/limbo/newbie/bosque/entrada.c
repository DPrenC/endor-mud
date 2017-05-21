/*
DESCRIPCION  : entrada al parque de newbies
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/entrada.c
MODIFICACION :

[a] Angor@Simauria

10-08-98 [a] Creacion
26-10-98 [a] Restringido el acceso al parque
29-06-99 [a] Corregido el bug que atascaba a los PNJ, wrapeado del texto

--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>
#include <wizlevels.h>
inherit ROOM;
#define NEWBIELEVEL 4      //acceso al parque
#define NOMBRE  capitalize(TP->QueryName())
#define AO     (TP->QueryGenderEndString())
#define S2     (TP->QueryGender()==2?"a":"e")

int ir_parque()
{
    if (!(TP->QueryIsPlayer())) return TP->move(BOSQUE("pradera04"),M_SPECIAL,
        ({"se va hacia el oeste","llega desde el oeste"}));
    if ((TP->QueryLevel()>NEWBIELEVEL) && !(query_wiz_level(TP)))
    {
        write("Avanzas por el camino hacia el oeste pero de repente eres detenid"+AO+" por una "
            "fuerza invisible. Lo intentas varias veces con el mismo resultado.\nSigreb te "
            "dice: ¿No puedes pasar? Eso es por que los dioses sólo dejan entrar a la zona de "
            "entrenamiento a los más novatos. Tú debes tener nivel suficiente como para "
            "buscarte la vida sin más favores de los dioses.\n");
        say(NOMBRE+" avanza hacia el oeste y es retenid"+AO+" por una fuerza invisible. Sigreb "
            "le dice que eso ocurre porque ya tiene demasiado nivel.\n",TP);
        return 1;
    }
    else return TP->move(BOSQUE("pradera04"),M_SPECIAL,
        ({"se va hacia el oeste","llega desde el oeste","Sigreb te dice:'Hasta luego!'\n"}));
    return 1;
}

int ir_se()
{
    if (TP->QueryIsPlayer()) return TP->move(LIMBO("camino17"),M_SPECIAL,
        ({"se va hacia el sudeste","llega desde el sudeste","Sigreb te dice:'Hasta luego!'\n"}));
    return 1; //los PNJ no salen del parque
}

create()
{
    ::create();
    SetIntShort("la entrada al parque");
    SetIntLong("A partir de aquí se abre un claro en el camino que atraviesa el bosque. En "
        "medio del claro hay una inmensa roca que no se te ocurre cómo demonios habrá podido "
        "llegar hasta aquí. En ella hay grabados una gran cantidad de símbolos extraños. De "
        "repente te das cuenta de que sobre la roca se halla un pequeño kender que te mira con "
        "curiosidad. Junto a la base de la roca hay un poste con un mapa.\n");
    AddDetail(({"roca","piedra"}),"La roca es una inmensa mole de piedra de forma irregular. "
        "Observas que alguien se tomó la molestia de pulir una superficie plana en su parte "
        "media en la que, a modo de letrero, se han realizado varias inscripciones con "
        "símbolos que te son desconocidos. La parte superior de la roca es bastante plana.\n"
        "Sigreb te dice: ¿A que es un pedazo de pedrusco? Pero es MI pedrusco.'\n");
    AddDetail(({"símbolos","simbolos","inscripciones"}),"Tu dominio sobre lenguas extrañas o "
        "antiguas es bastante pobre, por lo que no sabrías decir qué significan los símbolos "
        "tallados en la piedra.\nSigreb te dice: Vaya, interesado en los signos de la piedra, "
        "¿eh? Je, je. Sé que son uhmmm...., antiguos.\n");
    AddDetail(({"isla","isla Limbo","isla limbo","Limbo","limbo"}),"La isla Limbo es el lugar "
        "mágico de Simauria donde habitan los dioses. Gracias a ellos, en este lugar las almas "
        "de los seres se encarnan y dan sus primeros pasos para vivir en este mundo.\n");
    AddDetail(({"parque","entrenamiento","novatos","parque de entrenamiento"}),"Este sendero "
        "conduce al parque de entrenamiento para novatos, una zona dispuesta por los dioses "
        "para que los recién llegados a este mundo puedan practicar con las armas y así ganar "
        "algo de experiencia y nivel antes de emprender aventuras en el gran mundo.\n");
    AddDetail(({"poste","poste con mapa","mapa","informacion"}),
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Mapa de la Isla Limbo\n"   //
  "~~~~~~~~~  ~~~~~~~~~  ~~~~~~~\n"                          //
  "~~~~~~~~ ^^ _       ^^ ~~~~~~  T torre de wizards\n"      //
  "~~~~~~~~ ^^  \\     ^^^^ ~~~~~  A Templo de Asthar\n"     //
  "~~~~~~~~~~    |N    __  ~~~~~  S Stonehenge\n"            //
  "~~~~~~~~~~p_,--X._/'  '-p~~~~  M monolito\n"              //
  "~~~~~~~~~ ^ __    \\  ^ ~~~~~~  N parque para novatos\n"  //
  "~~~~~~~~ ^ / M\\__,-f---mmT~~~  P Pueblo\n"               //
  "~~~~~~~~ ^ \\__/S   | ^ ~~~~~~\n"                         //
  "~~~~~~~~~ ^       /\\_^ ~~~~~~ (f) fuente   (m) puente\n" //
  "~~~~~~~~~p---P---'   A ~~~~~~ (^) montanya (~) mar\n"     //
  "~~~.~~~~ ^   |    ^^  ~~~~~~~ (u) puerto   (p) playa\n"   //
  "~~/|\\~~ ^^ ~~u~~ ^^^^ ~~~~~~~\n"                         //
  "~~~|N~~ ^^ ~~~~~~ ^^ ~~~~~~~~  X usted esta aqui\n"       //
  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    SetIntNoise("Oyes el trinar de los pájaros y el roce de las ramas mecidas por el viento.\n");
    SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
    SetLocate("parque de isla Limbo");
    SetIndoors(0);
    AddExit("sudeste",SF(ir_se));
    AddExit("oeste",SF(ir_parque));
    AddItem(PNJ("sigreb"), REFRESH_DESTRUCT);
}

init()
{
    ::init();
    if (TP) say("Sigreb dice: '¡Hola "+NOMBRE+"!'\n");
}
