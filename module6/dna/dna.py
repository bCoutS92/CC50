import sys
import csv

#Open the sequence, store in a variable and close the file
with open(sys.argv[2], "r") as sequence:
    dnasqc = sequence.read()

def main():
    #Create a dictionary and a list
    STRs = {}
    final = []

    #Print a error message if the user give less than 3 arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    #Open the database
    data =  open(sys.argv[1], "r")
    datareader = csv.reader(data)

    #Store the first row of database
    frow = next(datareader)

    #Store the STRs in the dictionary
    for i in range(len(frow)-1):
        STRs[frow[i+1]] = 0

    #Change the value of the STR based in the longest sequence of the same STR
    for dna in STRs:
        for j in range(len(dnasqc) - (len(dna) - 1)):
            temp = count_consecutives(dna, j)
            if STRs[dna] < temp:
                STRs[dna] = temp

        #Put the final values in a list
        final.append(STRs[dna])

    for row in datareader:
        matchs = 0
        for i in range(len(final)):
            if final[i] == int(row[i+1]):
                matchs += 1
        #Check if all numbers of database match
        if matchs == len(final):
            print(row[0])
            data.close()
            sys.exit(0)

    #If don't find the person, print no match
    print("No match")

    data.close()

def count_consecutives(STR, starts):
    times = 0
    if dnasqc[starts:(starts+len(STR))] == STR:
        if starts+len(STR) <= len(dnasqc):
            times = count_consecutives(STR, starts+len(STR)) + 1
        else:
            times = 1

    return times

main()