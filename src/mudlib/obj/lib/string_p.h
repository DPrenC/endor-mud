varargs string mkstr (int len, string pattern);
varargs string ladjust (string str, int len, string pattern);
varargs string ladjcut (string str, int len, string pattern);
varargs string radjust (string str, int len, string pattern);
varargs string radjcut (string str, int len, string pattern);
varargs string cadjust (string str, int len, string pattern);
varargs string cadjcut (string str, int len, string pattern);
string string_replace (string str, string old, string new);
int string_compare (string str1, string str2);
varargs string *sort_strings (string *strs, string compare_fun);
string *break_string (string str, int len);
varargs string *break_line (string str, int len, string prefix);
string lit_string (string str);
varargs string mixed_to_string (mixed value, int depth);
varargs string stime (int date, int fmt);
void smore_prompt (int firstline, int lastline, int maxline)
void smore_help (int chunksize);
varargs int smore (mixed text, int quiet, int chunk);
int _even_smore (string str);
