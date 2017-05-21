#include "./path.h"
#include <properties.h>

inherit SIM_ROOM;

void say(string str) {
  tell_room(MARH("nandor/castillo/tunel/sal2"),
  "Oyes voces encima de tu cabeza.\nConcretamente, alguien dice: "+str+"\n");
}

create () {
    object portal;
    ::create();
        SetLocate("Aldea de Nandor");
    SetIntShort("un peque�o templo");
    SetIntLong("�ste peque�o templo fue una de las primeras edificaciones de nandor, y "
    "a lo largo del tiempo ha servido como lugar de culto para distintas divinidades y "
    "para enterrar personajes fallecidos y olvidados generaciones atr�s. En cualquier "
    "caso, las gentes humildes de Nandor ignoran su origen e historia, y tampoco les "
    "interesa. Se re�nen aqu� en d�as importantes como la fiesta de la cosecha, o "
    "acuden solos a rogar por asuntos tan mundanos como  la curaci�n de una vaca enferma "
    "o el buen crecimiento de un �rbol frutal.\n"
    "El interior del edificio es muy humilde, de forma rectangular, con paredes de "
    "piedra torpemente pulida al igual que las grandes losas del suelo que presentan un "
    "relieve accidentado. A lo largo de la parte baja de los muros mas largos se "
    "extiende un poyo de piedra corrido y en la parte mas alejada de la entrada hay un "
    "modesto altar construido en un �nico bloque de madera sobre el cual se iergue una "
    "estatua de tama�o medio del dios de la agricultura y la ganader�a Nhaigel.\n");
    AddDetail(({"pared", "paredes", "muro", "muros"}), "Los muros del templo est�n "
    "levantados a base de piedras de distintos tama�os y formas, unidas con mortero que "
    "con el paso de los a�os se ha ido  deteriorando, dejando peque�os huecos. Se "
    "percibe como el constructor que los levant� trat� de rebajar los sobresalientes "
    "para dejar una superficie lisa, aunque por el resultado no lo logr� por completo.\n");
    AddDetail(({"losas", "suelo"}), "Grandes lascas de piedra desiguales de superficie  "
    "irregular que forman el suelo, algunas mas hundidas o inclinadas que otras, y "
    "mostrando aqu� y all� peque�as rendijas entre ellas. Fij�ndose con atenci�n en "
    "algunas se pueden observar unos signos o letras medio borrados por el paso del "
    "tiempo que marcan la posici�n de antiguas tumbas excavadas bajo el suelo que pisas "
    "en estos instantes.\n");
    AddDetail("poyo", "Es un escal�n ancho que rodea los muros por su parte baja que es "
    "usado como asiento por los aldeanos cuando se congregan dentro del templo.\n");
    AddDetail("altar", "Un gran bloque de madera maciza algo descuidada de unos dos "
    "metros de longitud por uno de altura que reposa en cuatro bloques de piedra, "
    "sobre el que se depositan las ofrendas al dios Nhaigel. Su frontal y laterales "
    "aparecen trabajados laboriosamente con motivos naturales de hojas y ramas, y "
    "abundancia de espigas de trigo que representan al dios del templo, como si alguien "
    "hubiera querido suavizar la tosquedad del altar.\n");
    AddDetail(({"Nhaigel", "nhaigel", "dios", "estatua"}), "Es una estatua de un metro "
    "de altura que representa a Nhaigel, dios de la agricultura y la ganader�a y por "
    "ende adorado por los campesinos, pastores y dem�s gente de las regiones rurales.\n"
    "La estatua est� tallada en madera al igual que el altar que la sostiene pero al "
    "contrario que �ste, aparece pintada amorosamente, aunque quiz� con cierta falta de "
    "maestr�a. Representa a un humano de rasgos vagamente �lficos ataviado con una "
    "sencilla t�nica verde, erguido y sosteniendo una larga y dorada espiga de trigo "
    "maduro con la mano izquierda mientras que con la mano derecha prodiga su bendici�n "
    "a cualquier presente o quiz�s a la misma madre tierra. Parece mirarte con ojos "
    "apacibles y serenos desde su pedestal, como si te estuviera invitando a acercarte.\n");
    AddDetail(({"letras", "signos"}),
    "No merece la pena que intentes descifrarlos. Probablemente fueron escritos "
    "en una lengua ya perdida. Sin embargo, casi podr�as jurar que esas losas "
    "marcadas son tumbas. Quiz� las tumbas de algun sacerdote o noble importante.\n");

    AddExit("oeste", "../calle42n");
    AddDoor("oeste", "Una puerta de madera taraceada", "Es una puerta de madera "
    "taraceada con tachuelas de bronce deslustrado, hecha de dos batientes aunque solo "
    "se abre uno de ellos, y cuyo marco inferior forma un escal�n.\n",
    ({"puerta", "puerta de madera", "puerta de madera taraceada", "puerta del oeste"}));
    SetIntBright(40);

    AddRoomCmd("rezar", "cmd_rezar");
    AddRoomCmd(({"decir","\'"}),SF(say));

    portal=clone_object("/obj/monolito");
    portal->SetRaza("humano");
    portal->move(TO);

}

int cmd_rezar(string str)
{
	if (!str || (str = LOWER(str)) != "a nhaigel")
		return notify_fail("�A quien quieres rezar? solo hay un dios que te escucha.\n");
	say(CAP(TNAME)+ " le reza a Nhaigel.\n");
	if(TP->QueryRace()=="humano"){
	    TP->SetSmell("Desprende un suave y fresco aroma.\n");
	    write("Notas una suave brisa que procede de la estatua del dios. Te sientes "
    	"mucho m�s refrescad" + TP->QueryGenderEndString() + ".\n");
	    if(TP->QueryAlign()<0){
	        TP->SetAlign(TP->QueryAlign()+(TP->QueryInt()*2));
	        return 1;
	    }
	    else if(TP->QueryAlign()>=200 && TP->QueryHP()<TP->QueryMaxHP()){
	        TP->AddHP(random(TP->QueryInt()+TP->QueryCon()));
	        return 1;
	    }
	    return 1;
	}
	return  notify_fail("Rezas un rato, pero no ocurre nada.\n");
}
