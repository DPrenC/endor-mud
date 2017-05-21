/**
 * ENDOR-MUD'/secure/login.c'


*/
#pragma no_inherit

#include <telnet.h>
#include "/secure/config.h"
#include "/secure/wizlevels.h"
#include <rtlimits.h>
#include <input_to.h>
#include <characters.h>
#include <colours.h>
#include <moving.h>
#include "/secure/udp.h"
#include <properties.h>
#include "/secure/userinfo.h"
#include <stdrooms.h>
#define MIN_OFFLINE_TIME     900
#define MIN_OFFLINE_TIME_MSG   "un cuarto de hora"
#define BLOQUE                16

// tipos de correo a enviar por login
#define SEND_AUTH_CODE            0
#define REGENERATE_PASSWORD       1

//------------------------------------------------------------------------------

private nosave string name, password, main_character, race, *races, races_str, email, auth_code;
private nosave string race_base, *humanos, *elfos, *orcos, *hobbits, *enanos, *altoshombres;
private nosave string humanos_str, elfos_str, hobbits_str, orcos_str, enanos_str, altoshombres_str;
private nosave string *lineas_normas, terminal;
private nosave int level, new_character, character_id, main_character_id, gender, authorized, send_manual, forwarded;
private nosave int num_linea, sounds, charset;
private nosave string trozo_normas, normas;
private nosave int checked_shut = 0;
private nosave int width = 80;
private nosave int height = 25;

//------------------------------------------------------------------------------

public int load_player_object();
public nomask void again_password(string str, string pw);
public int check_chars(string str);
public nomask void main_character(string main);
public nomask void main_character2(string password, string main_password, int i);
public nomask void save_new_character();

//-----------------------------------------------------------------------------

// Creo esta funcion para destruir el login y asegurarme de que no deja
// call_outs pendientes
private void _destruct_me() {
    while (remove_call_out("time_out") != -1);
    destruct(TO);
}

//-----------------------------------------------------------------------------


/* Devuelve 1 si se puede entrar en el Mud, sino devuelve 0 */
public int check_armageddon() {
  object arma;
  int min, hours, time_left;

  if (checked_shut++) return 1;
  if (!interactive(TO)) return 0;

  arma = find_object(SHUTDEMON);
  if (arma && arma->query_progress()) {
    time_left = arma->query_time_left();
    if (time_left < 60) {
      write("\nEl Mud esta siendo reseteado en este momento.\n"
             "Intentalo de nuevo en pocos minutos.\n\n");
      return 0;
    }
    hours = time_left / 3600;
    min = (time_left / 60) % 60;
    write(sprintf("\nATENCION: El Mud se reseteara en %d:%02d horas.\n"
          "Razon: %s\n\n"
         , hours, min, arma->query_reason()
         ));
  }
  return 1;
}

/* Intenta cargar el objeto de jugador */
public varargs void load_blueprint(string fname)
{
  object bp;

  if (!fname) fname = PLAYER;

  bp = find_object(fname);
  if (bp && environment(bp)) destruct(bp);
  if (!find_object(fname)) load_object(fname);
}

public void printwelcome() {
    if (interactive(TO)) {
        string *welcomes;
        welcomes = get_dir("/etc/welcome/WELCOME**");

        write(ANSI_BLUE+"\n\tProcedente del Vacío Exterior, más allá de los confines de Éa, "
        "desciendes sobre la faz de Arda...\n"+ANSI_NORMAL);
                write("\n\t"+ANSI_RED+ MUDNAME + " "+ANSI_YELLOW + MUDVERSION + " LDmud "+__VERSION__+"\n\n"+ANSI_NORMAL);
        cat("/etc/welcome/"+welcomes[random(sizeof(welcomes))]);
    }
    if (!check_armageddon()) {
        _destruct_me();
        return;
    }
}
// -----------------------------------------------------------------------------
// Funciones varias

// Convierte letras acentuadas en normales
public nomask string quita_acentos(string str)
{
    switch(str)
    {
        case "á": return "a"; break;
        case "é": return "e"; break;
        case "í": return "i"; break;
        case "ó": return "o"; break;
        case "ú": return "u"; break;
        case "Á": return "A"; break;
        case "É": return "e"; break;
        case "Í": return "I"; break;
        case "Ó": return "O"; break;
        case "Ú": return "U"; break;
        }
    return str;
}

// Comprueba si un jugador puede conectarse o no, dependiendo de
// las restricciones impuestas para que una persona física, entre con
// distintos jugadores de su propiedad, y el tiempo transcurrido entre las conexiones.
// Si <name> es el ultimo jugador con el que se desconectó, no hay restricciones.
// Si es otro de sus jugadores, y hace menos de 5 minutos que salió con el anterior, no se
// permite.
private int _can_connect()
{
  mixed *mix = MASTER->find_associated_characters(character_id, ORDER_LAST_TIME);
  if (!mix) return 1;
  if (!sizeof(filter(mix, (:$1[AR_LEVEL]:))))
  // ninguno de ellos es un wiz, así que, lo siento, hacemos comprobaciones
  {
    string *connected;
    string last_player;

    if (sizeof(connected = filter(mix, (:$1[AR_CONNECTED]:))))
    // multiplayer
    {
      write("\nEl multiplaying no está permitido en Endor-Mud, es desonesto y poco ético."
      " Te agradeceríamos corrigieses tu comportamiento.\n");
      log_file("MULTIPLAYING",
               sprintf("%-76=s", ctime() + ": " + name + " intentó entrar mientras " +
                                 connected[0] + " estaba en línea.\n"));

      return 0;
    }

    // comprobamos si puede entrar con este, según las restricciones de tiempo
        if (query_mud_port() != TEST_PORT && name != (last_player = mix[0][AR_NAME]))
    // No estamos en testing, y este no es el último con el que entró
    {
        int remaining, mins, segs;
      if ((remaining = time() - mix[0][AR_LAST_TIME]) < MIN_OFFLINE_TIME)
      // hace demasiado poco que se desconectó con su último jjugador
      {
        remaining = MIN_OFFLINE_TIME - remaining;
        mins = remaining / 60;
        segs = remaining % 60;
        write(sprintf("%-76=s", "\n¡Lo sentimos! Hace menos de " +
                                MIN_OFFLINE_TIME_MSG + " que te desconectaste con " +
                                CAP(last_player) +
                                ". Aunque con tu último jugador puedes entrar "
                                "consecutivamente sin restricciones, "
                                "para cambiar entre jugadores de tu propiedad deberás esperar un "
                                "mínimo de " + MIN_OFFLINE_TIME_MSG + ". Te quedan " +
                                mins + " minutos, " + segs + " segundos.\n\n"));
        return 0;
      }
    }
  }
  return 1;
}

