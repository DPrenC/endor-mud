/*
Fichero: salita.c
Autor: aulë
Fecha: 18/03/2013
Descripción:  una salita privada donde dormirán los cuatro hobbits y Trancos.
*/
#include "./path.h"
#include <sounds.h>
#include <skills.h>
inherit BREE_ROOM;
#define LUZ 15
int fuego=0;
public int QueryFuego() { return fuego; }
string  f_olores(){
    if (fuego==1)
    return "Huele a humo de leña.\n";
    return "Te llega el tenue olor de pan recién horneado y carne asada.\n";
}

string  f_sonidos(){
    if (fuego==1)
    return "Escuchas el suave crepitar de la leña en el fuego del hogar.\n";
    return "El sonido de voces, risas y canciones llega, amortiguado, hasta tus oídos.\n";
}

string f_fuego(){
    if (fuego==1)
    return    "Un buen fuego arde alegremente en el hogar formado por dos bajos "
    "muretes de piedra que sobresalen de la pared norte, cerrados por delante con una "
    "línea de piedras aún más bajas y por un guardafuegos de hierro.\n";

    return "el hogar está formado por dos bajos muretes de piedra que sobresalen de la "
    "pared norte, cerrados por delante con una línea de piedras aún más bajas y por un "
    "guardafuegos de hierro.\n"
    "En el interior del hogar hay una pequeña pila de leña para caldear la salita "
    "cuando se encienda el fuego.\n";
}

