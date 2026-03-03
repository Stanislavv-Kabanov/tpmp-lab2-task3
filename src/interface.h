#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct {
    char surname_name[100];
    char zodiac[20];
    int date[3];
} ZNAK;

typedef struct {
    char surname[50];
    char name[50];
    char patronymic[50];
    char phone[15];
    char postal_index[10];
    char country[50];
    char region[50];
    char district[50];
    char city[50];
    char street[50];
    char house[10];
    char apartment[10];
    char car_brand[50];
    char car_number[15];
    char tech_passport[20];
} CarOwner;

int sum_of_digits(int number);
void sort_by_digit_sum(int arr[], int n);
void input_znak(ZNAK mass[], int size);
void sort_by_birthday(ZNAK mass[], int size);
void search_by_zodiac(ZNAK mass[], int size, char zodiac[]);
void input_car_owner(CarOwner *owner);
void print_car_owner(CarOwner owner);
void input_multiple_owners(CarOwner owners[], int count);
void search_by_car_brand(CarOwner owners[], int count, char brand[]);
void run_program();

#endif
