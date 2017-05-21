/*****************************************************************************************
 ARCHIVO:       violetas.c
 AUTOR:         Ztico
 FECHA:         28-06-2005
 DESCRIPCI�N:   Un ramillete de violetas, narc�tico
                Meter otro call_out
******************************************************************************************/

#include "./path.h"
#include <commands.h>
#include <properties.h>

inherit "/obj/hierba";

private int cmd_comer(string str);
private int f_atontao(int tiempo);
public int f_espera();
public int f_filtrar(string str);
public int f_reestablecer();

create()
{
    if(::create()) return 1;

    SetShort("un precioso grupo de violetas");
    SetLong(W("Un enorme conjunto de preciosas violetas crece aqu�. Sus hojas son "
        "grandes, de forma redondeada, est�n cubiertas de una suave pelusilla y parecen "
        "muy suaves al tacto. Sus peque�as flores de aspecto satinado tienen todos los "
        "colores de la gama, desde el malva m�s delicado al p�rpura m�s intenso.\n"));
    AddId(({"grupo", "violetas","grupo violetas", "conjunto", "flores"}));
    SetSmell(W("Su fragancia es muy suave pero a la vez muy atractiva, extra�amente "
        "seductora, invit�ndote a disfrutarla una y otra vez.\n"));
    Set(P_GENDER, GENERO_MASCULINO);
    Set(P_NUMBER, NUMERO_PLURAL);
    SetClass("narcotico");
    SetType("flor");
    SetWeight(60);
    Set(P_MAGIC, QueryHerb());
}

private int cmd_comer(string str)
{
    object pl;

    if(!str || member(QueryIds(),str) < 0) return 0;
    pl = TP;
    if(!pl || !living(pl)) return notify_fail("Nadie me come.\n", NOTIFY_NOT_OBJ);

    switch(pl->QueryRace())
    {
        case "elfo":
        case "duende":
                 write("Arrancas cuidadosamente un p�talo de violeta y lo masticas con "
                     "placer. Su ex�tico sabor acaricia tu paladar, sumi�ndote por "
                     "unos instantes en un delicioso �xtasis narc�tico sin mayores "
                     "consecuencias.\n");
                 say(CAP(NNAME(pl)) + " mastica un p�talo de violeta, mientras cierra "
                     "los ojos con expresi�n complacida, y cuando vuelve a abrirlos "
                     "parecen ser m�s oscuros y profundos durante un momento fugaz.\n");
                 TO->remove();
                 break;
        default:
                 write("Arrancas un p�talo de la violeta y te lo llevas a la boca, "
                     "mastic�ndolo con cautela. De inmediato comienzas a sentir una "
                     "extra�a lasitud que se va apoderando de tus miembros, se te "
                     "nubla la vista, todo parece ondular, ralentizarse y brillar como "
                     "si caminaras bajo el agua. Y de repente...\n\n");
                 call_out("f_espera", 3);
                 say(CAP(NNAME(pl)) +" acerca un p�talo de violeta a su boca y se lo "
                     "come, de pronto su rostro adquiere una expresi�n ausente y sus "
                     "ojos parecen nublarse y hacerse m�s profundos al mismo tiempo, "
                     "acto seguido cae al suelo semi-inconsciente antes de que puedas "
                     "sujetarle.\n");
                 f_atontao(60);
                 break;
    }
    return 1;
}

private int f_atontao(int tiempo)
{
    add_action("f_filtrar", "", AA_NOSPACE);
    call_out("f_reestablecer", tiempo);
    return 1;
}

public int f_espera()
{
    write("El suelo parece oscilar peligrosamente durante unos angustiosos segundos. A "
        "continuaci�n corre a tu encuentro y choca dolorosamente con tu cabeza. Tu "
        "cuerpo queda inm�vil mientras tu esp�ritu viaja a trav�s de un sinf�n de "
        "inmensidades.\n");
    return 1;
}

public int f_filtrar(string str)
{
    write("Tu cuerpo y tu alma est�n desconectados. En estos momentos no est�s en "
        "condiciones de hacer nada.\n");
    return 1;
}

public int f_reestablecer()
{
    remove_action("", TP);
    write("Poco a poco vas recuperando el control sobre tu cuerpo, parece que tu alma "
        "ha regresado de su extra�o viaje. Lentamente te pones en pie, con la "
        "sensaci�n de tener la cabeza vuelta del rev�s y un vac�o en alg�n lugar del "
        "est�mago, si es que sigue estando en el mismo sitio.\n");
    say(CAP(TNAME) + " comienza a reaccionar poco a poco. Su respiraci�n se normaliza y "
        "sus miembros vuelven a la vida. Al rato abre los ojos y se pone en pie con "
        "dificultad y aspecto p�lido y descompuesto.\n");
    TP->SetTP(0);
    TO->remove();
    return 1;
}

public varargs void init()
{
    ::init();

    add_action("cmd_comer", "comer");
}
