def getAbbreviation(word):
    return word[0] + str(len(word)-2) + word[-1]
 
t = int(raw_input())
for _ in range(t):
    word = raw_input()
    if len(word)>10:
        word = getAbbreviation(word)
    print word
