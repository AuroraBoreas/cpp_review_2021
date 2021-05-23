/*
JavaScript, meta review

@ZL, 20210523

*/ 

class Point {
    _x; _y;

    constructor(x, y) {
        this._x = x;
        this._y = y;
    }

    get X() { return this._x; }
    get Y() { return this._y; }
    set X(val) { this._x = val; }
    set Y(val) { this._y = val; }

    ToString() {
        return `Point[${this.X}, ${this.Y}]`;
    }

    Add(other) {
        return new Point(this.X + other.X, this.Y + other.Y);
    }

    Compare(other) {
        return this.ToString() == other.ToString();
    }
};

class Line
{
    _p1; _p2;

    constructor(p1, p2) {
        if (p1.Compare(p2)){
            throw new Error("detected p1 == p2; this is not allowed")
        }
        this._p1 = p1;
        this._p2 = p2;
    }

    slope() {
        return (this._p1.Y - this._p2.Y) / (this._p1.X - this._p2.X);
    }

    yIntercept() {
        return this._p1.Y - (this.slope() * this._p1.X);
    }

    xIntercept() {
        if(this.yIntercept() == 0) {
            return 0;
        }
        return -1 * this.yIntercept() / this.slope();
    }
}

class Person {
    _name; _age;
    constructor(name, age) {
        this._name = name;
        this._age = age;
    }

    get Name() { return this._name; }
    get Age()  { return this._age; }
    set Name(val) { this._name = val; }
    set Age(val)  { this._age = val; }

    ToString() {
        return `\nname: ${this.Name}\nage: ${this.Age}`;
    }
}

class Teacher extends Person {
    _subject;
    constructor(name, age, subject) {
        super(name, age);
        this._subject = subject;
    }

    get Subject() { return this._subject; }
    set Subject(val) { this._subject = val; }

    ToString() {
        return super.ToString() + `\nsubject: ${this.Subject}`;
    }
}

class Student extends Person {
    _score;
    constructor(name, age, score) {
        super(name, age);
        this._score = score;
    }
    get Score() { return this._score; }
    set Score(val) { this._score = val; }

    ToString() {
        return super.ToString() + `\nscore: ${this.Score}`;
    }
}

class A {
    ToString() {
        return "class A says nihao!";
    }
}

class B extends A {
    ToString() {
        return "class B says hey!";
    }
}

class C extends B {
    ToString() {
        return "class C says halo!";
    }
}
// var p1 = new Point(2, 4);
// var p2 = new Point(2, 4);
// var line = new Line(p1, p2);
// console.log(line.slope(), line.yIntercept(), line.xIntercept());

// let teach = new Teacher("TS", 30, "japanese");
// console.log(teach.ToString());

exports.Point = Point;
exports.Line = Line;
exports.Person = Person;
exports.Teacher = Teacher;
exports.Student = Student;
exports.A = A;
exports.B = B;
exports.C = C;