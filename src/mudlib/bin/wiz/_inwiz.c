// Comando inwiz

#include <messages.h>
#include <attributes.h>
#include <properties.h>

public int main(string arg) {
    mixed mmsgout;

    if (arg) return notify_fail("Uso: "+query_verb()+".\n");

    if ( TP->Query(P_INVIS) && TP->Query(P_INWIZ) ) {
        return notify_fail("Ya eras inwizible.\n");
    }

    mmsgout = TP->QueryAttr(A_MMSGOUT);
    if (!pointerp(mmsgout)) mmsgout = ({ mmsgout });
    tell_room(environment(TP), ({ MSG_SEE, TP->QueryName()+" "+mmsgout[0]+".\n" }), ({ TP }));

    TP->Set(P_INVIS, 1);
    TP->Set(P_INWIZ, 1);
    write("Te vuelves inwizible.\n");

    return 1;
}
