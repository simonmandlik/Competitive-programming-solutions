import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num;
        int a, b;
        num = sc.nextLine();
        a = sc.nextInt();
        b = sc.nextInt();
        int[] rem_pref = new int[num.length() + 1];
        int[] rem_suff = new int[num.length() + 1];
        rem_pref[0] = rem_suff[num.length()] = 0;
        for(int i = 1; i <= num.length(); ++i) {
            rem_pref[i] = (10 * rem_pref[i-1] + Integer.valueOf(num.substring(i-1, i))) % a;
        }
        int L = 1;
        for(int i = num.length() - 1; i >= 0; --i) {
            rem_suff[i] = (rem_suff[i+1] + L*Integer.valueOf(num.substring(i, i + 1))) % b;
            L *= 10;
            L = L % b;
        }

//        System.out.println(Arrays.toString(rem_pref));
//        System.out.println(Arrays.toString(rem_suff));

        for(int i = 1; i < num.length(); ++i) {
            if (num.charAt(i) != '0' && rem_pref[i] == 0 && rem_suff[i] == 0) {
                System.out.println("YES");
                System.out.println(num.substring(0, i));
                System.out.println(num.substring(i, num.length()));
                System.exit(0);
            }
        }
        System.out.println("NO");
    }
}
