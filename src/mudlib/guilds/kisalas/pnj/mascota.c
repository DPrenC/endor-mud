/*=======================================================================*
 |                  <<   Gremio de las Kisalas   >>                      |
 *=======================================================================*
 | [w] Woo@simauria                                                      |
 | [a] Avengelyne@simauria                                               |
 | [s] kastwey@simauria                                                  |
 |                                                                       |
 | 02-03-99 [w] Este archivo contendrá la mascota base.                  |
 | 09-03-99 [w] Ahora cada 10 minutos la mascota tendrá un poco más de   |
 |              hambre y sed, así como se le restablecerá un poquitin    |
 |              el nivel de alcohol (cada vez es más un tamagotchi)      |
 | 12-03-99 [w] Ahora la mascota puede ir a otro lugar, comprar en los   |
 |              pubs, mirar, atacar, hacer acciones y decir cosas.       |
 | 13-03-99 [w] Ahora las mascotas tienen edad que tendrá bastante valor |
 |              en el ranking de mascotas.                               |
 | 14-03-99 [w] Instalado el sistema de combate que puede tener dos modos|
 |              alerta/pasivo, en el primer caso cuando ataquen a la     |
 |              amazona la mascota le defenderá, en el segundo no.       |
 | 24-03-99 [w] Implementada la base de datos de las mascotas.           |
 | 17-04-99 [w] Cuando matabas a la mascota luego grababa los datos y    |
 |              podia resucitar. Ahora ya no lo hace :)                  |
 | 20-04-99 [w] Retocado el comando estado.                              |
 | 09-11-99 [w] Parece mentira, pero se comen los cadáveres :)           |
 | 27-03-00 [w] Pues ahora ya no hay dos mascotas cuando mueren.         |
 | 20-04-05 [s] comienzo a mirarlas y a retocar lo que falla.            |
 |              Modifico algunas funciones obsoletas por las actuales,   |
 |              simplifico, sangro...                                    |
 |              Le coloco la propiedad de brazalete, que estoy hasta los |
 |              mismos de ver present por todos lados...                 |
 *=======================================================================*/

#include "./path.h"
#include <living.h>
#include <moving.h>
#include <properties.h>
#include <guild.h>

#define MASCOTADB  AMAZONHOME "obj/mascotasdb"
#define HEART_MASCOTA 300 // 2*300=600 segundos (10 minutos)
#define HEART_ATAQUE 3 // Comprobará los atacantes de la amazona cada 6 segs.
#define GRABAR 30 // Grabará sus stats cada minuto (obligatoriamente)
#define SED    1
#define HAMBRE 2
#define M_PASIVO 0
#define M_ALERTA 1
#define MAX_SED    -250
#define MAX_HAMBRE -250
#define MAX_NIVEL    (QueryAmazona()?(QueryAmazona()->QueryGuildLevel()>>1):1)

inherit NPC;


static object amazona;
static object brazalete;
static int heart_cont;
static int heart_contat;
static int grabar_cont;
static int tiempo_vida;
static int modo_combate;

public object SetAmazona(object am);
public object QueryAmazona();
public object AsignaBrazalete();
public int check_chars(string str);
public varargs string ShortObjeto(object ob, string short);


public void create()
{
    ::create();
    if (!clonep()) return;
    seteuid(getuid());
    heart_cont=0;
    heart_contat=0;
    grabar_cont=0;
    tiempo_vida=time();
    enable_commands();
    //Set(P_IS_PET, 1); // Parche temporal para que reciban xp
    if (QueryAmazona()) AsignaBrazalete();
    // comento esto... los npc no tienen ya de por si heart_beat? ...
    // set_heart_beat(1); //[h] pues al comentar la linea anterior vuelve ha hacer falta no?
}

/*
 ======================
   [w] SET y QUERY
 ======================
*/

public string QueryLong()
{
    if (!QueryAmazona()) return ::QueryLong();
    return ::QueryLong() +
             "Lleva una pequeña chapa colgando que dice 'soy propiedad de " +
             QueryAmazona()->QueryName()+"'.\n";
}

public string QueryShort()
{
    if (!QueryAmazona()) return ::QueryShort();
    return ::QueryShort() +
             ", " + (QueryGender() == 2?"la":"el") + " " + QueryRace() + " de " +
             CAP(QueryAmazona()->QueryName());
}

public int SetModo(int modo)
{
    return modo_combate=modo;
}

