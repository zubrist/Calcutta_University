package singleton1;

public class SingletonLazy {
	private static SingletonLazy obj;
	private char name;
	private SingletonLazy(char name) {
		this.name = name;
	}
	
	public static SingletonLazy getInstance(char Name) {
		if(obj==null) {
			obj = new SingletonLazy(Name);
		}
		return obj;
	}

	public char getName() {
		return name;
	}
}
