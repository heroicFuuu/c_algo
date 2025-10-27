#!/bin/bash

# 判斷第一個參數是否為 -數字 格式，例如 -10, -5
if [ -n "$(echo $1 | grep '^-[0-9][0-9]*$')" ]; then
    howmany=$1
    shift
elif [ -n "$(echo $1 | grep '^-')" ]; then
    echo "usage: highest [-N] filename"
    exit 1
else
    # 預設值，設為 -10
    howmany="-10"
fi

# 第二個參數視為檔案名稱
filename=$1

# 顯示哪些行會被處理（測試用，只顯示資訊）
echo "howmany = $howmany"
echo "filename = $filename"

# 真正功能 (在測試時可以先不用執行)
# sort -nr $filename | head $howmany
