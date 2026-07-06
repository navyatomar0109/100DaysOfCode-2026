class Question2 {
    public static void main(String[] args) {
        int[] cards = {4, 1, 2, 10}; // Example test case
        
        int left = 0;
        int right = cards.length - 1;
        
        int p1Score = 0;
        int p2Score = 0;
        boolean isPlayer1Turn = true;
        
        while (left <= right) {
            int picked;
            
            if (cards[left] > cards[right]) {
                picked = cards[left];
                left++;
            } else {
                picked = cards[right];
                right--;
            }
            
            if (isPlayer1Turn) {
                p1Score += picked;
            } else {
                p2Score += picked;
            }
            
            isPlayer1Turn = !isPlayer1Turn;
        }
        
        System.out.println(p1Score + " " + p2Score);
    }
}
