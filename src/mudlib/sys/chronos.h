#ifndef __CHRONOS_H
#define __CHRONOS_H
string *MSG_DEFAULT_DIA = ({
 /* Normal */
	 ({"El cielo est� azul y totalmente despejado y Un sol espl�ndido brilla en el cielo.\n",
	 "Una leve brisa sopla en casi imperceptibles r�fagas.\n",
	 "Unas cuantas nubecillas blancas recorren lentamente el cielo iluminado por el "
	 "astro diurno.\n",
	 "Un leve soplo de brisa acaricia tu rostro junto con los suaves rayos del sol.\n",
	 "Un apacible vientecillo hace tremolear tus ropas.\n",
	 "Sopla una ligera brisa.\n",
	 "Un c�mulo de nubes tapa el sol moment�neamente.\n",
	 "Se levanta un viento fresco.\n",
	 "Poco a poco, el viento deja de soplar.\n",
	 "Algunas nubes recorren el cielo.\n",
	 "El cielo aparece azul y sereno.\n",
	 "Un leve vientecillo recorre el paisaje.\n"}),
 /* Calor */
  	 ({"El cielo est� despejado y el sol calienta agradablemente.\n",
	 "El sol brilla en lo alto con fuerza y cada vez hace m�s calor.\n",
	 "Hace mucho calor y no se percibe ni un solo soplo de brisa.\n",
  	 "Bajo el intenso calor el paisaje parece rielar.\n",
  	 "Los ardientes rayos del sol caen sobre ti sin piedad.\n",
  	 "Hace un calor agobiante.\n",
	 "El intenso calor no se ve alterado por la m�s m�nima brisa.\n",
  	 "Se levanta una brisa c�lida. Algunas nubecillas blancas navegan lentamente por el cielo.\n",
  	 "La brisa se vuelve algo m�s fresca y la temperatura desciende un poco.\n",
	 "El calor va remitiendo mientras las rachas de viento se intensifican y refrescan el lugar.\n",
 	 "La brisa empuja un c�mulo de nubes que ocultan por unos instantes el sol, dando tregua ante sus intensos rayos.\n",
 	 "El viento sopla con mayor intensidad por unos momentos, arrastrando las nubes.\n"
 	 "El sol vuelve a calentar.\n"}),
 /* Fr�o */
	({"El cielo comienza a nublarse lentamente.\n",
	 "La temperatura desciende sensiblemente.\n",
	 "Comienza a hacer fr�o. El cielo est� totalmente nublado.\n",
	 "Hace mucho fr�o y una brisa helada sopla en rachas continuas.\n",
	 "La brisa se convierte en un viento g�lido que sopla en fuertes rachas que el sol "
	 "oculto no acierta a atemperar.\n",
	 "La humedad del cielo neblinoso junto con el viento helado crean un ambiente de "
	 "intenso fr�o.\n",
	 "E viento parece calmarse y sus rachas disminuyen de intensidad.\n",
	 "El viento comienza a aumentar de intensidad otra vez mientras el encapotado cielo "
	 "se oscurece a�n m�s.\n",
	 "Cada vez hace m�s fr�o.\n",
	 "El viento va calm�ndose poco a poco y el fr�o parece disminuir.\n",
	 "El viento fr�o cesa por completo y la temperatura asciende algo m�s.\n"
	 "Algunos rayos de sol escapan t�midamente entre los c�mulos nubosos.\n",
	 "Las nubes se acumulan en el cielo. Parece que amenaza lluvia.\n"}),
 /* Lluvia */
	 ({"El viento arrastra nubes cargadas de lluvia que se van acumulando poco a poco.\n",
	 "El cielo est� totalmente encapotado y el aire huele a lluvia.\n",
	 "Del plomizo cielo caen algunas gotas.\n",
	 "Las gruesas gotas de lluvia tamborilean ap�ticamente sobre el suelo y un viento se "
	 "levanta, agitando y acumulando a�n m�s nubes.\n",
	 "El encapotado cielo comienza a dejar caer una lluvia regular.\n",
	 "La lluvia se intensifica y el viento h�medo la arrastra horizontalmente sobre el "
	 "paisaje\n",
	 "El cielo est� totalmente cubierto y la lluvia sigue cayendo.\n",
	 "La lluvia se convierte en torrencial. Espesas cortinas de agua son arrastradas por el "
	 "acuoso viento.\n",
	 "La intensa lluvia empieza a amainar.\n",
	 "La lluvia  se va convirtiendo en unas pocas gruesas gotas que caen perezosamente.\n",
	 "Solo caen unas pocas gotas y unos t�midos rayos de sol surgen entre las nubes.\n",
	 "La lluvia cesa por completo y las nubes se disipan poco a poco.\n"
	 "El sol brilla espl�ndidamente.\n"}), 
 /* Viento */
	 ({"Algunas nubes navegan lentamente en el cielo.\n",
	 "Se levanta un viento que va ganando en intensidad.\n",
	 "Fuertes rachas de viento baten el terreno mientras el astro rey brilla con fuerza.\n",
	 "El fuerte viento agita y empuja algunas nubes dispersas por el cielo a gran velocidad.\n",
	 "Las fuertes rachas de viento te zarandean y empujan.\n",
	 "El viento aumenta de intensidad convirti�ndose en un poderoso ventarr�n.\n",
	 "Te encorvas ante la enorme fuerza del viento.\n",
	 "Las poderosas rachas ventosas se solapan e intensifican de continuo.\n",
	 "El viento aulla y gime y las nubes ejecutan una alocada danza en el cielo.\n",
	 "Las poderosas r�fagas de viento parecen comenzar a disminuir de intensidad.\n",
	 "El vendaval amaina hasta convertirse en un apacible viento con solo algunas "
	 "r�fagas m�s intensas.\n",
	 "El viento cesa por completo y las nubes hierran lentamente por el soleado cielo.\n"}),
 /* Tormenta */
	 ({"El viento arrastra unas nubes negras que van oscureciendo el cielo diurno.\n",
	 "El cielo est� totalmente encapotado.\n",
	 "El ominoso rumor de un trueno lejano reververa en la distancia.\n",
	 "Los rel�mpagos iluminan el cielo en lontananza.\n",
	 "Empiezan a caer unas gruesas gotas.\n",
	 "Comienza a llover de forma torrencial.\n",
	 "La lluvia torrencial cae sin tregua mientras los rel�mpagos rasgan los oscuros "
	 "nubarrones y los truenos estallan sin tregua.\n",
	 "Pesadas cortinas de lluvia recorren el terreno.\n"
	 "Un poderoso rel�mpago rasga el cielo seguido de un ensordecedor estampido.\n",
	 "Los rel�mpagos empiezan a ser menos numerosos y el rumor de los truenos retumba "
	 "cada vez m�s lejano.\n",
	 "La lluvia comienza a caer con menos fuerza mientras la tormenta parece amainar.\n"
	 "El sordo gru�ido de los truenos es apenas audible en la lejan�a.\n",
	 "El chaparr�n disminuye hasta convertirse enuna suave llovizna.\n"
	 " Las nubes empiezan a dispersarse y sale el sol.\n",
	 "La lluvia ha cesado por completo y las �ltimas nubes se alejan.\n"
	 "El sol reluce con fuerza enlo alto.\n"}),
 /* Niebla */
	 ({"El cielo est� claro. Sopla un viento fresco.\n",
	 "Unos c�mulos nubosos son arrastrados por el viento y el sol aparece y desaparece "
	 "a cada momento.\n",
	 "El cielo se ha oscurecido y hilachas neblinosas se arrastran por el terreno.\n"
	 "El viento es cada vez m�s fr�o y h�medo.\n",
	 "La ligera niebla comienza a espesarse y cerrarse a tu alrededor.\n"
	 "El sol ha desaparecido completamente y hace fr�o.\n",
	 "El viento deja de soplar poco a poco y la niebla se cierra totalmente.\n"
	 "La visibilidad es muy reducida y todos los sonidos se amortiguan.\n",
	 "Un espeso dosel de niebla lo cubre todo.\n",
	 "Una s�bita r�faga de brisa agita la niebla por unos momentos.\n",
	 "La espesa niebla te impide ver m�s all� de tu brazo extendido.\n"
	 "El fr�o h�medo te cala hasta los huesos.\n",
	 "La niebla se agita y se arrastra con perezosa lentitud.\n",
	 "Se levanta viento y la niebla comienza a rasgarse y abrirse.\n",
	 "Solo queda un ligero velo de bruma.\n",
	 "Las �ltimas hilachas de bruma son dispersados por el viento y el cielo se despeja.\n"}),
 /* Nieve */
	 ({"El cielo est� claro pero hace fr�o.\n",
	 "Algunas algodonosas nubes surcan lentamente el cielo diurno.\n",
	 "Se est� nublando y el fr�o seco es m�s intenso.\n",
	 "Las nubes se espesan y el encapotado cielo amenaza nieve.\n",
	 "Algunos grandes copos de nieve caen perezosamente.\n",
	 "Los copos de nieve se hacen m�s peque�os pero m�s abundantes. Rompe a nevar.\n",
	 "La nieve cae copiosamente cubri�ndolo todo de un manto blanco.\n",
	 "Est� nevando con fuerza y lanevisca reduce mucho la visibilidad.\n",
	 "Nieva copiosamente y el cielo sigue cubierto.\n",
	 "La nevada comienza a remitir poco a poco.\n",
	 "Los copos van cayendo cada vez con menos abundancia y el aire se va aclarando.\n",
	 "Los �ltimos copos caen perezosamente. Deja de nevar.\n"})});






