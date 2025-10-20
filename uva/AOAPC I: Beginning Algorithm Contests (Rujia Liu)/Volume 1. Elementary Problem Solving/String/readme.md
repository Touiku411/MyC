# 題目: 10361 - Automatic Poetry
## 題意
- 第一行 s1<s2>s3<s4>s5 ，要輸出 s1s2s3s4s5 ，第二行碰到...要輸出s4s3s2s5
## 解
- 用find和substr取要的字串部分，設p1~p4存'<''>'位置
- 用substr取s1~s5

# 題目: 10878 - Decode the tape
## 題意
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
<pre>
Before       After
<u>ban</u>ana boat  babana boat
babana boat  bababa boat
bababa boat  beba boat
beba boat    behind the goat
</pre>
