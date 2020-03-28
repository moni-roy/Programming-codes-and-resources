char * defangIPaddr(char * a){
    char *s = (char*)malloc(sizeof(char)*29);
    int j = 0;
    for(int i = 0; a[i]; i++){
        if(a[i]=='.'){
            s[j++] = '[';
            s[j++] = a[i];
            s[j++] = ']';
        }
        else s[j++] = a[i];
    }
    s[j] = '\0';
    
    return s;
}
