/***
fichero: securebox.c
Autor: Kastwey
Fecha inicio: 16/08/2004
Descripci�n: Fichero que habr� que heredar para crear una oficina de taquillas
***/

#include <securebox.h>
#include <nightday.h>
#include <files.h>
#include <money.h>
#include <input_to.h>
#define SEX_EMPLEADO          (QueryKeeper()->QueryGender() ==2?"la empleada":"el empleado")
#define A_SEX_EMPLEADO        (QueryKeeper()->QueryGender()==2?"a la empleada":"al empleado")
#define EMPLEADO_AO           (QueryKeeper()->QueryGender() == 2?"a":"o")
#define EMPLEADO_AE           (QueryKeeper()->QueryGender() == 2?"a":"e")
#define SAVE_PL_CAJA          QueryRuta(TNREAL)
#define T_CREAR               1
#define T_RECUPERAR           2
#define EXT                   1
#define TRASLADO              0
#define INSTANTANEO           1
#define FEE_MOVE_BOX          25000
#define DISABLE_TRANSFER


inherit SCHEDULER_ROOM;
inherit KEEPER;


static string pPlace; // lugar de la oficina
static string pPlace_file_name; // ruta f�sica de esta habitaci�n
static int pLeaflets; // si hay o no hay folletos
static int pNumLeaflets; // n�mero de folletos que hay en la caja
static int pMaxNumLeaflets; // el n�mero m�ximo de folletos de la caja (se llena con el reset)



public string SetIntLong(mixed descripcion);
// funci�n para devolver la descripci�n de la oficina
public varargs string SetPlace(string lugar);
public string QueryPlace();
int mostrar_empleado(string sitio,string nombre_player, object empleado);
// funci�n para mostrar el empleado (mensaje predefinido) en cierta
// habitaci�n, para la simulaci�n de la puerta dimensional.
int cmd_pedir(string str);
// funci�n para pedir caja.
int cmd_transferir(string str);
// funci�n para transferencia de objetos entre jugadores.
int cmd_folleto(string str);
// coger un folleto del mostrador.
varargs int mover_player_habitacion(object player, int tipocaja, string tamano);
// se utiliza para mover al jugador al almac�n una vez aceptada su
// petici�n de caja, o una vez creada una caja nueva.
int volver_mover(object player, int tipocaja, string nombre_player, object empleado);
// funci�n que se ejecuta cuando el empleado vuelve de la otra oficina.
int cmd_alta(string str);
// funci�n para comprobar si lo que hay es alta o modificaci�n de tama�o
int nueva_alta(string tamanocaja);
// nueva alta
int cmd_pagar(string str);
// pago de comisi�n
int calcular_comision(int ultimopago, int edad, int tipocaja);
// c�lculo de la comisi�n acumulada
string calcular_tiempo_comision(int ultimopago, int edad);
// tiempo transcurrido desde el �ltimo pago traducido en d�as.
int introducir_en_caja(object player,object ob, string destinatario, object caja, object empleado);
// introducir el objeto del transferir en la caja del jugador
int pagar_comision(string str, mixed *arjs);
// funci�n para pagar comisi�n. Recibe la respuesta del input_to.
void devolver_objeto(object ob, object player);
// devuelve el objeto ob al player player.
void mover_a_caja(object ob, object caja, string destinatario, int tipo_traslado);
// mueve el objeto a la caja.
public int tamano_to_int(string tam);
// devuelve el n�mero asignado al tama�o de la caja, pasado como string
public varargs string QueryRuta(string name, int extension);
// devuelve la ruta de la caja
// pas�ndole como par�metros el nombre y si se desea a�adir o no, la extensi�n
// ".o".

public int SetLeaflets(int i) { return pLeaflets = i; }
public int QueryLeaflets() { return pLeaflets; }

public int SetNumLeaflets(int i) { return pNumLeaflets = i; }
public int QueryNumLeaflets() { return pNumLeaflets; }

public int SetMaxNumLeaflets(int i) { return pMaxNumLeaflets = i; }
public int QueryMaxNumLeaflets() { return pMaxNumLeaflets; }



private string mirar_caja() // funci�n para el detalle de la caja de folletos
{
    if (!pLeaflets) return 0;

    return "Es una caja con folletos en los que se explica el funcionamiento "
           "de la oficina de taquillas. " + (!pNumLeaflets ? "Ahora mismo est� vac�a.\n" :
                            "Si lo deseas puedes coger uno.\n");
}


