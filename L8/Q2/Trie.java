import java.util.*;
import java.io.*; 
public class Trie { 
    static final int ALPHA_SIZE = 26; 
    static int count=0;
    static HashMap<String, Integer> map=new HashMap<>();
    static class TrieNode { 
        TrieNode[] children = new TrieNode[ALPHA_SIZE]; 
        boolean isEndOfWord; 
        TrieNode(){ 
            isEndOfWord = false; 
            for (int i = 0; i < ALPHA_SIZE; i++) 
                children[i] = null; 
        } 
    }; 
    static TrieNode root;  
    static void insertion(String key) { 
        int level; 
        int length = key.length(); 
        int index; 
        TrieNode pCrawl = root; 
        for (level = 0; level < length; level++) { 
            index = key.charAt(level) - 'a'; 
            if (pCrawl.children[index] == null) 
                pCrawl.children[index] = new TrieNode(); 
            pCrawl = pCrawl.children[index]; 
        } 
        pCrawl.isEndOfWord = true; 
    } 
    
    public String swap(String a, int i, int j) { 
        char temp; 
        char[] charArray = a.toCharArray(); 
        temp = charArray[i] ; 
        charArray[i] = charArray[j]; 
        charArray[j] = temp; 
        return String.valueOf(charArray); 
    } 
    private void permutation(String str, int l, int r) { 
        if (l == r){
                if(search(str)==true){
                    if(!map.containsKey(str)){
                    map.put(str, 0);
                    System.out.println(str);
                    count++;
                    }
                }
            } 
        else{ 
            for (int i = l; i <= r; i++) { 
                str = swap(str,l,i); 
                permutation(str, l+1, r); 
                str = swap(str,l,i); 
            } 
        } 
    } 
    static boolean search(String key) { 
        int level; 
        int length = key.length(); 
        int index; 
        TrieNode pCrawl = root; 
        for (level = 0; level < length; level++) { 
            index = key.charAt(level) - 'a'; 
            if (pCrawl.children[index] == null) 
                return false; 
            pCrawl = pCrawl.children[index]; 
        } 
       
        return (pCrawl != null && pCrawl.isEndOfWord); 
    } 
   public String rectify(String s){
       String s1="";
       int n=s.length();
        for(int i=0;i<n;i++){
            if((int)s.charAt(i)>=97&&(int)s.charAt(i)<=122)
            s1=s1+s.charAt(i);
            else if((int)s.charAt(i)>=65&&(int)s.charAt(i)<=90){
                s1+=(char)((int)s.charAt(i)+32);
            }
        }
       return s1;
   }
    public static void main(String args[]) throws Exception { 
        System.out.println("Enter Word:");
        Trie t=new Trie();
        root = new TrieNode(); 
        File file = new File("words"); 
        BufferedReader br = new BufferedReader(new FileReader(file)); 
        String keys; 
        while ((keys = br.readLine()) != null) {
           keys= t.rectify(keys);
            insertion(keys); 
        }
        br.close();
        int i; 
       Scanner in =new Scanner(System.in);
       String input;
       input=in.nextLine();
       in.close();
       int n=input.length();
       int j,k,l;
       int ctr[]=new int[n];
       String inputCheck[][]=new String[n][1000];
        for(i=0;i<n;i++){
            for(j=n-2;j>=0;j--){
                for(k=0;k<ctr[j];k++){
                inputCheck[j+1][ctr[j+1]]=inputCheck[j][k]+input.charAt(i);
                ctr[j+1]++;
              }
            }
            inputCheck[j+1][ctr[j+1]]=""+input.charAt(i);
            ctr[j+1]++;
        }
        for(i=3;i<n;i++){
            System.out.println(i+1+":");
            count=0;  
            for(j=0;j<ctr[i];j++){
            t.permutation(inputCheck[i][j], 0, i);
             }
            System.out.println("\nCount-->"+(i+1)+"="+count+"\n");
        }       
    } 
} 