/* Chequea que todos los caracteres sean validos*/
public int check_chars(string str) {
  int i;
  if (str && (i=strlen(str=lower_case(str)))) for (; i-- ;) {
    if (str[i] < 'a' || str[i] > 'z') {
      write("\nalgunos caracteres que has usado no son válidos, usa sólo letras.\n");
                  return 0;
    }
  }
  return 1;
}

/* Chequea si el nombre del jugador es valido, solo minusculas */
public int valid_name(string str) {
  int i, length;

  length = strlen(str);
  if (length > 11) {
    write("\nel nombre debe de tener de 3 a 11 letras.\n");
    return 0;
  }
  if (length < 3) {
    write("\nEl nombre debe de tener de 3 a 11 letras.\n");
    return 0;
  }
  if (!check_chars(str)) return 0;

  return 1;
}

public int valid_email(string mail)
{
    string user, domain, *extensions;
    string *invalid_domains = ({"mailinator.com", "mailinator2.com", "sogetthis.com",
        "mailin8r.com", "mailinator.net", "spamherelots.com", "thisisnotmyrealemail.com", });

    if (!sizeof(mail)) return 0;
    if (sscanf(mail, "%s@%s", user, domain) != 2) return 0;
    if (!user ||!sizeof(user) || !domain || !sizeof(domain)) return 0;
    // comprobamos que el usuario solo pueda contener letras de la a a la z, guiones normales, guiones bajos y el signo de punto (.)
#if __VERSION__ >= "3.3"
    if (!regmatch(user, "^[\\._-\\d\\w]+$")) return 0;
#else
    if (!sizeof(regexp(({user}), "^[._-a-zA-Z0-9]+$"))) return 0;
#endif
    // ahora vamos con el dominio
    extensions = explode(domain, ".");
    if (sizeof(extensions) == 1) return 0;
    if (member(invalid_domains, domain) >= 0) return -1;
#if __VERSION__ >= "3.3"
    if (!regmatch(extensions[0], "^[-_\\d\\w]+$")) return 0;
#else
    if (!sizeof(regexp(extensions[0..0], "^[-_a-zA-Z0-9]+$"))) return 0;
#endif
    if (!sizeof(filter(extensions[1..], lambda(({SYM(ext)}), ({SF(>), ({SF(strlen), SYM(ext)}), 1}))))) return 0;
    return 1;
}

private int valid_email_msg(string mail)
{
    int res = valid_email(mail);
    if (!res)
    {
        write(ANSI_RED+"\nEl correo electrónico que has escrito no es válido."+ANSI_NORMAL+"\n");
        return 0;
    }
    if (res == -1)
    {
        write(ANSI_RED+"\nNo podemos aceptarte esa dirección de correo que has indicado."+ANSI_NORMAL+
        "\nEs imprescindible que introduzcas los datos correctos para ponernos en "
        "contacto contigo cuando sea preciso, sobre todo para activar tu personaje.\n");
                return 0;
    }
    return 1;
}

/* Chequea si el nombre del jugador no está rechazado */
public int allowed_name(string str) {
  if (CHARMASTER->QueryValidName(str) == NICK_INVALID) {
    write("\nEse nombre consta en nuestra base de datos como un nick que no es aceptable para el mud. Introduce otro.\n");
        return 0;
  }
  return 1;
}

/* Chequea si el nombre está baneado */
public int banished_name(string str)
{
       if (!str ||str == "") return 0;
       if (CHARMASTER->QueryBanishedName(str) == NICK_BANISHED)
       {
              write("\n¡Ese nombre está baneado! Por favor, elige otro.\n");
              return 0;
       }
       return 1;
}

public string generate_auth_code()
{
        string cod = "", letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int sz, pos, longitud = 30;
    sz = sizeof(letras);

    while(longitud--)
    {
        cod += letras[(pos = random(sz<<5)>>5)..pos];
    }
    return cod;
}

/* Chequea si el nombre del jugador está libre */
public int free_name(string str) {
  if (MASTER->find_userinfo(str, 1)) {
    write("\nEse nombre ya existe, inténtalo con otro.\n");
    return 0;
  }
  return 1;
}

public string QueryShort()   { return (name || "<logon>")+" sin titulo"; }
public string QueryName()    { return name || "<logon>"; }
public string QueryRealName(){ return name || "<logon>"; }

public void negotiate(int cmd, int option, int *args) {
    if (cmd == SB) {
        if (option == TELOPT_NAWS) {
            width = args[0]<<8|args[1];
            height = args[2]<<8|args[3];
        }
    }
    else if (cmd == WONT) {
        if (option == TELOPT_NAWS) {
            width = 80;
            height = 25;
        }
    }
}


// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

// Funciones input_..., para evitar tener que poner tantas veces input_to con mensajes
// en caso de que el usuario no dé una entrada correcta o lo que sea
private void input_name()
{
    name = password = level = new_character = main_character = authorized = auth_code = email = 0;

    input_to("logon2", INPUT_PROMPT, "\n\nEscribe el nombre del personaje con el que quieres jugar.\n"
    "Si el nombre introducido no está registrado se iniciará la creación de un nuevo personaje.\n"
    "Cancelar si quieres desconectar.\n");
}

private void input_chk_password(int i)
{
    if (i <=1) input_to("check_password", INPUT_NOECHO|INPUT_PROMPT, "\nIntroduce la contraseña de tu personaje: ");
    else input_to("check_password2", INPUT_NOECHO | INPUT_PROMPT, "Introduce de nuevo la clave: ");
}

private void input_new_character()
{
    input_to("new_character", INPUT_PROMPT,
                            "\n \tIntroduce el nombre del personaje que quieres crear: ");
}

private void input_confirm_name()
{
    input_to("confirm_name", INPUT_PROMPT,
         "\nEscribe sí para aceptar las normas y continuar con la creación.\n"
         "Escribe atrás para volver al paso anterior.\n");
}

private void input_new_password()
{
    input_to("new_password", INPUT_NOECHO|INPUT_PROMPT, "\nEscribe la contraseña para tu personaje "+name+", la podrás cambiar en cualquier momento con el comando password.\n");
}

private void input_again_password(string str)
{
    input_to("again_password", INPUT_NOECHO|INPUT_PROMPT, "\nEscribe de nuevo la contraseña para confirmarlo: ", str);
}

private void input_main_character()
{
    input_to("main_character", INPUT_PROMPT,"Si este es tu primer personaje en el mud escribe "
             +name+ ", si no lo es escribe entonces el nombre de tu personaje principal: ");
}

