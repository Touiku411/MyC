# 題目：Polynomial Addition 1

## Sample Input
2  
3 1 -2 0 -4  
0 4  
3 -1 -2 0 4  
3 1 2 1 -7  
## Sample Output
3 1 -2 0 0  
1 1 -3  

## 解題步驟
- 計算長度i = max(adddendDegree,adderDegree);
- 從最高項開始判斷，如果 i > addendDegree，sum[i] = adder[i]，反之 i < adderDegree，sum[i] = addend[i]，否則相加
- 最後取sum的最高項

# 題目：Polynomial Multiplication 1

## Sample Input
1  
3 1 -2 0 -4  
1 1 -3  
## Sample Output
4 1 -5 6 -4 12  

## 解題步驟
- 乘法係數相乘，次方相加。
- 乘項的位數i會得到i項乘項*被乘項
- 最後將乘出結果相加。結果[乘項次方加被乘項次方] += 乘項係數 * 被乘項係數


# 題目：Polynomial Division 1

## Sample Input
2  
3(最高次) 1 -3 4 -5 -> 除式  
2 1 0 2 -> 被除式  
2 1 0 -1  
1 1 1  
## Sample Output
1 1 -3 -> 商  
1 2 1 -> 餘式  
1 1 -1  
0 0  

## 題目重點
1.此題次方為係數的idx  
−x^3 − 2x^2 + 4  
次方 3  2 1 0  
係數−1 −2 0 4  

## 解法步驟
- 先將餘式初始化成被除式
**以下以餘式表示被除式**
- 商式最高次為餘式最高次-除式最高次
*開始計算*
- 條件:當餘式最高次方>=除式最高次方
- 當餘式最高次為0時跳過
- 商:
  - 係數為餘式最高次項/除式最高式項
  - 次方為餘式最高次方-除式最高次方
- 餘式-商*除式:
  - 長度為除式長度(divisorDegree)
  - 餘式從最高項(除式次方+商式次方)開始每項減掉(商係數*除式係數)
- 每次循環餘式長度-1(第一項一定會消掉)
*結果*
- 若整除 -> 餘式長度 = 0
- 否則 -> 從被除式長度(dividendDegree)開始判斷



