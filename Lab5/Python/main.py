from TPoint import *
from random import random


mode = ''
q = 0
k = 0
t = -1
xyz = {}

print('Рухома матеріальна точка (x, y, z)')
while mode != '+' and mode != '-':
    mode = input('Генерувати випадкові числа? (+/-): ')

while q < 2:
    q = int(input('Введіть q: '))

while t < 0:
    t = int(input('Введіть t: '))

if mode == '+':
    for i in range(q):
        xyz[i] = TPoint_xyz(random() * 100, random() * 100, random() * 100, random() * 100, random() * 100, random() * 100, t)
else:
    for i in range(q):
        print(f'{i}: Введіть значення (x0, ax, y0, ay, z0, az): ')
        x0 = int(input())
        ax = int(input())
        y0 = int(input())
        ay = int(input())
        z0 = int(input())
        az = int(input())
        xyz[i] = TPoint_xyz(x0, ax, y0, ay, z0, az, t)

min_val = float('inf')
min_t1 = 0
min_t2 = 0

for i in range(q-1):
    for j in range(i + 1, q):
        tmp = xyz[i].count_distace(xyz[j].coord)
        if tmp < min_val:
            min_val = tmp
            min_t1 = i
            min_t2 = j

for i in range(q):
    xyz[i].output(i)

print(f'Найменше значення між точками {min_t1} і {min_t2}: {min_val}')


print('\n\n\n')


mode = ''
t = -1
xy = {}

print('Рухома матеріальна точка (x, y)')
while mode != '+' and mode != '-':
    mode = input('Генерувати випадкові числа? (+/-): ')

while k < 2:
    k = int(input('Введіть k: '))

while t < 0:
    t = int(input('Введіть t: '))

if mode == '+':
    for i in range(q):
        xy[i] = TPoint_xy(random() * 100, random() * 100, random() * 100, random() * 100, t)
else:
    for i in range(q):
        print(f'{i}: Введіть значення (x0, ax, y0, ay): ')
        x0 = int(input())
        ax = int(input())
        y0 = int(input())
        ay = int(input())
        xy[i] = TPoint_xy(x0, ax, y0, ay, t)

min_val = float('inf')
min_t1 = 0
min_t2 = 0

for i in range(k-1):
    for j in range(i + 1, k):
        tmp = xy[i].count_distace(xy[j].coord)
        if tmp < min_val:
            min_val = tmp
            min_t1 = i
            min_t2 = j

for i in range(k):
    xy[i].output(i)

print(f'Найменше значення між точками {min_t1} і {min_t2}: {min_val}')