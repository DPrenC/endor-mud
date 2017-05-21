/***
fichero: caja.c
Autor: kastwey@simauria
Descripción: Objeto que se guardará con su contenido.
Esta es una caja de seguridad para las consignas.
Para guardar he usado y modificado la función save_me del player.c
Fecha inicio: 16/08/2004
***/

#include <securebox.h>
#define OB_AO            (m["Gender"] == 2?"a":"o")
// definición de coger o mirar.
// esto sirve para pasarlo como parámetros a las funciones comprobar_numeros
// y comprobar_plural para que en caso de encontrar coincidencias o bien miren
// el objeto, o bien lo cojan.
#define M_MIRAR          1
#define M_COGER          2
// mostrar o no mensajes al usar el mirar_objeto y mirar_objetos
#define MOSTRAR_MENSAJES 0
#define OCULTAR_MENSAJES 1
// simplificar en la función enumerar
#define SIMPLIFICAR      1
// propiedades a conservar al guardar objetos:
#define PROPS_CONSERVAR  ({P_LONG,P_SHORT,P_QUALITY,P_SIZE,P_GENDER,P_IDS,\
P_CLASS_IDS,P_NAME,P_NOTAKE,P_WEIGHT,P_QUALITY_MSG})
// ids de la caja
#define IDS_ABR_CER      ({"caja","caja de seguridad","la caja",\
"la caja de seguridad","caja fuerte","la caja fuerte","tapa","la tapa",\
"tapa de la caja","la tapa de la caja","la tapa de la caja de seguridad"})
#define IDS_TAPA         ({"tapa","la tapa","tapa de la caja","la tapa de la caja",\
"la tapa de la caja de seguridad","la tapa de la caja fuerte",\
"tapa de la caja fuerte"})

inherit CONTAINER;

int cmd_colocar(string str);
public int coger_objetos(mixed num_objeto);
public string short_objeto(int num_objeto);
public int QueryEstado();
public int comprobar_numero(string que, int numero, int accion);
public int comprobar_plural(string que, int accion);
public string AjustaCapacidadRest();
public int SetUltimoPago(int tiempo);
public int QueryUltimoPago();
public string QueryCapacidadRest();
public string GetQuality(int calidad, string gender);
public varargs string mirar_objeto(int num_objeto, int mensajes);
public varargs int buscar(string nombre, int base, int *exclude);
public varargs mixed buscar_objetos(string nombre, mixed arg1, mixed arg2);
public void ActualizaObjetos();
void mirar_tapa();
public int es_consonante_p_t_z(string letra);
public  int es_vocal(string letra);
public varargs string mirar_objetos(mixed num_objeto, int mensajes);
public string QueryObjetos();
public string *plural(string str);
int cmd_abrir(string str);
int cmd_cerrar(string str);
int cmd_permiso(string str);
int validar_nombre_permisos(string str);
public varargs string enumerar(string *arr, int simplificar);
public int SetTransitando(status trans);
public int borrar_objeto(object ob);
public int QueryTransitando();
public mapping QueryInventory();
public mapping SetInventory(mapping inv);
public string SetSitioTraslado(string sitio);
public string QuerySitioTraslado();
public int RecuperaVariables(string ruta);
public int GuardaVariables(string ruta);
public object SetOwner(object ob);
public object QueryOwner();
public int SetTamano(int tam);
public int QueryTamano();
public int SetMaxObj(int max);
public int QueryMaxObj();
public int AjustaTamano();
public int QueryObjects();
public int AddPermiso(string nombre);
public int RemovePermiso(string nombre);
public mapping QueryPermisos();
public void ListarPermitidos();
public int QueryPermitir();
public int AddObjGuest(string nombre, string obj, string fecha);
public string QueryPlace();
public string SetPlace(string lugar);
public string QueryPlaceFileName();
public string SetPlaceFileName(string name);

static string pContenido;
static string pCapacidadRest;
static int pEstado = 0;
static int pColocando;
static mixed *pIdx;
static object pOwner;
int pPesoTotal, pTransitando, pPermiso, pTamano, pMaxObj, pUltimoPago;
string pSitioTraslado, pPlace, pObjetos, pPlaceFileName;
mapping pPermisoLista, inventory;


init()
{
    ::init();
    add_action("cmd_permiso","permiso");
    add_action ("cmd_mirar","m",AA_SHORT);
    add_action("cmd_coger","coger");
    add_action ("cmd_colocar","poner");
    add_action ("cmd_colocar","dejar");
    add_action("cmd_abrir","abrir");
    add_action("cmd_cerrar","cerrar");
}

