public class Question1_Leetcode {
    public int compress(char[] chars) {
       int i=0; // Read pointer
       int j=0; // Write pointer
    
    while( i < chars.length ){
        char c = chars [i]; // Store the current character
        int count=0;        // Count the frequency of the current character

        // Count consecutive occurrences of the current character
        while( i < chars.length && chars[i] == c){
            count++;
            i++;
        }
        // Write the character and increment the write pointer 
        chars[j++] = c;

        // If frequency > 1, write the digits  
        if( count > 1){
            String str = String.valueOf(count); // Convert frequency to a string 
            for( char ch : str.toCharArray()){
                chars[j++]=ch; // Write each digit of the frequency into the compressed array
            }
        }
    }
    return j; // Return length of compressed string   
    }
}