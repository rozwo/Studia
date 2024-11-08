# Utworzyć trzy klasy wedlu schematu uml.
# metody:
# fill_up -> uzupełnia paliwo w baku. Paliwa nie może być więcej niż pojemność baku
# turn_on/off -> włącza i wyłącza silnik zmieniajć jego właściwość running na True lub False
# info -> wypisuje informacje o obecnym stanie auta tzn. procent napełnienia baku, stan włączenia silnika

class Engine:
    def __init__(self, running:bool):
        self.running = running
    def turn_on(self):
        self.running=True
    def turn_off(self):
        self.running=False
    def get_running_state(self):
        return self.running      
      
class FuelTank:
    def __init__(self,capacity:float,current_level:float):
        self.capacity=capacity
        self.current_level=current_level
    def fill_up(self,amount_fuel):
        if amount_fuel<=self.capacity:
            self.current_level=amount_fuel
        else:
            self.current_level=self.capacity
    def get_capacity(self):
        return self.capacity
    def get_current_level(self):
        return self.current_level

class Auto:
    def __init__(self, engine:Engine, tank:FuelTank):
        self.engine = engine
        self.tank = tank
    def get_engine(self):
        return self.engine
    def get_fuel_tank(self):
        return self.tank
    def set_engine(self, engine):
        self.engine=engine
    def set_fuel_tank(self, tank):
        self.tank=tank
    def fill_up(self,amount_fuel):
        self.tank.fill_up(amount_fuel)
    def turn_on_engine(self):
        self.engine.turn_on()
    def turn_off_engine(self):
        self.engine.turn_off()
    def info(self):
        print(100*self.tank.get_current_level()/self.tank.get_capacity(),"% ",self.engine.get_running_state())
        
e1=Engine(False)
e2=Engine(True)
f1=FuelTank(50,24)
f2=FuelTank(40,36)
auto=Auto(e1,f1)
# auto.info()
auto.turn_on_engine()
print(auto.get_engine())
auto.turn_off_engine()
print(auto.get_engine())
print(auto.get_fuel_tank())
auto.fill_up(23)
print(auto.get_fuel_tank())
auto.set_engine(e2)
auto.set_fuel_tank(e2)
# auto.info()

# info nie dziala
# a reszta jest tak:
# <__main__.Engine object at 0x7f30054ca160>
# <__main__.Engine object at 0x7f30054ca160>
# <__main__.FuelTank object at 0x7f300541a0d0>
# <__main__.FuelTank object at 0x7f300541a0d0>

