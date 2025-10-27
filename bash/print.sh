#!/bin/bash

# 初始程式，從這裡開始
recls() {
    singletab="    "      # 一層縮排（四個空格，或可改為 "\t"）
    branch="|-----"       # 用於顯示節點線
    vertical="|    "      # 用於顯示垂直連接線

    for tryfile in "$@"; do
        echo "$tryfile"
        if [ -d "$tryfile" ]; then
            thisfile=$tryfile
            recdir $(ls "$tryfile")
        fi
    done

    unset tab thisfile singletab branch vertical
}

# 遞迴顯示樹狀結構
recdir() {
    tab="$tab$vertical"    # 進入下一層，增加垂直線

    for file in "$@"; do
        echo "${tab}${branch}${file}"
        
        thisfile="$thisfile/$file"   # 更新現在路徑
        
        if [ -d "$thisfile" ]; then
            recdir $(ls "$thisfile")
        fi
        
        thisfile="${thisfile%/*}"    # 回到上一層路徑
    done

    tab="${tab%$vertical}"   # 返回上一層縮排
}

# ==========
# 主執行入口
# ==========
if [ -z "$1" ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

recls "$1"
