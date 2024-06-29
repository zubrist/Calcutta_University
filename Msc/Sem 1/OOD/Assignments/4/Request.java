
public class Request implements Comparable<Request> {
	int priority;

	Request(int priority) {
		this.priority = priority;
	}

	@Override
	public int compareTo(Request o) {
		return this.priority - o.priority;
	}

	@Override
	public String toString() {
		return "Request<priority=" + String.valueOf(this.priority) + ">";
	}
}
