"""

this module demonstrates the SOLID principles via Python.

what is SOLID princile?

- Single responsibility principle (SRP)
- Open-close principle            (OCP)
- Lisvok substitution principle   (LSP)
- Interface segregation principle (ISP)
- Dependency inversion principle  (DIP)

principles are NOT rules, it's guideline.

Merits

- esay to understand codebase
- easy to extend
- easy to maintain the codebase
- robust code
- minimum chaning existing codebase or not at all

v0.01, @ZL, 20201221

"""

# SIP
# a class should have only one responsibility and only one reason to change. that means a class does NOT perform multiple jobs.
# example: violation of SRP

class Account:
    def __init__(self, account_no: str):
        self.account_no = account_no
    # task one
    def get_account_number(self):
        return self.account_no
    # task two
    def save(self): 
        pass

# solution: a common solution to this problem is to apply the facade pattern.

# what is "facade pattern in the first place?"
# link: https://www.tutorialspoint.com/design_pattern/facade_pattern.htm
# merits and demerits
# what: 外观模式(facade pattern)隐藏系统的复杂性, 并向客户端提供一个客户端可以访问系统的接口。
#       这种类型的设计模式属于结构模式, 它向现有的系统添加一个接口, 来隐藏系统的复杂性。
#       这种模式涉及到一个单一的类, 该类提供了客户端请求的简化方法和现有系统类方法的委托调用
# why:  【意图】 为子系统的一组接口提供一个一致的界面, 外观模式定义了一个高层接口, 这个接口是的这一子系统更容易使用
#       【主要解决】 降低访问复杂系统的内部子系统时的复杂度, 简化客户端与子系统的接口
#       【何时使用】 1.客户端不需要指导系统内部的复杂联系, 整个系统只需提供一个“接待员"即可。 2.定义系统的入口
#       【如何解决】 客户端不与系统耦合, 外观与系统耦合
#       【应用实例】 1.去医院看病, 可能要去挂号, 门诊, 划价, 取药, 让患者或者患者家属觉得很复杂, 如果有提供接待人员, 只让接待人员来处理, 就很方便。
#       【优点】    1.减少系统相互依赖 2.提高灵活性 3.提高安全性
#       【缺点】    不符合OCP, 如果要改东西很麻烦, 继承重写不合适

class AccountDB:
    def get_account_number(self, _id):
        pass
    def account_save(self, obj):
        pass

class Account1:
    def __init__(self, account_no):
        self.account_no = account_no
        self._db = AccountDB()

    def get_account_number(self):
        return self.account_no

    def get(self, _id):
        return self._db.get_account_number(_id=_id)
    
    def save(self):
        self._db.account_save(obj=self)


# OCP
# open close principle
# software entities(classes, function, module) open for extension, but not for modification(or closed for modification)
# example: violation of OCP

class Discount:
    def __init__(self, customer, price):
        self.customer = customer
        self.price    = price
    
    def give_discount(self):
        if self.customer == 'normal':
            return self.price * .2
        elif self.customer == 'vip':
            return self.price * .4

# what if we have a "super vip" customer, and give the customer 0.8 discount?
# solution:

class Discount1:
    def __init__(self, customer, price):
        self.customer = customer
        self.price    = price
    def get_discount(self):
        return self.price * .2

class VIPDiscount(Discount1):
    def get_discount(self):
        return super().get_discount() * 2

class SVIPDiscount(VIPDiscount):
    def get_discount(self):
        return super().get_discount() * 2

# LSP
# if S is a subtype of T, then obj of type T may be replaced by obj of type S, w/o breaking the program. // upcasting is always safe
# example of violation of LSP

class Vehicle:
    def __init__(self, name, speed):
        self.name  = name
        self.speed = speed
    def get_name(self):
        return self.name
    def get_speed(self):
        return self.speed
    def engine(self):
        pass
    def start_engine(self):
        self.engine()

class Car(Vehicle):
    def start_engine(self):
        pass

class Bicycle(Vehicle):
    def start_engine(self): # violate LSP. Bicycle has no fking
        pass

# ISP
# it suggests that "A client should not be forced to implement an interface that it does NOT use"
# example: violation of ISP

class Shape:
    def draw_circle(self):
        raise NotImplementedError
    def draw_square(self):
        raise NotImplementedError

class Circle(Shape):
    def draw_cicle(self):
        pass
    def draw_square(self): # violate ISP. Circle obj does NOT use this method
        pass

# DIP
# it suggests that below two points:
#   a. high-level modules should not depend on low-level modules. both should depend on abstraction
#   b. abstractions should not depend on details. details should depend on abstractions.
# example: violation of DIP

class BackendDeveloper:
    """this is a low-level module"""
    @staticmethod
    def python():
        print("writing python code")

class FrontendDeveloper:
    """this is low-level module"""
    @staticmethod
    def javascript():
        print("writing JS code")

class Project: # high-level module depends on low-level modules. violate DIP
    """this is high-level module"""
    def __init__(self):
        self.backend  = BackendDeveloper()
        self.frontend = FrontendDeveloper()
    def develop(self):
        self.backend.python()
        self.frontend.javascript()
        return "Develop codebase"
 
# solution

class BackendDeveloper1:
    """this is a low-level module"""
    def develop(self):
        self.__python_code()

    @staticmethod
    def __python_code():
        print("writing python code")

class FrontendDeveloper1:
    """this is low-level module"""
    def develop(self):
        self.__javascript()

    @staticmethod
    def __javascript():
        print("writing JS code")

class Developers: # abstraction of low-level modules
    def __init__(self):
        self.backend  = BackendDeveloper1()
        self.frontend = FrontendDeveloper1()
    def develop(self):
        self.backend.develop()
        self.frontend.develop()

class Project1:
    def __init__(self):
        self.__developers = Developers()
    def develop(self):
        return self.__developers.develop()
    
    