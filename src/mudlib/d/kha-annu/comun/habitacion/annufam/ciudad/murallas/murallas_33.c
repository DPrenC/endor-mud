/****************************************************************************
Fichero: murallas_33.c
Autor: Riberales
Creaci�n: 8/10/2005
Descripci�n: Una room en la muralla de Annufam.
17/11/2005 [kastwey] a�ado un mont�n de cosas para lo de escalar la muralla.
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <messages.h>
#define DESENGANCHAR ({"garfio","el garfio","garfio de almena","garfio de la almena",\
"el garfio de almena","el garfio de la almena","garfio de muralla",\
"garfio de la muralla","el garfio de muralla","el garfio de la muralla",\
"cuerda","la cuerda","la cuerda de almena","la cuerda de la almena",\
"cuerda de almena","cuerda de la almena","cuerda de muralla",\
"la cuerda de muralla","cuerda de la muralla","la cuerda de la muralla"})
#define DESEN_PRURAL ({"garfios","los garfios","garfios de almena","garfios de la almena",\
"los garfios de almena","los garfios de la almena","garfios de muralla",\
"garfios de la muralla","los garfios de muralla","los garfios de la muralla",\
"cuerdas","las cuerdas","las cuerdas de almena","las cuerdas de la almena",\
"cuerdas de almena","cuerdas de la almena","cuerdas de muralla",\
"las cuerdas de muralla","cuerdas de la muralla","las cuerdas de la muralla"})



inherit HAB_MURALLAS_ANNUFAM("murallas_base");

int pCuerdasEnMuralla;
// cuerdas enganchadas, pero que no las tiene ning�n player
object *pObCuerdasEnMuralla = ({});
/*
Esta variable almacena las cuerdas que adem�s de estar enganchadas, la tienen
cogidas alg�n jugador. Esta chapuza la hago porque si alguien lanza la cuerda,
debe tenerla cogida, si la suelta, y ya que el foso est� del lado del player,
la cuerda se pegar� a la muralla y no podr� cogerla.
Esta �ltima, ser�n las cuerdas que est�n en pCuerdasEnMuralla, ya que no
se necesita saber a qu� usuario est� cogida la cuerda.
*/


public int QueryNumCuerdasEnMuralla()
// devuelve el n�mero de cuerdas que hay enganchadas
{
    return pCuerdasEnMuralla + sizeof(pObCuerdasEnMuralla);
}

public varargs mixed AddCuerdaEnMuralla(object cuerda);

public int EstaEnMuralla(object cuerda)
// devuelve 1 si un objeto cuerda pasado como par�metro est� enganchado a la
// muralla
{
    return member(pObCuerdasEnMuralla,cuerda) >= 0;
}

public RemoveCuerdas(int num_cuerdas)
// quita las cuerdas especificadas en el par�metro, de las murallas
{
    int i;
    object foso = load_object(HAB_FOSO_ANNUFAM("foso_01"));
    while (i < num_cuerdas && (   pCuerdasEnMuralla
                               || sizeof(pObCuerdasEnMuralla)))
    {
        if (pCuerdasEnMuralla)
        {
            clone_object(OTRO_ANNUFAM("cuerda_engarfiada"))->move(foso);
            pCuerdasEnMuralla--;
        }
        else
        {
            object cuerda = pObCuerdasEnMuralla[<1];
            object pl = environment(cuerda);
            if (living(pl))
            {
                tell_object(pl,"La inercia de la cuerda al caer, hace que "
                               "se te resbale y caiga al foso.\n");
            }
            cuerda->move(foso);
            pObCuerdasEnMuralla -= ({cuerda});
        }
        i++;
    }
    return i;
}

private RemoveCuerda() { return RemoveCuerdas(1); }


public int SoltarCuerda(object cuerda)
// Un player suelta una cuerda.
// esto quiere decir que se borra del array de objetos y se incrementa
// pCuerdasEnMurallas. Vamos, que la cuerda est� enganchad,a pero ya
// no la puede coger el player que est� abajo.
{
    if (member(pObCuerdasEnMuralla,cuerda) < 0) return 0;
    pObCuerdasEnMuralla -= ({cuerda});
    pCuerdasEnMuralla++;
    cuerda->remove();
    return 1;
}

