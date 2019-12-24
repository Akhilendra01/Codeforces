tc = input()
words = input().split()
for word in words:
    if word[0] == tc[0] or word[1] == tc[1]:
        print("YES")
        exit()
print("NO")