create()
{
    ::create();
    SetIntShort("Una oficina de taquillas");
    SetIntLong("Est�s en una oficina de taquillas.\n");
    SetIndoors(1);
    SetIntBright(45);
    SetIntNoise("No escuchas nada. Este es un lugar muy silencioso.");
    SetIntSmell("No hueles nada en especial.");
    SetLeaflets(1);
    SetMaxNumLeaflets(20);
    SetNumLeaflets(20);
    SetCloseTime(({ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
    // Si esta es una asociada a un banco, esto no vale para nada, pero por si acaso est� s�la, lo
    // pongo por defecto.

    SetPlace("oficina principal");
    AddDetail(({"caja", "caja de folletos", "caja con folletos"}), SF(mirar_caja));


    // se a�ade un cartel con informaci�n sobre las taquillas.
    AddReadMsg(({"cartel","Cartel","letrero","Letrero"}),(W("Oficina de taquillas.\n"
              "Informaci�n sobre las taquillas. En esta oficina, podr�s "
              "alquilar tres tipos de cajas, dependiendo de tus necesidades."
              "\n\n"
              "Tipos de caja:\n"
              "Caja peque�a. 25 kilos de capacidad, o 30 objetos como "
              "m�ximo: " + P_BOX_SMALL + " mithriles.\n"
              "Caja mediana: 50 kilos de capacidad, o 60 objetos como "
              "m�ximo: " + P_BOX_NORMAL + " mithriles.\n"
              "Caja grande: 100 kilos de capacidad, o 90 objetos como "
              "m�ximo: " + P_BOX_LARGE + " mithriles.\n"
              "Para alquilar una caja, escribe: alquilar caja <tipo.\n"
              "Por ejemplo: alquilar caja mediana, o alquilar caja grande.\n"
              "Si lo que deseas es cambiar tu tipo de caja a una caja mas "
              "grande, escribe alquilar caja <tama�o>.\n"
              "por ejemplo: alquilar caja grande: modificar�a tu caja de un "
              "tama�o peque�o o mediano, al tama�o grande.\n"
              "Atenci�n! No se admiten devoluciones! Si alquilas una caja "
              "grande, no podr�s alquilar una peque�a para que te "
              "reembolsemos la diferencia!\n\n"
              "Comisiones vigentes: Se cobrar� una comisi�n diaria "
              "dependiendo del tama�o de la caja alquilada:\n"
              "caja peque�a: " + BOX_COMMISSION_SMALL + " mithriles.\n"
              "Caja mediana: " + BOX_COMMISSION_NORMAL + " mithriles.\n"
              "Caja grande: " + BOX_COMMISSION_LARGE + " mithriles.\n"
              "Si al pedir tu caja, el empleado te informa de que debes pagar "
              "una comisi�n, para pagarla, escribe pagar comisi�n.\n\n"
              "Comisiones por el uso del servicio de intercambio de objetos:\n"
              "Por introducir un objeto en la caja de otro jugador, se le "
              "cobrar� el " + BOX_EXCHANGE_COMMISSION + "% del valor real de "
              "dicho objeto, en concepto de seguro y responsabilidad.\n"
              "Para transferir objetos a la caja de otro jugador, escribe "
              "transferir <objeto> a <jugador>, por ejemplo, transferir "
              "pelota a armandito.\n"
              )));

    AddDetail  (({"cartel","letrero"}),
              W("Se trata de un cartel que hay colgado en una de las paredes. "
              "Quiz�s deber�as leerlo.\n"));
}

init()
{
    ::init();
    add_action("cmd_transferir","transferir");
    add_action("cmd_pedir","pedir");
    add_action("cmd_alta","alquilar");
    add_action("cmd_pagar","pagar");
    add_action("cmd_folleto","coger");
}

reset()
{
    ::reset();
    SetNumLeaflets(pMaxNumLeaflets);
}


public string QueryIntLong()
// se sobrecarga la funci�n QueryIntLong, para incluir la descripci�n
// del cartel aunque se cambie la descripci�n gen�rica.
{
    string descripcion;
    if (!(descripcion = ::QueryIntLong()))
    {
        descripcion = "Te encuentras en una oficina de taquillas.\n";
    }
    if (closurep(descripcion)) return ::QueryIntLong();
    return descripcion + (!pLeaflets ? "" : "Encima del mostrador, puedes "
                                       "ver una caja con folletos "
                                       "que puedes coger.\n") +
                        "Puedes leer el cartel que hay en la pared, o el "
                        "empleado te dar� m�s informaci�n sobre nuestros "
                        "servicios.\n";
}


public string SetPlace(string lugar)
// ajusta el lugar de la oficina (se deben incluir mensajes del tipo:
// Zarkam, Nandor...).
{
    if (!lugar) lugar = QueryLocate() || "alg�n sitio";
    return pPlace = lugar;
}

public string QueryPlace()
// devuelve el nombre del lugar de la oficina.
{
    return pPlace;
}



int cmd_pedir(string str)
// funci�n para pedir la caja
{
    object caja;
    int comision;
    if (!str || !(str == "caja" || str == "caja de seguridad"))
    {
        return notify_fail ("Pedir qu�?\n",NOTIFY_NOT_VALID);
    }
    if (CantAttend(K_NOTIFY)) return 0;
    if (file_size(SAVE_PL_CAJA + ".o") == FSIZE_NOFILE)
    // la caja no existe
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: Lo siento " +
                             TNAME + ". No tienes ninguna caja alquilada "
                             "aqu�.\n"));
    }
    caja = clone_object("/std/securebox/box.c");
    caja->RecuperaVariables(SAVE_PL_CAJA);
    if (caja->QueryTransitando())
    // la caja se est� trasladando de una a otra oficina
    // por la raz�n que sea
    {
        KeeperTell("Vaya " + TNAME + ". Parece que en este momento tu caja "
                   "est� siendo trasladada desde la oficina de " +
                   caja->QueryPlace() + " hasta la de " +
                   caja->QuerySitioTraslado() + ". Seguramente alguien la "
                   "habr� pedido para colocar algo en ella, y al no "
                   "encontrarse en esa oficina, el empleado habr� ido a "
                   "recogerla. Espera un momento y vuelve a intentarlo.\n");
        Emote (W(TNAME + " va a pedir su caja, pero " + KeeperName() + " le "
                 "dice algo y se queda esperando.\n"));
        caja->remove();
        return 1;
    }
    comision = calcular_comision(caja->QueryUltimoPago(),
                                 TP->QueryAge(),caja->QueryTamano());
    if (comision)
    // tiene comisi�n que pagar
    {
        return notify_fail(W(KeeperName(K_CAP) + " consulta el libro de "
                             "registros y te dice: Vaya " + TNAME + ". "
                             "Parece ser que tienes pendiente el "
                             "pago de una comisi�n de " + comision / V_MITHRIL +
                             " mithriles por " + calcular_tiempo_comision
                             (caja->QueryUltimoPago(),TP->QueryAge()) +
                             " de alquiler.\nPara recoger tu caja deber�s "
                             "pagar esta comisi�n.\n"));
    }
    if (caja->QueryPlace() == pPlace && !caja->QueryTransitando())
    // la caja no se est� trasladando, y a dem�s, est�
    // en el almac�n de esta oficina.
    {
        KeeperEmote (({"saca un gran llavero de debajo del mostrador, y tras "
                       "desaparecer por una puerta, aparece portando tu caja "
                       "de seguridad en los brazos.\n"
                       "A continuaci�n,  te acompa�a hasta una de las "
                       "habitaciones de la sala, y tras dejar tu caja, sale "
                       "cerrando la puerta tras de s�.\n",0}));
        Emote(TNAME + " le pide su caja de seguridad  a " + KeeperName() + ", y "
              "est" + EMPLEADO_AE + ", tras desaparecer por una puerta, "
              "aparece con la caja de " + TNAME + ".\n" + KeeperName(K_CAP) +
              " acompa�a a " + TNAME + " a una de las habitaciones de la "
              "sala, y al momento aparece y se vuelve a sentar detr�s del "
              "mostrador.\n");
        mover_player_habitacion(TP,T_RECUPERAR);
        caja->remove();
        return 1;
    }
    // la caja no est� en esta oficina
    if (QueryCloseInformed())
    // Se ha informado de que vamos a cerrar, as� que ya no hacemos traslado de cajas
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: Lo siento " + TNAME + ", pero "
                           "estoy a punto de cerrar, y tu caja no est� en esta oficina. "
                           "Vuelve Ma�ana y con mucho gusto te atender�.\n");
    }
    write (KeeperName(K_CAP) + " saca su libro de registros y comienza a "
           "ojearlo.\nUmmm. " + TNAME + ". Parece ser que tu caja est� "
           "guardada en la oficina de " + caja->QueryPlace() + ". Si quieres, puedo ir a por "
           "ella, pero el precio por el servicio es de " + MONEY_LIB->Value2String(FEE_MOVE_BOX) + ".\n");
    input_to("_confirm_transfer_box", INPUT_PROMPT, "�Quieres que vaya a recogerla? Escribe s o n.\n", caja);
    return 1;
}

