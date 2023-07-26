from cs50 import get_string

s = get_string("Você concorda?”)

if s == "Y" or s == "y":
print("Concordo")
elif s == "N" or s == "n" :
print("Não concordo.")