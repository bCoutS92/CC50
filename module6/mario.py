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
for j in range(number):

    # Spaces
    for space in range(number - j - 1):
        print(" ", end="")

    # Blocks
    for i in range(j + 1):
        print("#", end="")

    print()