string *MSG_DEFAULT_NOCHE=({
 /* Normal */
 	 ({"La noche est� clara y el cielo nocturno aparece tachonado por millares de estrellas.\n",
	 "La temperatura es agradable y la b�veda celeste reluce cuajada de estrellas.\n",
	 "Unas cuantas nubes empiezan a tapar las estrellas.\n",
	 "Se levanta una suave brisa que empuja algunas nubecillas que navegan lentamente "
	 "por el cielo estrellado.\n",
	 "Una leve brisa nocturna acaricia tu rostro.\n",
	 "Las estrellas lucen claras y hermosas en el cielo nocturno.\n",
	 "La Luna recorre lentamente el cielo nocturno entre una pl�yade de estrellas.\n",
	 "Se levanta una suave brisa.\n"
	 "algunas nubes recorren el cielo estrellado.\n",
	 "La brisa nocturna deja de soplar poco a poco pero la temperatura sigue siendo "
	 "agradable.\n",
	 "Los rayos de la Luna y el brillo de las constelaciones iluminan suavemente el cielo.\n",
	 "El cielo estrellado contin�a despejado, haciendo de esta una magn�fica noche.\n",
	 "La Luna reluce en lo alto como una joya blanca , reinando en el cielo nocturno "
	 "rodeada por una corte de hermosas estrellas.\n"}),
 /* Calor */
 	 ({"La noche est� despejada. No hace calor ni hace viento.\n",
	 "Ni una brizna de brisa refresca el aire nocturno. Hace calor.\n",
	 "Algunas grandes nubes tapan la Luna y las estrellas. Hace un calor bochornoso.\n",
	 "Las estrellas vuelven a salir cuando las nubes se alejan. El bochorno nocturno es "
	 "intenso y h�medo.\n",            
	 "Un viento h�medo y c�lido agita tus cabellos.\n"
	 "El h�medo bochorno nocturno es agobiante.\n",     
	 "Hace un calor agobiante en esta clara noche.\n",			         
	 "Ves las estrellas en lo alto del cielo.\n",                          
	 "Aparecen unas peque�as nubes que tapan las estrellas.\n",         
	 "La noche empieza a ser un poco m�s fresca.\n",              
	 "Hace mucho calor, pero una leve brisa fresca comienza a soplar t�midamente.\n",
	 "La brisa aumenta de intensidad y la noche va refrescando poco a poco.\n",  
	 "Altos vientos nocturnos arrastran las nubes y las estrellas vuelven a relucir "
	 "en el cielo.\n"}),  
 /* Fr�o */
	 ({"Las nubes empiezan a ser agitadas por un viento fr�o.\n",
	 "Las estrellas asoman entre las nubes, contempl�ndote con impavidez mientras el "
	 "ambiente va enfri�ndose.\n",
	 "La noche se ha vuelto g�lida.\n",
	 "Las fr�as estrellas relucen en un p�lio oscuro. El fr�o es intenso. La noche va a ser dura.\n",
	 "Unas s�bitas rachas de viento helado recorren los alrededores.\n",
	 "Cada vez sopla el viento con m�s intensidad.\n",
	 "Tu aliento se condensa en el fr�o aire nocturno.\n",
	 "La temperatura ha bajado much�simo.\n",
	 "El viento deja de soplar pero la temperatura sigue siendo extremadamente fr�a.\n",
	 "Los fr�os rayos de Luna se conjugan con el brillo estelar para iluminar esta "
	 "noche helada.\n",
	 "Parece que la temperatura asciende poco a poco.\n",
	 "Las constelaciones giranlentamente enlo alto y el fr�o va remitiendo poco a poco.\n"}),
 /* Lluvia */
	 ({"La noche est� clara y un manto de estrellas cubre la b�veda celeste.\n"
	 	"Sopla una ligera brisa.\n",  
	 "El viento es cada vez mas fuerte y las nubes  tapan las estrellas.\n", 
	 "La noche se vuelve muy oscura cuando el cielo queda totalmente encapotado.\n",
	 "El aire huele a humedad. Se avecina lluvia.\n", 
	 "Empiezan a caer algunas gotas.\n",
	 "Empieza a llover.\n",
	 "La lluvia se convierte en un chaparr�n torrencial y el cielo permanece cubierto.\n",
	 "El intenso aguacero azota los alrededores sin tregua.\n"
	 "No se distinguen la Luna ni las estrellas.\n",
	 "El chaparr�n va remitiendo poco a poco mientras las nubes se van disgregando.\n",
	 "LCae una suave lluvia que va disminuyendo de intensidad.\n"
	  "Un viento continuo limpia el cielo de nubes y salen de nuevo las estrellas.\n",
	 "Solo caen unas pocas gotas dispersas y el cielo est� casi totalmente despejado.\n",
	 "La lluvia cesa por completo y la Luna y las estrellas se ense�orean del l�mpido "
	 "cielo nocturno.\n"}), 
 /* Viento */
	 ({"Alguna nube flota en el cielo nocturno.\n",
	 "Se levanta un viento que va ganando en fuerza e intensidad.\n",
	 "Fuertes r�fagas ventosas baten los alrededores.\n",
	 "El viento arrecia de continuo.\n"
	 "Algunas nubes cruzan en alocada carrera frente a las estrellas.\n",
	 "Empiezas a ser zarandeado por el viento.\n",
	 "El feroz ventarr�n sopla sin tregua sofocando todo sonido con sus poderosas r�fagas.\n",
	 "Te encorvas ante la enorme fuerza del viento.\n",
	 "El vendaval parece amainar por unos momentos y luego se reanuda con gran fuerza.\n",
	 "Las nubes siguen siendo zarandeadas en el cielo, dejando alg�n hueco por\n\
el que ver las estrellas.\n",
	 "El viento huracanado disminuye su intensidad y su aullido parece aplacarse.\n",
	 "El viento deja de soplar con tanta fuerza.\n",
	 "Las nubes parecen haberse detenido en el cielo y la noche vuelve a estar\n\
en calma. El viento se ha detenido por completo.\n"}),
 /* Tormenta */
	 ({"Negros nubarrones oscurecen el horizonte estrellado.\n",
	 "Poco a poco las nubes se van tragando las estrellas y la noche se oscurece.\n", 
	 "Un rel�mpago ilumina la noche y el subsiguiente trueno retumba poderosamente en las alturas.\n",
	 "Unas gruesas gotas comienzan a caer tamborileando sobre el suelo.\n", 
	 "Los rel�mpagos rasgan las nubes y los truenos estallan uno tras otro.\n"
	 "Se desata una lluvia torrencial.\n",
	 "Rayos y truenos parecen convertir en d�a la noche mientras la lluvia\n\
sigue cayendo.\n",
	 "Un estallido de luz blanquecina desgarra la noche cuando un rayo se descarga sobre "
	 "el suelo cerca de ti.\n"
	 "Un potent�simo estampido hace que te tambalees.\n",
	 "La lluvia torrencial azota sin tregua los alrededores  mientras los rayos siguen "
	 "iluminando la noche.\n",
	 "El lapso entre rel�mpagos y truenos se va alargando mientras la lluvia parece "
	 "perder fuerza.\n",
	 "La tormenta comienza a alejarse y los truenos se convierten en un mero rumor "
	 "amenazante. La lluvia va amainando\n",
	 "Tan solo caenunas pocas gotas dispersas.\n"
	 "Las nubes se abren poco a poco y dejan ver las estrellas en el l�mpido cielo nocturno.\n",
	 "La lluvia cesa por completo y el cielo se despeja por completo. Sale la Luna.\n"}),
 /* Niebla */
	 ({"La negra b�veda celestre est� iluminada por un manto de hermosas estrellas. Sopla un viento fresco.\n",
	 "El viento fr�o sopla con mayor intensidad, arrastrando pesados c�mulos nubosos que "
	 "van empa�ando las estrellas.\n",
	 "Torres de lobreguez son arrastradas por el viento h�medo de un lado a otro.\n"
	 "La noche se oscurece.\n",
	 "La niebla se espesa a tu alrededor y cae sobre los alrededores cual pesado "
	 "manto h�medo.\n",
	 "La humedad se condensa sobre tus ropas y tu rostro en pesadas gotas.\n"
	 "La niebla "
	 "impenetrable hace esta noche negra como boca de lobo.\n",
	 "No ves absolutamente nada.\n"
	 "Los sonidos nocturnos son amortiguados por el ambiente neblinoso.\n",
	 "Un viento fr�o, cargado de humedad hace agitarse la niebla.\n"
	 "Por breves momentos alguna estrella refulge d�bilmente en lo alto.\n",              
	 "La niebla se arrastra perezosamente por el suelo y sus muros impenetrables se "
	 "cierran sobre ti.\n",
 	 "Tu orientaci�n ha desaparecido.\n"
 	 "Te encuentras totalmente perdido entre la espesa niebla nocturna.\n",                                
	 "Se levanta un fuerte viento que rasga la niebla en pesados bancos que se arrastran "
	 "lentamente sobre el terreno.\n",
	 "Los bancos de niebla son agitados por el viento que los desgarra sin piedad "
	 "convirti�ndolos en simples hilachas de bruma.\n"
	 "Salen las estrellas\n",
	 "El viento arrastra los �ltimos girones de niebla que acaban disolvi�ndose.\n"
	 "El cielo estrellado est� ahora totalmente limpio y despejado.\n"
	 "Ha empezado a soplar un viento fresco.\n"}),
 /* Nieve */
	 ({"El cielo est� claro pero hace fr�o.\n",
	 "Hay unas pocas nubes algodonosas en el cielo estrellado.\n",
	 "Las pesadas nubes parecen acumularse y espesarse.\n",	            	
	 "El cielo est� encapotado y no se ve una sola estrella El fr�o es intenso, va a nevar.\n",
	 "Caen los primeros copos de nieve.\n",    
	 "Empieza a nevar con suavidad.\n",         
	 "La nieve empieza a caer copiosamente.\n"
	 "Se levanta un viento fr�o y seco que arrastra copos de nieve.\n",                             
	 "Nieva con gran intensidad y el aire se espesa con los copos de nieve.\n"
	 "La visibilidad se ha reducido mucho.\n",
	 "El viento helado arrastra y amontona la nieve en espesas cortinas blanquecinas.\n",
	 "Las nubes empiezana  disgregarse poco a poco yla nieve cae con menos fuerza.\n", 
	 "Unos pocos copos dispersos caen perezosamente mientras las nubes se "
	 "alejan empujadas por el viento.\n",
	 "La nevada cesa por completo.\n"
	 "El cielo se despeja por completo y las fr�as estrellas relucenen lo alto.\n"})});