public void _confirm_transfer_box(string str, object caja)
{
    string sitio;
    int segundos;
    
    if (str) str = LOWER(str);
    if (!str || member(({"s", "si", "s�", "n", "no"}), str) < 0)
    {
        write("Debes pulsar s o n.\n");
        input_to("_confirm_transfer_box", INPUT_PROMPT, "�Quieres que vaya a recogerla? Escribe s o n.\n", caja);
        return;
    }
    if (str == "n" || str == "no")
    {
        write(KeeperName(K_CAP) + " dice: Bien, como quieras.\n");
        caja->remove();
        return;
    }
    if (!Pay(TP, FEE_MOVE_BOX, "por el traslado de la caja de seguridad"))
    {
        write(KeeperName(K_CAP) + " te dice: No tienes suficiente dinero.\n");
        caja->remove();
        return;
    }
    write(KeeperName(K_CAP) + "Dice: bien, bien. Espera un "
             "momento que voy a por ella.\n");
    Emote (TNAME + " le pide su caja " + A_SEX_EMPLEADO + ". Est" +
           EMPLEADO_AE + ", consulta un instante el libro de registros y pone "
           "cara de disgusto.\n");
    caja->SetTransitando(1);
    caja->SetSitioTraslado(pPlace);
    KeeperEmote ("se levanta de detr�s del mostrador y parece concentrarse "
                 "intensamente. Al poco, observas como aparece de la nada una "
                 "puerta dimensional que " + KeeperName() + " atraviesa "
                 "r�pidamente.\n"
                 "La puerta dimensional se cierra y desaparece.\n");
    sitio = caja->QueryPlaceFileName();
    segundos = 15 + random(5);
    call_out("volver_mover",segundos,TP,T_RECUPERAR,TNAME,QueryKeeper());
    call_out("mostrar_empleado",segundos / 2,sitio,TNAME,QueryKeeper());
    // se mueve al empleado a una hab temporal, para que no se le vea
    // y parezca que de verdad se ha ido a alg�n sitio.
    QueryKeeper()->move("/std/securebox/store.c");
    caja->GuardaVariables(SAVE_PL_CAJA);
    caja->remove();
}

int cmd_alta(string str)
// gestiona las altas de una caja y sus modificaciones de tama�o
{
    int tamanocaja, tamanocajaactual, coste, comision;
    string strTactual, calcular, str_tamano;
    object caja, habitacion;
    if (!str)
    {
        return notify_fail ("Uso: alquilar caja <tipo>\n");
    }
    if (sscanf(str,"caja %s",str_tamano) != 1)
    {
        return notify_fail("Sintaxis: alquilar caja <tipo>.\n");
    }
    if (CantAttend(K_NOTIFY)) return 0;
    if (file_size(SAVE_PL_CAJA + ".o") == -1)
    // la caja noexiste
    // se llama a la funci�n de alta
    {
        return nueva_alta(str_tamano);
    }

    tamanocaja = tamano_to_int(str_tamano);
    caja = clone_object("/std/securebox/box.c");
    caja->RecuperaVariables(SAVE_PL_CAJA);
    if (comision = calcular_comision(caja->QueryUltimoPago(),TP->QueryAge(),caja->QueryTamano()))
    // tiene comisi�n que pagar.
    // deber� pagarla antes de cambiar el tama�o de la caja.
    {
        Emote(TNAME + " habla con " + SEX_EMPLEADO + " y pone cara de fastidio.\n");
        return notify_fail(W(KeeperName(K_CAP) + " te dice: Lo siento " + TNAME +
                             ". Para cambiar una caja de tama�o necesitar�s "
                             "pagar la comisi�n acumulada hasta el momento, "
                             "que es de " + (comision / V_MITHRIL) + " mithriles."
                             "\n"));
    }
    if (caja->QueryTamano() > tamanocaja)
    // la caja actual es mayor que el tama�o al que queremos modificar.
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: Lo siento " + TNAME +
                             ", pero tu caja es m�s grande que la que has "
                             "elegido. No se puede modificar una caja a un "
                             "tama�o menor que el que tienes actualmente.\n"));
    }
    if (caja->QueryTamano() == tamanocaja)
    // la caja a modificar es del mismo tama�o que la actual.
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: Pero si tu ya "
                             "tienes una caja de esas caracter�sticas " +
                             TNAME + "!\nSi lo que quieres es ped�rmela, "
                             "escribe pedir caja.\n"));
    }
    tamanocajaactual = caja->QueryTamano();
    switch(tamanocajaactual)
    {
        case BOX_SMALL:
            strTactual = "peque�a";
            if (tamanocaja == BOX_NORMAL)
            // quiere cambiar de peque�a a mediana
            {
                coste = V_MITHRIL * (P_BOX_NORMAL - P_BOX_SMALL);
                calcular = (P_BOX_NORMAL - P_BOX_SMALL) + " mithriles";
            }
            else
            {
                coste = (P_BOX_LARGE - P_BOX_SMALL)*V_MITHRIL;
                calcular = P_BOX_LARGE - P_BOX_SMALL + " mithriles";
            }
        case BOX_NORMAL:
            strTactual = "mediana";
            coste = (P_BOX_LARGE - P_BOX_NORMAL)*V_MITHRIL;
            calcular = P_BOX_LARGE - P_BOX_NORMAL + " mithriles";
    }

    write (W(KeeperName(K_CAP) + " saca el libro de registros de debajo del "
             "mostrador y te dice: Bien " + TNAME + ". As� que quieres "
             "alquilar una caja m�s grande eh?\n"
             "Veamos el libro de registros a ver por cuanto te saldr�a...\n"
             "Umm. S�. A ver. Tu tienes alquilada una caja " + strTactual + ", "
             "y quieres alquilar una caja " + str_tamano + ".\n"
             "El cambio de caja te saldr� por " + calcular + ".\n"));
    if (!Pay(TP,coste))
    // no tiene el dinero suficiente
    {
        Emote("Cuando " + TNAME + " va a pagarle a " + KeeperName() + ", "
              "se da cuenta de que no lleva suficiente dinero.\n");
        caja->remove();
        return 0;
    }
    caja->SetOwner(TP);
    caja->SetTamano(tamanocaja);
    caja->GuardaVariables(SAVE_PL_CAJA);
    KeeperEmote ("anota algo en el libro de registros y lo vuelve a "
                 "guardar.\n");
    KeeperTell ("Listo " + TNAME + "! ya he hecho el cambio de caja. La "
                "pr�xima vez que la pidas, ya tendr�s todas tus cosas en una "
                "caja de seguridad " + str_tamano + ".\n");
    Emote(KeeperName(1) + " informa a " + TNAME + " de que ya se ha "
          "efectuado el cambio de tama�o de su caja.\n");
    caja->remove();
    return 1;
}



