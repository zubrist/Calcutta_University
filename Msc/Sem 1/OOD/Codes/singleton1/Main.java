package singleton1;

public class Main {
	public static void main(String[] args) {
		SingletonEager eager;
		SingletonLazy lazy;
		for (int i = 0; i<10 ; i++) {
			eager = SingletonEager.getInstance((char)(i+65));
			System.out.print("Object name eager : "+eager.getName());
			System.out.println(" and hashcode : "+eager.hashCode());
		}
		
		for (int i = 0 ; i<10 ; i++ ) {
			lazy = SingletonLazy.getInstance((char)(i+65));
			System.out.print("Object name lazy : "+lazy.getName());
			System.out.println(" and hashcode : "+lazy.hashCode());
		}
	}
}
