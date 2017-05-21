/*********************************************************/
//		"ungrim"
//	El cazador de orcos, el héroe de kha-annu.
//	Va a la mina a luchar por su honor y por sus compañeros
//	caídos tiempo atrás.
//		07-12-01: Kodex-> creación
//		07-12-01: Kodex-> última modificación
// 23-03-2005 [kastwey] retoco algunas cosas
/*********************************************************/

#include <spellmonster.h>
#include <properties.h>
#include "./path.h"
#include <rooms.h>
#include <colours.h>
#include <gremios.h>
#include <moving.h>
#include <combat.h>
inherit SPELLMONSTER;


int cabreo, cabreado, tiene_pergamino, tiene_piedra;
public status check_hp();
public void alarido();

string EvaluarCabreo(int cab)
{
	switch (cab)
   {
		case 0: return "está de buen humor"; break;
		case 1: return "está serio"; break;
		case 2: return "está mosqueado"; break;
		case 3: return "está enfadado"; break;
		case 4: return "está muy cabreado"; break;
 }
 return "tiene una vena hinchada en la frente, está furioso";
}

create()
{
    ::create();
   tiene_pergamino=1;
    tiene_piedra=1;
    SetStandard("Ungrim","barbiluengo",([GC_LUCHADOR:55]),GENERO_MASCULINO);
    SetShort("Ungrim el héroe de Kha-annu");
    SetLong("Ungrim es un enano, tiene una barba rubia muy densa que acaba"
    " en trenzas, su cara y sus brazos están adornados con pinturas de guerra "
    "y cicatrices.\n  Ungrim se pasa el día pensando en estrategias para derrotar "
    "a los orcos. Parece un gran combatiente y " + EvaluarCabreo(cabreo) + ".\n");
    AddId("Ungrim");
    SetAggressive(2);
    SetFriendFunction((:($1->QueryRace() != "orco"):));
    SetAlign(100);
    AddQuestion(({"tabernero","Gulfar", "gulfar"}), "Ungrim dice entusiasmado:\n"
        "ah! por las largas barbas de mis honorables antepasados! Me estás diciendo "
        "que conoces a Gulfar Mano Férrea, hijo de Gulfur el Conquistador? Ese "
        "viejo terror de Orcos y taberneros! Que los dioses le conserven la barba "
        "larga y espesa hasta el fin de los tiempos!\n ¿Que noticias tienes de el?"
        " hace décadas que no nos vemos. Combatimos hacha con hacha sobre este "
        "mismo suelo, decapitando y destripando orcos a cientos. \n Ah! que tiempos!."
        " Lo último que se de él es que dirige la taberna Dragón Azul en Kha-Annu,"
        " sin duda una de las mejores de la ciudad, donde despacha la mejor cerveza "
        "del mundo!... No pudo volver aquí con migo... sufrió un ligero accidente, nada "
        "importante para un enano.\n");
    AddQuestion(({"kha-annu", "Kha-annu"}), QueryName()+
    " exclama: Ahh! Kha-Annu,  la de grandiosas cavernas y magníficos salones! Quieres "
    "decir que no conoces sus maravillas? deberías visitarla! por las barbas de mis "
    "antepasados que si! hace un tiempo viví allí, combatiendo por su honor y su gloria "
    "en compañía de mis camaradas.\n  Algún día volveré, y cuando lo haga será para "
    "entregarle a mi señor Beltaim hasta la última cabeza verdosa de este condenado "
    "lugar!.\n");
    AddQuestion(({"cerveza", "cerveza negra"}), QueryName()+
    " se palmea el abdomen con fuerza mientras te mira con un destello codicioso "
    "en los duros ojos y dice: bua! maldita sea, sería capaz de beberme todo un "
    "barril ahora mismo! esa cerveza negra de Kha-Annu, fría, espumosa y fuerte como "
    "el acero de nuestras minas! boto a los dioses! estoy harto de beber agua insípida "
    "como un maldito elfo! necesito cerveza!.\n");
    AddQuestion(({"barril", "barril de cerveza", "barril de cerveza negra"}), QueryName()+
    " se frota las manos con visible codicia mientras te observa pensativo y dice:\n "
    " Si... por mi barba que si! consígueme un buen barril de cerveza negra de Kha-Annu,"
    " bien rebosante! Quizás pueda hacer algo por ti entonces.\n");

    AddQuestion("juramento", QueryName()+
    " se iergue mientras se apoya en su hacha con expresión seria y dice con voz "
    "solemne: Los descendientes de Hardgrim Puño de Piedra juraron tomarse venganza "
        "contra los orcos y limpiar de pielesverdes estas minas para que volvieran "
        "a formar parte de los reinos enanos.\n ¡Yo soy el último descendiente vivo de "
        "Hardgrim, y como todos sus descendientes antes que yo también he jurado! ¡Por "
        "la sangre de los que aquí murieron, no abandonaré este lugar hasta haber "
        "acabado con el último y mas pequeño de los pielesverdes! ¡O eso, o yo también "
        "moriré aquí donde mis antepasados prosperaron en tiempos remotos!.\n");

    AddQuestion(({"pergamino", "pergamino de piel", "pergamino de piel de piedra"}),
    QueryName()+" gruñe: ¿pergamino?, acaso tengo yo pinta de conjurador?Si tengo o "
    "no tengo pergamino eso a ti no te incumbe.\n");
    AddQuestion(({"minas", "mina", "azmodan", "Azmodan"}),
    " Ante la mención de las minas, la barba de Ungrim parece erizarse mientras éste "
    "frunce el ceño lanzándote una mirada furibunda y alzando su hacha.\n Ungrim gruñe:"
    "\n  ¡éstas minas fueron excavadas y explotadas por mi raza hace mas de mil "
    "años! El oro que se extraía aquí era el mas puro y valioso que el mundo jamás "
    "halla visto, y numerosos los depósitos de piedras preciosas de valor sin par.\n  "
    "Mi gente prosperó aquí, y creció en número durante unos años y Kha-Annu se "
    "embelleció con las riquezas de éste valle, alcanzando mayor renombre del que ya "
    "poseía como la mas grande, antigua y populosa fortaleza enana. Pero una enorme "
    "horda orca ¡maldita sea esa odiosa raza por siempre!, sorprendió a los míos cuando "
    "la mayoría de nuestros guerreros estaban lejos, escoltando una caravana de "
    "mineral que viajaba hacia Kha-Annu para poner a buen recaudo las riquezas que "
    "habían arrancado del seno de la tierra con tanto trabajo, y acabó con todos los "
    "que encontraron a su paso, pues nos superaban en una proporción de cien a uno.\n"
    "  Finalmente, las minas fueron saqueadas y convertidas en guarida de los malditos "
    " pielesverdes que las habitan hasta hoy.\n");

    SetCastChance(20);
    AddSpell("conjuros",
    ([
    S_CHECKFUN:SF(check_hp),
    S_FUN:SF(alarido), S_SP:2,
    S_CHANCE:25,
    S_VICTIMS:1,
    ]));
    AddItem(ARMA_AZMODAN("hacha"),REFRESH_REMOVE,SF(wieldme));
    AddItem(ARMADURA_AZMODAN("cuero"),REFRESH_REMOVE,SF(wearme));
    InitChats(4,({"Ungrim dice: ¡¡'Añoro la cerveza de Kha-annu!!!'\n",
        " Ungrim exclama:¡¡¡Sería capaz de beberme un barril entero de la "
        "expléndida cerveza negra de Kha-annu!!!.\n",
    "Ungrim dice: 'Yo se más de esos pieles verdes de lo que tú sabrás en tres vidas.'\n",
    "Ungrim dice: 'Lo sé todo sobre sus clanes.'\n",
    "Ungrim dice: 'Algún día los machacaré uno a uno.'\n"}));

    AddQuestion(({"clanes","pielesverdes", "pieles verdes","orcos"}),
    "Ungrim se tira de la barba con furia y dice gruñendo: Esos malditos Orcos "
    "pielesverdes, malnacidos del infierno que nos tiraron de nuestro hogar.\n "
    " Hace un tiempo un shaman orco unificó los clanes, estos eran: Nzel-Orak,"
    " Karash, Gnarsht, Korgul, Tanglor, Gruniac, Jhanzur y Kniel-Zahg.\n");
    AddQuestion(({"nzel-orak","Nzel-Orak"}),
    "Ungrim dice: Su color es el gris plateado y son muy hábiles luchando.\n");
    AddQuestion(({"karash","Karash"}),
    "Ungrim dice: Su color es el marrón cuero y son los más diestros.\n");
    AddQuestion(({"gnarsht","Gnarsht"}),
    "Ungrim dice: Su color es el negro azabache y son los más resistentes.\n");
    AddQuestion(({"korgul","Korgul"}),
    "Ungrim dice: Su color es el blanco luminoso y dan unos golpes mortales.\n");
    AddQuestion(({"tanglor","Tanglor"}),
    "Ungrim dice: Su color es el azul marino y son los más fuertes.\n");
    AddQuestion(({"gruniac","Gruniac"}),
    "Ungrim dice: Su color es el amarillo llameante y destacan en manejo de armas y destreza.\n");
    AddQuestion(({"jhanzur","Jhanzur"}),
    "Ungrim dice: Su color es el azul brillante y son fuertes y resistentes.\n");
    AddQuestion(({"kniel-zahg","Kniel-Zahg"}),
    "Ungrim dice: Su color es el rojo sangre y son muy escurridizos.\n");
}