public int QueryModo() { return modo_combate; }

public object SetAmazona(object jugador)
{
    return amazona=jugador;
}

public object QueryAmazona() { return amazona; }

public object QueryBrazalete() { return brazalete || AsignaBrazalete(); }

public string QueryEdad()
{
    int edad;
    if (!QueryAmazona()) return 0;
    if (!QueryBrazalete()) return 0;
    if (brazalete->QueryObjectOwner() != QueryAmazona()) return 0;
    edad=brazalete->QueryMascotaEdad();
    edad=edad+time()-tiempo_vida;
    return (edad/1800)+((edad/1800)==1?" hora":" horas");
}


string QueryHambre()
{
    int hambre,sed;
    string msg_hambre,msg_sed,msg;

    hambre = QueryFood();
    sed = QueryDrink();
    if (hambre < -150 && sed < -150)
    {
        return "Estoy muriéndome de hambre y de sed.\n";
    }
    if (hambre < QueryMaxFood() / 2)
    // comienza a tener hambre...
    {
        switch(hambre)
        {
            case -150..-101: msg_hambre = "muchísima hambre"; break;
            case -100..-41:  msg_hambre = "mucha hambre"; break;
            case -40..-11:   msg_hambre = "hambre"; break;
            case  -10..-1:   msg_hambre = "algo de hambre"; break;
            default:
                if (hambre >= 0) msg_hambre = "un poco de apetito";
                else msg_hambre = "muriéndome de hambre";
            break;
        }
    }
    if (sed < QueryMaxDrink() / 2)
    // comienza a tener sed.
    {
        switch(sed)
        {
            case -150..-101: msg_sed="muchísima sed"; break;
            case -100..-51:  msg_sed = "mucha sed"; break;
            case -50..-11:   msg_sed = "bastante sed"; break;
            case -10..-1:    msg_sed = "sed"; break;
            default:
                if (sed >= 0) msg_sed = "un poco de sed";
                else msg_sed = "muriéndome de sed";
            break;
        }
    }
    if (!msg_hambre && !msg_sed) return 0;

    if (msg_hambre)
    {
        msg = (hambre < -150?"Estoy ":"Tengo ") + msg_hambre + (msg_sed?" y " +
              (sed < -150?"estoy ":(hambre < -150?"tengo ":"")) + msg_sed:"") + ".\n";
    }
    else
    {
        msg = (sed < -150?"estoy ":"tengo ") + msg_sed + ".\n";
    }
    if (msg) return msg;
    return 0;
}


/*
 ======================
   [w] FUNCIONES
 ======================
*/

void T(string texto)
{
    if (!QueryAmazona()) return;
    tell_object(QueryAmazona(),"\n"+CAP(QueryName())+" te dice: "+texto+"\n");
    return;
}

void Troom(string texto)
{
    if (!QueryAmazona()) return;
    tell_room(environment(),CAP(QueryName())+" "+texto+"\n", ({QueryAmazona()}));
    return;
}

void Tel(string texto)
{
    if (!QueryAmazona()) return;
    tell_object(QueryAmazona(),texto+"\n");
    return;
}

int GrabarMascota()
{
    if (!QueryAmazona()) return 0;
    if (!QueryBrazalete()) return 0;
    if (QueryGhost()) return 0;
    if (brazalete->QueryObjectOwner()!=QueryAmazona()) return 0;
    brazalete->SetMascotaNombre(QueryName());
    brazalete->SetMascotaSexo(QueryGender());
    brazalete->SetMascotaRaza(QueryRace());
    brazalete->SetMascotaHP(QueryHP());
    brazalete->SetMascotaSP(QuerySP());
    brazalete->SetMascotaXP(QueryXP());
    brazalete->SetMascotaSed(QueryDrink());
    brazalete->SetMascotaHambre(QueryFood());
    brazalete->SetMascotaAlcohol(QueryAlcohol());
    brazalete->SetMascotaNivel(QueryLevel());
    brazalete->SetMascotaCoraje(QueryWhimpy());
    brazalete->SetMascotaModo(QueryModo());
    brazalete->SetMascotaEdad(brazalete->QueryMascotaEdad()+time()-tiempo_vida);
    brazalete->SaveMe();
    tiempo_vida=time();
    MASCOTADB->ModifyDB(geteuid(QueryAmazona()),QueryName(),QueryLevel(),
                        brazalete->QueryMascotaEdad(),QueryGender(),
                        QueryRace());
    return 1;
}

