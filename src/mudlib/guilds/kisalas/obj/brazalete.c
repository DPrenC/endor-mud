/*=======================================================================*
 |                  <<   Gremio de las Kisalas   >>                      |
 *=======================================================================*
 | [w] Woo@simauria                                                      |
 | [a] Avengelyne@simauria                                               |
 | [h] Nyh@simauria                                                      |
 | [s] Kastwey@simauria                                                  |
 |                                                                       |
 | 09-10-98 [w] Creación de este archivo.                                |
 | 26-10-98 [w] Realizados y probados los skills de esquivar y ataque con|
 |              vara en WeaponHit y Defend.                              |
 | 12-03-99 [w] Añadido el skill de lucha con espada. Solo funcionará si |
 |              la espada es de 1 sola mano y pesa menos de 2.5 kg.      |
 | 14-03-99 [w] Ahora simplemente silbando aparece tu mascota. Añadido   |
 |              el modo de combate de las mascotas.                      |
 | 20-03-99 [w] Ahora usa el WeaponHit del gremio en cualquier arma.     |
 | 21-03-99 [w] Se pasan por NotifyEquip las armas que llevas empuñadas  |
 |              cuando consigues el brazalete.                           |
 | 23-03-99 [w] Ahora es el gremio de las kisalas.                       |
 |              Añadido el comando 'telepatia' para que en el caso de que|
 |              la mascota tenga el mismo nombre de un jugador conectado |
 |              pueda hacerse referencia a ella con 'tel mascota'.       |
 | 24-03-99 [w] Si le dices que se esconda a la mascota deberás esperar  |
 |              2 minutos hasta que puedas volver a llamarla.            |
 | 27-03-99 [w] El tamaño del brazalete se establece en genérico.        |
 | 17-04-99 [w] Solucionado un pequeño problema que habia a la hora de   |
 |              comunicarse con la mascota, le faltaba un\n. De paso le |
 |              he bajado la chance cuando esquiva.                      |
 | 30-11-99 [w] Añadida una protección para el path.                     |
 | 12-12-99 [w] Ahora tiene el gquien y el ggritar. Ya pueden enseñar    |
 |              hechizos y esas cosas tan bonitas.                       |
 | 04-03-00 [w] La habilidad de Odio ahora la usan más a menudo pero con |
 |              más de la mitad de chance. Retocado el comando esquivar, |
 |              ahora esquivan algo menos.                               |
 | 21-03-00 [w] Capadas.. bastante.                                      |
 | 23-03-00 [w] Modificados los niveles de los conjuros                  |
 | 27-03-00 [w] Pues ahora ya no hay dos mascotas cuando mueren.         |
 | 07-06-00 [w] Ahora se autodestruye si abandona el cuerpo del pibe.    |
 | 25-04-03 [h] Con el nuevo sistema de combate me penco las actuales    |
 |		habilidades de combate de aqui				 |
 | 24-04-05 [s] Modifico algunas funciones para adaptarlas a las nuevas  |
 |              de las mascotas. De paso, retoco muchas cosas            |
 *=======================================================================*/


#include <properties.h>
#include <guild.h>
#include <gremios.h>
#include <skills.h>
#include <colours.h>
#include <combat.h>
#include <moving.h>
#include <config.h>
#include <wizlevels.h>
#include "./path.h"

inherit THING;
inherit G_GUILDOBJ;

//#define DEBUG 1 //[w] Descomentar solo en modo prueba.

/*
 ======================
   [w] VARIABLES
 ======================
*/
static object amazona;
static object mascota;
static string nombre_amazona;
static int tiempo_escondida;

string Mascota_raza;
string Mascota_nombre;
int    Mascota_sexo;
int    Mascota_nivel;
int    Mascota_edad;
int    Mascota_XP;
int    Mascota_HP;
int    Mascota_SP;
int    Mascota_sed;
int    Mascota_hambre;
int    Mascota_alcohol;
int    Mascota_coraje;
int    Mascota_modo;
int    Mascota_muertas;

/*
 ========================================
   [w] FUNCIONES SET, QUERY, ADD y HAS
 ========================================
*/

// salvar el nombre de la amazona
varargs string QuerySaveName(string appendix)
{
    string s;

    s = (nombre_amazona?lower_case(nombre_amazona):"nadie") + (appendix || "");
    return s=AMAZONA_SAVE(s);
}

// propietario del brazalete
object QueryObjectOwner() { return amazona; }

