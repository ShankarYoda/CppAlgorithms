public class stringsearch {
    public static boolean stringsearch(String s,char key){
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==key){
                return true;
            }

        }
        return false;
    }
    public static void main(String[] args) {
        String s= "shalu";
        char key='a';
        System.out.println(stringsearch(s,key));
    }
}
