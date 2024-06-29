import java.util.ArrayList;

public class Stock {
	private ArrayList<Product> products;

	public Stock() {
		this.products = new ArrayList<>();
	}

	public void addProduct(Product... products) {
		for (Product product : products) {
			this.products.add(product);
		}
	}

	public double orderProduct(String name, int qty) {
		for (Product product : this.products) {
			if (name.toLowerCase().contains(product.getProductName().toLowerCase())) {
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
