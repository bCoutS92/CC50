from cs50 import get_string

people = {
"Brian": "+1-617-495-1000",
"David": "+1-949-468-2750"
}

name = get_string("Nome: ")
if name in people:
print(f"Numero: {people[name]}")

