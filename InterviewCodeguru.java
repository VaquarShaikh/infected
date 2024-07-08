// This was the code for the interview for project : aws codeguru in persistent systems
// Interviewer 1 : Anushi Gupta
// Interviewer 2 : Harshad Pathan
// Superior : Supriya Kharsan

// (new Employee(111, "Jiya Brein", 32, "Female", "HR", 2011, 25000.0));

import java.util.*;
import java.util.stream.Stream;
import java.io.*;

class Employee {
	private int serialNumber;
	private String userName;
	private int age;
	private String gender;
	private String designation;
	private int yearOfJoining;
	private double salary;

	Employee(int serialNumber, String userName, int age, String gender, String designation, int yearOfJoining,
			double d) {
		this.serialNumber = serialNumber;
		this.userName = userName;
		this.age = age;
		this.gender = gender;
		this.designation = designation;
		this.yearOfJoining = yearOfJoining;
		this.salary = d;
	}

	public int getSerialNumber() {
		return serialNumber;
	}

	public String getUuserName() {
		return userName;
	}

	public int getAge() {
		return age;
	}

	public String getGender() {
		return gender;
	}

	public String getDesignation() {
		return designation;
	}

	public int getYearOfJoining() {
		return yearOfJoining;
	}

	public double getSalary() {
		return salary;
	}

	public void setSerialNumber(int serialNumber) {
		this.serialNumber = serialNumber;
	}

	public void setUsername(String userName) {
		this.userName = userName;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public void getDestination(String designation) {
		this.designation = designation;
	}

	public void setyearOfJoining(int yearOfJoining) {
		this.yearOfJoining = yearOfJoining;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public String toString() {
		return serialNumber + " " + userName + " " + age + " " + gender + " " + designation + " " + yearOfJoining + " "
				+ salary;
	}

	// public int age() {
	// return age;
	// }

}

// Paul Niksui
// Martin Theron
// Murali Gowda
// Iqbal Hussain
// Manu Sharma
// Wang Liu
// Jaden Dough
// Nitin Joshi
// Nicolus Den
// Ali Baig
// Anuj Chettiar

class SortByAge implements Comparator<Employee> {
	public int compare(Employee a, Employee b) {
		return a.getAge() - b.getAge();
	}
}

public class InterviewCodeguru {
	public static void main(String[] args) {
		// System.out.println("Hello World!!!");
		List<Employee> employeeList = new ArrayList<>();
		employeeList.add(new Employee(111, "Jiya Brein", 32, "Female", "HR", 2011, 25000.0));
		employeeList.add(new Employee(122, "Paul Niksui", 25, "Male", "Sales And Marketing", 2015, 13500.0));
		employeeList.add(new Employee(133, "Martin Theron", 29, "Male", "Infrastructure", 2012, 18000.0));
		employeeList.add(new Employee(144, "Murali Gowda", 28, "Male", "Product Development", 2014, 32500.0));
		employeeList.add(new Employee(155, "Nima Roy", 27, "Female", "HR", 2013, 22700.0));
		employeeList.add(new Employee(166, "Iqbal Hussain", 43, "Male", "Security And Transport", 2016, 10500.0));
		employeeList.add(new Employee(177, "Manu Sharma", 35, "Male", "Account And Finance", 2010, 27000.0));
		employeeList.add(new Employee(188, "Wang Liu", 31, "Male", "Product Development", 2015, 34500.0));
		employeeList.add(new Employee(199, "Amelia Zoe", 24, "Female", "Sales And Marketing", 2016, 11500.0));
		employeeList.add(new Employee(200, "Jaden Dough", 38, "Male", "Security And Transport", 2015, 11000.5));
		employeeList.add(new Employee(211, "Jasna Kaur", 27, "Female", "Infrastructure", 2014, 15700.0));
		employeeList.add(new Employee(222, "Nitin Joshi", 25, "Male", "Product Development", 2016, 28200.0));
		employeeList.add(new Employee(233, "Jyothi Reddy", 27, "Female", "Account And Finance", 2013, 21300.0));
		employeeList.add(new Employee(244, "Nicolus Den", 24, "Male", "Sales And Marketing", 2017, 10700.5));
		employeeList.add(new Employee(255, "Ali Baig", 23, "Male", "Infrastructure", 2018, 12700.0));
		employeeList.add(new Employee(266, "Sanvi Pandey", 26, "Female", "Product Development", 2015, 28900.0));
		employeeList.add(new Employee(277, "Anuj Chettiar", 31, "Male", "Product Development", 2012, 35700.0));
		// List<Employee> youngestEmployee = employeeList.stream().reduce()
		// for (int i = 0; i < employeeList.size(); i++) {
		// System.out.println(employeeList.get(i).age + " ");

		// }

		// int returnAge = ((Employee) employeeList).age();
		// System.out.println(returnAge);

		// Stream<List<Employee>> employeeStream = Stream.of(employeeList);

		// System.out.println(employeeStream.);
		// List<Integer> list = Arrays.asList()

		int minAge = 9999;
		String employeeName = "";
		String maxEmployeeName = "";

		// for (Employee employee : employeeList) {
		// // if (minAge < employee.getAge()) {
		// // minAge = employee.getAge();

		// // }
		// System.out.println(employee.getAge());
		// }

		// System.out.println(minAge);

		for (int i = 0; i < employeeList.size(); i++) {
			// System.out.println(employeeList.get(i).getAge());
			if (employeeList.get(i).getAge() < minAge) {
				minAge = employeeList.get(i).getAge();
				employeeName = employeeList.get(i).getUuserName();
			}
		}

		int maxAge = -1;
		for (int i = 0; i < employeeList.size(); i++) {
			// System.out.println(employeeList.get(i).getAge());
			if (employeeList.get(i).getAge() > maxAge) {
				maxAge = employeeList.get(i).getAge();
				maxEmployeeName = employeeList.get(i).getUuserName();
			}
		}

		// System.out.println(minAge);
		// System.out.println(employeeName);

		// System.out.println(maxAge);
		// System.out.println(maxEmployeeName);

		int maleCount = 0;
		int femaleCount = 0;

		for (int i = 0; i < employeeList.size(); i++) {
			if (employeeList.get(i).getGender() == "Male") {
				// System.out.println(employeeList.get(i).getUuserName());
				maleCount++;
				// System.out.println(i + " " + employeeList.get(i).getUuserName());
			} else {
				femaleCount++;
				// System.out.println(i + " " + employeeList.get(i).getUuserName());
			}
		}

		Collections.sort(employeeList, new SortByAge());

		for (int i = 0; i < employeeList.size(); i++) {
			System.out.println(employeeList.get(i));
		}

		System.out.println(maleCount + " " + femaleCount);
		// Employee obj = new Employee(123, null, 0, null, null, 0, 0)

		for (int i = 0; i < employeeList.size(); i++) {
			if (employeeList.get(i).getDesignation() == "Product Development")
				System.out.println(employeeList.get(i).getUuserName());
		}

	}
}

// Nitin Joshi
// Sanvi Pandey
// Murali Gowda
// Wang Liu
// Anuj Chettiar

// Paul Niksui
// Martin Theron
// Murali Gowda
// Iqbal Hussain
// Manu Sharma
// Wang Liu
// Jaden Dough
// Nitin Joshi
// Nicolus Den
// Ali Baig
// Anuj Chettiar