public int AddCuerdasEnMuralla(mixed arg1)
// puede recibir un array de objetos a a�adir, o un solo objeto, o un n�mero.
{
    if (intp(arg1)) pCuerdasEnMuralla += arg1;
    else if (objectp(arg1)) pObCuerdasEnMuralla += ({arg1});
    else if (pointerp(arg1)) pObCuerdasEnMuralla += arg1;
    // borramos los posibles elementos repetidos
    pObCuerdasEnMuralla = m_indices(mkmapping(pObCuerdasEnMuralla));
    return QueryNumCuerdasEnMuralla();
}





private varargs void desenganchar(int num_garfios, string msg_aqui,
                          string msg_entrada, string msg_foso, string msg_pl)
// desengancha la cuerda de arriba (una o varias, dependiendo del primer
// par�metro, y env�a distintos mensajes a las habitaciones:
// msg_aqui, a esta hab, msg_entrada, a la entrada, y msg_foso, al foso.
// Se puede suprimir el msg_pl, en cuyo caso, �l ver� tambi�n el msg_aqui.
{
    object entrada, foso;
    int i;
    if (!QueryNumCuerdasEnMuralla())
    // no hay cuerdas para desenganchar
    {
        return;
    }

    if (!num_garfios || !msg_aqui || !msg_entrada) return;
    entrada = load_object(HAB_CIUDAD_ANNUFAM("entrada"));
    foso = load_object(HAB_FOSO_ANNUFAM("foso_01"));

    if (msg_pl) write(msg_pl);
    tell_room(TO,msg_aqui,(msg_pl ? ({TP}) : ({})));
    tell_room(entrada,msg_entrada);
    tell_room(foso,msg_foso);
    // quitamos lascuerdas
    RemoveCuerdas(num_garfios);
}

public string num2letra(int num)
// convierte los n�meros del 0 al 10 en sus respectivas palabras.
{
    switch(num)
    {
        case 1: return "un";
        case 2: return "dos";
        case 3: return "tres";
        case 4: return "cuatro";
        case 5: return "cinco";
        case 6: return "seis";
        case 7: return "siete";
        case 8: return "ocho";
        case 9: return "nueve";
        case 10: return "diez";
        default: return "cero";
    }

	return "cero";
}


int cmd_desenganchar(string str)
{
    int tipo, num_cuerdas = QueryNumCuerdasEnMuralla();
    string num;
    if (!num_cuerdas) return 0;
    if (   !str || !((tipo = 1) && member(DESENGANCHAR,str) >= 0
        || (tipo = 2) && member(DESEN_PRURAL,str) >= 0))
    {
        return notify_fail("�Desenganchar qu� de d�nde?",NOTIFY_NOT_VALID);
    }
    if (tipo == 1 || num_cuerdas == 1)
    // solo se va a quitar un garfio
    {
        desenganchar(1, CAP(TNAME) + " da un tir�n " +
                     (num_cuerdas > 1 ? "de un " : "del ") +
                     "garfio y lo desengancha de "
                     "la almena. La cuerda cae al vac�o... Tras unos segundos, "
                     "escuchas el golpe del garfio al llegar al foso.\n",
                     "Escuchas un ruido extra�o. Miras hacia arriba y ves " +
                     (num_cuerdas > 1? "uno de los garfios" :
                      "el garfio") + "que antes estaba en una almena de la "
                     "muralla, caer a toda velocidad. El garfio pasa "
                     "zumbando y cae al foso con un golpe seco.\n",
                     ({MSG_SEE,"Escuchas un silbido y ves como una "
                               "cuerda largu�sima cae desde lo alto.\n",
                               "Escuchas un silbido que va ganando en "
                               "intensidad hasta acabar en un golpe sordo. "
                               "Jurar�as que lo que sea que haya caido lo ha "
                               "hecho muy cerca de ti.\n"}),
                     "De un fuerte tir�n, desenganchas " +
                 (num_cuerdas > 1 ? "uno de los garfios" : "el garfio") +
                     " de la almena y lo dejas caer... Tras unos segundos, "
                     "escuchas un golpe seco.\n");
        return 1;
    }
    // desengancha todos los garfios
    num = num2letra(num_cuerdas);
    desenganchar(num_cuerdas,
                 CAP(TNAME) + " desengancha los " + num + " garfios que "
                 "hab�a en la muralla y los lanza al vac�o. "
                 "Al instante, los escuchas caer a lo lejos, en el foso.\n",
                 "Escuchas unos ruidos extra�os, y ves como " + num + " garfios "
                 "caen desde la muralla hasta aterrizar en el foso "
                 "con un golpe seco.\n",
                 ({MSG_SEE,"Escuchas un silbido y alzas la cabeza a tiempo de "
                           "ver como " + num + " cuerdas con garfios en la "
                           "punta se precipitan hacia ti. Te apartas al tiempo "
                           "que las cuerdas caen al suelo con un golpe sordo.\n",
                           "Escuchas un silbido que va aumentando de "
                           "velocidad. R�pidamente, te pegas a una de las "
                           "paredes del foso al tiempo que a tus pies, "
                           "escuchas varios golpes secos. Lo que sea que "
                           "haya caido desde arriba, lo ha hecho muy "
                           "cerca de ti.\n"}),
                 "Das un tir�n de los " + num + " garfios y los lanzas al "
                 "vac�o. Al poco, escuchas un golpe seco cuando chocan "
                 "contra el fondo del foso.\n");
    return 1;
}


