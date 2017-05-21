/* Habitacion de Control de dominio de Akallab
DESCRIPCION:   La función de esta habitación es dar información sobre
el estado de un dominio.

*/

#include <nightday.h>
#include <colours.h>
#include <properties.h>
#include <rooms.h>
#include "path.h"

inherit ROOM;

#define NDATOS 1

private object *habscargadas=({});
public varargs void CargarArray();
int Listar(string str);
void Hora();
private static int ArrayCargado;
int hora,minuto,dia,mes,anyo,estacion;
string _domain_;
string season;


init () {
    add_action("informe","informe");
    add_action("donde","donde");
    add_action("listar","listar");
    add_action("SetDominio","dominio");
    ::init();
}

create(){
    ::create();

    _domain_ = "ninguno";
    SetIntLong("Ésta es la habitación de control de los dominios del mud. Desde aquí "
        "podrás observar el estado de tu dominio y sus habitaciones, asi como ver "
        "que se está cociendo por ahi.\n"//
        "El dominio supervisado actualmente es: "+capitalize(_domain_)+"\n"//
        "Ves un cartel colgado de la pared.\n");
    SetIntShort("la Sala de control de Dominios");
    SetIndoors(1);
    SetIntBright(50);
    Set("CleanUp",0);
    ArrayCargado = 0;
    Hora();

    AddReadMsg(({"cartel","Cartel","letrero","Letrero"}),(("Sala de Control de "+capitalize(_domain_)+".\n"//
        "Actualmente los comandos operativos son:\n\n"//
        "-"TC_BOLD+"dominio"+TC_NORMAL+" <nombre del dominio>: Establece sobre que dominio informar.\n"//
        "-"TC_BOLD+"informe"+TC_NORMAL+": Muestra un informe resumido del estado del dominio.\n"//
        "-"TC_BOLD+"donde"+TC_NORMAL+" <jugador>: Te dice en que dominio esta el jugador.\n"//
        "-"TC_BOLD+"listar"+TC_NORMAL+"<>: te muestra una lista de:\n"//
        "     <habitaciones>: todas las habitaciones registradas del dominio.\n"//
        "     <habitaciones cargadas>: todas las habitaciones del dominio cargadas en memoria.\n"//
        "     <jugadores>: todos los jugadores que están actualmente en el dominio.\n")));

    AddDetail(({"cartel","letrero"}),(("Se trata de un cartel que hay colgado en una de las paredes. Quizás deberías leerlo.\n")));

    AddExit("norte",TORRE("piso2/center"));


}

int SetDominio(string str) {
    string dominio;

    if(!str) {
        /* write("Los dominios válidos ahora mismo son: Limbo, Simauria, Akallab, Kenton, "
            "Lad-laurelin, Kha-annu y Goldhai.\nEl dominio actual es: "+_domain_+"\n"); */
            write("Dominios válidos: Aman, pais-bree, eriador y montanyas-nubladas.\nEl dominio actual es: "+_domain_+"\n");
        return 1;
    }
    dominio = lower_case(str);

    switch(dominio){

        case "simauria":
            _domain_ = "simauria";
            break;

        case "akallab":
            _domain_ = "akallab";
            break;

        case "goldhai":
            _domain_ = "goldhai";
            break;

        case "lad-laurelin":
            _domain_ = "lad-laurelin";
            break;

        case "kha-annu":
            _domain_ = "kha-annu";
            break;

        case "kenton":
            _domain_ = "kenton";
            break;

        case "limbo":
            _domain_ = "limbo";
            break;
case "pais-bree":
            _domain_ = "pais-bree";
            break;
case "eriador":
            _domain_ = "eriador";
            break;
case "montanyas-nubladas":
            _domain_ = "montanyas-nubladas";
            break;
case "aman":
            _domain_ = "aman";
            break;
        default:
            write("Dominios válidos:  eriador, aman, montanyas-nubladas y pais-bree.\n");
            return 1;
    }
    write("El dominio activo es: "+TC_BOLD+capitalize(_domain_)+TC_NORMAL+".\n");
    SetIntLong("Ésta es la habitación de control de los dominios de Endor-Mud. Desde aquí\n"
        "podrás observar el estado de tu dominio y sus habitaciones, asi como ver\n"
        "que se está cociendo por ahi.\n"//
        "El dominio supervisado actualmente es: "+capitalize(_domain_)+"\n"//
        "Ves un cartel colgado de la pared.\n");
    return 1;

}
// Esta Funcion lee el registro de habitaciones y mete en el array habscargadas
// las habitaciones que estan cargadas en memoria

public varargs void CargarArray() {

    object *habitaciones;
    string nombre;
    int i;

    habscargadas=({});
    habitaciones = m_indices("/obj/lib/register"->QueryRegister("/log/register/dominios/"+_domain_+"/habitaciones.o"));
    for(i=0;i<sizeof(habitaciones);i++) {
        nombre = to_string(habitaciones[i]);
        if (find_object(nombre)) habscargadas += ({habitaciones[i]});
    }
    ArrayCargado=1;
}

//Funcion para saber la hora