int BorrarMascota()
{
    if (!QueryBrazalete()) return 0;
    if (brazalete->QueryObjectOwner()!=QueryAmazona()) return 0;
    brazalete->AddMascotaMuerta(1);
    brazalete->SetMascotaNombre(0);
    brazalete->SetMascotaSexo(0);
    brazalete->SetMascotaRaza(0);
    brazalete->SetMascotaHP(0);
    brazalete->SetMascotaSP(0);
    brazalete->SetMascotaXP(0);
    brazalete->SetMascotaSed(0);
    brazalete->SetMascotaHambre(0);
    brazalete->SetMascotaAlcohol(0);
    brazalete->SetMascotaNivel(0);
    brazalete->SetMascotaCoraje(0);
    brazalete->SetMascotaEdad(0);
    brazalete->SetMascotaModo(0);
    brazalete->SetMascota(0);
    brazalete->SaveMe();
    if (QueryAmazona()) QueryAmazona()->RemoveFollower(TO);
    MASCOTADB->DeleteDB(geteuid(QueryAmazona()));
    return 1;
}

int DesactivarMascota()
{
    if (!QueryAmazona()) return 0;
    if (!QueryBrazalete()) return 0;
    if (brazalete->QueryObjectOwner()!=QueryAmazona()) return 0;
    brazalete->SetMascota(0);
    brazalete->SetTiempoEscondida(time());
    if (QueryAmazona()) QueryAmazona()->RemoveFollower(TO);
    return 1;
}

void PlayerNetdead(int arg)
{
    if (!QueryAmazona() || PO != QueryAmazona()) return;
    if (!arg) GetHeart(HEART_USER);
    else
    {
        DropHeart(HEART_USER);
        remove();
    }
}

void ComprobarEnemigos()
{
    mixed enemigos;
    int i;

    if (!QueryAmazona()) return;
    if (environment() != ENV(QueryAmazona())) return;
    AddEnemies(QueryAmazona()->QueryEnemies());
    return;
}

public void Whimpy()
{
    GrabarMascota();
    if (QueryAmazona()) QueryAmazona()->RemoveFollower(TO);
    return ::Whimpy();
}

public int remove()
{
    GrabarMascota();
    DesactivarMascota();
    return ::remove();
}

int Muere(int causa)
{
    if (!causa) return 0;
    if (causa!=HAMBRE && causa!=SED) return 0;
    if (causa==HAMBRE)
    {
        Tel(CAP(QueryName()+" ha muerto de hambre."));
        LOG("MALNUTRICION",STR->etime()+"> "+CAP(QueryName())+" "+(QueryGender()==2?"la":"el")+
                           " "+QueryRace()+" de "+CAP(QueryAmazona()->QueryName())+" ha "
                           "muerto de hambre.\n");
    }
    else if (causa==SED)
    {
        Tel(CAP(QueryName()+" ha muerto de sed."));
        LOG("MALNUTRICION",STR->etime()+"> "+CAP(QueryName())+" "+(QueryGender()==2?"la":"el")+
                           " "+QueryRace()+" de "+CAP(QueryAmazona()->QueryName())+" ha "
                           "muerto de sed.\n");
    }
    BorrarMascota();
    call_out("Die",1);
    return 1;
}

void AumentarNivel()
{
    int ant_xp,ant_sed,ant_hambre,ant_alcohol, ant_hp, ant_sp;

    ant_xp=QueryXP();
    ant_sed=QueryDrink();
    ant_hambre=QueryFood();
    ant_alcohol=QueryAlcohol();
    ant_hp=QueryHP();
    ant_sp=QuerySP();
    SetStandard(QueryName(), QueryRace(), QueryLevel(), QueryGender());
    SetXP(ant_xp); // El SetStandard hace un random para ver la xp q tienes
    SetDrink(ant_sed);
    SetFood(ant_hambre);
    SetAlcohol(ant_alcohol);
    SetHP(ant_hp);
    SetSP(ant_sp);
    GrabarMascota();
    T("He aumentado a nivel "+QueryLevel()+".");
    LOG("NIVEL_MASCOTA",STR->etime()+"> "+CAP(QueryName())+" "+(QueryGender()==2?"la":"el")+
                        " "+QueryRace()+" de "+CAP(QueryAmazona()->QueryName())+" ha "
                        "aumentado a nivel "+ QueryLevel()+".\n");
}