create()
{
    ::create();
    pPermisoLista = ([]);
    inventory = ([]);
    SetShort("Una caja de seguridad");
    SetLong(W("Es una gran caja rectangular de metal macizo.\n"
              "En su parte superior, tiene una tapa del mismo metal, con una "
              "gran cerradura que parece muy resistente.\n"));
    SetWeight(0);
    SetMaxIntWeight(100000);
    SetNoGet("Una fuerza mágica parece haber pegado la caja al suelo. Te es "
             "imposible cogerla.\n");
    AddSubDetail(({"cerradura"}),W("Se trata de una cerradura que parece muy "
                                   "resistente.\nAunque ahora está abierta, "
                                   "te da la impresión de que sería "
                                   "totalmente imposible abrirla sin la "
                                   "llave correspondiente.\n"));
    AddSubDetail(({"tapa","tapa de metal","tapa de caja","tapa de la caja"}),
                 #'mirar_tapa);
    AddId(({"caja","caja de seguridad","caja fuerte"}));
}


private void SaveObject(object ob)
// guarda un objeto en la caja, añadiéndolo al mapping inventory.
{
    string objeto;
    int n, value, i, j;
    mixed args;
    mapping m;
    string bl_obj;
    // guardamos las propiedades del objeto y lo añadimos al inventory
    // al string objeto se asigna el path del objeto actual
    objeto=object_name(ob) + "#" + time();
    // asignamos a bl_obj el blueprint del objeto
    bl_obj = blueprint(ob);
    // asignamos al mapping m las propiedades que necesitamos conservar
    m = filter(ob->QueryProperties(),(:(   $2 != $3->Query($1)
                                        || member(PROPS_CONSERVAR,$1) >= 0)
                                     :),bl_obj);
    m[P_WEIGHT] = ob->QueryWeight(1);
    // añadimos al mapping del inventory el objeto con las propiedades
    // que hemos dejado en el mapping m.
    inventory+=([objeto: m]);
}

public int coger_objetos(mixed num_object)
// esta función intenta mover al inventario del player los objetos pasados
// en el array de identificador del pIdx.
{
    int i, j, val, contador;
    object ob;
    // variable objeto para clonar el objeto desde la variable inventory,
    // asignarle propiedades e intentar moverlo al player.
    string *mensajes = ({});
    // array donde se almacenan los objetos que no se han podido coger.
    string *mensajes_coger = ({});
    // aquí se irán almacenando las cosas que se han podido coger
    // y las que no
    mapping m;
    string cosas_cogidas, *attrs;
    if (pEstado == BOX_CLOSED)
    {
        return notify_fail("No ppuedes coger nada de la caja. Está "
                           "cerrada!\n",NOTIFY_NOT_VALID);
    }
    if (intp(num_object)) num_object = ({num_object});
    contador = sizeof(num_object);
    for (i=0;i<contador;i++)
    // se recorre el array de identificadores para ir clonando los objetos.
    {
        if (stringp(num_object[i]))
        // es un string, por lo cual, este elemento no fue encontrado.
        {
            mensajes += ({"No encuentras " + num_object[i] + " para coger.\n"});
        }
        else
        {
            m=inventory[pIdx[num_object[i]]];
            // m recibe el maping conteniendo el nombre y todas las propiedades
            // del objeto que vamos a clonar.
            if (m[P_NOTAKE])
            {
                mensajes += ({(intp(m[P_NOTAKE])?"No puedes coger " +
                                                 short_objeto(num_object[i]):
                                                 m[P_NOTAKE])
                            });
                break;
            }
            else
            {

                if (ob=clone_object(blueprint(pIdx[num_object[i]])))
                // se ha clonado.
                {
                    ob->SetProperties(m);
                    // aquí se comprueba si se puede coger o no, y si se puede,
                    // se intenta mover. se comprueba el resultado del move y
                    // se introducen los diferentes mensajes.
                    if (val = ob->move(TP) == ME_OK)
                    // se ha movido sin problemas
                    {
                        mensajes_coger += ({short_objeto(num_object[i])});
                        inventory = m_delete(inventory,pIdx[num_object[i]]);
                    }
                    else if (val == ME_TOO_HEAVY)
                    // demasiado pesado
                    {
                        mensajes +=({short_objeto(num_object[i]) + " es "
                                     "demasiado grande.\n"});
                    }
                    else if (val == ME_TOO_MANY)
                    // lleva demasiadas cosas en el inventario
                    {
                        mensajes += ({"Llevas demasiadas cosas en tu "
                                     "inventario para coger " +
                                      short_objeto(num_object[i]) + ".\n"});
                    }
                    else
                    // a saber porqué no se ha podido coger
                    {
                        mensajes += ({"No puedes coger " +
                                      short_objeto(num_object[i]) + ".\n"});
                    }
                }
            }
        }
    }
    if (sizeof(mensajes_coger))
    // si se ha cogido algo...
    {
        // Ahora se unifican los objetos del mensajes_coger, para que si hay
        // objetos con las mismas descripciones aparezcan como uno sólo y el
        // número de dichos objetos.
        // devuelvo las cosas que no se han podido coger, junto con las que sí.
        write (implode(mensajes,"") + W("Coges " +
               (cosas_cogidas = enumerar(mensajes_coger,SIMPLIFICAR)) + ".\n"));
        say(W(TNAME + " coge " + cosas_cogidas + ".\n"));
    }
    else
    {
        // no se ha cogido nada de lo que se intentó coger.
        write (implode(mensajes,"") + "No coges nada.\n");
    }
    ActualizaObjetos(); // actualizo los objetos de la caja.
    // actualizado los objetos de la caja (para las funciones de mirar, coger
    // y demás
    return 1;
}

int allow_enter(int method, mixed extra)
{
    // compruebo si un objeto se puede o no colocar en la caja.
    object *ContenidoObjeto = all_inventory(PO);
    string desc = (PO->QueryShort() || PO->QueryName() || "algo");
    int val;
    if (    PO->QueryWeight() + TO->QueryWeight() > TO->QueryMaxWeight()
         || sizeof(inventory) > pMaxObj - 1)
    // lo siento... no cabe
    {
        write (W("Intentas meter " + desc + " en la caja, pero parece ser "
                 "que es demasiado grande.\n"));
        return ME_NO_ENTER;
    }
    if (sizeof(ContenidoObjeto))
    // el objeto que se intenta colocar dentro es un contenedor que lleva
    // objetos en su interior.
    {
        write (W(capitalize(desc) + " contiene objetos en su interior.\n"
                 "Para introducirlo en la caja, deberás extraer lo que hay " +
                 "dentro de " + desc + ".\n"));
        return ME_NO_ENTER;
    }
    if (living(PO))
    // Está intentando meter a un bicho vivo!
    {
        write (W("Como vas a meter ahi a " + desc + "? Seguro que se muere "
                 "de hambre!\n"));
        return ME_NO_ENTER;
    }
    if (member(inherit_list(PO),"/std/corpse.c") >= 0)
    {
        // intenta meter a un cadáver
        write (W("Cuando vas a colocar " + desc + " en la caja, piensas "
                 "que quizás este no sea el mejor sitio... Decides no "
                 "hacerlo.\n"));
        return ME_NO_ENTER;
    }
    if (member(inherit_list(PO),"/obj/money.c") >= 0)
    // nada nada. para meter dinero están los  bancos.
    {
        write (W("No crees que para almacenar dinero ya están los bancos?\n"));
        return ME_NO_ENTER;
    }
    // se intenta meter... se usa la función por herencia.
    val = ::allow_enter(method, extra);
    if (val == ME_OK)
    {
        pPesoTotal +=PO->QueryWeight();
        SaveObject(PO);
        if (!pColocando)
        {
            call_out("ActualizaObjetos",1);
            pColocando = 1;
        }
        call_out("borrar_objeto",1,PO);
        // se borra el objeto de dentro de la caja. ya no sirve para nada ahí.
    }
    return val;
}


public object SetOwner(object ob) { return pOwner = ob; }

public object QueryOwner() { return pOwner; }

public int SetTamano(int tam)
{
    pTamano = tam;
    return AjustaTamano();
}

public int AjustaTamano()
{
    string long;
    switch(pTamano)
    // según el tamaño se asigna una descripción y unas características.
    {
        case 1:
            SetShort("una caja de seguridad pequeña");
            long = W("Es una pequeña caja rectangular de metal macizo.\n");
            SetMaxIntWeight(25000);
            SetMaxObj(30);
            break;
        case 2:
            SetShort("una caja de seguridad mediana");
            long = W("Es una caja rectangular de metal macizo.\n"
                     "Aunque no es una de las cajas más grandes, la verdad es que "
                     "es muy espaciosa y caben bastantes objetos.\n");
            SetMaxIntWeight(50000);
            SetMaxObj(60);
            break;
        case 3:
            SetShort("una caja de seguridad grande");
            long = "Es una gran caja rectangular de metal macizo.\n";
            SetMaxIntWeight(100000);
            SetMaxObj(90);
            break;
        default:
            return pTamano;
            break;
    }
    SetLong(long + W("En su parte superior, tiene una tapa del mismo metal, "
                   "con una gran cerradura que parece muy resistente.\n"
                   "En uno de sus lados, hay una etiqueta en la que se lee: "
                   "Caja propiedad "
                   "de " + capitalize(pOwner->QueryName()) + ".\n"));
    return pTamano;
}

public int QueryTamano() { return pTamano; }




public int SetMaxObj(int max) // objetos máximos que cabrán en la caja
{
    return pMaxObj = max;
}

public int QueryMaxObj() { return pMaxObj; }

public int QueryObjects() // número de objetos de la caja
{
    return sizeof(inventory || ({}));
}

public int AddPermiso(string nombre) // añade a un jugador a la lista de permitidos de la caja.
{
    if (member(pPermisoLista, nombre))
    // el jugador nombre ya estaba en la lista...
    {
        return 0;
    }
    // se añade.
    pPermisoLista +=([nombre:0;0;0]);
    return 1;
}


public int RemovePermiso(string nombre) // borra el permiso a un jugador
{
    if (pPermisoLista[nombre])
    // lo borramos
    {
        m_delete(pPermisoLista,nombre);
        return 1;
    }
    // no hay ningún jugador en la lista con ese nombre.
    return 0;
}


public mapping QueryPermisos() // devuelve un mapping con la lista de permitidos de la caja.
{
    return deep_copy(pPermisoLista);
}

public void ListarPermitidos()
// lista los players a los que se les permite poner cosas en esta caja.
{
    string texto, *indices;
    int i;
    texto = "Lista de jugadores a los que se les permitirá colocar cosas en "
            "su caja de seguridad:\n\n"
            "Nombre    |         objetos añadidos |  último objeto   |   "
            "fecha de colocación\n";
    indices = m_indices(pPermisoLista);
    if (!sizeof(indices))
    // la lista está vacía
    {
        write (W("No tienes permitido a ningún jugador la introducción de "
                 "objetos en tu caja de seguridad.\n"));
        return;
    }
    indices = sort_array(indices,(:$1 > $2:));
    for (i=0; i < sizeof(indices);i++)
    {
        if (!pPermisoLista[indices[i]])
        {
            texto += sprintf("%-20s%-20d", indices[i], 0);
        }
        else
        {
            texto += sprintf("%-20s%-20d%-20s%-20s",indices[i], pPermisoLista[indices[i]],
                             pPermisoLista[indices[i], 1], pPermisoLista[indices[i], 2]) + "\n";
        }
    }
    if (pPermiso == BOX_PERMISSION_NONE)
    // la lista de permisos está desactivada
    {
        texto += W("\nRecuerda que actualmente la lista de permitidos está "
                   "desactivada. Por tanto, aunque tengas jugadores en ella, "
                   "estos no podrán introducir cosas en tu caja hasta que no "
                   "la actives con el comando 'permiso si'.\n"
                   "\n\nPara borrar a algún jugador de tu lista de "
                   "permitidos, escribe permiso borrar <nombrejugador>.\n"
                   "Por ejemplo: borrar permiso " + TNREAL + ".\n"
                   "Para agregar el permiso a algún jugador, escribe: "
                   "permiso agregar <nombrejugador.\n");
    }
    else if (pPermiso == BOX_PERMISSION_ALL)
    // están activados los permisos para todos los jugadores.
    {
        texto += W("\nAtención! Recuerda que actualmente tienes activada la "
                   "modalidad de permisos 'todos'. Con esta modalidad, "
                   "todos los jugadores podrán poner cosas en tu caja, sin "
                   "tener en cuenta la lista de permisos anterior.\n"
                   "Para restringir el permiso únicamente a la lista, "
                   "escribe permiso si.\n");
    }
    "/obj/lib/string"->smore(texto,TP->QueryPageSize());
    // se pasa al string del /obj para dividirlo en páginas si fuera necesario.
    return;
}

int validar_nombre_permisos(string str)
// devolverá 1 si es posible agregar / borrar un permiso referente al nombre
// pasado como parámetro.
{
    if (str) str = lower_case(str);
    if (str == "")
    // no se especificó el jugador que se desea agregar
    {
        return  notify_fail  (W("Debes escribir el nombre del jugador al "
                                "que quieres agregar el permiso.\n"),
                                NOTIFY_NOT_VALID);
    }
    if (sizeof(explode(str," ")) > 1)
    // el nombre del jugador tiene espacios... así que no se puede.
    {
        return  notify_fail (W("El nombre del personaje no puede contener "
                               "más de una palabra... No uses "
                               "espacios.\n"));
    }
    else if (file_size(SAVEPATH + str[0..0] + "/" + str + ".o") == -1)
    // el jugador no existe, ya que no existe su archivo de ficha
    {
        return  notify_fail (capitalize(str) + " no existe en "
                             "Simauria.\n");
    }
    else if (str == TP->QueryRealName())
    /// El propio player se quiere agregar a sí mismo
    {
        return  notify_fail (W("Como titular de la caja, no necesitas "
                               "agregarte ningún permiso para introducir "
                               "cosas en ella...\n"));
    }
    else
    {
        return 1;
    }
}


int cmd_permiso(string str)
// función para llamar a las diversas funciones de permisos
// además de para mostrar información sobre su uso
{
    string str2;
    if (str) str = lower_case(str);
    if (!str || (   str != "si" && str != "sí" && str != "todos"
                 && str[0..6] != "agregar" && str[0..5] != "borrar"
                 && str != "no" && str != "info" && str != "lista"))
    {
        return  notify_fail (W("Uso:\n"
                               "permiso lista: muestra la lista de jugadores "
                               "a los que les permites colocar cosas en tu "
                               "caja.\n"
                               "permiso si / todos / no: Activas la lista de "
                               "permitidos, el permiso a todos los jugadores "
                               "o desactivas los permisos a que otros "
                               "jugadores coloquen cosas en tu caja.\n"
                               "permiso agregar <nombrejugador>: Agregas un "
                               "permiso al jugador <nombrejugador>.\n"
                               "permiso borrar <nombrejugador>: Borras de la "
                               "lista de permisos al jugador <nombrejugador>.\n"
                               "permiso info: Te muestra más información "
                               "sobre el uso de los permisos y sus diferentes "
                               "modos de funcionamiento.\n"));
    }

    if (str == "info")
    {
        string texto;
        texto = "Información sobre los permisos.\n\n"
                "La función de la lista de permisos y de sus diversas "
                "modalidades, te permite una fácil gestión de los jugadores a "
                "los que deseas permitir el acceso (solo para introducir "
                "objetos) a tu caja de seguridad.\n"
                "Las tres modalidades de acceso permitidas son:\n"
                "-permiso si: Permites la colocación de objetos en tu caja "
                "únicamente a los jugadores que tengas incluidos en la lista "
                "de permisos.\n"
                "-permiso no: Deniegas el permiso a todos los jugadores, "
                "incluidos los de la lista de permitidos.\n"
                "-permiso todos: Permites a todos los jugadores colocar "
                "objetos en tu caja de seguridad, sin tener en cuenta la "
                "lista de permitidos.\n\n"
                "Para agregar un jugador a la lista, escribe permiso agregar "
                "                nombrejugador.\n"
                "Por ejemplo: permiso agregar kastwey: agregaría a Kastwey a "
                "la lista de permisos.\n\n"
                "Para borrar a un jugador de la lista de permitidos escribe: "
                "permiso borrar <nombrejugador>.\n"
                "Por ejemplo: permiso borrar kastwey: borrarías a Kastwey "
                "de la lista.\n\n"
                "Para ver la lista de jugadores permitidos, el último "
                "objeto colocado y la fecha de inclusión de dicho objeto, "
                "escribe permiso lista.\n";
        texto = W(texto);
        "/obj/lib/string"->smore(texto,TP->QueryPageSize());

        return 1;
    }

    if (str == "lista")
    {
        ListarPermitidos();
        return 1;
    }
    if (sscanf(str,"agregar %s",str2) == 1)
    // se va a agregar un permiso.
    {
        if (!validar_nombre_permisos(str2)) return 0;
        if (AddPermiso(str2))
        {
            write (W("Añadido al jugador " + capitalize(str2) + " a la lista "
                     "de permitidos.\n"));
            return 1;
        }
        return  notify_fail (W(capitalize(str2) + " ya tenía permiso "
                               "para guardar cosas en tu caja.\n"));
    }

    if (str[0..5] == "borrar")
    // se va a borrar a un jugador
    {
        str2 = "";
        sscanf (str,"borrar %s",str2);
        if (!validar_nombre_permisos(str2)) return 0;
        if (RemovePermiso(str2))
        {
            write (W("eliminado al jugador " + capitalize(str2) + " de tu "
                     "lista de permitidos.\n"));
            return 1;
        }
        return  notify_fail (W(str2 + " no se encontraba en tu lista de "
                               "permitidos.\n"));
    }
    if (str == "si" || str == "sí")
    // se activa la lista de permitidos
    {
        if (pPermiso == BOX_PERMISSION_LIST)
        {
            return  notify_fail ("La lista de permitidos ya estaba "
                                 "activada.\n",NOTIFY_NOT_VALID);
        }
        pPermiso = BOX_PERMISSION_LIST;
        write ("Activando lista de permitidos.\n");
        return 1;
    }
    if (str == "todos")
    // activar el permiso a todos los jugadores, independientemente de la
    // lista.
    {
        if (pPermiso == BOX_PERMISSION_ALL)
        {
            return  notify_fail ("Esta modalidad de permiso ya estaba "
                                 "activada.\n",NOTIFY_NOT_VALID);
        }
        pPermiso = BOX_PERMISSION_ALL;
        write (W("Activando permiso a todos los jugadores.\n"
                 "Atención! Recuerda que ahora se permitirá a todos los "
                 "jugadores introducir objetos en tu caja de seguridad.\n"));
        return 1;
    }
    if (str == "no")
    // Desactivar los permisos
    {
        if (pPermiso == BOX_PERMISSION_NONE)
        {
            return  notify_fail ("la lista de permitidos ya estaba "
                                 "desactivada.\n",NOTIFY_NOT_VALID);
        }
        pPermiso = BOX_PERMISSION_NONE;
        write ("Desactivando lista de permitidos.\n");
        return 1;
    }
}


public int QueryPermitir() { return pPermiso; }

public int AddObjGuest(string nombre, string obj, string fecha)
// Añade un objeto con la modalidad de permisos.
// Se añade el nombre, la fecha y la descripción del objeto introducido.
{
    pPermisoLista[nombre]++;
    pPermisoLista[nombre,1] = obj;
    pPermisoLista[nombre,2] = fecha;
    return 1;
}


public string SetPlace(string lugar)
// ajusta el lugar de la caja
{
    return pPlace = lugar;
}

public string QueryPlace() { return pPlace; }

public string SetPlaceFileName(string name)
// ajusta el path del objeto oficina donde está la caja
{
    return pPlaceFileName = name;
}

public int RecuperaVariables(string ruta)
// recupera las variables del fichero dado en ruta
{
    int val = restore_object(ruta);
    ActualizaObjetos(); // se actualizan los objetos para las funciones mirar y coger
    return val;
}

public int GuardaVariables(string ruta)
// se guardan las variables del objeto en el archivo especificado en ruta
{
    return save_object(ruta);
}

public string QueryPlaceFileName() { return pPlaceFileName; }


public int SetTransitando(int trans)
// ajusta el estado de transitando, que determina si una caja está siendo trasladada
// entre dos oficinas.
// esto sirve para evitar que un player pueda coger cosas de su caja mientras
// otro player está colocando cosas en la caja del player 1y la caja está
// viajando a la oficina del segundo player
{
    return pTransitando = trans;
}

public int QueryTransitando() { return pTransitando; }

public string SetSitioTraslado(string sitio)
// ajusta el sitio al que está siendo trasladada la caja
{
    return pSitioTraslado = sitio;
}

public string QuerySitioTraslado() { return pSitioTraslado; }


public string *plural(string str)
// función que, dada una palabra en plural, devuelve sus posibles palabras en singular
// He probado con muchas palabras y funciona... Espero que funcione
// realmente con todas :)
{
    // si no cumple ciertas condiciones, no puede ser plural.
    if (!str || str[<1..<1] != "s" || strlen(str) < 3) return ({});
    if (str[<2..<1] == "es" && es_consonante_p_t_z(str[<3..<3]))
    {
        if (str[<3..<3] == "c")
        {
            return ({str[0..<4] + "z",str[0..<3],str[0..<2]});
        }
        else return ({str[0..<3],str[0..<2]});
    }
    else if (es_vocal(str[<2..<2]))
    {
        return ({str[0..<2]});
    }
    else return ({});
}



public int es_consonante_p_t_z(string letra)
// función para saber si una letra dada es consonante distinta de p, t o z
// complementa a la función plural
{
    letra = lower_case(letra);
    return member(({"a","e","i","o","u","p","t","z"}),letra) < 0;
}

public int es_vocal(string letra)
// función para saber si una letra dada es o no vocal
// complementa a la función plural
{
    letra=lower_case(letra);
    return member(({"a","e","i","o","u"}),letra) >= 0;
}


public mapping QueryInventory()
// devuelve el inventario
{
    return deep_copy(inventory);
}

public void ActualizaObjetos()
// actualiza las variables de control de objetos:
// pObjetos, pContenido, pPesoTotal y pIdx.
{
    int i, j;
    mapping m, cosas;
    string objetos, contenido;
    mixed idx;
    int *arr_objetos = ({});
    pColocando = 0;
    AjustaCapacidadRest();
    if (!sizeof(inventory))
    // la caja está vacía
    {
        pIdx=({});
        pContenido = "No contiene nada.";
        pObjetos = "La caja está vacía.\n";
        pPesoTotal=0;
        if (pOwner)
        {
            GuardaVariables(SAVEBOXPATH + "/" + pOwner->QueryRealName()[0..0] +
                            "/" + pOwner->QueryRealName());
        }
        return;
    }
    pIdx=m_indices(inventory||([]));
    pPesoTotal=0;
    cosas = ([]);
    for (i=sizeof(pIdx); i--;)
    {
        m=inventory[pIdx[i]];
        pPesoTotal+=m[P_WEIGHT];
        // se van sumando los pesos para dar al final el peso total de
        // todos los objetos
        arr_objetos+=({i});
        // se añade al arr_objetos el identificador del objeto actual
        cosas[short_objeto(i)]++;
        // se añade al mapping cosas para conformar la agrupación de elementos
    }
    objetos = mirar_objetos(arr_objetos,OCULTAR_MENSAJES);
    // se asigna a la variable objetos los objetos de la caja.
    idx = m_indices(cosas);
    contenido = "";
    for (i=0;i<sizeof(idx);i++)
    {
        contenido += idx[i] + (cosas[idx[i]] > 1?" [" + cosas[idx[i]] + "]":
                               "") + ".\n";
    }
    pContenido = "Contiene:\n" + contenido;
    if (objetos == "") objetos = "La caja está vacía.\n";
    pObjetos = objetos;
    if (pOwner)
    {
        GuardaVariables(SAVEBOXPATH + "/" + pOwner->QueryRealName()[0..0] +
                        "/" + pOwner->QueryRealName());
    }
    return;
}


public int borrar_objeto(object ob)
// borra el objeto pasado como parámetro
{
    ob->remove();
    if (ob) destruct(ob);
    if (ob) return 0;
    return 1;
}


public varargs string QueryLong(string what)
{
    if (pEstado == BOX_CLOSED)
    {
        return ::QueryLong() + "La tapa está cerrada.\n";
    }
    return ::QueryLong() + W("La caja está abierta y " + pCapacidadRest +
                             ".\n" + pContenido);
}



int cmd_mirar(string str)
// función que controla la acción mirar
{
    string que, *acc;
    mixed objetos;
    if (!str) return 0;
    if (member(({"m","mi","mir","mira","mirar"}),query_verb()) < 0) return 0;
    if (member(IDS_TAPA,str) >= 0)
    {
        mirar_tapa();
        return 1;
    }
    if (!sscanf(str,"%s de caja",que)) return 0;
    if (pEstado == BOX_CLOSED)
    {
        write("La caja está cerrada. No puedes mirar en su interior.\n");
        return 1;
    }
    if (pColocando) ActualizaObjetos();
    if (que == "todo")
    // equivalente a : mirar todo de caja
    {
        "/obj/lib/string"->smore(pObjetos,TP->QueryPageSize());
        say (W(TNAME + " mira en el interior de la caja de seguridad.\n"));
        return 1;
    }
    objetos = buscar_objetos(que);
    if (pointerp(objetos) || objetos != -1)
    {
        write(mirar_objetos(objetos));
        return 1;
    }
}




public string QueryObjetos()
// devuelve los objetos de la caja, en formato de cadena:
// Un vial de regeneración [7], una daga [2], un sombrerito y una espada.
{
    return pObjetos;
}


public varargs string mirar_objeto(int num_objeto, int mensajes)
// dado un número perteneciente al array de objetos dentro de la
// variable pIdx, se devuelve la descripción de dicho objeto.
{
    mapping m;
    string mensaje = "", quality, talla;
    m = inventory[pIdx[num_objeto]];
    if (m[P_LONG])
    // está la propiedad Long, así que se añade
    {
        mensaje = m[P_LONG];
    }
    if (m[P_QUALITY] && m[P_QUALITY_MSG])
    // Está la calidad
    {
        quality = GetQuality(m[P_QUALITY],(m[P_GENDER] == 2?"a":"o"));
        mensaje += "Está " + quality;
        if (m[P_SIZE])
        // si existe tamaño
        {
            switch (m[P_SIZE])
            {
                case 1:
                    talla = "bastante pequeñ" + OB_AO;
                    break;
                case 2:
                    talla = "de talla normal";
                    break;
                case 3:
                    talla = "bastante grande";
                    break;
            }
            mensaje += " y es " + talla + ".\n";
        }
        else
        {
            mensaje += ".\n";
        }
    }
    if (mensajes == MOSTRAR_MENSAJES)
    {
        say (W(TNAME + " mira " + short_objeto(num_objeto) + " en una caja "
               "de seguridad.\n"));
    }
    return mensaje;
}

public varargs int buscar(string nombre, int base, int *exclude)
// devuelve la posición dentro del array de identificadores, donde coincida
// el nombre pasado como parámetro.
// empezará a contar desde el elemento pasado como base.
// si se le pasa un array de exclude, excluirá de la búsqueda a dichos
// números
{
    string *ids_obj;
    mapping m;
    int i, encontrado;
    if (base > QueryObjects()) return -1;
    for (i=base;i<sizeof(pIdx); i++)
    {
        m=inventory[pIdx[i]];
        if (m[P_IDS]) ids_obj = m[P_IDS];
        if (m[P_NAME]) ids_obj +=({m[P_NAME]});
        if (m[P_CLASS_IDS])
        {
            // write (implode(m[P_IDS]," ") + "\n\n");
        }
        ids_obj += m[P_CLASS_IDS];
        if (member(ids_obj,nombre) >= 0 && member(exclude || ({}),i) < 0)
        // se encontró una coincidencia
        {
            encontrado = 1;
            break;
        }
    }
    if (encontrado) return i;
    return -1;
}


public int comprobar_numero(string que, int numero, int accion)
// comprueba si la cadena que y el número "numero" corresponde a un objeto
// dentro de la caja
{
    // comprueba el objeto n de la colección.
    // si no está, pos devuelve 0 y se lo pasa al siguiente de la lista :)
    // al encontrar una coincidencia, suma 1 a un contador, y así hasta que
    // llega al número especificado en el segundo parámetro.
    int i, num_objeto = -1;
    do
    {
        if ((num_objeto = buscar(que,num_objeto + 1)) >= 0) i++;
    } while (i < numero && num_objeto >= 0);
    if (i == numero)
    // se ha encontrado el objeto "que" con el numero "numero"
    {
        // dependiendo del parametro accion
        if (accion == M_MIRAR)
        {
            write (mirar_objeto(num_objeto,MOSTRAR_MENSAJES));
            return 1;
        }
        return coger_objetos(num_objeto);
    }
    else return 0;
}


public string GetQuality(int calidad, string gender)
// dado un número, devuelve la calidad correspondiente
{
    string quality;
    switch(calidad)
    {
        case 0..4:
            quality = "rot" + gender + " y doblad" + gender;
            break;
        case 5..24:
            quality = "seriamente machacad" + gender;
            break;
        case 25..49:
            quality = "seriamente dañad" + gender;
            break;
        case 50..74:
            quality = "dañad" + gender;
            break;
        case 75..94:
            quality = "ligeramente dañad" + gender;
            break;
        case 95..100:
            quality = "en perfecto estado";
            break;
        default:
            quality = "en perfecto estado";
            break;
    }
    return quality;
}

public varargs mixed buscar_objetos(string nombre, mixed arg1, mixed arg2)
// función que devuelve uno o varios números, correspondientes a
// los identificadores de los objetos encontrados con el parámetro <nombre>.
// devuelve -1 si no lo encuentra.
// si se le pasa un límite de objetos, dará como máximo de números
// ese límite, aunque haya más.
// si se le pasan números en el exclude, estos números no se tendrán en cuenta.
{
    int *numeros = ({}), num_objeto = -1, i, num, limite, *exclude, *nm;
    int *n_aux, contador;
    string *palabras, str_obj, *objetos = ({}), *aux = ({});
    mixed ob_encontrados = ({});
    if (!nombre) return -1;
    // asignamos a limite y a exclude sus correspondientes valores,
    // basándonos en el tipo de valor que corresponde a cada uno.
    limite = (intp(arg1) && arg1) || (intp(arg2) && arg2) || 0;
    exclude = (pointerp(arg1) && arg1) || (pointerp(arg2) && arg2) || ({});
    if ((num_objeto = buscar(nombre, 0, exclude)) >= 0)
    // se ha encontrado
    {
        return num_objeto;
    }
    // comprobamos si en la cadena hay más de un objeto
    if (strstr(nombre," y ") >= 0 || strstr(nombre,", ") >= 0)
    {
        // si es así, dividimos la frase entre sus yes y sus comas
        aux = explode(nombre,", ");
        foreach(string parte:aux) objetos += explode(parte," y ");
        if (!exclude) exclude = ({});
        for (i=0;i<sizeof(objetos);i++)
        {
            nm = buscar_objetos(objetos[i],exclude);
            if (pointerp(nm) || nm >= 0)
            {
                n_aux = (pointerp(nm)?nm:({nm}));
                ob_encontrados += n_aux;
                exclude += n_aux;
            }
            else ob_encontrados += ({objetos[i]});
        }
        return (!sizeof(ob_encontrados)?-1:ob_encontrados);
    }
    // si no se encuentra, se prueba con plurales o numéricos
    palabras = explode(nombre," ");
    // si el primero es un número, y es 0, no vale.
    if (palabras[0] == "0") return -1;
    // si la primera palabra es un número...
    if ((num = to_int(palabras[0])) != 0)
    {
        string nueva_frase = implode(palabras[1..<1]," ");
        // si el número es mayor que 1, y la palabran o es plural, la frase
        // (2 vial) no tiene sentido, así que se desecha.
        if (num >1 && !sizeof(plural(nueva_frase))) return -1;
        // se llama a esta misma función para obtener los resultados de
        // el trozo de frase.
        if ((numeros = buscar_objetos(nueva_frase,num)) == -1) return -1;
        if (   (intp(numeros) && num > 1)
            || (pointerp(numeros) && sizeof(numeros) < num))
        {
            // hay menos objetos de los que ha puesto que quería mirar / coger
            // o lo que sea.
            write("Hay menos objetos de los que piensas.\n");
        }
        return numeros;
    }

    // si el último es un número, pero es 0, no vale.
    if (palabras[<1] == "0") return -1;
    if (num = to_int(palabras[<1]))
    // es numérico
    {
        str_obj = implode(palabras[0..<2]," ");
        do
        {
            if (   (num_objeto = buscar(str_obj,num_objeto + 1)) >= 0
                && member(exclude,num_objeto || ({})) < 0) i++;
        } while (i < num && num_objeto >= 0);
        if (i == num)
        // se ha encontrado el objeto "que" con el numero "numero"
        {
            return num_objeto;
        }
        return -1;
    }
    // no es numérico, así que se intenta con el plural.
    // asignamos al array palabras los posibles singulares de la palabra
    // <nombre>
    palabras = plural(nombre);
    // si no ha encontrado posibles palabras en plural...
    if (!sizeof(palabras)) return -1;
    for (i=0;i<sizeof(palabras);i++)
    // se recorren todas las palabras para ver si alguna es un objeto de la
    // caja.
    {
        while (   (num_objeto = buscar(palabras[i],num_objeto + 1)) != -1
               && (contador < limite || !limite))
        {
            if (member(exclude || ({}),num_objeto) < 0)
            {
                numeros += ({num_objeto});
                contador++;
            }
        }
        if (sizeof(numeros)) break;
    }
    if (!sizeof(numeros)) return -1;
    return sizeof(numeros) >1?numeros:numeros[0];
}


public mapping SetInventory(mapping inv)
{
    inventory = inv;
    ActualizaObjetos();
    return inventory;
}


int cmd_coger(string str)
// acción coger
{
    string que;
    mixed objetos;
    int *arr_objs = ({}), i;
    if (!str) return 0;
    if (!sscanf(str,"%s de caja",que)) return 0;
    if (pEstado == BOX_CLOSED)
    {
        return notify_fail(W("La caja está cerrada. Quizás antes de coger "
                             "nada deberías abrirla.\n"),NOTIFY_NOT_VALID);
    }
    if (que == "todo")
    // coger todo de caja
    // se construye un array con todos los identificadores y se pasa al
    // coger_objetos
    {
        if (!sizeof(inventory))
        {
            return  notify_fail ("La caja está vacía.\n"
                                 "No coges nada.\n",NOTIFY_NOT_VALID);
        }
        for (i=0;i<sizeof(inventory);i++)
        {
            arr_objs+=({i});
        }
        coger_objetos(arr_objs);
        return 1;
    }
    if ((objetos = buscar_objetos(que)) != -1)
    {
        coger_objetos(objetos);
        return 1;
    }
    return 0;
}

public string short_objeto(int num_objeto)
// devuelve la descripción completa de un objeto
{
    mapping m;
    string desc, quality;
    m=inventory[pIdx[num_objeto]];
    desc = m[P_SHORT] || m[P_NAME] || "algo";
    if (m[P_QUALITY_MSG])
    {
        quality = GetQuality(m[P_QUALITY],OB_AO);
        desc += " " + quality;
    }
    return desc;
}

public int QueryWeight()
// sustituye a la avitual QueryWeight del objeto
// devuelve la variable pPesoTotal, que es una suma que se calcula en la función ActualizaObjetos
{
    return pPesoTotal;
}

public int SetWeight(int peso)
// Ajusta el peso de la caja.
// sustituye a la función SetWeight del objeto, y afecta a la variable pPesoTotal
{
    return pPesoTotal = peso;
}


public varargs string mirar_objetos(mixed num_objeto, int mostrar_mensajes)
// función que dado un array de identificadores dentro del pIdx, devuelve la
// descripción tanto corta como larga de los objetos pasados.
{
    string long, desc, objetos, *descripciones, *idx;
    int i;
    mapping cosas = m_allocate(0,2);
    // si el objeto es un sólo número, se le pasa a la función mirar_objeto
    if (intp(num_objeto)) return mirar_objeto(num_objeto);
    for (i=0;i<sizeof(num_objeto);i++)
    // se recorren los identificadores de objetos pasados como parámetros
    {
        // si el elemento es un string, quiere decir que no se encontró:
        if (stringp(num_objeto[i]))
        {
            write("Nno ves " + num_objeto[i] + " en la caja de seguridad.\n");
        }
        else
        {
            // se asigna a la variable long la descripción larga del objeto
            long = mirar_objeto(num_objeto[i],OCULTAR_MENSAJES);
            // se asigna a desc la descripción corta del objeto (short)
            desc = short_objeto(num_objeto[i]);
            // se añaden ambos valores al mapping cosas
            m_add(cosas,desc,cosas[desc]+1,long);
        }
    }
    // se asigna a idx los índices del mapping cosas
    idx = m_indices(cosas || ({}));
    // se asigna a descripciones el segundo valor del mapping cosas, que es donde
    // se almacenó la descripción.
    if (!sizeof(cosas)) descripciones = ({});
    else     descripciones = m_values(cosas,1||({}));
    objetos = "";
    for (i=0;i<sizeof(idx);i++)
    // se recorren los índices del array idx para unificarlos en la variable objetos
    {
        objetos += idx[i] + (cosas[idx[i]] > 1?" [" + cosas[idx[i]] + "]":"") +
                   ".\n";
        objetos += descripciones[i];
    }
    return objetos;
}


int cmd_colocar(string str)
{
    if (!str || strlen(str) < 7) return 0;
    if (str[<7..<1] == "en caja")
    {
        if (pEstado == BOX_CLOSED)
        {
            write (W("No puedes colocar nada en la caja. La tapa está "
                     "cerrada!\n"));
                           return 1;
        }
    }
    return 0;
}

public string AjustaCapacidadRest()
{
    int porc_peso, porc_objetos, porc_total;
    string mensaje;
    porc_peso = (100 * (pPesoTotal / 1000)) / (QueryMaxWeight() / 1000);
    porc_objetos = (100 * QueryObjects()) / pMaxObj;
    porc_total = (porc_peso > porc_objetos?porc_peso:porc_objetos);
    if (!sizeof(inventory)) porc_total = -1;
    switch(porc_total)
    {
        case -1:
            mensaje = "Está complétamente vacía";
            break;
        case 0..15:
            mensaje = "Está casi vacía";
            break;
        case 16..30:
            mensaje = "Aún le queda mucho espacio libre";
            break;
        case 31..49:
            mensaje = "Queda más de la mitad del espacio disponible";
            break;
        case 50..60:
            mensaje = "Queda aproximadamente la mitad del espacio disponible";
            break;
        case 61..75:
            mensaje = "Le queda algo menos de la mitad del espacio disponible";
            break;
        case 76..95:
            mensaje = "Está casi llena";
            break;
        case 96..99:
            mensaje = "Dirías que a penas queda espacio para introducir nada";
            break;
        case 100:
            mensaje = "Está completamente llena";
            break;
    }
    return pCapacidadRest = mensaje;
}

int cmd_abrir(string str)
{
    if (!str)
    {
        return  notify_fail("Abrir qué?\n",NOTIFY_NOT_VALID);
    }
    if (member(IDS_ABR_CER,str) < 0) return 0;
    if (pEstado == BOX_OPENED)
    {
        return notify_fail("La caja ya estaba abierta.\n",
                           NOTIFY_NOT_VALID);
    }
    pEstado = BOX_OPENED;
    write ("Abres la caja de seguridad.\n");
    say(W(TNAME + " abre la caja de seguridad.\n"));
    return 1;
}


int cmd_cerrar(string str)
{
    if (!str)
    {
        return  notify_fail("Cerrar qué?\n",NOTIFY_NOT_VALID);
    }
    if (member(IDS_ABR_CER,str) < 0) return 0;
    if (pEstado == BOX_CLOSED)
    {
        return notify_fail("La caja ya estaba cerrada.\n",
                           NOTIFY_NOT_VALID);
    }
    pEstado = BOX_CLOSED;
    write ("Cierras la caja de seguridad.\n");
    say(W(capitalize(TNAME) + " cierra la caja de seguridad.\n"));
    return 1;
}


public int QueryEstado() { return pEstado; }

void mirar_tapa()
{
    string msj = "La tapa es del mismo resistente metal que el resto de la "
                 "caja.\n";
    if (TP->QueryInt() > 30)
    {
        write (W(msj + "Cuando la miras más de cerca, compruebas "
                 "asombrad" + TP->QueryGenderEndString() + " que toda la caja parece hecha de "
                 "mithril... Sin duda el material más resistente que se conoce.\n"
                 "Actualmente la caja está " + (pEstado == BOX_OPENED?
                                               "abierta":"cerrada") +
                 ".\n"));
    }
    else
    {
        write (W(msj + "Te acercas más, intentando discernir de qué "
                 "material se trata, pero no consigues averiguarlo.\n"
                 "Actualmente la caja está " + (pEstado == BOX_OPENED?
                                               "abierta":"cerrada") +
                 ".\n"));
    }
}

public int SetUltimoPago(int tiempo)
{
    return pUltimoPago = tiempo;
}
public int QueryUltimoPago() { return pUltimoPago; }


public varargs string enumerar(string *arr, int simplificar)
// pasado un array de cosas, devuelve la concatenación de ellas, en el
// formato a, b, c y d.
// si se le pasa 1 en el segundo parámetro, además de concatenarlos,
// ordena los elementos iguales del modo:
// a [3], b [4] y c.
{
    string *arr2 = ({}), ob;
    int num = sizeof(arr), num_ob;

    if (simplificar)
    {
        while (num)
        {
            ob = arr[0];
            arr -= ({ob});
            num_ob = num - (num = sizeof(arr));
            arr2 += ({ob + (num_ob > 1 ? " [" + num_ob + "]" : "")});
        }
        arr = arr2;
    }
    return implode(arr[0..<2],", ")+(sizeof(arr[0..<2])?" y ":"")+arr[<1];
}

