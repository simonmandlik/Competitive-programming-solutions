import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    final static long MOD = 1000000007;

    static int N, M, u, v, P_count = 1, c_count = 1, stack_pointer = 0, min_cost, count;
    static int[] costs, component, stack, P, Z;
    static long net_cost = 0, ways = 1;
    static ArrayList<LinkedList<Integer>> neighList;

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        readInput();
        for (int i = 0; i < N; i++) {
            // P[i] == 0 <=> visited[i]
            if (P[i] == 0) {
                tarjan(i);
            }
        }
        System.out.printf("%d %d\n", net_cost, ways);
    }

    static void tarjan(int curr) {
        P[curr] = Z[curr] = P_count++;
        stack[stack_pointer++] = curr;
        for (int neigh : neighList.get(curr)) {
            if (component[neigh] != 0) continue;
            if (P[neigh] == 0) {
                tarjan(neigh);
                Z[curr] = Math.min(Z[curr], Z[neigh]);
            } else {
                Z[curr] = Math.min(Z[curr], P[neigh]);
            }
        }
        if (P[curr] == Z[curr]) {
            int x;
            min_cost = Integer.MAX_VALUE;
            count = 1;
            do {
                x = stack[--stack_pointer];
                component[x] = c_count;
                if (min_cost > costs[x]) {
                    min_cost = costs[x];
                    count = 1;
                } else if (min_cost == costs[x]) ++count;
            } while (x != curr);
            ++c_count;
            ways = (ways * count) % MOD;
            net_cost += min_cost;
        }
    }

    private static void readInput() {
        N = sc.nextInt();
        costs = new int[N];
        P = new int[N];
        Z = new int[N];
        stack = new int[N];
        component = new int[N];
        neighList = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            costs[i] = sc.nextInt();
            neighList.add(new LinkedList<>());
        }
        M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            u = sc.nextInt(); v = sc.nextInt(); --u; --v;
            neighList.get(u).add(v);
        }
    }
}
