class Solution{
public:
    vector<int> cardGameStratergy(vector<int>& cards){
        int left=0;
        int right=cards.size()-1;
        int player1=0;
        int player2=0;
        int turn=1;
        while(left<=right){
            int pick;
            if(cards[left]>cards[right]){
                pick=cards[left];
                left++;
            } else {
                pick=cards[right];
                right--;
            }
            if(turn){
                player1+=pick;
            } else {
                player2+=pick;
            }
            turn=1-turn;
        }
        return {player1, player2};
    }
};