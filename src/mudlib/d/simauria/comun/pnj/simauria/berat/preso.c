/****************************************************************************
Fichero: preso.c
Autor: Dharkus y Ratwor
Fecha: 08/05/2010
Descripci�n: Tres presos aleatorios para el calabozo de Berat.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>

inherit NPC;

create() {
    "*"::create();
    AddId("preso");
    
    switch(d3()){
        case 1:
            SetStandard("un borracho", "humano", ([GC_TORPE:8]), GENDER_MALE);
            AddId(({"borracho","hombre"}));
            SetShort("un borracho");
            SetLong("Es un pobre hombre enclenque y encorvado con largo pelo sucio "
            "y embara�ado.\n Su mirada perdida no parece mirar a ninguna parte "
            "en conccreto.\n Sus sucios y castigados pies desccalzos est�n llenos "
            "de heridas y durezas negras, fruto de una larga vida de andadura descalza.\n");
            SetAlcohol(100);
            InitChats(4,({
            "El borracho mueve la cabeza asintiendo sin sentido.\n",
            "El borracho erupta ruidosamente.\n",
            "El borracho te dice: vino, s�, s�, mejor vino.\n",
            "El boracho dice: aquello s� que era vida... todo un para�so...\n",
            "El borracho solloza.\n",
            "El borracho comenta en voz baja: yo, fu� yo, todo por mi culpa.\n"}));
            SetShrugMsg("El borracho no parece prestarte atenci�n.\n");
            AddQuestion(({"vida", "vino", "alcohol", "culpa"}), "El borracho se pone las "
            "manos en la cara y lloriquea.\n");
            AddItem(PROT("berat/tunica_vieja"), REFRESH_REMOVE, SF(wearme));
            break;
        case 2:
            SetStandard("un kender","kender",([GC_NINGUNO:13]),GENDER_MALE);
            AddId("kender");
            SetAds(({"viejo","aventurero","poliz�n"}));
            SetShort("un viejo kender");
            SetLong("Se trata de un poliz�n que apresaron en uno de los barcos "
            "llegados al puerto de Berat desde tierras lejanas.\n Es una criatura "
            "que a penas sobrepasa el metro de altura.\n Tiene rasgos de haber "
            "vivido muchos a�os y cientos de viajes y aventuras; pero a�n as� conserva "
            "la alegr�a y la chispa t�pica de su raza.\n");
            InitChats(4,({
            "El viejo kender te sonr�e animadamente.\n",
            "El viejo kender dice: �Vaya aventura esta!, nada menos que he llegado "
            "al dominio de los humanos.\n",
            "El kender comenta: Un poco rudos estos humanos... me han sacado del "
            "barco a patadas...\n",
            "El viejo kender te dice:\n 'Podr�a contarte cientos de viajes y aventuras...'\n",
            "El kender comenta: Me han quitado todo lo que llevaba... una pena... "
            "aunque me vastan mis piernas para seguir con mis aventuras.\n"}));
            AddQuestion(({"viaje","viajes","aventuras"}),
            "E viejo kender dice:\n '�Oh, mis aventuras... he vivido muchas! �Sabes?"
            "he convivido con gnomos, sabias criaturas... He atravesado algunos "
            "de los grandes bosques de Lad-Laurelin, grandes y espesos, �s� se�or!\n "
            "Incluso llegu� a alcanzar la costa sudeste del dominio: Andalo, "
            "Mithondin... �qu� buenos cart�grafos esos elfos!\n Tambi�n he conocido "
            "a esas maravillosas hadas de los profundos bosques de Faeria... �qu� "
            "bonito todo aquello!\n Y esos rudos enanos de Kha-annu y sus ciudades "
            "bajo tierra... Unas costumbres un tanto extra�as las de esos enanos.\n "
            "A�n me queda mucho por conocer...'\n");
            AddQuestion("gnomos",
            "El viejo kender aventurero dice:\n Muy sabios esos seres... y muy "
            "peque�os... �son incluso m�s peque�os que yo!\n  Viven dentro de grandes "
            "troncos y en escondidas cuevas.\n La naturaleza  lo es todo para ellos, "
            "y la magia por supuesto...\n");
            AddQuestion("enanos","El viejo kender dice:\n Los enanos, siempre quieren "
            "vivir bajo tierra, no los entiendo...\n �con lo bonita que es la "
            "naturaleza!\n Viven en ciudades subterr�neas y les gusta mucho los "
            "metales y las armas... no me dejaron usmear mucho por sus tierras.\n");
            AddQuestion("elfos", "El viejo kender dice:\n Los elfos que he conocido "
            "viven en Lad-laurelin, aunque posiblemente haya m�s elfos en otras "
            "partes del mundo.\n Son bastante dispares aunque muy comunes entre "
            "s� al mismo tiempo.\n Est�n los elfos silvanos que aman la naturaleza "
            "sobre todas las cosas y siempre viven en los bosques.\n Tambi�n hay "
            "otros elfos m�s refinados que viven en ciudades, entre m�rmoles y sedas.\n"
            "Y los medio elfos son muy buenos artesanos y buenas gentes, aunque "
            "he visto pocos.\n Nunca he conocido a los elfos oscuros, de momento "
            "prefiero evitarlos, hablan cosas terribles de ellos.\n");
            AddQuestion("lad-laurelin", "El viejo kender dice:\n Es el dominio "
            "de los elfos, se encuentra muy al este de donde nos encontramos nosotros "
            "ahora.\n All� lo que abunda son los bosques y la magia... mucha magia.\n");
            AddQuestion("faeria", "El viejo kender dice abriendo bien los ojos:\n "
            "Es un lugar maravilloso, todo es magia y seres de lo m�s interesante.\n "
            "Se encuentra m�s o menos hacia el noroeste de Lad-laurelin, pero no "
            "es nada f�cil encontrarlo... �No se�or!\n hadas, druidas, magia, driadas, "
            "centauros...\n aquello es otro mundo...\n");
            AddQuestion(({"andalo","mithondrin"}),
            "El viejo kender dice:\n All� es donde los elfos encontraron y conocieron "
            "el mar y desde donde se comunican y comercian con el resto del mundo.\n "
            "�Buenos artesanos y cart�grafos esos elfos!\n");
            AddQuestion(({"hadas","druidas","centauros", "driadas"}),
            "El viejo dice pensativo:\n Eso es para verlo, no se puede contar as� "
            "como as�...\n Parece algo increible...\n");
            AddQuestion("kenton", "El viejo kender sonr�e y exclama:\n �Yo soy "
            "de all�!\n �lo conoces?\n Hace mucho que no voy...\n Soy algo inquieto "
            "y necesito viajar...\n Flenton, hurgaton, khurton, klariton, nainton...\n "
            "Buena tierra...\n");
            AddQuestion(({"Flenton","hurgaton","khurton","klariton","nainton"}),
            "El viejo kender dice:\n Si no has estado all� te lo recomiendo, los "
            "kender somos buena gente y buenos anfitriones, mejor que vayas a "
            "conocerlo por ti mismo.\n");
            InitAChats(10,({
            "El kender se intenta tapar la cabeza.\n",
            "El kviejo kender exclama: �Yo no he hecho da�o a nadie!\n",
            "El viejo kender grita: �Nooo!\n",
            "El kender exclama: �no me pegues!\n"}));
            SetShrugMsg("El kender dice: 'ummm, no s�, no s�.'\n");
            AddItem(PROT("berat/pantalon_p"), REFRESH_REMOVE, SF(wearme));
            AddItem(PROT("berat/mocasines_p"), REFRESH_REMOVE, SF(wearme));
            AddItem(PROT("berat/chaleco_p"), REFRESH_REMOVE, SF(wearme));
            break;
        case 3:
            SetStandard("un maleante","humano",([GC_LUCHADOR:25]),GENDER_MALE);
            SetAggressive(random(2));
            AddId(({"maleante","marino","hombre"}));
            SetAds(({"rudo","fortach�n","fortachon"}));
            SetShort("un maleante");
            SetLong("Es un marino rudo y fortach�n con enormes y temibles manos.\n "
            "Sus malos modales y agresividad destacan sobremanera en sus facciones "
            "se�aladas por multitud de peleas y enfrentamientos.\n");
            InitChats(4,({
            "El maleante grita: �me vais a sacar de aqu� o qu�?\n",
            "El maleante te mira con agresividad.\n",
            "El maleante exclama: �traedme algo de comer que me est�is matando "
            "de hambre!\n",
            "El maleante te grita: �Qu� quieres?\n",
            "el maleante da un pu�etazo en la pared.\n",
            "El maleante te amenaza con el pu�o.\n",
            "El maleante te dice: venga p�game si te atreves.\n",
            "El maleante te dice:\n 'Tienes la cara m�s fea que he visto en mi "
            "vida. �Te pareces a un mono!'\n"}));
            InitAChats(6,({"El maleante te intenta dar un cabezazo.\n",
            "El maleante gru�e apretando los pu�os.\n",
            "El maleante te escupe.\n"}));
            SetShrugMsg("El maleante grita: �yo no estoy aqu� para que me hagan preguntas!\n");
            AddItem(PROT("berat/pantalon_marinero"), REFRESH_REMOVE, SF(wearme));
            AddItem(PROT("berat/bluson_marinero"), REFRESH_REMOVE, SF(wearme));
            AddItem(PROT("berat/sombrero_paja"), REFRESH_REMOVE, SF(wearme));
            break;
    }
}
