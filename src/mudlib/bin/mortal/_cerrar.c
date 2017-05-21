// comando cerrar para las puertas

public int main(string str)
{
    object env;
    if (!TP) return 0;
    env = environment(TP);
    if (!env) return 0;
    return env->fopen_close_door(str);
}