private void input_main_character_password(string pass, int try)
{
    input_to("main_character2", INPUT_NOECHO | INPUT_PROMPT,
             "\nEscribe la clave del personaje '" + main_character + "' para confirmar.\n"
             "Clave de '" + main_character + "': ", pass, try);
}

private void input_email()
{
    input_to("enter_email", INPUT_PROMPT,
        "Dirección de correo electrónico o cancelar:\n ");
}
/*
private void input_send_manual()
{
    input_to("send_manual", INPUT_PROMPT,
             "\n¿Deseas que te enviemos un manual de juego por correo electronico? pulsa s, o n: ");
}
*/
private void input_race()
{
    input_to("choose_race", INPUT_PROMPT,
              "¿Qué raza base quieres para tu nuevo personaje <"+name+">?\n"
              "Escribe una de las razas del listado.\n  atrás para elegir otro nombre.\n  "
              "razas para volver a mostrar las razas.\n"
              "info <raza> para ver información sobre la raza especificada.\n");
}

private void input_variante_humano(){
                        input_to("choose_humano", INPUT_PROMPT,
  "Escribe la cultura que quieres para tu nuevo personaje humano.\n  atrás para elegir "
  "otra raza base.\n  culturas para ver el listado.\n"
  "info <cultura> para ver la información disponible sobre la cultura especificada.\n");
}

private void input_variante_elfo(){
                        input_to("choose_elfo", INPUT_PROMPT,
  "Elige la estirpe élfica a la que quieres pertenecer.\n  atrás para elegir "
  "otra raza base.\n  estirpes para ver el listado.\n"
  "info <estirpe> para ver información sobre la estirpe especificada.\n");
}

private void input_variante_orco(){
                        input_to("choose_orco", INPUT_PROMPT,
  "Escribe la subraza que quieres para tu nuevo personaje orco.\n  atrás para elegir "
  "otra raza base.\n  subrazas para ver el listado.\n"
  "info <subraza> para ver información sobre la subraza especificada.\n");
}

private void input_variante_hobbit(){
                        input_to("choose_hobbit", INPUT_PROMPT,
  "Escribe la variante de hobbit que quieres para tu personaje.\n  atrás para elegir "
  "otra raza base.\n  variantes para ver el listado.\n"
  "info <variante> para ver información sobre la variante especificada.\n");
}

private void input_variante_enano(){
                        input_to("choose_enano", INPUT_PROMPT,
  "Escribe el clan de enano que quieres para tu personaje.\n atrás para elegir "
  "otra raza base.\n  clanes para ver el listado.\n"
  "info <clan> para ver información sobre el clan especificado.\n");
}

private void input_variante_altohombre(){
                        input_to("choose_altohombre", INPUT_PROMPT,
  "escribe la civilización que quieres para tu personaje.\n  atrás para elegir "
  "otra raza base.\n  civilizaciones para ver el listado.\n"
  "info <civilización> para ver información sobre la civilización especificada.\n");
}

private void input_gender()
{
        input_to("choose_gender", INPUT_PROMPT,
             "\nElige el género de tu personaje:\n masculino, femenino o cancelar.\n");
}

private void input_sounds()
{
    input_to("set_sounds", INPUT_PROMPT,
        "En Endor-Mud tienes la posibilidad de jugar con sonidos en formato MP3 si "
        "tu cliente de muds lo soporta.\n ¿Quieres jugar con sonidos?. Escribe sí o no: ");
}

private void input_auth_code()
{
    input_to("enter_auth_code", INPUT_PROMPT,
             "\nCodigo de autorizacion (escribe reenviar para que te reenviemos el correo): ");
}
private void input_regenerate_password()
{
    input_to("regenerate_password", INPUT_PROMPT,
        "\nEscribe la direccion de correo electronico con la que diste de alta a " + CAP(name) + ": ");
}

// -----------------------------------------------------------------------------


// función que se ejecuta cuando se recibe una nueva conexión
public nomask int logon() {
  log_file("LOGIN",
            ctime()[4..15]+": "+query_ip_name(TO)+" : "+object_name(TO)+"\n");

  binary_message(({IAC, DO, TELOPT_NAWS}), 0);

  printwelcome();

  input_name();
  call_out("time_out", query_mud_port() == NORMAL_PORT ? 420 : 600);
  return 1; /* si todo va bien */
}

public void time_out() {
  if (interactive(TO)) write("\nSe te acabó el tiempo, vuelve cuando quieras.\n");
  _destruct_me();
}

#ifdef CLOSED_FOR_PLAYERS
public void sorry() {
    cat("/etc/SORRY");
    _destruct_me();
    return;
}
#endif

public nomask void logon2(string str) {
  object ob;
  int i, until;
  mixed *res, uinfo;

  if (!interactive(TO) || !check_armageddon() || !str || str == "") {
    _destruct_me();
    return;
  }
  str = lower_case(str);

  if (!check_chars(str)) {
    input_name();
    return;
  }
  if(str=="cancel" || str=="cancelar"){
input_to("salir", INPUT_PROMPT, ANSI_RED+"Abortando la creación de la ficha..."+ANSI_NORMAL+
"\nTe esperamos pronto por La Tierra Media.\n");
return;
}
  /* Checkea nombres baneados */
  if ((res = CHARMASTER->QueryBanishedName(str, CH_INFO))[CH_STATUS] == NICK_BANISHED) {
    write("\nLo sentimos, ese nombre está reservado o baneado " +
          (!(until = res[CH_INFO][N_BAN_UNTIL]) ? "por tiempo indefinido" :
          "hasta el " + STR->etime(1, ctime(until))) +
          ".\n\n");
    input_name();
    return;
  }

  /* Comprobamos si el nombre ha sido marcado como no válido */
  if (CHARMASTER->QueryValidName(str) == NICK_INVALID)
  {
    if (MASTER->find_userinfo(str, 1))
    // existe el personaje, así que lo borramos
    {
      load_object("/secure/remover")->remove_player(str, 1, 1);
    }
    write("\nLo sentimos, ese nombre no es válido.\n\n");
    input_name();
    return;
  }
  /* comprobamos si el personaje existe */
  if (!uinfo = MASTER->find_userinfo(str, 1))
  { /* El personaje no existe */
        if (   !valid_name(str = lower_case(str))
        || !free_name(str)
        || !allowed_name(str))
    {
        input_name();
        return;
    }
    new_character = 1;
    name = lower_case(str);
    password = "";
    level = 0;
        write("\nCreando una nueva ficha para el personaje <"+str+">.\n"
        "Si continúas con la creación de este nuevo personaje das por aceptadas las normas de Endor-Mud, que son:\n"
        " 1.- Respeto absoluto entre jugadores y hacia los administradores del mud.\n"
        "  2.- Es obligatorio la interpretación de un rol coherente con el mundo de Tolkien.\n"
        "  3.- El aprovechamiento de bugs o errores del juego será castigado según "
        "criterio de los administradores, mientras que notificación o ayuda para "
        "testearlos será premiado convenientemente.\n");
    input_confirm_name();
    return;
}


#ifdef CLOSED_FOR_PLAYERS
  if (uinfo[USER_LEVEL] < 10) {
    sorry();
    return;
  }
#endif

  /* el personaje existe y no esta baneado */
  write("\nSé bienvenido a Endor, viajero.\n"
  "Que los Valar tengan a bien guiar tus pasos.\n");
  name = uinfo[USER_NAME];
  level = uinfo[USER_LEVEL];
  character_id = uinfo[USER_ID];
  main_character_id = uinfo[USER_MAIN_CHARACTER];
  email = uinfo[USER_EMAIL];
  auth_code = uinfo[USER_AUTH_CODE];
  authorized = uinfo[USER_AUTHORIZED];
  if (!(password = uinfo[USER_PASSWORD]) || password == "")
  {
    write(ANSI_RED+"\nTu personaje no tiene contraseña."+ANSI_NORMAL+"\n");
    write("Puedes usar el comando password dentro del mud para ponerte una contraseña.\n\n");
    if (!_can_connect()) _destruct_me();
  }
  input_chk_password(1);
}


