/***
Fichero: seccion_tronco.c
Autor: orome Endor-Mud
Descripción: una sección de tronco para trocearla y conseguir leños.
Creación: 27/10/2014
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
string pEstado,pTipoarbol="árbol";
public string QueryTipoArbol()         { return pTipoarbol; }
public string SetTipoArbol(string str) { return pTipoarbol = str; }
public f_short(){
    return "una sección del tronco de un "+QueryTipoArbol();
}

public string f_long(){
    return "Es una  sección circular del tronco de un "+QueryTipoArbol()+", con las "
    "marcas que indican que ha sido recientemente separada del cuerpo principal.\n"
    "Este pedazo de tronco es útil para ser troceado a su vez en leños o para el serrado "
    "de piezas de madera de carpintería.\n";
}

 create(){
      ::create();
    SetTipoArbol("árbol");
    SetWeight(60000);
    SetShort(SF(f_short));
    SetLong(SF(f_long));
    SetIds(({"madera","sección", "seccion", "trozo", "trozo de madera", "seccion de tronco", "sección de tronco"}));
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
        if(!que) return notify_fail("¿Qué quieres trocear?\n", NOTIFY_NOT_VALID);
                if(!(que == "sección" || que == "seccion" || que == "trozo")) return notify_fail("Eso no te interesa trocearlo ahora mismo, mejor céntrate en el trozo .\n", NOTIFY_NOT_VALID);
if (environment() == TP) return notify_fail("Trocearás mejor la sección del tronco si lo dejas en el suelo.\n",
    NOTIFY_NOT_VALID);
    if ( !TP->HasSkill(HAB_TALAR))
    return notify_fail("Para trocear esta sección de tronco deberás aprender a talar.\n",NOTIFY_NOT_VALID);
    if (!TP->CanSee()) return notify_fail("Mejor que no te pongas a dar hachazos a oscuras si no quieres terminar rebanándote un pie.\n",NOTIFY_NOT_VALID);
    hacha=present("hacha", TP);
        if (!hacha || !hacha->QueryEquipped())
    return notify_fail("\n Sería complicado partir leña sin empuñar una herramienta útil para ello.\n",NOTIFY_NOT_VALID);
    if(TP->QueryTP()<3 || TP->QuerySP()<3)
        return notify_fail("No tienes fuerzas para propinar un solo hachazo más, ni concentración para acertar en el tronco.\n", NOTIFY_NOT_VALID);
    if(TP->QueryHP()<10) return notify_fail("Estando al borde de la muerte no es conveniente que te pongas a hacer ese tipo de tareas.\n",
        NOTIFY_NOT_VALID);
             talar= TP->UseSkill(HAB_TALAR, bonus_gremio);
     hachazos=TO->QueryWeight()/PESO_LENYO;
     if(hacha->id("hacha_leñador")) hachazos= hachazos/2;
                write(talar+".\n");
    if(talar<1){
        write("observas con interés "+TO->QueryShort()+" desde distintos ángulos y no "
        "sabes muy bien como trocearlo, lo tanteas un poco con el hacha. Será mejor que vuelvas a intentarlo.\n");
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
                write("Aferras tu hacha y comienzas a trocear "+TO->QueryShort()+" con golpes metódicos.\n");
        say(CAP(TNAME)+" levanta su hacha y comienza a trocear "+TO->QueryShort()+"  con golpes metódicos.\n");
        break;
            case 51..120:
                write("Te frotas las manos, aferras el mango de tu hacha y la levantas  "
                "por encima de tu cabeza.\n"
                "Decidid"+TP->QueryGenderEndString()+", comienzas a trocear "+TO->QueryShort()+" con poderosos pero precisos hachazos...\n");
        say(CAP(TNAME)+" empuña el hacha con decisión, la levanta sobre su cabeza y comienza a destrozar "+TO->QueryShort()+" con golpes poderosos pero metódicos...\n");
        hachazos=hachazos/2;
        break;
        default:
        write("piensas que ese tipo de tareas no son dignas de tu profesionalidad y decides dejárselas para otro.\n");
        break;
               } //switch
TP->AddSP(-1);
TP->AddTP(-1);  // para que no pueda hacer ninguna otra cosa mientras está troceando
add_action("troceando", "", AA_NOSPACE);
call_out("seccion_troceada", hachazos);
        play_sound(environment(TP),SOUND_EVENTOS("hachazo"),0,100,hachazos);
        return 1;
}

}

public int troceando(string str)
{
    write("Estás demasiado ocupad"+TP->QueryGenderEndString()+" partiennndo leña.\n");
    say(CAP(TNAME) + " se encuentra muy ocupad"+TP->QueryGenderEndString()+" partiendo leña.\n");
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
write("... pero, tras destrozar casi toda la sección del tronco, lo único que puedes aprovechar de tu estropicio es un ridículo leño.\n");
say("... pero, habiendo destrozado practicamente toda la sección del tronco solo consigue aprovechar un miserable leño.\n");
break;
    case 2..3:
write("... pero, tras destrozar buena parte, tan solo consigues sacar en buen estado "+itoa(cantidad)+
" leños, el resto queda convertido en astillas inútiles.\n");
say("... pero, después de destrozar gran parte, tan solo saca en buen estado "+itoa(cantidad)+
", pues el resto ha quedado convertido en astillas inútiles.\n");
break;
case 4..7:
    write("... y consigues  sacar en buen estado "+itoa(cantidad)+
" leños, el resto queda convertido en pequeñas astillas.\n");
say("... y consigue sacar en buen estado "+itoa(cantidad)+
", quedándo el resto convertido en pequeñas astillas.\n");
break;
default:
write("... y consigues  sacar en buen estado "+itoa(cantidad)+
" leños.\n");
say("... y consigue sacar en buen estado "+itoa(cantidad)+
".\n");
break;
}//switch
remove_action("", TP); // para que se pueda mover ya después de haber terminado
TP->exp(cantidad*XP_BASICO);
TO->remove();
}

