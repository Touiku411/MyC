# 題目:Polynomial Addition 2
## Sample Input
```
2  
3  
1 -2 -4  
3 2 0  
1  
4  
0  
3  
-1 -2 4  
3 2 0  
4  
1 2 1 -7  
3 2 1 0  
```
## Sample Output
```
2  
1 -2  
3 2  
2  
1 -3  
1 0  
```
## 題目重點
*此題為反向輸入輸出*
 −x^3 − 2x^2 + 4
                    (2)(1)(0)                  
 coefficient array: −1 −2  4
                    (2)(1)(0) 
 exponent array   :  3  2  0

## 解題步驟
- 從最低次idx = 0開始往前判斷
- 設 i,j,k = 0 ， k為存sum之idx ，若 addendExpon[i] > adderExpon[j] => sum就放入較小項adder，反之放入addend，若相等時則放入兩項相加。
- 處理剩餘:
  - 若 i 還小於 addendSize 時， sum放入 addend，同 j 。
- 根據例子最後sum[0]~sum[2]是{4, -2, -1}，因輸出要從最高項，所以 sumSize = k;

# 題目:Polynomial Multiplication 2
## Sample Input
```
2  
3  
1 -2 -4  
3 2 0  
1  
4  
0  
3  
-1 -2 4  
3 2 0  
4  
1 2 1 -7  
3 2 1 0  
```
## Sample Output
```
3  
4 -8 -16  
3 2 0  
7  
-1 -4 -5 9 22 4 -28  
6 5 4 3 2 1 0  
```
## 解題思路
```
multiplicand -1x^3 - 2x^2         -  4
                  ⬉      ⬉          ⬆    
multiplier    1x^3 + 2x^2 +   1x  -  7   X
           _________________________________
```
- 從multiplier最低項開始，乘上multiplicand的每一項，會得到一個新的多項式，根據multiplierSize會得到multiplierSize個多項式
- 最後將多個多項式相加即可得到答案
- **若係數相加為 0 則跳過**

# 題目:Polynomial Division 2
## Sample Input
```
2
3
4 -8 -16
3 2 0
1
4
0
7
-1 -4 -5 9 22 6 -26
6 5 4 3 2 1 0
4
1 2 1 -7
3 2 1 0
```
## Sample Output
```
3  
1 -2 -4
3 2 0
1
0
0
3
-1 -2 4
3 2 0
2
2 2
1 0
```
## 解題思路
- 商 = 被除式 / 除式
- 被除式 - 商 * 除式 = 餘式
## 解題步驟
- 將餘式初始化為被除式
- 初始化商Size = 0(從0開始放，因最後從Size遞減輸出，所以商的結果須反轉)
- *開始除*
  - 條件:當餘式次方最高項>=除式次方最高項時
  - 商
    - 係數 : 第一項(最高項) = 餘式最高項 / 除式最高項
    - 次方 : 第一項(最高項) = 餘式最高項 - 除式最高項
    - 把係數和次方從 quotientSize = 0 遞增放入 quotientCoef、quotientExpon
  - 設一個暫存陣列Temp存 【商 * 除式】，因餘式從0到餘式Size是遞增，所以Temp也從0遞增輸入(從除式【最低項往高*商】)
  - *判斷整除*
    - 當餘式 = 暫存陣列，餘式Size = 1、係數和次方 = 0
  - 否則 呼叫 subtraction() 回傳當前【餘式 - 暫存】為新餘式
  - subtraction()為從最低項開始判斷(取較小)