void MensajesEstado()
{
    string msg;
    msg=QueryHambre();
    if (msg)
    {
        if (random(10)>5) T(CAP(msg));
    }
    return;
}

/*
 ======================
   [w] FUNCIONES CMD
 ======================
*/

int cmd_salvar()
{
    if (GrabarMascota()) return T("Ahora me siento más seguro."),1;
    return 0;
}

int cmd_nombre(string nombre)
{
    int i,valido;
    if (!nombre || nombre=="")
    {
        return T("Me llamo "+CAP(QueryName())+" ¿o no lo sabias?"),1;
    }
    if (strlen(nombre)>12 || strlen(nombre)<3)
    {
        return T("Mi nombre ha de tener entre 3 y 12 letras, sin "
                 "espacios, en minúsculas y sin carácteres raros :)"),1;
    }
    if (!check_chars(nombre))
    {
        return T("Mi nombre ha de tener entre 3 y 12 letras, sin "
                 "espacios, en minúsculas y sin carácteres raros :)"),1;
    }
    if (nombre==QueryName())
    {
        return T("Ya me llamo así."),1;
    }
    T("De acuerdo, a partir de ahora me llamo '"+nombre+"'.");
    SetName(nombre);
    SetShort(nombre);
    GrabarMascota();
    return 1;
}

int cmd_modo(string modo)
{
    if (!modo || modo=="")
    {
        return (QueryModo() == M_PASIVO?T("Me ordenaste mantenerme al margen "
                                          "de tus combates."):
                                        T("No te preocupes, si te atacan te defenderé.")),1;
    }
    if (modo!="pasivo" && modo!="alerta")
    {
        return T("¿Quieres que esté en modo alerta o pasivo en el combate?"),1;
    }
    if (modo=="pasivo")
    {
        if (QueryModo() == M_PASIVO)
        {
            return T("Ya estaba en modo pasivo."),1;
        }
        else
        {
            SetModo(M_PASIVO);
            GrabarMascota();
            return T("De acuerdo, me mantendré al margen de tus combates."),1;
        }
    }
    if (QueryModo() == M_ALERTA)
    {
        return T("Ya estaba en modo alerta."),1;
    }
    else
    {
        SetModo(M_ALERTA);
        GrabarMascota();
        return T("Como quieras, te defenderé cuando te ataquen."),1;
    }
    return 1;
}

int cmd_estado()
{
    string msg_estado, msg_comida;
    msg_estado = "Nivel(" + QueryLevel() + ") Edad(" + QueryEdad() +
               ") Vida(" + QueryHP() + "/" + QueryMaxHP() + ") Magia(" +
               QuerySP() + "/" + QueryMaxSP() + ") Coraje("+ QueryWhimpy() +
               ") Combate(" + (QueryModo() == M_PASIVO?"pasivo":"alerta") +
               ") Experiencia(" + QueryXP() + "). ";

    msg_comida = QueryHambre();
    if (QueryLevel()<MAX_NIVEL)
    {
        T(msg_estado + "Necesito " +
          ((level2xp(QueryLevel()+1))-QueryXP()) +
          " puntos de experiencia para aumentar de nivel" +
          (msg_comida?
           ", y " + msg_comida:""));
    }
    else
    {
        T(msg_estado + "No puedo aumentar de nivel, " +
          (msg_comida?" y " + msg_comida:""));
    }

    return 1;
}

int cmd_irse()
{
    T("Adios "+CAP(QueryAmazona()->QueryName())+", llámame si me necesitas.");
    Tel(CAP(QueryName())+" se aleja rápidamente.");
    Troom("se esconde y desaparece.");
    remove();
    return 1;
}

int cmd_seguir()
{
    if (!QueryAmazona()) return 0;
    if (ENV(TO)!=ENV(QueryAmazona()))
    {
        return T("ahora no puedo seguirte, no estoy contigo."),1;
    }
    if (member(QueryAmazona()->QueryFollowers(),TO) >= 0)
    {
        return T("Ya estaba siguiéndote."),1;
    }
    QueryAmazona()->AddFollower(TO);
    return T("Ya te sigo."),1;
}


