import java.util.*;
import java.util.stream.Collectors;
import java.io.*;

// (24, 32, "James", 3.1, "Mechanical Engineering")
class Student {
	private int Age;
	private int rollNo;
	private String Name;
	private double gpa;
	private String Majors;

	public Student(int age, int rollNo, String name, double gpa, String majors) {
		Age = age;
		this.rollNo = rollNo;
		Name = name;
		this.gpa = gpa;
		Majors = majors;
	}

	public int getAge() {
		return Age;
	}

	public void setAge(int age) {
		Age = age;
	}

	public int getRollNo() {
		return rollNo;
	}

	public void setRollNo(int rollNo) {
		this.rollNo = rollNo;
	}

	public String getName() {
		return Name;
	}

	public void setName(String name) {
		Name = name;
	}

	public double getGpa() {
		return gpa;
	}

	public void setGpa(double gpa) {
		this.gpa = gpa;
	}

	public String getMajors() {
		return Majors;
	}

	public void setMajors(String majors) {
		Majors = majors;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + Age;
		result = prime * result + rollNo;
		result = prime * result + ((Name == null) ? 0 : Name.hashCode());
		long temp;
		temp = Double.doubleToLongBits(gpa);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		result = prime * result + ((Majors == null) ? 0 : Majors.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Student other = (Student) obj;
		if (Age != other.Age)
			return false;
		if (rollNo != other.rollNo)
			return false;
		if (Name == null) {
			if (other.Name != null)
				return false;
		} else if (!Name.equals(other.Name))
			return false;
		if (Double.doubleToLongBits(gpa) != Double.doubleToLongBits(other.gpa))
			return false;
		if (Majors == null) {
			if (other.Majors != null)
				return false;
		} else if (!Majors.equals(other.Majors))
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "Student [Age=" + Age + ", rollNo=" + rollNo + ", Name=" + Name + ", gpa=" + gpa + ", Majors=" + Majors
				+ "]";
	}

}

public class Streams {
	public static void main(String[] args) {
		List<Student> students = new ArrayList<>();

		students.add(new Student(22, 1, "Alice", 3.9, "Computer Science"));
		students.add(new Student(21, 2, "Bob", 3.7, "Mechanical Engineering"));
		students.add(new Student(23, 3, "Charlie", 3.5, "Electrical Engineering"));
		students.add(new Student(20, 4, "David", 3.8, "Mathematics"));
		students.add(new Student(22, 5, "Eva", 3.6, "Physics"));
		students.add(new Student(21, 6, "Frank", 3.2, "Chemistry"));
		students.add(new Student(23, 7, "Grace", 3.4, "Biology"));
		students.add(new Student(20, 8, "Hannah", 3.1, "English"));
		students.add(new Student(24, 9, "Ivy", 3.3, "History"));
		students.add(new Student(22, 10, "Jack", 3.0, "Political Science"));
		students.add(new Student(25, 11, "Kate", 3.7, "Computer Science"));
		students.add(new Student(21, 12, "Liam", 3.5, "Mechanical Engineering"));
		students.add(new Student(22, 13, "Mia", 3.2, "Electrical Engineering"));
		students.add(new Student(23, 14, "Noah", 3.6, "Mathematics"));
		students.add(new Student(20, 15, "Olivia", 3.4, "Physics"));
		students.add(new Student(24, 16, "Sophia", 3.1, "Chemistry"));
		students.add(new Student(22, 17, "Lucas", 3.9, "Biology"));
		students.add(new Student(21, 18, "Emma", 3.7, "English"));
		students.add(new Student(23, 19, "Liam", 3.5, "History"));
		students.add(new Student(20, 20, "Ava", 3.8, "Political Science"));
		students.add(new Student(22, 21, "Mason", 3.6, "Computer Science"));
		students.add(new Student(21, 22, "Olivia", 3.2, "Mechanical Engineering"));
		students.add(new Student(23, 23, "Logan", 3.4, "Electrical Engineering"));
		students.add(new Student(20, 24, "Sophia", 3.1, "Mathematics"));
		students.add(new Student(24, 25, "Ethan", 3.3, "Physics"));
		students.add(new Student(22, 26, "Isabella", 3.0, "Chemistry"));
		students.add(new Student(25, 27, "Mia", 3.7, "Biology"));
		students.add(new Student(21, 28, "Alexander", 3.5, "English"));
		students.add(new Student(22, 29, "Charlotte", 3.2, "History"));
		students.add(new Student(23, 30, "William", 3.6, "Political Science"));
		students.add(new Student(20, 31, "Abigail", 3.4, "Computer Science"));
		students.add(new Student(24, 32, "James", 3.1, "Mechanical Engineering"));

		List<Student> minAgeStudents = students.stream().collect(Collectors.filtering(
				student -> student.getAge() == students.stream().min((a, b) -> Integer.compare(a.getAge(), b.getAge()))
						.get().getAge(),
				Collectors.toList()));

		minAgeStudents.forEach(student -> {
			System.out.println(student.getName());
		});

		// List<Student> sortedStudents = students.stream().sorted((a, b) ->
		// Integer.compare(a.getAge(), b.getAge()))
		// .collect(Collectors.toList());

		Map<String, List<Student>> branchWise = students.stream()
				.collect(Collectors.groupingBy(student -> student.getMajors()));

		branchWise.forEach((branchName, studentList) -> {
			System.out.println("Branch : " + branchName);
			studentList.forEach(student -> {
				System.out.println(student.getName());
			});
			System.out.println();
		});

		int[] arr = { 1, 2, 1, 1, 3, 3, 4, 4, 4, 4 };

		Map<Integer, Long> freqMap = Arrays.stream(arr).boxed()
				.collect(Collectors.groupingBy(t -> t, Collectors.counting()));

		freqMap.forEach((key, val) -> {
			System.out.println(key + " " + val);
		});

		List<String> inputArray = Arrays.asList("123", "jkfhsdkjhf", "234", "fsdfsdf", "111", "oiuem");

		List<String> outputArray = inputArray.stream().collect(Collectors.filtering(val -> {
			try {
				Integer.parseInt(val);
				return true;
			} catch (NumberFormatException e) {
				return false;
			}
		}, Collectors.toList()));

		outputArray.forEach(val -> {
			System.out.println(val);
		});

	}
}