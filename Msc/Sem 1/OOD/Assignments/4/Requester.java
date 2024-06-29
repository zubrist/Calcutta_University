public class Requester implements Runnable {
	private RequestPool pool;

	public Requester(RequestPool pool) {
		this.pool = pool;
	}

	@Override
	public void run() {
		while (true) {
			try {
				pool.getRequest();
			} catch (Exception e) {
				System.err.println("Exception: " + e.getMessage());
			}

			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				System.err.println("Exception: " + e.getMessage());
			}
		}

	}
}