int cmd_atacar(string objetivo)
{
    object enemigo;
    if (!objetivo || objetivo=="")
    {
        return T("¿A quien quieres que ataque?"),1;
    }
    if (enemigo=present(objetivo,environment()))
    {
        T("Tú mandas, atacaré a "+enemigo->QueryName()+".");
        Troom("comienza a atacar a "+enemigo->QueryName()+".");
        AddEnemy(enemigo);
        return 1;
    }
    T("No veo a "+objetivo+" por aquí cerca.");
    return 1;
}

int cmd_decir(string texto)
{
    if (!texto || texto=="")
    {
        return T("¿Qué quieres que diga?"),1;
    }
    tell_room(environment(TO),"\n"+W(CAP(QueryName())+" dice: "+texto)+"\n");
    return 1;
}

int cmd_ir(string direccion)
{
    mapping salidas;
    if (!direccion || direccion=="")
    {
        return T("¿Dónde quieres que vaya?"),1;
    }
    salidas=environment()->QueryExits();
    if (salidas && member(salidas,direccion))
    {
        QueryAmazona()->RemoveFollower(TO);
        command_me(direccion);
        return 1;
    }
    T("No puedo ir en esa dirección.");
    return 1;
}

int cmd_huir(string direccion)
{
    mapping salidas;
    if (!direccion || direccion=="")
    {
        return Whimpy(),1;
    }
    // Si no tiene nivel 15 huye aleatoriamente.
    if (QueryLevel()<15) return Whimpy(),1;
    if ((salidas = environment()->QueryExits()) && member(salidas,direccion))
    {
        command_me(direccion);
        return 1;
    }
    T("No puedo ir en esa dirección.");
    return 1;
}

int cmd_mirar(string objetivo)
{
    if (   !objetivo || objetivo == "" || objetivo == "lugar"
        ||  objetivo=="habitacion" || objetivo=="habitación")
    {
        if (!CanSee()) return T("No consigo ver nada."),1;
        else
        {
            Troom("mira a su alrededor.");
            return T("Estoy viendo...\n" + LookRoom()),1;
        }
    }
    T("Si quieres mirar algo en concreto será mejor que vengas tú.");
    return 1;
}

int cmd_tirar(string str)
{
    object ob;
    if (!str || str == "")
    {
        T("¿Qué es lo que quieres que tire?");
        return 0;
    }
    if (!(ob = present(str,TO)))
    {
        T("No tengo " + str + " encima.");
        return 0;
    }
    if (ob->move(environment()) != ME_OK)
    {
        tell_room(environment(),W(CAP(QueryName()) + " se sacude como si "
                                  "quisiese quitarse algo de encima, pero "
                                  "no ocurre nada.\n"));
        T("Lo siento, no puedo tirar " + ShortObjeto(ob) + ".");
        return 0;
    }
    tell_room(environment(),W(CAP(QueryName()) + " se sacude y tira " +
                              ShortObjeto(ob) + ".\n"));
    if (environment() != environment(QueryAmazona()))
    {
        T("De acuerdo, ya he tirado " + ShortObjeto(ob) + ".");
    }
    return 1;
}


int cmd_beber()
{
    if (command_me("beber agua") || command_me("beber agua de la fuente"))
    {
        if (environment() != environment(QueryAmazona()))
        {
            T("De acuerdo, he bebido agua.");
        }
        return 1;
    }
    if (QueryDrink() == QueryMaxDrink())
    {
        T("No puedo beber más.");
        return 1;
    }
    T("No encuentro agua para beber.");
    return 1;
}

int cmd_comprar(string producto)
{
    if (!producto || producto=="")
    {
        return T("¿Qué es lo que quieres que compre?"),1;
    }
    if (member(inherit_list(environment()),"/std/pub.c") < 0)
    {
        return T("No estoy en una taberna o restaurante."),1;
    }
    if (!command_me("pedir " + producto))
    {
        T("Lo siento, no he podido pedir eso.");
        return 0;
    }
    if (environment() != environment(QueryAmazona())) T("De acuerdo.");
    return 1;
}

int cmd_accion(string texto)
{
    if (!texto || texto=="")
    {
        return T("¿Qué quieres que haga?"),1;
    }
    tell_room(environment(),"\n"+W(CAP(QueryName())+" "+texto)+"\n");
    if (environment() != environment(QueryAmazona()))
    { // si no están en la misma habitación, le avisa de que ha hecho la acción
        T("Hecho.");
    }
    return 1;
}