object SetObjectOwner(object jug)
{
    if (!jug || !query_once_interactive(jug)) return 0;
    nombre_amazona=jug->QueryRealName();
    return amazona=jug;
}

// función para comprobar si la amazona tiene cierta habilidad
int HasSkill(string hab) { return QueryObjectOwner()->HasSkill(hab); }

// descripción del brazalete
public string QueryLong()
{
    return ::QueryLong() + (TP == QueryObjectOwner()?
                            "Puedes usar el comando 'gayuda' para obtener "
                            "más datos acerca del gremio.\n":"");
}


// devuelve un título apropiado, dependiendo del nivel de la amazona
string QueryAmazonTitle()
{
    switch(TP->QueryGuildLevel())
    {
        case   0..3: return "la aprendiz de kisala";
        case   4..5: return "la pequeña kisala";
        case   6..7: return "la kisala";
        case   8..9: return "la kisala";
        case 10..11: return "la pequeña guerrera kisala";
        case 12..14: return "la guerrera kisala";
        case 15..17: return "la gran guerrera kisala";
        case 18..20: return "la arquera kisala";
        case 21..23: return "la certera arquera kisala";
        case 24..28: return "la pequeña hechicera kisala";
        case 29..33: return "la hechicera kisala";
        case 34..37: return "la gran hechicera kisala";
        case 38..43: return "la poderosa kisala";
        case 44..49: return "la princesa kisala";
        case     50: return "la diosa kisala";
        default: return "la kisala";
    }
    return "la amazona";
}
/*============================================================*
|  Funciones para el ajuste de las propiedades de la mascota  |
*============================================================*/

public object SetMascota(object animal) { return mascota=animal; }

public object QueryMascota() { return mascota; }

public int SetMascotaXP(int xp) { return Mascota_XP=xp; }

public int QueryMascotaXP() { return Mascota_XP; }

public int SetMascotaCoraje(int coraje) { return Mascota_coraje=coraje; }

public int QueryMascotaCoraje(){ return Mascota_coraje; }

public int SetMascotaMuertas(int muertas) { return Mascota_muertas=muertas; }

public int AddMascotaMuerta(int m) { return Mascota_muertas += m; }

public int QueryMascotaMuertas() { return Mascota_muertas; }

public int SetMascotaModo(int modo) { return Mascota_modo=modo; }

public int QueryMascotaModo() { return Mascota_modo; }

public int SetMascotaAlcohol(int alcohol) { return Mascota_alcohol=alcohol; }

public int QueryMascotaAlcohol() { return Mascota_alcohol; }

public int SetMascotaHambre(int hambre) { return Mascota_hambre=hambre; }

public int QueryMascotaHambre() { return Mascota_hambre; }

public int SetMascotaSed(int sed) { return Mascota_sed=sed; }

public int QueryMascotaSed() { return Mascota_sed; }

public int SetMascotaSP(int sp) { return Mascota_SP=sp; }

public int QueryMascotaSP() { return Mascota_SP; }

public int SetMascotaHP(int hp) { return Mascota_HP=hp; }

public int QueryMascotaHP() { return Mascota_HP; }

public int SetMascotaEdad(int edad) { return Mascota_edad=edad; }

public int QueryMascotaEdad() { return Mascota_edad; }

public int SetMascotaNivel(int nivel) { return Mascota_nivel=nivel || 1; }

public int QueryMascotaNivel() { return Mascota_nivel || 1; }

public int SetMascotaSexo(int sexo) { return Mascota_sexo=sexo || 1; }

public int QueryMascotaSexo() { return Mascota_sexo || 1; }

public string SetMascotaNombre(string nombre) { return Mascota_nombre=nombre; }

public string QueryMascotaNombre() { return Mascota_nombre; }

public string SetMascotaRaza(string raza) { return Mascota_raza=raza; }

public string QueryMascotaRaza() { return Mascota_raza; }

public int SetTiempoEscondida(int tiempo) { return tiempo_escondida=tiempo; }

public int QueryTiempoEscondida() { return tiempo_escondida; }

/*
 ======================
   [w] CREATE()
 ======================
*/

