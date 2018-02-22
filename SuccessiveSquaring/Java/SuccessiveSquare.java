/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Successive Squaring
*/
import java.util.Scanner;

public class SuccessiveSquare {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b = 1, k, m;
		System.out.println("a^k(mod m)");
		System.out.println("a - ");
		a = sc.nextInt();
		System.out.println("k - ");
		k = sc.nextInt();
		System.out.println("m - ");
		m = sc.nextInt();
		System.out.println(a + "^" + k + "(mod " + m + ")");
		while(k >= 1)
		{
			if((k % 2) != 0)
				b *= a;
		
			a *= a;
			k /= 2;
		}
		System.out.println("x - " + b);
	}
}
