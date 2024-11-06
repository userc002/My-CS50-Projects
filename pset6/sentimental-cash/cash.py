# TODO
from cs50 import get_float

coins= 0

while True:
    cents= get_float("Cash owed -")
    if cents>0:
        break

cents= round(cents*100)

while cents>= 25:
    coins+= 1
    cents-= 25

while cents>= 10:
    coins+= 1
    cents-=10

while cents>= 5:
    coins+= 1
    cents-= 5

while cents>= 1:
    coins+= 1
    cents-= 1

print(coins)