/*
Fichero: h4.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  habitación de Cebadilla Mantecona. 
*/
#include "./path.h"
#include <sounds.h>
#include <skills.h>
inherit HABITACION+"bree/poney_pisador/basehabi";
string leer();

#define LUZ 15
int fuego=0;
public int QueryFuego() { return fuego; }
string  f_olores(){
    if (fuego==1)
    return "Huele a madera ardiendo y a sábanas limpias.\n";
    return "Huele a madera antigua, sábanas limpias y lana cálida, todo ello mezclado con "
    "un leve olor a humo añejo.\n";
}

string  f_sonidos(){
    if (fuego==1)
    return "El suave crepitar de la leña ardiendo procedente del pequeño hogar resulta "
    "himnótico.\n";
    return "Órdenes, ruido de cacharros, risas y voces amortiguadas llegan procedentes "
    "del piso inferior.\n";
}

string f_fuego(){
    if (fuego==1)
    return    "En el pequeño hogar de piedra primorosamente construído, arde un alegre "
    "fuego que caldea el aposento.  Cuenta con una pequeña chimenea propia para uso "
    "exclusivo de los Mantecona. El suelo de alrededor está cubierto de losetas para "
    "evitar que las llamas prendan el suelo de madera.";

    return "Es un pequeño hogar de piedra primorosamente construído con una pequeña "
    "chimenea propia para uso exclusivo de los Mantecona. El suelo de alrededor está "
    "cubierto de losetas para evitar que las llamas prendan el suelo de madera.\n";
}
create()
{
    ::create();
    	SetIntShort("los aposentos de Cebadilla Mantecona");
    	SetIntLong("Este cuarto es más grande y confortable que el resto, aunque no "
    	"mucho más ostentoso, pues en él prima la sencillez y la funcionalidad antes que "
    	"los alardeos inútiles.\n"
    	"Una gran cama está situada al lado de la ventana, junto a una mesita de madera "
    	"con diversos cajones. Separada de la cama por una gruesa alfombra hay una cómoda "
    	"silla delante de un escritorio de madera de roble. Hacia el fondo de la "
    	"habitación, al este, ves un pequeño hogar de piedra sobre una zona enlosada, y "
    	"frente a él, un amplio y cómodo butacón con mullidos cojines. Un cofre a los "
    	"pies de la cama, un gran armario de doble puerta y un retrato colgado sobre una "
    	"pequeña repisa sobre la que hay la maqueta de un edificio completan el mobiliario "
    	"del cuarto. Todo parece limpio y en buenas condiciones, y tanto la ventana de "
    	"doble batiente con cortinas que proporciona buena luz a la estancia, así como el "
    	"calor que asciende desde las cocinas hace de esta habitación la más confortable "
    	"de toda la posada.\n");
    	    AddDetail(({"chimenea", "fuego", "hogar"}), SF(f_fuego));
    	AddDetail("alfombra",
    	"Una gruesa alfombra con dibujos geométricos, regalo, a buen seguro, de algún "
    	"cliente agradecido que la trajo de tierras lejanas como presente para el honrado "
    	"y hospitalario posadero.\n");
    	AddDetail("silla",
    	"Es una confortable silla de respaldo, brazos y patas tallados con motivos "
    	"sencillos pero hermosos. Tiene un cojín en el asiento para resultar más "
    	"confortable.\n");
    	AddDetail("escritorio",
    	"Es un gran escritorio de madera oscura y con los bordes y pies tallados con "
    	"motivos geométricos. Intuyes por su antigüedad, que sobre él se han llevado las "
    	"cuentas de la posada desde hace varias generaciones de Manteconas.\n");
    	AddDetail(({"losetas", "losas"}),
    	"Alrededor del hogar, el suelo está cubierto de losetas de piedra bien unidas y "
    	"pulimentadas que evitan que las chispas ocasionales procedentes del pequeño hogar "
    	"prendan en el suelo de madera.\n");
    	AddDetail("retrato",
    	"En la pared, sobre una repisa, cuelga un gran retrato pintado a mano de una "
    	"familia de orondos aldeanos de Bree, con la posada del Poney Pisador a sus "
    	"espaldas. No podrías decir si uno de ellos es el actual señor Cebadilla Mantecona, "
    	"pero en cualquier caso, los rasgos de todos los retratados lo recuerdan vivamente.\n");
    	AddDetail("repisa",
    	"Una estrecha repisa de madera barnizada atornillada a la pared bajo un gran "
    	"retrato. Sobre ella reposa la maqueta de un edificio hecha a mano.\n");
    	AddDetail("maqueta",
    	"Te acercas y observas que se trata de una representación exacta de la posada del "
    	"Poney Pisador. Hasta el último y más mínimo detalle aparece en la maqueta, desde "
    	"el cartel pintado y la lámpara de la entrada hasta las tejas y chimeneas del "
    	"tejado. Además, cada elemento está fabricado con el material de su omónimo "
    	"real. Una obra tan minuciosa y exquisita solo ha podido salir de las manos de un "
    	"enano.\n"
    	"En la base de la maqueta hay una pequeña lámina de metal con algo escrito en hermosos y angulosos caracteres grabados.\n");
    	    AddRoomCmd("encender", "cmd_encender");
    AddRoomCmd("apagar", "cmd_apagar");
    	AddExit("norte", "./pasillo5");
     AddDoor("norte", "la puerta",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "norte", "n", "puerta norte"}));
         AddItem(MUEBLE_BREE("butacon"), REFRESH_DESTRUCT);
         AddReadMsg(({"inscripción de maqueta","placa de maqueta","inscripcion de maqueta","maqueta", "placa"}),SF(leer));
}

string leer()
{
    say(CAP(TNAME) + " lee la placa de la maqueta que hay sobre la repisa.\n",TP);
    return
       ("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
         "     Para el señor Mantecona, yo, Frodrin hijo de Frainur, del pueblo de los \n"
         "    Barba de Fuego, labré este presente en agradecimiento por la exquisita "
         "     acogida que siempre se ha dispensado a mí y a los míos en este establecimiento .\n"
         "     Ojalá esta posada se levante aquí durante muchos siglos y siempre cuente "
         "     con tan excelente cerveza.\n"
         "\n"
         "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");

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

            write("Frotas el eslabón con el pedernal y consigues hacer saltar unas "
            "chispas que prenden las ramitas secas que hay sobre la leña del hogar.\n"
            "Soplas suavemente para avivar el fuego que poco a poco va caldeando "
            "la habitación.\n");
            say(CAP(TNAME)+ " hace saltar unas chispas con su eslabón y pedernal que "
            "encienden las ramitas que hay sobre la leña del hogar.\n"
            "Luego, aviva el fuego soplando suavemente hasta que este comienza a "
            "caldear la habitación.\n");

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
            write("Utilizando un atizador golpeas las brasas y las remueves hasta que el "
            "fuego se apaga.\n");
            say(CAP(TNAME)+ " se sirve de un atizador para esparcer las brasas.\n"
            "El fuego se apaga poco a poco.\n");
            SetIntBright(QueryIntBright()-LUZ);
            stop_sounds(all_inventory(TO));
            SetSoundEnvironment(0);
            return 1;
        }
        return notify_fail("El fuego ya está apagado.\n", NOTIFY_NOT_VALID);
    }
    return notify_fail("¿Qué quieres apagar?.\n", NOTIFY_NOT_VALID);
}
