package abstractFactory;

public interface Pizza {
	void placeOrder();
}

class AmericanPannerPizza implements Pizza {

	@Override
	public void placeOrder() {
		System.out.println("Here is Your American Style Panner Pizza");
		
	}
}

class AmericanChickenPizza implements Pizza {

	@Override
	public void placeOrder() {
		System.out.println("Here is Your American Style Chicken Pizza");
		
	}
}

class AmericanBarbequePizza implements Pizza {

	@Override
	public void placeOrder() {
		System.out.println("Here is Your American Style Barbeque Pizza");
		
	}
}

class NorthIndianPannerPizza implements Pizza {

	@Override
	public void placeOrder() {
		System.out.println("Here is Your NorthIndian Style Panner Pizza");
		
	}
}

class NorthIndianChickenPizza implements Pizza {

	@Override
	public void placeOrder() {
		System.out.println("Here is Your NorthIndian Style Chicken Pizza");
		
	}
}
