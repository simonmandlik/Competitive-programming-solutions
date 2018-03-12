import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N, u, v, count, tail;
    static ArrayList<ArrayList<Integer>> adjList;
    static int[] curr, fin, sol;
    static boolean[] visited;


    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        adjList = new ArrayList<>(N);
        curr = new int[N]; fin = new int[N]; sol = new int[N];
        visited = new boolean[N];
        for (int i = 0; i < N; ++i) adjList.add(new ArrayList<>());
        for (int i = 0; i < N - 1; ++i) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken()); v = Integer.parseInt(st.nextToken());
            --u; --v;
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            curr[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            fin[i] = Integer.parseInt(st.nextToken());
        }
        count = 0;
        tail = 0;
        solve(0, 0, 0);
        System.out.println(count);
        for (int i = 0; i < tail; i++) {
            System.out.println(sol[i]);
        }
    }

    private static void solve(int n, int a, int b) {
        visited[n] = true;
        int next_b = a;
        if (curr[n] == fin[n] ^ a == 0) {
            sol[tail++] = n+1;
            ++count;
            next_b = (1 + a) % 2;
        }
        for (int child : adjList.get(n)) {
            if (!visited[child])
            solve(child, b, next_b);
        }
    }
}
