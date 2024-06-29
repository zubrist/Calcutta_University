import java.util.*;

class Request{
	int priority;
	Request (int pri){
		this.priority=pri;
	}
	int getPri() {
		return priority;
	}
	
}

class CreatePool extends Thread{
	Random rn = new Random();
	public void run() {
		try {
			
			while(true) {
				// set the size of the pool
				int PoolSize = rn.nextInt(15);
				System.out.println("NEW Size of the pool is: " + PoolSize);
				if(PoolSize >ObjectPool.pq.size()) {
					System.out.println("Pool size is Increased, thus Requests are being added ......");
					while(PoolSize >ObjectPool.pq.size()) {
						ObjectPool.pq.add(new Request(rn.nextInt(ObjectPool.pq.size()+1)));
					}
					int i=0;
					System.out.println("********** CURRENT ELEMENTS IN QUEUE **********");
					for (Request r1 : ObjectPool.pq) {
						i++;
						System.out.println("Request Element "+ i + ":" + r1 + "  Priority : "+ r1.getPri());
					}
				}
				else if(PoolSize <ObjectPool.pq.size()) {
					System.out.println("Pool size is decreased, thus Requests with the lowest priority are being removed ......");
					while(PoolSize <ObjectPool.pq.size()) 
						System.out.println("Priority number : " + ObjectPool.pq.peek().getPri() + " Removed Element : " + ObjectPool.pq.poll() );
				}
				else
					System.out.println("Pool size remains same, thus no Request gets added or removed...");
					Thread.sleep(5000);
				
				Thread.sleep(3000);
			}
			
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	
}

class Compare implements Comparator<Request>{
	public int compare(Request r1 ,Request r2 ) {
		if (r1.priority>r2.priority) {
			return -1;
		}
		else if (r1.priority<r2.priority) {
			return 1;
		}
		else 
			return 0;
	}
}

class ObjectPool{
	
	public static PriorityQueue<Request> pq = new PriorityQueue<Request>(new Compare());
	public static void main(String Args[]) {
		CreatePool ob =  new CreatePool();
		ob.start();
	}
}