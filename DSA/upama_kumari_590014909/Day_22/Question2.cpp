#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int>cards = {4,1,2,10};

    int left = 0;
    int right = cards.size() - 1;

    int player1 = 0;
    int player2 = 0;
    
    bool turn = true;
    while(left<=right){

        int picked = 0;

        if(cards[left] > cards[right]){
            picked = picked + cards[left];
            left++;
        }else{
            picked = picked + cards[right];
            right--;
        }

        if(turn){
            player1 = player1 + picked;
        }else{
            player2 = player2 + picked;
        }

        turn =!turn;

        
    }

    cout<<"Player 1 score : "<<player1<<endl;
    cout<<"Player 2 score : "<<player2<<endl;

        return 0;
}