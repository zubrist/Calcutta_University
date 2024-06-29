import java.util.*;
import java.io.*;

public class Test {
	public static void main(String[] args) throws IOException {
		boolean flag = true;
		
		int n, id, qty, opt;
		double price, sub, dis = 0.0, sum = 0.0;
		String name;
		
		Stock stock = new Stock();
		
		Scanner sc = new Scanner(System.in);
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter Number of Products: ");
		n = sc.nextInt();
		
		for (int i = 0; i < n; i++) {
			System.out.println("\nProduct " + (i + 1) + "\n---------");
			System.out.print("Product ID: ");
			id = sc.nextInt();
			System.out.print("Product Name: ");
			name = "" + stdin.readLine();
			System.out.print("Product Price (₹): ");
			price = sc.nextDouble();
			System.out.print("Product Quantity: ");
			qty = sc.nextInt();
			
			stock.addProduct(new Product(id, name, price, qty));
		}

		System.out.println();
		
		do {
			System.out.println(stock);
			
			System.out.print("Do you want to order more products? (1/-1) ");
			opt = sc.nextInt();
			
			if (opt == -1) flag = false;
			else if (opt == 1) {
				System.out.print("Enter Product Name: ");
				name = "" + stdin.readLine();
				System.out.print("Enter Quantity: ");
				qty = sc.nextInt();
				sub = stock.orderProduct(name, qty);
				if (sub >= 0) sum += sub;
			}
		} while (flag == true);
		
		if (sum > 1000) dis = 0.05 * sum;
		
		System.out.println("Invoice Subtotal: ₹" + sum);
		System.out.println("Invoice Discount: ₹" + dis);
		System.out.println("Invoice Total: ₹" + (sum - dis));
		sc.close();
	}
}