public nomask void new_character(string str)
{
    //string str2, msg;
    if (!str || "" == str) { _destruct_me(); return; }
    str = lower_case(str);
    if (   !valid_name(str = lower_case(str))
        || !free_name(str)
        || !allowed_name(str))
    {
        input_new_character();
        return;
    }
    new_character = 1;
    name = lower_case(str);
    password = "";
    level = 0;
    input_confirm_name();
    return;
}

public nomask void confirm_name(string str)
{
    str = lower_case(str||"");

    if(str == "" || (str!="s" && str!="n" && str!="si" && str!="sí" && str!="no" && str!="atras" && str!="atrás"))
    {
        write("\nEscribe sí o no.\n");
        input_confirm_name();
        return;
    }

    if (str=="n" || str=="no" || str=="atras" || str=="atrás")
    {
        input_name();
        return;
    }

    if (str=="s" || str=="si" || str=="sí")
    {
                races = RACEMASTER->RazasBase();
    races_str = implode(races[..<2], ", ") +
                 (sizeof(races[..<2]) ? " o " : "") + races[<1];
                write("\nElección de la raza base de tu personaje <"+name+">.\n "
                "Puedes elegir de las siguientes razas:\n" +
              sprintf("%-76=s", races_str) + "\n");
            input_race();
        return;
    }
    return;
}

//----------------------------------------------------------------------------
//Nuevo personaje -> Nueva clave
public nomask void new_password(string str)
{
    if (!str || str == "")
    {
        write("\nDebes introducir una clave.\n");
        input_new_password();
        return;
    }
    if (strlen(str) < 6 || strlen(str) > 20)
    {
        write(ANSI_RED+"\nLa contraseña debe tener de 6 a 20 caracteres."+ANSI_NORMAL+"\n");
        input_new_password();
        return;
    }
    if (!sizeof(regexp(({str}), "^[-_a-zA-Z0-9]*$")))
    {
        write("\nLa clave no puede contener caracteres extranyos: solo letras,\n"
            "numeros, y el caracter de guion (-) y guion bajo (_).\n");
        input_new_password();
        return;
    }
    input_again_password(str);
    return;
}

public nomask void again_password(string str, string pw)
{
    if (str != pw)
    {
        write(ANSI_RED+"\n¡Las contraseñas no coinciden!"+ANSI_NORMAL+"\n");
        input_new_password();
        return;
    }
    password = crypt(pw, 0);

    // ahora ajustamos el personaje principal:
    write("\nIntroduce el nombre de tu personaje principal.\n Si todavía no tienes "
    "ningún personaje en Endor-Mud entonces tu personaje principal debe de ser "+name+
    ".\n"+ANSI_RED+"Debes de tener tan solo un personaje principal.\n"+ANSI_NORMAL);

    input_main_character();
    return;
}

public nomask void main_character(string main)
{
    mixed *uinfo;

    if (!sizeof(main))
    {
        write("\nIntroduce el nombre de tu personaje principal.\n");
        input_main_character();
        return;
    }
    if (main == "n")
    // iniciamos sesión con otro personaje
    {
        input_name();
        return;
    }


    if (main == name)
    {
        write("\nSe ha establecido a "+name+" como tu personaje principal.\n");
        main_character = main;
        main_character_id = character_id;
        if (new_character)
        {
            write("Necesitamos tu e-mail. Sólo lo usaremos para activar el personaje y "
            "verificar tu identidad antes de abandonar el proceso de aprendizaje"
            " (imprescindible).\n\n");
                              input_email();
            return;
        }
        MASTER->update_main_character(character_id, main_character_id);
        if (!new_character && !_can_connect()) _destruct_me();
        else load_player_object();
        return;
    }
    if (!uinfo = MASTER->find_userinfo(main, 1))
    {
        write("\n¡Ese personaje no existe!\n");
        input_main_character();
        return;
    }
    if (uinfo[USER_ID] != uinfo[USER_MAIN_CHARACTER])
    // no se puede asociar un personaje secundario a otro personaje secundario
    {
        write(ANSI_RED+"\n¡Sólo puedes tener un personaje principal!\n"+ANSI_NORMAL);
        input_main_character();
        return;
    }
    if (!uinfo[USER_AUTHORIZED])
    {
        write("\n¡Ese personaje aun no ha sido autorizado!\n"
              "Si lo deseas, puedes iniciar sesion con el para autorizarlo.\n");
        input_name();
        return;
    }
    main_character = main;
    main_character_id = uinfo[USER_ID];
    email = uinfo[USER_EMAIL];
    authorized = 1;
    // como es un personaje secundario, se autoriza automáticamente.
    input_main_character_password(uinfo[USER_PASSWORD], 1);
    return;
}

