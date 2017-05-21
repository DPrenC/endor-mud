/***
Fichero: seccion_tronco.c
Autor: orome Endor-Mud
Descripci�n: una secci�n de tronco para trocearla y conseguir le�os.
Creaci�n: 27/10/2014
***/
#include <commands.h>
#include <skills.h>
#include <properties.h>
#include <xp.h>
#include <moving.h>
#include <sounds.h>
#include <domain.h>
inherit THING;
public int troceando(string str);
public void seccion_troceada();
#define PESO_LENYO   5000
int talar,hachazos=1;
string pEstado,pTipoarbol="�rbol";
public string QueryTipoArbol()         { return pTipoarbol; }
public string SetTipoArbol(string str) { return pTipoarbol = str; }
public f_short(){
    return "una secci�n del tronco de un "+QueryTipoArbol();
}

public string f_long(){
    return "Es una  secci�n circular del tronco de un "+QueryTipoArbol()+", con las "
    "marcas que indican que ha sido recientemente separada del cuerpo principal.\n"
    "Este pedazo de tronco es �til para ser troceado a su vez en le�os o para el serrado "
    "de piezas de madera de carpinter�a.\n";
}

 create(){
      ::create();
    SetTipoArbol("�rbol");
    SetWeight(60000);
    SetShort(SF(f_short));
    SetLong(SF(f_long));
    SetIds(({"madera","secci�n", "seccion", "trozo", "trozo de madera", "seccion de tronco", "secci�n de tronco"}));
    SetValue(2000);
    SetMaterial("madera");
        SetSmell("huele a savia fresca y madera verde.\n");
        Set(P_SIZE,P_SIZE_MEDIUM);
    }

public void init(){
    ::init();
    add_action("cmd_trocear","trocear");
}

public int cmd_trocear(string que) {
    object hacha;
    int i,bonus_gremio=0;
        if(!que) return notify_fail("�Qu� quieres trocear?\n", NOTIFY_NOT_VALID);
                if(!(que == "secci�n" || que == "seccion" || que == "trozo")) return notify_fail("Eso no te interesa trocearlo ahora mismo, mejor c�ntrate en el trozo .\n", NOTIFY_NOT_VALID);
if (environment() == TP) return notify_fail("Trocear�s mejor la secci�n del tronco si lo dejas en el suelo.\n",
    NOTIFY_NOT_VALID);
    if ( !TP->HasSkill(HAB_TALAR))
    return notify_fail("Para trocear esta secci�n de tronco deber�s aprender a talar.\n",NOTIFY_NOT_VALID);
    if (!TP->CanSee()) return notify_fail("Mejor que no te pongas a dar hachazos a oscuras si no quieres terminar reban�ndote un pie.\n",NOTIFY_NOT_VALID);
    hacha=present("hacha", TP);
        if (!hacha || !hacha->QueryEquipped())
    return notify_fail("\n Ser�a complicado partir le�a sin empu�ar una herramienta �til para ello.\n",NOTIFY_NOT_VALID);
    if(TP->QueryTP()<3 || TP->QuerySP()<3)
        return notify_fail("No tienes fuerzas para propinar un solo hachazo m�s, ni concentraci�n para acertar en el tronco.\n", NOTIFY_NOT_VALID);
    if(TP->QueryHP()<10) return notify_fail("Estando al borde de la muerte no es conveniente que te pongas a hacer ese tipo de tareas.\n",
        NOTIFY_NOT_VALID);
             talar= TP->UseSkill(HAB_TALAR, bonus_gremio);
     hachazos=TO->QueryWeight()/PESO_LENYO;
     if(hacha->id("hacha_le�ador")) hachazos= hachazos/2;
                write(talar+".\n");
    if(talar<1){
        write("observas con inter�s "+TO->QueryShort()+" desde distintos �ngulos y no "
        "sabes muy bien como trocearlo, lo tanteas un poco con el hacha. Ser� mejor que vuelvas a intentarlo.\n");
        say(CAP(TNAME)+" se queda mirando detenidamente "+TO->QueryShort()+", le da unos leves golpecitos con el hacha, pero parece que no se atreve a trocear el tronco.\n");
TP->AddSP(-1);
    return 1;
    }else{
        switch(talar){
            case 1..20:
        write("Con ciertas dudas te pones a trocear "+TO->QueryShort()+"...\n");
        say(CAP(TNAME)+", algo indecis"+TP->QueryGenderEndString()+" empieza a trocear "+TO->QueryShort()+"...\n");
        break;
            case 21..50:
                write("Aferras tu hacha y comienzas a trocear "+TO->QueryShort()+" con golpes met�dicos.\n");
        say(CAP(TNAME)+" levanta su hacha y comienza a trocear "+TO->QueryShort()+"  con golpes met�dicos.\n");
        break;
            case 51..120:
                write("Te frotas las manos, aferras el mango de tu hacha y la levantas  "
                "por encima de tu cabeza.\n"
                "Decidid"+TP->QueryGenderEndString()+", comienzas a trocear "+TO->QueryShort()+" con poderosos pero precisos hachazos...\n");
        say(CAP(TNAME)+" empu�a el hacha con decisi�n, la levanta sobre su cabeza y comienza a destrozar "+TO->QueryShort()+" con golpes poderosos pero met�dicos...\n");
        hachazos=hachazos/2;
        break;
        default:
        write("piensas que ese tipo de tareas no son dignas de tu profesionalidad y decides dej�rselas para otro.\n");
        break;
               } //switch
TP->AddSP(-1);
TP->AddTP(-1);  // para que no pueda hacer ninguna otra cosa mientras est� troceando
add_action("troceando", "", AA_NOSPACE);
call_out("seccion_troceada", hachazos);
        play_sound(environment(TP),SOUND_EVENTOS("hachazo"),0,100,hachazos);
        return 1;
}

}

