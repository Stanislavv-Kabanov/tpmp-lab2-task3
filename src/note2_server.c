#include <stdio.h>
#include <string.h>
#include "note2.h"

void input_znak(ZNAK *mass, int *count) {
    printf("Введите информацию о людях (для завершения введите пустую фамилию):\n");
    
    while (*count < MAX_MASS) {
        printf("\nЗапись %d:\n", *count + 1);
        
        printf("Фамилия и имя: ");
        fgets(mass[*count].name, MAX_NAME, stdin);
        mass[*count].name[strcspn(mass[*count].name, "\n")] = 0;
        
        if (strlen(mass[*count].name) == 0) {
            break;
        }
        
        printf("Знак зодиака: ");
        fgets(mass[*count].zodiac, MAX_ZODIAC, stdin);
        mass[*count].zodiac[strcspn(mass[*count].zodiac, "\n")] = 0;
        
        printf("Дата рождения (год месяц число): ");
        scanf("%d %d %d", &mass[*count].date[0], &mass[*count].date[1], &mass[*count].date[2]);
        getchar();
        
        (*count)++;
    }
}

int compare_dates(const ZNAK *a, const ZNAK *b) {
    if (a->date[0] != b->date[0]) return a->date[0] - b->date[0];
    if (a->date[1] != b->date[1]) return a->date[1] - b->date[1];
    return a->date[2] - b->date[2];
}

void sort_by_date(ZNAK *mass, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare_dates(&mass[j], &mass[j + 1]) > 0) {
                ZNAK temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
}

void print_znak(const ZNAK *z) {
    printf("%s | %s | %04d.%02d.%02d\n", 
           z->name, 
           z->zodiac,
           z->date[0], 
           z->date[1], 
           z->date[2]);
}

void search_by_zodiac(ZNAK *mass, int count, char *zodiac) {
    int found = 0;
    
    printf("\nЛюди, родившиеся под знаком %s:\n", zodiac);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(mass[i].zodiac, zodiac) == 0) {
            print_znak(&mass[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Людей, родившихся под знаком %s, не найдено.\n", zodiac);
    }
}