void Hora() {

    hora=CHRONOS->QueryHour();
    minuto=CHRONOS->QueryMinute();
    dia=CHRONOS->QueryDay();
    mes=CHRONOS->QueryMonth();
    anyo=CHRONOS->QueryYear();
    switch(CHRONOS->QueryEstacion())
    {
    case 1: season="invierno";    break;
    case 2: season="primavera";	break;
    case 3: season="verano";	break;
    case 4: season="otoño";		break;
    }
    season="una estacion muy rara";
}

/*Como todas las habs del dominio se cargan en la lista, aqui
hay una funcioncita para saber cuantas habs hay cargadas en
memoria
*/


int HabitacionesCargadas()
{
    CargarArray();
    return sizeof(habscargadas);
}

//Función para averiguar en que dominio esta el player


string EnQueDominioEstoy(object player) {

    string *donde,path,dominio,nombre;
    object env;


    env=environment(player);
    path=to_string(env);
    donde=explode(path,"/");
    if (to_string(player) == "Ze/us") return ("perdido en el siglo.");
    if (!path) return("en ningún lado.\n");
    else if (donde[1] == "d") dominio=donde[2];
    else if(donde[1] == "std") return("el vacío");
    else return("los dominios de "+donde[2]);
    return dominio;


}
//Función para saber cuantos jugadores estan en el dominio

int CuantosEstanAqui() {

    object *usuarios, player;
    int i, cuantos;

    cuantos=0;
    usuarios=users();
    for(i=0;i<sizeof(usuarios);i++)
    {
        player=usuarios[i];
        if (EnQueDominioEstoy(player) == _domain_) cuantos++;
    }
    return cuantos;
}

//Función provisional para saber si rula la de en donde estoy. :)

donde(str) {

    object player;

    player=find_object(lower_case(str));
    if (find_object(lower_case(str))) write(player->QueryShort()+ " esta en "+EnQueDominioEstoy(player)+".\n");
    else {
        write("Ese jugador no existe o no esta conectado.\n");
        return 1;
    }
    return 1;

}

//Función que genera un informe sobre el dominio
informe() {

    if (_domain_ == "ninguno") {
        write("No hay ningún dominio seleccionado.\n");
        return 1;
   	}
    Hora();
    write(TC_BOLD+TC_GREEN+TC_BG_RED+"********************************************************************\n"//
        "******************"+TC_NORMAL+TC_BOLD+TC_CYAN+"  Informe sobre el dominio  "TC_BOLD+TC_GREEN+TC_BG_RED+"**********************\n"//
        "******************"+TC_NORMAL+TC_BOLD+TC_CYAN+"         "+upper_case(_domain_)+"            "+TC_BOLD+TC_GREEN+TC_BG_RED+"**********************\n"//
        "********************************************************************\n\n"+TC_NORMAL+//
        "                    Ahora mismo son las "+hora+":"+minuto+"\n"//
        "            Estamos a día "+dia+" del mes "+mes+" del año "+anyo+"\n"//
        "                            Es "+season+"[0m\n\n"+//
        "\n\n"//
        "Número de habitaciones registradas: "+sizeof(m_indices("/obj/lib/register"->QueryRegister("/log/register/dominios/"+_domain_+"/habitaciones.o")))+"\n"//
        "Número de habitaciones cargadas: "+HabitacionesCargadas()+"\n"//
        "Número de players en "+capitalize(_domain_)+": "+CuantosEstanAqui()+"\n");


    return 1;
}

int listar(string str) {

    object *habitaciones;
    string nombre;
    object *usuarios, player;
    int i;

    if(!str) {
        write("Las opciones actuales de "+TC_BOLD+"listar"+TC_NORMAL+" son:\n"//
            "habitaciones, habitaciones cargadas y jugadores.\n");
        return 1;
    }
    if (_domain_ == "ninguno") {
        write("No hay ningún dominio seleccionado.\n");
        return 1;
    }
    switch(str) {
        case "habitaciones":
            write("Las habitaciones registradas de "+capitalize(_domain_)+" son:\n\n");
            habitaciones = m_indices("/obj/lib/register"->QueryRegister("/log/register/dominios/"+_domain_+"/habitaciones.o"));
            STR->smore(habitaciones,TP->QueryPageSize());
            return 1;
            break;


        case "habitaciones cargadas":
            write("Las Habitaciones de "+capitalize(_domain_)+" cargadas en memoria son:\n\n");
            CargarArray();
            STR->smore(habscargadas,TP->QueryPageSize());
            return 1;
            break;

        case "jugadores":
            if (CuantosEstanAqui() == 0) {
                write("No hay ningún jugador en "+_domain_+".\n");
                return 1;
            }

            usuarios=users();
            write("En "+capitalize(_domain_)+" estan:\n\n");
            for(i=0;i<sizeof(usuarios);i++){
                player=usuarios[i];
                if (EnQueDominioEstoy(player) == _domain_)
                    write(player->QueryShort()+"\n");
            }
            return 1;
            break;
    }
    write("Las opciones actuales de "+TC_BOLD+"listar"+TC_NORMAL+" son:\n"//
        "habitaciones, habitaciones cargadas y jugadores.\n");
    return 1;
}