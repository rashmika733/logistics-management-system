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
void showDistanceTable(int distance[][MAX_CITIES], int cityCount, char cityNames[][30]);
void showVehicles(char vehicleNames[][20], int capacities[], float rates[],float speeds[], float efficiencies[], int vehicleCount);
int main()
{
    char cityNames[MAX_CITIES][30];
    int cityCount=0;
    int distance[MAX_CITIES][MAX_CITIES] = {0};

    char vehicleNames[3][20] = {"Van","Truck","Lorry"};
    int capacities[3] = {1000, 5000, 10000};
    float rates[3] = {30.0, 40.0, 80.0};
    float speeds[3] = {60.0, 50.0, 45.0};
    float efficiencies[3] = {12.0, 6.0, 4.0};
    int vehicleCount = 3;

    int choice;
    do{
        printf("\n-----LOGISTICS MANAGEMENT SYSTEM-----\n");
        printf("1.Add new city\n");
        printf("2. Rename a city\n");
        printf("3. Remove a city\n");
        printf("4. Display all cities\n");
        printf("5. Enter distance between cities\n");
        printf("6. Show distance table\n");
        printf("7. Show vehicles\n");
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
        case 6:
            showDistanceTable(distance, cityCount, cityNames);
            break;
        case 7:
            showVehicles(vehicleNames,capacities,rates,speeds,efficiencies,vehicleCount);
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
void showDistanceTable(int distance[][MAX_CITIES], int cityCount, char cityNames[][30]) {
    if (cityCount == 0) {
        printf("\nNo cities available.\n");
        return;
    }

    printf("\n--- Distance Table (km) ---\n      ");
    for (int i = 0; i < cityCount; i++) {
        printf("%-10s", cityNames[i]);
    }
    printf("\n");

    for (int i = 0; i < cityCount; i++) {
        printf("%-6s", cityNames[i]);
        for (int j = 0; j < cityCount; j++) {
            printf("%-10d", distance[i][j]);
        }
        printf("\n");
    }
}

void showVehicles(char vehicleNames[][20], int capacities[], float rates[],float speeds[], float efficiencies[], int vehicleCount) {
    int i;
    if (vehicleCount == 0) {
        printf("\nNo vehicles available.\n");
        return;
    }
    printf("\n--- Vehicle List ---\n");
    printf("No   Type        Capacity(kg)  Rate/km(LKR)  Speed(km/h)  Efficiency(km/l)\n");
    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < vehicleCount; i++) {
        printf("%-4d %-12s %-12d %-14.2f %-12.2f %.2f\n",
               i + 1, vehicleNames[i], capacities[i], rates[i], speeds[i], efficiencies[i]);
    }
}

