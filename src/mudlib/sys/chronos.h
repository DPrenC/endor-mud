#ifndef __CHRONOS_H
#define __CHRONOS_H
string *MSG_DEFAULT_DIA = ({
 /* Normal */
	 ({"El cielo está azul y totalmente despejado y Un sol espléndido brilla en el cielo.\n",
	 "Una leve brisa sopla en casi imperceptibles ráfagas.\n",
	 "Unas cuantas nubecillas blancas recorren lentamente el cielo iluminado por el "
	 "astro diurno.\n",
	 "Un leve soplo de brisa acaricia tu rostro junto con los suaves rayos del sol.\n",
	 "Un apacible vientecillo hace tremolear tus ropas.\n",
	 "Sopla una ligera brisa.\n",
	 "Un cúmulo de nubes tapa el sol momentáneamente.\n",
	 "Se levanta un viento fresco.\n",
	 "Poco a poco, el viento deja de soplar.\n",
	 "Algunas nubes recorren el cielo.\n",
	 "El cielo aparece azul y sereno.\n",
	 "Un leve vientecillo recorre el paisaje.\n"}),
 /* Calor */
  	 ({"El cielo está despejado y el sol calienta agradablemente.\n",
	 "El sol brilla en lo alto con fuerza y cada vez hace más calor.\n",
	 "Hace mucho calor y no se percibe ni un solo soplo de brisa.\n",
  	 "Bajo el intenso calor el paisaje parece rielar.\n",
  	 "Los ardientes rayos del sol caen sobre ti sin piedad.\n",
  	 "Hace un calor agobiante.\n",
	 "El intenso calor no se ve alterado por la más mínima brisa.\n",
  	 "Se levanta una brisa cálida. Algunas nubecillas blancas navegan lentamente por el cielo.\n",
  	 "La brisa se vuelve algo más fresca y la temperatura desciende un poco.\n",
	 "El calor va remitiendo mientras las rachas de viento se intensifican y refrescan el lugar.\n",
 	 "La brisa empuja un cúmulo de nubes que ocultan por unos instantes el sol, dando tregua ante sus intensos rayos.\n",
 	 "El viento sopla con mayor intensidad por unos momentos, arrastrando las nubes.\n"
 	 "El sol vuelve a calentar.\n"}),
 /* Frío */
	({"El cielo comienza a nublarse lentamente.\n",
	 "La temperatura desciende sensiblemente.\n",
	 "Comienza a hacer frío. El cielo está totalmente nublado.\n",
	 "Hace mucho frío y una brisa helada sopla en rachas continuas.\n",
	 "La brisa se convierte en un viento gélido que sopla en fuertes rachas que el sol "
	 "oculto no acierta a atemperar.\n",
	 "La humedad del cielo neblinoso junto con el viento helado crean un ambiente de "
	 "intenso frío.\n",
	 "E viento parece calmarse y sus rachas disminuyen de intensidad.\n",
	 "El viento comienza a aumentar de intensidad otra vez mientras el encapotado cielo "
	 "se oscurece aún más.\n",
	 "Cada vez hace más frío.\n",
	 "El viento va calmándose poco a poco y el frío parece disminuir.\n",
	 "El viento frío cesa por completo y la temperatura asciende algo más.\n"
	 "Algunos rayos de sol escapan tímidamente entre los cúmulos nubosos.\n",
	 "Las nubes se acumulan en el cielo. Parece que amenaza lluvia.\n"}),
 /* Lluvia */
	 ({"El viento arrastra nubes cargadas de lluvia que se van acumulando poco a poco.\n",
	 "El cielo está totalmente encapotado y el aire huele a lluvia.\n",
	 "Del plomizo cielo caen algunas gotas.\n",
	 "Las gruesas gotas de lluvia tamborilean apáticamente sobre el suelo y un viento se "
	 "levanta, agitando y acumulando aún más nubes.\n",
	 "El encapotado cielo comienza a dejar caer una lluvia regular.\n",
	 "La lluvia se intensifica y el viento húmedo la arrastra horizontalmente sobre el "
	 "paisaje\n",
	 "El cielo está totalmente cubierto y la lluvia sigue cayendo.\n",
	 "La lluvia se convierte en torrencial. Espesas cortinas de agua son arrastradas por el "
	 "acuoso viento.\n",
	 "La intensa lluvia empieza a amainar.\n",
	 "La lluvia  se va convirtiendo en unas pocas gruesas gotas que caen perezosamente.\n",
	 "Solo caen unas pocas gotas y unos tímidos rayos de sol surgen entre las nubes.\n",
	 "La lluvia cesa por completo y las nubes se disipan poco a poco.\n"
	 "El sol brilla espléndidamente.\n"}), 
 /* Viento */
	 ({"Algunas nubes navegan lentamente en el cielo.\n",
	 "Se levanta un viento que va ganando en intensidad.\n",
	 "Fuertes rachas de viento baten el terreno mientras el astro rey brilla con fuerza.\n",
	 "El fuerte viento agita y empuja algunas nubes dispersas por el cielo a gran velocidad.\n",
	 "Las fuertes rachas de viento te zarandean y empujan.\n",
	 "El viento aumenta de intensidad convirtiéndose en un poderoso ventarrón.\n",
	 "Te encorvas ante la enorme fuerza del viento.\n",
	 "Las poderosas rachas ventosas se solapan e intensifican de continuo.\n",
	 "El viento aulla y gime y las nubes ejecutan una alocada danza en el cielo.\n",
	 "Las poderosas ráfagas de viento parecen comenzar a disminuir de intensidad.\n",
	 "El vendaval amaina hasta convertirse en un apacible viento con solo algunas "
	 "ráfagas más intensas.\n",
	 "El viento cesa por completo y las nubes hierran lentamente por el soleado cielo.\n"}),
 /* Tormenta */
	 ({"El viento arrastra unas nubes negras que van oscureciendo el cielo diurno.\n",
	 "El cielo está totalmente encapotado.\n",
	 "El ominoso rumor de un trueno lejano reververa en la distancia.\n",
	 "Los relámpagos iluminan el cielo en lontananza.\n",
	 "Empiezan a caer unas gruesas gotas.\n",
	 "Comienza a llover de forma torrencial.\n",
	 "La lluvia torrencial cae sin tregua mientras los relámpagos rasgan los oscuros "
	 "nubarrones y los truenos estallan sin tregua.\n",
	 "Pesadas cortinas de lluvia recorren el terreno.\n"
	 "Un poderoso relámpago rasga el cielo seguido de un ensordecedor estampido.\n",
	 "Los relámpagos empiezan a ser menos numerosos y el rumor de los truenos retumba "
	 "cada vez más lejano.\n",
	 "La lluvia comienza a caer con menos fuerza mientras la tormenta parece amainar.\n"
	 "El sordo gruñido de los truenos es apenas audible en la lejanía.\n",
	 "El chaparrón disminuye hasta convertirse enuna suave llovizna.\n"
	 " Las nubes empiezan a dispersarse y sale el sol.\n",
	 "La lluvia ha cesado por completo y las últimas nubes se alejan.\n"
	 "El sol reluce con fuerza enlo alto.\n"}),
 /* Niebla */
	 ({"El cielo está claro. Sopla un viento fresco.\n",
	 "Unos cúmulos nubosos son arrastrados por el viento y el sol aparece y desaparece "
	 "a cada momento.\n",
	 "El cielo se ha oscurecido y hilachas neblinosas se arrastran por el terreno.\n"
	 "El viento es cada vez más frío y húmedo.\n",
	 "La ligera niebla comienza a espesarse y cerrarse a tu alrededor.\n"
	 "El sol ha desaparecido completamente y hace frío.\n",
	 "El viento deja de soplar poco a poco y la niebla se cierra totalmente.\n"
	 "La visibilidad es muy reducida y todos los sonidos se amortiguan.\n",
	 "Un espeso dosel de niebla lo cubre todo.\n",
	 "Una súbita ráfaga de brisa agita la niebla por unos momentos.\n",
	 "La espesa niebla te impide ver más allá de tu brazo extendido.\n"
	 "El frío húmedo te cala hasta los huesos.\n",
	 "La niebla se agita y se arrastra con perezosa lentitud.\n",
	 "Se levanta viento y la niebla comienza a rasgarse y abrirse.\n",
	 "Solo queda un ligero velo de bruma.\n",
	 "Las últimas hilachas de bruma son dispersados por el viento y el cielo se despeja.\n"}),
 /* Nieve */
	 ({"El cielo está claro pero hace frío.\n",
	 "Algunas algodonosas nubes surcan lentamente el cielo diurno.\n",
	 "Se está nublando y el frío seco es más intenso.\n",
	 "Las nubes se espesan y el encapotado cielo amenaza nieve.\n",
	 "Algunos grandes copos de nieve caen perezosamente.\n",
	 "Los copos de nieve se hacen más pequeños pero más abundantes. Rompe a nevar.\n",
	 "La nieve cae copiosamente cubriéndolo todo de un manto blanco.\n",
	 "Está nevando con fuerza y lanevisca reduce mucho la visibilidad.\n",
	 "Nieva copiosamente y el cielo sigue cubierto.\n",
	 "La nevada comienza a remitir poco a poco.\n",
	 "Los copos van cayendo cada vez con menos abundancia y el aire se va aclarando.\n",
	 "Los últimos copos caen perezosamente. Deja de nevar.\n"})});






