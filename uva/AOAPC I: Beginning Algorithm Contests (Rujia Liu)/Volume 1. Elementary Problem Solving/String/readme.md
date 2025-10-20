## 題目: 10361 - Automatic Poetry
# 題論
- 第一行 s1<s2>s3<s4>s5 ，要輸出 s1s2s3s4s5 ，第二行碰到...要輸出s4s3s2s5
# 解
- 用find和substr取要的字串部分，設p1~p4存'<''>'位置
- 用substr取s1~s5
