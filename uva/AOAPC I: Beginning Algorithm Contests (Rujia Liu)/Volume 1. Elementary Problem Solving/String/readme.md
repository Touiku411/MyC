# 題目: 10361 - Automatic Poetry
## 題意
- 第一行 s1 < s2 > s3 < s4 > s5 ，要輸出 s1s2s3s4s5 ，第二行碰到...要輸出s4s3s2s5
## 解:
- 用find和substr取要的字串部分，設p1~p4存'<''>'位置
- 用substr取s1~s5

# 題目: 10878 - Decode the tape
## 題意:
- 每列| | 中空格代表0，o代表1，每列不含|跟.共有八個字元，每列會得到一個8-bit二進位
- 將二進位轉為十進位並對照Ascii表將其對應字符輸出
## input
```
___________
| o   .  o|
|  o  .   |
| ooo .  o|
| ooo .o o|
| oo o.  o|
| oo  . oo|
| oo o. oo|
___________
```
## ouput
```
A quick
```

# 題目: 10115 - Automatic Editing
```
Rule Find  Replace-by
1.   ban   bab
2.   baba  be
3.   ana   any
4.   ba b  hind the g
```
```
Before       After
banana boat  babana boat
babana boat  bababa boat
bababa boat  beba boat
beba boat    behind the goat
```
## 目標:
- 解析一字串，若該字串中找到ban、baba、...就將該部分替換成Replace-by部分 <註>每個測資Rule不相同
- 每替換完得到一新字串時，比對Rule時須重頭開始搜尋
## 解:
- 用vector<pair<string, string>> Rules存Rules
- 接著遍歷Rules，若字串找到Find，紀錄該位置pos，和Find的len
- 對字串replace(pos, len, "Replace")
- 最後輸出字串

# 題目: 644 - Immediate Decodability
- 判斷一編碼(二進位)是否存在前綴
- 思路:
  - A = 0101, B = 010 , 則 B 為 A 的前綴
  - 若 B.rfind(A, 0) == 0 || A.rfind(B, 0) == 0 (B 為 A 的前綴 或 A 為 B 的前綴)

# 題目: 409 - Excuses, Excuses!
- 給t1個Keywords，t2句Excuses，回傳字串中出現最多個關鍵詞的字串。
- Keyword皆為小寫字母，Excuse : 大寫字母視同小寫、關鍵詞可重複。
## 解:
- 設一temp = Excuses，將temp 字母轉為小寫，若遇到非字母轉成空格。
- 用stringstream 解析 temp 並遍歷 Keyword 存取Keyword出現次數(cnt)，存取該字串idx跟cnt。
- 當cnt == Max 時輸出Excuses[idx]。

# 題目： 537 - Artifical intelligence? 
## P = U * I
- 有三種情況: 給 P、U 求 I ， 給 P 、 I 求 U ， 給 U、I 求 P。
- 找到字串中 size_t = {P= , U= , I= }， 再根據上面三種情況找到對應 P U I 的單位 { W , V, A } 。
- 最後再處理遇到單位 m 、 k 、 M ， 分別乘上 1e-3 , 1e3 , 1e6 。
  
# 題目： 10010 - Where's Waldorf?
- 判斷word是否在grid中(8個方向:左上右下、左上、右上、右下、左下)，方向用dx,dy儲存。
- 在grid中若與word的第一個字匹配則向8個方向遍歷搜尋
