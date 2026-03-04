#ifndef NOTE2_H
#define NOTE2_H

#define MAX_NAME 50
#define MAX_ZODIAC 15
#define MAX_MASS 10

typedef struct {
    char name[MAX_NAME];
    char zodiac[MAX_ZODIAC];
    int date[3];
} ZNAK;

void input_znak(ZNAK *mass, int *count);
void sort_by_date(ZNAK *mass, int count);
void search_by_zodiac(ZNAK *mass, int count, char *zodiac);
void print_znak(const ZNAK *z);
int compare_dates(const ZNAK *a, const ZNAK *b);

#endif
