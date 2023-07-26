// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

personcreate_family(int generations);
void print_family(person p, int generation);
void free_family(personp);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *n = malloc(sizeof(person));
    if (n == NULL)
    {
        return NULL;
    }
    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents
        n->parents[0] = create_family(generations - 1);
        n->parents[1] = create_family(generations - 1);

        // TODO: Randomly assign child alleles based on parents
        n->alleles[0] = n->parents[0]->alleles[rand() % 2];
        n->alleles[1] = n->parents[1]->alleles[rand() % 2];
    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        n->parents[0] = NULL;
        n->parents[1] = NULL;
        // TODO: Randomly assign alleles
        n->alleles[0] = random_allele();
        n->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return n;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }
    // TODO: Free parents
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    // TODO: Free child
    free(p);
}