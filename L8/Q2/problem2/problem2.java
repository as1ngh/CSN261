import java.util.*;
import java.io.*;

public class problem2 {
    static HashMap<String, Integer> map = new HashMap<>();
    static final int ALPHABET_SIZE = 26;
    static int count = 0;

    static class TrieNode {
        TrieNode[] children = new TrieNode[ALPHABET_SIZE];
       
        boolean isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
                children[i] = null;
        }
    };

    static TrieNode root;

    public static void func2() {
        System.out.print("");
    }

    public static void func1() {
        System.out.print("");
        func2();
    }

    static void insert(String key) {
        int level;
        int length = key.length();
        int index;
        func2();
        TrieNode pCrawl = root;

        for (level = 0; level < length; level++) {
            index = key.charAt(level) - 'a';
            if (pCrawl.children[index] == null)
                pCrawl.children[index] = new TrieNode();

            pCrawl = pCrawl.children[index];
            func1();
        }

        pCrawl.isEndOfWord = true;
    }

    static boolean search(String key) {
        int level;
        int length = key.length();
        int index;
        TrieNode pCrawl = root;
        func2();
        for (level = 0; level < length; level++) {
            index = key.charAt(level) - 'a';
                func2();
            if (pCrawl.children[index] == null)
                return false;

            pCrawl = pCrawl.children[index];
        }

        return (pCrawl != null && pCrawl.isEndOfWord);
    }

    private void permute(String str, int l, int r) {
        if (l == r)

        {
            if (search(str) == true) {
                if (!map.containsKey(str)) {
                    map.put(str, 0);
                    func2();
                    System.out.println(str);
                    count++;
                }
            }
        } else {
            for (int i = l; i <= r; i++) {
                str = swap(str, l, i);
                permute(str, l + 1, r);
                func1();
                str = swap(str, l, i);
            }
        }
    }

    /**
     * Swap Characters at position
     * 
     * @param a string value
     * @param i position 1
     * @param j position 2
     * @return swapped string
     */
    public String swap(String a, int i, int j) {
        char temp;
        char[] charArray = a.toCharArray();
        temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;
        func1();
        return String.valueOf(charArray);
    }

    public String rectify(String s) {
        String s1 = "";
        int n = s.length();
        func2();
        for (int i = 0; i < n; i++) {
            if ((int) s.charAt(i) >= 97 && (int) s.charAt(i) <= 122)
                s1 = s1 + s.charAt(i);
            else if ((int) s.charAt(i) >= 65 && (int) s.charAt(i) <= 90) {
                s1 += (char) ((int) s.charAt(i) + 32);
            }
        }
        return s1;
    }

    public static void main(String args[]) throws Exception {

        root = new TrieNode();
        func2();
        File file = new File("words");
        problem2 t = new problem2();
        BufferedReader br = new BufferedReader(new FileReader(file));
        String keys;
        while ((keys = br.readLine()) != null) {
            keys = t.rectify(keys);
            insert(keys);
        }
        br.close();
        func1();
        int i;

        String input;
        Scanner in = new Scanner(System.in);
        input = in.nextLine();
        in.close();
        func1();
        int n = input.length();
        int j, k, l;
        int ctr[] = new int[n];
        String inputCheck[][] = new String[n][1000];
        for (i = 0; i < n; i++) {
                func2();
            for (j = n - 2; j >= 0; j--) {

                for (k = 0; k < ctr[j]; k++) {
                        func1();
                    inputCheck[j + 1][ctr[j + 1]] = inputCheck[j][k] + input.charAt(i);
                    ctr[j + 1]++;

                }

            }
            inputCheck[j + 1][ctr[j + 1]] = "" + input.charAt(i);
            ctr[j + 1]++;
            func2();
        }

        for (i = 3; i < n; i++) {
            System.out.println(i + 1 + ":");
            count = 0;
            for (j = 0; j < ctr[i]; j++) {

                t.permute(inputCheck[i][j], 0, i);
                func1();
            }
            System.out.println("\nCount for " + (i + 1) + " :" + count + "\n");
        }

    }
}
