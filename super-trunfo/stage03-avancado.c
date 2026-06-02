#include <stdio.h>
#include <string.h>

// Try in english for practive    
// Just curious, this game is related to Brazil at this stage.

// Promise
int welcome(void);
struct Card makeCard(void);
void displayCard(
  struct Card c
);
void compareGDPPerCapita(
  struct Card card1, 
  struct Card card2
);
void compareAttribute(
  char attributeName[],
  double value1,
  double value2,
  char city1[],
  char city2[]
);
void compareDensity(
  struct Card card1,
  struct Card card2
);

// We need to add a Mold Card to this object;
struct Card {
  char state[21];
  char code[5]; // State abbreviation + card number. Ex: SC01
  char cityName[33];
  
  unsigned long population;
  float areaKm2; 
  double gdp; // Portuguese PIB -> English GDP Gross-Domestic-Product
  int touristAttractionsCount;
  
  double populationDensity;
  double gdpPerCapita;

  double superPower;
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

    compareAttribute(
      "Population",
      card01.population,
      card02.population,
      card01.cityName,
      card02.cityName
    );

    compareAttribute(
      "Area",
      card01.areaKm2,
      card02.areaKm2,
      card01.cityName,
      card02.cityName
    );

    compareAttribute(
      "GDP",
      card01.gdp,
      card02.gdp,
      card01.cityName,
      card02.cityName
    );

    compareAttribute(
      "Tourist Attractions",
      card01.touristAttractionsCount,
      card02.touristAttractionsCount,
      card01.cityName,
      card02.cityName
    );

    compareAttribute(
      "GDP Per Capita",
      card01.gdpPerCapita,
      card02.gdpPerCapita,
      card01.cityName,
      card02.cityName
    );

    compareDensity(
      card01,
      card02
    );

    compareAttribute(
      "Super Power",
      card01.superPower,
      card02.superPower,
      card01.cityName,
      card02.cityName
    );
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
    scanf(" %lu", &newCard.population);
  
  printf("Enter the Area in Square Kilometers: ");
    scanf(" %f", &newCard.areaKm2);

  printf("Enter the Gross-Domestic-Product (GDP): ");
    scanf(" %lf", &newCard.gdp);

  printf("Enter How Many Tourist Attractions Exist in this City: ");
    scanf(" %i", &newCard.touristAttractionsCount);

  newCard.populationDensity =
    (newCard.population/newCard.areaKm2);

  newCard.gdpPerCapita =
    (newCard.gdp/newCard.population);

  newCard.superPower =
    newCard.population +
    newCard.areaKm2 +
    newCard.gdp +
    newCard.touristAttractionsCount +
    newCard.gdpPerCapita +
    (1.0 / newCard.populationDensity); // add 1/ because if i sum density upper is this advantage, for this i use 1/density

  return newCard;
};

// Visualization Card
void displayCard(struct Card c) {
  printf("State: %s\n", c.state);
  printf("City: %s\n", c.cityName);
  printf("Population: %lu\n", c.population);
  printf("Area in Square Kilometers: %f\n", c.areaKm2);
  printf("Gross-Domestic-Product (GDP) %.2lf\n", c.gdp);
  printf("Tourist Attractions %d\n", c.touristAttractionsCount);
  printf("Density Population: %f\n", c.populationDensity);
  printf("PIB Per Capita: %f\n", c.gdpPerCapita);
};

void compareAttribute(
  char attributeName[],
  double value1,
  double value2,
  char city1[],
  char city2[]
)
{
  printf("\n=== %s ===\n", attributeName);

  printf("%s: %.2lf\n", city1, value1);
  printf("%s: %.2lf\n", city2, value2);

  if(value1 > value2){
    printf("Winner: %s\n", city1);
  } else if(value2 > value1) {
    printf("Winner: %s\n", city2);
  } else {
    printf("Tie!\n");
  }
};

void compareDensity(
  struct Card card1,
  struct Card card2
)
{
  printf("\n=== Population Density ===\n");

  printf("%s: %.2f\n",
    card1.cityName,
    card1.populationDensity);

  printf("%s: %.2f\n",
    card2.cityName,
    card2.populationDensity);

  if(card1.populationDensity < card2.populationDensity) {
    printf("Winner: %s\n", card1.cityName);
  } else if(card2.populationDensity < card1.populationDensity) {
    printf("Winner: %s\n", card2.cityName);
  } else {
    printf("Tie!\n");
  }
};


