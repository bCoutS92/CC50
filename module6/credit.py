from cs50 import get_string
import sys

def main():
    credit_card = get_credit_card()
    sys.stdout.write("A bandeira do cartão é: ")
    show_result(credit_card)
    sys.stdout.write(".\n")

def get_credit_card():
    while True:
        credit_card = get_string("Digite o número do cartão de crédito: ")
        if len(credit_card) >= 13 and len(credit_card) <= 16:
            break
        else:
            print ("DIGITE UM NÚMERO ENTRE 13 E 16 DÍGITOS.")

    return credit_card

def show_result(credit_card):
    number = credit_card  # Armazena o número do cartão de crédito em "number"
    count = 0  # Contador contar os dígitos do cartão e descobrir o lenght.
    soma = 0  # Variável para somar os dígitos do cartão

    # Itera pelos dígitos do número do cartão de crédito de trás para frente
    for digit in reversed(number):
        digit = int(digit)

        if count % 2 == 0:
            # Pega os dígitos em posições pares, adiciona o dígito à soma
            soma += digit
        else:
            # Pega os dígitos em posições ímpares, multiplica por 2 e trata os dígitos resultantes
            multiplied = digit * 2
            soma += multiplied % 10 + multiplied // 10

        count += 1
        # verifica se o valor da "soma" é divisível por 10 sem deixar resto.
    # no loop anterior "soma" calcula a soma dos dígitos do cartão, logo se soma for divisível por 10 sem resto, atende ao critério de validação do algoritmo.
    # ao calcular, se houver resto na divisão, logo o cartão não passou no critério do algoritmo e passa para o último "else: sys.stdout.write("NÚMERO INVÁLIDO")"
    if soma % 10 == 0:
        # Verifica as condições para determinar a bandeira do cartão
        # trata o número do cartão de crédito como uma string
        # Bandeira American Express (AMEX), os dois primeiros dígitos são "34" ou "37"
        if count == 15 and (number[:2] == "34" or number[:2] == "37"):
            sys.stdout.write("AMEX")
        # Bandeira MasterCard, os dois primeiros dígitos estão na lista ["51", "52", "53", "54", "55"]
        elif count == 16 and number[:2] in ["51", "52", "53", "54", "55"]:
            sys.stdout.write("MASTERCARD")
        # Bandeira Visa, primeiro dígito é "4"
        elif (count == 13 or count == 16) and number[0] == "4":
            sys.stdout.write("VISA")
        else:
            # Nenhuma bandeira correspondente encontrada
            sys.stdout.write("NÚMERO VÁLIDO PORÉM A BANDEIRA NÃO FOI LOCALIZADA NA BASE CADASTRAL")
    else:
        # Cartão inválido (não passa no teste de soma)
        sys.stdout.write("NÚMERO INVÁLIDO")

main()