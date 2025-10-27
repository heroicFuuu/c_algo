
void (*(*papf)[3])(char*);

/*等價寫法*/
typedef void (*pf)(char*); // type : 指向函式的指標
pf (*papf)[3];
