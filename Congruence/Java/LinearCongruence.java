/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Linear Congruence Solver
*/
import java.util.Scanner;

public class LinearCongruence {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, c, m, g;
		System.out.println("a ≅ c(mod m)");
		System.out.println("a - ");
		a = sc.nextInt();
		System.out.println("c - ");
		c = sc.nextInt();
		System.out.println("m - ");
		m = sc.nextInt();
		System.out.println(a + " ≅  " + c + "(mod " + m + ")");
		g = gcd(a, m); 
		System.out.println("GCD - " + g);
		if(m % g == 0)
		{
			for(int x = 0; x < m; x++)
			{
				if((a*x) % m == c)
					System.out.println("\nx ≅ "+ x + "(mod " + m + ")");
			}
			System.out.println("");
		}
	}

	public static int gcd(int a,int b) {
		if(a == 0)
        		return b;
    		return gcd(b%a, a);
    	}
}
