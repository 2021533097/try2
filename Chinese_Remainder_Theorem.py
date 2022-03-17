import functools


# 使用到扩展欧几里德算法
def exgcd_1(a, b):
    l1 = [(a, b)]
    n = 0
    while b != 0:
        a, b = b, a % b
        l1.append((a, b))
        n += 1
    x, y = 1, 0
    l1 = l1[::-1]
    for a, b in l1[1:len(l1)]:
        x, y = y, x - (a // b) * y
    return (l1[0])[0], x, y


num = 0
isvalid = True
print("q to quit")

def multiply(a, b):
    return a * b


result = []
A_set = []
N_set = []
Y = list()

while isvalid:
    num = input("The number of your equations")
    if num == 'q' or num == 'Q':
        break
    try:
        num = int(num)
    except ValueError:
        print("Please input an integer:")
        continue
    else:

        for i in range(num):
            A_set.append(int(input("a1: ")))
            N_set.append(int(input("n1: ")))
        isvalid = False
        N = functools.reduce(multiply, N_set)
        N_2 = [N // i for i in N_set]
        x = 0
        for i in range(num):
            Y.append(exgcd_1(N_2[i], N_set[i])[1])
            x += Y[i] * N_2[i] * A_set[i]
        print(x)
        break
print("Bye")