int cmd_coraje(string coraje)
{
    int i;
    if (coraje && coraje != "0" && ((i = (int)coraje) < 0 || !i))
    {
        return T("Debes darme un número positivo para que lo use como coraje. "
                 "Si quieres saber qué coraje tengo, dime coraje, "
                 "simplemente.\n"), 1;
    }
    if (!coraje)
    {
        if (QueryWhimpy())
        {
            return T("Actualmente huyo cuando me queden menos de " + QueryWhimpy() +
                     " puntos de vida.\n"), 1;
        }
        return T("Ahora lucho hasta la muerte.\n"), 1;
    }
    if (i > QueryMaxHP())
    {
        i = QueryMaxHP();
        T("No tengo tanta vida como para huir con el número que me has dicho, "
          "así que huiré cuando me queden menos de " + i + " puntos.\n");
    }
    else if (i)
    {
        T("De acuerdo, huiré cuando me queden menos de " + i + " puntos de "
          "vida.\n");
    }
    else
    {
        T("De acuerdo, lucharé hasta la muerte.\n");
    }
    SetWhimpy(i);
    GrabarMascota();
    return 1;
}

int cmd_cadaver()
{
    object ob;
    while(remove_call_out(SF(cmd_cadaver))!=-1);
    ob= present("cadáver",environment());
    if (ob && !query_once_interactive(ob) && !living(ob))
    {
        tell_room(environment(),W(CAP(QueryName()) + " se come " +
                                  ShortObjeto(ob,"un cadáver") + ".\n"));
        Heal(20);
        ob->remove();
    }
    return 1;
}

/*
 ======================
   [w] CATCH_TELL
 ======================
*/

catch_tell(string str)
{
    string com;

    if (!QueryAmazona()) return;
    if (sscanf(str,"%s muerto.",com)==1) call_out(SF(cmd_cadaver),7);
    if (sscanf(str,"%scadáver%s",com)) call_out(SF(cmd_cadaver),7);
    return;
}

// ejecutar un comando que le diga el player
public void EjecutaComando(string comando)
{
    string accion;
    mixed  extra;
    int n;
    // calculamos la acción y el posible extra
    // la acción es la primera palabra
    accion = explode(comando," ")[0];
    // el extra es lo que va después del espacio
    if ((n = strstr(comando," ")) >= 0) extra = comando[n+1..];
    switch(accion)
    {
        case "nombre":
            call_out("cmd_nombre",1,extra);
            return;
        case "combate":
            call_out("cmd_modo",1,extra);
            return;
        case "huye":
            call_out("cmd_huir",1,extra);
            return;
        case "ataca":
            call_out("cmd_atacar",1,extra);
            return;
        case "coraje":
            call_out("cmd_coraje",1,extra);
            return;
        case "estado":
            call_out("cmd_estado",1);
            return;
        case "sigueme":
        case "sígueme":
            call_out("cmd_seguir",1);
            return;
        case "salvate":
        case "sálvate":
            call_out("cmd_salvar",1);
            return;
        case "escondete":
        case "escóndete":
            call_out("cmd_irse",1);
            return;
        // nivel 5 o superior
        case "di":
            if (QueryLevel() < 5) break;
            call_out("cmd_decir",1,extra);
            return;
        case "accion":
        case "acción":
            if (QueryLevel() < 5) break;
            call_out("cmd_accion",1,extra);
            return;
        // nivel >= 15
        case "vete":
            if (QueryLevel() < 15) break;
            call_out("cmd_ir",1,extra);
            return;
        case "tira":
            if (QueryLevel() < 15) break;
            call_out("cmd_tirar",1,extra);
            break;
        case "bebe":
            if (QueryLevel() < 15) break;
            call_out("cmd_beber",1);
            return;
        case "mira":
            if (QueryLevel() < 15) break;
            call_out("cmd_mirar",1,extra);
            return;
        case "compra":
            if (QueryLevel() < 15) break;
            call_out("cmd_comprar",1,extra);
            return;
    }
    T("No entiendo lo que quieres decirme.");
    return;
}



/*
 ====================
   [w] HEART_BEAT
 ====================
*/

