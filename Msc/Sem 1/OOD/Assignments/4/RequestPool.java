import java.util.*;

public class RequestPool {
	int index = 0;
	private int maxSize = 10;
	private Random random;
	private PriorityQueue<Request> pq;
	private ArrayList<Request> pool;
	private static RequestPool instance;

	private RequestPool() {
		this.random = new Random(0);
		this.pq = new PriorityQueue<Request>(this.maxSize);
		this.pool = new ArrayList<Request>(this.maxSize);
	}

	public static RequestPool getInstance() {
		if (instance == null) {
			instance = new RequestPool();
		}
		return instance;
	}

	public Request getRequest() throws Exception {
		Collections.sort(this.pool, Collections.reverseOrder());
		if (this.pool.size() == 0 || this.index >= this.pool.size()) {
			Request r = new Request(this.random.nextInt(100) + 1);
			this.pool.add(r);
			this.pq.add(r);
		}
		Request r = this.pool.get(this.index);
		this.index = (this.index + 1) % this.maxSize;
		System.out.println("Serving " + r + " ...");
		return r;
	}

	public void expand(int n) {
		this.maxSize += n;
	}

	public void trim(int n) {
		for (int i = 0; i < n; i++) {
			Request r = this.pq.poll();
			this.pool.remove(r);
			System.out.println("Removed " + r + " ...");
		}
		this.maxSize -= n;
		System.out.println("Left with " + this.pq.size() + " Requests ...");
	}
}