string *MSG_DEFAULT_GROUND=({
   /* Normal */
   	  ({"El suelo est� seco.\n",
   	   "La brisa acaricia el suelo.\n",
   	   "La brisa crea peque�os remolinos en el suelo.\n",
  	   "La brisa crea peque�os remolinos en el suelo.\n",
   	   "La brisa acaricia el suelo.\n",
 	   "El suelo est� seco.\n"}),
   /* Calor */
	   ({"El suelo est� seco.\n",
	   "Ves un suelo caliente y seco.\n",
	   "El terreno est� seco y polvoriento.\n",
	   "Desde el suelo sube un calor agobiante.\n",
	   "El terreno esta seco y resquebrajado.\n",
	   "El suelo esta caliente y reseco.\n"}),
   /* Lluvia */
   	  ({"El suelo est� fr�o y seco.\n",
   	   "Vaharadas de vapor ascienden del suelo.\n",
   	   "Ves algo de escarcha por el suelo.\n",
   	   "Ves trozos de escarcha helada en el suelo.\n",
  	   "El suelo est� helado.\n",
 	   "El suelo est� fr�o.\n"}),
   /* Lluvia */
	   ({"El suelo est� h�medo.\n",
	   "Ves restos de humedad en el suelo.\n",
	   "El suelo est� mojado.\n",
	   "Empiezan a formarse charcos.\n",
	   "El suelo est� anegado.\n",
	   "El suelo empieza a secarse.\n"}),
   /* Viento */
   	   ({"El suelo est� seco.\n",
   	   "El viento empieza a azotar el suelo.\n",
   	   "A tus pies ves remolinos formados por el viento.\n",
   	   "El viento castiga el suelo.\n",
   	   "Los remolinos formados por el viento disminuyen en tama�o e intensidad.\n",
   	   "El suelo est� seco.\n"}),
   /* Tormenta */
	   ({"El suelo se est� humedeciando.\n",
	   "El suelo est� mojado.\n",
	   "Se empiezan a formar charcos mientras cae alg�n rayo al suelo.\n",
	   "Los charcos est�n creciendo de manera alarmante.\n",
	   "El suelo est� inundado.\n",
	   "El suelo est� mojado.\n"}),
   /* Niebla */
	   ({"El suelo est� h�medo.\n",
	   "Jirones de niebla empiezan a cubrirlo.\n",
	   "Una espesa niebla te impide verlo.\n",
	   "Una niebla impenetrable planea sobre el suelo.\n",
	   "A�n queda algo de niebla a tus pies.\n",
	   "Los �ltimos restos de niebla desaparecen.\n"}),
   /* Nieve */
   	   ({"El suelo est� h�medo.\n",
  	   "El suelo est� algo h�medo.\n",
	   "Sobre el suelo se est� formando una fina capa de nieve.\n",
	   "El suelo est� cubierto de nieve.\n",
	   "La nieve lo cubre todo.\n",
	   "La gruesa capa de nieve empieza a derretirse.\n"})});

#endif /* __CHRONOS_H */