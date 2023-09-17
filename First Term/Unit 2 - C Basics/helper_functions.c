void memory_dump(char *first, int size){
    char *end = first + size;
    for (; first<end; first++){
        printf("%p:\t%x\n", first, *first);
    }
}