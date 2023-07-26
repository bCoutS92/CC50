number = 0
space = 1
while True:
    try:
        number = int(input("Altura: "))
        if (number > 0) and (number < 9):
            break
    except:
        print("", end="")

#Create new lines
for j in range(0, number, 1):
    for i in range(0, number + j + 3, 1):
        if (i == number or i == number + 1 or j + i < number - 1):
            # Spaces
            print(" ", end="")
        else:
            # Blocks
            print("#", end="")
    print()