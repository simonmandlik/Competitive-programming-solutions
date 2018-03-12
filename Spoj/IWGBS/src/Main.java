import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        BigInteger[] one = new BigInteger[N + 1];
        BigInteger[] two = new BigInteger[N + 1];
        one[1] = two[1] = new BigInteger("1");
        for(int i = 2; i <= N; ++i) {
            one[i] = two[i - 1];
            two[i] = one[i].add(one[i - 1]);
//            System.out.println(one[i]);
//            System.out.println(two[i]);
        }
        System.out.println(one[N].add(two[N]));
    }
}
