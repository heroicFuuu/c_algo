#define dPS struct s* // 這只是替換字元
typedef struct s* tPS;

/*

dPS p1, p2;
tPS p3, p4;

會在前置處理器階段

struct s* p1, p2;// p2不是指標而是一個變數
struct s *p3;
struct s *p3;


*/
