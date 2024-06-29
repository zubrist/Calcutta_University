package reflection;

interface Interface1 {
	int number = 10;
}

interface Interface2 {}

class Parent {}

public class ExampleClass extends Parent implements Interface1,Interface2 {
	private String str1 = "private member";
	public String str2 = "public member";
	protected String str3 = "protected member";
	
	private final int variable = 15;
	
	ExampleClass() {
		System.out.println("Constructor 1");
	}
	
	ExampleClass(int i, char c) {
		System.out.println("Constructor 2");
	}
	
	public void method1() {
		System.out.println("public method1");
	}
	
	public void method1(String i, char j) {
		System.out.println("public method2");
	}
}
