/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Euler's Phi Function
*/
import java.util.Scanner;

public class EulersPhiFunction {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, res, i, temp;
		System.out.println("\nEnter n - ");
		n = sc.nextInt();
		res = n;
		temp = n;
		
		for(i = 2; i <= Math.sqrt(n); i++) {
        	if(n % i == 0) { 
       			while(n % i == 0) {
            	    n /= i;
				}
            	res -= (res / i);
        	}
    	}

    	if(n > 1)
        	res -= (res / n);
        
    	System.out.println("\nPhi of " + temp + " - " + res);
    	}
}
