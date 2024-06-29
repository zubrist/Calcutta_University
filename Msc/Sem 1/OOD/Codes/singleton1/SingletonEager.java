package singleton1;

public class SingletonEager {
	private char name;
	private SingletonEager() {
		// we cant use constructor for data initialization
	}
	
	private static SingletonEager obj = new SingletonEager();
	public static SingletonEager getInstance(char name) {
		obj.name=name;
		return obj;
	}
	public char getName() {
		return name;
	}
}
