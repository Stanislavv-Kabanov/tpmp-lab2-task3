
#include <stdio.h>
#include <string.h>
#include "note2.h"

int main() {
    ZNAK mass[MAX_MASS];
    int count = 0;
    char search_zodiac[MAX_ZODIAC];
    
    printf("=== Программа для работы со структурой ZNAK ===\n");
    
    input_znak(mass, &count);
    
    if (count == 0) {
        printf("Нет введенных данных.\n");
        return 0;
    }
    
    sort_by_date(mass, count);
    
    printf("\nЗаписи, упорядоченные по дате рождения:\n");
    for (int i = 0; i < count; i++) {
        print_znak(&mass[i]);
    }
    
    printf("\nВведите знак зодиака для поиска: ");
    fgets(search_zodiac, MAX_ZODIAC, stdin);
    search_zodiac[strcspn(search_zodiac, "\n")] = 0;
    
    search_by_zodiac(mass, count, search_zodiac);
    
    return 0;
}