public status check_hp()
{
    return QueryDrink() >= 0;
}

mixed SetCombatDelay(int time , string s)
{
    object *targs;
    int i;
    tell_room(environment(),TC_CYAN+"Ungrim dice: 'Me estás cabreando, esas tonterías no te servirán conmigo...'\n"+TC_NORMAL);
    cabreo ++;
    SetLong("Ungrim es un enano, tiene una barba rubia muy densa que"
    " acaba en trenzas, su cara y sus brazos están adornados con pinturas "
    "de guerra y cicatrices. Ungrim se pasa el día pensando en estrategias "
    "para derrotar a los orcos. Parece un gran combatiente y " + EvaluarCabreo(cabreo) + ".\n");
    if (cabreo >= 6 && !cabreado)
    {
        tell_room(environment(),TC_RED+"Ungrim entra en furia asesina!!!.\n"+TC_NORMAL);
        SetMaxHP(QueryMaxHP()+250);
        SetHP(QueryHP()+250);
        targs = filter(all_inventory(environment()),(:query_once_interactive($1)?1:0:));
        AddEnemies(targs);
        cabreado = 1;
    }
    return 1;
}

public void alarido()
{
    object *en,ene;
    if (QueryDrink() <= 0) return;
    en=QueryEnemies() || ({});
    if(!sizeof(en)) return;
    ene=en[random(sizeof(en))];

    AddDrink(-8);
    ene->SetCombatDelay(random(4)+2,"Estás asustado.\n");
    tell_room(environment(),"Ungrim se vuelve hacia " + ene->QueryName() + " y grita como sólo los guerreros pueden hacer.\n"),({ene});
    tell_object(ene,"Ungrim grita como un bárbaro, asustándote.\n");
}

