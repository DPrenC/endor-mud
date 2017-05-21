/****************************************************************************
Fichero: bosque_base.c
Autor: Ratwor
Fecha: 07/12/2006
Descripci�n: El archivo base del bosque de marhalt.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <nightday.h>
#include <sounds.h>
#include <moving.h>
inherit SIM_ROOM;

private string last_sound;
public string snd_ambiente();
public descripciones(){
    string bloque1, bloque2;

    switch (d10()){
        case 1:
            bloque1= "Est�s en el bosque de Marhalt, ubicado al sur de Nandor. Es "
            "un bosque joven, lleno de luz y de vida. Te rodean �rboles y reto�os. En "
            "su mayor�a son robles y hayas, aunque tambi�n puedes ver algunas otras "
            "especies que no sabr�as identificar.\n A lo lejos, el aullido de un lobo "
            "muestra que no s�lo los �rboles habitan estas regiones de Simauria.\n";
            break;
        case 2:
            bloque1= "Te encuentras en el bosque de Marhalt, al norte de la capital "
            "Ishtria. Este lugar est� poblado de vegetaci�n joven, en su mayor parte "
            "robles y hayas, que lo llenan todo de un colorido intenso. Al tratarse "
            "de �rboles medianos, la luz natural puede filtrarse entre las ramas sin "
            "dejar lugares oscuros.\n";
            break;
        case 3:
            bloque1= "Est�s en el bosque de Marhalt, al sur de Nandor y al norte de la "
            "capital de Simauria. Es un bosque lleno de �rboles medianos de todo tipo, "
            "aunque predominan robles y hayas. La vegetaci�n lo inunda todo, pero se "
            "trata de plantas j�venes que no cierran el paso al caminante.\n Escuchas "
            "a lo lejos el ulular de una lechuza, que demuestra que tambi�n hay por "
            "aqu� fauna variada.\n";
            break;
        case 4:
            bloque1= "Te encuentras en el bosque de Marhalt, rodeado de �rboles que, "
            "lejos de obstruirte el paso, te permiten mirar por entre sus troncos y "
            "follajes. Se trata de �rboles j�venes, de hojas muy verdes. En su "
            "mayor�a ves robles y hayas, aunque tambi�n hay otros tipos de plantas "
            "que no sabr�as clasificar.\n  Puedes o�r la brisa moviendo las ramas, y "
            "de tanto en tanto te llega el sonido de alg�n animal en la distancia.\n";
            break;
        case 5:
            bloque1= "Te encuentras en el bosque de Marhalt. Esta extensi�n verde est� "
            "poblada de �rboles j�venes y reto�os, en su mayor�a robles y hayas aunque"
            " tambi�n puedes ver �rboles m�s corrientes pero que no sabr�as identificar. "
            " Se aprecia c�mo la brisa mueve las verdes ramas.\n  Puedes observar "
            "diversos claros entre los �rboles, por donde transcurren peque�os "
            "senderos naturales.\n";
            break;
        case 6:
            bloque1= " Te encuentras en el bosque de Marhalt, y por todos lados ves "
            "�rboles j�venes de escaso follaje.  Observas incluso algunos reto�os. En "
            "su mayor�a son hayas y robles, aunque tambi�n ves �rboles silvestres.\n"
            " Te llega el sonido de la brisa entre las ramas, entremezclado con"
            " alg�n aullido lejano.\n";
            break;
        case 7:
            bloque1= "Reto�os y �rboles medianos invaden este bosque que la naturaleza ha"
            " puesto recientemente. El verde es intenso y el aroma de los �rboles, "
            "en su mayor�a hayas y robles, es penetrante.\n  La brisa que agita las "
            "ramas trae tambi�n sonidos lejanos, entre los que percibes alg�n aullido de"
            " lo que podr�a reconocerse como de lobo.\n  La luz lo invade todo y no hay "
            "rincones oscuros.\n";
            break;
        case 8:
            bloque1= "En este bosque al sur de Nandor, y al norte de Ishtria, una mano "
            "parece haber tenido especial cuidado en plantar fundamentalmente robles "
            "y hayas, aunque tambi�n puedes ver �rboles m�s corrientes. Pero a�n "
            "as� todos son �rboles j�venes llenos de vida y de un color verde intenso. "
            " Sus troncos parecen ser de muy buena madera.\n Por distintas partes se "
            "ven claros dejados por los �rboles, cuyas copas tampoco son, en su "
            "mayor�a, demasiado frondosas.\n";
            break;
        case 9:
            bloque1= " Est�s en el bosque de Marhalt. Te rodean �rboles j�venes y de "
            "escaso follaje, en su mayor�a robles y hayas, que en algunos sitios "
            "dejan claros por donde transcurren peque�os caminos naturales. Las "
            "copas, abiertas y poco frondosas, permiten que el lugar parezca lleno de "
            "vida y colorido a los ojos de quien lo mire.\n  Desde lejos te llega el "
            "ulular de una lechuza, demostrando que tambi�n viven animales por aqu�.\n";
            break;
        case 10:
            bloque1= " Est�s en el bosque de Marhalt, al sur de Nandor y al norte de "
            "Ishtria. Por donde mires ves �rboles j�venes y reto�os, en su mayor parte "
            "robles y hayas, aunque tambi�n puedes encontrar �rboles de otras especies "
            "dificiles de clasificar.\n La brisa te trae aromas y sonidos, y escuchas a "
            "la distancia algo parecido al aullido de un lobo.\n";
            break;
    }

    switch(d20()){
         case 1:
            bloque2= "El suelo de este bosque est� cubierto por una tierra fina y "
            "aparentemente f�rtil, a juzgar por la cantidad de vegetaci�n que crece por "
            "todas partes. Observas arbustos carnosos y tambi�n algunas malezas,"
            " que sin embargo no llegan a obstruir el paso.\n";
            break;
        case 2:
            bloque2= "�sta es una porci�n de terreno cubierta por una tierra fina y "
            "f�rtil sobre la que crece todo tipo de vegetaci�n.\n  Aqu� se encuentra "
            "un �rbol que ha sido recientemente talado, esperando ser recogido en "
            "breve.\n";
            AddDetail(({"arbol talado", "�rbol talado", "arbol cortado", "�rbol cortado"}),
            "Es un tronco en el que son visibles las huellas del hacha. Est� ca�do, el "
            "�rbol robusto que era ha sido cortado y parte de �l seguramente arder� "
            "pronto en alguna hoguera. \n Ves cortes de hacha a lo largo y ancho de lo "
            "que ha quedado del tronco.\n");
            break;
        case 3:
            bloque2= "El suelo del bosque es indudablemente f�rtil, como lo demuestra "
            "la abundante vegetaci�n que se ha desarrollado por aqu�.\n  En �sta "
            "parte los �rboles no est�n tan juntos y puedes ver un claro. En �l, "
            "observas un grupo de rocas dispuestas creativamente, formando una extra�a "
            "figura indefinida.\n";
            AddDetail(({"grupo de rocas", "rocas", "figura", "figura indefinida"}),
            "Son unas grandes rocas agrupadas y dispuestas formando una especie de "
            "semic�rculo o media luna. En el centro, otra roca m�s peque�a queda "
            "semioculta por las m�s grandes.\n");
            break;
        case 4:
            bloque2= "Algunos arbustos y malezas se agrupan en esta parte del bosque, "
            "aunque no obstruyen ni bloquean el paso. Son plantas j�venes que todav�a no "
            "han crecido lo suficiente.\n  El suelo est� recubierto por una tierra "
            "fina que parece ser muy f�rtil, a juzgar por la abundante vegetaci�n.\n";
            break;
        case 5:
            bloque2="La vegetaci�n crece por todas partes, y donde los �rboles dejan"
            " un claro se agrupan los arbustos. Son frecuentes distintos sonidos de "
            "animales.\n";
            break;
        case 6:
            bloque2="Te encuentras sobre un suelo muy f�rtil, recubierto por una tierra"
            " fina que parece permitir el crecimiento de una vegetaci�n muy variada."
            " Arbustos y malezas se entremezclan en algunos lugares, pero como se trata "
            "de plantas j�venes, no obstruyen ni cierran el paso.\n";
            break;
        case 7:
            bloque2="Te hallas sobre un suelo recubierto de tierra fina y muy f�rtil, "
            "en la que crece variada y abundante vegetaci�n. Dicha vegetaci�n, en "
            "consonancia con los �rboles robustos, dan un ambiente agradable y alegre"
            " al entorno.\n";
            break;
        case 8:
            bloque2="El suelo de este bosque es rico en malezas y arbustos, que "
            "se desarrollan en mayor n�mero por los claros donde los �rboles dejan "
            "m�s espacio. Est�s precisamente en uno de esos claros. Junto a los grupos de"
            " malezas ves una roca de gran tama�o, sobre la que incluso podr�as sentarte.\n";
            AddDetail(({"gran roca", "roca", "piedra", "gran piedra"}), "Se trata de una "
            "roca que parece puesta a prop�sito para que alguien se siente sobre ella."
            " Por supuesto que su forma no es la de un banco, pero tiene un buen tama�o y"
            " parece estar s�lidamente emplazada en el suelo.\n");
            break;
        case 9:
            bloque2="El suelo que pisas est� recubierto por una tierra delgada y "
            "f�rtil, sobre la que han crecido diferentes tipos de �rboles, arbustos y "
            "malezas.\n  Ves algunas rocas dispersas, a las que tambi�n se han aferrado "
            "los arbustos.\n";
            AddDetail(({"piedras", "rocas dispersas", "rocas"}), "Son rocas comunes, "
            "en su mayor�a algo hundidas en la tierra.\n");
            break;
        case 10:
            bloque2="Pisas una tierra fina y delgada que, a juzgar por la vegetaci�n "
            "que observas, es adem�s muy f�rtil. Puedes ver arbustos y malezas casi por "
            "todas partes, cubriendo lo que los �rboles dejan libre.\n";
            break;
        case 11:
            bloque2= "Aqu�, los �rboles dejan un claro que te permite tener una visi�n "
            "amplia de los alrededores. Lejos, a mucha distancia hacia el oeste, aprecias"
            " lo que te parece el pico de una monta�a. Es probable que exista alg�n pasaje"
            " monta�oso por la regi�n.\n";
            break;
        case 12:
            bloque2= "Ves algunas ramas ca�das, seguramente pertenecen a alg�n �rbol "
            "que alguien habr� talado con anterioridad. Entre las hojas ves los restos "
            "de algo que parece un nido de p�jaros, pero s�lo son eso, restos.\n";
            break;
        case 13:
            bloque2= "�sta parte del bosque parece ligeramente m�s antigua, porque los "
            "�rboles, aunque j�venes son algo m�s frondosos, y hasta el sonido de la brisa"
            " en sus copas parece algo diferente.\n ";
            break;
        case 14:
            bloque2= "En esta zona puedes ver huellas de alg�n animal que ha pasado "
            "por aqu�. Son marcas de pisadas m�s o menos recientes, aunque no sabr�as "
            "especificar de qu� animal podr�a tratarse.\n";
            AddDetail("huellas", "Son unas huellas como de pezu�as o garras, pero no "
            "podr�as decir a qu� animal pertenecen. No parecen seguir ning�n camino; "
            "quiz�s el resto ya se haya borrado o est� cubierto por los arbustos.\n");
            break;
        case 15:
            bloque2="En un �rbol cercano puedes ver las huellas del trabajo de un "
            "hacha. Quien lo talaba debi� interrumpir su trabajo a medias, y las "
            "marcas han quedado en buena parte del tronco.\n";
            AddDetail(({"tronco", "marcas"}), "El pobre �rbol ha sido medio talado y lo "
            "han dejado a medias con sus heridas en la corteza.\n");
            break;
        case 16:
            bloque2="A lo lejos, en direcci�n oeste, divisas una baja regi�n monta�osa.\n";
            break;
        case 17:
            bloque2="Por esta zona se aprecian claramente unas huellas que no parecen "
            "de animal, es posible que quien ahbita este bosque ha pasado recientemente "
            "por aqu�.\n";
            AddDetail(({"huella", "huellas"}), "Son de botas y parecen frescas, deben "
            "de ser de quien habita el bosque, aunque tambie�n pueden ser de alg�n "
            "explorador o viajero.\n");
            break;
        case 18:
            bloque2="Escondido entre las ramas de un �rbol cercano puedes ver un nido "
            "de p�jaros, aunque no podr�as decir si se encuentra habitado porque casi est�"
            "totalmente recubierto de hojas. Se encuentra bien protegido de cualquier "
            "tormenta.\n";
            AddDetail("nido", "Entre las hojas de las ramas de un �rbol, puedes observar "
            "un nido de p�jaros muy bien construido y que parece bien fijado a las ramas."
            " No podr�as asegurar que est� vac�o, quiz�s todav�a conserve alg�n huevo "
            "de p�jaro.\n");
            AddItem(PNJ("marhalt/pajaro"), REFRESH_DESTRUCT);
            break;
        case 19:
            bloque2="Observas que en un �rbol cercano alguien ha intentado grabar "
            "sus iniciales. Es evidente que no lo ha hecho con algo lo bastante "
            "contundente, porque ya no pueden leerse y no son m�s que una marca sin "
            "forma sobre el tronco.\n";
            AddDetail(({"iniciales", "marca"}), "Las iniciales est�n demasiado borrosas,"
            " parece que han sido hechas con un objeto no apropiado para eso y ya casi "
            "no pueden leerse. Apenas se observan las marcas en el tronco.\n");
            break;
        case 20:
            bloque2="En esta zona los �rboles est�n m�s juntos, formando una especie "
            "de figura semicircular y dando un poco m�s de sombra.\n";
            break;
    }
    return bloque1 + bloque2;
}

string f_suelo(){
    switch(d3()){
        case 1:
            return "El suelo est� lleno de arbustos y malezas que crecen por todas "
            "partes, y cubierto por una tierra fina que se escurrir�a entre tus "
            "dedos si intentases cogerla; casi no quedan lugares libres de vegetaci�n.\n";
        case 2:
            return "Este suelo est� cubierto por una tierra fina y f�rtil que permite "
            "que crezca una vegetaci�n variada y colorida. En algunos lugares �sta es "
            "m�s abundante y cubre cada palmo del terreno, y en otros los claros "
            "dejan ver la tierra que hay debajo y sobre la que se afirman los �rboles.\n";
        case 3:
            return "La tierra que pisas es f�rtil y delgada, y si cogieras un pu�ado "
            "se te escurrir�a entre los dedos. Est� cubierta de vegetaci�n verde por "
            "doquier.\n";
    }
    return "";
}

string f_sonidos(){
    switch(d10()){
        case 1:
            return "Escuchas el aullar de un lobo en la distancia.\n";
        case 2:
            return "Te llega un sonido como el ulular de una lechuza.\n";
        case 3:
            return "Puedes o�r el murmullo de la brisa entre las ramas de los �rboles.\n";
        case 4:
            return "La brisa entre las ramas parece susurrarte en los o�dos.\n";
        case 5:
            return "Te llegan desde lejos los sonidos de la fauna del bosque.\n";
        case 6:
            return "Escuchas el golpetear de un hacha en la distancia.\n";
        case 7:
            return "Escuchas el canto de un p�jaro en un �rbol cercano.\n";
        case 8:
            return "Escuchas el movimiento de las ramas.\n";
        case 9:
            return "El aullido de un lobo se entremezcla con el canto de las aves sobre "
            "los �rboles.\n";
        case 10:
            return "El suave murmullo de la brisa te invade los o�dos.\n";
    }
    return "";
}

string f_olores(){
    switch(d10()){
        case 1:
            return "Hueles a resina y a madera reci�n cortada.\n";
        case 2:
            return "Percibes el aroma silvestre del bosque que te rodea.\n";
        case 3:
            return "Hueles a madera fresca.\n";
        case 4:
            return "Sientes el aroma de la tierra mezclado con el suave perfume de los "
            "�rboles.\n";
        case 5:
            return "Te llega con la brisa un perfume a flores silvestres.\n";
        case 6:
            return "Hueles a flores silvestres.\n";
        case 7:
            return "La brisa te trae el aroma silvestre de �rboles y arbustos.\n";
        case 8:
            return "Sientes el aroma indefinible de la vegetaci�n que te rodea.\n";
        case 9:
            return "Hueles a flores y frutos silvestres.\n";
        case 10:
            return "Aspiras el penetrante aroma de la sabia reci�n derramada.\n";
    }
    return "";
}

create(){
    ::create();
    SetIndoors(0);
    SetLocate("bosque de Marhalt");
    SetIntShort("el bosque de Marhalt");
    SetIntLong(descripciones());
    SetIntNoise(SF(f_sonidos));
    SetIntSmell(SF(f_olores));
    SetSoundEnvironment(SF(snd_ambiente), 5);
    AddDetail(({"suelo", "tierra", "arena", "tierra fina"}), SF(f_suelo));
    AddDetail(({"monta�a", "monta�as",  "pico de monta�a", "pico de la monta�a"}),
        "A lo lejos, hacia el oeste,  se aprecian los picos de algunas monta�as.\n"
        " Tu mirada se pierde en la altura de los picos, que de todos modos no "
        "alcanzas a divisar por completo. Apenas ves la silueta recort�ndose en la "
        "distancia, pero a�n est� demasiado lejos como para que puedas precisar m�s"
        " detalles.\n");
    AddDetail(({"ramas", "ramas ca�das", "ramas caidas"}), "Son unas ramas ca�das de "
    "�rbol, no demasiado largas pero llenas de hojas.\n");
    AddDetail(({"arbol","�rbol","arboles","�rboles"}),
        "Miras a tu alrededor y puedes observar que te rodean hayas, robles y "
        "alguna otra especie que no consigues identificar.\n");
    AddDetail(({"arboles corrientes", "�rboles corrientes", "arbol corriente",
        "�rbol corriente", "otra especie", "otras especies"}),
        "Son �rboles de distintas variedades, de flores y hojas bien diferentes entre "
        "s�, pero todos tienen en com�n el color verde intenso y el hecho de ser �rboles"
        " j�venes.\n");
    AddDetail("bosque", "El bosque te rodea, todo es vegetaci�n y armon�a entre los "
        "elementos.\n Examin�ndolo m�s detenidamente observas que los �rboles que te "
        "acompa�an deben de tener pocas d�cadas, con lo que forman un bosque joven y "
        "poco frondoso.\n");
    AddDetail(({"roble","robles"}), "Los robles de �ste bosque son silvestres, "
        "adem�s de j�venes y altos.\n");
    AddDetail(({"haya","hayas"}), "Son �rboles de gran longevidad que presentan"
        " un porte majestuoso y con su copa algo recogida, quiz� algo ovalada, su "
        "corteza es notablemente lisa.\n");
    AddDetail(({"reto�o", "reto�os", "arboles jovenes", "�rboles jovenes"}),
        "Son reto�os muy j�venes, en su mayor�a de robles y hayas, que son los "
        "�rboles que pueblan la mayor parte de este bosque.\n  Son plantas de color "
        "verde intenso y de escaso follaje que no tapa las entradas de luz. Sus "
        "troncos son todav�a muy delgados como para pensar en talarlos.\n");
    AddDetail(({"vegetacion", "vegetaci�n", "plantas", "plantas jovenes"}),
        "Se trata de vegetaci�n de lo m�s variado en especie y colorido. Va desde "
        "hierbas hasta arbustos y malezas. Desprende un aroma silvestre que es "
        "caracter�stico de este bosque.\n Todas las plantas de este bosque son j�venes"
        " y de tama�o mediano. No tienen copas frondosas, pero s� un intenso colorido "
        "que llena de vida cada recodo del bosque.\n");
    AddDetail("troncos", "Son troncos de �rboles j�venes, algunos lo suficientemente "
        "grandes como para que alguien piense en talarlos.\n");
    AddDetail(({"follaje", "follajes"}), "Todo el follaje que ves en este bosque es "
        "poco frondoso, porque los �rboles han sido plantados recientemente.\n  Las "
        "ramas dejan lugar para que se filtre la luz, y en muchas de ellas ves "
        "brotes verdes que hacen pensar que en unos a�os, todo esto podr�a estar m�s "
        "frondoso.\n");
    AddDetail(({"arbustos", "arbusto"}), "Por todas partes ves arbustos que crecen "
        "muy juntos, aunque no lo bastante espesos como para cerrarte el paso. No "
        "puedes identificar a qu� clase pertenecen porque observas una infinidad de "
        "variedades distintas. Llama la atenci�n su colorido intenso.\n");
    AddDetail("maleza", "Todav�a se trata de maleza joven, vigorosa pero no invasiva "
        "del terreno. \n Son grupos de malezas de distintas clases que parecen "
        "poblar gran parte del suelo de este bosque.\n");
    AddRoomCmd("coger", "cmd_coger");

    switch(random(150)){
        case 0:
            AddItem(HERBS("seta_intoxicante"), REFRESH_REMOVE, 1);
            break;
        case 10:
            AddItem(HERBS("hierba_saciante"), REFRESH_REMOVE,1);
            break;
        case 20:
            AddItem(HERBS("hierba_magica"), REFRESH_REMOVE, 1);
            break;
        case 30:
            AddItem(HERBS("hierba_curativa"), REFRESH_REMOVE, 1);
            break;
        case 40:
            AddItem(HERBS("hierba_narcotica"),REFRESH_REMOVE,1);
            break;
        case 50:
            AddItem(HERBS("hierba_intoxicante"), REFRESH_REMOVE, 1);
            break;
        case 60:
            AddItem(HERBS("seta_saciante"), REFRESH_REMOVE, 1);
            break;
        case 70:
            AddItem(HERBS("seta_magica"), REFRESH_REMOVE, 1);
            break;
        case 80:
            AddItem(HERBS("seta_curativa"), REFRESH_REMOVE, 1);
            break;
        case 90:
            AddItem(HERBS("seta_narcotica"), REFRESH_REMOVE, 1);
            break;
        case 100:
            AddItem(HERBS("hierba_venenosa"), REFRESH_REMOVE, 1);
            break;
        case 110:
            AddItem(HERBS("seta_venenosa"), REFRESH_REMOVE, 1);
            break;
    }

    if (d2()==1)
        AddItem(PNJ("marhalt/animales_bosque"), REFRESH_DESTRUCT);
}

public int cmd_coger(string str){
    if (str=="tierra" || str=="arena"){
        write("Coges un pu�ado de tierra del suelo, pero se te escurre por los dedos y "
        "al final te quedas sin nada en la mano.\n");
        say(CAP(TNAME)+ " intenta coger tierra del suelo, pero no lo consigue.\n");
        return 1;
    }
    return 0;
}
/*
public void animales(){
    object animal=clone_object(PNJ("marhalt/animales_bosque"));
    //AddItem(animal, REFRESH_DESTRUCT, 1);
    animal->move(environment(TP),M_SILENT);
    if(animal->id("aguila") || animal->id("lechuza") || animal->id("ave")){
        tell_room(environment(animal), "Observas como "+animal->QueryShort()+" llega "
        "volando y se mantiene a distancia.\n");
    }else{
        tell_room(environment(animal), "Escuchas movimiento de ramas detr�s de t� y ves "
        "que es "+animal->QueryShort()+" que estaba entre la maleza.\n");
    }
}

public void pajarito(){
    object pajaro=clone_object(PNJ("marhalt/pajaro"));
    //AddItem(pajaro,REFRESH_DESTRUCT,1);
    pajaro->move(environment(TP), M_SILENT);
    tell_room(environment(pajaro), "Un bonito pajarito llega volando y se posa cerca de t�.\n");
}
*/
public varargs string snd_ambiente(int newstate){
    int hora;
    string sonido;
    if (newstate)
    // si la funci�n se llama con un estado nuevo, es que ha sido llamada por NotifyDayStateChange.
    // Si no, ha sido llamada por el SoundEnvironment
    {
        hora = newstate;
    }
    else
    {
        hora = QueryServer()->QueryState();
    }

    if(hora==ND_NIGHT || hora==ND_PREDAWN || hora==ND_DAWN || hora==ND_PRENIGHT){
        sonido = SND_AMBIENTES("noche_grillos");
    }else{
        sonido = SND_AMBIENTES("bosque1");
    }
    if (newstate && sonido != last_sound)
    // Si se ha llamado desde el NotifyDayStateChange y el sonido ha cambiado con respecto al
    // �ltimo, se hace stop_sound y PlaySound
    // pues si no los que est�n dentro no se enterar�an del cambio.
    // Si el sonido es el mismo no hacemos nada, ya que no tiene sentido pararlo y volverlo a iniciar
    // si va a seguir sonando el mismo
    {
        stop_sounds(TO);
        play_sound(TO, sonido, 0, 5, -1);
    }
    last_sound = sonido;
    return sonido;
}

public void NotifyDayStateChange(mixed data, int newstate)
{
    ::NotifyDayStateChange(data, newstate);
    snd_ambiente(newstate);
}

