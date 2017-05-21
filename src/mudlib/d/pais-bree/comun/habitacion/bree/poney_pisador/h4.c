/*
Fichero: h4.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  habitaci�n de Cebadilla Mantecona. 
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
    return "Huele a madera ardiendo y a s�banas limpias.\n";
    return "Huele a madera antigua, s�banas limpias y lana c�lida, todo ello mezclado con "
    "un leve olor a humo a�ejo.\n";
}

string  f_sonidos(){
    if (fuego==1)
    return "El suave crepitar de la le�a ardiendo procedente del peque�o hogar resulta "
    "himn�tico.\n";
    return "�rdenes, ruido de cacharros, risas y voces amortiguadas llegan procedentes "
    "del piso inferior.\n";
}

string f_fuego(){
    if (fuego==1)
    return    "En el peque�o hogar de piedra primorosamente constru�do, arde un alegre "
    "fuego que caldea el aposento.  Cuenta con una peque�a chimenea propia para uso "
    "exclusivo de los Mantecona. El suelo de alrededor est� cubierto de losetas para "
    "evitar que las llamas prendan el suelo de madera.";

    return "Es un peque�o hogar de piedra primorosamente constru�do con una peque�a "
    "chimenea propia para uso exclusivo de los Mantecona. El suelo de alrededor est� "
    "cubierto de losetas para evitar que las llamas prendan el suelo de madera.\n";
}
create()
{
    ::create();
    	SetIntShort("los aposentos de Cebadilla Mantecona");
    	SetIntLong("Este cuarto es m�s grande y confortable que el resto, aunque no "
    	"mucho m�s ostentoso, pues en �l prima la sencillez y la funcionalidad antes que "
    	"los alardeos in�tiles.\n"
    	"Una gran cama est� situada al lado de la ventana, junto a una mesita de madera "
    	"con diversos cajones. Separada de la cama por una gruesa alfombra hay una c�moda "
    	"silla delante de un escritorio de madera de roble. Hacia el fondo de la "
    	"habitaci�n, al este, ves un peque�o hogar de piedra sobre una zona enlosada, y "
    	"frente a �l, un amplio y c�modo butac�n con mullidos cojines. Un cofre a los "
    	"pies de la cama, un gran armario de doble puerta y un retrato colgado sobre una "
    	"peque�a repisa sobre la que hay la maqueta de un edificio completan el mobiliario "
    	"del cuarto. Todo parece limpio y en buenas condiciones, y tanto la ventana de "
    	"doble batiente con cortinas que proporciona buena luz a la estancia, as� como el "
    	"calor que asciende desde las cocinas hace de esta habitaci�n la m�s confortable "
    	"de toda la posada.\n");
    	    AddDetail(({"chimenea", "fuego", "hogar"}), SF(f_fuego));
    	AddDetail("alfombra",
    	"Una gruesa alfombra con dibujos geom�tricos, regalo, a buen seguro, de alg�n "
    	"cliente agradecido que la trajo de tierras lejanas como presente para el honrado "
    	"y hospitalario posadero.\n");
    	AddDetail("silla",
    	"Es una confortable silla de respaldo, brazos y patas tallados con motivos "
    	"sencillos pero hermosos. Tiene un coj�n en el asiento para resultar m�s "
    	"confortable.\n");
    	AddDetail("escritorio",
    	"Es un gran escritorio de madera oscura y con los bordes y pies tallados con "
    	"motivos geom�tricos. Intuyes por su antig�edad, que sobre �l se han llevado las "
    	"cuentas de la posada desde hace varias generaciones de Manteconas.\n");
    	AddDetail(({"losetas", "losas"}),
    	"Alrededor del hogar, el suelo est� cubierto de losetas de piedra bien unidas y "
    	"pulimentadas que evitan que las chispas ocasionales procedentes del peque�o hogar "
    	"prendan en el suelo de madera.\n");
    	AddDetail("retrato",
    	"En la pared, sobre una repisa, cuelga un gran retrato pintado a mano de una "
    	"familia de orondos aldeanos de Bree, con la posada del Poney Pisador a sus "
    	"espaldas. No podr�as decir si uno de ellos es el actual se�or Cebadilla Mantecona, "
    	"pero en cualquier caso, los rasgos de todos los retratados lo recuerdan vivamente.\n");
    	AddDetail("repisa",
    	"Una estrecha repisa de madera barnizada atornillada a la pared bajo un gran "
    	"retrato. Sobre ella reposa la maqueta de un edificio hecha a mano.\n");
    	AddDetail("maqueta",
    	"Te acercas y observas que se trata de una representaci�n exacta de la posada del "
    	"Poney Pisador. Hasta el �ltimo y m�s m�nimo detalle aparece en la maqueta, desde "
    	"el cartel pintado y la l�mpara de la entrada hasta las tejas y chimeneas del "
    	"tejado. Adem�s, cada elemento est� fabricado con el material de su om�nimo "
    	"real. Una obra tan minuciosa y exquisita solo ha podido salir de las manos de un "
    	"enano.\n"
    	"En la base de la maqueta hay una peque�a l�mina de metal con algo escrito en hermosos y angulosos caracteres grabados.\n");
    	    AddRoomCmd("encender", "cmd_encender");
    AddRoomCmd("apagar", "cmd_apagar");
    	AddExit("norte", "./pasillo5");
     AddDoor("norte", "la puerta",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n"
     "Un pestillo sirve para cerrar desde dentro y tres ganchos situados a lo largo de su "
     "parte media pueden utilizarse para colgar enseres o prendas de vestir.\n",
     ({"puerta", "norte", "n", "puerta norte"}));
         AddItem(MUEBLE_BREE("butacon"), REFRESH_DESTRUCT);
         AddReadMsg(({"inscripci�n de maqueta","placa de maqueta","inscripcion de maqueta","maqueta", "placa"}),SF(leer));
}

string leer()
{
    say(CAP(TNAME) + " lee la placa de la maqueta que hay sobre la repisa.\n",TP);
    return
       ("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
         "     Para el se�or Mantecona, yo, Frodrin hijo de Frainur, del pueblo de los \n"
         "    Barba de Fuego, labr� este presente en agradecimiento por la exquisita "
         "     acogida que siempre se ha dispensado a m� y a los m�os en este establecimiento .\n"
         "     Ojal� esta posada se levante aqu� durante muchos siglos y siempre cuente "
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
                return notify_fail("Frotas el eslab�n y el pedernal con gran vigor pero "
                "no consigues hacer saltar chispas suficientes como para encender el fuego.\n", NOTIFY_NOT_VALID);

            write("Frotas el eslab�n con el pedernal y consigues hacer saltar unas "
            "chispas que prenden las ramitas secas que hay sobre la le�a del hogar.\n"
            "Soplas suavemente para avivar el fuego que poco a poco va caldeando "
            "la habitaci�n.\n");
            say(CAP(TNAME)+ " hace saltar unas chispas con su eslab�n y pedernal que "
            "encienden las ramitas que hay sobre la le�a del hogar.\n"
            "Luego, aviva el fuego soplando suavemente hasta que este comienza a "
            "caldear la habitaci�n.\n");

            fuego=1;
            SetIntBright(QueryIntBright()+LUZ);
            play_sound(TO, SOUND_AMBIENTES("chimenea"), 0, 80, -1);
            SetSoundEnvironment(SOUND_AMBIENTES("chimenea"),80);
            return 1;
        }
        return notify_fail("el fuego ya est� encendido.\n",NOTIFY_NOT_VALID);
    }
    return notify_fail("�Qu� quieres encender?.\n", NOTIFY_NOT_VALID);
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
        return notify_fail("El fuego ya est� apagado.\n", NOTIFY_NOT_VALID);
    }
    return notify_fail("�Qu� quieres apagar?.\n", NOTIFY_NOT_VALID);
}
