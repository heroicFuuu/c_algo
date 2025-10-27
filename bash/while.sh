#!/bin/bash

# 建立 path 變數，將系統 PATH 複製過來，最後加一個冒號
path="$PATH:"

echo "=== 掃描 PATH 中的每個目錄 ==="

# 只要 path 不是空的就繼續
while [ "$path" ]; do
    
    # 取出第一個冒號前的內容（第一個目錄）
    dir="${path%%:*}"
    
    # 印出這個目錄
    echo "DIR: $dir"
    
    # 去掉第一個目錄與冒號，準備下一輪
    path="${path#*:}"
done
