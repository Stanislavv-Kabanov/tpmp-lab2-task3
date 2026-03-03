#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "note2.h"

void input_notes(NOTE2 block[], int size) {
    printf("\n=== Ввод информации о %d людях ===\n", size);
    
    for (int i = 0; i < size; i++) {
        printf("\n--- Человек %d ---\n", i + 1);
        
        printf("Введите фамилию и инициалы: ");
        fgets(block[i].name, sizeof(block[i].name), stdin);
        block[i].name[strcspn(block[i].name, "\n")] = 0;
        
        printf("Введите номер телефона: ");
        fgets(block[i].tele, sizeof(block[i].tele), stdin);
        block[i].tele[strcspn(block[i].tele, "\n")] = 0;
        
        printf("Введите дату рождения (год месяц число): ");
        scanf("%d %d %d", &block[i].date[0], &block[i].date[1], 
&block[i].date[2]);
        getchar();
    }
}

void sort_by_phone(NOTE2 block[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int first_three1 = atoi(block[j].tele);
            int first_three2 = atoi(block[j + 1].tele);
            
            if (first_three1 > first_three2) {
                NOTE2 temp = block[j];
                block[j] = block[j + 1];
                block[j + 1] = temp;
            }
        }
    }
    printf("\n[СЕРВЕР] Массив отсортирован по первым трем цифрам телефона\n");
}

void search_by_surname(NOTE2 block[], int size, char surname[]) {
    int found = 0;
    printf("\n=== Поиск человека с фамилией '%s' ===\n", surname);
    
    for (int i = 0; i < size; i++) {
        if (strstr(block[i].name, surname) != NULL) {
            printf("\nНайдено: Фамилия и инициалы: %s\n", block[i].name);
            printf("Номер телефона: %s\n", block[i].tele);
            printf("Дата рождения: %04d-%02d-%02d\n", 
                   block[i].date[0], block[i].date[1], block[i].date[2]);
            found++;
        }
    }
    
    if (found == 0) {
        printf("Человек с фамилией %s не найден\n", surname);
    } else {
        printf("\nНайдено %d человек(а)\n", found);
    }
}
