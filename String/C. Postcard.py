#https://codeforces.com/contest/1099/problem/C

def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())
 
s = input().strip()
k = ii()
n = len(s)
cc, sf = s.count('?'), s.count('*')
m = n - cc - sf
ans = 'Impossible'
if m == k:
    ans = ''.join(c for c in s if c not in '?*')
elif m < k:
    d = k - m
    if sf:
        ans = []
        for i in range(n):
            if s[i] == '?':
                pass
            elif s[i] == '*':
                if d:
                    ans.append(s[i - 1] * d)
                    d = 0
            else:
                ans.append(s[i])
        ans = ''.join(ans)
else:
    d = m - k
    if d <= cc + sf:
        ans = []
        for i in range(n):
            if s[i] in '?*':
                if d:
                    ans.pop()
                    d -= 1
            else:
                ans.append(s[i])
        ans = ''.join(ans)
 
print(ans)