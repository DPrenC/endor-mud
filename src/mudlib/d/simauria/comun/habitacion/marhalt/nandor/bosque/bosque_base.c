/****************************************************************************
Fichero: bosque_base.c
Autor: Ratwor
Fecha: 07/12/2006
Descripción: El archivo base del bosque de marhalt.
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
            bloque1= "Estás en el bosque de Marhalt, ubicado al sur de Nandor. Es "
            "un bosque joven, lleno de luz y de vida. Te rodean árboles y retoños. En "
            "su mayoría son robles y hayas, aunque también puedes ver algunas otras "
            "especies que no sabrías identificar.\n A lo lejos, el aullido de un lobo "
            "muestra que no sólo los árboles habitan estas regiones de Simauria.\n";
            break;
        case 2:
            bloque1= "Te encuentras en el bosque de Marhalt, al norte de la capital "
            "Ishtria. Este lugar está poblado de vegetación joven, en su mayor parte "
            "robles y hayas, que lo llenan todo de un colorido intenso. Al tratarse "
            "de árboles medianos, la luz natural puede filtrarse entre las ramas sin "
            "dejar lugares oscuros.\n";
            break;
        case 3:
            bloque1= "Estás en el bosque de Marhalt, al sur de Nandor y al norte de la "
            "capital de Simauria. Es un bosque lleno de árboles medianos de todo tipo, "
            "aunque predominan robles y hayas. La vegetación lo inunda todo, pero se "
            "trata de plantas jóvenes que no cierran el paso al caminante.\n Escuchas "
            "a lo lejos el ulular de una lechuza, que demuestra que también hay por "
            "aquí fauna variada.\n";
            break;
        case 4:
            bloque1= "Te encuentras en el bosque de Marhalt, rodeado de árboles que, "
            "lejos de obstruirte el paso, te permiten mirar por entre sus troncos y "
            "follajes. Se trata de árboles jóvenes, de hojas muy verdes. En su "
            "mayoría ves robles y hayas, aunque también hay otros tipos de plantas "
            "que no sabrías clasificar.\n  Puedes oír la brisa moviendo las ramas, y "
            "de tanto en tanto te llega el sonido de algún animal en la distancia.\n";
            break;
        case 5:
            bloque1= "Te encuentras en el bosque de Marhalt. Esta extensión verde está "
            "poblada de árboles jóvenes y retoños, en su mayoría robles y hayas aunque"
            " también puedes ver árboles más corrientes pero que no sabrías identificar. "
            " Se aprecia cómo la brisa mueve las verdes ramas.\n  Puedes observar "
            "diversos claros entre los árboles, por donde transcurren pequeños "
            "senderos naturales.\n";
            break;
        case 6:
            bloque1= " Te encuentras en el bosque de Marhalt, y por todos lados ves "
            "árboles jóvenes de escaso follaje.  Observas incluso algunos retoños. En "
            "su mayoría son hayas y robles, aunque también ves árboles silvestres.\n"
            " Te llega el sonido de la brisa entre las ramas, entremezclado con"
            " algún aullido lejano.\n";
            break;
        case 7:
            bloque1= "Retoños y árboles medianos invaden este bosque que la naturaleza ha"
            " puesto recientemente. El verde es intenso y el aroma de los árboles, "
            "en su mayoría hayas y robles, es penetrante.\n  La brisa que agita las "
            "ramas trae también sonidos lejanos, entre los que percibes algún aullido de"
            " lo que podría reconocerse como de lobo.\n  La luz lo invade todo y no hay "
            "rincones oscuros.\n";
            break;
        case 8:
            bloque1= "En este bosque al sur de Nandor, y al norte de Ishtria, una mano "
            "parece haber tenido especial cuidado en plantar fundamentalmente robles "
            "y hayas, aunque también puedes ver árboles más corrientes. Pero aún "
            "así todos son árboles jóvenes llenos de vida y de un color verde intenso. "
            " Sus troncos parecen ser de muy buena madera.\n Por distintas partes se "
            "ven claros dejados por los árboles, cuyas copas tampoco son, en su "
            "mayoría, demasiado frondosas.\n";
            break;
        case 9:
            bloque1= " Estás en el bosque de Marhalt. Te rodean árboles jóvenes y de "
            "escaso follaje, en su mayoría robles y hayas, que en algunos sitios "
            "dejan claros por donde transcurren pequeños caminos naturales. Las "
            "copas, abiertas y poco frondosas, permiten que el lugar parezca lleno de "
            "vida y colorido a los ojos de quien lo mire.\n  Desde lejos te llega el "
            "ulular de una lechuza, demostrando que también viven animales por aquí.\n";
            break;
        case 10:
            bloque1= " Estás en el bosque de Marhalt, al sur de Nandor y al norte de "
            "Ishtria. Por donde mires ves árboles jóvenes y retoños, en su mayor parte "
            "robles y hayas, aunque también puedes encontrar árboles de otras especies "
            "dificiles de clasificar.\n La brisa te trae aromas y sonidos, y escuchas a "
            "la distancia algo parecido al aullido de un lobo.\n";
            break;
    }

    switch(d20()){
         case 1:
            bloque2= "El suelo de este bosque está cubierto por una tierra fina y "
            "aparentemente fértil, a juzgar por la cantidad de vegetación que crece por "
            "todas partes. Observas arbustos carnosos y también algunas malezas,"
            " que sin embargo no llegan a obstruir el paso.\n";
            break;
        case 2:
            bloque2= "Ésta es una porción de terreno cubierta por una tierra fina y "
            "fértil sobre la que crece todo tipo de vegetación.\n  Aquí se encuentra "
            "un árbol que ha sido recientemente talado, esperando ser recogido en "
            "breve.\n";
            AddDetail(({"arbol talado", "árbol talado", "arbol cortado", "árbol cortado"}),
            "Es un tronco en el que son visibles las huellas del hacha. Está caído, el "
            "árbol robusto que era ha sido cortado y parte de él seguramente arderá "
            "pronto en alguna hoguera. \n Ves cortes de hacha a lo largo y ancho de lo "
            "que ha quedado del tronco.\n");
            break;
        case 3:
            bloque2= "El suelo del bosque es indudablemente fértil, como lo demuestra "
            "la abundante vegetación que se ha desarrollado por aquí.\n  En ésta "
            "parte los árboles no están tan juntos y puedes ver un claro. En él, "
            "observas un grupo de rocas dispuestas creativamente, formando una extraña "
            "figura indefinida.\n";
            AddDetail(({"grupo de rocas", "rocas", "figura", "figura indefinida"}),
            "Son unas grandes rocas agrupadas y dispuestas formando una especie de "
            "semicírculo o media luna. En el centro, otra roca más pequeña queda "
            "semioculta por las más grandes.\n");
            break;
        case 4:
            bloque2= "Algunos arbustos y malezas se agrupan en esta parte del bosque, "
            "aunque no obstruyen ni bloquean el paso. Son plantas jóvenes que todavía no "
            "han crecido lo suficiente.\n  El suelo está recubierto por una tierra "
            "fina que parece ser muy fértil, a juzgar por la abundante vegetación.\n";
            break;
        case 5:
            bloque2="La vegetación crece por todas partes, y donde los árboles dejan"
            " un claro se agrupan los arbustos. Son frecuentes distintos sonidos de "
            "animales.\n";
            break;
        case 6:
            bloque2="Te encuentras sobre un suelo muy fértil, recubierto por una tierra"
            " fina que parece permitir el crecimiento de una vegetación muy variada."
            " Arbustos y malezas se entremezclan en algunos lugares, pero como se trata "
            "de plantas jóvenes, no obstruyen ni cierran el paso.\n";
            break;
        case 7:
            bloque2="Te hallas sobre un suelo recubierto de tierra fina y muy fértil, "
            "en la que crece variada y abundante vegetación. Dicha vegetación, en "
            "consonancia con los árboles robustos, dan un ambiente agradable y alegre"
            " al entorno.\n";
            break;
        case 8:
            bloque2="El suelo de este bosque es rico en malezas y arbustos, que "
            "se desarrollan en mayor número por los claros donde los árboles dejan "
            "más espacio. Estás precisamente en uno de esos claros. Junto a los grupos de"
            " malezas ves una roca de gran tamaño, sobre la que incluso podrías sentarte.\n";
            AddDetail(({"gran roca", "roca", "piedra", "gran piedra"}), "Se trata de una "
            "roca que parece puesta a propósito para que alguien se siente sobre ella."
            " Por supuesto que su forma no es la de un banco, pero tiene un buen tamaño y"
            " parece estar sólidamente emplazada en el suelo.\n");
            break;
        case 9:
            bloque2="El suelo que pisas está recubierto por una tierra delgada y "
            "fértil, sobre la que han crecido diferentes tipos de árboles, arbustos y "
            "malezas.\n  Ves algunas rocas dispersas, a las que también se han aferrado "
            "los arbustos.\n";
            AddDetail(({"piedras", "rocas dispersas", "rocas"}), "Son rocas comunes, "
            "en su mayoría algo hundidas en la tierra.\n");
            break;
        case 10:
            bloque2="Pisas una tierra fina y delgada que, a juzgar por la vegetación "
            "que observas, es además muy fértil. Puedes ver arbustos y malezas casi por "
            "todas partes, cubriendo lo que los árboles dejan libre.\n";
            break;
        case 11:
            bloque2= "Aquí, los árboles dejan un claro que te permite tener una visión "
            "amplia de los alrededores. Lejos, a mucha distancia hacia el oeste, aprecias"
            " lo que te parece el pico de una montaña. Es probable que exista algún pasaje"
            " montañoso por la región.\n";
            break;
        case 12:
            bloque2= "Ves algunas ramas caídas, seguramente pertenecen a algún árbol "
            "que alguien habrá talado con anterioridad. Entre las hojas ves los restos "
            "de algo que parece un nido de pájaros, pero sólo son eso, restos.\n";
            break;
        case 13:
            bloque2= "Ésta parte del bosque parece ligeramente más antigua, porque los "
            "árboles, aunque jóvenes son algo más frondosos, y hasta el sonido de la brisa"
            " en sus copas parece algo diferente.\n ";
            break;
        case 14:
            bloque2= "En esta zona puedes ver huellas de algún animal que ha pasado "
            "por aquí. Son marcas de pisadas más o menos recientes, aunque no sabrías "
            "especificar de qué animal podría tratarse.\n";
            AddDetail("huellas", "Son unas huellas como de pezuñas o garras, pero no "
            "podrías decir a qué animal pertenecen. No parecen seguir ningún camino; "
            "quizás el resto ya se haya borrado o esté cubierto por los arbustos.\n");
            break;
        case 15:
            bloque2="En un árbol cercano puedes ver las huellas del trabajo de un "
            "hacha. Quien lo talaba debió interrumpir su trabajo a medias, y las "
            "marcas han quedado en buena parte del tronco.\n";
            AddDetail(({"tronco", "marcas"}), "El pobre árbol ha sido medio talado y lo "
            "han dejado a medias con sus heridas en la corteza.\n");
            break;
        case 16:
            bloque2="A lo lejos, en dirección oeste, divisas una baja región montañosa.\n";
            break;
        case 17:
            bloque2="Por esta zona se aprecian claramente unas huellas que no parecen "
            "de animal, es posible que quien ahbita este bosque ha pasado recientemente "
            "por aquí.\n";
            AddDetail(({"huella", "huellas"}), "Son de botas y parecen frescas, deben "
            "de ser de quien habita el bosque, aunque tambie´n pueden ser de algún "
            "explorador o viajero.\n");
            break;
        case 18:
            bloque2="Escondido entre las ramas de un árbol cercano puedes ver un nido "
            "de pájaros, aunque no podrías decir si se encuentra habitado porque casi está"
            "totalmente recubierto de hojas. Se encuentra bien protegido de cualquier "
            "tormenta.\n";
            AddDetail("nido", "Entre las hojas de las ramas de un árbol, puedes observar "
            "un nido de pájaros muy bien construido y que parece bien fijado a las ramas."
            " No podrías asegurar que esté vacío, quizás todavía conserve algún huevo "
            "de pájaro.\n");
            AddItem(PNJ("marhalt/pajaro"), REFRESH_DESTRUCT);
            break;
        case 19:
            bloque2="Observas que en un árbol cercano alguien ha intentado grabar "
            "sus iniciales. Es evidente que no lo ha hecho con algo lo bastante "
            "contundente, porque ya no pueden leerse y no son más que una marca sin "
            "forma sobre el tronco.\n";
            AddDetail(({"iniciales", "marca"}), "Las iniciales están demasiado borrosas,"
            " parece que han sido hechas con un objeto no apropiado para eso y ya casi "
            "no pueden leerse. Apenas se observan las marcas en el tronco.\n");
            break;
        case 20:
            bloque2="En esta zona los árboles están más juntos, formando una especie "
            "de figura semicircular y dando un poco más de sombra.\n";
            break;
    }
    return bloque1 + bloque2;
}

string f_suelo(){
    switch(d3()){
        case 1:
            return "El suelo está lleno de arbustos y malezas que crecen por todas "
            "partes, y cubierto por una tierra fina que se escurriría entre tus "
            "dedos si intentases cogerla; casi no quedan lugares libres de vegetación.\n";
        case 2:
            return "Este suelo está cubierto por una tierra fina y fértil que permite "
            "que crezca una vegetación variada y colorida. En algunos lugares ésta es "
            "más abundante y cubre cada palmo del terreno, y en otros los claros "
            "dejan ver la tierra que hay debajo y sobre la que se afirman los árboles.\n";
        case 3:
            return "La tierra que pisas es fértil y delgada, y si cogieras un puñado "
            "se te escurriría entre los dedos. Está cubierta de vegetación verde por "
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
            return "Puedes oír el murmullo de la brisa entre las ramas de los árboles.\n";
        case 4:
            return "La brisa entre las ramas parece susurrarte en los oídos.\n";
        case 5:
            return "Te llegan desde lejos los sonidos de la fauna del bosque.\n";
        case 6:
            return "Escuchas el golpetear de un hacha en la distancia.\n";
        case 7:
            return "Escuchas el canto de un pájaro en un árbol cercano.\n";
        case 8:
            return "Escuchas el movimiento de las ramas.\n";
        case 9:
            return "El aullido de un lobo se entremezcla con el canto de las aves sobre "
            "los árboles.\n";
        case 10:
            return "El suave murmullo de la brisa te invade los oídos.\n";
    }
    return "";
}

string f_olores(){
    switch(d10()){
        case 1:
            return "Hueles a resina y a madera recién cortada.\n";
        case 2:
            return "Percibes el aroma silvestre del bosque que te rodea.\n";
        case 3:
            return "Hueles a madera fresca.\n";
        case 4:
            return "Sientes el aroma de la tierra mezclado con el suave perfume de los "
            "árboles.\n";
        case 5:
            return "Te llega con la brisa un perfume a flores silvestres.\n";
        case 6:
            return "Hueles a flores silvestres.\n";
        case 7:
            return "La brisa te trae el aroma silvestre de árboles y arbustos.\n";
        case 8:
            return "Sientes el aroma indefinible de la vegetación que te rodea.\n";
        case 9:
            return "Hueles a flores y frutos silvestres.\n";
        case 10:
            return "Aspiras el penetrante aroma de la sabia recién derramada.\n";
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
    AddDetail(({"montaña", "montañas",  "pico de montaña", "pico de la montaña"}),
        "A lo lejos, hacia el oeste,  se aprecian los picos de algunas montañas.\n"
        " Tu mirada se pierde en la altura de los picos, que de todos modos no "
        "alcanzas a divisar por completo. Apenas ves la silueta recortándose en la "
        "distancia, pero aún está demasiado lejos como para que puedas precisar más"
        " detalles.\n");
    AddDetail(({"ramas", "ramas caídas", "ramas caidas"}), "Son unas ramas caídas de "
    "árbol, no demasiado largas pero llenas de hojas.\n");
    AddDetail(({"arbol","árbol","arboles","árboles"}),
        "Miras a tu alrededor y puedes observar que te rodean hayas, robles y "
        "alguna otra especie que no consigues identificar.\n");
    AddDetail(({"arboles corrientes", "árboles corrientes", "arbol corriente",
        "árbol corriente", "otra especie", "otras especies"}),
        "Son árboles de distintas variedades, de flores y hojas bien diferentes entre "
        "sí, pero todos tienen en común el color verde intenso y el hecho de ser árboles"
        " jóvenes.\n");
    AddDetail("bosque", "El bosque te rodea, todo es vegetación y armonía entre los "
        "elementos.\n Examinándolo más detenidamente observas que los árboles que te "
        "acompañan deben de tener pocas décadas, con lo que forman un bosque joven y "
        "poco frondoso.\n");
    AddDetail(({"roble","robles"}), "Los robles de éste bosque son silvestres, "
        "además de jóvenes y altos.\n");
    AddDetail(({"haya","hayas"}), "Son árboles de gran longevidad que presentan"
        " un porte majestuoso y con su copa algo recogida, quizá algo ovalada, su "
        "corteza es notablemente lisa.\n");
    AddDetail(({"retoño", "retoños", "arboles jovenes", "árboles jovenes"}),
        "Son retoños muy jóvenes, en su mayoría de robles y hayas, que son los "
        "árboles que pueblan la mayor parte de este bosque.\n  Son plantas de color "
        "verde intenso y de escaso follaje que no tapa las entradas de luz. Sus "
        "troncos son todavía muy delgados como para pensar en talarlos.\n");
    AddDetail(({"vegetacion", "vegetación", "plantas", "plantas jovenes"}),
        "Se trata de vegetación de lo más variado en especie y colorido. Va desde "
        "hierbas hasta arbustos y malezas. Desprende un aroma silvestre que es "
        "característico de este bosque.\n Todas las plantas de este bosque son jóvenes"
        " y de tamaño mediano. No tienen copas frondosas, pero sí un intenso colorido "
        "que llena de vida cada recodo del bosque.\n");
    AddDetail("troncos", "Son troncos de árboles jóvenes, algunos lo suficientemente "
        "grandes como para que alguien piense en talarlos.\n");
    AddDetail(({"follaje", "follajes"}), "Todo el follaje que ves en este bosque es "
        "poco frondoso, porque los árboles han sido plantados recientemente.\n  Las "
        "ramas dejan lugar para que se filtre la luz, y en muchas de ellas ves "
        "brotes verdes que hacen pensar que en unos años, todo esto podría estar más "
        "frondoso.\n");
    AddDetail(({"arbustos", "arbusto"}), "Por todas partes ves arbustos que crecen "
        "muy juntos, aunque no lo bastante espesos como para cerrarte el paso. No "
        "puedes identificar a qué clase pertenecen porque observas una infinidad de "
        "variedades distintas. Llama la atención su colorido intenso.\n");
    AddDetail("maleza", "Todavía se trata de maleza joven, vigorosa pero no invasiva "
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
        write("Coges un puñado de tierra del suelo, pero se te escurre por los dedos y "
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
        tell_room(environment(animal), "Escuchas movimiento de ramas detrás de tí y ves "
        "que es "+animal->QueryShort()+" que estaba entre la maleza.\n");
    }
}

public void pajarito(){
    object pajaro=clone_object(PNJ("marhalt/pajaro"));
    //AddItem(pajaro,REFRESH_DESTRUCT,1);
    pajaro->move(environment(TP), M_SILENT);
    tell_room(environment(pajaro), "Un bonito pajarito llega volando y se posa cerca de tí.\n");
}
*/
public varargs string snd_ambiente(int newstate){
    int hora;
    string sonido;
    if (newstate)
    // si la función se llama con un estado nuevo, es que ha sido llamada por NotifyDayStateChange.
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
    // último, se hace stop_sound y PlaySound
    // pues si no los que están dentro no se enterarían del cambio.
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

