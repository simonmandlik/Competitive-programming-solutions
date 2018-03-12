import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Created by Sheemon on 1.12.
 */
public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        BigInteger a; int N;
        while (sc.hasNext()) {
            N = sc.nextInt();
            a = new BigInteger(String.valueOf(sc.nextInt()));
            BigInteger res = BigInteger.ZERO;
            for(int i = 1; i <= N; ++i) {
                res = res.add(a.pow(i).multiply(new BigInteger(String.valueOf(i))));
            }
            System.out.println(res);
        }
    }
}
