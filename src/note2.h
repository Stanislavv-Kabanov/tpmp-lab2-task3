#ifndef NOTE2_H
#define NOTE2_H

typedef struct {
    char name[100];       
    char tele[15];        
    int date[3];          
} NOTE2;

void input_notes(NOTE2 block[], int size);
void sort_by_phone(NOTE2 block[], int size);
void search_by_surname(NOTE2 block[], int size, char surname[]);

#endif
