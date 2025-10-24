#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CITIES 30
#define MAX_VEHICLES 3
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0

void addCities(int maxCities, char cityNames[][30], int *cityCount);

int main()
{
    char cityNames[MAX_CITIES][30];
    int cityCount=0;
    int distance[MAX_CITIES][MAX_CITIES] = {0};

    int choice;
    do{
        printf("\n-----LOGISTICS MANAGEMENT SYSTEM-----\n");
        printf("1.Add new city\n");
        printf("10.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
           addCities(MAX_CITIES,cityNames,&cityCount);
           break;
        case 10:
            printf("Exit\n");
            break;
        default:
            printf("invalid choice!\n");
        }
        }while(choice!=10);
 return 0;
}
void addCities(int maxCities, char cityNames[][30], int *cityCount) {

    char newCity[30];
    int i = 0;

    if (*cityCount >= maxCities) {
        printf("\nCannot add more cities. Maximum limit reached.\n");
        return;
    }
    printf("\nEnter city name: ");
    scanf(" %[^\n]", newCity);


    while (newCity[i] != '\0') {
        cityNames[*cityCount][i] = newCity[i];
        i++;
    }
    cityNames[*cityCount][i] = '\0';
    (*cityCount)++;
    printf("City added successfully!\n");
}
