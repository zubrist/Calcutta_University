package abstractFactory;

public abstract class PizzaFactory {
	
	public static PizzaFactory getFactory(String style) {
		if(style.equalsIgnoreCase("american")) {
			return new AmericanStylePizza();
		}
		else if(style.equalsIgnoreCase("northindian")) {
			return new NorthIndianStylePizza();
		}
		else return null;
	}
	
	abstract Pizza order(String type);
}


class AmericanStylePizza extends PizzaFactory {

	@Override
	public Pizza order(String type) {
		if(type.equalsIgnoreCase("panner")) {
			return new AmericanPannerPizza();
		}
		else if(type.equalsIgnoreCase("chicken")) {
			return new AmericanChickenPizza();
		}
		else if(type.equalsIgnoreCase("barbeque")) {
			return new AmericanBarbequePizza();
		}
		else return null;
	}
	
	
}

class NorthIndianStylePizza extends PizzaFactory {

	@Override
	public Pizza order(String type) {
		if(type.equalsIgnoreCase("panner")) {
			return new NorthIndianPannerPizza();
		}
		else if(type.equalsIgnoreCase("chicken")) {
			return new NorthIndianChickenPizza();
		}
		else return null;
	}
	
	
}