public void create()
{
    ::create();
    seteuid(getuid());
    SetShort("un brazalete");
    SetLong(W("Puedes ver un brazalete de plata con algunas piedras preciosas "
              "incrustadas de diversos colores. Con él quedas identificada "
              "ante otras kisalas y es un signo de lealtad y obediencia al "
              "gremio.\n"));
    SetMaterial(M_PLATA);
    SetSize(P_SIZE_GENERIC);
    SetUsage(EQM_WEAR);
    SetGuild("/guilds/kisalas/habitacion/gremio");
    if (TP)
    {
        SetObjectOwner(TP);
        if (   TP->QueryGuild()!=GC_KISALAS
            || TP->QueryGender()!=2) call_out("remove",1);
    }
    AddId(({"brazalete","brazalete del gremio de kisalas","brazalete de las "
            "kisalas"}));
    SetWeight(0);
    SetValue(0);
    Set(P_NOSELL,"Sería una ofensa para el gremio si lo vendieses.\n");
    Set(P_NOBUY);
    Set(P_NOGIVE);
    Set(P_NODROP);
    restore_object(QuerySaveName());
    if (clonep(TO)) // Comprobación para que no pueda ver dos veces las noticias.
    {
        if (file_size(AMAZONHOME+"NOTICIAS") > 0)
        {
            cat(AMAZONHOME+"NOTICIAS");
        }
    }
}


void autodest()
{
    destruct(TO);
    return;
}

/*
 ======================
   [w] INIT()
 ======================
*/

public void init()
{
    object ob;
    ::init();
    if (!TP) return;
    if (!(ob = environment()) || !query_once_interactive(ob))
    {
        call_out("autodest",2);
    }
    ob=QueryObjectOwner();
    if (ob && ob==TP)
    {
        Equip(ob, EWF_WEAPON | EWF_SILENT );
        add_action("cmd_estado","estado");
        add_action("cmd_gayuda","gayuda");
        add_action("cmd_salvar","salvar");
        add_action("cmd_silbar","silbar");
        add_action("cmd_telepatia","tel");
        add_action("cmd_telepatia","telepatia");
        add_action("cmd_hechizos","hechizos");
        add_action("cmd_conjuros","conjuros");
        add_action("cmd_quien","gquien");
        add_action("cmd_gshout","ggritar");
        add_action("cmd_gbug","gbug");
        add_false_cmds();
    }
}

/*
 ======================
   [w] OTRAS FUNCIONES
 ======================
*/

int Debug(string texto)
{
#ifndef DEBUG
    return 0;
#else
    LOG("DEBUG","> "+texto+"\n");
    return 1;
#endif
}

public int SaveMe()
{
    save_object(QuerySaveName());
    return 1;
}

public int remove()
{
    if(QueryObjectOwner()) SaveMe();
    return ::remove();
}

/*
 =============================
   [w] FUNCIONES PRINCIPALES
 =============================
*/

public varargs int LlamarMascota(int exterior)
{
    object animal;

    if (QueryMascota())
    { // si tiene una mascota cargada
        if (ENV(QueryMascota()) == ENV(TP))
        { // no está al lado de la amazona
            return notify_fail("Mira mejor porque tienes al lado a tu "
                               "mascota.\n",NOTIFY_NOT_VALID);
        }
        // se mueve a la habitación del amazona
        tell_room(environment(QueryMascota()),W(QueryMascotaNombre() + " se "
                                                "esconde y desaparece.\n"));
        QueryMascota()->move(environment(TP),M_SILENT);
        write(CAP(QueryMascotaNombre())+" llega a tu lado.\n");
        say(CAP(QueryMascotaNombre())+ " aparece y se coloca al lado de " +
            CAP(TNAME) + ".\n");
        return 1;
    }
    if (!QueryMascotaNombre())
    { // si no tiene mascota
        if (!exterior)
        { // la llamada no la hace el player diréctamente silbando
            return notify_fail("No tienes ninguna mascota.\n",
                               NOTIFY_NOT_VALID);
        }
        return notify_fail("Tu mascota no aparece.\n",NOTIFY_NOT_OBJ);
    }
    // sí que tienes una mascota, así que se intenta clonar
    if (!animal=clone_object(MASCOTA))
    { // por alguna razón no se ha podido clonar
        if (!exterior)
        { // la llamada la ha hehco silbando
            return notify_fail("Llamas a tu mascota pero no aparece.\n",
                               NOTIFY_NOT_OBJ);
        }
        return notify_fail("Tu mascota no aparece.\n",NOTIFY_NOT_OBJ);
    }
    // Lo primerisimo asignar amazona, porque si no el nivel maximo peta
    animal->SetAmazona(QueryObjectOwner());
    animal->SetStandard(QueryMascotaNombre(),QueryMascotaRaza(),([ GC_GUERREROS: QueryMascotaNivel()]),QueryMascotaSexo());
    animal->SetXP(QueryMascotaXP());
    animal->SetSP(QueryMascotaSP());
    animal->SetHP(QueryMascotaHP());
    animal->SetDrink(QueryMascotaSed());
    animal->SetFood(QueryMascotaHambre());
    animal->SetModo(QueryMascotaModo());
    animal->SetAlcohol(QueryMascotaAlcohol());
    animal->SetWhimpy(QueryMascotaCoraje());
    animal->AsignaBrazalete();
    animal->move(environment(TP),M_SILENT);
    if (!exterior)
    {
        write("Silbas fuerte.\n");
        say(CAP(TNAME) + " silba con todas sus fuerzas.\n");
    }
    write(CAP(QueryMascotaNombre())+" llega y se coloca a tu lado.\n");
    say(CAP(QueryMascotaNombre())+" aparece y se coloca al lado de "+
        CAP(TNAME) + ".\n");
    TP->AddFollower(animal);
    SetMascota(animal);
    return 1;
}

