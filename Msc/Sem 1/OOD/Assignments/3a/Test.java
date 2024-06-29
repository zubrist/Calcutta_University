import java.io.*;
import java.util.*;

public class Test {
	public static void main(String[] args) throws IOException {
		boolean flag = false;

		int opt;
		UserType user;

		// admin or user
		Scanner sc = new Scanner(System.in);

		do {
			System.out.println("Choose User Type: ");
			System.out.println("1. Admin");
			System.out.println("2. User");
			System.out.print("Enter your choice: ");

			try {
				opt = sc.nextInt();
				if (opt == 1) {
					user = UserType.ADMIN;
					flag = true;

					String name;
					double price;
					int id, qty;

					System.out.println("Welcome " + user + "!");

					Stock stock = Stock.readStock("stock.db", user);

					do {
						System.out.println(stock);
						System.out.println("Choose Option: ");
						System.out.println("1. Add Product");
						System.out.println("2. Remove Product");
						System.out.println("3. Update Product");
						System.out.println("4. Save Stock");
						System.out.println("5. Reset Stock");
						System.out.println("6. Exit");
						System.out.print("Enter your choice: ");

						opt = sc.nextInt();
						System.out.println();

						try {
							switch (opt) {
								case 1:
									System.out.print("Enter Product ID: ");
									id = sc.nextInt();
									System.out.print("Enter Product Name: ");
									name = sc.next();
									System.out.print("Enter Product Price: ");
									price = sc.nextDouble();
									System.out.print("Enter Product Quantity: ");
									qty = sc.nextInt();

									stock.addProduct(new Product(id, name, price, qty));
									break;
								case 2:
									System.out.print("Enter Product ID: ");
									id = sc.nextInt();

									stock.removeProduct(id);
									break;
								case 3:
									System.out.print("Enter Product ID: ");
									id = sc.nextInt();
									System.out.print("Enter Product Name: ");
									name = sc.next();
									System.out.print("Enter Product Price: ");
									price = sc.nextDouble();
									System.out.print("Enter Product Quantity: ");
									qty = sc.nextInt();

									stock.updateProduct(new Product(id, name, price, qty));
									break;
								case 4:
									stock.saveStock("stock.db");
									break;
								case 5:
									stock.resetStock("stock.db");
									stock = null;
									stock = Stock.readStock("stock.db", user);
									System.gc();
									break;
								case 6:
									System.out.println("Thank you for your service!");
									break;
								default:
									System.out.println("Invalid Option!");
							}
						} catch (Exception e) {
							System.err.println("Exception: " + e.getMessage());
						}
					} while (opt != 6);
				} else if (opt == 2) {
					user = UserType.USER;
					flag = true;

					int qty;
					String name;
					double sub, sum = 0, dis = 0;

					System.out.println("Welcome " + user + "!");

					Stock stock = Stock.readStock("stock.db", user);

					do {
						System.out.println(stock);
						System.out.println("Choose Option: ");
						System.out.println("1. Order Product");
						System.out.println("2. Exit");
						System.out.print("Enter your choice: ");
						opt = sc.nextInt();
						System.out.println();

						switch (opt) {
							case 1:
								System.out.print("Enter Product name: ");
								name = sc.next();
								System.out.print("Enter Product Quantity: ");
								qty = sc.nextInt();
								sub = stock.orderProductByName(name, qty);
								if (sub != -1)
									sum += sub;
								break;
							case 2:
								System.out.println("Invoice Subtotal: ₹" + sum);
								if (sum >= 1000) {
									dis = sum * 0.1;
									System.out.println("Invoice Discount: (-) ₹" + dis);
								}
								System.out.println("Invoice Total: ₹" + (sum - dis));
								System.out.println("Thank you for shopping with us!");
								stock.saveStock("stock.db");
								break;
							default:
								System.out.println("Invalid Option!");
								break;
						}
					} while (opt != 2);
				} else {
					System.out.println("Invalid Choice");
				}
			} catch (InputMismatchException e) {
				System.out.println("Invalid Choice");
			} catch (Exception e) {
				System.err.println("Exception: " + e.getMessage());
			}
		} while (flag == false);

		sc.close();
	}
}