public nomask void main_character2(string password, string main_password, int i)
{
    mixed *info;

    if (!((main_password == "" && password == "") || (main_password == crypt(password, main_password))))
    // no es la contraseña correcta
    {
        if (i == 2)
        // se superó el número de intentos
        {
            write("\nHas fallado otra vez!\n");
            _destruct_me();
            return;
        }
        write("\n¡Clave erronea! Intentalo de nuevo.\n");
        input_main_character_password(main_password, 2);
        return;
    }
    // es la contraseña correcta, así que, seguimos
    if ((info = CHARMASTER->QueryBanishedEmail(email, CH_INFO))[CH_STATUS] == EMAIL_BANISHED)
    {
        write("\nLo sentimos, ese e-mail esta baneado" +
            (info[CH_INFO][E_BAN_UNTIL] ? " hasta el " + STR->etime(1, ctime(info[CH_INFO][E_BAN_UNTIL])) : "") +
            ".\n");
        input_to("salir", INPUT_PROMPT, "\nPulsa enter para salir.\n");
        return;
    }

    write("\nHa sido establecido a "+main_character+" como tu personaje principal.\n\n");

    if (new_character)
    {

        input_sounds();
        return;
    }
    MASTER->update_main_character(character_id, main_character_id);
    authorized=1;
    DBMASTER->Exec("update characters set authorized=1 where id=" + character_id);
    if (!new_character && !_can_connect()) _destruct_me();
    else load_player_object();
}


private int send_mail(int type)
{
    switch(type)
    {
    case SEND_AUTH_CODE:
        return send_server_request("SendAuthCode", character_id, (find_savefile(name) ? 0 : 1), send_manual);
        break;
    case REGENERATE_PASSWORD:
        return send_server_request("RegeneratePassword", character_id);
        break;
    }
    return 0;
}


public nomask void enter_email(string str)
{
        if(str=="cancel" || str=="cancelar"){
input_to("salir", INPUT_PROMPT,ANSI_RED+"\nAbortando la creación de la ficha..."+ANSI_NORMAL+
"\nTe esperamos pronto por La Tierra Media.\n Pulsa enter.\n");
return;}
    if (!str ||str == "")
    {
        write("\nEscribe una dirección de correo electrónico o cancelar.\n");
        input_email();
        return;
    }
    if (!valid_email_msg(str))
    {
        input_email();
        return;
    }
    email = str;
    input_to("enter_email2", INPUT_PROMPT,
        "\nEscribe de nuevo tu dirección de correo electrónico:\n", str);
    return;
}


public nomask void enter_email2(string str, string stremail)
{
    mixed *info;
    if (str != stremail)
    {
        write(ANSI_RED+"\n¡La direccion de e-mail y la confirmación no coinciden!"+ANSI_NORMAL+"\n");
        input_email();
        return;
    }
    if ((info = CHARMASTER->QueryBanishedEmail(email, CH_INFO))[CH_STATUS] == EMAIL_BANISHED)
    {
        write("\nLo sentimos, ese e-mail esta baneado" +
            (info[CH_INFO][E_BAN_UNTIL] ? " hasta el " + STR->etime(1, ctime(info[CH_INFO][E_BAN_UNTIL])) : "") +
            ".\n");
        input_email();
        return;
    }

    if (MASTER->mail_exists(email))
    {
        write("\nLa dirección de correo introducida ya está en nuestra base de "
        "datos asociada a otro personaje. Este nuevo personaje debería de ser personaje secundario del otro.\n");
                input_email();
        return;
    }

    auth_code = generate_auth_code();

    if (new_character)
    {
              input_sounds();
        return;
    }
    if (!new_character && !_can_connect()) _destruct_me();

    DBMASTER->Exec("update characters set auth_code='" + auth_code + "', email='" + email + "' "
                   "where id=" + character_id);
    /*if (!send_mail(SEND_AUTH_CODE))
    {
        write("\n¡Error al enviar el correo electronico! Por favor, contacta con un wizard.\n");
        _destruct_me();
        return;
    }
    write("\n¡Atencion! Se ha enviado un e-mail a la direccion de correo " +
          "\n" + email + ".\nEn el se te informa del codigo de autorizacion que deberas\n"
          "introducir para activar tu personaje. Si en un plazo de 20 minutos\n"
          "no lo has recibido, vuelve a iniciar sesion, y en el paso en el que tienes\n"
          "que introducir el codigo de autorizacion, escribe reenviar.\n");
          */
    load_player_object();
}
/*
public nomask void send_manual(string str)
{
    if (!str || (str = LOWER(str)) == "" || (str != "s" && str != "n"))
    {
        write("\nDebes pulsar s, o n.\n");
        input_send_manual();
        return;
    }
    if (str == "s")
    {
        write("\nDe acuerdo. En el correo en el que te enviemos el codigo de autorizacion,\n"
              "se te adjuntara un manual sobre Simauria.\n");
        send_manual = 1;
    }
    else
    {
        send_manual = 0;
    }
    input_sounds();
    return;
}
*/
public nomask void choose_race(string str)
{
    string razainfo;

    if(!sizeof(str))
    {
        write("\nSelecciona una de las razas base del listado.\n");
        input_race();
        return;
    }
    str = LOWER(str);
    if (str == "razas")
    {
        write("\nLas razas base de La Tierra Media son:\n" + sprintf("%-76=s", races_str) + "\n");
        input_race();
        return;
    }
    if(str=="atras" || str=="atrás"){
        input_name();
     return;
    }
/*la info de cada raza y subraza.*/
    if (sscanf(str, "info %s", razainfo) == 1)
            // está pidiendo info
    {
                if (member(races, razainfo) < 0)
        {
            write("\nNoestá disponible la información solicitada.\n");
            input_race();
            return;
        }
        write("\n"+ RACEMASTER->RaceDescr(razainfo) + "\n");
        input_race();
        return;
    }
    /**/
        if (member(races, str) < 0)
    {
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_race();
        return;
    }
    race_base = str;
     switch(race_base){
        case "humano":
            humanos = RACEMASTER->RazasHumanos();
    humanos_str = implode(humanos[..<2], ", ") +
                 (sizeof(humanos[..<2]) ? " o " : "") + humanos[<1];
                write("\n¿Qué cultura de los hombres quieres para <"+name+">?\n "
                "  Elije de la siguiente lista:\n" +
              sprintf("%-76=s", humanos_str) + "\n");
            input_variante_humano();
break;
case "elfo":
            elfos = RACEMASTER->RazasElfos();
    elfos_str = implode(elfos[..<2], ", ") +
                 (sizeof(elfos[..<2]) ? " o " : "") + elfos[<1];
                write("\n¿Qué variante de la estirpe élfica quieres para <"+name+">?\n "
                "  Elije de la siguiente lista:\n" +
              sprintf("%-76=s", elfos_str) + "\n");
            input_variante_elfo();
break;
case "orco":
            orcos = RACEMASTER->RazasOrcos();
    orcos_str = implode(orcos[..<2], ", ") +
                 (sizeof(orcos[..<2]) ? " o " : "") + orcos[<1];
                write("\n¿Qué subraza de los orcos quieres para <"+name+">?\n "
                "  Elije de la siguiente lista:\n" +
              sprintf("%-76=s", orcos_str) + "\n");
            input_variante_orco();
break;
case "hobbit":
            hobbits = RACEMASTER->RazasHobbits();
    hobbits_str = implode(hobbits[..<2], ", ") +
                 (sizeof(hobbits[..<2]) ? " o " : "") + hobbits[<1];
                write("\n¿Qué variante de los hobbits quieres para <"+name+">?\n "
                "  Elije de la siguiente lista:\n" +
              sprintf("%-76=s", hobbits_str) + "\n");
            input_variante_hobbit();
break;
case "enano":
            enanos = RACEMASTER->RazasEnanos();
    enanos_str = implode(enanos[..<2], ", ") +
                 (sizeof(enanos[..<2]) ? " o " : "") + enanos[<1];
                write("\n¿Qué clan de los enanos quieres para <"+name+">?\n "
                "  Elije de la siguiente lista:\n" +
              sprintf("%-76=s", enanos_str) + "\n");
            input_variante_enano();
break;
        case "alto-hombre":
            altoshombres = RACEMASTER->RazasAltosHombres();
    altoshombres_str = implode(altoshombres[..<2], ", ") +
                 (sizeof(altoshombres[..<2]) ? " o " : "") + altoshombres[<1];
                write("\n¿Qué civilización quieres para <"+name+">?\n "
                "  Elije de la siguiente lista:\n" +
              sprintf("%-76=s", altoshombres_str) + "\n");
            input_variante_altohombre();
break;

}
        return;
}

