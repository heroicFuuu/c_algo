#include<stdio.h>
// int main()
// {
//     
//     static int i=5;
//     if(--i){
//         // 先遞迴到底 (i==0) 
//         main();
//         // 結束遞迴後，因為(i==0)
//         printf("%d ",i);
//     }  
//     printf("\n");
//     return 0;
// }


int main()
{
    static int var = 5;
    printf("%d ",var--);
    if(var)
        main();         
    printf("\n");
    return 0;          
}