int nueva_alta(string tamanocaja)
// gestiona la nueva alta de una caja
{
    int coste;
    switch (tamanocaja)
    {
        case "peque�a": coste = V_MITHRIL * P_BOX_SMALL; break;
        case "mediana": coste = V_MITHRIL * P_BOX_NORMAL; break;
        case "grande": coste = V_MITHRIL * P_BOX_LARGE; break;
    }
    if (!Pay(TP, coste)) return 0;
    KeeperEmote(({" extrae una caja vac�a de debajo del mostrador y te "
                  "acompa�a a una de las habitaciones de la sala.\n" +
                  KeeperName(K_CAP) + " te dice: Aqu� tienes tu caja. Guarda lo "
                  "que quieras en ella, y cuando termines, no tienes m�s que "
                  "salir. yo ya la recoger� y la guardar� en el almac�n. "
                  "Cuando quieras volver a usarla, no tienes m�s que venir "
                  "aqu� y ped�rmela.\n",
                  " extrae una caja de seguridad vac�a de debajo del "
                  "mostrador, y acompa�a a " + TNAME + " a una de las "
                  "habitaciones de la sala.\n"
                  "al poco, regresa y vuelve a sentarse detr�s del mostrador."
                  "\n"}));
    mover_player_habitacion(TP,T_CREAR,tamanocaja);
    return 1;
}


varargs int mover_player_habitacion(object player,int tipocaja, string tamano)
// mueve a un jugador a la habitaci�n de seguridad.
// Si se le pasa como par�metro <tipocaja> T_CREAR, se crear� una nueva caja.
// si no, se recuperar� la que ya ten�a el player.
{
    object habitacion;
    int tam;
    tam = tamano_to_int(tamano);
    habitacion = clone_object("/std/securebox/store.c");
    habitacion->SetParams(KeeperName(K_CAP),TP,TO);
    if (tipocaja == T_CREAR)
    // se crea una caja nueva
    {
        object registros;
        registros = clone_object ("/std/securebox/registerbook");
        registros->recuperar();
        registros->AddCaja(CAP(NNAME(player)),pPlace, STR->etime(ctime(time())));
        registros->guardar();
        registros->remove();
        habitacion->crear_caja_nueva(player,tam);
    }
    else
    {
        habitacion->crear_caja(player);
    }
    player->move(habitacion,M_SILENT);
    player->LookAfterMove();
    return 1;
}

int volver_mover(object player,int tipocaja, string nombre_player, object empleado)
// se usa cuando el empleado llega usando una puerta dimensional
{
    empleado->move(TO,M_SILENT);
    tell_room(TO,W("Se abre una puerta dimensional y ves aparecer a " +
                   KeeperName(K_CAP) + " con una caja entre sus brazos.\n"));
    if (!player&&present(nombre_player,TO)) player = present(nombre_player,TO);
    if (present(nombre_player,TO))
    {
        tell_object (player,W("Acompa�as a " + KeeperName(K_CAP) + " hacia una "
                              "de las habitaciones.\n" +
                              SEX_EMPLEADO + " suelta la caja en su interior, "
                              "y cierra la puerta al marcharse.\n"));
        Emote (KeeperName(K_CAP) + " acompa�a a " +
               CAP(NNAME(player)) + " a una de las habitaciones "
               "de la sala. Al regresar, vuelve a sentarse tras el "
               "mostrador.\n");
        mover_player_habitacion(player,tipocaja,"");
    }
    else
    {
        object caja;
        tell_room(TO,W("Cuando " + KeeperName(K_CAP) + " mira a su alrrededor "
                       "buscando a " + nombre_player + ", se da cuenta de que "
                       "se ha ido. Enfadad" + EMPLEADO_AO + ", guarda la "
                       "caja en el almac�n y se vuelve a sentar tras el "
                       "mostrador.\n"));
        caja = clone_object("/std/securebox/box.c");
        caja->RecuperaVariables(QueryRuta(nombre_player));
        caja->SetPlace(pPlace);
        caja->SetPlaceFileName(object_name(TO));
        caja->SetTransitando(0);
        caja->GuardaVariables(QueryRuta(nombre_player));
        return 1;
    }
}

int mostrar_empleado(string sitio, string nombre_player, object empleado)
// muestra al empleado en la room pasada como par�metro
{
    sitio += ".c";
    if (file_size(sitio) != -1)
    // el lugar existe
    {
        tell_room(sitio,W("Se abre una puerta dimensional y ves aparecer " +
                          (empleado->QueryGender() == 2?"a la empleada":
                          "al empleado") + " de la oficina de " + pPlace +
                          ". " + CAP(empleado->QueryName()) + " entra "
                          "en el almac�n y sale portando una caja de "
                          "seguridad.\n"
                          "Al instante, observas como se concentra "
                          "intensamente y de la nada surge una puerta "
                          "dimensional.\n" +
                          CAP(empleado->QueryName())+ " atraviesa la puerta "
                          "que se cierra y desaparece.\n"));
    }
    return 1;
}



