import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by Sheemon on 28.10.
 */
public class Main {
    static int maxN = 205;
    static BigInteger[] fib;

    static Scanner sc = new Scanner(System.in);

    static void fill() {
        fib[0] = fib[1] = new BigInteger("1");
        for (int i = 2; i < maxN; i++) {
            fib[i] = fib[i - 2].add(fib[i - 1]);
        }
    }

    public static void main(String[] args) {
        fib = new BigInteger[maxN];
        fill();
        while (sc.hasNext()) {
            int N = sc.nextInt();
            if (N == 0) {
                System.out.println(1);
                continue;
            }
            System.out.println(fib[2 * N - 1]);
        }
    }
}