public varargs int EngancharCuerdaEnMuralla(object cuerda)
// a�ade una cuerda a la muralla.
{
    object prev = PO;
    AddCuerdasEnMuralla(cuerda);if (cuerda && object_name(prev) == HAB_CIUDAD_ANNUFAM("entrada"))
    // se llama a esta funci�n desde la entrada de la ciudad, por lo que
    // alguien ha lanzado la cuerda a la muralla
    {
        object soldado;
        tell_room(TO,"Escuchas un golpe seco, y observas como en la "
                     "almena que tienes a tu lado hay enganchado " +
                     (QueryNumCuerdasEnMuralla() ? "otro" : "un") + " gran "
                     "garfio del que parte una gruesa cuerda hacia el exterior "
                     "de la muralla.\n");

        if (sizeof(filter(all_inventory(),
                          (:living($1) && $1->id("soldado_murallas") ?
                            $2 = $1:0:),&soldado)))

        // hay un soldado en esa room, as� que ve el garfio, y lo quita.
        {
            string msg = "�Maldito ladr�n! no podr�s subir, pero si lo "
                         "haces tendr�s que enfrentarte con nosotros, as� que "
                         "m�s te vale no volver a intentarlo!\n";


            desenganchar(1,
                         CAP(soldado->QueryName()) + " observa "
                         "sorprendid" + soldado->QueryGenderEndString() +
                         "la cuerda, mira el garfio y de un tir�n lo arroja "
                         "al vac�o. Al momento, se asoma por la muralla y "
                         "grita: " + msg,
                         "Escuchas una maldici�n proveniente de lo alto "
                         "de la muralla, y el garfio es desenganchado de la "
                         "almena y arrojado al vac�o. La cuerda pasa a toda "
                         "velocidad ante ti y se precipita al foso, donde cae "
                         "con un ruido seco.\n"
                         "Alguien grita desde lo alto de la muralla: " +
                         msg,
                         ({MSG_SEE,"Escuchas un silbido sobre tu cabeza. "
                                   "Miras hacia arriba a tiempo de apartarte "
                                   "de la trayectoria de una enorme cuerda "
                                   "que cae a tus pies con un estruendoso "
                                   "ruido.\n"
                                   "Desde muy arriba escuchas a alguien gritar: " + msg,
                                   "Escuchas un silbido sobre tu cabeza. "
                                   "R�pidamente te apartas hacia una de las "
                                   "paredes del foso, al tiempo que escuchas "
                                   "un golpe seco a tus pies. Desde muy "
                                   "arriba, escuchas a alguien gritar: " +
                                   msg}));
        }
    }
    return QueryNumCuerdasEnMuralla();
}



string m_cuerdas()
{
    string s;
    int num = QueryNumCuerdasEnMuralla();
    if (!num) return 0;
    s = num > 1 ? "s":"";
    return "Se trata de una" + s + " gruesa" + s + " cuerda" + s +
           " enganchada" + s + " a un gran garfio que se encuentra sujeto a "
           "una de las almenas. Seg�ramente, alguien la" + s + " ha lanzado "
           "desde abajo para intentar escalar hasta aqu�.\n";
}