public nomask void choose_humano(string str)
{
    string infocultura;
    if(!sizeof(str))
    {
        write("\nElije para tu personaje humano una cultura de la lista.\n");
        input_variante_humano();
        return;
    }
    str = LOWER(str);
    if (str == "culturas")
    {
        write("\nLas distintas culturas de hombres que puedes elegir son:\n" + sprintf("%-76=s", humanos_str) + ": ");
        input_variante_humano();
        return;
    }
    if(str=="atras" || str=="atrás"){
        input_race();
     return;
    }
        if (sscanf(str, "info %s", infocultura) == 1)
    // está pidiendo info
    {
        if (member(humanos, infocultura) < 0)
        {
            write("\nNoestá disponible la información solicitada.\n");
            input_variante_humano();
            return;
        }
        write("\n"+ RACEMASTER->RaceDescr(infocultura) + "\n");
        input_variante_humano();
        return;
    }

if (member(humanos, str) < 0)
    {
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_variante_humano();
        return;
    }
    race = str;
input_gender();
    return;
}

public nomask void choose_elfo(string str)
{
    string infoelfo;
    if(!sizeof(str))
    {
        write("\nElije para tu personaje elfo una estirpe de la lista.\n");
        input_variante_elfo();
        return;
    }
    str = LOWER(str);
    if (str == "estirpes")
    {
        write("\nLas distintas estirpes élficas que puedes elegir son:\n" + sprintf("%-76=s", elfos_str) + ": ");
        input_variante_elfo();
        return;
    }
    if(str=="atras" || str=="atrás"){
        input_race();
     return;
    }
        if (sscanf(str, "info %s", infoelfo) == 1)
    // está pidiendo info
    {
        if (member(elfos, infoelfo) < 0)
        {
            write("\nNoestá disponible la información solicitada.\n");
            input_variante_elfo();
            return;
        }
        write("\n"+ RACEMASTER->RaceDescr(infoelfo) + "\n");
        input_variante_elfo();
        return;
    }

if (member(elfos, str) < 0)
    {
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_variante_elfo();
        return;
    }
    race = str;
input_gender();
    return;
}

public nomask void choose_orco(string str)
{
    string infoorco;
    if(!sizeof(str))
    {
        write("\nElije para tu personaje orco una subraza de la lista.\n");
        input_variante_orco();
        return;
    }
    str = LOWER(str);
    if (str == "subrazas")
    {
        write("\nLas distintas subrazas de orcos que puedes elegir son:\n" + sprintf("%-76=s", orcos_str) + ": ");
        input_variante_orco();
        return;
    }
    if(str=="atras" || str=="atrás"){
        input_race();
     return;
    }
        if (sscanf(str, "info %s", infoorco) == 1)
    // está pidiendo info
    {
        if (member(orcos, infoorco) < 0)
        {
            write("\nNoestá disponible la información solicitada.\n");
            input_variante_orco();
            return;
        }
        write("\n"+ RACEMASTER->RaceDescr(infoorco) + "\n");
        input_variante_orco();
        return;
    }

if (member(orcos, str) < 0)
    {
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_variante_orco();
        return;
    }
    race = str;
    write("Por mera elección de Ilúbatar la raza orco sólo pueden ser del género masculino.\n");
    gender = 1;
    input_new_password();

    return;
}

public nomask void choose_hobbit(string str)
{
   string infohobbit;
    if(!sizeof(str))
    {
        write("\nElije para tu personaje hobbit una variante de la lista.\n");
        input_variante_hobbit();
        return;
    }
    str = LOWER(str);
    if (str == "variantes")
    {
        write("\Las distintas variantes de hobbits que puedes elegir son:\n" + sprintf("%-76=s", hobbits_str) + ": ");
        input_variante_hobbit();
        return;
    }
    if(str=="atras" || str=="atrás"){
        input_race();
     return;
    }

if (sscanf(str, "info %s", infohobbit) == 1)
    // está pidiendo info
    {
        if (member(hobbits, infohobbit) < 0)
        {
            write("\nNoestá disponible la información solicitada.\n");
            input_variante_hobbit();
            return;
        }
        write("\n"+ RACEMASTER->RaceDescr(infohobbit) + "\n");
        input_variante_hobbit();
        return;
    }

if (member(hobbits, str) < 0)
    {
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_variante_hobbit();
        return;
    }
    race = str;
input_gender();
    return;
}

public nomask void choose_enano(string str)
{
    string infoenano;
    if(!sizeof(str))
    {
        write("\nElije para tu personaje enano un clan de la lista.\n");
        input_variante_enano();
        return;
    }
    str = LOWER(str);
    if (str == "clanes")
    {
        write("\nLos distintos clanes de enanos que puedes elegir son:\n" + sprintf("%-76=s", enanos_str) + ": ");
        input_variante_enano();
        return;
    }
    if(str=="atras" || str=="atrás"){
        input_race();
     return;
    }

    if (sscanf(str, "info %s", infoenano) == 1)
    // está pidiendo info
    {
        if (member(enanos, infoenano) < 0)
        {
            write("\nNoestá disponible la información solicitada.\n");
            input_variante_enano();
            return;
        }
        write("\n"+ RACEMASTER->RaceDescr(infoenano) + "\n");
        input_variante_enano();
        return;
    }

if (member(enanos, str) < 0)
    {
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_variante_enano();
        return;
    }
    race = str;
input_gender();
    return;
}

