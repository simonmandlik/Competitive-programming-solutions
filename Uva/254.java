import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    static int n, from, to, over, tmp;
    static int[] pegs = new int[3];
    static BigInteger m;

    static BigInteger[] powers = new BigInteger[101];

    public static void main(String[] args) {
        BigInteger cum = BigInteger.ONE;
        for (int i = 0; i < 101; i++) {
            powers[i] = cum;
            cum = cum.multiply(new BigInteger("2"));
        }

        while (sc.hasNext()) {
            n = sc.nextInt(); m = sc.nextBigInteger();
            if (n == 0) break;
            from = 0;
            if (n % 2 == 1) { to = 1; over = 2; }
            else { to = 2; over = 1; }
            Arrays.fill(pegs, 0);
            for (int i = n; i > 0; i--) {
                if (m.compareTo(powers[i-1]) >= 0) {
                    m = m.subtract(powers[i-1]);
                    pegs[to]++;
                    tmp = from;
                    from = over;
                    over = tmp;
                } else {
                    pegs[from]++;
                    tmp = to;
                    to = over;
                    over = tmp;
                }
            }
            System.out.printf("%d %d %d\n", pegs[0], pegs[1], pegs[2]);
        }
    }
}
