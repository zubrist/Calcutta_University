import java.util.ArrayList;
import java.util.Random;

/**
 * This is an implementation of ObjectPool Class that uses the
 * object pool pattern to return a random object from the pool
 * 
 * @author Sudipto Ghosh (Roll No. 27)
 *
 */
public class ObjectPool {
	private static int poolSize = 5;
	private static ObjectPool _instance = null;
	private static ArrayList<Object> pool = new ArrayList<>();
	private static Random random = new Random();

	private ObjectPool() {
		random.setSeed(10);
		for (int i = 0; i < poolSize; i++) {
			pool.add(new Object());
		}
		System.out.println("ObjectPool<" + hashCode() + "> Created with " + poolSize + " Objects");
	}

	public static ObjectPool getInstance() {
		if (_instance == null)
			_instance = new ObjectPool();
		return _instance;
	}

	public Object getObject() {
		if (pool.size() > 0) {
			int rnd = random.nextInt(pool.size());
			Object obj = pool.get(rnd);
			pool.remove(rnd);
			setPoolSize(poolSize - 1);
			return obj;
		} else {
			return null;
		}
	}

	public void storeObject(Object obj) {
		pool.add(obj);
		setPoolSize(poolSize + 1);
	}

	public int getPoolSize() {
		return pool.size();
	}

	public void setPoolSize(int poolSize) {
		ObjectPool.poolSize = poolSize;
	}

	/*
	 * Driver Code
	 */
	public static void main(String[] args) {
		ObjectPool pool = ObjectPool.getInstance();

		for (int i = 0; i < 5; i++) {
			Object obj = pool.getObject();

			if (obj == null) {
				System.out.println("No Object Could Be Fetched From ObjectPool<"
						+ pool.hashCode() + ">");
				continue;
			}

			if (i % (random.nextInt(3) + 1) == 0) {
				System.out.println("Object<" + obj.hashCode() + "> Fetched From ObjectPool<"
						+ pool.hashCode() + "> (Objects Remaining: " + pool.getPoolSize() + ")");
			} else {
				pool.storeObject(obj);
				System.out.println("Object<" + obj.hashCode() + "> Fetched and Stored Back Into ObjectPool<"
						+ pool.hashCode() + "> (Objects Remaining: " + pool.getPoolSize() + ")");
			}
		}
	}
}