public int troceando(string str)
{
    write("Est�s demasiado ocupad"+TP->QueryGenderEndString()+" partiennndo le�a.\n");
    say(CAP(TNAME) + " se encuentra muy ocupad"+TP->QueryGenderEndString()+" partiendo le�a.\n");
    return 1;
}

public void seccion_troceada(){
    seteuid(getuid());
    int cantidad=1+(talar/10);
    if(cantidad>12) cantidad=12;

    for (int i = 0;i<cantidad;i++) {
object lenyo = clone_object(OTROS("lenyo"));
lenyo->SetTipoArbol(TO->QueryTipoArbol());
lenyo->move(environment(TO),M_SILENT);
}//for
switch(cantidad){
case 1:
write("... pero, tras destrozar casi toda la secci�n del tronco, lo �nico que puedes aprovechar de tu estropicio es un rid�culo le�o.\n");
say("... pero, habiendo destrozado practicamente toda la secci�n del tronco solo consigue aprovechar un miserable le�o.\n");
break;
    case 2..3:
write("... pero, tras destrozar buena parte, tan solo consigues sacar en buen estado "+itoa(cantidad)+
" le�os, el resto queda convertido en astillas in�tiles.\n");
say("... pero, despu�s de destrozar gran parte, tan solo saca en buen estado "+itoa(cantidad)+
", pues el resto ha quedado convertido en astillas in�tiles.\n");
break;
case 4..7:
    write("... y consigues  sacar en buen estado "+itoa(cantidad)+
" le�os, el resto queda convertido en peque�as astillas.\n");
say("... y consigue sacar en buen estado "+itoa(cantidad)+
", qued�ndo el resto convertido en peque�as astillas.\n");
break;
default:
write("... y consigues  sacar en buen estado "+itoa(cantidad)+
" le�os.\n");
say("... y consigue sacar en buen estado "+itoa(cantidad)+
".\n");
break;
}//switch
remove_action("", TP); // para que se pueda mover ya despu�s de haber terminado
TP->exp(cantidad*XP_BASICO);
TO->remove();
}

