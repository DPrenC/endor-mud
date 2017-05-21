/****************************************************************************
Fichero: base_minas.c
Autor: Riberales
Creación: 18/10/2005
Descripción: Habitación base para las minas de Kha-annu. Añado algo para ver
             el tema de permisos.
****************************************************************************/

#include "path.h"
#include <materials.h>
#include <moving.h>
#include <combat.h>
#include <properties.h>

inherit ROOM;

string planta;
int p_antorchas, p_posible_picar, p_veces_picadas, p_tipo_mineral, p_vision;
int cmd_picar();
void DetalleTecho();
void DetalleSuelo();



public int SetTipo(int i)
{
    return p_tipo_mineral = i;
}


public int QueryTipo()
{
    return p_tipo_mineral;
}

create()
{
    ::create();
    SetLocate("las minas de Kha-annu");
    SetIndoors(1);
    SetIntBright(5);
    AddRoomCmd("picar","cmd_picar");
    AddRoomCmd("coger","cmd_coger");
    DetalleSuelo();
    DetalleTecho();

    AddDetail(({"roca","rocas"}),
                "La roca está explotada, e incontables fragmentos de ésta "
                "están desperdigados por todo el suelo.\n");

    Set(P_TPORT,1);
}

void DetalleTecho()
{
    string techo;
    switch(random(3))
    {
        case 0:
            techo= "El techo está lleno de salientes y algunas estalactitas, "
                   "con lo que es relativamente sencillo que te des algún "
                   "golpe.\n";
            break;
        case 1:
            techo= "El techo está tan explotado como las paredes, y presenta "
                   "innumerables orificios y salientes.\n";
            break;
        case 2:
            techo= "Está repleto de orificios, consecuencia de la explotación "
                   "minera. En ocasiones, hay formados salientes que pueden "
                   "llegar a ser mortales.\n";
            break;
    }

    AddDetail("techo",techo);
    return ;
}


DetalleSuelo()
{
    string suelo;
    switch(random(4))
    {
        case 0:
            suelo = "El suelo tiene muchos baches, y sufre continuos "
                    "desniveles.\n";
            break;
        case 1:
            suelo = "El suelo es bastante escarpado, y con una pendiente hacia"
                    " abajo, lo que le da un poco más de inestabilidad.\n";
            break;
        case 2:
            suelo = "Está repleto de pequeñas piedras, producto de picar en "
                    "las paredes.\n";
            break;
        case 3:
            suelo = "El suelo está inclinado hacia arriba, haciendo aún más "
                    "dificultoso el camino.\n";
            break;
    }
    AddDetail("suelo",suelo);
}

void DetalleParedes()
{
    string pared;
    switch (random(4))
    {
        case 0:
            pared = "Las paredes son de roca, y en general, bastante "
                    "machacadas.\n";
            break;
        case 1:
            pared = "Tocas las paredes y notas los incontables orificios y "
                    "marcas que los picos han dejado sobre ellas.\n";
            break;
        case 2:
            pared = "Las paredes son de piedra, y explotadas en casi su "
                    "totalidad. Sólo en algunas zonas sigue quedando alguna "
                    "veta sin tratar.\n";
            break;
        case 3:
            pared = "Observas las paredes de la mina, y debido al juego de "
                    "sombras, en tu cabeza se forman las siluetas de criaturas"
                    " imaginarias de todo tipo.\n";
            break;
    }
    AddDetail(({"pared","paredes"}),pared);
    return;
}


void DetalleVeta()
{
    string pared;
    switch(random(2))
    {
        case 0:
            pared = "Estas paredes están muy explotadas, mas observas un "
                    "pedazo de veta donde puede haber residuos "
                    "minerales.\n";
            break;
        case 1:
            pared = "En una de las esquinas te parece ver una veta sin "
                    "tratar.\n";
            break;
    }
    AddDetail(({"pared","paredes"}),pared);


    AddDetail("veta",
              "Se trata de una veta de mineral. Conforme está ubicada, "
                   "no serías capaz de diferenciar qué mineral descansa en "
                   "la roca, pero quizá picando lo descubras.\n");
    p_posible_picar = 1;
    return;

}


void DetalleAntorchas()
{
AddDetail(({"antorchas","antorcha"}),
            "Son unos recipientes de metal con algún material inflamable en "
            "su interior, y que se prende para poder dar luz a las minas. "
            "Desprenden un olor bastante fuerte, aunque soportable para tu "
            "olfato.\n");
    SetIntBright(45);
    p_antorchas = 1;

}





