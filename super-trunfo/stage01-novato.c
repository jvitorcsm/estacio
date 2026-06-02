#include <stdio.h>
#include <string.h>

// Try in english for practive    
// Just curious, this game is related to Brazil at this stage.

// Promise
int welcome(void);
struct Card makeCard(void);
void displayCard(struct Card c);

  // We need to add a Mold Card to this object;
struct Card {
  char state[21];
  char code[5]; // State abbreviation + card number. Ex: SC01
  char cityName[33];
  float population;
  float areaKm2; 
  float gdp; // Portuguese PIB -> English GDP Gross-Domestic-Product
  int touristAttractionsCount;
};

// When we declare it this way, we have two structs with the same structure (fields), but each variable has its own value
int main() {
  
  int play = welcome();

  if (play == 1) {
    //Loading
    printf("Starting the game...\n");

    // Continue creating the cards 
    printf("\n--- Registering Card 01 ---\n");   
    struct Card card01 = makeCard();  
    printf("\n--- Registering Card 02 ---\n");
    struct Card card02 = makeCard();

    //Show cards
    printf("\n--- Card 01 ---\n");   
    displayCard(card01);
    printf("\n--- Card 02 ---\n");   
    displayCard(card02);

  } else {
    printf("Exiting... See you next time! :P\n");
    
    // Return 0, equal the kill program
    return 0;
  };

  return 0;
};

// Function welcome(void), because dont have consequence
int welcome(void) {
  
  char userChoice;
 
  printf("Hello, Welcome to the *Super Trunfo!*\n"
        "In this game, you need to create your cards to battle against other players.\n"
        "You can create up to 4 cards. These cards represent 4 cities organized by states.\n"
        "At the end of the game, the player with the highest score wins.\n"
        "In case of a tie, we analyze which card is closer to reality\n");
 
  putchar('\n');
 
  printf("Do you want continue? - Y(yes), or N(no)\n>> ");
  scanf("%c", &userChoice); // Add value in userChoice
   
  if (userChoice == 'Y' || userChoice == 'y') {
    return 1; // 1 is true
  } else if (userChoice == 'N' || userChoice == 'n') {
    return 0; // 0 is false
  } else {
    return 0;
  };

};

// Function makeCard, I dont want repeat printf and scanf for card02 and 02, so I do this function
// I will make function makeCard that, when finish, send a package complete in the format mold struct Card
struct Card makeCard(void) {
  
  struct Card newCard; //I need create temporary mold for send later
 
  printf("Enter State: ");
    scanf("%s", newCard.state);
  
  printf("Enter City Name: ");
    scanf("%s", newCard.cityName);

  printf("Enter City's Population: ");
    scanf(" %f", &newCard.population);
  
  printf("Enter the Area in Square Kilometers: ");
    scanf(" %f", &newCard.areaKm2);

  printf("Enter the Gross-Domestic-Product (GDP): ");
    scanf(" %f", &newCard.gdp);

  printf("Enter How Many Tourist Attractions Exist in this City: ");
    scanf(" %i", &newCard.touristAttractionsCount);

  return newCard;
};

// Visualization Card
void displayCard(struct Card c) {
  printf("State: %s\n", c.state);
  printf("City: %s\n", c.cityName);
  printf("Population: %f\n", c.population);
  printf("Area in Square Kilometers: %f\n", c.areaKm2);
  printf("Gross-Domestic-Product (GDP) %f\n", c.gdp);
  printf("Tourist Attractions %d\n", c.touristAttractionsCount);
};
