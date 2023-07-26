from cs50 import get_float

def main():
    change = get_change()
    print("O mínimo de moedas a ser dado no troco é (são): ", end="")
    show_result(change)


def get_change():
    while True:
        change = get_float("Quantas moedas são necessárias para dar o seguinte troco (digite o troco desejado): ")
        if change >= 0:
            break
    return change

def show_result(change):
    resultado = round(change * 100)
    qrt = resultado // 25
    resultado %= 25

    dim = resultado // 10
    resultado %= 10

    pen = resultado // 5
    resultado %= 5

    nic = resultado // 1
    total = qrt + dim + pen + nic
    print(total)

main()