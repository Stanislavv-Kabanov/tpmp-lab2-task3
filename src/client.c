#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void task1_demo() {
    printf("\n========== ЗАДАНИЕ 1 ==========\n");
    printf("Сортировка массива по сумме цифр\n");
    
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    
    printf("Введите %d натуральных чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nИсходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d (сумма цифр: %d)  ", arr[i], sum_of_digits(arr[i]));
    }
    
    sort_by_digit_sum(arr, n);
    
    printf("\nОтсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d (сумма цифр: %d)  ", arr[i], sum_of_digits(arr[i]));
    }
    printf("\n");
    
    free(arr);
}

void task2_demo() {
    printf("\n========== ЗАДАНИЕ 2 ==========\n");
    printf("Работа со структурой ZNAK\n");
    
    ZNAK mass[10];
    getchar();
    
    input_znak(mass, 10);
    
    sort_by_birthday(mass, 10);
    
    printf("\n=== Отсортированные записи ===\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - %s (%02d.%02d.%04d)\n", 
               i + 1, mass[i].surname_name, mass[i].zodiac,
               mass[i].date[0], mass[i].date[1], mass[i].date[2]);
    }
    
    char search_zodiac[20];
    printf("\nВведите знак зодиака для поиска: ");
    fgets(search_zodiac, sizeof(search_zodiac), stdin);
    search_zodiac[strcspn(search_zodiac, "\n")] = 0;
    
    search_by_zodiac(mass, 10, search_zodiac);
}

void task3_demo() {
    printf("\n========== ЗАДАНИЕ 3 ==========\n");
    printf("Владельцы автомобилей\n");
    
    CarOwner owners[2];
    getchar();
    
    input_multiple_owners(owners, 2);
    
    search_by_car_brand(owners, 2, "Ваз");
}

void run_program() {
    int choice;
    
    do {
        printf("\n====================================\n");
        printf("         ГЛАВНОЕ МЕНЮ\n");
        printf("====================================\n");
        printf("1. Задание 1 - Сумма цифр и сортировка\n");
        printf("2. Задание 2 - Знаки зодиака\n");
        printf("3. Задание 3 - Владельцы автомобилей\n");
        printf("4. Выполнить все задания\n");
        printf("0. Выход\n");
        printf("====================================\n");
        printf("Выберите пункт: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                task1_demo();
                break;
            case 2:
                task2_demo();
                break;
            case 3:
                task3_demo();
                break;
            case 4:
                task1_demo();
                task2_demo();
                task3_demo();
                break;
            case 0:
                printf("Программа завершена.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while(choice != 0);
}

int main() {
    printf("\n=== Лабораторная работа №2 ===\n");
    printf("Вариант: Владелец автомобиля\n\n");
    
    run_program();
    
    return 0;
}