string long()
{
    int num = QueryNumCuerdasEnMuralla();
    string l = "Paseas sobre la parte m�s elevada de la ciudad de Annufam, "
               "sus murallas. Desde aqu� divisas gran parte del dominio "
               "enano, y algunas laderas m�s all�. A�n as�, no crees que este "
               "sitio sea un mirador, aunque en parte, los enanos que est�n "
               "aqu� pasan todo el d�a haciendo eso, mirar por si hay alguna "
               "irregularidad.\n";
    if (num)
    {
        string s = num > 1 ? "s":"";
        l += "Tambi�n puedes ver " + num2letra(num) +
             " garfio" + s + " enganchado" + s + " a una de las almenas, "
             "de" + (num > 1? " los":"l") +
             " que parte una gruesa cuerda que desciende hacia el "
             "exterior de la ciudad.\n";
    }
    return l;
}

public void create()
{
    ::create();

    SetIntLong(SF(long));

    AddDetail(({"cuerda","cuerda de muralla","cuerda de la muralla",
                "cuerdas","cuerdas de muralla","cuerdas de la muralla"}),
              SF(m_cuerdas));

    AddRoomCmd(({"desenganchar","soltar","tirar"}),"cmd_desenganchar");
    AddExit("oeste",HAB_MURALLAS_ANNUFAM("murallas_00"));
    AddExit("este",HAB_MURALLAS_ANNUFAM("murallas_32"));

}

public void reset()
{
    ::reset();
    int num_cuerdas;
    // numero de cuerdas que hay en la muralla

    if (num_cuerdas = QueryNumCuerdasEnMuralla()) return;
    // la / las soltamos
    if (num_cuerdas > 1)
    {
        string num = num2letra(num_cuerdas);
        desenganchar(num_cuerdas,
                     "Los garfios se sueltan y las cuerdas caen al vac�o.\n",
                     "Escuchas un extra�o ruido y ves como " +
                     num + " cuerdas caen al vac�o hasta estrellarse contra "
                     "el fondo del foso.\n",
                     ({MSG_SEE,"Escuchas un extra�o ruido y alzas la cabeza "
                               "a tiempo de ver como " + num + " cuerdas con "
                               "garfios en las puntas se precipitan hacia ti. "
                               "R�pidamente te arrimas a una de las "
                               "paredes del foso, al tiempo que las cuerdas "
                               "caen al suelo con golpes sordos.\n",
                               "Escuchas unos extra�os ruidos sobre tu cabeza. "
                               "Rapidamente te arrimas a una de las paredes "
                               "del foso al tiempo que escuchas varios golpes "
                               "sordos a tus pies.\n"}));
        return;
    }
    desenganchar(1,
                     "El garfio se suelta y la cuerda cae al vac�o.\n",
                     "Escuchas un extra�o ruido. Miras hacia arriba y "
                     "observas como cae de arriba una cuerda con un garfio "
                     "enganchado. La cuerda cae al foso con un golpe "
                     "seco.\n",
                     ({MSG_SEE,"Escuchas un ruido y alzas la cabeza al tiempo "
                               "que te apartas hacia una de las paredes del "
                               "foso. Al instante, ves aproximarse a toda "
                               "velocidad una cuerda con un garfio en la "
                               "punta, que se estrella a tus pies con un "
                               "golpe sordo.\n",
                               "Escuchas un extra�o ruido por encima de tu "
                               "cabeza. Rapidamente te apartas hacia una de "
                               "las paredes del foso, al tiempo que escuchas "
                               "un golpe sordo a tus pies.\n"}));

}




public void notify_enter(mixed from, int method, mixed extra)
{
    object prev = PO || TP;
    ::notify_enter(from, method, extra);
    if (prev && living(prev) && prev->id("soldado_murallas") && method ==M_GO)
    // llega un soldado de la muralla
    {
        desenganchar(1, "\n" + CAP(prev->QueryName()) + " mira contrariad" +
                     prev->QueryGenderEndString() + " el garfio y la cuerda "
                     "que hay enganchada en la almena. De un en�rgico tir�n, "
                     "desengancha el garfio, y lo arroja al vac�o mientras "
                     "murmura: Otro maldito ladr�n que se piensa que "
                     "escalar las murallas es como dar un pase�to.\n",
                     "Escuchas un golpe seco y observas como el garfio "
                     "cae desde lo alto de la muralla, produciendo un "
                     "estruendoso ruido al llegar al suelo. Te parece "
                     "escuchar a alguien rezongando desde arriba.\n");
    }
}


