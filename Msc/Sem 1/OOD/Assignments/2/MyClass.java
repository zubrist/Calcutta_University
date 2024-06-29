public class MyClass {
	static int num = 1;

	public MyClass() {
		System.out.println("My Class Instantiated");
	}

	private MyClass(int i) {
		System.out.println("My Class Instantiated");
	}

	String hello(int i, String name) {
		return "hi " + name;
	}
}
