def print_hash(string, length):
    result = 0
    r = 31
    m = 1234567891
    for i in range(length):
        result += (ord(string[i]) - ord('a') + 1) * pow(r, i)
    result %= m
    print(result)

length = int(input())
string = input().strip()
print_hash(string, length)