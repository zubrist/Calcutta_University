package abstractFactory;

public class PizzaStore {
	public static void main(String[] args) {
		PizzaFactory pf1 = PizzaFactory.getFactory("american");
		if(pf1 != null) {
			Pizza p1 = pf1.order("chicken");
			if(p1 != null)
				p1.placeOrder();
		}
		
		PizzaFactory pf2 = PizzaFactory.getFactory("northindian");
		if(pf2 != null) {
			Pizza p2 = pf2.order("panner");
			if(p2 != null)
				p2.placeOrder();
		
			
			
			//This is fun
			pf1.order("panner").placeOrder();
			pf2.order("chicken").placeOrder();
			
			//This is more fun. Direct
			PizzaFactory.getFactory("american").order("barbeque").placeOrder();
			PizzaFactory.getFactory("northindian").order("chicken").placeOrder();
		}
		
	}
}
