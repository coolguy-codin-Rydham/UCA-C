#include <stdio.h>


typedef struct  cards
{  
    int card;
} card;

 


int main(){
    char *decks[] = {"1: Spade", "2: Clubs", "3: Diamonds", "4: Hearts"};
    int cardNumber;
    int cardDeck;
    for(int i=0;i<=3;i++){
        printf("%s ", decks[i]);
    }

    printf("\n");
    printf("Enter Card Deck Number: ");
    scanf("%d", &cardDeck);

    printf("Enter Card Number consider Ace as 1, King as 13, Queen as 12, Jack as 11 ");
    
    scanf("%d", &cardNumber);

    printf("\n");


    printf("%d\n", cardNumber);
    printf("%d", cardDeck);


    int cardDepiction = 0;


    cardDepiction = cardDepiction^cardNumber;

    // printf("%d", cardDepiction);

    cardDeck = cardDeck<<6;
    printf("%d", cardDeck);

    cardDepiction = cardDepiction ^ cardDeck;


    printf("%d", cardDepiction);

    

    return 0;
}


