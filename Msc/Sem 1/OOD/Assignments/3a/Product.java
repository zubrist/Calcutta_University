import java.io.Serializable;

class Product implements Serializable {
	private int productId;
	private String productName;
	private double price;
	private int quantity;

	public Product(int id, String name, double price, int qty) {
		this.productId = id;
		this.productName = name;
		this.price = price;
		this.quantity = qty;
	}

	public int getProductId() {
		return productId;
	}

	public String getProductName() {
		return productName;
	}

	public double getPrice() {
		return price;
	}

	public int getQuantity() {
		return quantity;
	}

	public void setProductName(String name) {
		this.productName = name;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public void setQuantity(int quantity) throws Exception {
		if (quantity < 0)
			throw new Exception("NegativeQuantityException");
		this.quantity = quantity;
	}

}
