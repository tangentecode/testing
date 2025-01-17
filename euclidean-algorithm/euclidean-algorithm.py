# get input
a = int(input("First number: "))
b = int(input("Second number: "))


# calculate result
while b > 0:
    r = a % b
    a = b
    b = r

# output
print("Result: ", a)

