/*****************************************************************************************
 ARCHIVO:       tdhab24.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <ansi.h>
#include <moving.h>

#define P_ABIERTO 1
#define P_CERRADO 0

#define B_DEFAULT 0
#define B_CORAZON 1
#define B_ESTOMAG  2
#define B_CABEZA  3
#define B_TECHO   4
#define B_PARED   5
#define B_SUELO   6

#define BRA_IZQ ({"BRAZO IZQUIERDO ESTATUA", "EL BRAZO IZQUIERDO DE LA ESTATUA",\
                  "BRAZO IZQUIERDO DE ESTATUA", "EL BRAZO IZQUIERDO DE ESTATUA",\
                  "BRAZO IZQUIERDO DE LA ESTATUA"})
#define BRA_DER ({"BRAZO DERECHO ESTATUA", "EL BRAZO DERECHO DE LA ESTATUA",\
                  "BRAZO DERECHO DE ESTATUA", "EL BRAZO DERECHO DE ESTATUA",\
                  "BRAZO DERECHO DE LA ESTATUA"})


inherit ROOM;

private int posI;
private int posD;
private object arm;

object crear_armario();
void muestra_frase(int pos);
int msg_abre(string str);
int msg_cierra(string str);
int oracion(string str);
int cmd_moverbrazo(string brazo);
varargs string msg_brazo(int pos, int plural);
string mirar_estatua();


public void create()
{
    ::create();

    SetIntShort("el altar de Dehim");
    SetIntLong("El altar tiene un retablo bellamente decorado y ornamentado. Delante "
          "de �l, tallada en m�rmol blanco y detallada con oro, est� la estatua de "
          "Dehim, dios de la curaci�n. En una de las paredes destaca un llamativo tapiz "
          "de color terroso, con un marco de bordados de hilo de oro de aspecto "
          "intrincado pero no obstante bello. En el propio retablo, en la parte "
          "inferior, ves la peque�a puerta de un armario.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("techo", "Es una inmensa b�veda decorada con expresivos dibujos del "
          "dios. Justo a tu nivel ves la representaci�n de un �rbol enorme.\n");

    AddDetail(({"estatua", "Dehim"}),SF(mirar_estatua));

    AddDetail(({"brazos de estatua", "brazos de la estatua"}), "Observas que est�n "
          "articulados.\n");
    AddSubDetail("brazos de estatua", "Tienen junturas.\n");
    AddDetail("tapiz", "Observas el tapiz m�s de cerca y ves que se trata de una gran "
          "pieza de seda de unos dos metros de alto y m�s de un metro de ancho. Su "
          "aspecto brillante y lujoso desentona por completo con el resto de la "
          "decoraci�n, y te preguntas el motivo de su presencia aqu�. En el centro de la "
          "tela, una figura que parece impresa en tinta dorada llama poderosamente tu "
          "atenci�n. Junto al tapiz, clavado a la pared, hay un peque�o pergamino "
          "enmarcado en madera.\n");
    AddDetail("pergamino", "El Gran Se�or Nanteriel, en el d�a 10 del mes 9 del "
          "a�o 1236 y en un gesto de insuperable magnanimidad, hizo entrega de este "
          "fastuoso donativo a los monjes del monasterio de Dehim, quienes lo aceptaron "
          "con humildad y rezar�n siempre por el bienestar de su alma. Has de saber, "
          "estimado visitante, que el tapiz refleja la personificaci�n de nuestra deidad "
          "en el momento de su mayor gloria, cuando alcanz� el Divino Estado tras muchos "
          "a�os de rezos y  contemplaci�n. Aqu� nos muestra la postura m�s adecuada para "
          "permitir el correcto flujo de energ�a entre nuestro cuerpo y el Universo, que "
          "es donde moran los Dioses, alabados Sean.\n");
    AddDetail("figura", "Se trata de la figura de un hombre dibujado con trazos finos "
          "y precisos, da la impresi�n de ser algo et�reo, inmaterial, o en cualquier "
          "caso, desprendido de las complicaciones de este mundo. Su cuerpo est� "
          "envuelto en una sencilla t�nica que deja su brazo izquierdo y parte del t�rax "
          "al descubierto. Su rostro tiene una expresi�n concentrada y serena a la vez y "
          "sus ojos est�n cerrados. Parece estar sentado sobre alguna superficie lisa, "
          "con la espalda recta y las piernas cruzadas. Sus manos est�n unidas como si "
          "orase en silencio, algo separadas del cuerpo, a la altura de su estern�n. "
          "Sientes una ligera pero inexplicable oleada de paz y compasi�n al contemplar "
          "este tapiz.\n");

    AddRoomCmd("abrir", "msg_abre");
    AddRoomCmd("cerrar", "msg_cierra");
    AddRoomCmd("mover", "cmd_moverbrazo");
    AddRoomCmd("rezar", "oracion");

    AddExit("este", ALULAGO("templo/tdhab23.c"));
    AddExit("sur", ALULAGO("templo/tdhab19.c"));
    AddExit("oeste", ALULAGO("templo/tdhab25.c"));
    AddExit("sudeste", ALULAGO("templo/tdhab18.c"));
    AddExit("suroeste", ALULAGO("templo/tdhab20.c"));

    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);

    arm = crear_armario();
    posI = B_DEFAULT;
    posD = B_DEFAULT;
}

object crear_armario()
{
    object ob;
    ob = clone_object(ALUOBJ("otro/armario.c"));
    ob->move(TO, M_SILENT);
    return ob;
}

void muestra_frase(int pos)
{
    switch (pos)
    {
        case B_DEFAULT:
               write("Mueves el brazo hacia ti.\n");
               break;
        case B_CORAZON:
               write("Doblas el brazo hacia el coraz�n de la estatua.\n");
               break;
        case B_ESTOMAG:
               write("Mueves el brazo hasta el est�mago de la estatua.\n");
               break;
        case B_CABEZA:
               write("Mueves el brazo hasta la cabeza de la estatua.\n");
               break;
        case B_TECHO:
               write("Mueves el brazo hacia el techo.\n");
               break;
        case B_PARED:
               write("Mueves el brazo hacia la pared.\n");
               break;
        case B_SUELO:
               write("Mueves el brazo hacia el suelo.\n");
               break;
        default:
               write("Mueves el brazo hacia el altar.\n");
               break;
    }
    return;
}

varargs string msg_brazo(int pos, int plural)
{
    string s = (plural ? "s":"");
    switch(pos)
    {
        case B_DEFAULT:
             return "extendido" + s + " hacia ti";
        case B_CORAZON:
             return "doblado" + s + " hacia el coraz�n";
        case B_ESTOMAG:
             return "orientado" + s + " hacia el est�mago";
        case B_CABEZA:
             return "alzado" + s + " hacia la cabeza";
        case B_TECHO:
             return "mirando hacia el techo";
        case B_PARED:
             return "mirando hacia la pared";
    }
    return "orientado" + s + " hacia el altar";
}


             int msg_abre(string str)
{
    if (!str) return 0;
    if (UPPER(str) == "ARMARIO")
    {
        if (arm->QueryEstado() == P_ABIERTO)
        {
            write("El armario ya est� abierto.\n");
            return 1;
        }
        if (arm->QueryEstado() == P_CERRADO)
        {
            write("No consigues abrir el armario.\n");
            return 1;
        }
    }
    else return 0;
}

int msg_cierra(string str)
{
    if (!str) return 0;
    if (UPPER(str) == "ARMARIO")
    {
        if (arm->QueryEstado() == P_ABIERTO)
        {
            write("Cierras el armario.\n");
            arm->SetEstado(P_CERRADO);
            return 1;
        }
        if (arm->QueryEstado() == P_CERRADO)
        {
            write("El armario ya est� cerrado.\n");
            return 1;
        }
     }
     else return 0;
}

int oracion(string str)
{
    if (!str) return 0;
    if(str != "Bondadoso Dehim abreme la puerta de tu casa" &&
       str != "Bondadoso Dehim �breme la puerta de tu casa")
    {
        write("Has rezado mal.\n");
        return 1;
    }
    if(posI != B_CORAZON || posD != B_TECHO)
    {
        write("Algo en tu interior te dice que deber�as hacer algo m�s.\n");
        return 1;
    }
    write("Escuchas: �click!\n");
    arm->SetEstado(P_ABIERTO);
    return 1;
}

int cmd_moverbrazo(string brazo)
{
    if (!brazo) return 0;
    if (member(BRA_IZQ, UPPER(brazo)) >= 0)
    {
        if (posI <= 6)
        {
            posI = posI + 1;
            muestra_frase(posI);
            return 1;
        }
        posI = B_DEFAULT;
        muestra_frase(posI);
        return 1;
    }
    if (member(BRA_DER, UPPER(brazo)) >= 0)
    {
        if (posD <= 6)
        {
            posD = posD + 1;
            muestra_frase(posD);
            return 1;
        }
        posD = B_DEFAULT;
        muestra_frase(posD);
        return 1;
    }
}

public varargs void reset()
{
    posI = B_DEFAULT;
    posD = B_DEFAULT;
    arm->SetEstado(P_CERRADO);
    ::reset();
}

string mirar_estatua()
{
    string msg = "Las ruinas y el deterioro del lugar parecen no haberla "
                 "afectado. Incluso parece que te est� sonriendo. ";

    if (posI == posD)
    {
        return msg + "Sus brazos est�n " + msg_brazo(posI,1) + ".\n";
    }
    return msg + "El brazo izquierdo est� " + msg_brazo(posI) + ", y el "
           "derecho " + msg_brazo(posD) + ".\n";
}