int calcular_comision(int ultimopago, int edad, int tipocaja)
{
    if ((edad*2-ultimopago)<BOX_SEC_COMMISSION) return 0;
    switch(tipocaja)
    {
        case 1:
            return   ((edad*2-ultimopago)
                   / BOX_SEC_COMMISSION) * BOX_COMMISSION_SMALL*V_MITHRIL;
            break;
        case 2:
            return   ((edad*2-ultimopago)
                   / BOX_SEC_COMMISSION) * BOX_COMMISSION_NORMAL*V_MITHRIL;
            break;
        case 3:
            return   ((edad*2-ultimopago)
                   / BOX_SEC_COMMISSION) * BOX_COMMISSION_LARGE*V_MITHRIL;
            break;
    }
    return 0;
}

string calcular_tiempo_comision(int ultimopago, int edad)
{
    int tiempo;
    tiempo = (edad * 2- ultimopago) / BOX_SEC_COMMISSION;
    if (tiempo == 1) return "1 " + BOX_COMMISSION_TIME;
    else return to_string(tiempo + " " + BOX_COMMISSION_TIME + "s");
}

int cmd_pagar(string str)
// funci�n para pagar la comisi�n acumulada por el alquiler.
{
    int total, unidad, resto, dinero;
    object caja;
    if (   !str || !(str == "comision" || str == "comision de caja"
        || str == "comisi�n" ||str == "comisi�n de caja"))
    {
        return notify_fail("�Pagar qu�?");
    }
    if (CantAttend()) return 0;
    if (file_size(SAVE_PL_CAJA + ".o") == -1)
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: No puedes pagar "
                             "comisi�n si no tienes ninguna caja alquilada. "
                             "Antes alquila una caja.\n"));
    }
    caja=clone_object("/std/securebox/box");
    caja->RecuperaVariables(SAVE_PL_CAJA);
    total = calcular_comision(caja->QueryUltimoPago(),TP->QueryAge(),caja->QueryTamano());
    if (!total)
    // no hay comisi�n
    {
        return notify_fail(W(KeeperName(K_CAP) + " dice: " + TNAME + ". No "
                             "tienes comisi�n acumulada que pagar.\n"));
    }
    if (!CheckMoney(total))
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: No llevas "
                             "suficiente dinero encima para pagar la comisi�n "
                             "de " + total / V_MITHRIL + " monedas de mithril.\n"));
    }
    resto = (TP->QueryAge()*2 - caja->QueryUltimoPago()) % BOX_SEC_COMMISSION;
    Pay(TP,total);
    caja->SetUltimoPago(TP->QueryAge()*2 - resto);
    caja->GuardaVariables(SAVE_PL_CAJA);
    return 1;
}


int cmd_folleto(string str)
// para coger un folleto de la caja de folletos del mostrador
{
    int val;
    object folleto;
    if (   !str || !(str == "folleto" || str == "folleto de caja"
        || str == "folleto de mostrador" || str == "folleto del mostrador"))
    {
        return 0;
    }
    if (present("folleto de consignas",TP))
    // ya tiene uno... para qu� m�s?
    {
        return notify_fail(W("�Para qu� quieres coger otro folleto si ya "
                             "tienes uno?\n"),NOTIFY_NOT_VALID);
    }
    if (!pNumLeaflets)
    // la caja est� vac�a
    {
        return notify_fail("La caja de folletos est� vac�a.\n", NOTIFY_NOT_VALID);
    }

    folleto = clone_object("/std/securebox/folleto.c");
    if (val = folleto->move(TP,M_GIVE) == ME_OK)
    {
        write(W("Coges un folleto de la caja de encima del mostrador.\n"));
        say (W(TNAME + " coge un folleto de la caja de encima del "
               "mostrador.\n"));
        pNumLeaflets--;
        return 1;
    }
    if (val == ME_TOO_HEAVY)
    // pesa mucho
    {
        folleto->remove();
        write(W("Un folleto es demasiado grande. Quiz�s deber�as dejar algo "
                "de tu inventario.\n"));
        return 1;
    }
    folleto->remove();
    write(W("No puedes coger un folleto de la hermandad de consignas.\n"));
    return 1;
}


