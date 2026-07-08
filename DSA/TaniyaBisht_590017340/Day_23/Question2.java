
class Back{
    public static String process(String str){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++){
            char ch = str.charAt(i);
            if(ch =='#'){
                if(sb.length() > 0){
                    sb.deleteCharAt(sb.length() - 1);
                }
            } 
            else{
                sb.append(ch);
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        String s = "ab#d#c";
        String t = "ad#e#c";
        String s1 = process(s);
        String t1 = process(t);
        System.out.println(s1.equals(t1));
    }
}