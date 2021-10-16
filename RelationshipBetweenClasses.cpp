//Dependency - is the relationship in which the object of this class uses the object of the othe class
//class ClassA {
// public:
// 	void myMethod(ClassB b) {
// 		b.doWork();
// 	}
// }
// ClassA ------------> classB

// Association - occurs when an object has attributes which are another object
// class Manager {
// private:
// 	string name;

// public:
// 	Manager() {

// 	}
// 	Manager(string name) {
// 		this->name = name;
// 	}

// 	string getName() {
// 		return name;
// 	}
// };

// class Employee {
// private:
// 	string name;
// 	Manager manager;

// public:
// 	Employee(string name, Manager manager) {
// 		this->name = name;
// 		this->manager = manager;
// 	}

// 	string getManagerName() {
// 		return manager.getName();
// 	}

// 	string getName() {
// 		return name;
// 	}
// };

//Associations are divided into 2 types: Aggregation and Composition 

//Aggregation - occurs when an object has an attribute that is another object and these two object can exst independently 
//class ClassA {
// private:
// 	ClassB b;
// public:
// 	void setB(ClassB b) {
// 		this->b = b;
// 	}
// };

//Composition -- occurs when object of a classB is a part in object of another classA
//When object of another classA is destroyed, so does the object of classB
// class ClassA {
// private:
// 	ClassB *b;
// public:
// 	ClassA() {
// 		b = new ClassB();
// 	}
// }


