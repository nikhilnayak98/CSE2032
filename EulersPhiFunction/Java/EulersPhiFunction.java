/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Euler's Phi Function
*/
import java.util.Scanner;

public class EulersPhiFunction {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.println("\nEnter n - ");
		n = sc.nextInt();
        
    	System.out.println("\nPhi of " + n + " - " + phi(n));
    	}
    	
    public static int phi(int n) {
		int i;
		double res = n;
	
		for(i = 2; i <= Math.sqrt(n); i++) {
			if(n % i == 0) {
				while(n % i == 0) {
				n /= i;
				}
				res *= (1.0 - 1.0 / (double)i);
			}
		}

		if(n > 1)
			res *= (1.0 - 1.0 / n);
	
		return (int)res;
	}
}
