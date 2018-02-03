/*
Name - Nikhil Ranjan Nayak
Regd No - 1641012040
Desc - Compute intergration of dt/ln(t) from 2 to x, Π(x) and x / ln(x).
 */

public class Program {
	public static void main(String[] args) {
		double x, lower_bound = compute_series(2);

		System.out.println("Π(x)");
		System.out.println("x/ln(x)");
		System.out.println("[2, x]Sdt/ln(t)\n");

		System.out.println("10        10^2        10^3        10^4        10^6");
		System.out.println(bigpi(10) + "      " + bigpi(100) + "      " + bigpi(1000) + "      " + bigpi(10000) + "      " + bigpi(1000000));

		System.out.println((10 / Math.log(10)) + "   " + (100 / Math.log(100)) + "   " + (1000 / Math.log(1000)) + "   " + (10000 / Math.log(10000)) + "   " + (1000000 / Math.log(1000000)));

		System.out.println((compute_series(10) - lower_bound) + "   " + (compute_series(100) - lower_bound) + "   " + (compute_series(1000) - lower_bound) + "   " + (compute_series(10000) - lower_bound) + "   " + (compute_series(1000000) - lower_bound));
	}

	public static double compute_series(double t) {
		double i = 1, sum, term, error = 0.000001;

		sum = Math.log(Math.log(t)) + Math.log(t);
		term = Math.log(t);
		
		while(Math.abs(term) > error) {
			i++;
			term = (term * (Math.log(t) / i) * (i - 1)) / i;
			sum += term;
		}
		
		return sum;
	}

	public static int bigpi(double x) {
		int i, ctr = 0;

		if(x >= 2)
			ctr++;
		for(i = 3; i <= x; i += 2) {
			if (isprime(i) == 1)
				ctr++;
		}
		
		return ctr;
	}

	public static int isprime(int x) {
		int i, flag = 1;

		for(i = 2; i <= Math.sqrt(x); i++) {
			if(x % i == 0) {
				flag = 0;
				break;
			}
		}
	return flag;
	}
}
