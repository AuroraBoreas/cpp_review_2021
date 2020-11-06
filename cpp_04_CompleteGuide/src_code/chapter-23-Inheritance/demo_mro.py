import logging
logging.basicConfig(level=logging.DEBUG, format="%(module)s %(message)s")

class Base:
    def __init__(self):
        logging.debug("im base class")
    def print(self):
        logging.debug("hello im Base")
    def nmgb(self):
        logging.debug("NMGB, im Base")

class A(Base):
    def __init__(self):
        logging.debug("im class A")
    def print(self):
        logging.debug("hello im A")
    def cnm(self):
        logging.debug("CNM, im A")

class B(Base):
    def __init__(self):
        logging.debug("im class B")
    def print(self):
        logging.debug("hello im B")
    def nmsl(self):
        logging.debug("NMSL, im B")

class C(A, B):
    def __init__(self):
        logging.debug("im class C")

if __name__ == "__main__":
    objC = C()
    # MRO test
    objC.print() # output: "hello im A"
    objC.nmsl()
    objC.nmgb()