/*
 ======================
   [w] HABILIDADES
 ======================
*/
public varargs int UseSkill(string name, int chance, int percentage)
{
 int align;

 if (!name) return 0; // [w] Sin habilidad.. na de na.

// [w] Si el skill no es ninguno de las amazonas hace el UseSkill normal.
 if (member(HAB_KISALAS,name)==-1)
 {
   percentage=OWNER->UseSkill(name,chance);
   if (percentage>0) return 1;
   else return 0;
 }
 if (!HasSkill(name)) return 0; // [w] Si el jugador no posee esa habilidad, sale.

// [w] Si tu caracter es bueno tienes más oportunidad de realizar la habilidad
//     por el contrario si eres malo la oportunidad disminuye.
 align=OWNER->QueryAlign();
 if (align >= BUENO ) chance=chance+5;
 else if (align <= MUY_MALO) chance=chance-10;
 else if (align <= MALO) chance=chance-20;

 percentage=OWNER->UseSkill(name,chance);
 Debug("Skill: "+name+" Percentage: "+percentage+" Align: "+align+" Chance: "+chance);
 if (percentage>0) return 1;
 else return 0;
 return 0;
}


/*
 ======================
   [w] FUNCIONES DE
       ATAQUE Y DEFENSA
 ======================
*/

//Nyh: borrado TODO

/*
 ======================
   [w] COMANDOS 'CMD'
 ======================
*/

// devuelve una frase inicial para tu estado
int cmd_estado()
{
    string msg;

    if (TP->QueryGhost()) return 0;
    msg="Eres "TC_RED+CAP(TP->QueryRealName())+TC_NORMAL", ";
    msg+=TC_GREEN+QueryAmazonTitle()+TC_NORMAL+".\n";
    write(msg);
    return 0;
}

// ayuda sobre el gremio
int cmd_gayuda(string str)
{
    string s;

    if (!str)
    {
        s = "Escribe '"TC_BRIGHT"gayuda <tema>"TC_NORMAL"' para obtener más "
            "información.\nTemas disponibles:\n"
            "  "TC_GREEN"historia"TC_NORMAL"....... Historia de las kisalas.\n"
            "  "TC_GREEN"gremio"TC_NORMAL"......... Informacion genérica acerca "
            "del gremio.\n"
            "  "TC_GREEN"comandos"TC_NORMAL"....... Comandos especiales del "
            "gremio.\n"
            "  "TC_GREEN"magia"TC_NORMAL".......... Informacion acerca de la "
            "magia.\n"
            "  "TC_GREEN"mascotas"TC_NORMAL"....... Informacion acerca de las "
            "mascotas.\n"
            "  "TC_GREEN"habilidades"TC_NORMAL".... Informacion acerca de las "
            "distintas habilidades.\n"
            "  "TC_GREEN"hechizos"TC_NORMAL"....... Informacion acerca de los "
            "hechizos.\n";
        write(s);
        return 1;
    }
    s=AMAZONHOME+"ayuda/"+str;
    if(file_size(s)<=0)
    {
        return notify_fail("No existe información sobre ese tema.\n",
                           NOTIFY_NOT_VALID);
    }
    STR->smore(read_file(s));
    return 1;
}

// salvar estado
int cmd_salvar(string str)
{
    SaveMe();
    return 0;
}

// llamar a la mascota
int cmd_silbar(string str)
{
    if (!QueryMascotaNombre())
    {
        return notify_fail("No tienes ninguna mascota.\n",NOTIFY_NOT_VALID);
    }
    if (!tiempo_escondida) return LlamarMascota();
    if (tiempo_escondida<time()-120)
    {
        tiempo_escondida=0;
        return LlamarMascota();
    }
    return notify_fail("Tu mascota debe estar muy escondida, llámala más "
                       "tarde.\n",NOTIFY_NOT_VALID);
}