public void heart_beat()
{
    ::heart_beat();
    if (!QueryAmazona()) remove(); // Si la amazona ha cortado la conexión desaparece.
    heart_cont++;
    heart_contat++;
    grabar_cont++;
    if (grabar_cont>=GRABAR)
    // ya es hora de grabar
    {
        GrabarMascota();
        grabar_cont=0;
    }
    if (heart_contat>=HEART_ATAQUE)
    {
        if (QueryModo())
        {
            heart_contat=0;
            ComprobarEnemigos();
        }
        else heart_contat=0;
    }
    if (heart_cont>=HEART_MASCOTA)
    {
        heart_cont=0;
        AddFood(-5);
        AddDrink(-5);
        if (QueryAlcohol())
        {
            if (QueryAlcohol() > 5) AddAlcohol(-5);
            else SetAlcohol(0);
        }
        MensajesEstado();
    }
    if (QueryFood()<MAX_HAMBRE) return Muere(HAMBRE),0;
    if (QueryDrink()<MAX_SED) return Muere(SED),0;
}




public varargs int move(mixed dest,int method, mixed extra)
{
    if (!QueryAmazona() || QueryAmazona()->QueryGhost()) remove();
    return ::move(dest, method, extra);
}


public varargs void Die(mixed silent)
{
    object killer = QueryKiller();
    string nombre_asesino;

    BorrarMascota();
    if (   killer && (query_once_interactive(killer) || killer->QueryIsPet())
        && killer != QueryAmazona())
    {
    // Otro jugador, o la mascota de otro jugador  mató a
    // la mascota.
        nombre_asesino = (query_once_interactive(killer)?killer->QueryRealName():
                          (killer->QueryOwner()?
                           killer->QueryOwner()->QueryRealName():"una mascota "
                           "sin dueño"));
        LOG("ASESINOS_MASCOTAS",STR->etime() + "> " + CAP(nombre_asesino) +
            " ha asesinado a la mascota de "+ CAP(QueryAmazona()->QueryName()) + ".\n");
    }
    else
    {
        LOG("MUERTE_MASCOTA",STR->etime() + "> " + CAP(QueryName()) + " " +
            (QueryGender() == 2?"la":"el") + " "+ QueryRace() + " de " +
            CAP(QueryAmazona()->QueryName()) + " ha muerto.\n");
   }
    return ::Die(silent);
}

public object AsignaBrazalete()
{
    if (brazalete) return 0;
    if (!QueryAmazona()) return 0;
    if (!(brazalete = present("brazalete del gremio de kisalas",QueryAmazona()))) return 0;
    return brazalete;
}

public int check_chars(string str)
{
  int i;
  if (str && (i=strlen(str=lower_case(str)))) for (; i-- ;)
  {
    if ((str[i] < 'a' || str[i] > 'z') && str[i] != 'ñ')
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------

/**
 * Le sumo experiencia teniendo en cuenta que el limite de nivel es la mitad
 * del que tenga mi dueño.
 */
public int AddXP(int xp)
{
  int rc;

  if (!QueryAmazona()) return ::AddXP(xp);

  // Compruebo que la experiencia esta no me hace sobrepasar mi limite
  if (xp2level(QueryXP()+xp) > MAX_NIVEL)
  {  // Me paso de nivel, impedirlo.
     xp = level2xp(MAX_NIVEL) - QueryXP() - 1;
     if (xp < 1) return 0; // Para por si acaso, q no me apetece echar cuentas
  }

  rc = ::AddXP(xp); // Le añado la xp

  // Miro si he subido de nivel
  if (xp2level(QueryXP())>QueryLevel())
  { // Resulta que he subido de nivel!!
    AumentarNivel();
  }

  return rc;
}

//------------------------------------------------------------------------------

public int SetXP(int xp)
{ // Llamada cada vez que se crea la mascota, ya q solo se guarda la XP
  int rc;

  if (!QueryAmazona()) return ::SetXP(xp);

  // Compruebo que la experiencia esta no me hace sobrepasar mi limite
  if (xp2level(xp) > MAX_NIVEL)
  {  // Me paso de nivel, impedirlo.
     xp = level2xp(MAX_NIVEL) - 1;
     if (xp < 1) return 0; // Para por si acaso, q no me apetece echar cuentas
  }

  rc = ::SetXP(xp); // Le añado la xp

  // Miro si he subido de nivel
  if (xp2level(QueryXP())>QueryLevel())
  { // Resulta que he subido de nivel!!
    AumentarNivel();
  }

  return rc;
}

//------------------------------------------------------------------------------

public varargs string ShortObjeto(object ob, string short)
{
    if (!ob) return 0;
    return (ob->QueryShort() || ob->QueryName() || short || "algo");
}

//------------------------------------------------------------------------------
