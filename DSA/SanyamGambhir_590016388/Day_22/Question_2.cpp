#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cardGame(vector<int>& cards) {
    int left = 0;
    int right = cards.size() - 1;
    
    int player1Score = 0;
    int player2Score = 0;
    bool isPlayer1Turn = true; // True for Player 1, False for Player 2
    
    while (left <= right) {
        int pickedCard = 0;
        
        // Pick the larger card from either end
        if (cards[left] > cards[right]) {
            pickedCard = cards[left];
            left++;
        } else {
            // If they are equal, picking either is fine. We default to right.
            pickedCard = cards[right];
            right--;
        }
        
        // Add the picked card to the correct player's score
        if (isPlayer1Turn) {
            player1Score += pickedCard;
        } else {
            player2Score += pickedCard;
        }
        
        // Switch turns
        isPlayer1Turn = !isPlayer1Turn;
    }
    
    // Output the final scores as requested by the format
    cout << player1Score << " " << player2Score << endl;
}

int main() {
    // Example test case
    vector<int> cards = {4, 1, 2, 10};
    
    // Should output: 12 5
    cardGame(cards);
    
    return 0;
}