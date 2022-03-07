import time

def ti(func):
    def wrapper(*args,**kwargs):
        t1 = time.time()
        ret=func(*args,**kwargs)
        t2=time.time()
        print('{:.3}'.format(t2-t1))
        return ret
    return wrapper


def len_ex(int_ex):
    a = []
    count = 0
    while (int_ex >= 1):
        c = int_ex % 2
        int_ex = int_ex // 2
        count += 1
        a.append(c)
    return count, a

@ti
def mod(int_bn, int_ex, int_m):
    x = 1
    k, bit = len_ex(int_ex)
    power = int_bn % int_m
    for i in range(k):
        if bit[i] == 1:
            x = (x * power) % int_m
        power = power * power % int_m
    return x