create()
{
    ::create();
    	SetIntShort("Una confortable salita");
    	SetIntLong("Estás en una confortable salita reservada para aquellos huéspedes que "
    	"desean conversar y comer en privado.\n"
    	"El suelo y las paredes son de piedra lisa y hay un hogar de piedra para el fuego.\n"
    	"Ante el hogar  hay varias sillas bajas y en un rincón, junto a una mesa redonda "
   "cubierta por un mantel blanco, hay un mullido sillón bajo.\n"
    	"La única ventana da al norte y cuenta con pesadas persianas interiores y espesas "
    	"cortinas. En el interior de la estancia reina un calor agradable que junto con la "
    	"ausencia de ruido procedente de la sala común, hace de esta salita un lugar "
    	"acogedor y reconfortante, propia para el descanso o una agradable charla.\n");
SetIndoors(1);
    	AddDetail("cortinas",
    	"Pesadas cortinas que cuelgan hasta el suelo, aislando la habitación del frío "
    	"exterior y de las posibles miradas indiscretas.\n");
    AddDetail(({"persianas", "persiana"}),
    "Es una pesada persiana formada por robustas tablillas unidas entre sí mediante "
    "resistente bramante. Se hacen subir y bajar tirando de una cinta de cuero "
    "trenzado y se enrrolla en la parte superior de la ventana.\n");
    AddDetail(({"ventana", "por la ventana", "la ventana"}),
    "La ventana da al norte y atisbando por ella ves las estribaciones de la colina de "
    "bree y algunas casas desperdigadas.\n");
    AddDetail("mesa",
    "Es una mesa redonda para unos cuatro comensales. Está cubierta por un pulcro mantel "
    "blanco. Sobre el mantel hay una campanilla.\n");
    AddDetail(({"campanilla", "campanita", "campana"}),
    "Una campanilla de latón que se utiliza para llamar al personal de la posada.\n");
    AddDetail(({"sillón", "sillon"}),
    "Es un bajo y confortable sillón de mullido asiento, amplios brazos, cortas y "
    "gruesas patas de madera y amplio respaldo.\n"
    "Parece ideal para acercarlo al fuego y pasarse unas cuantas horas leyendo con los "
    "pies al calor o echando una buena siesta.\n");
    AddDetail("mantel",
    "Es un pulcro mantel blanco bien tejido que cubre la mesa redonda y cae hasta una "
    "distancia equidistante del suelo y el borde de la mesa.\n");
    AddDetail(({"sillas","silla"}),
    "Son sillas amplias pero bajas y pesadas, hechas de madera y con el asiento de "
    "mimbre entretejido cubierto por un mullido cojín.\n");
    AddDetail("techo",
    "Largas vigas de roble bien pulidas y cepilladas soportan un techo de madera limpia, "
    "antigua pero bien cuidada y mantenida.\n");
    AddDetail(({"chimenea", "fuego", "hogar"}), SF(f_fuego));

    AddDetail("guardafuegos",
    "Es una rejilla metálica con agujeros redondos, inserta en un bastidor de hierro "
    "rectangular que se apoya sobre dos anchos pies del mismo material. En la parte "
    "superior tiene un asa para moverlo. Se utiliza para ponerlo ante el fuego y evitar "
    "que las chispas salten e incendien algo.\n");
    SetIntNoise(SF(f_sonidos));
    SetIntSmell(SF(f_olores));
    SetIntBright(20);
    AddRoomCmd("encender", "cmd_encender");
    AddRoomCmd("apagar", "cmd_apagar");
    AddRoomCmd(({"tocar","sonar", "coger"}), "cmd_campana");
     AddExit("sur", "./pasillo1");
     AddDoor("sur", "la puerta",
     "Es una puerta de madera pulida y bien cuidada con una manilla de bronce.\n"
     "Cuenta con un cerrojo y un pestillo para atrancarla.\n",
     ({"puerta", "s", "sur", "salita"}));

    }
    int cmd_encender(string str){
    if (str=="hogar" || str=="el hogar" || str=="fuego" || str=="el fuego"
        || str=="chimenea" || str=="la chimenea"){
        if (!fuego){
            if(!present("encendedor",TP)) return notify_fail("Necesitas un encendedor.\n", NOTIFY_NOT_VALID);
            int encender = TP->UseSkill(HAB_FIRE);
            if(encender < -10)
                //say(CAP(TNAME)+" intenta encender torpemente el fuego pero no es capaz.\n");
                return notify_fail("Frotas el eslabón y el pedernal con gran vigor pero "
                "no consigues hacer saltar chispas suficientes como para encender el fuego.\n", NOTIFY_NOT_VALID);

            write("Frotas eslabón y pedernal haciendo saltar un arco de chispas que "
            "caen y encienden la leña. Las sombras retroceden y la salita comienza a "
            "caldearse entre el alegre crepitar de los leños.\n");
            say(CAP(TNAME)+ " enciende el fuego y la estancia comienza a caldearse.\n");

            fuego=1;
            SetIntBright(QueryIntBright()+LUZ);
            play_sound(TO, SOUND_AMBIENTES("chimenea"), 0, 80, -1);
            SetSoundEnvironment(SOUND_AMBIENTES("chimenea"),80);
            return 1;
        }
        return notify_fail("el fuego ya está encendido.\n",NOTIFY_NOT_VALID);
    }
    return notify_fail("¿Qué quieres encender?.\n", NOTIFY_NOT_VALID);
}

    int cmd_apagar(string str){
    if (str=="fuego" || str=="el fuego" || str=="hogar" || str=="el hogar"
        || str=="chimenea" || str=="la chimenea"){
        if (fuego==1){
            fuego=0;
            write("Con el atizador revuelves las brasas hasta que el fuego se va "
            "apagando poco a poco.\n");
            say(CAP(TNAME)+ " utiliza el atizador para esparcer las brasas. El fuego se apaga poco a poco.\n");
            SetIntBright(QueryIntBright()-LUZ);
            stop_sounds(all_inventory(TO));
            SetSoundEnvironment(0);
            return 1;
        }
        return notify_fail("El fuego ya está apagado.\n", NOTIFY_NOT_VALID);
    }
    return notify_fail("¿Qué quieres apagar?.\n", NOTIFY_NOT_VALID);
}
public int cmd_campana(string str){
    if(str!="campana" && str!="campanilla" && str!="campanilla") return 0;
write("Coges la campanilla y la haces sonar vigorosamente, la vuelves a dejar sobre la mesa.\n"
"Alguien grita desde lejos: ¡medio minuto, ya voy!\n");
say(capitalize(TNAME)+" coge la campanilla y la hace sonar vigorosamente, la vuelve a dejar sobre la mesa.\n"
"Alguien grita: ¡ya voy, ya voy! ¡Medio minuto!\n");
    play_sound(TO, SOUND_EVENTOS("campanilla"));
    TP->SetExplored();
return 1;
}