int cmd_transferir(string str)
// funci�n que se le pasa como par�metro el nombre del player en cuya caja
// se va a meter el objeto que sea.
{
    object caja, ob, jug;
    string destino, tmp_cosa, desc;
#ifdef DISABLE_TRANSFER
    return notify_fail(KeeperName(K_CAP) + " te dice: Este servicio no se est� prestando actualmente. Lo siento.\n");
#endif
    // miramos si ha escrito bien el formato: transferir cosa a jugador
    if (!str || sscanf(str,"%s a %s",tmp_cosa,destino) != 2)
    {
        return notify_fail("transferir objeto a jugador.\n");
    }
    // quitamos posibles may�sculas
    tmp_cosa=lower_case(tmp_cosa);
    destino=lower_case(destino);
    // si no tiene el objeto... (a lo mejor tb le pongo pa plurares, pero
    // por ahora, paso)
    if (!present(tmp_cosa,TP))
    {
        return notify_fail(W("No tienes " + tmp_cosa + " en tu inventario.\n"));
    }
    // asignamos al object ob el objeto del inventario del player
    ob = present(tmp_cosa,TP);
    desc = (ob->QueryShort() || ob->QueryName() || "algo");
    // si lo tiene puesto o empu�ado, no se deja mover
    if (ob->QueryEquipped() == TP || ob->QueryEquipped() == TP)
    {
        return notify_fail(W("No puedes transferir objetos ni puestos ni "
                             "empu�ados.\n"));
    }
    // si tiene el NoGive, no se puede dar
    if (ob->QueryNoGive())
    {
        return notify_fail((ob->QueryNoGive() == 1?W("No puedes transferir "
                                                     "eso.\n"):
                                                  ob->QueryNoGive()));
    }
    // si no se puede tirar
    if (ob->QueryNoDrop())
    {
        return notify_fail((ob->QueryNoDrop() == 1?W("No puedes transferir "
                                                     "eso.\n"):
                                                  ob->QueryNoDrop()));
    }
    // si el nombre tiene espacios, no se permite
    if (sizeof(explode(destino," ")) > 1)
    {
        return notify_fail(W("El nombre del jugador no puede llevar "
                             "espacios.\n"));
    }
    // si el jugador no existe en simauria, como que tampoco.
    if (file_size("/save/" + destino[0..0] + "/" + destino + ".o") < 0)
    {
        return notify_fail(CAP(destino) + " no existe en Simauria.\n");
    }
    // si no est� el empleado / empleada, o est� luchando,
    // no hay nada que hacer
    if (CantAttend()) return 0;
    write(W("Le muestras " + desc + "a " + KeeperName(K_CAP) + ".\n"));
    say(W(TNAME + " le muestra " + desc + " a " + KeeperName(K_CAP) + ".\n"));
        if (destino == TNREAL)
    // te est�s intentando poner algo en tu propia caja.
    {
        return   notify_fail (
               (:KeeperEmote(({"dice: �" + TNAME + "? �Quieres ponerte "
                               "una cosa en tu propia caja? Para eso, "
                               "p�demela y lo pones dir�ctamente...\n",
                               "mira a " + TNAME + ", y le dice algo "
                               "mientras "+(TP->QueryGender() == 2?"la ":"lo ")+
                               "mira con cara rara.\n"}));; return;:));
    }
    if (sizeof(all_inventory(ob)) >= 1)
    // lo que est�s intentando meter es un objet ocontenedor, con cosas dentro.
    {
        return    notify_fail(
               (: KeeperEmote(({"te dice: Lo siento " + TNAME + ", pero no "
                                "puedes meter objetos dentro de otros objetos "
                                "en las cajas de seguridad.\n"
                                "Si quieres, saca todo lo que hay dentro de "
                                "esto y me los das de uno en uno.\n",
                                "le dice algo a " + TNAME + " mientras niega "
                                "con la cabeza.\n"
                  })); return;:));
    }
    KeeperEmote (({"te dice: De acuerdo " + TNAME + ". Dejame que mire en el "
                   "libro de registros si " + CAP(destino) + " tiene "
                   "alguna caja alquilada aqu�...\n",
                   "saca el libro de registros y comienza a ojearlo "
                   "detenidamente.\n"}));
    if (file_size(QueryRuta(destino,EXT)) == -1)
    // el fichero de caja no existe
    {
        return notify_fail(
               funcall((:KeeperEmote(({"cierra el libro y te dice: Lo "
                                       "siento " + TNAME + ", pero " +
                                       CAP($1) + " no tiene ninguna "
                                       "caja alquilada aqu�.\n",
                                       "cierra el libro y le dice algo a " +
                                       TNAME + " mientras niega con la "
                                       "cabeza.\n"})):),destino));
    }
    // el fichero de caja existe.
    write (W("Veamos... Si. Parece que " + CAP(destino) + " tiene "
             "aqu� una. Disculpa un momento...\n"));
    if (jug = find_object(destino))
    // si el player existe, se comprueba que no est� en su habitacion de seguridad.
    {
        if (   call_other(environment(jug),"QuerySecurityRoom")
            && call_other(environment(jug),"QueryOwner") == jug)
        // el jugador est� en su habitaci�n de seguridad
        {
            return notify_fail (
                   funcall((:write(W("Vaya " + TNAME + ". Parece ser que " +
                                     CAP($1) + " est� en este momento "
                                     "en una de nuestras habitaciones con su "
                                     "caja...\n"
                                     "Ser� mejor que esperemos a que salga.\n")
                                    );
                             Emote(SEX_EMPLEADO + " mira hacia una de las "
                                   "puertas de las habitaciones y le dice "
                                   "algo a " + TNAME + ".\n"); return;:),destino));
        }
    }
    // se clona la caja
    caja = clone_object("/std/securebox/box.c");
    caja->RecuperaVariables(QueryRuta(destino));
    // se le pone de propietario temporal al player.
    caja->SetOwner(TP);
    caja->AjustaTamano();
    if (   !((member(caja->QueryPermisos(), TNREAL)
        && caja->QueryPermitir()) || caja->QueryPermitir() == BOX_PERMISSION_ALL))
    // no tienes permisos para meter eso en la caja.
    {
        caja->remove();
        return notify_fail(funcall((:KeeperEmote(({"te dice: Lo siento " +
                                     TNAME + ". No tienes permiso para "
                                     "poner nada en la caja de " +
                                     CAP($1) + ".\n",
                                     "le dice algo a " + TNAME + " mientras"
                                     "niega con la cabeza.\n"
                                               })):),destino));
                                               ;
    }
    // tienes permiso para poner cosas.
    if (   caja->QueryObjects() == caja->QueryMaxObj()
        || ob->QueryWeight() + caja->QueryWeight() > caja->QueryMaxWeight())
    // no caben m�s cosas.
    {
        return notify_fail(funcall((:KeeperEmote (({
                                     " mira unas anotaciones en el libro de "
                                     "registros y te dice: Lo siento " +
                                     TNAME + ". En la caja de seguridad de " +
                                     CAP($1) +", no caben mas cosas.\n",
                                     "mira unas anotaciones en el libro de "
                                     "registros y le dice algo a " + TNAME +
                                     ".\n"       })):),destino));
    }
    if (living(ob))
    // est�s intentando meter a un ser viviente? si es q...
    {
        return notify_fail(
               funcall((:KeeperEmote(({"te mira sorprendid" + EMPLEADO_AO + " y "
                                       "dice: " + TNAME + "! como vas a "
                                       "meter en la caja de " + CAP($1)+
                                       " " + $2 + "? seguro que ahi dentro se "
                                       "muere de hambre!\n",
                                       "mira a " + TNAME + ", luego mira " + $2+
                                       ",vuelve a mirar a " + TNAME + ", y "
                                       "le grita algo que no consigues "
                                       "entender.\n"
                                       })):),destino,desc));
    }
    if(member(inherit_list(ob),"/std/corpse.c") >= 0)
    // un muerto? ... ... ...
    {
        return notify_fail (
               funcall((:KeeperEmote(({"observa m�s detenidamente " + $2 + " "
                                       "y da un grito asombrado.\n"
                                       "Pero por diooos " + TNAME + "! como "
                                       "vas a meter " + $2 +
                                       " en la caja de " + CAP($1) +
                                       "! que asco!",
                                       "mira a " + TNAME + ", luego mira " +
                                       $2 + ", vuelve a mirar a " + TNAME +
                                       ", y le grita algo que no consigues "
                                       "entender.\n"
                                       })):), destino,desc));
    }
    if (caja->QueryTransitando())
    // si la caja est� siendo trasladada de un sitio a otro...
    {
        return notify_fail (
               funcall((:write(W("Vaya " + TNAME + ". Parece ser que en este "
                                 "momento la caja de " + CAP($1) +
                                 " est� siendo trasladada desde la oficina "
                                 "de " + $1->QueryPlace() + " hasta " +
                                 $1->QuerySitioTraslado() + ". Intentalo en "
                                 "un rato a ver si ya est� disponible.\n"));
                         Emote(KeeperName(K_CAP) + " le dice algo a " + TNAME +
                         " mientras niega con la cabeza.\n"); return;:),caja));
    }
    pPlace_file_name = object_name(TO);
    if (ob->QueryValue() >= 100/BOX_EXCHANGE_COMMISSION)
    // tienes que pagar comisi�n por la introducci�n del objeto.
    {
        int valor;
        string pagar;
        valor = ob->QueryValue() * BOX_EXCHANGE_COMMISSION / 100;
        pagar = call_other(MONEY_LIB,"Value2String",valor);
        KeeperEmote(({"observa detenidamente " + desc + " y te dice:\n"
                      "Veamos... Los costes de introducir " + desc + " en la "
                      "caja de " + CAP(destino) + " son de " + pagar +
                      ".\n"
                      "�Est�s dispuest" + TP->QueryGenderEndString() + " a pagarlo? Escribe si o no.\n",
                      "observa detenidamente " + desc + ", y a continuaci�n "
                      "le pregunta algo a " + TNAME + ".\n"}));
        // se pasa a la funci�n pagar_comision la respuesta del player.
        // si es s�, se intenta pagar.. si no, se le devolver� el objeto.
        input_to("pagar_comision",0,({ob,caja,(caja->QueryPlace() != pPlace?
                                               TRASLADO:INSTANTANEO),
                 valor,destino}));
        return 1;
    }
    // no hay que pagar nada.
    if (caja->QueryPlace() != pPlace)
    // la caja no est� en esta oficina
    {
        string sitio;
        int segundos;
        KeeperEmote (({"consulta el libro de registros y dice: Vaya " +
                       TNAME + ". Parece ser que la caja de " +
                       CAP(destino) + " est� en la oficina de " +
                       caja->QueryPlace() + ". Tendr� que ir a por ella.\n",
                       "observa un instante el libro de registros y le dice "
                       "algo a " + TNAME + ".\n"}));
        tell_room(TO,W(CAP(SEX_EMPLEADO) + " se levanta de "
                       "detr�s del mostrador y parece concentrarse "
                       "intensamente. Al poco, observas como aparece de la "
                       "nada una puerta dimensional que " + KeeperName(K_CAP) +
                       " atraviesa r�pidamente.\n"
                       "La puerta dimensional se cierra y desaparece.\n"));
        // se ajusta la caja para que se sepa que se est� trasladando,
        // de d�nde y hacia d�nde.
        caja->SetTransitando(1);
        caja->SetSitioTraslado(pPlace);
        caja->GuardaVariables(QueryRuta(destino));
        sitio = blueprint(caja->QueryPlaceFileName());
        segundos = 15 + random(5);
        call_out("introducir_en_caja",segundos, TP, ob, destino, caja,
                 QueryKeeper());
        call_out("mostrar_empleado",segundos / 2, sitio, TNAME,QueryKeeper());
        // se mueve el empleado al almac�n, para dar la sensaci�n de que
        // se ha largado de verdad.
        QueryKeeper()->move("/std/securebox/store.c");
        return 1;
    }
    // la caja est� en esta oficina.
    // no hay que pagar nada.
    mover_a_caja(ob, caja, destino, INSTANTANEO);
    return 1;
}


