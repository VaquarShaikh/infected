import java.util.*;
import java.io.*;

public class Test {
	public static void main(String[] args) {
		// System.out.println("Hello World");
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			int num = 0;
			while (n-- > 0) {
				num = sc.nextInt();
			}
			if (num % 10 == 5 || num % 10 == 0) {
				System.out.println("LUCKY");
			} else {
				System.out.println("UNLUCKY");
			}
		}
	}
}