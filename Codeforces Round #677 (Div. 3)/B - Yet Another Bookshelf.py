def getFirstOne(arr):
    n = len(arr)
    for i in range(0,n):
        if arr[i] == 1:
            return i
    return -1
    
def getLastOne(arr):
    n = len(arr)
    for i in range(n-1,-1,-1):
        if arr[i] == 1:
            return i
    return -1

def getMinMoves(arr):
    firstOne = getFirstOne(arr)
    if firstOne == -1:return 0
    lastOne = getLastOne(arr)
    minMoves = 0
    for i in range(firstOne,lastOne+1):
        minMoves += 1 - arr[i]
    return minMoves

t = int(raw_input())
for _ in range(t):
    n = int(raw_input())
    arr = list(map(int, raw_input().split()))
    minMoves = getMinMoves(arr)
    print minMoves
        