public void notify_enter(mixed from,int method,mixed extra){
    object quien = from;
    object que = PO;
    ::notify_enter(from, method, extra);
    if (!quien || !query_once_interactive(quien)) return;
    call_out("dar_barril",1,quien, que);
}

void dar_barril(object quien, object que){
    if (!que) return;
    if (!quien|| !present(quien, environment())){
        tell_room(environment(), "Ungrim mira a su alrededor con cara confundida "
        "y exclama: ¡¡Qué cosas más extrañas ocurren en estas minas!!, estos malditos "
        "pielesverdes y su endemoniada brujería...\n");
        return;
    }

    if (que->id("barril de cerveza")){
        tell_object(quien,"Ungrim levanta a pulso el barril y lo examina  con "
        "incredulidad...\n Ungrim exclama: ¡Por mi barba!¿Qué tenemos aquí? ¡Hierros "
        "candentes! no puede ser posible pero  parece  uno de los barriletes del viejo "
        "Gulfar!. Abre, con la habilidad que da la practica, el barril y hechando "
        "la cabeza hacia atrás bebe un enorme trago de su contenido, tras lo cual "
        "chasquea la lengua con evidente placer y suelta un enorme eructo de "
        "satisfacción.\n Ungrim brama: ¡Que me fundan vivo y me den forma en un molde "
        "si esto no es verdadera cerveza negra de Kha-Annu! Se acerca a ti "
        "agradecido y te asesta una recia  palmada en la espalda que te hace "
        "expulsar todo el aire.\n");
        tell_room(environment(quien), CAP(quien->QueryName())+" le entrega un barril a "
        "Ungrim, el cual examina entusiasmado y lo abre rapidamente, bebe de él un "
        "largo trago, que le hace eructar sonoramente, y le arrecia una fuerte palmada"
        " en la espalda de agradecimiento.\n",({quien}));
        if(tiene_pergamino==1){
            object pergamino =
            clone_object("/guilds/conjuradores/pergamino/pergamino_piel_piedra");
            tell_object(quien," Ungrim dice: Si las minas estuvieran ya en nuestras "
            "manos podría recompensarte largamente por este detalle, pero ahora mismo"
            " sólo te puedo ofrecer un... ¿Donde lo habré metido...? se lo quité a "
            "aquel goblin esmirriado que maté al sur del valle...\n  Tras unos segundos"
            " rebusca bajo su armadura y con un gruñido desdeñoso saca un pergamino y te lo"
            " entrega.\n Ungrim gruñe: No es mas que un papel mugriento con garabatos "
            "pero... hmmmm... puede que alguno de esos que se dedican a hacer trucos,"
            " conjuradores los llaman, le pueda sacar algún uso y te  lo pague bien. "
            "Aunque no te fíes, todos esos magos y hechiceros no son mas que una "
            "banda de tramposos y farsantes poco dignos de confianza.\n");
            tell_room(environment(TP),"Ungrim le da lo que parece un pergamino a "+
            CAP(quien->QueryName())+ " y le habla algo sobre los conjuradores.\n",({quien}));
            pergamino->move(quien,M_SILENT);
            tiene_pergamino=0;
            if (que) destruct(que);
            return;
        }else{
            if(tiene_piedra){
                object obsequio= clone_object(OBJETO_AZMODAN("piedra"));
                tell_object(quien,"Ungrim dice entusiasmado: Ah... como pagártelo?. "
                "Tengo una piedra preciosa, la encontré hace unos días cuando exploraba "
                "los niveles superiores de las minas. Si mi pueblo las hubiera conquistado"
                " ya, te podría dar un cofre lleno de piedras como esta, pero me temo "
                "que el día no ha llegado aún.\n Rebusca bajo su armadura y te da "
                "la piedra.\n");
                tell_room(environment(quien)," Ungrim le da algo pequeño a "
                +CAP(quien->QueryName())+".\n",({quien}));
                obsequio->move(quien,M_SILENT);
                if (que) destruct(que);
                tiene_piedra=0;
                return;
            }else{
                tell_object(quien,"Ungrim te dice alegremente: me ha encantado tu "
                "detalle, aquí tienes un amigo para lo que quieras, siento no tener "
                "nada para tí, pero mi amistad vale más que todo el oro del mundo, "
                "¿verdad que sí?.\n");
                tell_room(environment(quien), "Ungrim le da las gracias a "+CAP(TNAME)+
                ".\n",({quien}));
                if (que) destruct(que);
                return;
            }
        }
    }else{
        tell_object(quien, "Ungrim mira "+que->QueryShort()+" que le has dado y te lo "
        "tira a la cabeza precipitándose sobre ti con los ojos encendidos de furia "
        "mientras te dice: ¡Miserable gusano, no estoy de humor para que alguien como "
        "tú me tome el pelo!.\n");
        tell_room(environment(quien), CAP(quien->QueryName())+" le da a Ungrim "
        +que->QueryShort()+
        " y el enano se enfada tirándoselo a la cabeza y gruñéndole.\n",({quien}));
        que->move(environment(quien), M_SILENT);
        quien->Defend(d20(2),TD_APLASTAMIENTO, DEFEND_NOMSG);
        cabreo ++;
        return;
    }
}

