package reflection;

//import java.io.FileNotFoundException;
//import java.io.PrintStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Arrays;


public class ReflectDemo {

	public static void main(String[] args) {
			
//		Temporary tmp = new Temporary();
//		Class<? extends Temporary> cls = tmp.getClass();
			Class<?> cls = ExampleClass.class;
			
			//PrintStream file = new PrintStream("./"+cls.getName()+"_debug.java");
			//System.setOut(file);
			
			
			System.out.println("Name : "+cls.getSimpleName());
			System.out.println("Package : "+cls.getPackageName());
			System.out.println("Super Class : "+cls.getSuperclass().getSimpleName());
			System.out.println("Interfaces : "+Arrays.toString(cls.getInterfaces()));
			
			System.out.println("\nAll constructors...\n");
			for(Constructor<?> i : cls.getDeclaredConstructors()) {
				System.out.println("Name : "+i.getName());
				System.out.println("Modifiers : "+Modifier.toString(i.getModifiers()));
				System.out.println("Parameter Count : "+i.getParameterCount());
				System.out.println("Parameter types : "+Arrays.toString(i.getParameterTypes())+"\n");
			}
			
			System.out.println("\nAll declared methods...\n");
//		Method [] method1 = cls.getDeclaredMethods();
			for(Method i : cls.getDeclaredMethods()) {
				System.out.println("Name : "+i.getName());
				System.out.println("Modifiers : "+Modifier.toString(i.getModifiers()));
				System.out.println("Return Type : "+i.getReturnType());
				System.out.println("Parameter Count : "+i.getParameterCount());
				System.out.println("Parameter types : "+Arrays.toString(i.getParameterTypes())+"\n");
				
			}
			
//		System.out.println("\nAll public methods...(both base and super class)\n");
//		Method [] method2 = cls.getMethods();
//		for(Method i : cls.getMethods()) {
//			System.out.println("Name : "+i.getName());
//			System.out.println("Modifiers : "+Modifier.toString(i.getModifiers()));
//			System.out.println("Return Type : "+i.getReturnType()+"\n");
//		}
			
			System.out.println("\nAll declared fields...\n");
			for(Field i : cls.getDeclaredFields()) {
				System.out.println("Name : "+i.getName());
				System.out.println("Type : "+i.getType());
				System.out.println("Modifiers : "+Modifier.toString(i.getModifiers())+"\n");
			}
			
			Class<?> inter = Interface1.class;
			System.out.println("Name : "+inter.getName());
			System.out.println(inter.isInterface() ? "Its an Interface" : "Its not an Interface");
			System.out.println("\nAll declared fields...\n");
			for(Field i : inter.getDeclaredFields()) {
				System.out.println("Name : "+i.getName());
				System.out.println("Type : "+i.getType());
				System.out.println("Modifiers : "+Modifier.toString(i.getModifiers())+"\n");
			}
	}

}
