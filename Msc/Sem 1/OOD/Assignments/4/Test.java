
public class Test {

	public static void main(String[] args) {
		RequestPool pool = RequestPool.getInstance();
		
		Requester requester = new Requester(pool);
		Thread t1 = new Thread(requester);
		t1.start();
		Thread t2 = new Thread(new Resizer(pool));
		t2.start();
	}

}
