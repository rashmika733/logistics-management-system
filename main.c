#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CITIES 30
#define MAX_VEHICLES 3
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0

void addCities(int maxCities, char cityNames[][30], int *cityCount);
void renameCity(char cityNames[][30], int cityCount);
void removeCity(char cityNames[][30], int *cityCount);
void inputDistance(int distance[][MAX_CITIES], int cityCount, char cityNames[][30]);

int main()
{
    char cityNames[MAX_CITIES][30];
    int cityCount=0;
    int distance[MAX_CITIES][MAX_CITIES] = {0};

    int choice;
    do{
        printf("\n-----LOGISTICS MANAGEMENT SYSTEM-----\n");
        printf("1.Add new city\n");
        printf("2. Rename a city\n");
        printf("3. Remove a city\n");
        printf("4. Display all cities\n");
        printf("5. Enter distance between cities\n");
        printf("10.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

 switch(choice){
        case 1:
           addCities(MAX_CITIES,cityNames,&cityCount);
           break;
        case 2:
            renameCity(cityNames, cityCount);
            break;
        case 3:
            removeCity(cityNames, &cityCount);
            break;
        case 4:
            if (cityCount == 0)
                printf("No cities added yet.\n");
            else {
            printf("\nList of Cities:\n");
            for (int i = 0; i < cityCount; i++) {
            printf("%d. %s\n", i + 1, cityNames[i]);
            }
        }
        break;
        case 5:
            inputDistance(distance, cityCount, cityNames);
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
void renameCity(char cityNames[][30], int cityCount) {
    int index;
    char newName[30];
    int i = 0;

    if (cityCount == 0) {
        printf("\n No cities available to rename.\n");
        return;
    }
    printf("\n---- City List ----\n");
    for (int i = 0; i < cityCount; i++) {
        printf("%d. %s\n", i + 1, cityNames[i]);
    }

    printf("Enter the city number to rename: ");
    scanf("%d", &index);

    if (index < 1 || index > cityCount) {
        printf("Invalid city number!\n");
        return;
    }
    printf("Enter new name: ");
    scanf(" %[^\n]", newName);

    while (newName[i] != '\0') {
        cityNames[index - 1][i] = newName[i];
        i++;
    }
    cityNames[index - 1][i] = '\0';

    printf("City renamed successfully!\n");
}
void removeCity(char cityNames[][30], int *cityCount) {
    int index;

    if (*cityCount == 0) {
        printf("\nNo cities available to remove.\n");
        return;
    }

    printf("\n--- City List ---\n");
    for (int i = 0; i < *cityCount; i++) {
        printf("%d. %s\n", i + 1, cityNames[i]);
    }

    printf("Enter the city number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > *cityCount) {
        printf("Invalid city number!\n");
        return;
    }
    for (int i = index - 1; i < *cityCount - 1; i++) {
        int j = 0;
        while (cityNames[i + 1][j] != '\0') {
            cityNames[i][j] = cityNames[i + 1][j];
            j++;
        }
        cityNames[i][j] = '\0';
    }
    (*cityCount)--;
    printf("City removed successfully!\n");
}
void inputDistance(int distance[][MAX_CITIES], int cityCount, char cityNames[][30]) {
    int city1, city2, dist;

    if (cityCount < 2) {
        printf("\nAt least two cities are needed to enter distances.\n");
        return;
    }
    printf("\n--- City List ---\n");
    for (int i = 0; i < cityCount; i++) {
        printf("%d. %s\n", i + 1, cityNames[i]);
    }
    printf("\nEnter source city number: ");
    scanf("%d", &city1);
    printf("Enter destination city number: ");
    scanf("%d", &city2);

    if (city1 < 1 || city2 < 1 || city1 > cityCount || city2 > cityCount) {
        printf("Invalid city numbers!\n");
        return;
    }
    if (city1 == city2) {
        printf("Distance from a city to itself is always 0.\n");
        return;
    }
    printf("Enter distance between %s and %s (in km): ", cityNames[city1 - 1], cityNames[city2 - 1]);
    scanf("%d", &dist);

    if (dist < 0) {
        printf("Distance cannot be negative!\n");
        return;
    }
    distance[city1 - 1][city2 - 1] = dist;
    distance[city2 - 1][city1 - 1] = dist;

    printf("Distance saved successfully!\n");
}

