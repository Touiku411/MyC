# 題目 : 340 - Master-Mind Hints
## 幾A幾B問題
## 解:
- 建立一個vector<pair<int,bool>> vec;，存放數字跟是否已經選擇過。
- 找A
  - 判斷相同位置相同數字
- 找B
  - 判斷不同位置但有該數字
  - secret : 1 3 5 5 (答案)
  - guess  : 6 5 5 1 (猜)
  - 由guess[0]開始遍歷secret，如果兩數字相同且該位置尚未被選擇，則找到該數並結束這回合搜索。
  - 每次遍歷完guess[i]，重製secret的bool。

# 題目 : 400 - Unix ls
- ceil(A/B) (無條件進位)
  - (A + B - 1) / B
- round(A/B) (四捨五入)
  - (A + B / 2) / B
