import java.io.*;
import java.util.ArrayList;

public class Stock {
	private UserType user;
	private ArrayList<Product> products;

	public Stock() {
		this.products = new ArrayList<>();
	}

	public Stock(UserType user) {
		this();
		this.user = user;
	}

	public void addProduct(Product... products) throws Exception {
		for (Product product : products) {
			this.products.add(product);
		}
	}

	public void removeProduct(int id) throws Exception {
		if (this.user != UserType.ADMIN) {
			throw new Exception("Unauthorized Access");
		}

		for (Product product : this.products) {
			if (product.getProductId() == id) {
				this.products.remove(product);
				return;
			}
		}

		System.err.println("Product Not Found");
	}

	public void updateProduct(Product p) throws Exception {
		if (this.user != UserType.ADMIN) {
			throw new Exception("Unauthorized Access");
		}

		for (Product product : this.products) {
			if (product.getProductId() == p.getProductId()) {
				this.products.remove(product);
				this.products.add(p);
				return;
			}
		}

		System.err.println("Product Not Found");
	}

	public double orderProductByID(int id, int qty) {
		for (Product product : this.products) {
			if (id == product.getProductId()) {
				try {
					product.setQuantity(product.getQuantity() - qty);
					return qty * product.getPrice();
				} catch (Exception e) {
					System.err.println(e.getMessage());
					return -1.0;
				}
			}
		}
		System.err.println("Product Not Found");
		return -1.0;
	}

	public double orderProductByName(String name, int qty) {
		for (Product product : this.products) {
			if (product.getProductName().toLowerCase().contains(name.toLowerCase())) {
				try {
					product.setQuantity(product.getQuantity() - qty);
					return qty * product.getPrice();
				} catch (Exception e) {
					System.err.println(e.getMessage());
					return -1.0;
				}
			}
		}
		System.err.println("Product Not Found");
		return -1.0;
	}

	public static Stock readStock(String fileName, UserType user) throws Exception {
		Stock stock = new Stock(user);
		try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
			FileInputStream fis = new FileInputStream(fileName);
			ObjectInputStream ois = new ObjectInputStream(fis);
			ArrayList<?> products = (ArrayList<?>) ois.readObject();
			for (Object product : products) {
				if (product instanceof Product) {
					stock.addProduct((Product) product);
				}
			}
			ois.close();
		} catch (FileNotFoundException e) {
			File file = new File(fileName);
			file.createNewFile();
		} catch (IOException e) {
			System.err.println("Exception: " + e.getMessage());
		}
		return stock;
	}

	public void saveStock(String fileName) throws FileNotFoundException, IOException {
		try {
			FileOutputStream fout = new FileOutputStream(fileName);
			ObjectOutputStream oos = new ObjectOutputStream(fout);
			oos.writeObject(products);
			fout.close();
		} catch (FileNotFoundException e) {
			File file = new File(fileName);
			file.createNewFile();
			FileOutputStream fout = new FileOutputStream(fileName);
			ObjectOutputStream oos = new ObjectOutputStream(fout);
			oos.writeObject(products);
			fout.close();
		} catch (IOException e) {
			System.err.println("Exception: " + e.getMessage() + e);
		}
	}

	public void resetStock(String fileName) throws Exception {
		try {
			if (this.user != UserType.ADMIN) {
				throw new Exception("Unauthorized Access");
			}

			FileOutputStream fout = new FileOutputStream(fileName);
			ObjectOutputStream oos = new ObjectOutputStream(fout);
			oos.writeObject(new ArrayList<Product>());
			fout.close();
		} catch (FileNotFoundException e) {
			File file = new File(fileName);
			file.createNewFile();
			FileOutputStream fout = new FileOutputStream(fileName);
			ObjectOutputStream oos = new ObjectOutputStream(fout);
			oos.writeObject(new ArrayList<Product>());
			fout.close();
		} catch (Exception e) {
			System.err.println("Exception: " + e.getMessage());
		}
	}

	@Override
	public String toString() {
		String s = "Store Inventory:\n\nProduct ID\t | Product Name\t | Price ₹\t | Qty Left\n";
		s += "------------------------------------------------------------\n";
		for (Product product : this.products) {
			s += product.getProductId() + "\t\t | "
					+ product.getProductName() + "\t | "
					+ product.getPrice() + "\t\t | "
					+ product.getQuantity() + "\n";
		}
		return s;
	}
}
