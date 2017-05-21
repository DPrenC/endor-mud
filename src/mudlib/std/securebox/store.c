/***
fichero: almacen.c
Autor: Kastwey@simauria
Descripci�n: El almac�n de las cajas de seguridad.
Aqu� es donde se lleva al player para que haga lo que sea con su caja.
Fecha inicio: 16/08/2004
***/

#include <securebox.h>

inherit "/std/room";

object caja;
object pOficina;
public object SetOficina(object ob);
public object QueryOficina();
public void SetParams(string keeper_name, object player, object office);
public void crear_caja(object owner);
int cmd_abandonar();
public void crear_caja_nueva(object owner,int size);
void comprueba_objetos();
static object pOwner;
public object SetOwner(object ob);
public object QueryOwner();

create()
{
    ::create();
    SetIntShort("la habitaci�n de seguridad");
    SetIndoors(1);
    SetIntLight(45);
    SetIntNoise("El silencio es absoluto. Si te fijas hasta puedes escuchar "
                "los latidos de tu coraz�n.\n");
    SetIntSmell("Huele a cerrado.\n");
    AddDetail  (({"puerta"}),
              W("Es una puerta de hierro reforzado, con un pomo en su parte "
              "interior. Seguramente ser�a muy dif�cil abrirla desde fuera, "
              "a no ser que dispongas de la llave adecuada.\n"));
    AddDetail  (({"cartel","letrero"}),
              W("Se trata de un cartel pegado encima de la puerta. Quiz�s "
              "deber�as leerlo.\n"));
    AddDetail  (({"mesa","mesilla"}),(
              W("Es una mesita peque�a en la que se encuentra colocada la "
              "romana.\n")));
    AddReadMsg  (({"cartel","Cartel","letrero","Letrero"}),
               W("Normas a tener en cuenta mientras realiza sus gestiones con "
               "su caja de seguridad.\n"
               "1. No podr� introducir m�s objetos que los especificados en "
               "las caracter�sticas de su caja. As� mismo, no se permiten "
               "introducir mochilas ni otros objetos que a su vez contengan "
               "otros objetos en su interior.\n"
               "2. Aqu� podr� encontrar una romana que le permitir� pesar sus "
               "objetos, a fin de saber cuanto espacio est� ocupando en su "
               "caja.\n"
               "3. Cuando usted efect�a el alquiler de una de nuestras cajas, "
               "se le otorga el derecho a modificar siempre que quiera su "
               "contenido, asegur�ndole que ninguna persona m�s que usted "
               "tendr� acceso al contenido de ella. As� mismo, tambi�n se le "
               "suscribe autom�ticamente a un seguro contra robos, que le "
               "permitir� recuperar el valor de sus objetos si por alguna "
               "raz�n desapareciesen de nuestras instalaciones.\n"
               "4. Cualquier tentativa de robo, asesinato de nuestros "
               "empleados, o destrozos en el moviliario de nuestras "
               "instalaciones, ser� notificado autom�ticamente a la guardia "
               "local que proceder� seg�n sus pautas acostumbradas.\n"
               "5. En caso de dudas, reclamaciones, quejas o cualquier otro "
               "asunto, uno de nuestros  empleados le atender� las 24 horas "
               "del d�a.\n\n"
               "Firmado: Crizmal Mlatzem. Tesorero y administrador de las "
               "oficinas de consignas de Simauria.\n"));
    AddItem("/std/securebox/romana", REFRESH_HOME);
}

void notify_leave(mixed from,int method,mixed extra)
// Comprueba quien sale de la habitaci�n... y act�a en consecuencia
{
    if (!living(PO) || method == M_DESTRUCT || method == M_GET)
    {
        return ::notify_leave(from, method, extra);
    }
    if (PO == pOwner && present("caja fuerte"))
    // el que sale es el owner, y la caja fuerte estaba.
    {
        caja->GuardaVariables(SAVEBOXPATH +
                              pOwner->QueryRealName()[0..0] +
                              "/" + pOwner->QueryRealName());
        if (caja->QueryEstado() == BOX_OPENED)
        // la caja est� abierta... Antes de salir, simula cerrarla.
        {
            tell_object(pOwner,"Cierras la caja y sales de la habitaci�n.\n");
        }
        call_out("comprueba_objetos",1);
        // en un segundo se comprobara si el que ha salido ha sido el propietario,
        // y si ha sido as�, destruir� la habitaci�n si no hay players.
        // si no ha sido el propietario quien ha salido pero ya no est�
        // dentro (sali� antes), tb se intentar� destruir... siempre q no
        // haya players
        // dentro.
    }
    return ::notify_leave(from, method, extra);
}


public void crear_caja(object owner)
// crea una caja con los par�metros especificados (caja ya existente).
{
    caja = clone_object("/std/securebox/box");
    caja->move(TO);
    caja->RecuperaVariables(SAVEBOXPATH +
                            owner->QueryRealName()[0..0] + "/" +
                            owner->QueryRealName());
    caja->SetOwner(owner);
    caja->SetTransitando(0);
    caja->SetSitioTraslado("");
    caja->AjustaTamano();
    caja->SetPlace(pOficina->QueryPlace());
    caja->SetPlaceFileName(object_name(pOficina));
    caja->GuardaVariables(SAVEBOXPATH +
                          owner->QueryRealName()[0..0] + "/" +
                          owner->QueryRealName());
}

