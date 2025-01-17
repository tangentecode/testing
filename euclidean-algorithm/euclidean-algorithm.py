a = int(input("First number: "))
b = int(input("Second number: "))

while b > 0:
    r = a % b
    a = b
    b = r

print("Result: ", a)