string *MSG_DEFAULT_NOCHE=({
 /* Normal */
 	 ({"La noche está clara y el cielo nocturno aparece tachonado por millares de estrellas.\n",
	 "La temperatura es agradable y la bóveda celeste reluce cuajada de estrellas.\n",
	 "Unas cuantas nubes empiezan a tapar las estrellas.\n",
	 "Se levanta una suave brisa que empuja algunas nubecillas que navegan lentamente "
	 "por el cielo estrellado.\n",
	 "Una leve brisa nocturna acaricia tu rostro.\n",
	 "Las estrellas lucen claras y hermosas en el cielo nocturno.\n",
	 "La Luna recorre lentamente el cielo nocturno entre una pléyade de estrellas.\n",
	 "Se levanta una suave brisa.\n"
	 "algunas nubes recorren el cielo estrellado.\n",
	 "La brisa nocturna deja de soplar poco a poco pero la temperatura sigue siendo "
	 "agradable.\n",
	 "Los rayos de la Luna y el brillo de las constelaciones iluminan suavemente el cielo.\n",
	 "El cielo estrellado continúa despejado, haciendo de esta una magnífica noche.\n",
	 "La Luna reluce en lo alto como una joya blanca , reinando en el cielo nocturno "
	 "rodeada por una corte de hermosas estrellas.\n"}),
 /* Calor */
 	 ({"La noche está despejada. No hace calor ni hace viento.\n",
	 "Ni una brizna de brisa refresca el aire nocturno. Hace calor.\n",
	 "Algunas grandes nubes tapan la Luna y las estrellas. Hace un calor bochornoso.\n",
	 "Las estrellas vuelven a salir cuando las nubes se alejan. El bochorno nocturno es "
	 "intenso y húmedo.\n",            
	 "Un viento húmedo y cálido agita tus cabellos.\n"
	 "El húmedo bochorno nocturno es agobiante.\n",     
	 "Hace un calor agobiante en esta clara noche.\n",			         
	 "Ves las estrellas en lo alto del cielo.\n",                          
	 "Aparecen unas pequeñas nubes que tapan las estrellas.\n",         
	 "La noche empieza a ser un poco más fresca.\n",              
	 "Hace mucho calor, pero una leve brisa fresca comienza a soplar tímidamente.\n",
	 "La brisa aumenta de intensidad y la noche va refrescando poco a poco.\n",  
	 "Altos vientos nocturnos arrastran las nubes y las estrellas vuelven a relucir "
	 "en el cielo.\n"}),  
 /* Frío */
	 ({"Las nubes empiezan a ser agitadas por un viento frío.\n",
	 "Las estrellas asoman entre las nubes, contemplándote con impavidez mientras el "
	 "ambiente va enfriándose.\n",
	 "La noche se ha vuelto gélida.\n",
	 "Las frías estrellas relucen en un pálio oscuro. El frío es intenso. La noche va a ser dura.\n",
	 "Unas súbitas rachas de viento helado recorren los alrededores.\n",
	 "Cada vez sopla el viento con más intensidad.\n",
	 "Tu aliento se condensa en el frío aire nocturno.\n",
	 "La temperatura ha bajado muchísimo.\n",
	 "El viento deja de soplar pero la temperatura sigue siendo extremadamente fría.\n",
	 "Los fríos rayos de Luna se conjugan con el brillo estelar para iluminar esta "
	 "noche helada.\n",
	 "Parece que la temperatura asciende poco a poco.\n",
	 "Las constelaciones giranlentamente enlo alto y el frío va remitiendo poco a poco.\n"}),
 /* Lluvia */
	 ({"La noche está clara y un manto de estrellas cubre la bóveda celeste.\n"
	 	"Sopla una ligera brisa.\n",  
	 "El viento es cada vez mas fuerte y las nubes  tapan las estrellas.\n", 
	 "La noche se vuelve muy oscura cuando el cielo queda totalmente encapotado.\n",
	 "El aire huele a humedad. Se avecina lluvia.\n", 
	 "Empiezan a caer algunas gotas.\n",
	 "Empieza a llover.\n",
	 "La lluvia se convierte en un chaparrón torrencial y el cielo permanece cubierto.\n",
	 "El intenso aguacero azota los alrededores sin tregua.\n"
	 "No se distinguen la Luna ni las estrellas.\n",
	 "El chaparrón va remitiendo poco a poco mientras las nubes se van disgregando.\n",
	 "LCae una suave lluvia que va disminuyendo de intensidad.\n"
	  "Un viento continuo limpia el cielo de nubes y salen de nuevo las estrellas.\n",
	 "Solo caen unas pocas gotas dispersas y el cielo está casi totalmente despejado.\n",
	 "La lluvia cesa por completo y la Luna y las estrellas se enseñorean del límpido "
	 "cielo nocturno.\n"}), 
 /* Viento */
	 ({"Alguna nube flota en el cielo nocturno.\n",
	 "Se levanta un viento que va ganando en fuerza e intensidad.\n",
	 "Fuertes ráfagas ventosas baten los alrededores.\n",
	 "El viento arrecia de continuo.\n"
	 "Algunas nubes cruzan en alocada carrera frente a las estrellas.\n",
	 "Empiezas a ser zarandeado por el viento.\n",
	 "El feroz ventarrón sopla sin tregua sofocando todo sonido con sus poderosas ráfagas.\n",
	 "Te encorvas ante la enorme fuerza del viento.\n",
	 "El vendaval parece amainar por unos momentos y luego se reanuda con gran fuerza.\n",
	 "Las nubes siguen siendo zarandeadas en el cielo, dejando algún hueco por\n\
el que ver las estrellas.\n",
	 "El viento huracanado disminuye su intensidad y su aullido parece aplacarse.\n",
	 "El viento deja de soplar con tanta fuerza.\n",
	 "Las nubes parecen haberse detenido en el cielo y la noche vuelve a estar\n\
en calma. El viento se ha detenido por completo.\n"}),
 /* Tormenta */
	 ({"Negros nubarrones oscurecen el horizonte estrellado.\n",
	 "Poco a poco las nubes se van tragando las estrellas y la noche se oscurece.\n", 
	 "Un relámpago ilumina la noche y el subsiguiente trueno retumba poderosamente en las alturas.\n",
	 "Unas gruesas gotas comienzan a caer tamborileando sobre el suelo.\n", 
	 "Los relámpagos rasgan las nubes y los truenos estallan uno tras otro.\n"
	 "Se desata una lluvia torrencial.\n",
	 "Rayos y truenos parecen convertir en día la noche mientras la lluvia\n\
sigue cayendo.\n",
	 "Un estallido de luz blanquecina desgarra la noche cuando un rayo se descarga sobre "
	 "el suelo cerca de ti.\n"
	 "Un potentísimo estampido hace que te tambalees.\n",
	 "La lluvia torrencial azota sin tregua los alrededores  mientras los rayos siguen "
	 "iluminando la noche.\n",
	 "El lapso entre relámpagos y truenos se va alargando mientras la lluvia parece "
	 "perder fuerza.\n",
	 "La tormenta comienza a alejarse y los truenos se convierten en un mero rumor "
	 "amenazante. La lluvia va amainando\n",
	 "Tan solo caenunas pocas gotas dispersas.\n"
	 "Las nubes se abren poco a poco y dejan ver las estrellas en el límpido cielo nocturno.\n",
	 "La lluvia cesa por completo y el cielo se despeja por completo. Sale la Luna.\n"}),
 /* Niebla */
	 ({"La negra bóveda celestre está iluminada por un manto de hermosas estrellas. Sopla un viento fresco.\n",
	 "El viento frío sopla con mayor intensidad, arrastrando pesados cúmulos nubosos que "
	 "van empañando las estrellas.\n",
	 "Torres de lobreguez son arrastradas por el viento húmedo de un lado a otro.\n"
	 "La noche se oscurece.\n",
	 "La niebla se espesa a tu alrededor y cae sobre los alrededores cual pesado "
	 "manto húmedo.\n",
	 "La humedad se condensa sobre tus ropas y tu rostro en pesadas gotas.\n"
	 "La niebla "
	 "impenetrable hace esta noche negra como boca de lobo.\n",
	 "No ves absolutamente nada.\n"
	 "Los sonidos nocturnos son amortiguados por el ambiente neblinoso.\n",
	 "Un viento frío, cargado de humedad hace agitarse la niebla.\n"
	 "Por breves momentos alguna estrella refulge débilmente en lo alto.\n",              
	 "La niebla se arrastra perezosamente por el suelo y sus muros impenetrables se "
	 "cierran sobre ti.\n",
 	 "Tu orientación ha desaparecido.\n"
 	 "Te encuentras totalmente perdido entre la espesa niebla nocturna.\n",                                
	 "Se levanta un fuerte viento que rasga la niebla en pesados bancos que se arrastran "
	 "lentamente sobre el terreno.\n",
	 "Los bancos de niebla son agitados por el viento que los desgarra sin piedad "
	 "convirtiéndolos en simples hilachas de bruma.\n"
	 "Salen las estrellas\n",
	 "El viento arrastra los últimos girones de niebla que acaban disolviéndose.\n"
	 "El cielo estrellado está ahora totalmente limpio y despejado.\n"
	 "Ha empezado a soplar un viento fresco.\n"}),
 /* Nieve */
	 ({"El cielo está claro pero hace frío.\n",
	 "Hay unas pocas nubes algodonosas en el cielo estrellado.\n",
	 "Las pesadas nubes parecen acumularse y espesarse.\n",	            	
	 "El cielo está encapotado y no se ve una sola estrella El frío es intenso, va a nevar.\n",
	 "Caen los primeros copos de nieve.\n",    
	 "Empieza a nevar con suavidad.\n",         
	 "La nieve empieza a caer copiosamente.\n"
	 "Se levanta un viento frío y seco que arrastra copos de nieve.\n",                             
	 "Nieva con gran intensidad y el aire se espesa con los copos de nieve.\n"
	 "La visibilidad se ha reducido mucho.\n",
	 "El viento helado arrastra y amontona la nieve en espesas cortinas blanquecinas.\n",
	 "Las nubes empiezana  disgregarse poco a poco yla nieve cae con menos fuerza.\n", 
	 "Unos pocos copos dispersos caen perezosamente mientras las nubes se "
	 "alejan empujadas por el viento.\n",
	 "La nevada cesa por completo.\n"
	 "El cielo se despeja por completo y las frías estrellas relucenen lo alto.\n"})});


