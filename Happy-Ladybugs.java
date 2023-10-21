import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'happyLadybugs' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING b as parameter.
     */
public static String happyLadybugs(String b) {
       //List<Integer> x = new ArrayList<Integer>(26);
       List<Integer> x = new ArrayList<>(26);
        for (int i = 0; i < 26; i++) {
            x.add(0);
        }

        boolean sp = false;
        int count = 0;
        char d = '!';

        for (char c : b.toCharArray()) {
            if (c == '_') {
                sp = true;
                continue;
            }

            int index = c - 'A';
            x.set(index, x.get(index) + 1);

            if (x.get(index) == 1) {
                count++;
            }

            if (d != c) {
                count--;
            }

            d = c;
        }

        if (!sp && count != 0) {
            return "NO";
        }

        for (int i : x) {
            if (i == 1) {
                return "NO";
            }
        }

        return "YES";
    }

     
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int g = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, g).forEach(gItr -> {
            try {
                int n = Integer.parseInt(bufferedReader.readLine().trim());

                String b = bufferedReader.readLine();

                String result = Result.happyLadybugs(b);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
