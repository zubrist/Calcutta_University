public class Resizer implements Runnable {
	private int ctr = 0;
	private RequestPool pool;

	public Resizer(RequestPool pool) {
		this.pool = pool;
	}

	@Override
	public void run() {
		while (true) {
			try {
				Thread.sleep(10000);
			} catch (InterruptedException e) {
				System.err.println("Exception: " + e.getMessage());
			}

			try {
				if (ctr++ % 2 == 0) {
					System.out.println("Trimming ...");
					pool.trim(5);
				} else {
					System.out.println("Expanding ...");
					pool.expand(5);
				}

			} catch (Exception e) {
				System.err.println("Exception: " + e.getMessage() + " " + e);
			}

		}

	}
}