// Sustitución del comando tel ordinario para poder hablarle a la
// mascota
int cmd_telepatia(string str)
{
    string comando;
    if (!str ||str == "") return 0;
    if (   sscanf(str,"mascota %s",comando) == 1 && QueryMascota()
        || sscanf(str,QueryMascotaNombre() + " %s",comando) == 1)
    { // tiene mascota cargada, y el tel es para ella.
        if (!strstr(str,QueryMascotaNombre()) && find_object(lower_case(QueryMascotaNombre()))) return 0;
        QueryMascota()->EjecutaComando(comando);
        return 1;
    }
    return 0;
}

string nivel(int n)
{
  if (!n || n<0) return "desastroso";
  if (n>100) return "perfecto";
  switch (n) {
    case 0..4:   return "desastroso";
    case 5..9:   return "fatal";
    case 10..14: return "pésimo";
    case 15..19: return "muy mal";
    case 20..24: return "bastante mal";
    case 25..29: return "mal";
    case 30..39: return "regular";
    case 40..49: return "aceptable";
    case 50..54: return "adecuado";
    case 55..64: return "bueno";
    case 65..69: return "muy bueno";
    case 70..79: return "excelente";
    case 80..89: return "óptimo";
    case 90..98: return "casi perfecto";
    case 99..100: return "perfecto";
    default: return "desconocido";
  }
  return "desconocido";
}

string nivel_max(int n)
{
 if (!n) return "[Aprendiz]";
 if (n<=50) return "[Aprendiz]";
 if (n<=70) return "[Mago]";
 if (n>70) return "[Archimago]";
}

int cmd_hechizos(string w)
{
  mapping sp;
  mixed *idx;
  string p;
  int i;

  p="";

  sp=TP->QuerySpells();
  if (!sp || !sizeof(sp)) return notify_fail("No conoces ningún hechizo.\n");

  idx=m_indices(sp);
  for (i=0; i<sizeof(idx); i++)
    p+="  "+STR->ladjust(idx[i]+" ",25,".")+" "TC_GREEN+STR->ladjust(""+nivel((sp[idx[i],0]*100)/sp[idx[i],1])+TC_NORMAL" ",18,".")
        +" "+nivel_max(sp[idx[i],1])+"\n";

  seteuid(getuid(TP));
  if (p!="")
  {
    write(TC_BOLD"Hechizos que tienes memorizados:\n"TC_NORMAL);
    STR->smore(p,TP->QueryPageSize());
  }
  return 1;
}

int cmd_conjuros(string str)
{
 return write("Usa el comando 'hechizos'.\n"),1;
}

protected string who_list()
{
  object *obs;
  string msg;
  int i;

  LoadGuild();
  obs=guild_users();
  msg="";

  for (i=0; i<sizeof(obs); i++)
  {
    if (!obs[i]->Query(P_INVIS))
    {
      msg+="  "+capitalize(obs[i]->QueryRealName())+" "+obs[i]->QueryTitle();
      msg+=TC_GREEN" ["TC_NORMAL+capitalize(obs[i]->QueryRace()||"")+", "+obs[i]->QueryGuildLevel()+TC_GREEN"]"TC_NORMAL;
      if (QueryGuildObject()->is_creator(obs[i])) msg+=TC_CYAN" - Creador -\n"TC_NORMAL;
      else if (QueryGuildObject()->is_leader(obs[i])) msg+=TC_RED" - Líder -\n"TC_NORMAL;
      else msg+="\n";
    }
    else
    {
      if (IS_LEARNER(TP))
      {
        msg+="  ("+capitalize(obs[i]->QueryRealName())+")";
        msg+=TC_GREEN" ["TC_NORMAL+capitalize(obs[i]->QueryRace()||"")+", "+obs[i]->QueryGuildLevel()+TC_GREEN"]"TC_NORMAL;
        if (QueryGuildObject()->is_creator(obs[i])) msg+=TC_CYAN" - Creador -\n"TC_NORMAL;
        else if (QueryGuildObject()->is_leader(obs[i])) msg+=TC_RED" - Líder -\n"TC_NORMAL;
        else msg+="\n";
      }
    }
  }
  return msg;
}

public int cmd_quien(string arg)
{
  if (!TP) return 0;

  STR->smore(who_list(),TP->QueryPageSize());
  return 1;
}