public nomask void choose_altohombre(string str)
{
    string infoaltohombre;
    if(!sizeof(str))
    {
        write("\nElije para tu personaje una civilización de la lista.\n");
        input_variante_altohombre();
        return;
    }
    str = LOWER(str);
    if (str == "civilizaciones")
    {
        write("\nLas distintas culturas de los altos hombres que puedes elegir son:\n" + sprintf("%-76=s", altoshombres_str) + ": ");
        input_variante_altohombre();
        return;
    }
    if(str=="atras" || str=="atrás"){
        input_race();
     return;
    }

    if (sscanf(str, "info %s", infoaltohombre) == 1)
    // está pidiendo info
    {
        if (member(altoshombres, infoaltohombre) < 0)
        {
            write("\nNoestá disponible la información solicitada.\n");
            input_variante_altohombre();
            return;
        }
        write("\n"+ RACEMASTER->RaceDescr(infoaltohombre) + "\n");
        input_variante_altohombre();
        return;
    }

if (member(altoshombres, str) < 0)
    {
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_variante_altohombre();
        return;
    }
    race = str;
input_gender();
    return;
}

public nomask void choose_gender(string str)
{
    if (!str || str == "")
    {
        write("\nEscribe masculino o femenino.\n");
        input_gender();
        return;
    }

            if (member(({"cancel", "cancelar", "masculino", "masc", "m", "ma", "femenino", "fem", "fe", "f"}), str) < 0)
    // no es ni masculino ni femenino
    {
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_gender();
        return;
    }
    if(str=="cancel" || str=="cancelar"){
input_to("salir", INPUT_PROMPT, "\nAbortando la creación de la ficha...\n Te esperamos pronto por La Tierra Media.\n Pulsa enter.\n");
}
    if (member(({"f", "fem", "fe", "femenino"}), str) >= 0) gender = 2;
    else gender = 1;
input_new_password();
}

public nomask void set_sounds(string str)
{
    if (!str || member(({"cancel", "cancelar", "s", "si", "sí", "n", "no"}), (str = LOWER(str))) < 0)
    {
        write(ANSI_RED+"\n sí, no o cancelar."+ANSI_NORMAL+"\n");
        input_sounds();
        return;
    }
    if(str=="cancel" || str=="cancelar"){
input_to("salir", INPUT_PROMPT, ANSI_RED+"Abortando la creación de la ficha..."+ANSI_NORMAL+
"\nTe esperamos pronto por La Tierra Media.\n");
return;
}
    if (str == "n" || str == "no") sounds = 0;
    else sounds = 1;
    input_to("desconectar", INPUT_PROMPT, "\n\n"+ANSI_PURPLE+"¡Ficha creada!"+ANSI_NORMAL+
        "\nPulsa enter para salir y ajustar los parámetros.\n Vuelve a conectar con "
        "los datos de tu nuevo personaje "+ANSI_PURPLE+race+" "+name+ANSI_NORMAL+".\n");
        }
public nomask void desconectar()
{
    save_new_character();
    load_player_object();
}
public nomask void save_new_character()
{
    object ob;

    DBMASTER->Exec("insert into characters values(default, '" + name + "', '" + password + "', 0, " +
                   time() + ", 0, null, " + (main_character_id ? main_character_id : "null") +
                   ", " + time() + ", '" + email + "', '" + auth_code + "', " + 1 /* authorized*/ + ")");
    character_id = DBMASTER->InsertId();
    if (!main_character_id)
    {
        main_character_id = character_id;
        DBMASTER->Exec("update characters set main_character=" + main_character_id + " where id=" +
                       main_character_id);
    }
    CHARMASTER->AddPendingName(LOWER(name));
    /*if (!send_mail(SEND_AUTH_CODE))
    {
        write("\n¡Error al enviar el correo electronico! Por favor, contacta con un wizard!\n");
    }*/
    seteuid(name);

    /* carga el objeto player 'real' */
    load_blueprint(PLAYER);

    /* clona el objeto player */
    ob = clone_object(PLAYER);

    if (!ob)
    {
        log_file("LOGIN",sprintf("              Error: Can't clone %O. Login aborted!\n", PLAYER));
        write("Error al cargar "+PLAYER+"\n");
        _destruct_me();
        return;
    }
    log_file("LOGIN",sprintf("              rename_object(%O, %O)\n", ob, name));
    rename_object(ob, name);

    exec(ob, TO);
    ob->SetName(capitalize(name));
    ob->SetGender(gender);
        ob->SetCharset(EXTENDED);
                ob->SetTTY("ansi");
    ob->SetSounds(sounds);
    ob->SetMusic(sounds);
    ob->SetSoundEnvironment(sounds);
    ob->SetGhost(0);
    ob->SetRazabase(race_base);
    RACEMASTER->InitRace(ob, race);
    RACEMASTER->AdjustStats(ob);
                                ob->move(AJUSTES, M_SILENT);
    ob->SetTitle("Hijo de Ilúvatar");
    ob->SetMMsgIn("aparece de repente");
    ob->SetMMsgOut("desaparece");
    ob->SetCombateBreve(1);
    ob->SetColorAtaco(TC_BLUE);
    ob->SetColorAtacado(TC_PURPLE);
    ob->SetColorAjeno(TC_YELLOW);
    ob->save();
            ob->remove();
}

public nomask void update_main_character()
{
    load_player_object();
}

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//Viejo personaje -> Comprobar clave
public nomask void check_password(string str) {
   object ob;
   if (crypt(str, password) == password) {
     if (   ((ob = find_object(name)) && query_once_interactive(ob) && getuid(ob) == name)
         || _can_connect())
     {
       load_player_object();
     }
     else _destruct_me();
     return;
   }
   if (LOWER(str) == "regenerar")
   {
     input_regenerate_password();
     return;
   }
   input_to("check_password2", INPUT_NOECHO|INPUT_PROMPT, ANSI_RED+"\n¡Contraseña incorrecta!"+ANSI_NORMAL+"\n"
            "Tienes otro intento más: ");
   return;
}

public nomask void check_password2(string str) {
   object ob;
   if (crypt(str, password) == password) {
     if (   ((ob = find_object(name)) && query_once_interactive(ob) && getuid(ob) == name)
         || _can_connect())
     {
       load_player_object();
       return;
     }
     else
     {
       _destruct_me();
       return;
     }
   }
   if (LOWER(str) == "regenerar")
   {
     if (!email)
     {
       write(sprintf("%-76=s", "\nEste personaje no tiene una direccion de correo asociada a la que enviar "
             "el correo de regeneracion de contrasenya. Lo sentimos.\n"));
       _destruct_me();
       return;
     }
     input_regenerate_password();
     return;
   }
   write(ANSI_RED+"\n¡Era tu último intento!"+ANSI_NORMAL+"\n");
   _destruct_me();
   return;
}

