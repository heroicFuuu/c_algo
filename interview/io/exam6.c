
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int i;
    for(i=0; i<2; i++){
        fork();
        printf("-");
        fflush(stdout);
    }

    wait(NULL);
    wait(NULL);
    // 感覺上會印出 6 個 但實際上8個
    // 會印出 8 個 來自 第一次迴圈p1印"-"  c1子程序會複製一份緩衝區""會印 "-"
    // 然後 第二次 p1緩衝區"-" 複製出 c2 "-"， p1 "-" c2 "--" ;然後 c1緩衝區"-" 複製出 c3 "-"，c2 "-" c3 "--" 
    return 0;
    
}