void comprueba_objetos()
// comprueba si la habitaci�n ya se puede destruir
{
    if (!pOwner || !present(pOwner,TO))
    // el propietario de la habitaci�n no est�, asi que o ha salido ahora
    // o ya salio antes.
    {
        if (present("caja fuerte",TO) && pOficina)
        // El propietario acaba de salir, ya que la caja fuerte sigue aqu�.
        {
            int hay_empleado;
            hay_empleado = pOficina->keeper_in_room(K_SILENT);
            tell_room(TO,W("Se abre la puerta y aparece un empleado, que coge "
                           "la caja y se la lleva.\n"
                           "Cuando va a cerrar de nuevo la puerta, te mira "
                           "con cara de sospecha y al final la deja "
                           "entreabierta.\n"));
            SetIntLong(W("Te encuentras en una habitaci�n espaciosa, aunque "
                         "sin m�s mobiliario que una mesa con una romana "
                         "encima y un cartel pegado en la puerta.\n"
                         "La puerta que tienes hacia el sur est� "
                         "entreabierta, como si el empleado la hubiese dejado "
                         "as� a prop�sito invit�ndote a salir cuanto antes "
                         "de aqu�.\n"));
            if (!hay_empleado)
            // no hay empleado
            {
	            tell_room(pOficina,
	                      W("Un ayudante se asoma desde el almac�n, y al ver "
	                        "que el empleado no est� disponible, se acerca a "
	                        "una de las habitaciones, y sale portando una "
	                        "caja.\n"
	                        "A continuaci�n, vuelve a entrar en el almac�n.\n"
	                        ));
            }
            else
            {
                tell_room(pOficina,
                          W(pOficina->KeeperName(K_CAP) + " sale de detr�s del "
                            "mostrador, y se dirige a una de las "
                            "habitaciones. Al instante, aparece con una caja "
                            "en los brazos, y tras guardarla en el almac�n, "
                            "vuelve a sentarse.\n"));
            }
            caja->remove();
        }
        if (!sizeof(filter(all_inventory(TO),(:query_once_interactive($1):))))
        {
            clean_up();
        }
    }
}



public object SetOwner(object ob)
// establece el objeto player del propietario de la habitaci�n
{
    return pOwner = ob;
}

public object QueryOwner()
// devuelve la referencia al objeto Owner de la habitaci�n
{
    return pOwner;
}


public void crear_caja_nueva(object owner,int size)
// crea una caja nueva con los par�metros especificados
{
    caja = clone_object("/std/securebox/box");
    caja->move(TO);
    if (!caja->QueryOwner()) caja->SetOwner(owner);
    caja->SetTamano(size);
    caja->SetPlace(pOficina->QueryPlace());
    caja->SetPlaceFileName(object_name(pOficina));
    caja->SetInventory(([]));
    caja->SetUltimoPago(2*TP->QueryAge());
    caja->GuardaVariables(SAVEBOXPATH + owner->QueryRealName()[0..0] + "/" + owner->QueryRealName());
    caja->SetObjetosCaja("La caja est� vac�a");
}

init()
{
    ::init();
    if (TP) TP->SetHomeTmp(pOficina);
}


int allow_enter(int method, mixed extra)
// aqu� controlo si alguien puede entrar a la room
// si no es un wiz y no es el propietario... como que no
{
    if (method != M_SPECIAL && PO->QueryIsPlayer() && PO != pOwner && !query_wiz_level(PO))
    // lo ziento.. no erez digno de entrar aqui...
    {
        tell_object (PO,W("No te est� permitido ir a este lugar.\n" +
                          capitalize(pOwner->QueryName()) + " est� en la "
                          "habitaci�n de seguridad con su caja en este "
                          "momento.\n"));
        return ME_NO_ENTER;
    }
    return ::allow_enter(method, extra);
}

public object SetOficina(object ob)
// ajusta el objeto de la oficina.
{
    return pOficina = ob;
}

public object QueryOficina()
// devuelve el objeto oficina
{
    return pOficina;
}


reset()
// si se hace un reset y no hay players, la habitacion se destruye
{
  comprueba_objetos();
}

public void SetParams(string keeper_name, object player, object office)
// ajusta los par�metros personalizados de la habitaci�n.
{
    SetIntLong(W("Te encuentras en una habitaci�n espaciosa, aunque sin m�s "
                 "mobiliario que una mesa con una romana encima, un cartel "
                 "pegado encima de la puerta y la caja de seguridad que "
                 "tienes ante ti.\n"
                 "La puerta que tienes hacia el sur permanece totalmente "
                 "cerrada, impidiendo as� que nadie pueda molestarte mientras "
                 "realizas tus gestiones con la caja. Antes de salir, " +
                 keeper_name + " ha colocado un cartel por fuera que reza:\n"
                 "Habitaci�n en uso por " + capitalize(player->QueryName()) +
                 ".\n"));
    SetOficina(office);
    SetIds(({"hab_" + player->QueryRealName()}));
    SetOwner(player);
    AddExit("salir",object_name(pOficina));
}

public int QuerySecurityRoom() { return 1; }
public void NotifyDayStateChange(mixed data, int newstate)
{
    ::NotifyDayStateChange(data, newstate);
    if (pOficina && pOficina->IsCloseTime(newstate))
    {
        foreach(object ob:all_inventory())
        {
            if (query_once_interactive(ob))
            {
                tell_object(ob, "Escuchas voces fuera. Temiendo que vayan a cerrar y te "
                            "quedes dentro, decides salir a ver qu� ocurre.\n");
                ob->move(pOficina, M_NOCHECK);
                ob->LookAfterMove();
            }
        }
        pOficina->CheckState(newstate, 0);
    }
}
