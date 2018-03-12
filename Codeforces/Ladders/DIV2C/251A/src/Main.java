import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n, d;
    static int[] X;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        X = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            X[i] = Integer.parseInt(st.nextToken());
        }

        BigInteger res = BigInteger.ZERO;
        int a, b, m;
        long best;
        for(int i = 0; i < n; ++i) {
            best = i; a = i+2; b = n-1;

            while (a <= b) {
                m = (a+b) / 2;
                if (X[m] - X[i] <= d) {
                    best = Math.max(i, m);
                    a = m + 1;
                } else {
                    b = m - 1;
                }
            }

            if (best - i > 1) {
                long inc = ((best-i)*(best-i-1)) / 2;
                res = res.add(new BigInteger(String.valueOf(inc)));
            }
        }

        System.out.println(res);

    }
}
