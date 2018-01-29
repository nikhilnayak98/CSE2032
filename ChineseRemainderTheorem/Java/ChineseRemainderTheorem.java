/*
Name - Nikhil Ranjan Nayak
Regd no - 1641012040
Desc - Chinese Remainder Theorem
*/
import java.util.Scanner;

public class ChineseRemainderTheorem {

	public static void main(String[] args)  {
    	Scanner sc = new Scanner(System.in);
    	int y, b, c, m, n, x;
    	System.out.println("\nx ≅ b(mod m)");
    
	    System.out.println("\nEnter b - ");
    	b = sc.nextInt();
    
	    System.out.println("\nEnter m - ");
    	m = sc.nextInt();
    
    	System.out.println("\nx ≅ c(mod n)");
    
    	System.out.println("\nEnter c - ");
    	c = sc.nextInt();
    
    	System.out.println("\nEnter n - ");
    	n = sc.nextInt();
    
    	if(gcd(m, n) == 1) {
    		for(y = 0; y < n; y++) {
    			if((m * y) % n == (c - b)) {
                	x = (m * y) + b;
    				System.out.println("\nx = " + x);
                	break;
            	}
    		}
    	}
}

	public static int gcd(int a, int b) {
    	if(b == 0)
        	return a;
    	return gcd(b, a % b);
    }
}
