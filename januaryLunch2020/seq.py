MOD = 1000000007
def fast_power(base, power):
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % MOD
        power = power // 2
        # Multiply base to itself
        base = (base * base) % MOD

    return result


T=int(input())
while(T>0):
     T-=1
     N,M = map(int,input().split())
     if N<3:
          print(fast_power(M,N))
     else:
          A=fast_power(M,N)
          B=M*fast_power((M-1),(N-3))
          print(A-B)
