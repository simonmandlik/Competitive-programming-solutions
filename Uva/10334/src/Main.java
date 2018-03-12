import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by Sheemon on 27.10.
 */
public class Main {

    static BigInteger[] fibonacci;
    static int maxN = 1005;

    static Scanner sc = new Scanner(System.in);

    public static void fill() {
        fibonacci = new BigInteger[maxN];
        fibonacci[0] = fibonacci[1] = new BigInteger("1");

        for (int i = 2; i < maxN; i++) {
            fibonacci[i] = fibonacci[i - 1].add(fibonacci[i - 2]);
        }
    }
    public static void main(String[] args) {
        fill();
        while(sc.hasNext()) {
            int N = sc.nextInt();
            System.out.printf("%s\n", fibonacci[N + 1]);
        }
    }
}
