class Employee:
    def __init__(self, serialNumber, userName, age, gender, designation, yearOfJoining, salary):
        self._serialNumber = serialNumber
        self._userName = userName
        self._age = age
        self._gender = gender
        self._designation = designation
        self._yearOfJoining = yearOfJoining
        self._salary = salary

    @property
    def serialNumber(self):
        return self._serialNumber

    @property
    def userName(self):
        return self._userName

    @property
    def age(self):
        return self._age

    @property
    def gender(self):
        return self._gender

    @property
    def designation(self):
        return self._designation

    @property
    def yearOfJoining(self):
        return self._yearOfJoining

    @property
    def salary(self):
        return self._salary

    @serialNumber.setter
    def serialNumber(self, value):
        self._serialNumber = value

    @userName.setter
    def userName(self, value):
        self._userName = value

    @age.setter
    def age(self, value):
        self._age = value

    @gender.setter
    def gender(self, value):
        self._gender = value

    @designation.setter
    def designation(self, value):
        self._designation = value

    @yearOfJoining.setter
    def yearOfJoining(self, value):
        self._yearOfJoining = value

    @salary.setter
    def salary(self, value):
        self._salary = value

    def __str__(self):
        return f"{self.serialNumber} {self.userName} {self.age} {self.gender} {self.designation} {self.yearOfJoining} {self.salary}"


class InterviewCodeguru:
    @staticmethod
    def main():
        employeeList = [
            Employee(111, "Jiya Brein", 32, "Female", "HR", 2011, 25000.0),
            Employee(122, "Paul Niksui", 25, "Male", "Sales And Marketing", 2015, 13500.0),
            Employee(133, "Martin Theron", 29, "Male", "Infrastructure", 2012, 18000.0),
            Employee(144, "Murali Gowda", 28, "Male", "Product Development", 2014, 32500.0),
            Employee(155, "Nima Roy", 27, "Female", "HR", 2013, 22700.0),
            Employee(166, "Iqbal Hussain", 43, "Male", "Security And Transport", 2016, 10500.0),
            Employee(177, "Manu Sharma", 35, "Male", "Account And Finance", 2010, 27000.0),
            Employee(188, "Wang Liu", 31, "Male", "Product Development", 2015, 34500.0),
            Employee(199, "Amelia Zoe", 24, "Female", "Sales And Marketing", 2016, 11500.0),
            Employee(200, "Jaden Dough", 38, "Male", "Security And Transport", 2015, 11000.5),
            Employee(211, "Jasna Kaur", 27, "Female", "Infrastructure", 2014, 15700.0),
            Employee(222, "Nitin Joshi", 25, "Male", "Product Development", 2016, 28200.0),
            Employee(233, "Jyothi Reddy", 27, "Female", "Account And Finance", 2013, 21300.0),
            Employee(244, "Nicolus Den", 24, "Male", "Sales And Marketing", 2017, 10700.5),
            Employee(255, "Ali Baig", 23, "Male", "Infrastructure", 2018, 12700.0),
            Employee(266, "Sanvi Pandey", 26, "Female", "Product Development", 2015, 28900.0),
            Employee(277, "Anuj Chettiar", 31, "Male", "Product Development", 2012, 35700.0)
        ]

        youngest_employee = min(employeeList, key=lambda x: x.age)
        print(youngest_employee.userName)

        oldest_employee = max(employeeList, key=lambda x: x.age)
        print(oldest_employee.userName)

        male_count = sum(1 for employee in employeeList if employee.gender == "Male")
        female_count = len(employeeList) - male_count
        print(male_count, female_count)

        employeeList.sort(key=lambda x: x.age)
        for employee in employeeList:
            print(employee)

        for employee in employeeList:
            if employee.designation == "Product Development":
                print(employee.userName)


if __name__ == "__main__":
    InterviewCodeguru.main()
