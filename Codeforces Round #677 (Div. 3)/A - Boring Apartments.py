def getOneDigitOf(n):
    return n%10
    
def countDigits(n):
    cnt = 0
    while n > 0:
        n /=10
        cnt+=1
    return cnt
    
def sequanceSum(n):
    return n*(n+1)/2
    
# Where group is apartment numbers which have the same digit , e.g (1,11,111,1111)
GROUP_PRESSES = 10

t = int(raw_input())
for _ in range(int(t)):
    x = int(raw_input())
    
    n = getOneDigitOf(x-1)
    pressesExceptLastGroup = GROUP_PRESSES * n
    
    digitsCount = countDigits(x)
    lastGroupPresses = sequanceSum(digitsCount)
    
    ans = pressesExceptLastGroup + lastGroupPresses
    print ans
