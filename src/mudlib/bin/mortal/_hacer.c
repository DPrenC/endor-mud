// Comando hacer

#define NUM_HACER 10 // [w] Está limitado a 10 hacer

public int main(string str) {
    int i, n, s;
    string *strs, cmd;
    object me = TP;

    if (  !str
        || str == "?"
        || !( s = sizeof(strs = explode(str, ";")-({""})) )
       )
    {
        return notify_fail(
"        Uso    : hacer [<veces1>#]<cmd1>;[<veces2>#]<cmd2>;[<veces3>#]<cmd3>..\n"
"        Ejemplo: hacer 3#n;2#e;coger espada;3#n\n");
    }

    //dtell("nyh",sprintf("Hacer TP = %O\n", me));
    for(i=0; i<s; i++) {
        if(strs[i]) {
            switch(sscanf(strs[i], "%d#%s", n, cmd)) {
            case 0:
      //dtell("nyh",sprintf("\tme = %O\tComando: %O\n",me, strs[i]));
	            if(!command(strs[i], me)) return 1;
	            break;
            case 1:
      //dtell("nyh",sprintf("\tme = %O\tComando: %O\n",me, cmd));
	            if(cmd&&(!command(cmd, me))) return 1;
	            break;
            case 2:
	            n= n<1 ? 1 : n;
	            if (n>NUM_HACER) n = NUM_HACER;
	            if(cmd) {
	                while(n--)
      //dtell("nyh",sprintf("\tme = %O\tComando: %O\n",me, cmd));
	                    if(!command(cmd, me)) return 1;
	            }
	            break;
            }
        }
    }
    return 1;
}
