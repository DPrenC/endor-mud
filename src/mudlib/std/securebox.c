/***
fichero: securebox.c
Autor: Kastwey
Fecha inicio: 16/08/2004
Descripción: Fichero que habrá que heredar para crear una oficina de taquillas
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
static string pPlace_file_name; // ruta física de esta habitación
static int pLeaflets; // si hay o no hay folletos
static int pNumLeaflets; // número de folletos que hay en la caja
static int pMaxNumLeaflets; // el número máximo de folletos de la caja (se llena con el reset)



public string SetIntLong(mixed descripcion);
// función para devolver la descripción de la oficina
public varargs string SetPlace(string lugar);
public string QueryPlace();
int mostrar_empleado(string sitio,string nombre_player, object empleado);
// función para mostrar el empleado (mensaje predefinido) en cierta
// habitación, para la simulación de la puerta dimensional.
int cmd_pedir(string str);
// función para pedir caja.
int cmd_transferir(string str);
// función para transferencia de objetos entre jugadores.
int cmd_folleto(string str);
// coger un folleto del mostrador.
varargs int mover_player_habitacion(object player, int tipocaja, string tamano);
// se utiliza para mover al jugador al almacén una vez aceptada su
// petición de caja, o una vez creada una caja nueva.
int volver_mover(object player, int tipocaja, string nombre_player, object empleado);
// función que se ejecuta cuando el empleado vuelve de la otra oficina.
int cmd_alta(string str);
// función para comprobar si lo que hay es alta o modificación de tamaño
int nueva_alta(string tamanocaja);
// nueva alta
int cmd_pagar(string str);
// pago de comisión
int calcular_comision(int ultimopago, int edad, int tipocaja);
// cálculo de la comisión acumulada
string calcular_tiempo_comision(int ultimopago, int edad);
// tiempo transcurrido desde el último pago traducido en días.
int introducir_en_caja(object player,object ob, string destinatario, object caja, object empleado);
// introducir el objeto del transferir en la caja del jugador
int pagar_comision(string str, mixed *arjs);
// función para pagar comisión. Recibe la respuesta del input_to.
void devolver_objeto(object ob, object player);
// devuelve el objeto ob al player player.
void mover_a_caja(object ob, object caja, string destinatario, int tipo_traslado);
// mueve el objeto a la caja.
public int tamano_to_int(string tam);
// devuelve el número asignado al tamaño de la caja, pasado como string
public varargs string QueryRuta(string name, int extension);
// devuelve la ruta de la caja
// pasándole como parámetros el nombre y si se desea añadir o no, la extensión
// ".o".

public int SetLeaflets(int i) { return pLeaflets = i; }
public int QueryLeaflets() { return pLeaflets; }

public int SetNumLeaflets(int i) { return pNumLeaflets = i; }
public int QueryNumLeaflets() { return pNumLeaflets; }

public int SetMaxNumLeaflets(int i) { return pMaxNumLeaflets = i; }
public int QueryMaxNumLeaflets() { return pMaxNumLeaflets; }



private string mirar_caja() // función para el detalle de la caja de folletos
{
    if (!pLeaflets) return 0;

    return "Es una caja con folletos en los que se explica el funcionamiento "
           "de la oficina de taquillas. " + (!pNumLeaflets ? "Ahora mismo está vacía.\n" :
                            "Si lo deseas puedes coger uno.\n");
}


create()
{
    ::create();
    SetIntShort("Una oficina de taquillas");
    SetIntLong("Estás en una oficina de taquillas.\n");
    SetIndoors(1);
    SetIntBright(45);
    SetIntNoise("No escuchas nada. Este es un lugar muy silencioso.");
    SetIntSmell("No hueles nada en especial.");
    SetLeaflets(1);
    SetMaxNumLeaflets(20);
    SetNumLeaflets(20);
    SetCloseTime(({ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
    // Si esta es una asociada a un banco, esto no vale para nada, pero por si acaso está sóla, lo
    // pongo por defecto.

    SetPlace("oficina principal");
    AddDetail(({"caja", "caja de folletos", "caja con folletos"}), SF(mirar_caja));


    // se añade un cartel con información sobre las taquillas.
    AddReadMsg(({"cartel","Cartel","letrero","Letrero"}),(W("Oficina de taquillas.\n"
              "Información sobre las taquillas. En esta oficina, podrás "
              "alquilar tres tipos de cajas, dependiendo de tus necesidades."
              "\n\n"
              "Tipos de caja:\n"
              "Caja pequeña. 25 kilos de capacidad, o 30 objetos como "
              "máximo: " + P_BOX_SMALL + " mithriles.\n"
              "Caja mediana: 50 kilos de capacidad, o 60 objetos como "
              "máximo: " + P_BOX_NORMAL + " mithriles.\n"
              "Caja grande: 100 kilos de capacidad, o 90 objetos como "
              "máximo: " + P_BOX_LARGE + " mithriles.\n"
              "Para alquilar una caja, escribe: alquilar caja <tipo.\n"
              "Por ejemplo: alquilar caja mediana, o alquilar caja grande.\n"
              "Si lo que deseas es cambiar tu tipo de caja a una caja mas "
              "grande, escribe alquilar caja <tamaño>.\n"
              "por ejemplo: alquilar caja grande: modificaría tu caja de un "
              "tamaño pequeño o mediano, al tamaño grande.\n"
              "Atención! No se admiten devoluciones! Si alquilas una caja "
              "grande, no podrás alquilar una pequeña para que te "
              "reembolsemos la diferencia!\n\n"
              "Comisiones vigentes: Se cobrará una comisión diaria "
              "dependiendo del tamaño de la caja alquilada:\n"
              "caja pequeña: " + BOX_COMMISSION_SMALL + " mithriles.\n"
              "Caja mediana: " + BOX_COMMISSION_NORMAL + " mithriles.\n"
              "Caja grande: " + BOX_COMMISSION_LARGE + " mithriles.\n"
              "Si al pedir tu caja, el empleado te informa de que debes pagar "
              "una comisión, para pagarla, escribe pagar comisión.\n\n"
              "Comisiones por el uso del servicio de intercambio de objetos:\n"
              "Por introducir un objeto en la caja de otro jugador, se le "
              "cobrará el " + BOX_EXCHANGE_COMMISSION + "% del valor real de "
              "dicho objeto, en concepto de seguro y responsabilidad.\n"
              "Para transferir objetos a la caja de otro jugador, escribe "
              "transferir <objeto> a <jugador>, por ejemplo, transferir "
              "pelota a armandito.\n"
              )));

    AddDetail  (({"cartel","letrero"}),
              W("Se trata de un cartel que hay colgado en una de las paredes. "
              "Quizás deberías leerlo.\n"));
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
// se sobrecarga la función QueryIntLong, para incluir la descripción
// del cartel aunque se cambie la descripción genérica.
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
                        "empleado te dará más información sobre nuestros "
                        "servicios.\n";
}


public string SetPlace(string lugar)
// ajusta el lugar de la oficina (se deben incluir mensajes del tipo:
// Zarkam, Nandor...).
{
    if (!lugar) lugar = QueryLocate() || "algún sitio";
    return pPlace = lugar;
}

public string QueryPlace()
// devuelve el nombre del lugar de la oficina.
{
    return pPlace;
}



int cmd_pedir(string str)
// función para pedir la caja
{
    object caja;
    int comision;
    if (!str || !(str == "caja" || str == "caja de seguridad"))
    {
        return notify_fail ("Pedir qué?\n",NOTIFY_NOT_VALID);
    }
    if (CantAttend(K_NOTIFY)) return 0;
    if (file_size(SAVE_PL_CAJA + ".o") == FSIZE_NOFILE)
    // la caja no existe
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: Lo siento " +
                             TNAME + ". No tienes ninguna caja alquilada "
                             "aquí.\n"));
    }
    caja = clone_object("/std/securebox/box.c");
    caja->RecuperaVariables(SAVE_PL_CAJA);
    if (caja->QueryTransitando())
    // la caja se está trasladando de una a otra oficina
    // por la razón que sea
    {
        KeeperTell("Vaya " + TNAME + ". Parece que en este momento tu caja "
                   "está siendo trasladada desde la oficina de " +
                   caja->QueryPlace() + " hasta la de " +
                   caja->QuerySitioTraslado() + ". Seguramente alguien la "
                   "habrá pedido para colocar algo en ella, y al no "
                   "encontrarse en esa oficina, el empleado habrá ido a "
                   "recogerla. Espera un momento y vuelve a intentarlo.\n");
        Emote (W(TNAME + " va a pedir su caja, pero " + KeeperName() + " le "
                 "dice algo y se queda esperando.\n"));
        caja->remove();
        return 1;
    }
    comision = calcular_comision(caja->QueryUltimoPago(),
                                 TP->QueryAge(),caja->QueryTamano());
    if (comision)
    // tiene comisión que pagar
    {
        return notify_fail(W(KeeperName(K_CAP) + " consulta el libro de "
                             "registros y te dice: Vaya " + TNAME + ". "
                             "Parece ser que tienes pendiente el "
                             "pago de una comisión de " + comision / V_MITHRIL +
                             " mithriles por " + calcular_tiempo_comision
                             (caja->QueryUltimoPago(),TP->QueryAge()) +
                             " de alquiler.\nPara recoger tu caja deberás "
                             "pagar esta comisión.\n"));
    }
    if (caja->QueryPlace() == pPlace && !caja->QueryTransitando())
    // la caja no se está trasladando, y a demás, está
    // en el almacén de esta oficina.
    {
        KeeperEmote (({"saca un gran llavero de debajo del mostrador, y tras "
                       "desaparecer por una puerta, aparece portando tu caja "
                       "de seguridad en los brazos.\n"
                       "A continuación,  te acompaña hasta una de las "
                       "habitaciones de la sala, y tras dejar tu caja, sale "
                       "cerrando la puerta tras de sí.\n",0}));
        Emote(TNAME + " le pide su caja de seguridad  a " + KeeperName() + ", y "
              "est" + EMPLEADO_AE + ", tras desaparecer por una puerta, "
              "aparece con la caja de " + TNAME + ".\n" + KeeperName(K_CAP) +
              " acompaña a " + TNAME + " a una de las habitaciones de la "
              "sala, y al momento aparece y se vuelve a sentar detrás del "
              "mostrador.\n");
        mover_player_habitacion(TP,T_RECUPERAR);
        caja->remove();
        return 1;
    }
    // la caja no está en esta oficina
    if (QueryCloseInformed())
    // Se ha informado de que vamos a cerrar, así que ya no hacemos traslado de cajas
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: Lo siento " + TNAME + ", pero "
                           "estoy a punto de cerrar, y tu caja no está en esta oficina. "
                           "Vuelve Mañana y con mucho gusto te atenderé.\n");
    }
    write (KeeperName(K_CAP) + " saca su libro de registros y comienza a "
           "ojearlo.\nUmmm. " + TNAME + ". Parece ser que tu caja está "
           "guardada en la oficina de " + caja->QueryPlace() + ". Si quieres, puedo ir a por "
           "ella, pero el precio por el servicio es de " + MONEY_LIB->Value2String(FEE_MOVE_BOX) + ".\n");
    input_to("_confirm_transfer_box", INPUT_PROMPT, "¿Quieres que vaya a recogerla? Escribe s o n.\n", caja);
    return 1;
}

public void _confirm_transfer_box(string str, object caja)
{
    string sitio;
    int segundos;
    
    if (str) str = LOWER(str);
    if (!str || member(({"s", "si", "sí", "n", "no"}), str) < 0)
    {
        write("Debes pulsar s o n.\n");
        input_to("_confirm_transfer_box", INPUT_PROMPT, "¿Quieres que vaya a recogerla? Escribe s o n.\n", caja);
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
    KeeperEmote ("se levanta de detrás del mostrador y parece concentrarse "
                 "intensamente. Al poco, observas como aparece de la nada una "
                 "puerta dimensional que " + KeeperName() + " atraviesa "
                 "rápidamente.\n"
                 "La puerta dimensional se cierra y desaparece.\n");
    sitio = caja->QueryPlaceFileName();
    segundos = 15 + random(5);
    call_out("volver_mover",segundos,TP,T_RECUPERAR,TNAME,QueryKeeper());
    call_out("mostrar_empleado",segundos / 2,sitio,TNAME,QueryKeeper());
    // se mueve al empleado a una hab temporal, para que no se le vea
    // y parezca que de verdad se ha ido a algún sitio.
    QueryKeeper()->move("/std/securebox/store.c");
    caja->GuardaVariables(SAVE_PL_CAJA);
    caja->remove();
}

int cmd_alta(string str)
// gestiona las altas de una caja y sus modificaciones de tamaño
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
    // se llama a la función de alta
    {
        return nueva_alta(str_tamano);
    }

    tamanocaja = tamano_to_int(str_tamano);
    caja = clone_object("/std/securebox/box.c");
    caja->RecuperaVariables(SAVE_PL_CAJA);
    if (comision = calcular_comision(caja->QueryUltimoPago(),TP->QueryAge(),caja->QueryTamano()))
    // tiene comisión que pagar.
    // deberá pagarla antes de cambiar el tamaño de la caja.
    {
        Emote(TNAME + " habla con " + SEX_EMPLEADO + " y pone cara de fastidio.\n");
        return notify_fail(W(KeeperName(K_CAP) + " te dice: Lo siento " + TNAME +
                             ". Para cambiar una caja de tamaño necesitarás "
                             "pagar la comisión acumulada hasta el momento, "
                             "que es de " + (comision / V_MITHRIL) + " mithriles."
                             "\n"));
    }
    if (caja->QueryTamano() > tamanocaja)
    // la caja actual es mayor que el tamaño al que queremos modificar.
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: Lo siento " + TNAME +
                             ", pero tu caja es más grande que la que has "
                             "elegido. No se puede modificar una caja a un "
                             "tamaño menor que el que tienes actualmente.\n"));
    }
    if (caja->QueryTamano() == tamanocaja)
    // la caja a modificar es del mismo tamaño que la actual.
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: Pero si tu ya "
                             "tienes una caja de esas características " +
                             TNAME + "!\nSi lo que quieres es pedírmela, "
                             "escribe pedir caja.\n"));
    }
    tamanocajaactual = caja->QueryTamano();
    switch(tamanocajaactual)
    {
        case BOX_SMALL:
            strTactual = "pequeña";
            if (tamanocaja == BOX_NORMAL)
            // quiere cambiar de pequeña a mediana
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
             "mostrador y te dice: Bien " + TNAME + ". Así que quieres "
             "alquilar una caja más grande eh?\n"
             "Veamos el libro de registros a ver por cuanto te saldría...\n"
             "Umm. Sí. A ver. Tu tienes alquilada una caja " + strTactual + ", "
             "y quieres alquilar una caja " + str_tamano + ".\n"
             "El cambio de caja te saldrá por " + calcular + ".\n"));
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
                "próxima vez que la pidas, ya tendrás todas tus cosas en una "
                "caja de seguridad " + str_tamano + ".\n");
    Emote(KeeperName(1) + " informa a " + TNAME + " de que ya se ha "
          "efectuado el cambio de tamaño de su caja.\n");
    caja->remove();
    return 1;
}



int nueva_alta(string tamanocaja)
// gestiona la nueva alta de una caja
{
    int coste;
    switch (tamanocaja)
    {
        case "pequeña": coste = V_MITHRIL * P_BOX_SMALL; break;
        case "mediana": coste = V_MITHRIL * P_BOX_NORMAL; break;
        case "grande": coste = V_MITHRIL * P_BOX_LARGE; break;
    }
    if (!Pay(TP, coste)) return 0;
    KeeperEmote(({" extrae una caja vacía de debajo del mostrador y te "
                  "acompaña a una de las habitaciones de la sala.\n" +
                  KeeperName(K_CAP) + " te dice: Aquí tienes tu caja. Guarda lo "
                  "que quieras en ella, y cuando termines, no tienes más que "
                  "salir. yo ya la recogeré y la guardaré en el almacén. "
                  "Cuando quieras volver a usarla, no tienes más que venir "
                  "aquí y pedírmela.\n",
                  " extrae una caja de seguridad vacía de debajo del "
                  "mostrador, y acompaña a " + TNAME + " a una de las "
                  "habitaciones de la sala.\n"
                  "al poco, regresa y vuelve a sentarse detrás del mostrador."
                  "\n"}));
    mover_player_habitacion(TP,T_CREAR,tamanocaja);
    return 1;
}


varargs int mover_player_habitacion(object player,int tipocaja, string tamano)
// mueve a un jugador a la habitación de seguridad.
// Si se le pasa como parámetro <tipocaja> T_CREAR, se creará una nueva caja.
// si no, se recuperará la que ya tenía el player.
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
        tell_object (player,W("Acompañas a " + KeeperName(K_CAP) + " hacia una "
                              "de las habitaciones.\n" +
                              SEX_EMPLEADO + " suelta la caja en su interior, "
                              "y cierra la puerta al marcharse.\n"));
        Emote (KeeperName(K_CAP) + " acompaña a " +
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
                       "caja en el almacén y se vuelve a sentar tras el "
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
// muestra al empleado en la room pasada como parámetro
{
    sitio += ".c";
    if (file_size(sitio) != -1)
    // el lugar existe
    {
        tell_room(sitio,W("Se abre una puerta dimensional y ves aparecer " +
                          (empleado->QueryGender() == 2?"a la empleada":
                          "al empleado") + " de la oficina de " + pPlace +
                          ". " + CAP(empleado->QueryName()) + " entra "
                          "en el almacén y sale portando una caja de "
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
// función para pagar la comisión acumulada por el alquiler.
{
    int total, unidad, resto, dinero;
    object caja;
    if (   !str || !(str == "comision" || str == "comision de caja"
        || str == "comisión" ||str == "comisión de caja"))
    {
        return notify_fail("¿Pagar qué?");
    }
    if (CantAttend()) return 0;
    if (file_size(SAVE_PL_CAJA + ".o") == -1)
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: No puedes pagar "
                             "comisión si no tienes ninguna caja alquilada. "
                             "Antes alquila una caja.\n"));
    }
    caja=clone_object("/std/securebox/box");
    caja->RecuperaVariables(SAVE_PL_CAJA);
    total = calcular_comision(caja->QueryUltimoPago(),TP->QueryAge(),caja->QueryTamano());
    if (!total)
    // no hay comisión
    {
        return notify_fail(W(KeeperName(K_CAP) + " dice: " + TNAME + ". No "
                             "tienes comisión acumulada que pagar.\n"));
    }
    if (!CheckMoney(total))
    {
        return notify_fail(W(KeeperName(K_CAP) + " te dice: No llevas "
                             "suficiente dinero encima para pagar la comisión "
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
    // ya tiene uno... para qué más?
    {
        return notify_fail(W("¿Para qué quieres coger otro folleto si ya "
                             "tienes uno?\n"),NOTIFY_NOT_VALID);
    }
    if (!pNumLeaflets)
    // la caja está vacía
    {
        return notify_fail("La caja de folletos está vacía.\n", NOTIFY_NOT_VALID);
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
        write(W("Un folleto es demasiado grande. Quizás deberías dejar algo "
                "de tu inventario.\n"));
        return 1;
    }
    folleto->remove();
    write(W("No puedes coger un folleto de la hermandad de consignas.\n"));
    return 1;
}


int cmd_transferir(string str)
// función que se le pasa como parámetro el nombre del player en cuya caja
// se va a meter el objeto que sea.
{
    object caja, ob, jug;
    string destino, tmp_cosa, desc;
#ifdef DISABLE_TRANSFER
    return notify_fail(KeeperName(K_CAP) + " te dice: Este servicio no se está prestando actualmente. Lo siento.\n");
#endif
    // miramos si ha escrito bien el formato: transferir cosa a jugador
    if (!str || sscanf(str,"%s a %s",tmp_cosa,destino) != 2)
    {
        return notify_fail("transferir objeto a jugador.\n");
    }
    // quitamos posibles mayúsculas
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
    // si lo tiene puesto o empuñado, no se deja mover
    if (ob->QueryEquipped() == TP || ob->QueryEquipped() == TP)
    {
        return notify_fail(W("No puedes transferir objetos ni puestos ni "
                             "empuñados.\n"));
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
    // si no está el empleado / empleada, o está luchando,
    // no hay nada que hacer
    if (CantAttend()) return 0;
    write(W("Le muestras " + desc + "a " + KeeperName(K_CAP) + ".\n"));
    say(W(TNAME + " le muestra " + desc + " a " + KeeperName(K_CAP) + ".\n"));
        if (destino == TNREAL)
    // te estás intentando poner algo en tu propia caja.
    {
        return   notify_fail (
               (:KeeperEmote(({"dice: ¿" + TNAME + "? ¿Quieres ponerte "
                               "una cosa en tu propia caja? Para eso, "
                               "pídemela y lo pones diréctamente...\n",
                               "mira a " + TNAME + ", y le dice algo "
                               "mientras "+(TP->QueryGender() == 2?"la ":"lo ")+
                               "mira con cara rara.\n"}));; return;:));
    }
    if (sizeof(all_inventory(ob)) >= 1)
    // lo que estás intentando meter es un objet ocontenedor, con cosas dentro.
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
                   "alguna caja alquilada aquí...\n",
                   "saca el libro de registros y comienza a ojearlo "
                   "detenidamente.\n"}));
    if (file_size(QueryRuta(destino,EXT)) == -1)
    // el fichero de caja no existe
    {
        return notify_fail(
               funcall((:KeeperEmote(({"cierra el libro y te dice: Lo "
                                       "siento " + TNAME + ", pero " +
                                       CAP($1) + " no tiene ninguna "
                                       "caja alquilada aquí.\n",
                                       "cierra el libro y le dice algo a " +
                                       TNAME + " mientras niega con la "
                                       "cabeza.\n"})):),destino));
    }
    // el fichero de caja existe.
    write (W("Veamos... Si. Parece que " + CAP(destino) + " tiene "
             "aquí una. Disculpa un momento...\n"));
    if (jug = find_object(destino))
    // si el player existe, se comprueba que no esté en su habitacion de seguridad.
    {
        if (   call_other(environment(jug),"QuerySecurityRoom")
            && call_other(environment(jug),"QueryOwner") == jug)
        // el jugador está en su habitación de seguridad
        {
            return notify_fail (
                   funcall((:write(W("Vaya " + TNAME + ". Parece ser que " +
                                     CAP($1) + " está en este momento "
                                     "en una de nuestras habitaciones con su "
                                     "caja...\n"
                                     "Será mejor que esperemos a que salga.\n")
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
    // no caben más cosas.
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
    // estás intentando meter a un ser viviente? si es q...
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
               funcall((:KeeperEmote(({"observa más detenidamente " + $2 + " "
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
    // si la caja está siendo trasladada de un sitio a otro...
    {
        return notify_fail (
               funcall((:write(W("Vaya " + TNAME + ". Parece ser que en este "
                                 "momento la caja de " + CAP($1) +
                                 " está siendo trasladada desde la oficina "
                                 "de " + $1->QueryPlace() + " hasta " +
                                 $1->QuerySitioTraslado() + ". Intentalo en "
                                 "un rato a ver si ya está disponible.\n"));
                         Emote(KeeperName(K_CAP) + " le dice algo a " + TNAME +
                         " mientras niega con la cabeza.\n"); return;:),caja));
    }
    pPlace_file_name = object_name(TO);
    if (ob->QueryValue() >= 100/BOX_EXCHANGE_COMMISSION)
    // tienes que pagar comisión por la introducción del objeto.
    {
        int valor;
        string pagar;
        valor = ob->QueryValue() * BOX_EXCHANGE_COMMISSION / 100;
        pagar = call_other(MONEY_LIB,"Value2String",valor);
        KeeperEmote(({"observa detenidamente " + desc + " y te dice:\n"
                      "Veamos... Los costes de introducir " + desc + " en la "
                      "caja de " + CAP(destino) + " son de " + pagar +
                      ".\n"
                      "¿Estás dispuest" + TP->QueryGenderEndString() + " a pagarlo? Escribe si o no.\n",
                      "observa detenidamente " + desc + ", y a continuación "
                      "le pregunta algo a " + TNAME + ".\n"}));
        // se pasa a la función pagar_comision la respuesta del player.
        // si es sí, se intenta pagar.. si no, se le devolverá el objeto.
        input_to("pagar_comision",0,({ob,caja,(caja->QueryPlace() != pPlace?
                                               TRASLADO:INSTANTANEO),
                 valor,destino}));
        return 1;
    }
    // no hay que pagar nada.
    if (caja->QueryPlace() != pPlace)
    // la caja no está en esta oficina
    {
        string sitio;
        int segundos;
        KeeperEmote (({"consulta el libro de registros y dice: Vaya " +
                       TNAME + ". Parece ser que la caja de " +
                       CAP(destino) + " está en la oficina de " +
                       caja->QueryPlace() + ". Tendré que ir a por ella.\n",
                       "observa un instante el libro de registros y le dice "
                       "algo a " + TNAME + ".\n"}));
        tell_room(TO,W(CAP(SEX_EMPLEADO) + " se levanta de "
                       "detrás del mostrador y parece concentrarse "
                       "intensamente. Al poco, observas como aparece de la "
                       "nada una puerta dimensional que " + KeeperName(K_CAP) +
                       " atraviesa rápidamente.\n"
                       "La puerta dimensional se cierra y desaparece.\n"));
        // se ajusta la caja para que se sepa que se está trasladando,
        // de dónde y hacia dónde.
        caja->SetTransitando(1);
        caja->SetSitioTraslado(pPlace);
        caja->GuardaVariables(QueryRuta(destino));
        sitio = blueprint(caja->QueryPlaceFileName());
        segundos = 15 + random(5);
        call_out("introducir_en_caja",segundos, TP, ob, destino, caja,
                 QueryKeeper());
        call_out("mostrar_empleado",segundos / 2, sitio, TNAME,QueryKeeper());
        // se mueve el empleado al almacén, para dar la sensación de que
        // se ha largado de verdad.
        QueryKeeper()->move("/std/securebox/store.c");
        return 1;
    }
    // la caja está en esta oficina.
    // no hay que pagar nada.
    mover_a_caja(ob, caja, destino, INSTANTANEO);
    return 1;
}


int introducir_en_caja(object player, object ob, string destinatario,
                       object caja, object empleado)
// el empleado llega de su escursión a la otra oficina e intenta meter el
// objeto en la caja.
{
    empleado->move(pPlace_file_name);
    tell_room(pPlace_file_name,W("Se abre una puerta dimensional y ves "
                                 "aparecer a " + KeeperName(K_CAP) + ".\n"));
    if (!ob || !player || !present(player,TO) || !present(ob,player))
    // el player no está, el objeto no existe, o el player está, pero no tiene el objeto
    {
        if (player && present(player,TO) && (!ob || !present(ob,player)))
        // el jugador está aquí, pero el objeto ha desaparecido de
        // su inventario o a lo mejor lo tiene en una mochila o lo que se1,
        // pero a la vista, no está, o ha sido destruido...
        {
            KeeperTell ("Eih " + TNAME + ". ¿Donde está eso que querías "
                        "meter en la caja de " + CAP(destinatario) +
                        "?\nAhora que traigo la caja, vas y me ll "
                        "escondes...\n");
            Emote(KeeperName(K_CAP) + " mira enfadad" + EMPLEADO_AO + " a " +
                  TNAME + " y le dice: ¿Donde está eso que querías poner "
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
        // el jugador no está en la habitación
        {
                KeeperEmote("mira hacia todos lados buscando a alguien. Al "
                            "poco, sacude la cabeza con cara de pocos amigos, "
                            "guarda la caja en el almacén y se sienta tras el "
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
// función usada para devolver un objeto a un player.
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
// función para pagar la comisión de la introducción de un objeto.
// se le pasan como parámetros la respuesta del player, y un array de
// argumentos: objeto a introducir, referencia al objeto caja, tipo de
// introducción (instantanea o con traslado a otra oficina), dinero q tiene
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
    if (!(str == "si" || str == "Sí" || str == "s" || str == "sí"))
    // ha dicho que no, o algo diferente a un posible sí ;)
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
                       CAP(receptor) + " está en la oficina de " +
                       caja->QueryPlace() + ". Tendré que ir a por ella.\n",
                       "le dice algo a " + TNAME + ".\n"}));
        KeeperEmote("se levanta de detrás del mostrador y parece concentrarse "
                    "intensamente. Al poco, observas como aparece de la nada "
                    "una puerta dimensional que " + KeeperName(K_CAP) + " "
                    "atraviesa rápidamente.\n"
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
    // por alguna razón el objeto no se pudo mover a la caja.
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
        KeeperEmote(({"se levanta de detrás del mostrador portando en sus "
                      "manos " +desc + " que le has dado.\n"
                      "Entra en el almacén, y al poco vuelve a salir con "
                      "las manos vacías y se sienta de nuevo.\n",
                      "se levanta de detrás del mostrador portando en sus "
                      "manos " + desc + " que le ha dado " + TNAME + ".\n"
                      "Entra en el almacén, y al poco vuelve a salir con las "
                      "manos vacías.\n"}));
    }
    else
    {
        KeeperEmote("saca un llavero de debajo del mostrador e inserta una de "
                    "las llaves en la cerradura de la caja.\n"
                    "Escuchas un leve ¡click!, y la tapa se abre.\n" +
                    KeeperName(K_CAP) + " coloca " + desc + " dentro de la caja "
                    "y vuelve a cerrarla.\n"
                    "Luego, la coge y la guarda en el almacén.\n");
    }
    // si el player está conectado, se le avisa de la introducción del objeto.
    if (pl = find_object(destinatario))
    {
        tell_object(pl,W(TNAME + " ha puesto " + desc + " en tu caja de "
                         "seguridad.\n"));
    }
    // añado un log_file para ver cuantos objetos se introducen.
    log_file("securebox/EXCHANGES",ctime(time()) + ". " +
             TNAME + " ha introducido " + desc + " (pagando una comisión "
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
        case "pequeña": iTamano = 1; break;
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
