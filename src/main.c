#include <stdio.h>
#include <string.h>
#include "note2.h"

int main() {
    printf("\n=== Лабораторная работа №2 ===\n");
    printf("Структура NOTE2\n\n");
    
    NOTE2 block[7];
    getchar();
    
    input_notes(block, 7);
    
    sort_by_phone(block, 7);
    
    printf("\n=== Отсортированные записи ===\n");
    for (int i = 0; i < 7; i++) {
        printf("%d. %s - %s (%04d-%02d-%02d)\n", 
               i + 1, block[i].name, block[i].tele,
               block[i].date[0], block[i].date[1], block[i].date[2]);
    }
    
    char search_surname[50];
    printf("\nВведите фамилию для поиска: ");
    fgets(search_surname, sizeof(search_surname), stdin);
    search_surname[strcspn(search_surname, "\n")] = 0;
    
    search_by_surname(block, 7, search_surname);
    
    return 0;
}
