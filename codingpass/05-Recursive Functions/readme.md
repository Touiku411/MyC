# 題目: Prime Numbers
## 解題思路
- 判斷一整數是否為質數:
- n = 判斷的數, end = sqrt(n)
- 從end開始判斷 n / end 是否整除，若整除則回傳true，否則呼叫hasFactor(n, end - 1)， 當 end == 1 時代表沒有找到因數，回傳false
```
bool hasFactor(int n, int end)
{
    if (end == 1)return false;
    if (n % end != 0) {
        return hasFactor(n, end - 1);
    }
    return true;
}
```
# 題目: The Summation of Even Integers
## 解題思路
- 回傳 range(a, b + 1)中 偶數和
- 從 a 開始判斷是否為偶數，若是呼叫 a + evenSum(a + 1, b) ， 否則呼叫evenSum(a + 1, b)。
- 當 a > b 時停止
```
int evenSum(int a, int b)
{
    if (a > b) return 0;
    if (a % 2 == 0) 
        return a + evenSum(a + 1, b);
    else
        return evenSum(a + 1, b);
}
```
# 題目: Palindromes
## 解題思路
-  first = 0, last = len - 1
-  len個數偶數時停止判斷條件為 first > last，奇數時為 first == last
-  當 first >= last 回傳true
-  若第 first 項 != last項時回傳 false，否則呼叫isPalindrome (first + 1, last - 1)
```
bool isPalindrome(int first, int last)
{

    if (first >= last)return true;
    if (digits[first] != digits[last])
        return false;
    else
        return isPalindrome(first + 1, last - 1);
}
```
# 題目: Perfect Numbers
## 解題思路
- 因數合為自己本身
- 目標: 回傳因數和
- n = 判斷的數，start = 1
- 當 n % start == 0 時呼叫 start + sumFactors(n, start + 1)，否則呼叫 sumFactors(n, start + 1)，當 start > n/2 時回傳 0
```
int sumFactors(int n, int start)
{
	if (start > n / 2)return 0;
	if (n % start == 0)
		return start + sumFactors(n, start + 1);
	else
		return sumFactors(n, start + 1);

}
```
# 題目: Armstrong Numbers
## 解題思路 
- 目標: 回傳每位數的該數次方(長度)和
- ex. 123 ， len = 3 ， return 1^3 + 2^3 + 3^3
- sumPowerDigits
  - n % 10 得到第 i 位數
  - 回傳 power(n % 10, numDigits) + sumPowerDigits(n / 10) ， 當 n == 0 時停止
- power
- 目標: 回傳d的p次方
- 呼叫 d * power(d, p - 1)，當 p == 0 時回傳 1 。
```
int sumPowerDigits(int n)
{
    if (n == 0)return 0;
    return power(n % 10, numDigits) + sumPowerDigits(n / 10);
}
// returns the p-th power of d
int power(int d, int p)
{
    if (p == 0)return 1;
    return d * power(d, p - 1);
}
```