int cmd_picar(string str)
{
    string msg, tipo, name, nada_player, nada_room;
    object mineral;
    object pico = present("pico",TP);


    if (!pico) return notify_fail("Para picar sería bueno tener un pico.\n",
                      NOTIFY_NOT_VALID);


    if (!sizeof(filter(TP->QueryWeapons(),(:$1->id("pico"):))))
    {
        return notify_fail("Mejor que empuñes primero el pico si quieres "
                           "picar algo.\n",
               NOTIFY_NOT_VALID);
    }

    if (!str || member(({"veta","pared","paredes","roca"}),str) <= -1)
    {
        return notify_fail("¿Picar qué?\n",NOTIFY_NOT_VALID);
    }

    if (!p_posible_picar)
    {
        return notify_fail("Te pones a buscar una buena veta, pero parece que "
                           "por esta zona no hay ninguna  sin explotar.\n",
               NOTIFY_NOT_VALID);
    }

    if (sizeof(filter(all_inventory(environment(TP)),
       (:living($1) && $1->id("enano_minero"):))))
    {
        return notify_fail("Miras al enano minero y piensas que no es buena "
                           "idea picar en estos momentos.\n",
               NOTIFY_NOT_VALID);
    }

    if (TP->QueryTP() < 6) return notify_fail("Estás demasiado fatigad" +SEXO+
                                              " para ponerte a picar.\n",
                                  NOTIFY_NOT_VALID);

    if (p_veces_picadas >= 10)
    {
        switch(d2())
        {
            case 1:
                msg = "El poco mineral que queda está situado de forma que "
                      "por más que lo intentas, no consigues desprender ni "
                                   "una viruta.\n";
                break;
            case 2:
                msg = "Aunque aún quedan restos de mineral, parecen "
                      "dispuestos de una forma en la que te es imposible "
                      "extraerlo.\n";
                break;
        }
        return notify_fail(msg,NOTIFY_NOT_VALID);
    }

    nada_player = "Comienzas a picar durante un rato, pero no consigues "
                  "extraer nada.\n";
    nada_room = " comienza a picar, mas no ves que saque nada.\n";

    switch(p_tipo_mineral)
    {

        case M_NINGUNO:
            write(nada_player);
            say(CAP(TNAME) +nada_room);
            TP->AddTP(-6);
            return 1;
        case M_HIERRO:
            switch(random(100))
            {
                case 0..49:
                    write(nada_player);
                    say(CAP(TNAME)+ nada_room);
                    TP->AddTP(-6);
                    return 1;
                case 50..79:
                    tipo = "mineral";
                    name = "hierro_peque";
                    break;
                case 80..99:
                    tipo = "mineral";
                    name = "hierro_grande";
                    break;
            }
            break;
        case M_PLATA:
            switch(random(100))
            {
                case 0..59:
                    write(nada_player);
                    say(CAP(TNAME)+ nada_room);
                    TP->AddTP(-6);
                    return 1;
                case 60..84:
                    tipo = "plata";
                    name = "plata_peque";
                    break;
                case 85..99:
                    tipo = "plata";
                    name = "plata_grande";
                    break;
            }
            break;
        case M_ORO:
            switch(random(100))
            {
                case 0..74:
                    write(nada_player);
                    say(CAP(TNAME)+ nada_room);
                    TP->AddTP(-6);
                    return 1;
                case 75..89:
                    tipo = "oro";
                    name = "oro_peque";
                    break;
                case 90..99:
                    tipo = "oro";
                    name = "oro_grande";
                    break;
            }
            break;
        case M_MITHRIL:
            switch(random(100))
            {
                case 0..84:
                    write(nada_player);
                    say(CAP(TNAME)+ nada_room);
                    TP->AddTP(-6);
                    return 1;
                case 85..94:
                    tipo = "mithril";
                    name = "mithril_peque";
                    break;
                case 95..99:
                    tipo = "mithril";
                    name = "mithril_grande";
                    break;
            }
            break;
    }

    write("Comienzas a picar en la roca y tras un rato de trabajo, tu "
          "esfuerzo se ve recompensado con un trozo de " + tipo + ", que cae al "
          "suelo");
    say(CAP(TNAME) + " comienza a picar en la pared y de repente cae un trozo "
                                   "de " + tipo + " al suelo.\n");
    TP->AddTP(-6);
    p_veces_picadas++;

    mineral = clone_object(OTRO_MINAS(name));
    mineral->move(TO,M_SILENT);
    return 1;
}




int cmd_coger(string str)
{
    object lamp;

    if (!str || str != "antorcha" || str != "antorchas") return 0;
    if (!present("antorcha")) return 0;
    write("Las antorchas están bien aferradas a la roca y no las puedes coger.\n");
    return 1;
}