public nomask regenerate_password(string email_str)
{
    if (!email || email == "")
    {
        write("\nDebes introducir una direccion de correo.\n");
        input_regenerate_password();
    }
    if (email_str != email)
    {
        write("\nEl e-mail introducido no es correcto.\n");
        _destruct_me();
        return;
    }
    if (!send_mail(REGENERATE_PASSWORD))
    {
        write("\nError al enviar el correo de regeneracion de tu contrasenya. Por favor,\n"
              "ponte en contacto con un wizard.\n");
        _destruct_me();
        return;
    }
    write(sprintf("%76=s", "\nDe acuerdo. Se te ha enviado un correo a " + email + ", con un "
                  "vinculo que deberas seguir para regenerar tu contrasenya.\n"
          "Pulsa enter para salir.\n"));
    input_to("salir");
}

public nomask void salir()
{
    write("\n\nDesconectando...\n");
    _destruct_me();
}
//----------------------------------------------------------------------------

// Carga el jugador(simauria)
public int load_player_object() {
    string obname;
    object ob, ob2;
    mixed tmp, uinfo;

    if (!main_character_id)
    // Es una ficha creada antes de esta versión, así que no tiene asociado personaje
    // principal.
    {
        write(ANSI_RED+"\nEste personaje no está registrado ni como personaje principal ni secundario."+ANSI_NORMAL+
        "\nSi este personaje tiene que ser tu personaje principal, entonces escribe "+name+
        ", si no escribe el nombre del personaje que quieres como personaje principal.\n"
        "Si escribes simplemente n podrás iniciar sesión con otro personaje.\n");

        input_main_character();
        return 0;
    }
    if (character_id != main_character_id && (uinfo = MASTER->find_userinfo(main_character_id)) && !uinfo[USER_AUTHORIZED])
    {
        write("\n¡Atencion! Tu personaje principal (" + CAP(uinfo[USER_NAME]) + "), no ha sido\n"
            "autorizado aun. Si lo deseas, puedes iniciar sesion con ese personaje para activarlo.\n");
        input_name();
        return 0;
    }
    if (!email)
    {
write("\nEs imprescindible que introduzcas una dirección de correo válida: ");
        input_email();
        return 0;
    }

         if (!authorized)
    // aún no está autorizado
    {
        write("\nEste personaje no ha sido activado aun. Para activarlo, debes introducir\n"
              "el codigo que te hemos enviado a la direccion de correo que nos has especificado.\n"
              "Si tras 20 minutos de haber introducido tu dirección, no te ha llegado el\n"
              "correo con el codigo de activacion, escribe reenviar.\n");
        input_auth_code();
        return 0;
    }

    /* Chequea si estamos jugando en estos momentos */
    seteuid(name);
    ob = find_object(name);

    if (ob && ob->QueryIsPlayer() && getuid(ob)==name) {
        tell_object(ob, "Recibiendo una nueva conexión desde "+query_ip_name(TO)+" ("+query_ip_number()+")\n");

        ob->SetConsoleWidth(width);
        ob->SetConsoleHeight(height);

        write("\nTu cuerpo ya estaba vagando por La Tierra Media.\n"
              "Transportándote de nuevo a tu esencia corporal...\n");
        if (interactive(ob)) remove_interactive(ob);
        /* Reconecta el viejo cuerpo */
        exec(ob, TO);
        log_file("LOGIN",sprintf("              %O->restart_player(%O)\n", ob, name));
        ob->restart_player(name);
        if (call_resolved(&tmp, ob, "QueryPlayerStarted") && !tmp) {
           log_file("LOGIN",sprintf("              %O->start_player(%O)\n", ob, name));
            ob->start_player(name);
        }
        log_file("LOGIN",sprintf("              Login completed!\n", ob));
                _destruct_me();
        return 1;
    }

  /* Carga el archivo del jugador que corresponda */
  if (level >= 10) obname = "std/wizard";
  else obname = "std/player";

  /* solo wizs! */
  if (level > 0) write(object_name(TO)+": Conectado a "+obname+"...\n");

  /* carga el objeto player 'real' */
  load_blueprint(obname);

  /* clona el objeto player */
  ob = clone_object(obname);

  if (!ob) {
    log_file("LOGIN",sprintf("              Error: Can't clone %O. Login aborted!\n", obname));
    write("Error al cargar "+obname+"\n");
    _destruct_me();
    return 1;
  }

  if (ob2 = find_object(name)) {
    log_file("LOGIN",sprintf("              Still exists find_object(%O) = %O\n", name, ob2));
    destruct(ob2);
  }

  rename_object(ob, name);

  if (level >= 10) set_is_wizard(ob, 1);

  exec(ob, TO);
  log_file("LOGIN",sprintf("              %O->start_player(%O)\n", ob, name));
  limited(symbol_function("start_player", ob), ({ LIMIT_UNLIMITED }), name);

  ob->SetConsoleWidth(width);
  ob->SetConsoleHeight(height);
  log_file("LOGIN",sprintf("              Login completed!\n", ob));
  _destruct_me();
  return 1;
}

public void enter_auth_code(string str)
{
    if (!str ||str == "")
    {
        write("\nDebes introducir el codigo de autorizacion.\n");
        input_auth_code();
        return;
    }
    if (str == "reenviar")
    {
        if (forwarded)
        {
            write("\nYa te hemos reenviado el código. Por favor. Espera unos minutos.\n");
            input_auth_code();
            return;
        }
        if (!send_mail(SEND_AUTH_CODE))
        {
            write("\n¡Error al enviar el correo de autorización! Por favor, contacta con un wizard\n"
                  "o intentalo de nuevo.\n");
            input_auth_code();
            return;
        }
        forwarded = 1;
        write("\nDe acuerdo, se te ha vuelto a enviar el correo con el codigo de autorizacion.\n");
        input_auth_code();
        return;
    }
    if ((query_mud_port() == NORMAL_PORT || LOWER(str) != "valar morghulis") && str != auth_code)
    {
        write("\n¡Error! El codigo de autorizacion no coincide con el introducido aqui.\n"
              "Asegurate de haberlo escrito correctamente, respetando mayusculas y minusculas.\n"
              "Te recomendamos que utilices la opcion copiar de tu correo, y pegar,\n"
              "de tu cliente de conexion para evitar errores.\n");
        input_auth_code();
        return;
    }
    write("\n¡Personaje autorizado!\n");
    DBMASTER->Exec("update characters set authorized=1 where id=" + character_id);
    authorized = 1;

    load_player_object();
}
