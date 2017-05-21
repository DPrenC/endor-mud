/***
fichero: almacen.c
Autor: Kastwey@simauria
Descripción: El almacén de las cajas de seguridad.
Aquí es donde se lleva al player para que haga lo que sea con su caja.
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
    SetIntShort("la habitación de seguridad");
    SetIndoors(1);
    SetIntLight(45);
    SetIntNoise("El silencio es absoluto. Si te fijas hasta puedes escuchar "
                "los latidos de tu corazón.\n");
    SetIntSmell("Huele a cerrado.\n");
    AddDetail  (({"puerta"}),
              W("Es una puerta de hierro reforzado, con un pomo en su parte "
              "interior. Seguramente sería muy difícil abrirla desde fuera, "
              "a no ser que dispongas de la llave adecuada.\n"));
    AddDetail  (({"cartel","letrero"}),
              W("Se trata de un cartel pegado encima de la puerta. Quizás "
              "deberías leerlo.\n"));
    AddDetail  (({"mesa","mesilla"}),(
              W("Es una mesita pequeña en la que se encuentra colocada la "
              "romana.\n")));
    AddReadMsg  (({"cartel","Cartel","letrero","Letrero"}),
               W("Normas a tener en cuenta mientras realiza sus gestiones con "
               "su caja de seguridad.\n"
               "1. No podrá introducir más objetos que los especificados en "
               "las características de su caja. Así mismo, no se permiten "
               "introducir mochilas ni otros objetos que a su vez contengan "
               "otros objetos en su interior.\n"
               "2. Aquí podrá encontrar una romana que le permitirá pesar sus "
               "objetos, a fin de saber cuanto espacio está ocupando en su "
               "caja.\n"
               "3. Cuando usted efectúa el alquiler de una de nuestras cajas, "
               "se le otorga el derecho a modificar siempre que quiera su "
               "contenido, asegurándole que ninguna persona más que usted "
               "tendrá acceso al contenido de ella. Así mismo, también se le "
               "suscribe automáticamente a un seguro contra robos, que le "
               "permitirá recuperar el valor de sus objetos si por alguna "
               "razón desapareciesen de nuestras instalaciones.\n"
               "4. Cualquier tentativa de robo, asesinato de nuestros "
               "empleados, o destrozos en el moviliario de nuestras "
               "instalaciones, será notificado automáticamente a la guardia "
               "local que procederá según sus pautas acostumbradas.\n"
               "5. En caso de dudas, reclamaciones, quejas o cualquier otro "
               "asunto, uno de nuestros  empleados le atenderá las 24 horas "
               "del día.\n\n"
               "Firmado: Crizmal Mlatzem. Tesorero y administrador de las "
               "oficinas de consignas de Simauria.\n"));
    AddItem("/std/securebox/romana", REFRESH_HOME);
}

void notify_leave(mixed from,int method,mixed extra)
// Comprueba quien sale de la habitación... y actúa en consecuencia
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
        // la caja está abierta... Antes de salir, simula cerrarla.
        {
            tell_object(pOwner,"Cierras la caja y sales de la habitación.\n");
        }
        call_out("comprueba_objetos",1);
        // en un segundo se comprobara si el que ha salido ha sido el propietario,
        // y si ha sido así, destruirá la habitación si no hay players.
        // si no ha sido el propietario quien ha salido pero ya no está
        // dentro (salió antes), tb se intentará destruir... siempre q no
        // haya players
        // dentro.
    }
    return ::notify_leave(from, method, extra);
}


public void crear_caja(object owner)
// crea una caja con los parámetros especificados (caja ya existente).
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
// comprueba si la habitación ya se puede destruir
{
    if (!pOwner || !present(pOwner,TO))
    // el propietario de la habitación no está, asi que o ha salido ahora
    // o ya salio antes.
    {
        if (present("caja fuerte",TO) && pOficina)
        // El propietario acaba de salir, ya que la caja fuerte sigue aquí.
        {
            int hay_empleado;
            hay_empleado = pOficina->keeper_in_room(K_SILENT);
            tell_room(TO,W("Se abre la puerta y aparece un empleado, que coge "
                           "la caja y se la lleva.\n"
                           "Cuando va a cerrar de nuevo la puerta, te mira "
                           "con cara de sospecha y al final la deja "
                           "entreabierta.\n"));
            SetIntLong(W("Te encuentras en una habitación espaciosa, aunque "
                         "sin más mobiliario que una mesa con una romana "
                         "encima y un cartel pegado en la puerta.\n"
                         "La puerta que tienes hacia el sur está "
                         "entreabierta, como si el empleado la hubiese dejado "
                         "así a propósito invitándote a salir cuanto antes "
                         "de aquí.\n"));
            if (!hay_empleado)
            // no hay empleado
            {
	            tell_room(pOficina,
	                      W("Un ayudante se asoma desde el almacén, y al ver "
	                        "que el empleado no está disponible, se acerca a "
	                        "una de las habitaciones, y sale portando una "
	                        "caja.\n"
	                        "A continuación, vuelve a entrar en el almacén.\n"
	                        ));
            }
            else
            {
                tell_room(pOficina,
                          W(pOficina->KeeperName(K_CAP) + " sale de detrás del "
                            "mostrador, y se dirige a una de las "
                            "habitaciones. Al instante, aparece con una caja "
                            "en los brazos, y tras guardarla en el almacén, "
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
// establece el objeto player del propietario de la habitación
{
    return pOwner = ob;
}

public object QueryOwner()
// devuelve la referencia al objeto Owner de la habitación
{
    return pOwner;
}


public void crear_caja_nueva(object owner,int size)
// crea una caja nueva con los parámetros especificados
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
    caja->SetObjetosCaja("La caja está vacía");
}

init()
{
    ::init();
    if (TP) TP->SetHomeTmp(pOficina);
}


int allow_enter(int method, mixed extra)
// aquí controlo si alguien puede entrar a la room
// si no es un wiz y no es el propietario... como que no
{
    if (method != M_SPECIAL && PO->QueryIsPlayer() && PO != pOwner && !query_wiz_level(PO))
    // lo ziento.. no erez digno de entrar aqui...
    {
        tell_object (PO,W("No te está permitido ir a este lugar.\n" +
                          capitalize(pOwner->QueryName()) + " está en la "
                          "habitación de seguridad con su caja en este "
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
// ajusta los parámetros personalizados de la habitación.
{
    SetIntLong(W("Te encuentras en una habitación espaciosa, aunque sin más "
                 "mobiliario que una mesa con una romana encima, un cartel "
                 "pegado encima de la puerta y la caja de seguridad que "
                 "tienes ante ti.\n"
                 "La puerta que tienes hacia el sur permanece totalmente "
                 "cerrada, impidiendo así que nadie pueda molestarte mientras "
                 "realizas tus gestiones con la caja. Antes de salir, " +
                 keeper_name + " ha colocado un cartel por fuera que reza:\n"
                 "Habitación en uso por " + capitalize(player->QueryName()) +
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
                            "quedes dentro, decides salir a ver qué ocurre.\n");
                ob->move(pOficina, M_NOCHECK);
                ob->LookAfterMove();
            }
        }
        pOficina->CheckState(newstate, 0);
    }
}
