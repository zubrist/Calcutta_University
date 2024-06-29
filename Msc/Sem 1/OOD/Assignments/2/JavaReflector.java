import java.io.*;
import java.lang.Class;
import java.lang.reflect.*;

/**
 * Prints the blueprint of a class given as a command line argument
 * onto the console and a <ClassName>.java file.
 * 
 * @author Sudipto Ghosh (R. No. 27)
 */
public class JavaReflector {

	static void printClassMetadata(Class<?> c) {
		if (c.getPackage() != null && !c.getPackage().getName().equals(""))
			System.out.println("package " + c.getPackage().getName() + ";");

		if (c.getModifiers() != 0) {
			int m = c.getModifiers();
			if (Modifier.isPublic(m))
				System.out.print("public ");
			if (Modifier.isAbstract(m))
				System.out.print("abstract ");
			if (Modifier.isFinal(m))
				System.out.print("final ");
			if (Modifier.isStatic(m))
				System.out.print("static ");
		}

		if (c.isInterface()) {
			System.out.print("interface ");
		} else if (c.isEnum()) {
			System.out.print("enum ");
		} else {
			System.out.print("class ");
		}

		System.out.print(c.getSimpleName());

		if (c.getTypeParameters().length > 0) {
			System.out.print("<");
			TypeVariable<?>[] typeParameters = c.getTypeParameters();
			for (int i = 0; i < typeParameters.length; i++) {
				System.out.print(typeParameters[i].getName());
				if (i < typeParameters.length - 1) {
					System.out.print(", ");
				}
			}
			System.out.print(">");
		}

		if (c.getSuperclass() != null && c.getSuperclass() != Object.class) {
			System.out.print(" extends " + c.getSuperclass().getName());
		}

		Class<?>[] interfaces = c.getInterfaces();
		if (interfaces.length > 0) {
			System.out.print(" implements ");
			for (int i = 0; i < interfaces.length; i++) {
				System.out.print(interfaces[i].getName());
				if (i < interfaces.length - 1) {
					System.out.print(", ");
				}
			}
		}
	}

	static void printFieldMetadata(Field f) {
		System.out.print("\t");

		if (f.getModifiers() != 0) {
			System.out.print(Modifier.toString(f.getModifiers()) + " ");
		}

		if (f.getType().isArray()) {
			System.out.print(f.getType().getComponentType().getName() + "[] ");
		} else {
			System.out.print(f.getType().getName() + " ");
		}

		// TODO: print default values

		System.out.println(f.getName() + ";");
	}

	static void printConstructorMetadata(Constructor<?> c) {
		System.out.print("\t");

		if (c.getModifiers() != 0) {
			System.out.print(Modifier.toString(c.getModifiers()) + " ");
		}

		System.out.print(c.getDeclaringClass().getSimpleName() + "(");

		Class<?>[] paramTypes = c.getParameterTypes();
		for (int i = 0; i < paramTypes.length; i++) {
			if (paramTypes[i].isArray()) {
				System.out.print((paramTypes[i].getComponentType().getName() == c.getDeclaringClass().getName()
						? c.getDeclaringClass().getSimpleName()
						: paramTypes[i].getComponentType().getName()) + "[]");
			} else {
				System.out.print((paramTypes[i].getName() == c.getDeclaringClass().getName()
						? c.getDeclaringClass().getSimpleName()
						: paramTypes[i].getName()));
			}
			System.out.print(" arg" + i);
			if (i < paramTypes.length - 1) {
				System.out.print(", ");
			}
		}

		System.out.println(");");
	}

	static void printMethodMetadata(Method m) {
		System.out.print("\t");

		if (m.getModifiers() != 0) {
			System.out.print(Modifier.toString(m.getModifiers()) + " ");
		}

		if (m.getReturnType().isArray()) {
			System.out.print((m.getReturnType().getComponentType().getName() == m.getDeclaringClass().getName()
					? m.getDeclaringClass().getSimpleName()
					: m.getReturnType().getComponentType().getName()) + "[] ");
		} else {
			System.out
					.print((m.getReturnType().getName() == m.getDeclaringClass().getName()
							? m.getDeclaringClass().getSimpleName()
							: m.getReturnType().getName()) + " ");
		}
		System.out.print(m.getName() + "(");

		Class<?>[] paramTypes = m.getParameterTypes();
		for (int i = 0; i < paramTypes.length; i++) {
			if (paramTypes[i].isArray()) {
				System.out.print((paramTypes[i].getComponentType().getName() == m.getDeclaringClass().getName()
						? m.getDeclaringClass().getSimpleName()
						: paramTypes[i].getComponentType().getName()) + "[]");
			} else {
				System.out.print((paramTypes[i].getName() == m.getDeclaringClass().getName()
						? m.getDeclaringClass().getSimpleName()
						: paramTypes[i].getName()));
			}
			System.out.print(" arg" + i);
			if (i < paramTypes.length - 1) {
				System.out.print(", ");
			}
		}

		System.out.println(");");
	}

	public static void main(String[] args) {
		try {
			// get class name as a cli argument or String
			String cName = args.length > 0 && args[0] != null ? args[0] : "java.lang.String";

			// get the class ref
			Class<?> c = Class.forName(cName);

			// get -o cli argument or default to stdout
			String out = args.length > 1 && args[1] != null ? args[1] : "stdout";

			if (out != "stdout") {
				// create a file with the name ClassName.java
				File file = new File(c.getSimpleName() + ".java");
				file.createNewFile();

				// tie stdout with file and console if we want to create a file
				System.setOut(new PrintStream(file));
			}

			// print class
			printClassMetadata(c);

			System.out.println(" {");

			// print fields
			Field[] fields = c.getDeclaredFields();
			if (fields.length > 0) {
				System.out.println("\t// Fields");
				for (Field f : fields) {
					printFieldMetadata(f);
				}
				System.out.println();
			}

			// print constructors
			Constructor<?>[] ctors = c.getDeclaredConstructors();
			if (ctors.length > 0) {
				System.out.println("\t// Constructors");
				for (Constructor<?> ctor : ctors) {
					printConstructorMetadata(ctor);
				}
				System.out.println();
			}

			// print methods
			Method[] methods = c.getDeclaredMethods();
			if (methods.length > 0) {
				System.out.println("\t// Methods");
				for (Method m : methods) {
					printMethodMetadata(m);
				}
			}

			System.out.println("}");
		} catch (ClassNotFoundException e) {
			System.err.println("Error: Class Not Found");
		} catch (IOException e) {
			System.err.println("Error: IO Exception");
		}
	}
}
