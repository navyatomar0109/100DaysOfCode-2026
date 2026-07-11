public class Question1 {

    public static int compress(char[] chars){

        int index=0;
        int i=0;

        while(i<chars.length){

            char ch=chars[i];
            int count=0;

            while(i<chars.length && chars[i]==ch){
                i++;
                count++;
            }

            chars[index++]=ch;

            if(count>1){

                String s=String.valueOf(count);

                for(int j=0;j<s.length();j++){
                    chars[index++]=s.charAt(j);
                }
            }
        }

        return index;
    }

    public static void main(String[] args){

        char[] chars={'a','a','b','b','c','c','c'};

        System.out.println(compress(chars));
    }
}