/****************************************************************************
Fichero: casa_leñador.c
Autor: Ratwor
Fecha: 27/01/2007
Descripción: la cabaña del leñador del bosque de Marhalt.
****************************************************************************/

#include "./path.h"
#include <skills.h>
#include <sounds.h>
inherit SIM_ROOM;

int chimenea=0;
public int QueryChimenea() { return chimenea; }

string f_ventana(){
    object fuera = find_object(MARH("nandor/bosque/zona_leñador"));
    tell_room(MARH("nandor/bosque/zona_leñador"), CAP(TNAME)+ " asoma la cabeza por "
        "el pequeño ventanuco de la cabaña mirando hacia afuera.\n");
    if (!fuera){
        write("Miras por el ventanuco y puedes ver varios montones de troncos apilados "
        "y preparados para entrar en cualquier chimenea cuando sea preciso.\n");
        return "";
    }else{
        write(" Miras por el ventanuco y puedes ver un claro dejado por los árboles "
        "permitiéndote observar la maleza y los arbustos que crecen por todas partes "
        "donde los robles y las hayas dejan sitio. Quizás este claro tenga que ver "
        "con la cantidad de troncos que pueden verse por aquí, troncos de árboles "
        "que han estado en esta zona pero que ahora han desaparecido por obra del "
        "trabajo de un hacha. Se cuentan distintos montones de ttroncos cortados y "
        "apilados, dispuestos para su uso inmediato.\n"+ fuera->Content());
        return "";
    }
    return "";
}

string  f_olores(){
    if (chimenea==1)
    return "Huele a madera ardiendo.\n";
    return "Hasta aquí llegan los aromas del bosque.\n";
}

string  f_sonidos(){
    if (chimenea==1)
    return "Se escucha arder la leña en el fuego de la chimenea.\n";
    return "Escuchas algunos pajarillos del bosque.\n";
}

string f_chimenea(){
    if (chimenea==1)
    return "Es una vieja chimenea de piedra que hace muy bien su papel de calentar "
        "esta estancia. Está encendida y notas un agradable calorcito del fuego de "
        "su interior.\n";
    return "Es una vieja chimenea de piedra que hace muy bien su papel de calentar "
        "esta estancia. Notarías un ambiente más caldeado si estuviera encendida, pero "
        "ahora mismo está apagada.\n";
}

create()
{
    ::create();
    SetLocate("bosque de Marhalt");
    SetIntShort("la cabaña de Corl");
    SetIntLong("Estás en la cabaña de Corl el leñador. Es un lugar bastante acogedor "
        "aunque muy rústico. Ves un camastro,una mesa de madera y un par de sillas "
        "también de madera, y junto a ellas una gran chimenea. Sobre ella, en una de las"
        " paredes, puedes ver un cuadro, y un poco más lejos, en un rincón, hay una "
        "figura de madera.\n Esparcidas aquí y allá, ves herramientas propias del "
        "trabajo de leñador.\n Cerca de la puerta hay un pequeñísimo ventanuco que, "
        "junto con la poca luz que entra de la puerta, no es suficiente para alumbrar "
        "practicamente nada, por lo que la estancia nunca se ve alumbrada por luz "
        "natural.\n");
    AddDetail(({"chimenea", "fuego"}), SF(f_chimenea));
    AddDetail("herramientas", "Son distintas herramientas de leñador sin importancia.\n");
    AddDetail(({"retrato","cuadro"}), "El cuadro representa a un hombre joven pero que "
        "es sin duda el propio Corl, acompañado de una mujer y de un muchacho que a "
        "juzgar por el parecido, sólo puede ser su hijo.\n  Los rumores que corren por la"
        " villa de Nandor dicen que todos menos el leñador murieron hace años en una "
        "incursión orca, y que ahora Corl se refugia en este bosque para soportar "
        "mejor sus días en soledad.\n");
    AddDetail(({"ninfa", "estatuilla", "estatua","figura", "figura de madera", "talla"}),
        "Se trata de la rústica representación de una ninfa, una figura esbelta y "
        "grácil de largos cabellos. Resaltan en su rostro unos labios gruesos y "
        "entreabiertos, y unos ojos tallados con tal maestría que parecen mirar a "
        "quien los mire.\n No está muy claro si la figura está enganchada en un pilar "
        "de la propia cabaña o sin embargo se ha tallado en él mismo.\n");
    AddDetail(({"madera", "troncos", "troncos apilados"}), "Distintos montones de "
        "troncos apilados y de diferentes tamaños.\n");
    AddDetail(({"camastro", "silla", "mesa"}), "Es el poco mobiliario de la cabaña.\n");
    SetIntNoise(SF(f_sonidos));
    SetIntSmell(SF(f_olores));
    AddRoomCmd("encender", "cmd_encender");
    AddRoomCmd("apagar", "cmd_apagar");
    AddDetail(({"ventana", "por ventana", "por la ventana", "através de la ventana",
        "atraves de la ventana", "ventanuco", "por el ventanuco", "por ventanuco",
        "atraves del ventanuco", "através del ventanuco"}), SF(f_ventana));
    AddExit("oeste","./zona_leñador");
    AddDoor("oeste", "una puerta", "La puerta de la cabaña para salir y entrar de ella.\n",
    ({"puerta", "puerta de la cabaña", "puerta de salida", "puerta del oeste"}));
}

int cmd_encender(string str){
    if (str=="chimenea" || str=="la chimenea" || str=="fuego" || str=="el fuego"){
        if (!chimenea){
            if(!present("encendedor",TP)) return notify_fail("Necesitas un encendedor.\n", NOTIFY_NOT_VALID);
            int encender = TP->UseSkill(HAB_FIRE);
            if(encender < -10)
                //say(CAP(TNAME)+" intenta encender la chimenea, pero no lo consigue.\n");
                return notify_fail("No atinas a encender el fuego con el encendedor, te "
                "falta experiencia.\n", NOTIFY_NOT_VALID);

            write("Consigues encender el fuego, la cabaña se ilumina ligeramente con "
            "las llamas y empieza a caldearse.\n");
            say(CAP(TNAME)+ " enciende el fuego de la chimenea, la estancia se ilumina"
            " ligeramente por la luz de las llamas y empiezas a notar el ambiente "
            "algo más caldeado.\n");
            TP->SetExplored();
            chimenea=1;
            SetIntBright(QueryIntBright()+25);
            play_sound(TO, SND_AMBIENTES("chimenea"), 0, 80, -1);
            SetSoundEnvironment(SND_AMBIENTES("chimenea"),80);
            return 1;
        }
        return notify_fail("el fuego ya está encendido.\n",NOTIFY_NOT_VALID);
    }
    return notify_fail("¿Qué quieres encender?.\n", NOTIFY_NOT_VALID);
}

    int cmd_apagar(string str){
    if (str=="chimenea" || str=="la chimenea" || str=="fuego" || str=="el fuego"){
        if (chimenea==1){
            chimenea=0;
            write("Esparces las brasas y el fuego se va apagando, atenuando a su vez "
            "la iluminación y el caldeamiento de la estancia.\n");
            say(CAP(TNAME)+ " apaga el fuego de la chimenea esparciendo las brasas. "
            "La estancia pierde un poco de luz y calor.\n");
            SetIntBright(QueryIntBright()-25);
            stop_sounds(all_inventory(TO));
            SetSoundEnvironment(0);
            return 1;
        }
        return notify_fail("El fuego ya está apagado.\n", NOTIFY_NOT_VALID);
    }
    return notify_fail("¿Qué quieres apagar?.\n", NOTIFY_NOT_VALID);
}