int introducir_en_caja(object player, object ob, string destinatario,
                       object caja, object empleado)
// el empleado llega de su escursi�n a la otra oficina e intenta meter el
// objeto en la caja.
{
    empleado->move(pPlace_file_name);
    tell_room(pPlace_file_name,W("Se abre una puerta dimensional y ves "
                                 "aparecer a " + KeeperName(K_CAP) + ".\n"));
    if (!ob || !player || !present(player,TO) || !present(ob,player))
    // el player no est�, el objeto no existe, o el player est�, pero no tiene el objeto
    {
        if (player && present(player,TO) && (!ob || !present(ob,player)))
        // el jugador est� aqu�, pero el objeto ha desaparecido de
        // su inventario o a lo mejor lo tiene en una mochila o lo que se1,
        // pero a la vista, no est�, o ha sido destruido...
        {
            KeeperTell ("Eih " + TNAME + ". �Donde est� eso que quer�as "
                        "meter en la caja de " + CAP(destinatario) +
                        "?\nAhora que traigo la caja, vas y me ll "
                        "escondes...\n");
            Emote(KeeperName(K_CAP) + " mira enfadad" + EMPLEADO_AO + " a " +
                  TNAME + " y le dice: �Donde est� eso que quer�as poner "
                  "en la caja de " + CAP(destinatario) + "? Encima "
                  "que voy a por ella, ahora vas y lo escondes.\n");
            if (ob->QueryValue() >= 100/BOX_EXCHANGE_COMMISSION)
            {
                int valor = ob->QueryValue()*BOX_EXCHANGE_COMMISSION/100;
                string importe = call_other(MONEY_LIB,"Value2String",valor);
                call_other(MONEY_LIB,"AdjustMoney",TP,valor);
                KeeperEmote(({"te da " + importe + ".\n",
                              "le da a " + TNAME + " " + importe + ".\n"}));
            }
        }
        else if (!player || !present(player,TO))
        // el jugador no est� en la habitaci�n
        {
                KeeperEmote("mira hacia todos lados buscando a alguien. Al "
                            "poco, sacude la cabeza con cara de pocos amigos, "
                            "guarda la caja en el almac�n y se sienta tras el "
                            "mostrador.\n");
        }
        caja->SetPlace(pPlace);
        caja->SetPlaceFileName(pPlace_file_name);
        caja->SetTransitando(0);
        caja->GuardaVariables(QueryRuta(destinatario));
        caja->remove();
        return 1;
    }
    mover_a_caja(ob,caja, destinatario, TRASLADO);
    return 1;
}

void devolver_objeto(object ob, object player)
// funci�n usada para devolver un objeto a un player.
{
    string desc = (ob->QueryShort() || ob->QueryName() || "algo");
                                        if (ob->move(player) == ME_OK)
    {
        KeeperEmote(({"te devuelve " + desc + ".\n",
                      "le devuelve a " + TNAME + " " + desc + ".\n"}));
    }
    else
    {
        KeeperEmote(({"te devuelve " + desc + ", pero sin poder evitarlo, "
                      "se te cae al suelo.\n",
                      "le devuelve a " + TNAME + " " + desc + " pero se le "
                      "cae al suelo.\n"}));
        ob->move(TO,M_SILENT);
    }
}



