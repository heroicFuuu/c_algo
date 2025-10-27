#!/bin/bash

selectd() {
    PS3='directory? '             # 自訂 select 提示字串
    dirstack=" $DIR_STACK "       # 兩側加空白，方便字串操作

    select selection in $dirstack; do
        if [ $selection ]; then    # 有選擇到項目才執行
          
            # (1) 把選擇的項目移到最前面
            DIR_STACK="$selection${dirstack%% $selection *}"
            
            # (2) 把剩下的項目接回後面，形成新堆疊
            DIR_STACK="$DIR_STACK ${dirstack##* $selection }"
            
            # (3) 移除最右邊多餘空格
            DIR_STACK=${DIR_STACK% }
            
            # (4) 切換到這個目錄
            cd $selection
            
            break  # 離開 select 選單
        else
            echo 'invalid selection.'
        fi
    done
}
