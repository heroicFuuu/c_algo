#include <stdio.h>
int main() {
    float a = 12.5;
    printf("%d\n", a);
    printf("%d\n", (int) a);
    printf("%d\n", *(int*) &a);
    return 0;
}
/*

參考答案：
該項程序輸出如下所示，
0 (-749071256 (x86-64 clang 17.0.1), 1027694856 (x86-64 gcc 13.2))
12
1095237632

Explaination：

12.5f 的二進制表示法 (sign, exponent, mantissa)：

sign	exponent	mantissa
0	10000010	10010000000000000000000
先把 12.5 轉二進位：1100.1，平移三位後：1.1001，所以 exponent 會是 3 + 127 = 130，130 二進位表示為
10000010。mantissa 就是平移之後的結果補滿零。

因此 12.5f in binary = 01000001010010000000000000000000。

IEEE-754 Floating Point Converter
十六進制是：0x41480000，十進制是：1095237632。

第二和第三行的 output 比較簡單就可以判斷出來，(int) a 就是 cast a float to
int，直接去掉小數點。*(int *)&a 是 dereference a interger pointer which points to this floating
point，對於這 32 個 bit 而言，會用 interger 的觀點去處理，而 01000001010010000000000000000000 對於
int 來說，值就是 1095237632。

而對於第一個，為什麼會輸出 0？

我們需要瞭解一下 float 和 double 的記憶體佈局，如下：

float: 1位符號位(s)、8位指數(e)，23位尾數(m,共32位)

double: 1位符號位(s)、11位指數(e)，52位尾數(m,共64位)

然後，我們還需要瞭解一下 printf 由於類型不匹配，所以，會把 float 直接轉成 double(What happens to a
float variable when %d is used in a printf?)，注意，12.5 的 float 和 double
的記憶體二進制完全不一樣。別忘了在x86晶片下使用是的反位元組序，高位位元組和低位字位要反過來。所以：

float版：0x41480000 (在記憶體中是：00 00 48 41)
double版：0x4029000000000000 (在記憶體中是：00 00 00 00 00 00 29 40)
而我們的%d要求是一個4位元組的int，對於double的記憶體佈局，我們可以看到前四個位元組是00，所以輸出自然是0了。

這個示例向我們說明printf並不是類型安全的，這就是為什麼C++要引如cout的原因了。

*/