int pagar_comision(string str, mixed *args)
// funci�n para pagar la comisi�n de la introducci�n de un objeto.
// se le pasan como par�metros la respuesta del player, y un array de
// argumentos: objeto a introducir, referencia al objeto caja, tipo de
// introducci�n (instantanea o con traslado a otra oficina), dinero q tiene
// que pagar, receptor del objeto.
{
    if (sizeof(args) != 5) return 0;
    object ob = args[0];
    object caja = args[1];
    int tipo_introducir = args[2];
    int coste = args[3];
    string receptor = args[4];
    string sitio;
    int segundos, dinero;
    if (!(str == "si" || str == "S�" || str == "s" || str == "s�"))
    // ha dicho que no, o algo diferente a un posible s� ;)
    {
        return notify_fail(KeeperName(K_CAP) +" te dice: Bien, como quieras.\n");
    }
    if (!CheckMoney(coste))
    // no tiene dinero suficiente
    {
        KeeperTell("Lo siento. No llevas suficiente dinero encima.\n");
        Emote("Cuando " + TNAME + " va a pagar, se da cuenta de que no lleva "
              "suficiente dinero.\n");
        return 1;
    }
    Pay(TP, coste);
    if (tipo_introducir == INSTANTANEO)
    {
        mover_a_caja(ob, caja, receptor, INSTANTANEO);
    }
    else
    {
        KeeperEmote (({"consulta el libro de registros y te dice: Vaya " +
                       TNAME + ". Parece ser que la caja de " +
                       CAP(receptor) + " est� en la oficina de " +
                       caja->QueryPlace() + ". Tendr� que ir a por ella.\n",
                       "le dice algo a " + TNAME + ".\n"}));
        KeeperEmote("se levanta de detr�s del mostrador y parece concentrarse "
                    "intensamente. Al poco, observas como aparece de la nada "
                    "una puerta dimensional que " + KeeperName(K_CAP) + " "
                    "atraviesa r�pidamente.\n"
                    "La puerta dimensional se cierra y desaparece.\n");
        caja->SetTransitando(1);
        caja->SetSitioTraslado(pPlace);
        caja->GuardaVariables(QueryRuta(receptor));
        sitio = blueprint(caja->QueryPlaceFileName());
        segundos = 15 + random(5);
        call_out("introducir_en_caja",segundos,TP,ob,receptor, caja,
                 QueryKeeper());
        call_out("mostrar_empleado",segundos / 2,sitio,TNAME,QueryKeeper());
        QueryKeeper()->move("/std/securebox/store.c");
        return 1;
    }
}

void mover_a_caja(object ob, object caja, string destinatario, int tipo_traslado)
{
    string desc = (ob->QueryShort() || ob->QueryName() || "algo");
    object pl;
    if (ob->move(caja,0) == ME_NO_ENTER)
    // por alguna raz�n el objeto no se pudo mover a la caja.
    {
        write (W("Vaya " + TNAME + ". Parece ser que esto no se puede meter "
                 "en la caja... Lo siento.\n"));
        if (ob->QueryValue() >= 100/BOX_EXCHANGE_COMMISSION)
        {
            int valor = ob->QueryValue()*BOX_EXCHANGE_COMMISSION/100;
            string importe = call_other(MONEY_LIB,"Value2String",valor);
            call_other(MONEY_LIB,"AdjustMoney",TP,valor);
            KeeperEmote(({"te da " + importe + ".\n",
                          "le da a " + TNAME + " " + importe + ".\n"}));
        }
        caja->SetPlace(pPlace);
        caja->SetPlaceFileName(pPlace_file_name);
        caja->GuardaVariables(QueryRuta(destinatario));
        caja->remove();
        return;
    }
    if (tipo_traslado== INSTANTANEO)
    {
        KeeperEmote(({"se levanta de detr�s del mostrador portando en sus "
                      "manos " +desc + " que le has dado.\n"
                      "Entra en el almac�n, y al poco vuelve a salir con "
                      "las manos vac�as y se sienta de nuevo.\n",
                      "se levanta de detr�s del mostrador portando en sus "
                      "manos " + desc + " que le ha dado " + TNAME + ".\n"
                      "Entra en el almac�n, y al poco vuelve a salir con las "
                      "manos vac�as.\n"}));
    }
    else
    {
        KeeperEmote("saca un llavero de debajo del mostrador e inserta una de "
                    "las llaves en la cerradura de la caja.\n"
                    "Escuchas un leve �click!, y la tapa se abre.\n" +
                    KeeperName(K_CAP) + " coloca " + desc + " dentro de la caja "
                    "y vuelve a cerrarla.\n"
                    "Luego, la coge y la guarda en el almac�n.\n");
    }
    // si el player est� conectado, se le avisa de la introducci�n del objeto.
    if (pl = find_object(destinatario))
    {
        tell_object(pl,W(TNAME + " ha puesto " + desc + " en tu caja de "
                         "seguridad.\n"));
    }
    // a�ado un log_file para ver cuantos objetos se introducen.
    log_file("securebox/EXCHANGES",ctime(time()) + ". " +
             TNAME + " ha introducido " + desc + " (pagando una comisi�n "
             "de " + call_other(  MONEY_LIB,"Value2String",ob->QueryValue()
                                * BOX_EXCHANGE_COMMISSION / 100) +
             "), en la caja de " + CAP(destinatario) + ".\n");
    caja->AddObjGuest(TNREAL, desc,
                      STR->etime(ctime(time())));
    if (tipo_traslado == TRASLADO)
    {
        caja->SetPlace(pPlace);
        caja->SetPlaceFileName(pPlace_file_name);
        caja->SetTransitando(0);
    }
    caja->GuardaVariables(QueryRuta(destinatario));
    caja->remove();
    return;
}


public int tamano_to_int(string tam)
{
    int iTamano;
    switch(tam)
    {
        case "peque�a": iTamano = 1; break;
        case "mediana": iTamano = 2; break;
        case "grande": iTamano = 3; break;
        default : iTamano = 1;
    }
    return iTamano;
}

public varargs string QueryRuta(string name, int extension)
{
    return SAVEBOXPATH + name[0..0] + "/" + name +
          (extension?".o":"");
}
