#include <stdio.h>
#include "slist.h"

int main(void)
{
    node *head = NULL;

    printf("=== 測試 push_head ===\n");
    push_head(&head, 3);
    push_head(&head, 2);
    push_head(&head, 1);
    print_list(head); // 預期: 1 -> 2 -> 3 -> NULL

    printf("\n=== 測試 append_tail ===\n");
    append_tail(&head, 4);
    append_tail(&head, 5);
    print_list(head); // 預期: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    printf("\n=== 測試 insert_after ===\n");
    insert_after(head, 2, 99);   // 在位置 2 後插入 99 (1-based)
    print_list(head); // 預期: 1 -> 2 -> 99 -> 3 -> 4 -> 5 -> NULL

    printf("\n=== 測試 delete_value ===\n");
    delete_value(&head, 99);
    print_list(head); // 預期: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    printf("\n=== 測試 reverse_list ===\n");
    reverse_list(&head);
    print_list(head); // 預期: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

    printf("\n=== 測試 list_size ===\n");
    printf("size = %d\n", list_size(head)); // 預期: 5

    printf("\n=== 測試 free_list ===\n");
    free_list(&head);
    print_list(head); // 預期: (空)

    return 0;
}
