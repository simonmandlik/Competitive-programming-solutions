import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.jar.Pack200;

/**
 * Created by Sheemon on 3.11.
 */
public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(br.readLine());
        int N;
        while(T-- > 0) {
            N = Integer.parseInt(br.readLine());            BigInteger[] sum = new BigInteger[N + 1];
            BigInteger[] p = new BigInteger[N + 1];
            p[0] = new BigInteger("0");
            sum[0] = new BigInteger("0");
            st = new StringTokenizer(br.readLine());
            for (int i = N; i > 0; i--) {
                p[i] = new BigInteger(String.valueOf(st.nextToken()));
            }
            sum[1] = p[1];
            sum[2] = sum[1].add(p[2]);
            sum[3] = sum[2].add(p[3]);
            for(int i = 4; i <= N; ++i) {
                BigInteger best = new BigInteger("0");
                for (int j = 1; j <= 3; j++) {
                    BigInteger s = sum[(i - 2 * j) >=  0 ? i - 2 * j : 0];
                    int k = 0;
                    while (k < j) {
                        s = s.add(p[i - k]);
                        ++k;
                    }
                    if (s.compareTo(best) == 1) {
                        best = s;
                    }
                }
                sum[i] = best;
            }
            System.out.println(sum[N]);
        }
    }
}