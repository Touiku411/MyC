- 均勻隨機從array中選一個pivot.
- 讓小於pivot的排在pivot左邊,大於的排右邊

# step:
- 先將pivot與sub array最後位置交換以方便計算
- 兩變數 i = left, j = left
- j 負責向前搜尋 array[j] 是否小於pivot
- i 負責紀錄位置與 j 位置交換
```
array[j] < pivot
  swap(array[i],array[j])
  i++;
```
- 最後 i 會剛好停在交界處 , 再將 array[i] 與 pivot 換回來:
- 讓各自排好的子字串繼續排... [left ~ i - 1], [i + 1 ~ right]
