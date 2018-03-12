import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int count = 0;
    public static void main(String[] args) {
        int T = sc.nextInt();
        int N, result;
        int[] pupils, l_b, u_b;
        while (T-- > 0) {
            count = 0;
            result = 1;
            N = sc.nextInt();
            pupils = new int[N];
            l_b = new int[N];
            u_b = new int[N];

            for (int i = 0; i < N; i++) {
                pupils[i] = sc.nextInt();
                u_b[i] = N - 1;
                l_b[i] = 0;
            }

            for (int i = 0; i < N; i++) {
                l_b[i] += pupils[i];
                if (i + pupils[i] == N) {
                    System.out.println(0);
                    count = -1;
                    break;
                }
                if (i + pupils[i] != N - 1) {
                    l_b[i + pupils[i] + 1]++;
                    u_b[i]--;
                }
                for (int j = 1; j <= pupils[i]; ++j) {
                    u_b[j + i]--;
                }
                if (u_b[i] < l_b[i]) {
                    System.out.println(0);
                    count = -1;
                    break;
                }
            }
            if (count != -1) {
                HashSet<Integer> used = new HashSet<>(N);
                solve(N, 0, l_b, u_b, used);
                System.out.println(count);
            }
        }
    }

    public static void solve(int N, int from, int[] l_b, int[] u_b, Set<Integer> used) {
        if (from == N) {
            count++;
        } else {
            for (int i = l_b[from]; i <= u_b[from]; ++i) {
                if (!used.contains(i)) {
                    used.add(i);
                    solve(N, from + 1, l_b, u_b, used);
                    used.remove(i);
                }
            }
        }
    }

}



