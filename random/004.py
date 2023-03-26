import math

h, w, a = [int(j) for j in input("").split()]

if a * a >= h * w:
    print(1)
else:
    len_h = 1 if h <= a else math.ceil(h / a)
    len_w = 1 if w <= a else math.ceil(w /a)
    print(len_w * len_h)