string *MSG_DEFAULT_GROUND=({
   /* Normal */
   	  ({"El suelo está seco.\n",
   	   "La brisa acaricia el suelo.\n",
   	   "La brisa crea pequeños remolinos en el suelo.\n",
  	   "La brisa crea pequeños remolinos en el suelo.\n",
   	   "La brisa acaricia el suelo.\n",
 	   "El suelo está seco.\n"}),
   /* Calor */
	   ({"El suelo está seco.\n",
	   "Ves un suelo caliente y seco.\n",
	   "El terreno está seco y polvoriento.\n",
	   "Desde el suelo sube un calor agobiante.\n",
	   "El terreno esta seco y resquebrajado.\n",
	   "El suelo esta caliente y reseco.\n"}),
   /* Lluvia */
   	  ({"El suelo está frío y seco.\n",
   	   "Vaharadas de vapor ascienden del suelo.\n",
   	   "Ves algo de escarcha por el suelo.\n",
   	   "Ves trozos de escarcha helada en el suelo.\n",
  	   "El suelo está helado.\n",
 	   "El suelo está frío.\n"}),
   /* Lluvia */
	   ({"El suelo está húmedo.\n",
	   "Ves restos de humedad en el suelo.\n",
	   "El suelo está mojado.\n",
	   "Empiezan a formarse charcos.\n",
	   "El suelo está anegado.\n",
	   "El suelo empieza a secarse.\n"}),
   /* Viento */
   	   ({"El suelo está seco.\n",
   	   "El viento empieza a azotar el suelo.\n",
   	   "A tus pies ves remolinos formados por el viento.\n",
   	   "El viento castiga el suelo.\n",
   	   "Los remolinos formados por el viento disminuyen en tamaño e intensidad.\n",
   	   "El suelo está seco.\n"}),
   /* Tormenta */
	   ({"El suelo se está humedeciando.\n",
	   "El suelo está mojado.\n",
	   "Se empiezan a formar charcos mientras cae algún rayo al suelo.\n",
	   "Los charcos están creciendo de manera alarmante.\n",
	   "El suelo está inundado.\n",
	   "El suelo está mojado.\n"}),
   /* Niebla */
	   ({"El suelo está húmedo.\n",
	   "Jirones de niebla empiezan a cubrirlo.\n",
	   "Una espesa niebla te impide verlo.\n",
	   "Una niebla impenetrable planea sobre el suelo.\n",
	   "Aún queda algo de niebla a tus pies.\n",
	   "Los últimos restos de niebla desaparecen.\n"}),
   /* Nieve */
   	   ({"El suelo está húmedo.\n",
  	   "El suelo está algo húmedo.\n",
	   "Sobre el suelo se está formando una fina capa de nieve.\n",
	   "El suelo está cubierto de nieve.\n",
	   "La nieve lo cubre todo.\n",
	   "La gruesa capa de nieve empieza a derretirse.\n"})});

#endif /* __CHRONOS_H */